// Generated by stratus_hls 17.20-p100  (88533.190925)
// Wed Nov 18 11:38:24 2020
// from dut.cc
#ifndef CYNTH_PART_dut_dut_entirecomputation_4_h
#define CYNTH_PART_dut_dut_entirecomputation_4_h

#include "systemc.h"
/* Include declarations of instantiated parts. */


/* Declaration of the synthesized module. */
struct dut_entirecomputation_4 : public sc_module {
  sc_in<sc_uint<8> > in1;
  sc_in<sc_uint<8> > in2;
  sc_in<sc_uint<8> > in3;
  sc_in<sc_uint<8> > in4;
  sc_in<sc_uint<8> > in5;
  sc_in<sc_uint<8> > in6;
  sc_in<sc_uint<8> > in7;
  sc_in<sc_uint<8> > in8;
  sc_out<sc_uint<32> > out1;
  sc_in<bool > clk;
  sc_in<sc_uint<1> > stall;
  dut_entirecomputation_4( sc_module_name name );
  SC_HAS_PROCESS(dut_entirecomputation_4);
  sc_signal<sc_uint<32> > out1_1;
  sc_uint<32> out1_0;
  sc_uint<32> val2;
  sc_uint<32> val1;
  void dut_entirecomputation_4_thread_1();
};

#endif
