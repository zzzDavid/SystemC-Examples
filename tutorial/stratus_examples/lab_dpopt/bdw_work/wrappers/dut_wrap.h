/****************************************************************************
*
*  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/


#ifndef _DUT_WRAP_INCLUDED_
#define _DUT_WRAP_INCLUDED_


/* Save ioConfig define values for parent module and define those for this module's ioConfigs. */


#if defined(CYNTHVLG) 

#include <systemc.h>

#define dut_wrapper dut

/* This is the section that is seen during processing by cynthVLG of a module
 * that instantiates the module defined by this wrapper.
 */
SC_MODULE(dut)
{
public:
	sc_in< bool > clk;
	sc_in< bool > rst;
	sc_out< bool > din_busy;
	sc_in< bool > din_vld;
	sc_in< sc_uint< 8 > > din_data_a;
	sc_in< sc_uint< 8 > > din_data_b;
	sc_in< sc_uint< 8 > > din_data_c;
	sc_in< sc_uint< 8 > > din_data_d;
	sc_in< sc_uint< 8 > > din_data_e;
	sc_in< sc_uint< 8 > > din_data_f;
	sc_in< sc_uint< 8 > > din_data_g;
	sc_in< sc_uint< 8 > > din_data_h;
	sc_in< bool > dout_busy;
	sc_out< bool > dout_vld;
	sc_out< sc_uint< 32 > > dout_data;

	SC_CTOR(dut);
};

#elif defined(CYNTHHL) || defined(BDW_EXTRACT)

/* This is the section seen during processing by cynthHL or bdw_extract of a module 
 * that instantiates the module defined by this wrapper.
 */
#include <systemc.h>

#include "input_t.h"
#include "cynw_p2p.h"
#include "cyn_enums.h"


#define dut_wrapper dut

/* Only port declarations are required for nested modules.
 */
SC_MODULE(dut)
{
public:
	sc_in< bool > clk;
	sc_in< bool > rst;
	cynw::cynw_p2p_base_in <input_t, CYN::cyn_enum <(int)1 > > din;
	cynw::cynw_p2p_base_out <sc_dt::sc_uint <(int)32 >, CYN::cyn_enum <(int)1 > > dout;


	SC_HAS_PROCESS(dut);
    	dut_wrapper( sc_module_name name = sc_module_name( sc_gen_unique_name("dut")) );
};

#else

#include <esc.h>


/* This is the section seen during processing by gcc either when the module
 * itself is compiled, or when a module that instantiates it is compiled.
 */

struct dut;
struct dut_cosim;
struct dut_cycsim;
struct dut_rtl;

#ifdef BDW_COWARE
#include	"dut_coware.h"
#endif

#include "input_t.h"
#include "cynw_p2p.h"
#include "cyn_enums.h"


// Declaration of wrapper with BEH level ports

SC_MODULE(dut_wrapper)
{
public:

	sc_in< bool > clk;
	sc_in< bool > rst;
	cynw::cynw_p2p_base_in <input_t, CYN::cyn_enum <(int)1 > > din;
	cynw::cynw_p2p_base_out <sc_dt::sc_uint <(int)32 >, CYN::cyn_enum <(int)1 > > dout;

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    sc_signal< sc_uint< 8 > > din_data_a;
    sc_signal< sc_uint< 8 > > din_data_b;
    sc_signal< sc_uint< 8 > > din_data_c;
    sc_signal< sc_uint< 8 > > din_data_d;
    sc_signal< sc_uint< 8 > > din_data_e;
    sc_signal< sc_uint< 8 > > din_data_f;
    sc_signal< sc_uint< 8 > > din_data_g;
    sc_signal< sc_uint< 8 > > din_data_h;

    
	enum Representation { BDWRep_None, BDWRep_Behavioral, BDWRep_RTL_C, BDWRep_RTL_HDL, BDWRep_Gates, BDWRep_CYC_HDL };
	static const char * simConfigName();
	static Representation lookupRepresentation( const char* instName );
	// create the netlist
    void InitInstances( );
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

	void CloseTrace();
	void start_of_simulation();
	void end_of_simulation();


    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    void thread_din_data_a();
    void thread_din_data_b();
    void thread_din_data_c();
    void thread_din_data_d();
    void thread_din_data_e();
    void thread_din_data_f();
    void thread_din_data_g();
    void thread_din_data_h();


	SC_HAS_PROCESS(dut_wrapper);

    	dut_wrapper( sc_module_name name = sc_module_name( sc_gen_unique_name("dut")) )
		: sc_module(name)
		  ,clk("clk")
		  	,rst("rst")
		  	,din("din")
		  	,dout("dout")
		  	

		  ,dut0(0), dut_cosim0(0), dut_rtl0(0), dut_cycsim0(0)
		

    {
        InitInstances( );
		InitThreads();
    }


    // destructor
    ~dut_wrapper()
    {
        DeleteInstances();

		CloseTrace();
    }

    bool isBEH() { return ( dut_wrapper::lookupRepresentation( name() ) == BDWRep_Behavioral ); }
    bool isRTL_C() { return ( dut_wrapper::lookupRepresentation( name() ) == BDWRep_RTL_C ); }
    bool isRTL_V() { return ( dut_wrapper::lookupRepresentation( name() ) == BDWRep_RTL_HDL ); }
    bool isGATES_V() { return ( dut_wrapper::lookupRepresentation( name() ) == BDWRep_Gates ); }
	bool isCosim() { return ( isRTL_V() || isGATES_V() ); }
    bool isCycsim() { return ( dut_wrapper::lookupRepresentation( name() ) == BDWRep_CYC_HDL ); }

	dut* behModule() { return dut0; }
	dut_cosim* cosimModule() { return dut_cosim0; }
	dut_cycsim* cycsimModule() { return dut_cycsim0; }
	dut_rtl* rtlModule() { return dut_rtl0; }

	dut* dut0;
	dut_cosim* dut_cosim0;
	dut_rtl* dut_rtl0;
	dut_cycsim* dut_cycsim0;
};

// Declaration of wrapper with RTL level ports

SC_MODULE(dut_wrapper_r)
{
public:

	sc_in< bool > clk;
	sc_in< bool > rst;
	sc_out< bool > din_busy;
	sc_in< bool > din_vld;
	sc_in< sc_uint< 8 > > din_data_a;
	sc_in< sc_uint< 8 > > din_data_b;
	sc_in< sc_uint< 8 > > din_data_c;
	sc_in< sc_uint< 8 > > din_data_d;
	sc_in< sc_uint< 8 > > din_data_e;
	sc_in< sc_uint< 8 > > din_data_f;
	sc_in< sc_uint< 8 > > din_data_g;
	sc_in< sc_uint< 8 > > din_data_h;
	sc_in< bool > dout_busy;
	sc_out< bool > dout_vld;
	sc_out< sc_uint< 32 > > dout_data;

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    sc_signal< input_t > din_data;

    
	enum Representation { BDWRep_None, BDWRep_Behavioral, BDWRep_RTL_C, BDWRep_RTL_HDL, BDWRep_Gates, BDWRep_CYC_HDL };

	static const char * simConfigName();
	static Representation lookupRepresentation( const char* instName );
	// create the netlist
    void InitInstances();
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

	void CloseTrace();
	void start_of_simulation();
	void end_of_simulation();


    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    void thread_din_data();


	SC_HAS_PROCESS(dut_wrapper_r);

	dut_wrapper_r( sc_module_name name = sc_module_name( sc_gen_unique_name("dut")) )
		: sc_module(name)
		  ,clk("clk")
		  	,rst("rst")
		  	,din_busy("din_busy")
		  	,din_vld("din_vld")
		  	,din_data_a("din_data_a"),
		  din_data_b("din_data_b"),
		  din_data_c("din_data_c"),
		  din_data_d("din_data_d"),
		  din_data_e("din_data_e"),
		  din_data_f("din_data_f"),
		  din_data_g("din_data_g"),
		  din_data_h("din_data_h")
		  	,dout_busy("dout_busy")
		  	,dout_vld("dout_vld")
		  	,dout_data("dout_data")
		  	

		  ,dut0(0), dut_cosim0(0), dut_rtl0(0), dut_cycsim0(0)
		

    {
        InitInstances();
        InitThreads();
		end_module();
    }


    // destructor
    ~dut_wrapper_r()
    {
        DeleteInstances();

		CloseTrace();
    }

    bool isBEH() { return ( dut_wrapper_r::lookupRepresentation( name() ) == BDWRep_Behavioral ); }
    bool isRTL_C() { return ( dut_wrapper_r::lookupRepresentation( name() ) == BDWRep_RTL_C ); }
    bool isRTL_V() { return ( dut_wrapper_r::lookupRepresentation( name() ) == BDWRep_RTL_HDL ); }
    bool isGATES_V() { return ( dut_wrapper_r::lookupRepresentation( name() ) == BDWRep_Gates ); }
	bool isCosim() { return ( isRTL_V() || isGATES_V() ); }
    bool isCycsim() { return ( dut_wrapper_r::lookupRepresentation( name() ) == BDWRep_CYC_HDL ); }

	dut* behModule() { return dut0; }
	dut_cosim* cosimModule() { return dut_cosim0; }
	dut_cycsim* cycsimModule() { return dut_cycsim0; }
	dut_rtl* rtlModule() { return dut_rtl0; }

protected:
	dut* dut0;
	dut_cosim* dut_cosim0;
	dut_rtl* dut_rtl0;
	dut_cycsim* dut_cycsim0;
};

#endif

/* Restore ioConfig define values for parent module. */

#endif /*  */
