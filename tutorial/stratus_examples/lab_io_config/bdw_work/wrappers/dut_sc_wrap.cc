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
* This file is used to wrap the three different versions of the DUT
* block called "dut". By default, it will include the behavioral
* model. Otherwise, it will include the RTL C++ or the RTL Verilog
* depending on the definition of either of "RTL" or "COSIM".
*
****************************************************************************/


#include	"dut_sc_wrap.h"
#include	"dut_sc_foreign.h"

// The following threads are used to connect structured ports to the actual
// RTL ports

#if defined ( ioConfig_TLM )



#else


#endif


void dut_wrapper::InitInstances(  )
{
	
#if defined ( ioConfig_TLM )
	
	
	
#else
	
	
#endif

            
    dut0 = new dut( "dut" );

    
#if defined ( ioConfig_TLM )
    
    dut0->clk(clk);
    dut0->rst(rst);
    
    
#else
    
    dut0->clk(clk);
    dut0->rst(rst);
    
#endif

}

void dut_wrapper::InitThreads()
{
    
#if defined ( ioConfig_TLM )
    
    
    
#else
    
    
#endif

}

void dut_wrapper::DeleteInstances()
{
    if (dut0)
    {
        delete dut0;
        dut0 = 0;
    }
}

