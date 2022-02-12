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
* This file contains the add_one_type_wrapper module
* for use in the verilog verification wrapper add_one_vlwrapper.v
* It creats an instance of the add_one module and has threads
* for converting the BEH ports to RTL level ports on the wrapper.
*
****************************************************************************/

#include "add_one_type_wrapper.h"


SC_MODULE_EXPORT(add_one_type_wrapper)

// The following threads are used to connect RTL ports to the actual
// structured ports

void add_one_type_wrapper::InitInstances()
{
    add_one0 = new add_one( "add_one" );

    add_one0->clk(clk);
    add_one0->rst(rst);
    add_one0->add_one_x.busy(add_one_x_busy);
    add_one0->add_one_x.vld(add_one_x_vld);
    add_one0->add_one_x.data(add_one_x_data);
    add_one0->add_one_return.busy(add_one_return_busy);
    add_one0->add_one_return.vld(add_one_return_vld);
    add_one0->add_one_return.data(add_one_return_data);

}

void add_one_type_wrapper::InitThreads()
{
    
}

void add_one_type_wrapper::DeleteInstances()
{
        delete add_one0;
        add_one0 = 0;
}

