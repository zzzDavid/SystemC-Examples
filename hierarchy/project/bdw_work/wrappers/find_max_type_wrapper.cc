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
* This file contains the find_max_type_wrapper module
* for use in the verilog verification wrapper find_max_vlwrapper.v
* It creats an instance of the find_max module and has threads
* for converting the BEH ports to RTL level ports on the wrapper.
*
****************************************************************************/

#include "find_max_type_wrapper.h"


SC_MODULE_EXPORT(find_max_type_wrapper)

// The following threads are used to connect RTL ports to the actual
// structured ports

void find_max_type_wrapper::InitInstances()
{
    find_max0 = new find_max( "find_max" );

    find_max0->clk(clk);
    find_max0->rst(rst);
    find_max0->find_max_x.busy(find_max_x_busy);
    find_max0->find_max_x.vld(find_max_x_vld);
    find_max0->find_max_x.data(find_max_x_data);
    find_max0->find_max_return.busy(find_max_return_busy);
    find_max0->find_max_return.vld(find_max_return_vld);
    find_max0->find_max_return.data(find_max_return_data);
    find_max0->add_one_x_out.busy(add_one_x_out_busy);
    find_max0->add_one_x_out.vld(add_one_x_out_vld);
    find_max0->add_one_x_out.data(add_one_x_out_data);
    find_max0->add_one_return_in.busy(add_one_return_in_busy);
    find_max0->add_one_return_in.vld(add_one_return_in_vld);
    find_max0->add_one_return_in.data(add_one_return_in_data);

}

void find_max_type_wrapper::InitThreads()
{
    
}

void find_max_type_wrapper::DeleteInstances()
{
        delete find_max0;
        find_max0 = 0;
}

