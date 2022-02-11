/****************************************************************************
 *
 *  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
 *
 *  This file contains confidential information that may not be
 *  distributed under any circumstances without the written permision
 *  of Cadence Design Systems.
 *
 ***************************************************************************/

#ifndef _DUT_CYCSIM_INCLUDED_
#define _DUT_CYCSIM_INCLUDED_

#include "systemc.h"
#include "cynthhl.h"

SC_MODULE(dut_cycsim)
{

	// Port declarations.
	
#if defined ( ioConfig_TLM )
	
	sc_in< bool > clk;
	sc_in< bool > rst;
	
	
#else
	
	sc_in< bool > clk;
	sc_in< bool > rst;
	
#endif


	dut_cycsim( sc_module_name in_name=sc_module_name(sc_gen_unique_name(" dut") ) )
		: sc_module(in_name)
		  
#if defined ( ioConfig_TLM )
		  
		  ,clk("clk")
		  	,rst("rst")
		  	
		  
#else
		  
		  ,clk("clk")
		  	,rst("rst")
		  	
#endif
		  

    {
    };
};

#endif
