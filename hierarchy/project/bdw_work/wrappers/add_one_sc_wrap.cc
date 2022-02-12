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
* block called "add_one". By default, it will include the behavioral
* model. Otherwise, it will include the RTL C++ or the RTL Verilog
* depending on the definition of either of "RTL" or "COSIM".
*
****************************************************************************/


#include	"add_one_sc_wrap.h"
#include	"add_one_sc_foreign.h"

// The following threads are used to connect structured ports to the actual
// RTL ports

void add_one_wrapper::InitInstances( sc_int< 32 > _A[10] )
{
	
            
    add_one0 = new add_one( "add_one" );

    add_one0->clk(clk);
    add_one0->rst(rst);
    add_one0->add_one_x_busy(add_one_x.busy);
    add_one0->add_one_x_vld(add_one_x.vld);
    add_one0->add_one_x_data(add_one_x.data);
    add_one0->add_one_return_busy(add_one_return.busy);
    add_one0->add_one_return_vld(add_one_return.vld);
    add_one0->add_one_return_data(add_one_return.data);

}

void add_one_wrapper::InitThreads()
{
    
}

void add_one_wrapper::DeleteInstances()
{
    if (add_one0)
    {
        delete add_one0;
        add_one0 = 0;
    }
}

