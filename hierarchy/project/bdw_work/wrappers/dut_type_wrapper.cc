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

#include "dut_type_wrapper.h"


SC_MODULE_EXPORT(dut_type_wrapper)

// The following threads are used to connect RTL ports to the actual
// structured ports

void dut_type_wrapper::InitInstances()
{
    dut0 = new dut( "dut" );

    dut0->clk(clk);
    dut0->rst(rst);
    dut0->finish(finish);
    dut0->find_max_x_out.busy(find_max_x_out_busy);
    dut0->find_max_x_out.vld(find_max_x_out_vld);
    dut0->find_max_x_out.data(find_max_x_out_data);
    dut0->find_max_return_in.busy(find_max_return_in_busy);
    dut0->find_max_return_in.vld(find_max_return_in_vld);
    dut0->find_max_return_in.data(find_max_return_in_data);

}

void dut_type_wrapper::InitThreads()
{
    
}

void dut_type_wrapper::DeleteInstances()
{
        delete dut0;
        dut0 = 0;
}

