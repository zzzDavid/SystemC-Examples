/****************************************************************************
*
*  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/


#ifndef _ADD_ONE_WRAP_INCLUDED_
#define _ADD_ONE_WRAP_INCLUDED_


/* Save ioConfig define values for parent module and define those for this module's ioConfigs. */


#if defined(STRATUS_VLG) 

#include <systemc.h>

#define add_one_wrapper add_one

/* This is the section that is seen during processing by stratus_vlg of a module
 * that instantiates the module defined by this wrapper.
 */
SC_MODULE(add_one)
{
public:
	sc_in< bool > clk;
	sc_in< bool > rst;
	sc_out< bool > add_one_x_busy;
	sc_in< bool > add_one_x_vld;
	sc_in< sc_int< 32 > > add_one_x_data;
	sc_in< bool > add_one_return_busy;
	sc_out< bool > add_one_return_vld;
	sc_out< sc_int< 32 > > add_one_return_data;

	SC_CTOR(add_one);
};

#elif defined(CYNTHHL) || defined(BDW_EXTRACT)

/* This is the section seen during processing by stratus_hls or bdw_extract of a module 
 * that instantiates the module defined by this wrapper.
 */
#include <systemc.h>

#include "cynw_p2p.h"
#include "hls_enums.h"


#define add_one_wrapper add_one

/* Only port declarations are required for nested modules.
 */
SC_MODULE(add_one)
{
public:
	sc_in< bool > clk;
	sc_in< bool > rst;
	cynw::cynw_p2p_base_in <sc_dt::sc_int <(int)32 >, HLS::hls_enum <(int)1 > > add_one_x;
	cynw::cynw_p2p_base_out <sc_dt::sc_int <(int)32 >, HLS::hls_enum <(int)1 > > add_one_return;


	SC_HAS_PROCESS(add_one);
        add_one_wrapper( sc_core::sc_module_name name, sc_int< 32 > _A[10] );
};

#else

#include <esc.h>


/* This is the section seen during processing by gcc either when the module
 * itself is compiled, or when a module that instantiates it is compiled.
 */

struct add_one;
struct add_one_cosim;
struct add_one_rtl;

#ifdef BDW_COWARE
#include	"add_one_coware.h"
#endif

#include "cynw_p2p.h"
#include "hls_enums.h"


// Declaration of wrapper with BEH level ports

SC_MODULE(add_one_wrapper)
{
public:

	sc_in< bool > clk;
	sc_in< bool > rst;
	cynw::cynw_p2p_base_in <sc_dt::sc_int <(int)32 >, HLS::hls_enum <(int)1 > > add_one_x;
	cynw::cynw_p2p_base_out <sc_dt::sc_int <(int)32 >, HLS::hls_enum <(int)1 > > add_one_return;

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    
    
	enum Representation { BDWRep_None, BDWRep_Behavioral, BDWRep_RTL_C, BDWRep_RTL_HDL, BDWRep_Gates, BDWRep_CYC_HDL };
	static const char * simConfigName();
	static Representation lookupRepresentation( const char* instName );
	// create the netlist
    void InitInstances( sc_int< 32 > _A[10]);
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

	void CloseTrace();
	void start_of_simulation();
	void end_of_simulation();


    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    

	SC_HAS_PROCESS(add_one_wrapper);

        add_one_wrapper( sc_core::sc_module_name name, sc_int< 32 > _A[10] )
		: sc_module(name)
		  ,clk("clk")
		  	,rst("rst")
		  	,add_one_x("add_one_x")
		  	,add_one_return("add_one_return")
		  	

          		  ,add_one0(0), add_one_cosim0(0), add_one_rtl0(0)
		

    {
        InitInstances( _A);
		InitThreads();
    }


    // destructor
    ~add_one_wrapper()
    {
        DeleteInstances();

		CloseTrace();
    }

    bool isBEH() { return ( add_one_wrapper::lookupRepresentation( name() ) == BDWRep_Behavioral ); }
    bool isRTL_C() { return ( add_one_wrapper::lookupRepresentation( name() ) == BDWRep_RTL_C ); }
    bool isRTL_V() { return ( add_one_wrapper::lookupRepresentation( name() ) == BDWRep_RTL_HDL ); }
    bool isGATES_V() { return ( add_one_wrapper::lookupRepresentation( name() ) == BDWRep_Gates ); }
	bool isCosim() { return ( isRTL_V() || isGATES_V() ); }
    
        
#ifdef add_one_INTERNAL
	add_one* behModule() { return add_one0; }
#else
	add_one* behModule() { return add_one0; }
#endif
	add_one_cosim* cosimModule() { return add_one_cosim0; }
    	add_one_rtl* rtlModule() { return add_one_rtl0; }

#ifdef add_one_INTERNAL
	add_one* add_one0;
#else
	add_one* add_one0;
#endif
	add_one_cosim* add_one_cosim0;
	add_one_rtl* add_one_rtl0;
	};

// Declaration of wrapper with RTL level ports

SC_MODULE(add_one_wrapper_r)
{
public:

	sc_in< bool > clk;
	sc_in< bool > rst;
	sc_out< bool > add_one_x_busy;
	sc_in< bool > add_one_x_vld;
	sc_in< sc_int< 32 > > add_one_x_data;
	sc_in< bool > add_one_return_busy;
	sc_out< bool > add_one_return_vld;
	sc_out< sc_int< 32 > > add_one_return_data;

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    
    
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
    

	SC_HAS_PROCESS(add_one_wrapper_r);

	add_one_wrapper_r( sc_module_name name = sc_module_name( sc_gen_unique_name("add_one")) )
		: sc_module(name)
		  ,clk("clk")
		  	,rst("rst")
		  	,add_one_x_busy("add_one_x_busy")
		  	,add_one_x_vld("add_one_x_vld")
		  	,add_one_x_data("add_one_x_data")
		  	,add_one_return_busy("add_one_return_busy")
		  	,add_one_return_vld("add_one_return_vld")
		  	,add_one_return_data("add_one_return_data")
		  	

          		  ,add_one0(0), add_one_cosim0(0), add_one_rtl0(0)
		

    {
        InitInstances();
        InitThreads();
		end_module();
    }


    // destructor
    ~add_one_wrapper_r()
    {
        DeleteInstances();

		CloseTrace();
    }

    bool isBEH() { return ( add_one_wrapper_r::lookupRepresentation( name() ) == BDWRep_Behavioral ); }
    bool isRTL_C() { return ( add_one_wrapper_r::lookupRepresentation( name() ) == BDWRep_RTL_C ); }
    bool isRTL_V() { return ( add_one_wrapper_r::lookupRepresentation( name() ) == BDWRep_RTL_HDL ); }
    bool isGATES_V() { return ( add_one_wrapper_r::lookupRepresentation( name() ) == BDWRep_Gates ); }
	bool isCosim() { return ( isRTL_V() || isGATES_V() ); }
	
#ifdef add_one_INTERNAL
	add_one* behModule() { return add_one0; }
#else
	add_one* behModule() { return add_one0; }
#endif
	add_one_cosim* cosimModule() { return add_one_cosim0; }
		add_one_rtl* rtlModule() { return add_one_rtl0; }

protected:
#ifdef add_one_INTERNAL
	add_one* add_one0;
#else
	add_one* add_one0;
#endif
	add_one_cosim* add_one_cosim0;
	add_one_rtl* add_one_rtl0;
	};

#endif

/* Restore ioConfig define values for parent module. */

#endif /*  */
