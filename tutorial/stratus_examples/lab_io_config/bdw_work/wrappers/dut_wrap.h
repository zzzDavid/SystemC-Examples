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

#if !defined(ioConfig_TLM) && !defined(ioConfig_PIN)
#if defined(_p_ioConfig_TLM)
#define ioConfig_TLM 1
#endif
#if defined(_p_ioConfig_PIN)
#define ioConfig_PIN 1
#endif
#endif


/* Save ioConfig define values for parent module and define those for this module's ioConfigs. */
#if defined(ioConfig_TLM)
#if defined(ioConfig) && defined(_wrap_ioConfig) && !defined(_local_ioConfig)
#undef ioConfig
#define ioConfig _local_ioConfig
#define _local_ioConfig TLM
#endif
#endif
#if defined(ioConfig_PIN)
#if defined(ioConfig) && defined(_wrap_ioConfig) && !defined(_local_ioConfig)
#undef ioConfig
#define ioConfig _local_ioConfig
#define _local_ioConfig PIN
#endif
#endif


#if defined(CYNTHVLG) 

#include <systemc.h>

#define dut_wrapper dut

/* This is the section that is seen during processing by cynthVLG of a module
 * that instantiates the module defined by this wrapper.
 */
SC_MODULE(dut)
{
public:
	
#if defined ( ioConfig_TLM )
	
	sc_in< bool > clk;
	sc_in< bool > rst;
	
	
#else
	
	sc_in< bool > clk;
	sc_in< bool > rst;
	
#endif

	SC_CTOR(dut);
};

#elif defined(CYNTHHL) || defined(BDW_EXTRACT)

/* This is the section seen during processing by cynthHL or bdw_extract of a module 
 * that instantiates the module defined by this wrapper.
 */
#include <systemc.h>

#include "cynw_p2p.h"
#include "cyn_enums.h"


#define dut_wrapper dut

/* Only port declarations are required for nested modules.
 */
SC_MODULE(dut)
{
public:
	
#if defined ( ioConfig_TLM )
	
	sc_in< bool > clk;
	sc_in< bool > rst;
	cynw::cynw_p2p_base_in <sc_dt::sc_uint <(int)8 >, CYN::cyn_enum <(int)2 > > din;
	cynw::cynw_p2p_base_out <sc_dt::sc_uint <(int)11 >, CYN::cyn_enum <(int)2 > > dout;
	
	
#else
	
	sc_in< bool > clk;
	sc_in< bool > rst;
	cynw::cynw_p2p_base_in <sc_dt::sc_uint <(int)8 >, CYN::cyn_enum <(int)2 > > din;
	cynw::cynw_p2p_base_out <sc_dt::sc_uint <(int)11 >, CYN::cyn_enum <(int)2 > > dout;
	
#endif


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

#include "cynw_p2p.h"
#include "cyn_enums.h"


// Declaration of wrapper with BEH level ports

SC_MODULE(dut_wrapper)
{
public:

	
#if defined ( ioConfig_TLM )
	
	sc_in< bool > clk;
	sc_in< bool > rst;
	cynw::cynw_p2p_base_in <sc_dt::sc_uint <(int)8 >, CYN::cyn_enum <(int)2 > > din;
	cynw::cynw_p2p_base_out <sc_dt::sc_uint <(int)11 >, CYN::cyn_enum <(int)2 > > dout;
	
	
#else
	
	sc_in< bool > clk;
	sc_in< bool > rst;
	cynw::cynw_p2p_base_in <sc_dt::sc_uint <(int)8 >, CYN::cyn_enum <(int)2 > > din;
	cynw::cynw_p2p_base_out <sc_dt::sc_uint <(int)11 >, CYN::cyn_enum <(int)2 > > dout;
	
#endif

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    
#if defined ( ioConfig_TLM )
    
    
    
#else
    
    
#endif

    
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
    
#if defined ( ioConfig_TLM )
    
    
    
#else
    
    
#endif


	SC_HAS_PROCESS(dut_wrapper);

    	dut_wrapper( sc_module_name name = sc_module_name( sc_gen_unique_name("dut")) )
		: sc_module(name)
		  
#if defined ( ioConfig_TLM )
		  
		  ,clk("clk")
		  	,rst("rst")
		  	,din("din")
		  	,dout("dout")
		  	
		  
#else
		  
		  ,clk("clk")
		  	,rst("rst")
		  	,din("din")
		  	,dout("dout")
		  	
#endif
		  

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

	
#if defined ( ioConfig_TLM )
	
	sc_in< bool > clk;
	sc_in< bool > rst;
	
	
#else
	
	sc_in< bool > clk;
	sc_in< bool > rst;
	
#endif

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    
#if defined ( ioConfig_TLM )
    
    
    
#else
    
    
#endif

    
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
    
#if defined ( ioConfig_TLM )
    
    
    
#else
    
    
#endif


	SC_HAS_PROCESS(dut_wrapper_r);

	dut_wrapper_r( sc_module_name name = sc_module_name( sc_gen_unique_name("dut")) )
		: sc_module(name)
		  
#if defined ( ioConfig_TLM )
		  
		  ,clk("clk")
		  	,rst("rst")
		  	
		  
#else
		  
		  ,clk("clk")
		  	,rst("rst")
		  	
#endif
		  

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
#if defined(ioConfig_TLM)
#if defined(ioConfig) && defined(_wrap_ioConfig) && defined(_local_ioConfig)
#undef _local_ioConfig
#undef ioConfig
#define ioConfig _wrap_ioConfig
#endif
#endif
#if defined(ioConfig_PIN)
#if defined(ioConfig) && defined(_wrap_ioConfig) && defined(_local_ioConfig)
#undef _local_ioConfig
#undef ioConfig
#define ioConfig _wrap_ioConfig
#endif
#endif

#endif /*  */
