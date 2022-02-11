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
void dut_wrapper::thread_din_data_a()
{
   din_data_a = din.data.read().a;
}
void dut_wrapper::thread_din_data_b()
{
   din_data_b = din.data.read().b;
}
void dut_wrapper::thread_din_data_c()
{
   din_data_c = din.data.read().c;
}
void dut_wrapper::thread_din_data_d()
{
   din_data_d = din.data.read().d;
}
void dut_wrapper::thread_din_data_e()
{
   din_data_e = din.data.read().e;
}
void dut_wrapper::thread_din_data_f()
{
   din_data_f = din.data.read().f;
}
void dut_wrapper::thread_din_data_g()
{
   din_data_g = din.data.read().g;
}
void dut_wrapper::thread_din_data_h()
{
   din_data_h = din.data.read().h;
}


void dut_wrapper::InitInstances(  )
{
	
            
    dut0 = new dut( "dut" );

    dut0->clk(clk);
    dut0->rst(rst);
    dut0->din_busy(din.busy);
    dut0->din_vld(din.vld);
    dut0->din_data_a(din_data_a);
    dut0->din_data_b(din_data_b);
    dut0->din_data_c(din_data_c);
    dut0->din_data_d(din_data_d);
    dut0->din_data_e(din_data_e);
    dut0->din_data_f(din_data_f);
    dut0->din_data_g(din_data_g);
    dut0->din_data_h(din_data_h);
    dut0->dout_busy(dout.busy);
    dut0->dout_vld(dout.vld);
    dut0->dout_data(dout.data);

}

void dut_wrapper::InitThreads()
{
    SC_METHOD(thread_din_data_a);
      sensitive << din.data;
    SC_METHOD(thread_din_data_b);
      sensitive << din.data;
    SC_METHOD(thread_din_data_c);
      sensitive << din.data;
    SC_METHOD(thread_din_data_d);
      sensitive << din.data;
    SC_METHOD(thread_din_data_e);
      sensitive << din.data;
    SC_METHOD(thread_din_data_f);
      sensitive << din.data;
    SC_METHOD(thread_din_data_g);
      sensitive << din.data;
    SC_METHOD(thread_din_data_h);
      sensitive << din.data;

}

void dut_wrapper::DeleteInstances()
{
    if (dut0)
    {
        delete dut0;
        dut0 = 0;
    }
}

