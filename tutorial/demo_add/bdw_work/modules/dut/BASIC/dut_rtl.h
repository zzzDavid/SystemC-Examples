// Generated by stratus_hls 17.20-p100  (88533.190925)
// Fri Nov 20 12:05:36 2020
// from dut.cc
#ifndef CYNTH_PART_dut_dut_rtl_h
#define CYNTH_PART_dut_dut_rtl_h

#include "systemc.h"
/* Include declarations of instantiated parts. */


/* Declaration of the synthesized module. */
struct dut : public sc_module {
  sc_in<bool > clk;
  sc_in<bool > rst;
  sc_out<bool > din_1_busy;
  sc_in<bool > din_1_vld;
  sc_in<sc_uint<8> > din_1_data;
  sc_out<bool > din_2_busy;
  sc_in<bool > din_2_vld;
  sc_in<sc_uint<8> > din_2_data;
  sc_in<bool > dout_busy;
  sc_out<bool > dout_vld;
  sc_out<sc_uint<9> > dout_data;
  dut( sc_module_name name );
  SC_HAS_PROCESS(dut);
  sc_signal<bool > dout_m_req_m_prev_trig_req;
  sc_signal<sc_uint<1> > dut_Xor_1Ux1U_1U_4_17_out1;
  sc_signal<bool > dout_m_unacked_req;
  sc_signal<sc_uint<1> > dut_Or_1Ux1U_1U_4_18_out1;
  sc_signal<sc_uint<1> > dut_N_Muxb_1_2_0_4_2_out1;
  sc_signal<sc_uint<1> > dut_And_1Ux1U_1U_4_13_out1;
  sc_signal<sc_uint<1> > dut_Not_1U_1U_4_12_out1;
  sc_signal<sc_uint<1> > dut_Or_1Ux1U_1U_4_10_out1;
  sc_signal<bool > din_2_m_unvalidated_req;
  sc_signal<sc_uint<1> > dut_And_1Ux1U_1U_4_11_out1;
  sc_signal<sc_uint<1> > dut_N_Muxb_1_2_0_4_1_out1;
  sc_signal<sc_uint<1> > dut_And_1Ux1U_1U_4_6_out1;
  sc_signal<sc_uint<1> > dut_Not_1U_1U_4_5_out1;
  sc_signal<sc_uint<1> > dut_Or_1Ux1U_1U_4_3_out1;
  sc_signal<bool > din_1_m_unvalidated_req;
  sc_signal<sc_uint<1> > dut_And_1Ux1U_1U_4_4_out1;
  sc_signal<sc_uint<2> > global_state_next;
  sc_signal<sc_uint<1> > dut_Not_1U_1U_4_7_out1;
  sc_signal<sc_uint<1> > dut_Not_1U_1U_4_14_out1;
  sc_signal<sc_uint<1> > dut_And_1Ux1U_1U_4_19_out1;
  sc_signal<sc_uint<1> > dut_Not_1U_1U_4_20_out1;
  sc_signal<bool > dout_m_req_m_trig_req;
  sc_signal<bool > din_2_m_busy_req_0;
  sc_signal<bool > din_1_m_busy_req_0;
  sc_signal<sc_uint<9> > dut_Add_8Ux8U_9U_4_22_out1;
  sc_signal<sc_uint<2> > global_state;
  sc_signal<sc_uint<1> > stall0;
  void drive_dout_data();
  void drive_din_1_m_busy_req_0();
  void drive_din_2_m_busy_req_0();
  void drive_dout_m_req_m_trig_req();
  void drive_stall0();
  void dut_Add_8Ux8U_9U_4_22();
  void drive_global_state();
  void drive_global_state_next();
  void drive_din_1_busy();
  void dut_Or_1Ux1U_1U_4_3();
  void dut_And_1Ux1U_1U_4_4();
  void dut_Not_1U_1U_4_5();
  void dut_And_1Ux1U_1U_4_6();
  void dut_Not_1U_1U_4_7();
  void drive_din_1_m_unvalidated_req();
  void dut_N_Muxb_1_2_0_4_1();
  void drive_din_2_busy();
  void dut_Or_1Ux1U_1U_4_10();
  void dut_And_1Ux1U_1U_4_11();
  void dut_Not_1U_1U_4_12();
  void dut_And_1Ux1U_1U_4_13();
  void dut_Not_1U_1U_4_14();
  void drive_din_2_m_unvalidated_req();
  void dut_N_Muxb_1_2_0_4_2();
  void drive_dout_vld();
  void dut_Or_1Ux1U_1U_4_18();
  void drive_dout_m_unacked_req();
  void dut_And_1Ux1U_1U_4_19();
  void dut_Xor_1Ux1U_1U_4_17();
  void drive_dout_m_req_m_prev_trig_req();
  void dut_Not_1U_1U_4_20();
};

#endif
