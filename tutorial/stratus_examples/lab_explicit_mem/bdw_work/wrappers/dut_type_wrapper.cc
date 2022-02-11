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
    dut0->din.busy(din_busy);
    dut0->din.vld(din_vld);
    dut0->din.data(din_data);
    dut0->dout.busy(dout_busy);
    dut0->dout.vld(dout_vld);
    dut0->dout.data(dout_data);
    dut0->mem.WE0(mem_WE0);
    dut0->mem.DIN0(mem_DIN0);
    dut0->mem.DOUT0(mem_DOUT0);
    dut0->mem.A0(mem_A0);
    dut0->mem.REQ0(mem_REQ0);

}

void dut_type_wrapper::InitThreads()
{
    
}

void dut_type_wrapper::DeleteInstances()
{
        delete dut0;
        dut0 = 0;
}

