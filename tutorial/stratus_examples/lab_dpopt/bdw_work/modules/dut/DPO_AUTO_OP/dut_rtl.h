// Generated by stratus_hls 17.20-p100  (88533.190925)
// Wed Nov 18 11:33:09 2020
// from dut.cc
#ifndef CYNTH_PART_dut_dut_rtl_h
#define CYNTH_PART_dut_dut_rtl_h

#include "systemc.h"
/* Include declarations of instantiated parts. */


/* Declaration of the synthesized module. */
struct dut : public sc_module {
  sc_in<bool > clk;
  sc_in<bool > rst;
  sc_out<bool > din_busy;
  sc_in<bool > din_vld;
  sc_in<sc_uint<8> > din_data_a;
  sc_in<sc_uint<8> > din_data_b;
  sc_in<sc_uint<8> > din_data_c;
  sc_in<sc_uint<8> > din_data_d;
  sc_in<sc_uint<8> > din_data_e;
  sc_in<sc_uint<8> > din_data_f;
  sc_in<sc_uint<8> > din_data_g;
  sc_in<sc_uint<8> > din_data_h;
  sc_in<bool > dout_busy;
  sc_out<bool > dout_vld;
  sc_out<sc_uint<32> > dout_data;
  dut( sc_module_name name );
  SC_HAS_PROCESS(dut);
  sc_signal<bool > dout_m_req_m_prev_trig_req;
  sc_signal<sc_uint<1> > dut_Xor_1U_8_4_9_out1;
  sc_signal<bool > dout_m_unacked_req;
  sc_signal<sc_uint<1> > dut_Or_1U_7_4_10_out1;
  sc_signal<sc_uint<1> > dut_N_Muxb_1_2_11_4_1_out1;
  sc_signal<sc_uint<1> > dut_And_1U_5_4_5_out1;
  sc_signal<sc_uint<1> > dut_Not_1U_1_4_4_out1;
  sc_signal<sc_uint<1> > dut_Or_1U_7_4_2_out1;
  sc_signal<bool > din_m_unvalidated_req;
  sc_signal<sc_uint<1> > dut_And_1U_5_4_3_out1;
  sc_signal<sc_uint<3> > global_state_next;
  sc_signal<sc_uint<9> > dut_Mul_20Ux9U_29U_1_19_in1;
  sc_signal<sc_uint<9> > dut_Add_8Ux8U_9U_4_20_out1;
  sc_signal<sc_uint<20> > dut_Mul_20Ux9U_29U_1_19_in2;
  sc_signal<sc_uint<1> > gs_ctrl8;
  sc_signal<sc_uint<9> > dut_Mul_32Ux9U_32U_1_18_in1;
  sc_signal<sc_uint<1> > gs_ctrl7;
  sc_signal<sc_uint<29> > dut_Mul_32Ux9U_32U_1_18_in2_slice;
  sc_signal<sc_uint<2> > gs_ctrl6;
  sc_signal<sc_uint<32> > dut_Mul_32Ux32U_32U_1_17_in1;
  sc_signal<sc_uint<2> > gs_ctrl5;
  sc_signal<sc_uint<32> > dut_Mul_32Ux32U_32U_1_17_in2;
  sc_signal<sc_uint<2> > gs_ctrl4;
  sc_signal<sc_uint<32> > dut_Add_32Ux32U_32U_1_16_in1;
  sc_signal<sc_uint<32> > dut_Add_32Ux32U_32U_1_16_in2;
  sc_signal<sc_uint<1> > gs_ctrl2;
  sc_signal<sc_uint<32> > dut_Add_32Ux16U_32U_1_15_out1;
  sc_signal<sc_uint<16> > dut_Add_32Ux16U_32U_1_15_in1;
  sc_signal<sc_uint<32> > dut_Add_32Ux16U_32U_1_15_in2;
  sc_signal<sc_uint<2> > gs_ctrl0;
  sc_signal<sc_uint<9> > dut_Add_8Ux8U_9U_4_14_out1;
  sc_signal<sc_uint<9> > dut_Add_8Ux8U_9U_4_13_out1;
  sc_signal<sc_uint<32> > dut_Add_32Ux32U_32U_1_16_out1;
  sc_signal<sc_uint<17> > dut_Add_16Ux16U_17U_4_22_out1;
  sc_signal<sc_uint<32> > s_reg_32;
  sc_signal<sc_uint<29> > dut_Mul_20Ux9U_29U_1_19_out1;
  sc_signal<sc_uint<29> > s_reg_31;
  sc_signal<sc_uint<32> > dut_Mul_32Ux9U_32U_1_18_out1;
  sc_signal<sc_uint<16> > s_reg_30;
  sc_signal<sc_uint<9> > dut_Add_8Ux8U_9U_4_25_out1;
  sc_signal<sc_uint<9> > s_reg_29;
  sc_signal<sc_uint<8> > s_reg_28;
  sc_signal<sc_uint<8> > s_reg_27;
  sc_signal<sc_uint<8> > s_reg_26;
  sc_signal<sc_uint<8> > s_reg_25;
  sc_signal<sc_uint<8> > s_reg_24;
  sc_signal<sc_uint<8> > s_reg_23;
  sc_signal<sc_uint<1> > dut_Not_1U_1_4_6_out1;
  sc_signal<sc_uint<1> > dut_And_1U_5_4_11_out1;
  sc_signal<sc_uint<1> > dut_Not_1U_1_4_12_out1;
  sc_signal<bool > dout_m_req_m_trig_req;
  sc_signal<bool > din_m_busy_req_0;
  sc_signal<sc_uint<32> > dut_Mul_32Ux32U_32U_1_17_out1;
  sc_signal<sc_uint<3> > global_state;
  sc_signal<sc_uint<1> > stall0;
  void drive_dout_data();
  void drive_din_m_busy_req_0();
  void drive_dout_m_req_m_trig_req();
  void drive_stall0();
  void drive_s_reg_23();
  void drive_s_reg_24();
  void drive_s_reg_25();
  void drive_s_reg_26();
  void drive_s_reg_27();
  void drive_s_reg_28();
  void drive_s_reg_29();
  void drive_s_reg_30();
  void drive_s_reg_31();
  void drive_s_reg_32();
  void dut_Add_8Ux8U_9U_4_13();
  void dut_Add_8Ux8U_9U_4_14();
  void drive_dut_Add_32Ux16U_32U_1_15_in2();
  void drive_dut_Add_32Ux16U_32U_1_15_in1();
  void dut_Add_32Ux16U_32U_1_15();
  void drive_dut_Add_32Ux32U_32U_1_16_in2();
  void drive_dut_Add_32Ux32U_32U_1_16_in1();
  void dut_Add_32Ux32U_32U_1_16();
  void drive_dut_Mul_32Ux32U_32U_1_17_in2();
  void drive_dut_Mul_32Ux32U_32U_1_17_in1();
  void dut_Mul_32Ux32U_32U_1_17();
  void drive_dut_Mul_32Ux9U_32U_1_18_in2();
  void drive_dut_Mul_32Ux9U_32U_1_18_in1();
  void dut_Mul_32Ux9U_32U_1_18();
  void drive_dut_Mul_20Ux9U_29U_1_19_in2();
  void drive_dut_Mul_20Ux9U_29U_1_19_in1();
  void dut_Mul_20Ux9U_29U_1_19();
  void dut_Add_8Ux8U_9U_4_20();
  void dut_Add_16Ux16U_17U_4_22();
  void dut_Add_8Ux8U_9U_4_25();
  void drive_global_state();
  void drive_global_state_next();
  void drive_gs_ctrl0();
  void drive_gs_ctrl2();
  void drive_gs_ctrl4();
  void drive_gs_ctrl5();
  void drive_gs_ctrl6();
  void drive_gs_ctrl7();
  void drive_gs_ctrl8();
  void drive_din_busy();
  void dut_Or_1U_7_4_2();
  void dut_And_1U_5_4_3();
  void dut_Not_1U_1_4_4();
  void dut_And_1U_5_4_5();
  void dut_Not_1U_1_4_6();
  void drive_din_m_unvalidated_req();
  void dut_N_Muxb_1_2_11_4_1();
  void drive_dout_vld();
  void dut_Or_1U_7_4_10();
  void drive_dout_m_unacked_req();
  void dut_And_1U_5_4_11();
  void dut_Xor_1U_8_4_9();
  void drive_dout_m_req_m_prev_trig_req();
  void dut_Not_1U_1_4_12();
};

#endif
