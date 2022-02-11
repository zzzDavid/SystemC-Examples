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
void dut_type_wrapper::thread_din_data()
{
   input_t tmp;
   tmp.a = din_data_a.read();
   tmp.b = din_data_b.read();
   tmp.c = din_data_c.read();
   tmp.d = din_data_d.read();
   tmp.e = din_data_e.read();
   tmp.f = din_data_f.read();
   tmp.g = din_data_g.read();
   tmp.h = din_data_h.read();
   din_data.write(tmp);
}


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

}

void dut_type_wrapper::InitThreads()
{
    SC_METHOD(thread_din_data);
      sensitive << din_data_a;
      sensitive << din_data_b;
      sensitive << din_data_c;
      sensitive << din_data_d;
      sensitive << din_data_e;
      sensitive << din_data_f;
      sensitive << din_data_g;
      sensitive << din_data_h;

}

void dut_type_wrapper::DeleteInstances()
{
        delete dut0;
        dut0 = 0;
}

