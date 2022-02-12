/****************************************************************************
*
*  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/


#ifndef _FIND_MAX_WRAP_INCLUDED_
#define _FIND_MAX_WRAP_INCLUDED_


/* Save ioConfig define values for parent module and define those for this module's ioConfigs. */


#if defined(STRATUS_VLG) 

#include <systemc.h>

#define find_max_wrapper find_max

/* This is the section that is seen during processing by stratus_vlg of a module
 * that instantiates the module defined by this wrapper.
 */
SC_MODULE(find_max)
{
public:
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

	SC_CTOR(find_max);
};

#elif defined(CYNTHHL) || defined(BDW_EXTRACT)

/* This is the section seen during processing by stratus_hls or bdw_extract of a module 
 * that instantiates the module defined by this wrapper.
 */
#include <systemc.h>

#include "cynw_p2p.h"
#include "hls_enums.h"


#define find_max_wrapper find_max

/* Only port declarations are required for nested modules.
 */
SC_MODULE(find_max)
{
public:
	sc_in< bool > clk;
	sc_in< bool > rst;
	cynw::cynw_p2p_base_in <sc_dt::sc_int <(int)32 >, HLS::hls_enum <(int)1 > > find_max_x;
	cynw::cynw_p2p_base_out <sc_dt::sc_int <(int)32 >, HLS::hls_enum <(int)1 > > find_max_return;
	cynw::cynw_p2p_base_out <sc_dt::sc_int <(int)32 >, HLS::hls_enum <(int)1 > > add_one_x_out;
	cynw::cynw_p2p_base_in <sc_dt::sc_int <(int)32 >, HLS::hls_enum <(int)1 > > add_one_return_in;


	SC_HAS_PROCESS(find_max);
        find_max_wrapper( sc_core::sc_module_name name, sc_int< 32 > _A[10], sc_int< 32 > _B[10] );
};

#else

#include <esc.h>


/* This is the section seen during processing by gcc either when the module
 * itself is compiled, or when a module that instantiates it is compiled.
 */

struct find_max;
struct find_max_cosim;
struct find_max_rtl;

#ifdef BDW_COWARE
#include	"find_max_coware.h"
#endif

#include "cynw_p2p.h"
#include "hls_enums.h"


// Declaration of wrapper with BEH level ports

SC_MODULE(find_max_wrapper)
{
public:

	sc_in< bool > clk;
	sc_in< bool > rst;
	cynw::cynw_p2p_base_in <sc_dt::sc_int <(int)32 >, HLS::hls_enum <(int)1 > > find_max_x;
	cynw::cynw_p2p_base_out <sc_dt::sc_int <(int)32 >, HLS::hls_enum <(int)1 > > find_max_return;
	cynw::cynw_p2p_base_out <sc_dt::sc_int <(int)32 >, HLS::hls_enum <(int)1 > > add_one_x_out;
	cynw::cynw_p2p_base_in <sc_dt::sc_int <(int)32 >, HLS::hls_enum <(int)1 > > add_one_return_in;

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    
    
	enum Representation { BDWRep_None, BDWRep_Behavioral, BDWRep_RTL_C, BDWRep_RTL_HDL, BDWRep_Gates, BDWRep_CYC_HDL };
	static const char * simConfigName();
	static Representation lookupRepresentation( const char* instName );
	// create the netlist
    void InitInstances( sc_int< 32 > _A[10], sc_int< 32 > _B[10]);
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

	void CloseTrace();
	void start_of_simulation();
	void end_of_simulation();


    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    

	SC_HAS_PROCESS(find_max_wrapper);

        find_max_wrapper( sc_core::sc_module_name name, sc_int< 32 > _A[10], sc_int< 32 > _B[10] )
		: sc_module(name)
		  ,clk("clk")
		  	,rst("rst")
		  	,find_max_x("find_max_x")
		  	,find_max_return("find_max_return")
		  	,add_one_x_out("add_one_x_out")
		  	,add_one_return_in("add_one_return_in")
		  	

          		  ,find_max0(0), find_max_cosim0(0), find_max_rtl0(0)
		

    {
        InitInstances( _A, _B);
		InitThreads();
    }


    // destructor
    ~find_max_wrapper()
    {
        DeleteInstances();

		CloseTrace();
    }

    bool isBEH() { return ( find_max_wrapper::lookupRepresentation( name() ) == BDWRep_Behavioral ); }
    bool isRTL_C() { return ( find_max_wrapper::lookupRepresentation( name() ) == BDWRep_RTL_C ); }
    bool isRTL_V() { return ( find_max_wrapper::lookupRepresentation( name() ) == BDWRep_RTL_HDL ); }
    bool isGATES_V() { return ( find_max_wrapper::lookupRepresentation( name() ) == BDWRep_Gates ); }
	bool isCosim() { return ( isRTL_V() || isGATES_V() ); }
    
        
#ifdef find_max_INTERNAL
	find_max* behModule() { return find_max0; }
#else
	find_max* behModule() { return find_max0; }
#endif
	find_max_cosim* cosimModule() { return find_max_cosim0; }
    	find_max_rtl* rtlModule() { return find_max_rtl0; }

#ifdef find_max_INTERNAL
	find_max* find_max0;
#else
	find_max* find_max0;
#endif
	find_max_cosim* find_max_cosim0;
	find_max_rtl* find_max_rtl0;
	};

// Declaration of wrapper with RTL level ports

SC_MODULE(find_max_wrapper_r)
{
public:

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
    

	SC_HAS_PROCESS(find_max_wrapper_r);

	find_max_wrapper_r( sc_module_name name = sc_module_name( sc_gen_unique_name("find_max")) )
		: sc_module(name)
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
		  	

          		  ,find_max0(0), find_max_cosim0(0), find_max_rtl0(0)
		

    {
        InitInstances();
        InitThreads();
		end_module();
    }


    // destructor
    ~find_max_wrapper_r()
    {
        DeleteInstances();

		CloseTrace();
    }

    bool isBEH() { return ( find_max_wrapper_r::lookupRepresentation( name() ) == BDWRep_Behavioral ); }
    bool isRTL_C() { return ( find_max_wrapper_r::lookupRepresentation( name() ) == BDWRep_RTL_C ); }
    bool isRTL_V() { return ( find_max_wrapper_r::lookupRepresentation( name() ) == BDWRep_RTL_HDL ); }
    bool isGATES_V() { return ( find_max_wrapper_r::lookupRepresentation( name() ) == BDWRep_Gates ); }
	bool isCosim() { return ( isRTL_V() || isGATES_V() ); }
	
#ifdef find_max_INTERNAL
	find_max* behModule() { return find_max0; }
#else
	find_max* behModule() { return find_max0; }
#endif
	find_max_cosim* cosimModule() { return find_max_cosim0; }
		find_max_rtl* rtlModule() { return find_max_rtl0; }

protected:
#ifdef find_max_INTERNAL
	find_max* find_max0;
#else
	find_max* find_max0;
#endif
	find_max_cosim* find_max_cosim0;
	find_max_rtl* find_max_rtl0;
	};

#endif

/* Restore ioConfig define values for parent module. */

#endif /*  */
