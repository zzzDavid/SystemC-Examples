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


#if defined(STRATUS_VLG) 

#include <systemc.h>

#define dut_wrapper dut

/* This is the section that is seen during processing by stratus_vlg of a module
 * that instantiates the module defined by this wrapper.
 */
SC_MODULE(dut)
{
public:
	sc_in< bool > clk;
	sc_in< bool > rst;
	sc_out< bool > finish;
	sc_in< bool > find_max_x_out_busy;
	sc_out< bool > find_max_x_out_vld;
	sc_out< sc_int< 32 > > find_max_x_out_data;
	sc_out< bool > find_max_return_in_busy;
	sc_in< bool > find_max_return_in_vld;
	sc_in< sc_int< 32 > > find_max_return_in_data;

	SC_CTOR(dut);
};

#elif defined(CYNTHHL) || defined(BDW_EXTRACT)

/* This is the section seen during processing by stratus_hls or bdw_extract of a module 
 * that instantiates the module defined by this wrapper.
 */
#include <systemc.h>

#include "cynw_p2p.h"
#include "hls_enums.h"


#define dut_wrapper dut

/* Only port declarations are required for nested modules.
 */
SC_MODULE(dut)
{
public:
	sc_in< bool > clk;
	sc_in< bool > rst;
	sc_out< bool > finish;
	cynw::cynw_p2p_base_out <sc_dt::sc_int <(int)32 >, HLS::hls_enum <(int)1 > > find_max_x_out;
	cynw::cynw_p2p_base_in <sc_dt::sc_int <(int)32 >, HLS::hls_enum <(int)1 > > find_max_return_in;


	SC_HAS_PROCESS(dut);
        dut_wrapper( sc_core::sc_module_name name, sc_int< 32 > _A[10], sc_int< 32 > _B[10], sc_int< 32 > _D[10] );
};

#else

#include <esc.h>


/* This is the section seen during processing by gcc either when the module
 * itself is compiled, or when a module that instantiates it is compiled.
 */

struct dut;
struct dut_cosim;
struct dut_rtl;

#ifdef BDW_COWARE
#include	"dut_coware.h"
#endif

#include "cynw_p2p.h"
#include "hls_enums.h"


// Declaration of wrapper with BEH level ports

SC_MODULE(dut_wrapper)
{
public:

	sc_in< bool > clk;
	sc_in< bool > rst;
	sc_out< bool > finish;
	cynw::cynw_p2p_base_out <sc_dt::sc_int <(int)32 >, HLS::hls_enum <(int)1 > > find_max_x_out;
	cynw::cynw_p2p_base_in <sc_dt::sc_int <(int)32 >, HLS::hls_enum <(int)1 > > find_max_return_in;

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    
    
	enum Representation { BDWRep_None, BDWRep_Behavioral, BDWRep_RTL_C, BDWRep_RTL_HDL, BDWRep_Gates, BDWRep_CYC_HDL };
	static const char * simConfigName();
	static Representation lookupRepresentation( const char* instName );
	// create the netlist
    void InitInstances( sc_int< 32 > _A[10], sc_int< 32 > _B[10], sc_int< 32 > _D[10]);
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

	void CloseTrace();
	void start_of_simulation();
	void end_of_simulation();


    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    

	SC_HAS_PROCESS(dut_wrapper);

        dut_wrapper( sc_core::sc_module_name name, sc_int< 32 > _A[10], sc_int< 32 > _B[10], sc_int< 32 > _D[10] )
		: sc_module(name)
		  ,clk("clk")
		  	,rst("rst")
		  	,finish("finish")
		  	,find_max_x_out("find_max_x_out")
		  	,find_max_return_in("find_max_return_in")
		  	

          		  ,dut0(0), dut_cosim0(0), dut_rtl0(0)
		

    {
        InitInstances( _A, _B, _D);
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
    
        
#ifdef dut_INTERNAL
	dut* behModule() { return dut0; }
#else
	dut* behModule() { return dut0; }
#endif
	dut_cosim* cosimModule() { return dut_cosim0; }
    	dut_rtl* rtlModule() { return dut_rtl0; }

#ifdef dut_INTERNAL
	dut* dut0;
#else
	dut* dut0;
#endif
	dut_cosim* dut_cosim0;
	dut_rtl* dut_rtl0;
	};

// Declaration of wrapper with RTL level ports

SC_MODULE(dut_wrapper_r)
{
public:

	sc_in< bool > clk;
	sc_in< bool > rst;
	sc_out< bool > finish;
	sc_in< bool > find_max_x_out_busy;
	sc_out< bool > find_max_x_out_vld;
	sc_out< sc_int< 32 > > find_max_x_out_data;
	sc_out< bool > find_max_return_in_busy;
	sc_in< bool > find_max_return_in_vld;
	sc_in< sc_int< 32 > > find_max_return_in_data;

    
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
    

	SC_HAS_PROCESS(dut_wrapper_r);

	dut_wrapper_r( sc_module_name name = sc_module_name( sc_gen_unique_name("dut")) )
		: sc_module(name)
		  ,clk("clk")
		  	,rst("rst")
		  	,finish("finish")
		  	,find_max_x_out_busy("find_max_x_out_busy")
		  	,find_max_x_out_vld("find_max_x_out_vld")
		  	,find_max_x_out_data("find_max_x_out_data")
		  	,find_max_return_in_busy("find_max_return_in_busy")
		  	,find_max_return_in_vld("find_max_return_in_vld")
		  	,find_max_return_in_data("find_max_return_in_data")
		  	

          		  ,dut0(0), dut_cosim0(0), dut_rtl0(0)
		

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
	
#ifdef dut_INTERNAL
	dut* behModule() { return dut0; }
#else
	dut* behModule() { return dut0; }
#endif
	dut_cosim* cosimModule() { return dut_cosim0; }
		dut_rtl* rtlModule() { return dut_rtl0; }

protected:
#ifdef dut_INTERNAL
	dut* dut0;
#else
	dut* dut0;
#endif
	dut_cosim* dut_cosim0;
	dut_rtl* dut_rtl0;
	};

#endif

/* Restore ioConfig define values for parent module. */

#endif /*  */
