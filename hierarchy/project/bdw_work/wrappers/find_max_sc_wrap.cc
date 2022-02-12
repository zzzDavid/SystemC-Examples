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
* block called "find_max". By default, it will include the behavioral
* model. Otherwise, it will include the RTL C++ or the RTL Verilog
* depending on the definition of either of "RTL" or "COSIM".
*
****************************************************************************/


#include	"find_max_sc_wrap.h"
#include	"find_max_sc_foreign.h"

// The following threads are used to connect structured ports to the actual
// RTL ports

void find_max_wrapper::InitInstances( sc_int< 32 > _A[10], sc_int< 32 > _B[10] )
{
	
            
    find_max0 = new find_max( "find_max" );

    find_max0->clk(clk);
    find_max0->rst(rst);
    find_max0->find_max_x_busy(find_max_x.busy);
    find_max0->find_max_x_vld(find_max_x.vld);
    find_max0->find_max_x_data(find_max_x.data);
    find_max0->find_max_return_busy(find_max_return.busy);
    find_max0->find_max_return_vld(find_max_return.vld);
    find_max0->find_max_return_data(find_max_return.data);
    find_max0->add_one_x_out_busy(add_one_x_out.busy);
    find_max0->add_one_x_out_vld(add_one_x_out.vld);
    find_max0->add_one_x_out_data(add_one_x_out.data);
    find_max0->add_one_return_in_busy(add_one_return_in.busy);
    find_max0->add_one_return_in_vld(add_one_return_in.vld);
    find_max0->add_one_return_in_data(add_one_return_in.data);

}

void find_max_wrapper::InitThreads()
{
    
}

void find_max_wrapper::DeleteInstances()
{
    if (find_max0)
    {
        delete find_max0;
        find_max0 = 0;
    }
}

