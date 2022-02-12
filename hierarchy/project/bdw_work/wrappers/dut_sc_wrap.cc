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

void dut_wrapper::InitInstances( sc_int< 32 > _A[10], sc_int< 32 > _B[10], sc_int< 32 > _D[10] )
{
	
            
    dut0 = new dut( "dut" );

    dut0->clk(clk);
    dut0->rst(rst);
    dut0->finish(finish);
    dut0->find_max_x_out_busy(find_max_x_out.busy);
    dut0->find_max_x_out_vld(find_max_x_out.vld);
    dut0->find_max_x_out_data(find_max_x_out.data);
    dut0->find_max_return_in_busy(find_max_return_in.busy);
    dut0->find_max_return_in_vld(find_max_return_in.vld);
    dut0->find_max_return_in_data(find_max_return_in.data);

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

