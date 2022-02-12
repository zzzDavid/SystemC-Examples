/****************************************************************************
 *
 *  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
 *
 *  This file contains confidential information that may not be
 *  distributed under any circumstances without the written permision
 *  of Cadence Design Systems.
 *
 ***************************************************************************/

#ifndef _FIND_MAX_COSIM_INCLUDED_
#define _FIND_MAX_COSIM_INCLUDED_

#include "systemc.h"
#include "cynthhl.h"
#include "esc.h"
#if __GNUC__ < 3
#include <ostream.h>
#else
#include <ostream>

#endif

#if !defined(XM_SYSTEMC) && defined(NC_SYSTEMC)
#define xmsc_foreign_module ncsc_foreign_module
#endif

#if defined(XM_SYSTEMC) || defined(NC_SYSTEMC)
struct find_max_cosim : public xmsc_foreign_module
#else
SC_MODULE(find_max_cosim)
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
	sc_out< bool > find_max_x_busy;
	sc_in< bool > find_max_x_vld;
	sc_in< sc_int< 32 > > find_max_x_data;
	sc_in< bool > find_max_return_busy;
	sc_out< bool > find_max_return_vld;
	sc_out< sc_int< 32 > > find_max_return_data;
	sc_in< bool > add_one_x_out_busy;
	sc_out< bool > add_one_x_out_vld;
	sc_out< sc_int< 32 > > add_one_x_out_data;
	sc_out< bool > add_one_return_in_busy;
	sc_in< bool > add_one_return_in_vld;
	sc_in< sc_int< 32 > > add_one_return_in_data;

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
					"More than one instance of module find_max is being simulated in Verilog,\n"
					"but no instance names have been specified in simConfig %s.\n"
					"Additional instances can be specified using the following syntax:\n\n"
					"    simConfig <config_name> { <module> RTL_V <config> <inst1> <inst2> ...}\n\n"
					"where <inst1> and <inst2> are the leaf names of instances of find_max in SystemC\n", 
					scName );
				return;
			} else {
				s << "find_max0" << std::ends;
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
								  "More than %d instance(s) of module find_max are being simulated in Verilog,\n"
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
#if !defined(XM_SYSTEMC) && !defined(NC_SYSTEMC)
        int registeredClocks = 0;

		double inputDelay = 0.0;
		const char* scName = getenv("BDW_SIM_CONFIG");
		if (!scName) scName = "?";
		if ( qbhVerilogInputDelay( qbhEmptyHandle, scName, &inputDelay ) != qbhOK )
			inputDelay = 0.0;

		// Try to register the boolean input ports as clocks.
		int clk_is_clock = esc_link_clockgen( &clk, sc_time( 0, SC_NS ), module_path, sim_domain, "clk" );
		int rst_is_clock = esc_link_clockgen( &rst, sc_time( 0, SC_NS ), module_path, sim_domain, "rst" );
		int find_max_x_vld_is_clock = esc_link_clockgen( &find_max_x_vld, sc_time( 0, SC_NS ), module_path, sim_domain, "find_max_x_vld" );
		int find_max_return_busy_is_clock = esc_link_clockgen( &find_max_return_busy, sc_time( 0, SC_NS ), module_path, sim_domain, "find_max_return_busy" );
		int add_one_x_out_busy_is_clock = esc_link_clockgen( &add_one_x_out_busy, sc_time( 0, SC_NS ), module_path, sim_domain, "add_one_x_out_busy" );
		int add_one_return_in_vld_is_clock = esc_link_clockgen( &add_one_return_in_vld, sc_time( 0, SC_NS ), module_path, sim_domain, "add_one_return_in_vld" );

		esc_link_signals( &rst, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &find_max_x_busy, module_path, sim_domain, true );
		esc_link_signals( &find_max_x_vld, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &find_max_x_data, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &find_max_return_busy, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &find_max_return_vld, module_path, sim_domain, true );
		esc_link_signals( &find_max_return_data, module_path, sim_domain, true );
		esc_link_signals( &add_one_x_out_busy, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &add_one_x_out_vld, module_path, sim_domain, true );
		esc_link_signals( &add_one_x_out_data, module_path, sim_domain, true );
		esc_link_signals( &add_one_return_in_busy, module_path, sim_domain, true );
		esc_link_signals( &add_one_return_in_vld, module_path, sim_domain, true, inputDelay );
		esc_link_signals( &add_one_return_in_data, module_path, sim_domain, true, inputDelay );
		

		if ( clk_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = clk[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, clk.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "find_max", "clk", scName ) ) {
			esc_report_error( esc_error, "The port 'clk' on module 'find_max'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( rst_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = rst[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, rst.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "find_max", "rst", scName ) ) {
			esc_report_error( esc_error, "The port 'rst' on module 'find_max'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( find_max_x_vld_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = find_max_x_vld[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, find_max_x_vld.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "find_max", "vld", scName ) ) {
			esc_report_error( esc_error, "The port 'vld' on module 'find_max'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( find_max_return_busy_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = find_max_return_busy[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, find_max_return_busy.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "find_max", "busy", scName ) ) {
			esc_report_error( esc_error, "The port 'busy' on module 'find_max'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( add_one_x_out_busy_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = add_one_x_out_busy[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, add_one_x_out_busy.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "find_max", "busy", scName ) ) {
			esc_report_error( esc_error, "The port 'busy' on module 'find_max'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}
		if ( add_one_return_in_vld_is_clock )
		{
			sc_signal_in_if< bool > *clock_inif = add_one_return_in_vld[0];
			sc_clock *clock_module = dynamic_cast<sc_clock*>(clock_inif);
			esc_hub_register_clock( clock_module, esc_alledge, 0, module_path, sim_domain, add_one_return_in_vld.basename() );
			++registeredClocks;
		} else if ( qbhGetPortUsedAsClock( qbhEmptyHandle, "find_max", "vld", scName ) ) {
			esc_report_error( esc_error, "The port 'vld' on module 'find_max'\n\tis used as a clock in the design,\n\tbut is not connected to an sc_clock");
		}


        if ( registeredClocks == 0 )
		{
			esc_report_error( esc_fatal, 
				"The clock port in module find_max must have\n"
				"an sc_clock bound to it to make cosimulation work" );
		}
#endif
    }

#if defined(XM_SYSTEMC) || defined(NC_SYSTEMC)
    const char* hdl_name() const 
    {
        if ( getenv("BDW_NO_NCWRAPPER") )
        {
            return "find_max"; 
        }
        else
        {
            return "find_max_nc_cosim"; 
        }
    } 
    find_max_cosim( sc_module_name name )
        : xmsc_foreign_module(name)
#else
	find_max_cosim( sc_module_name in_name=sc_module_name(sc_gen_unique_name(" find_max") ) )
		: sc_module(in_name)
#endif
		  ,clk("clk")
		  	,rst("rst")
		  	,find_max_x_busy("find_max_x_busy")
		  	,find_max_x_vld("find_max_x_vld")
		  	,find_max_x_data("find_max_x_data")
		  	,find_max_return_busy("find_max_return_busy")
		  	,find_max_return_vld("find_max_return_vld")
		  	,find_max_return_data("find_max_return_data")
		  	,add_one_x_out_busy("add_one_x_out_busy")
		  	,add_one_x_out_vld("add_one_x_out_vld")
		  	,add_one_x_out_data("add_one_x_out_data")
		  	,add_one_return_in_busy("add_one_return_in_busy")
		  	,add_one_return_in_vld("add_one_return_in_vld")
		  	,add_one_return_in_data("add_one_return_in_data")
		  	

    {
    };
};

int find_max_cosim::numLinked = 0;
find_max_cosim::StringPair find_max_cosim::instanceNames[] = {
	{ NULL, NULL, false } };

#endif
