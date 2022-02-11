/****************************************************************************
*
*  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/
/****************************************************************************
*
* This file contains the dut_type_wrapper module
* for use in the verilog verification wrapper dut_vlwrapper.v
* It creats an instance of the dut module and has threads
* for converting the BEH ports to RTL level ports on the wrapper.
*
****************************************************************************/


#ifndef _DUT_TYPE_WRAP_INCLUDED_
#define _DUT_TYPE_WRAP_INCLUDED_

#if !defined(ioConfig_TLM) && !defined(ioConfig_PIN)
#if defined(_p_ioConfig_TLM)
#define ioConfig_TLM 1
#endif
#if defined(_p_ioConfig_PIN)
#define ioConfig_PIN 1
#endif
#endif


#include <systemc.h>
#include "dut.h"


// Declaration of wrapper with RTL level ports

SC_MODULE(dut_type_wrapper)
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

    

	// create the netlist
    void InitInstances();
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    
#if defined ( ioConfig_TLM )
    
    
    
#else
    
    
#endif


	SC_HAS_PROCESS(dut_type_wrapper);

	dut_type_wrapper( sc_module_name name = sc_module_name( sc_gen_unique_name("dut")) )
		: sc_module(name)
		  
#if defined ( ioConfig_TLM )
		  
		  ,clk("clk")
		  	,rst("rst")
		  	
		  
#else
		  
		  ,clk("clk")
		  	,rst("rst")
		  	
#endif
		  

		  ,dut0(0)
		

    {
        InitInstances();
        InitThreads();
		end_module();
    }


    // destructor
    ~dut_type_wrapper()
    {
        DeleteInstances();
    }


protected:
	dut* dut0;
};

#endif /*  */
