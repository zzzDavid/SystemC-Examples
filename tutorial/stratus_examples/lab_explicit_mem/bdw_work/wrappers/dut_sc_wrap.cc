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

void dut_wrapper::InitInstances(  )
{
	
            
    dut0 = new dut( "dut" );

    dut0->clk(clk);
    dut0->rst(rst);
    dut0->din_busy(din.busy);
    dut0->din_vld(din.vld);
    dut0->din_data(din.data);
    dut0->dout_busy(dout.busy);
    dut0->dout_vld(dout.vld);
    dut0->dout_data(dout.data);
    dut0->mem_WE0(mem.WE0);
    dut0->mem_DIN0(mem.DIN0);
    dut0->mem_DOUT0(mem.DOUT0);
    dut0->mem_A0(mem.A0);
    dut0->mem_REQ0(mem.REQ0);

}

void dut_wrapper::InitThreads()
{
    
}

void dut_wrapper::DeleteInstances()
{
    if (dut0)
    {
        delete dut0;
        dut0 = 0;
    }
}

