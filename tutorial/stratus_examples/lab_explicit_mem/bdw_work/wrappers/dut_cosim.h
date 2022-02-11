/****************************************************************************
 *
 *  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
 *
 *  This file contains confidential information that may not be
 *  distributed under any circumstances without the written permision
 *  of Cadence Design Systems.
 *
 ***************************************************************************/

#ifndef _DUT_COSIM_INCLUDED_
#define _DUT_COSIM_INCLUDED_

#include "systemc.h"
#include "cynthhl.h"
#include "esc.h"
#if __GNUC__ < 3
#include <ostream.h>
#else
#include <ostream>

#endif

#ifdef NC_SYSTEMC
struct dut_cosim : public ncsc_foreign_module
#else
SC_MODULE(dut_cosim)
#endif
{
	struct StringPair {
		const char* simConfigName;
		const char* instanceName;
		bool linked;
	};

	// Instance number used during elaboration-time SystemC-to-HDL signal linkage.
	static int numLinked;
	static StringPair instanceNames[];

	static int numInstanceNames( const char* simConfigName ) {
		int nin = 0;
		for ( int i = 0; instanceNames[i].simConfigName != NULL; ++i )
			if ( strcmp( instanceNames[i].simConfigName, simConfigName ) == 0 )
				++nin;
		return nin;
	}

	// Port declarations.
	sc_in< bool > clk;
	sc_in< bool > rst;
	sc_out< bool > din_busy;
	sc_in< bool > din_vld;
	sc_in< sc_uint< 8 > > din_data;
	sc_in< bool > dout_busy;
	sc_out< bool > dout_vld;
	sc_out< sc_uint< 11 > > dout_data;
	sc_out< bool > mem_WE0;
	sc_out< sc_uint< 8 > > mem_DIN0;
	sc_in< sc_uint< 8 > > mem_DOUT0;
	sc_out< sc_uint< 6 > > mem_A0;
	sc_out< bool > mem_REQ0;

    void end_of_elaboration()
    {
#if __GNUC__ < 3
		strstream s;
#else
		std::ostringstream s;
#endif


		s << "top/";

		const char* scName = getenv("BDW_SIM_CONFIG");
		if (!scName) 
			scName = "?";

		int nin = numInstanceNames(scName);
		if ( nin == 0 )
		{
			if ( numLinked > 0 ) 
			{
				esc_report_error( esc_fatal, 
					"More than one instance of module dut is being simulated in Verilog,\n"
					"but no instance names have been specified in simConfig %s.\n"
					"Additional instances can be specified using the following syntax:\n\n"
					"    simConfig <config_name> { <module> RTL_V <config> <inst1> <inst2> ...}\n\n"
					"where <inst1> and <inst2> are the leaf names of instances of dut in SystemC\n", 
					scName );
				return;
			} else {
				s << "dut0" << std::ends;
			}
		}
		else
		{
			StringPair *instPair = &instanceNames[ numLinked ];
			while ( instPair->instanceName != NULL )
			{
				if ( ( ! instPair->linked )
					 && ( ! strcmp( instPair->simConfigName, scName ) ) )
				{
					const char *instName = instPair->instanceName;

					// Hierarchical SystemC instance names must be escaped for Verilog.
					if ( strchr( instName, '.' ) != NULL )
						s << '\\' << instName << ' ' << std::ends;
					else
						s << instName << std::ends;

					instPair->linked = true;
					break;
				}

				++instPair;
			}

			if ( instPair->instanceName == NULL )
			{
				esc_report_error( esc_fatal, 
								  "More than %d instance(s) of module dut are being simulated in Verilog,\n"
								  "but only %d instance name(s) have been specified in simConfig %s.\n",
								  nin, nin, scName );
				return;
			}
		}
		numLinked++;


#if __GNUC__ < 3
		char *c = s.str();
#else
		char *c = (char *)strdup( s.str().c_str() );
#endif

        link_signals(c, "verilog");
#if __GNUC__ < 3
		delete c;
#else
		free( c );
#endif
    }

    void link_signals(const char *module_path, const char *sim_domain)
    {
#ifndef NC_SYSTEMC
        int registeredClocks = 0;

		double inputDelay = 0.0;
		const char* scName = getenv("BDW_SIM_CONFIG");
		if (!scName) scName = "?";
		if ( qbhVerilogInputDelay( qbhEmptyHandle, scName, &inputDelay ) != qbhOK )
			inputDelay = 0.0;

		// Try to register the boolean input ports as clocks.
		int clk_is_clock = esc_link_clockgen( &clk, sc_time( 0, SC_NS ), module_path, sim_domain, "clk" );
		int rst_is_clock = esc_link_clockgen( &rst, sc_time( 0, SC_NS ), module_path, sim_domain, "rst" );
		int din_vld_is_clock = esc_link_clockgen( &din_vld, sc_time( 0, SC_NS ), module_path, sim_domain, "din_vld" );
		int dout_busy_is_clock = esc_link_clockgen( &dout_busy, sc_time( 0, SC_NS ), module_path, sim_domain, "dout_busy" );

		esc_link_signals( &rst, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &din_busy, module_path, sim_domain, true );
		esc_link_signals( &din_vld, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &din_data, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &dout_busy, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &dout_vld, module_path, sim_domain, true );
		esc_link_signals( &dout_data, module_path, sim_domain, true );
		esc_link_signals( &mem_WE0, module_path, sim_domain, true );
		esc_link_signals( &mem_DIN0, module_path, sim_domain, true );
		esc_link_signals( &mem_DOUT0, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &mem_A0, module_path, sim_domain, true );
		esc_link_signals( &mem_REQ0, module_path, sim_domain, true );
		

		if ( clk_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = clk[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, clk.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "dut", "clk", scName ) ) {
			esc_report_error( esc_error, "The port 'clk' on module 'dut'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( rst_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = rst[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, rst.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "dut", "rst", scName ) ) {
			esc_report_error( esc_error, "The port 'rst' on module 'dut'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( din_vld_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = din_vld[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, din_vld.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "dut", "vld", scName ) ) {
			esc_report_error( esc_error, "The port 'vld' on module 'dut'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( dout_busy_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = dout_busy[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, dout_busy.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "dut", "busy", scName ) ) {
			esc_report_error( esc_error, "The port 'busy' on module 'dut'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}


        if ( registeredClocks == 0 )
		{
			esc_report_error( esc_fatal, 
				"The clock port in module dut must have\n"
				"an sc_clock bound to it to make cosimulation work" );
		}
#endif
    }

#ifdef NC_SYSTEMC
    const char* hdl_name() const { return "dut_nc_cosim"; } 
    dut_cosim( sc_module_name name )
        : ncsc_foreign_module(name)
#else
	dut_cosim( sc_module_name in_name=sc_module_name(sc_gen_unique_name(" dut") ) )
		: sc_module(in_name)
#endif
		  ,clk("clk")
		  	,rst("rst")
		  	,din_busy("din_busy")
		  	,din_vld("din_vld")
		  	,din_data("din_data")
		  	,dout_busy("dout_busy")
		  	,dout_vld("dout_vld")
		  	,dout_data("dout_data")
		  	,mem_WE0("mem_WE0")
		  	,mem_DIN0("mem_DIN0")
		  	,mem_DOUT0("mem_DOUT0")
		  	,mem_A0("mem_A0")
		  	,mem_REQ0("mem_REQ0")
		  	

    {
    };
};

int dut_cosim::numLinked = 0;
dut_cosim::StringPair dut_cosim::instanceNames[] = {
	{ NULL, NULL, false } };

#endif
