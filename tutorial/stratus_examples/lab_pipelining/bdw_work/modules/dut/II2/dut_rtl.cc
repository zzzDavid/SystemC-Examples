// Generated by stratus_hls 17.20-p100  (88533.190925)
// Thu Nov 19 00:45:43 2020
// from dut.cc
#include "dut_rtl.h"

struct dut;
dut::dut(sc_module_name name) : sc_module(name) 
    ,clk("clk")
    ,rst("rst")
    ,din_busy("din_busy")
    ,din_vld("din_vld")
    ,din_data_a("din_data_a")
    ,din_data_b("din_data_b")
    ,din_data_c("din_data_c")
    ,din_data_d("din_data_d")
    ,din_data_e("din_data_e")
    ,din_data_f("din_data_f")
    ,din_data_g("din_data_g")
    ,din_data_h("din_data_h")
    ,dout_busy("dout_busy")
    ,dout_vld("dout_vld")
    ,dout_data("dout_data")
    ,dout_m_req_m_prev_trig_req("dout_m_req_m_prev_trig_req")
    ,dut_Xor_1Ux1U_1U_4_14_out1("dut_Xor_1Ux1U_1U_4_14_out1")
    ,dout_m_unacked_req("dout_m_unacked_req")
    ,dut_Or_1Ux1U_1U_4_15_out1("dut_Or_1Ux1U_1U_4_15_out1")
    ,dut_And_1Ux1U_1U_4_12_out1("dut_And_1Ux1U_1U_4_12_out1")
    ,dut_And_1Ux1U_1U_4_10_out1("dut_And_1Ux1U_1U_4_10_out1")
    ,dut_Not_1U_1U_4_9_out1("dut_Not_1U_1U_4_9_out1")
    ,dut_And_1Ux1U_1U_4_11_out1("dut_And_1Ux1U_1U_4_11_out1")
    ,dut_N_Muxb_1_2_1_4_1_out1("dut_N_Muxb_1_2_1_4_1_out1")
    ,dut_And_1Ux1U_1U_4_5_out1("dut_And_1Ux1U_1U_4_5_out1")
    ,dut_Not_1U_1U_4_4_out1("dut_Not_1U_1U_4_4_out1")
    ,dut_And_1Ux1U_1U_4_3_out1("dut_And_1Ux1U_1U_4_3_out1")
    ,dut_Or_1Ux1U_1U_4_2_out1("dut_Or_1Ux1U_1U_4_2_out1")
    ,din_m_unvalidated_req("din_m_unvalidated_req")
    ,dut_Or_1Ux1U_1U_4_7_out1("dut_Or_1Ux1U_1U_4_7_out1")
    ,global_state_next("global_state_next")
    ,cycle2_state("cycle2_state")
    ,dut_Mul_32Ux9U_32U_4_42_out1("dut_Mul_32Ux9U_32U_4_42_out1")
    ,dut_Add_8Ux8U_9U_4_40_out1("dut_Add_8Ux8U_9U_4_40_out1")
    ,dut_Add_32Ux17U_33U_1_36_in1("dut_Add_32Ux17U_33U_1_36_in1")
    ,dut_Add_32Ux17U_33U_1_36_in2("dut_Add_32Ux17U_33U_1_36_in2")
    ,dut_Mul_32Ux9U_32U_4_35_out1("dut_Mul_32Ux9U_32U_4_35_out1")
    ,dut_Mul_32Ux9U_32U_4_35_in1_slice("dut_Mul_32Ux9U_32U_4_35_in1_slice")
    ,dut_Mul_32Ux9U_32U_4_35_in2_slice("dut_Mul_32Ux9U_32U_4_35_in2_slice")
    ,dut_Mul_8Ux8U_16U_4_34_out1("dut_Mul_8Ux8U_16U_4_34_out1")
    ,dut_Mul_8Ux8U_16U_4_34_in1("dut_Mul_8Ux8U_16U_4_34_in1")
    ,dut_Mul_8Ux8U_16U_4_34_in2("dut_Mul_8Ux8U_16U_4_34_in2")
    ,dut_Mul_33Ux32U_64U_4_33_in1("dut_Mul_33Ux32U_64U_4_33_in1")
    ,dut_Add_32Ux32U_32U_4_44_out1("dut_Add_32Ux32U_32U_4_44_out1")
    ,dut_Mul_33Ux32U_64U_4_33_in2("dut_Mul_33Ux32U_64U_4_33_in2")
    ,dut_Add_32Ux16U_33U_4_45_out1("dut_Add_32Ux16U_33U_4_45_out1")
    ,dut_Mul_32Ux10U_32U_4_32_out1("dut_Mul_32Ux10U_32U_4_32_out1")
    ,dut_Mul_32Ux10U_32U_4_32_in1("dut_Mul_32Ux10U_32U_4_32_in1")
    ,dut_Add_8Ux8U_9U_4_39_out1("dut_Add_8Ux8U_9U_4_39_out1")
    ,dut_Mul_32Ux10U_32U_4_32_in2_slice("dut_Mul_32Ux10U_32U_4_32_in2_slice")
    ,gs_ctrl0("gs_ctrl0")
    ,dut_Add_8Ux8U_9U_4_31_out1("dut_Add_8Ux8U_9U_4_31_out1")
    ,dut_Add_9Ux8U_10U_4_30_out1("dut_Add_9Ux8U_10U_4_30_out1")
    ,dut_Add_9Ux8U_10U_4_29_out1("dut_Add_9Ux8U_10U_4_29_out1")
    ,din_m_stall_reg_h("din_m_stall_reg_h")
    ,din_m_stall_reg_g("din_m_stall_reg_g")
    ,dut_Add_8Ux8U_9U_4_26_out1("dut_Add_8Ux8U_9U_4_26_out1")
    ,dut_Add_8Ux8U_9U_4_25_out1("dut_Add_8Ux8U_9U_4_25_out1")
    ,dut_N_Mux_8_2_0_4_24_out1("dut_N_Mux_8_2_0_4_24_out1")
    ,din_m_stall_reg_f("din_m_stall_reg_f")
    ,din_m_stall_reg_c("din_m_stall_reg_c")
    ,din_m_stall_reg_e("din_m_stall_reg_e")
    ,din_m_stall_reg_d("din_m_stall_reg_d")
    ,din_m_stall_reg_b("din_m_stall_reg_b")
    ,din_m_stall_reg_full("din_m_stall_reg_full")
    ,din_m_stall_reg_a("din_m_stall_reg_a")
    ,dut_Add_32Ux17U_33U_1_36_out1("dut_Add_32Ux17U_33U_1_36_out1")
    ,s_reg_22("s_reg_22")
    ,dut_Mul_33Ux32U_64U_4_33_out1("dut_Mul_33Ux32U_64U_4_33_out1")
    ,s_reg_21_slice11("s_reg_21_slice11")
    ,dut_N_Mux_8_2_0_4_28_out1("dut_N_Mux_8_2_0_4_28_out1")
    ,s_reg_20("s_reg_20")
    ,dut_N_Mux_8_2_0_4_27_out1("dut_N_Mux_8_2_0_4_27_out1")
    ,s_reg_19("s_reg_19")
    ,dut_N_Mux_8_2_0_4_23_out1("dut_N_Mux_8_2_0_4_23_out1")
    ,s_reg_18("s_reg_18")
    ,dut_N_Mux_8_2_0_4_22_out1("dut_N_Mux_8_2_0_4_22_out1")
    ,s_reg_17("s_reg_17")
    ,dut_N_Mux_8_2_0_4_21_out1("dut_N_Mux_8_2_0_4_21_out1")
    ,s_reg_16("s_reg_16")
    ,dut_N_Mux_8_2_0_4_20_out1("dut_N_Mux_8_2_0_4_20_out1")
    ,s_reg_15("s_reg_15")
    ,dut_N_Mux_8_2_0_4_19_out1("dut_N_Mux_8_2_0_4_19_out1")
    ,s_reg_14("s_reg_14")
    ,dut_Or_1Ux1U_1U_4_6_out1("dut_Or_1Ux1U_1U_4_6_out1")
    ,s_reg_13_stage1("s_reg_13_stage1")
    ,cycle6_state("cycle6_state")
    ,dut_And_1Ux1U_1U_4_16_out1("dut_And_1Ux1U_1U_4_16_out1")
    ,dut_Not_1U_1U_4_17_out1("dut_Not_1U_1U_4_17_out1")
    ,cycle4_state("cycle4_state")
    ,s_reg_13("s_reg_13")
    ,dout_m_req_m_trig_req("dout_m_req_m_trig_req")
    ,global_state("global_state")
    ,din_m_busy_req_0("din_m_busy_req_0")
    ,s_reg_21_stage1("s_reg_21_stage1")
    ,dut_Div_64Ux2U_32U_4_47_in1("dut_Div_64Ux2U_32U_4_47_in1")
    ,dut_Div_64Ux2U_32U_4_47_out1("dut_Div_64Ux2U_32U_4_47_out1")
    ,stall0("stall0")
{
  dut_Div_64Ux2U_32U_4_47 = new dut_Div_64Ux2U_32U_4("dut_Div_64Ux2U_32U_4_47");
  dut_Div_64Ux2U_32U_4_47->in2(s_reg_21_stage1);
  dut_Div_64Ux2U_32U_4_47->in1(dut_Div_64Ux2U_32U_4_47_in1);
  dut_Div_64Ux2U_32U_4_47->out1(dut_Div_64Ux2U_32U_4_47_out1);
  dut_Div_64Ux2U_32U_4_47->clk(clk);
  dut_Div_64Ux2U_32U_4_47->stall(stall0);

  SC_METHOD(drive_dout_data);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_din_m_busy_req_0);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_dout_m_req_m_trig_req);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_stall0);
  sensitive << ( global_state );
  sensitive << ( cycle6_state );
  sensitive << ( dut_And_1Ux1U_1U_4_16_out1 );

  SC_METHOD(drive_s_reg_13);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_14);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_15);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_16);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_17);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_18);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_19);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_20);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_21);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_22);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(dut_N_Mux_8_2_0_4_19);
  sensitive << ( din_m_stall_reg_full );
  sensitive << ( din_m_stall_reg_a );
  sensitive << ( din_data_a );

  SC_METHOD(dut_N_Mux_8_2_0_4_20);
  sensitive << ( din_m_stall_reg_full );
  sensitive << ( din_m_stall_reg_b );
  sensitive << ( din_data_b );

  SC_METHOD(dut_N_Mux_8_2_0_4_21);
  sensitive << ( din_m_stall_reg_full );
  sensitive << ( din_m_stall_reg_d );
  sensitive << ( din_data_d );

  SC_METHOD(dut_N_Mux_8_2_0_4_22);
  sensitive << ( din_m_stall_reg_full );
  sensitive << ( din_m_stall_reg_e );
  sensitive << ( din_data_e );

  SC_METHOD(dut_N_Mux_8_2_0_4_23);
  sensitive << ( din_m_stall_reg_full );
  sensitive << ( din_m_stall_reg_c );
  sensitive << ( din_data_c );

  SC_METHOD(dut_N_Mux_8_2_0_4_24);
  sensitive << ( din_m_stall_reg_full );
  sensitive << ( din_m_stall_reg_f );
  sensitive << ( din_data_f );

  SC_METHOD(dut_Add_8Ux8U_9U_4_25);
  sensitive << ( dut_N_Mux_8_2_0_4_22_out1 );
  sensitive << ( dut_N_Mux_8_2_0_4_21_out1 );

  SC_METHOD(dut_Add_8Ux8U_9U_4_26);
  sensitive << ( dut_N_Mux_8_2_0_4_20_out1 );
  sensitive << ( dut_N_Mux_8_2_0_4_19_out1 );

  SC_METHOD(dut_N_Mux_8_2_0_4_27);
  sensitive << ( din_m_stall_reg_full );
  sensitive << ( din_m_stall_reg_g );
  sensitive << ( din_data_g );

  SC_METHOD(dut_N_Mux_8_2_0_4_28);
  sensitive << ( din_m_stall_reg_full );
  sensitive << ( din_m_stall_reg_h );
  sensitive << ( din_data_h );

  SC_METHOD(dut_Add_9Ux8U_10U_4_29);
  sensitive << ( dut_N_Mux_8_2_0_4_24_out1 );
  sensitive << ( dut_Add_8Ux8U_9U_4_25_out1 );

  SC_METHOD(dut_Add_9Ux8U_10U_4_30);
  sensitive << ( dut_N_Mux_8_2_0_4_23_out1 );
  sensitive << ( dut_Add_8Ux8U_9U_4_26_out1 );

  SC_METHOD(dut_Add_8Ux8U_9U_4_31);
  sensitive << ( dut_N_Mux_8_2_0_4_28_out1 );
  sensitive << ( dut_N_Mux_8_2_0_4_27_out1 );

  SC_METHOD(drive_dut_Mul_32Ux10U_32U_4_32_in2);
  sensitive << ( gs_ctrl0 );
  sensitive << ( dut_Add_9Ux8U_10U_4_30_out1 );
  sensitive << ( s_reg_21_slice11 );

  SC_METHOD(drive_dut_Mul_32Ux10U_32U_4_32_in1);
  sensitive << ( gs_ctrl0 );
  sensitive << ( dut_Add_9Ux8U_10U_4_29_out1 );
  sensitive << ( dut_Add_8Ux8U_9U_4_39_out1 );

  SC_METHOD(dut_Mul_32Ux10U_32U_4_32);
  sensitive << ( dut_Mul_32Ux10U_32U_4_32_in1 );
  sensitive << ( dut_Mul_32Ux10U_32U_4_32_in2_slice );

  SC_METHOD(drive_dut_Mul_33Ux32U_64U_4_33_in2);
  sensitive << ( gs_ctrl0 );
  sensitive << ( dut_Mul_32Ux10U_32U_4_32_out1 );
  sensitive << ( dut_Add_32Ux16U_33U_4_45_out1 );

  SC_METHOD(drive_dut_Mul_33Ux32U_64U_4_33_in1);
  sensitive << ( gs_ctrl0 );
  sensitive << ( dut_Add_8Ux8U_9U_4_31_out1 );
  sensitive << ( dut_Add_32Ux32U_32U_4_44_out1 );

  SC_METHOD(dut_Mul_33Ux32U_64U_4_33);
  sensitive << ( dut_Mul_33Ux32U_64U_4_33_in1 );
  sensitive << ( dut_Mul_33Ux32U_64U_4_33_in2 );

  SC_METHOD(drive_dut_Mul_8Ux8U_16U_4_34_in2);
  sensitive << ( gs_ctrl0 );
  sensitive << ( dut_N_Mux_8_2_0_4_23_out1 );
  sensitive << ( s_reg_19 );

  SC_METHOD(drive_dut_Mul_8Ux8U_16U_4_34_in1);
  sensitive << ( gs_ctrl0 );
  sensitive << ( dut_N_Mux_8_2_0_4_21_out1 );
  sensitive << ( s_reg_20 );

  SC_METHOD(dut_Mul_8Ux8U_16U_4_34);
  sensitive << ( dut_Mul_8Ux8U_16U_4_34_in1 );
  sensitive << ( dut_Mul_8Ux8U_16U_4_34_in2 );

  SC_METHOD(drive_dut_Mul_32Ux9U_32U_4_35_in2);
  sensitive << ( gs_ctrl0 );
  sensitive << ( dut_N_Mux_8_2_0_4_19_out1 );
  sensitive << ( s_reg_21_slice11 );

  SC_METHOD(drive_dut_Mul_32Ux9U_32U_4_35_in1);
  sensitive << ( gs_ctrl0 );
  sensitive << ( dut_N_Mux_8_2_0_4_20_out1 );
  sensitive << ( s_reg_17 );

  SC_METHOD(dut_Mul_32Ux9U_32U_4_35);
  sensitive << ( dut_Mul_32Ux9U_32U_4_35_in1_slice );
  sensitive << ( dut_Mul_32Ux9U_32U_4_35_in2_slice );

  SC_METHOD(drive_dut_Add_32Ux17U_33U_1_36_in2);
  sensitive << ( gs_ctrl0 );
  sensitive << ( dut_Mul_32Ux9U_32U_4_35_out1 );

  SC_METHOD(drive_dut_Add_32Ux17U_33U_1_36_in1);
  sensitive << ( gs_ctrl0 );
  sensitive << ( dut_Mul_8Ux8U_16U_4_34_out1 );
  sensitive << ( s_reg_22 );

  SC_METHOD(dut_Add_32Ux17U_33U_1_36);
  sensitive << ( dut_Add_32Ux17U_33U_1_36_in1 );
  sensitive << ( dut_Add_32Ux17U_33U_1_36_in2 );

  SC_METHOD(dut_Add_8Ux8U_9U_4_39);
  sensitive << ( s_reg_18 );
  sensitive << ( s_reg_16 );

  SC_METHOD(dut_Add_8Ux8U_9U_4_40);
  sensitive << ( s_reg_15 );
  sensitive << ( s_reg_14 );

  SC_METHOD(dut_Mul_32Ux9U_32U_4_42);
  sensitive << ( dut_Add_8Ux8U_9U_4_40_out1 );
  sensitive << ( dut_Add_32Ux17U_33U_1_36_out1 );

  SC_METHOD(dut_Add_32Ux32U_32U_4_44);
  sensitive << ( dut_Mul_32Ux10U_32U_4_32_out1 );
  sensitive << ( dut_Mul_32Ux9U_32U_4_42_out1 );

  SC_METHOD(dut_Add_32Ux16U_33U_4_45);
  sensitive << ( dut_Mul_8Ux8U_16U_4_34_out1 );
  sensitive << ( dut_Add_32Ux17U_33U_1_36_out1 );

  SC_METHOD(drive_dut_Div_64Ux2U_32U_4_47_in1);

  SC_METHOD(drive_s_reg_13_stage1);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_21_stage1);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_cycle2_state);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_cycle4_state);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_cycle6_state);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_global_state);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_global_state_next);
  sensitive << ( global_state );

  SC_METHOD(drive_gs_ctrl0);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_din_busy);
  sensitive << ( dut_Or_1Ux1U_1U_4_7_out1 );

  SC_METHOD(dut_Or_1Ux1U_1U_4_2);
  sensitive << ( din_vld );
  sensitive << ( din_m_unvalidated_req );

  SC_METHOD(dut_And_1Ux1U_1U_4_3);
  sensitive << ( din_m_busy_req_0 );
  sensitive << ( dut_Or_1Ux1U_1U_4_2_out1 );

  SC_METHOD(dut_Not_1U_1U_4_4);
  sensitive << ( dut_And_1Ux1U_1U_4_3_out1 );

  SC_METHOD(dut_And_1Ux1U_1U_4_5);
  sensitive << ( din_vld );
  sensitive << ( dut_Not_1U_1U_4_4_out1 );

  SC_METHOD(dut_Or_1Ux1U_1U_4_6);
  sensitive << ( din_m_stall_reg_full );
  sensitive << ( dut_And_1Ux1U_1U_4_5_out1 );

  SC_METHOD(dut_Or_1Ux1U_1U_4_7);
  sensitive << ( din_m_stall_reg_full );
  sensitive << ( dut_And_1Ux1U_1U_4_3_out1 );

  SC_METHOD(drive_din_m_unvalidated_req);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(dut_N_Muxb_1_2_1_4_1);
  sensitive << ( din_m_busy_req_0 );
  sensitive << ( din_m_unvalidated_req );
  sensitive << ( din_vld );

  SC_METHOD(drive_din_m_stall_reg_h);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_din_m_stall_reg_g);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_din_m_stall_reg_f);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_din_m_stall_reg_e);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_din_m_stall_reg_d);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_din_m_stall_reg_c);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_din_m_stall_reg_b);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_din_m_stall_reg_a);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(dut_Not_1U_1U_4_9);
  sensitive << ( din_m_stall_reg_full );

  SC_METHOD(dut_And_1Ux1U_1U_4_10);
  sensitive << ( stall0 );
  sensitive << ( dut_Or_1Ux1U_1U_4_6_out1 );

  SC_METHOD(dut_And_1Ux1U_1U_4_11);
  sensitive << ( dut_Not_1U_1U_4_9_out1 );
  sensitive << ( dut_And_1Ux1U_1U_4_10_out1 );

  SC_METHOD(drive_din_m_stall_reg_full);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(dut_And_1Ux1U_1U_4_12);
  sensitive << ( stall0 );
  sensitive << ( dut_Or_1Ux1U_1U_4_6_out1 );

  SC_METHOD(drive_dout_vld);
  sensitive << ( dut_Or_1Ux1U_1U_4_15_out1 );

  SC_METHOD(dut_Or_1Ux1U_1U_4_15);
  sensitive << ( dut_Xor_1Ux1U_1U_4_14_out1 );
  sensitive << ( dout_m_unacked_req );

  SC_METHOD(drive_dout_m_unacked_req);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(dut_And_1Ux1U_1U_4_16);
  sensitive << ( dout_vld );
  sensitive << ( dout_busy );

  SC_METHOD(dut_Xor_1Ux1U_1U_4_14);
  sensitive << ( dout_m_req_m_prev_trig_req );
  sensitive << ( dout_m_req_m_trig_req );

  SC_METHOD(drive_dout_m_req_m_prev_trig_req);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(dut_Not_1U_1U_4_17);
  sensitive << ( dout_m_req_m_trig_req );

}
// resource: regr_32b
void dut::drive_dout_data(){
  if ( stall0.read() );
  else {
    dout_data = dut_Div_64Ux2U_32U_4_47_out1.read();
  }
}
// resource: mux_1bx2i
// resource: regr_1b
void dut::drive_din_m_busy_req_0(){
  if ( (rst.read() == 0ULL) ) {
    din_m_busy_req_0 = 1ULL;
  } else {
    if ( stall0.read() );
    else {
      switch( (sc_uint<2>)(global_state.read()) ) {
      case 1ULL: 
        din_m_busy_req_0 = 0ULL;
        break;
      case 2ULL: 
        din_m_busy_req_0 = 1ULL;
        break;
      }
    }
  }
}
// resource: regr_1b
void dut::drive_dout_m_req_m_trig_req(){
  if ( (rst.read() == 0ULL) ) {
    dout_m_req_m_trig_req = 0ULL;
  } else {
    if ( stall0.read() );
    else {
      switch( (sc_uint<2>)(global_state.read()) ) {
      case 2ULL: 
        if ( (!cycle4_state.read() && s_reg_13.read()) ) {
          dout_m_req_m_trig_req = (sc_uint<1> ) (dut_Not_1U_1U_4_17_out1.read())
          ;
        } 
        break;
      }
    }
  }
}
// resource: mux_1bx2i
void dut::drive_stall0(){
  switch( (sc_uint<2>)(global_state.read()) ) {
  default:
    stall0 = 0ULL;
    break;
  case 1ULL: 
    if ( cycle6_state.read() ) {
      stall0 = 0ULL;
    } else {
      stall0 = dut_And_1Ux1U_1U_4_16_out1.read();
    }
    break;
  }
}
// resource: mux_1bx2i
// resource: regr_1b
void dut::drive_s_reg_13(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<2>)(global_state.read()) ) {
    case 1ULL: 
      if ( cycle4_state.read() );
      else {
        s_reg_13 = s_reg_13_stage1.read();
      }
      break;
    case 2ULL: 
      s_reg_13 = dut_Or_1Ux1U_1U_4_6_out1.read();
      break;
    }
  }
}
// resource: regr_8b
void dut::drive_s_reg_14(){
  if ( stall0.read() );
  else {
    s_reg_14 = dut_N_Mux_8_2_0_4_19_out1.read();
  }
}
// resource: regr_8b
void dut::drive_s_reg_15(){
  if ( stall0.read() );
  else {
    s_reg_15 = dut_N_Mux_8_2_0_4_20_out1.read();
  }
}
// resource: regr_8b
void dut::drive_s_reg_16(){
  if ( stall0.read() );
  else {
    s_reg_16 = dut_N_Mux_8_2_0_4_21_out1.read();
  }
}
// resource: regr_8b
void dut::drive_s_reg_17(){
  if ( stall0.read() );
  else {
    s_reg_17 = dut_N_Mux_8_2_0_4_22_out1.read();
  }
}
// resource: regr_8b
void dut::drive_s_reg_18(){
  if ( stall0.read() );
  else {
    s_reg_18 = dut_N_Mux_8_2_0_4_23_out1.read();
  }
}
// resource: regr_8b
void dut::drive_s_reg_19(){
  if ( stall0.read() );
  else {
    s_reg_19 = dut_N_Mux_8_2_0_4_27_out1.read();
  }
}
// resource: regr_8b
void dut::drive_s_reg_20(){
  if ( stall0.read() );
  else {
    s_reg_20 = dut_N_Mux_8_2_0_4_28_out1.read();
  }
}
// resource: regr_29b
void dut::drive_s_reg_21(){
  if ( stall0.read() );
  else {
    s_reg_21_slice11 = (sc_uint<29> )dut_Mul_33Ux32U_64U_4_33_out1.read();
  }
}
// resource: regr_17b
void dut::drive_s_reg_22(){
  if ( stall0.read() );
  else {
    s_reg_22 = (sc_uint<17> )dut_Add_32Ux17U_33U_1_36_out1.read();
  }
}
// resource: dut_N_Mux_8_2_0_4
void dut::dut_N_Mux_8_2_0_4_19(){
  if ( din_m_stall_reg_full.read() ) {
    dut_N_Mux_8_2_0_4_19_out1 = din_m_stall_reg_a.read();
  } else {
    dut_N_Mux_8_2_0_4_19_out1 = din_data_a.read();
  }
}
// resource: dut_N_Mux_8_2_0_4
void dut::dut_N_Mux_8_2_0_4_20(){
  if ( din_m_stall_reg_full.read() ) {
    dut_N_Mux_8_2_0_4_20_out1 = din_m_stall_reg_b.read();
  } else {
    dut_N_Mux_8_2_0_4_20_out1 = din_data_b.read();
  }
}
// resource: dut_N_Mux_8_2_0_4
void dut::dut_N_Mux_8_2_0_4_21(){
  if ( din_m_stall_reg_full.read() ) {
    dut_N_Mux_8_2_0_4_21_out1 = din_m_stall_reg_d.read();
  } else {
    dut_N_Mux_8_2_0_4_21_out1 = din_data_d.read();
  }
}
// resource: dut_N_Mux_8_2_0_4
void dut::dut_N_Mux_8_2_0_4_22(){
  if ( din_m_stall_reg_full.read() ) {
    dut_N_Mux_8_2_0_4_22_out1 = din_m_stall_reg_e.read();
  } else {
    dut_N_Mux_8_2_0_4_22_out1 = din_data_e.read();
  }
}
// resource: dut_N_Mux_8_2_0_4
void dut::dut_N_Mux_8_2_0_4_23(){
  if ( din_m_stall_reg_full.read() ) {
    dut_N_Mux_8_2_0_4_23_out1 = din_m_stall_reg_c.read();
  } else {
    dut_N_Mux_8_2_0_4_23_out1 = din_data_c.read();
  }
}
// resource: dut_N_Mux_8_2_0_4
void dut::dut_N_Mux_8_2_0_4_24(){
  if ( din_m_stall_reg_full.read() ) {
    dut_N_Mux_8_2_0_4_24_out1 = din_m_stall_reg_f.read();
  } else {
    dut_N_Mux_8_2_0_4_24_out1 = din_data_f.read();
  }
}
// resource: dut_Add_8Ux8U_9U_4  instance: dut_Add_8Ux8U_9U_4_25
void dut::dut_Add_8Ux8U_9U_4_25(){
  dut_Add_8Ux8U_9U_4_25_out1 = (dut_N_Mux_8_2_0_4_21_out1.read() + 
                               dut_N_Mux_8_2_0_4_22_out1.read());
}
// resource: dut_Add_8Ux8U_9U_4  instance: dut_Add_8Ux8U_9U_4_26
void dut::dut_Add_8Ux8U_9U_4_26(){
  dut_Add_8Ux8U_9U_4_26_out1 = (dut_N_Mux_8_2_0_4_19_out1.read() + 
                               dut_N_Mux_8_2_0_4_20_out1.read());
}
// resource: dut_N_Mux_8_2_0_4
void dut::dut_N_Mux_8_2_0_4_27(){
  if ( din_m_stall_reg_full.read() ) {
    dut_N_Mux_8_2_0_4_27_out1 = din_m_stall_reg_g.read();
  } else {
    dut_N_Mux_8_2_0_4_27_out1 = din_data_g.read();
  }
}
// resource: dut_N_Mux_8_2_0_4
void dut::dut_N_Mux_8_2_0_4_28(){
  if ( din_m_stall_reg_full.read() ) {
    dut_N_Mux_8_2_0_4_28_out1 = din_m_stall_reg_h.read();
  } else {
    dut_N_Mux_8_2_0_4_28_out1 = din_data_h.read();
  }
}
// resource: dut_Add_9Ux8U_10U_4  instance: dut_Add_9Ux8U_10U_4_29
void dut::dut_Add_9Ux8U_10U_4_29(){
  dut_Add_9Ux8U_10U_4_29_out1 = (dut_Add_8Ux8U_9U_4_25_out1.read() + 
                                dut_N_Mux_8_2_0_4_24_out1.read());
}
// resource: dut_Add_9Ux8U_10U_4  instance: dut_Add_9Ux8U_10U_4_30
void dut::dut_Add_9Ux8U_10U_4_30(){
  dut_Add_9Ux8U_10U_4_30_out1 = (dut_Add_8Ux8U_9U_4_26_out1.read() + 
                                dut_N_Mux_8_2_0_4_23_out1.read());
}
// resource: dut_Add_8Ux8U_9U_4  instance: dut_Add_8Ux8U_9U_4_31
void dut::dut_Add_8Ux8U_9U_4_31(){
  dut_Add_8Ux8U_9U_4_31_out1 = (dut_N_Mux_8_2_0_4_27_out1.read() + 
                               dut_N_Mux_8_2_0_4_28_out1.read());
}
// resource: mux_29bx2i
void dut::drive_dut_Mul_32Ux10U_32U_4_32_in2(){
  if ( gs_ctrl0.read() ) {
    dut_Mul_32Ux10U_32U_4_32_in2_slice = (sc_uint<29> ) (
                                         dut_Add_9Ux8U_10U_4_30_out1.read());
  } else {
    dut_Mul_32Ux10U_32U_4_32_in2_slice = s_reg_21_slice11.read();
  }
}
// resource: mux_10bx2i
void dut::drive_dut_Mul_32Ux10U_32U_4_32_in1(){
  if ( gs_ctrl0.read() ) {
    dut_Mul_32Ux10U_32U_4_32_in1 = dut_Add_9Ux8U_10U_4_29_out1.read();
  } else {
    dut_Mul_32Ux10U_32U_4_32_in1 = (sc_uint<10> ) (dut_Add_8Ux8U_9U_4_39_out1
                                   .read());
  }
}
// resource: dut_Mul_32Ux10U_32U_4  instance: dut_Mul_32Ux10U_32U_4_32
void dut::dut_Mul_32Ux10U_32U_4_32(){
  dut_Mul_32Ux10U_32U_4_32_out1 = ( (sc_uint<32> )(sc_bv<32>)((sc_bv<3>)(0ULL), 
                                  (sc_bv<29>)(dut_Mul_32Ux10U_32U_4_32_in2_slice
                                  .read())) ) * dut_Mul_32Ux10U_32U_4_32_in1
                                  .read();
}
// resource: mux_33bx2i
void dut::drive_dut_Mul_33Ux32U_64U_4_33_in2(){
  if ( gs_ctrl0.read() ) {
    dut_Mul_33Ux32U_64U_4_33_in2 = (sc_uint<33> ) ((sc_uint<20> )
                                   dut_Mul_32Ux10U_32U_4_32_out1.read());
  } else {
    dut_Mul_33Ux32U_64U_4_33_in2 = dut_Add_32Ux16U_33U_4_45_out1.read();
  }
}
// resource: mux_32bx2i
void dut::drive_dut_Mul_33Ux32U_64U_4_33_in1(){
  if ( gs_ctrl0.read() ) {
    dut_Mul_33Ux32U_64U_4_33_in1 = (sc_uint<32> ) (dut_Add_8Ux8U_9U_4_31_out1
                                   .read());
  } else {
    dut_Mul_33Ux32U_64U_4_33_in1 = dut_Add_32Ux32U_32U_4_44_out1.read();
  }
}
// resource: dut_Mul_33Ux32U_64U_4  instance: dut_Mul_33Ux32U_64U_4_33
void dut::dut_Mul_33Ux32U_64U_4_33(){
  dut_Mul_33Ux32U_64U_4_33_out1 = dut_Mul_33Ux32U_64U_4_33_in2.read() * 
                                  dut_Mul_33Ux32U_64U_4_33_in1.read();
}
// resource: mux_8bx2i
void dut::drive_dut_Mul_8Ux8U_16U_4_34_in2(){
  if ( gs_ctrl0.read() ) {
    dut_Mul_8Ux8U_16U_4_34_in2 = dut_N_Mux_8_2_0_4_23_out1.read();
  } else {
    dut_Mul_8Ux8U_16U_4_34_in2 = s_reg_19.read();
  }
}
// resource: mux_8bx2i
void dut::drive_dut_Mul_8Ux8U_16U_4_34_in1(){
  if ( gs_ctrl0.read() ) {
    dut_Mul_8Ux8U_16U_4_34_in1 = dut_N_Mux_8_2_0_4_21_out1.read();
  } else {
    dut_Mul_8Ux8U_16U_4_34_in1 = s_reg_20.read();
  }
}
// resource: dut_Mul_8Ux8U_16U_4  instance: dut_Mul_8Ux8U_16U_4_34
void dut::dut_Mul_8Ux8U_16U_4_34(){
  dut_Mul_8Ux8U_16U_4_34_out1 = dut_Mul_8Ux8U_16U_4_34_in2.read() * 
                                dut_Mul_8Ux8U_16U_4_34_in1.read();
}
// resource: mux_29bx2i
void dut::drive_dut_Mul_32Ux9U_32U_4_35_in2(){
  if ( gs_ctrl0.read() ) {
    dut_Mul_32Ux9U_32U_4_35_in2_slice = (sc_uint<29> ) (
                                        dut_N_Mux_8_2_0_4_19_out1.read());
  } else {
    dut_Mul_32Ux9U_32U_4_35_in2_slice = s_reg_21_slice11.read();
  }
}
// resource: mux_8bx2i
void dut::drive_dut_Mul_32Ux9U_32U_4_35_in1(){
  if ( gs_ctrl0.read() ) {
    dut_Mul_32Ux9U_32U_4_35_in1_slice = dut_N_Mux_8_2_0_4_20_out1.read();
  } else {
    dut_Mul_32Ux9U_32U_4_35_in1_slice = s_reg_17.read();
  }
}
// resource: dut_Mul_32Ux9U_32U_4  instance: dut_Mul_32Ux9U_32U_4_35
void dut::dut_Mul_32Ux9U_32U_4_35(){
  dut_Mul_32Ux9U_32U_4_35_out1 = ( (sc_uint<32> )(sc_bv<32>)((sc_bv<3>)(0ULL), 
                                 (sc_bv<29>)(dut_Mul_32Ux9U_32U_4_35_in2_slice
                                 .read())) ) * ( (sc_uint<9> )(sc_bv<9>)(
                                 (sc_bv<1>)(0ULL), 
                                 (sc_bv<8>)(dut_Mul_32Ux9U_32U_4_35_in1_slice
                                 .read())) );
}
// resource: mux_32bx2i
void dut::drive_dut_Add_32Ux17U_33U_1_36_in2(){
  if ( gs_ctrl0.read() ) {
    dut_Add_32Ux17U_33U_1_36_in2 = (sc_uint<32> ) ((sc_uint<16> )
                                   dut_Mul_32Ux9U_32U_4_35_out1.read());
  } else {
    dut_Add_32Ux17U_33U_1_36_in2 = dut_Mul_32Ux9U_32U_4_35_out1.read();
  }
}
// resource: mux_17bx2i
void dut::drive_dut_Add_32Ux17U_33U_1_36_in1(){
  if ( gs_ctrl0.read() ) {
    dut_Add_32Ux17U_33U_1_36_in1 = (sc_uint<17> ) (dut_Mul_8Ux8U_16U_4_34_out1
                                   .read());
  } else {
    dut_Add_32Ux17U_33U_1_36_in1 = s_reg_22.read();
  }
}
// resource: dut_Add_32Ux17U_33U_1  instance: dut_Add_32Ux17U_33U_1_36
void dut::dut_Add_32Ux17U_33U_1_36(){
  dut_Add_32Ux17U_33U_1_36_out1 = (dut_Add_32Ux17U_33U_1_36_in2.read() + 
                                  dut_Add_32Ux17U_33U_1_36_in1.read());
}
// resource: dut_Add_8Ux8U_9U_4  instance: dut_Add_8Ux8U_9U_4_39
void dut::dut_Add_8Ux8U_9U_4_39(){
  dut_Add_8Ux8U_9U_4_39_out1 = (s_reg_16.read() + s_reg_18.read());
}
// resource: dut_Add_8Ux8U_9U_4  instance: dut_Add_8Ux8U_9U_4_40
void dut::dut_Add_8Ux8U_9U_4_40(){
  dut_Add_8Ux8U_9U_4_40_out1 = (s_reg_14.read() + s_reg_15.read());
}
// resource: dut_Mul_32Ux9U_32U_4  instance: dut_Mul_32Ux9U_32U_4_42
void dut::dut_Mul_32Ux9U_32U_4_42(){
  dut_Mul_32Ux9U_32U_4_42_out1 = (sc_uint<32> )dut_Add_32Ux17U_33U_1_36_out1
                                 .read() * dut_Add_8Ux8U_9U_4_40_out1.read();
}
// resource: dut_Add_32Ux32U_32U_4  instance: dut_Add_32Ux32U_32U_4_44
void dut::dut_Add_32Ux32U_32U_4_44(){
  dut_Add_32Ux32U_32U_4_44_out1 = (dut_Mul_32Ux9U_32U_4_42_out1.read() + 
                                  dut_Mul_32Ux10U_32U_4_32_out1.read());
}
// resource: dut_Add_32Ux16U_33U_4  instance: dut_Add_32Ux16U_33U_4_45
void dut::dut_Add_32Ux16U_33U_4_45(){
  dut_Add_32Ux16U_33U_4_45_out1 = ((sc_uint<32> )dut_Add_32Ux17U_33U_1_36_out1
                                  .read() + dut_Mul_8Ux8U_16U_4_34_out1.read());
}
void dut::drive_dut_Div_64Ux2U_32U_4_47_in1(){
  dut_Div_64Ux2U_32U_4_47_in1 = 3ULL;
}
// resource: regr_1b
void dut::drive_s_reg_13_stage1(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<2>)(global_state.read()) ) {
    case 1ULL: 
      if ( cycle2_state.read() );
      else {
        s_reg_13_stage1 = s_reg_13.read();
      }
      break;
    }
  }
}
// resource: regr_64b
void dut::drive_s_reg_21_stage1(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<2>)(global_state.read()) ) {
    case 1ULL: 
      if ( cycle2_state.read() );
      else {
        s_reg_21_stage1 = dut_Mul_33Ux32U_64U_4_33_out1.read();
      }
      break;
    }
  }
}
// resource: mux_1bx2i
// resource: regr_1b
void dut::drive_cycle2_state(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<2>)(global_state.read()) ) {
    case 0ULL: 
      cycle2_state = 1ULL;
      break;
    case 2ULL: 
      cycle2_state = 0ULL;
      break;
    }
  }
}
// resource: mux_1bx2i
// resource: regr_1b
void dut::drive_cycle4_state(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<2>)(global_state.read()) ) {
    case 0ULL: 
      cycle4_state = 1ULL;
      break;
    case 2ULL: 
      cycle4_state = cycle2_state.read();
      break;
    }
  }
}
// resource: mux_1bx2i
// resource: regr_1b
void dut::drive_cycle6_state(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<2>)(global_state.read()) ) {
    case 0ULL: 
      cycle6_state = 1ULL;
      break;
    case 2ULL: 
      cycle6_state = cycle4_state.read();
      break;
    }
  }
}
// resource: regr_2b
void dut::drive_global_state(){
  if ( (rst.read() == 0ULL) ) {
    global_state = 0ULL;
  } else {
    if ( stall0.read() );
    else {
      global_state = global_state_next.read();
    }
  }
}
// resource: mux_2bx2i
void dut::drive_global_state_next(){
  switch( (sc_uint<2>)(global_state.read()) ) {
  default:
    global_state_next = (global_state.read() + 1ULL);
    break;
  case 0ULL: case 2ULL: 
    global_state_next = 1ULL;
    break;
  }
}
// resource: mux_1bx2i
// resource: regr_1b
void dut::drive_gs_ctrl0(){
  if ( (rst.read() == 0ULL) ) {
    gs_ctrl0 = 0ULL;
  } else {
    if ( stall0.read() );
    else {
      switch( (sc_uint<2>)(global_state_next.read()) ) {
      default:
        gs_ctrl0 = 0ULL;
        break;
      case 2ULL: 
        gs_ctrl0 = 1ULL;
        break;
      }
    }
  }
}
void dut::drive_din_busy(){
  din_busy = (sc_uint<1> ) (dut_Or_1Ux1U_1U_4_7_out1.read());
}
// resource: dut_Or_1Ux1U_1U_4  instance: dut_Or_1Ux1U_1U_4_2
void dut::dut_Or_1Ux1U_1U_4_2(){
  dut_Or_1Ux1U_1U_4_2_out1 = din_m_unvalidated_req.read() | din_vld.read();
}
// resource: dut_And_1Ux1U_1U_4  instance: dut_And_1Ux1U_1U_4_3
void dut::dut_And_1Ux1U_1U_4_3(){
  dut_And_1Ux1U_1U_4_3_out1 = (sc_uint<1> ) (dut_Or_1Ux1U_1U_4_2_out1.read() & (
                              sc_uint<1> )din_m_busy_req_0.read());
}
// resource: dut_Not_1U_1U_4  instance: dut_Not_1U_1U_4_4
void dut::dut_Not_1U_1U_4_4(){
  dut_Not_1U_1U_4_4_out1 = !dut_And_1Ux1U_1U_4_3_out1.read();
}
// resource: dut_And_1Ux1U_1U_4  instance: dut_And_1Ux1U_1U_4_5
void dut::dut_And_1Ux1U_1U_4_5(){
  dut_And_1Ux1U_1U_4_5_out1 = (sc_uint<1> ) (dut_Not_1U_1U_4_4_out1.read() & (
                              sc_uint<1> )din_vld.read());
}
// resource: dut_Or_1Ux1U_1U_4  instance: dut_Or_1Ux1U_1U_4_6
void dut::dut_Or_1Ux1U_1U_4_6(){
  dut_Or_1Ux1U_1U_4_6_out1 = dut_And_1Ux1U_1U_4_5_out1.read() | (sc_uint<1> )
                             din_m_stall_reg_full.read();
}
// resource: dut_Or_1Ux1U_1U_4  instance: dut_Or_1Ux1U_1U_4_7
void dut::dut_Or_1Ux1U_1U_4_7(){
  dut_Or_1Ux1U_1U_4_7_out1 = dut_And_1Ux1U_1U_4_3_out1.read() | (sc_uint<1> )
                             din_m_stall_reg_full.read();
}
// resource: regr_1b
void dut::drive_din_m_unvalidated_req(){
  if ( (rst.read() == 0ULL) ) {
    din_m_unvalidated_req = 1ULL;
  } else {
    din_m_unvalidated_req = (sc_uint<1> ) (dut_N_Muxb_1_2_1_4_1_out1.read());
  }
}
// resource: dut_N_Muxb_1_2_1_4
void dut::dut_N_Muxb_1_2_1_4_1(){
  if ( din_m_busy_req_0.read() ) {
    dut_N_Muxb_1_2_1_4_1_out1 = (sc_uint<1> ) (din_m_unvalidated_req.read());
  } else {
    dut_N_Muxb_1_2_1_4_1_out1 = (sc_uint<1> ) (din_vld.read());
  }
}
// resource: regr_8b
void dut::drive_din_m_stall_reg_h(){
  if ( dut_And_1Ux1U_1U_4_11_out1.read() ) {
    din_m_stall_reg_h = din_data_h.read();
  } 
}
// resource: regr_8b
void dut::drive_din_m_stall_reg_g(){
  if ( dut_And_1Ux1U_1U_4_11_out1.read() ) {
    din_m_stall_reg_g = din_data_g.read();
  } 
}
// resource: regr_8b
void dut::drive_din_m_stall_reg_f(){
  if ( dut_And_1Ux1U_1U_4_11_out1.read() ) {
    din_m_stall_reg_f = din_data_f.read();
  } 
}
// resource: regr_8b
void dut::drive_din_m_stall_reg_e(){
  if ( dut_And_1Ux1U_1U_4_11_out1.read() ) {
    din_m_stall_reg_e = din_data_e.read();
  } 
}
// resource: regr_8b
void dut::drive_din_m_stall_reg_d(){
  if ( dut_And_1Ux1U_1U_4_11_out1.read() ) {
    din_m_stall_reg_d = din_data_d.read();
  } 
}
// resource: regr_8b
void dut::drive_din_m_stall_reg_c(){
  if ( dut_And_1Ux1U_1U_4_11_out1.read() ) {
    din_m_stall_reg_c = din_data_c.read();
  } 
}
// resource: regr_8b
void dut::drive_din_m_stall_reg_b(){
  if ( dut_And_1Ux1U_1U_4_11_out1.read() ) {
    din_m_stall_reg_b = din_data_b.read();
  } 
}
// resource: regr_8b
void dut::drive_din_m_stall_reg_a(){
  if ( dut_And_1Ux1U_1U_4_11_out1.read() ) {
    din_m_stall_reg_a = din_data_a.read();
  } 
}
// resource: dut_Not_1U_1U_4  instance: dut_Not_1U_1U_4_9
void dut::dut_Not_1U_1U_4_9(){
  dut_Not_1U_1U_4_9_out1 = !din_m_stall_reg_full.read();
}
// resource: dut_And_1Ux1U_1U_4  instance: dut_And_1Ux1U_1U_4_10
void dut::dut_And_1Ux1U_1U_4_10(){
  dut_And_1Ux1U_1U_4_10_out1 = (sc_uint<1> ) (dut_Or_1Ux1U_1U_4_6_out1.read() & 
                               stall0.read());
}
// resource: dut_And_1Ux1U_1U_4  instance: dut_And_1Ux1U_1U_4_11
void dut::dut_And_1Ux1U_1U_4_11(){
  dut_And_1Ux1U_1U_4_11_out1 = (sc_uint<1> ) (dut_And_1Ux1U_1U_4_10_out1.read()
                                & dut_Not_1U_1U_4_9_out1.read());
}
// resource: regr_1b
void dut::drive_din_m_stall_reg_full(){
  if ( (rst.read() == 0ULL) ) {
    din_m_stall_reg_full = 0ULL;
  } else {
    din_m_stall_reg_full = (sc_uint<1> ) (dut_And_1Ux1U_1U_4_12_out1.read());
  }
}
// resource: dut_And_1Ux1U_1U_4  instance: dut_And_1Ux1U_1U_4_12
void dut::dut_And_1Ux1U_1U_4_12(){
  dut_And_1Ux1U_1U_4_12_out1 = (sc_uint<1> ) (dut_Or_1Ux1U_1U_4_6_out1.read() & 
                               stall0.read());
}
void dut::drive_dout_vld(){
  dout_vld = (sc_uint<1> ) (dut_Or_1Ux1U_1U_4_15_out1.read());
}
// resource: dut_Or_1Ux1U_1U_4  instance: dut_Or_1Ux1U_1U_4_15
void dut::dut_Or_1Ux1U_1U_4_15(){
  dut_Or_1Ux1U_1U_4_15_out1 = dout_m_unacked_req.read() | (sc_uint<1>)
                              dut_Xor_1Ux1U_1U_4_14_out1.read();
}
// resource: regr_1b
void dut::drive_dout_m_unacked_req(){
  if ( (rst.read() == 0ULL) ) {
    dout_m_unacked_req = 0ULL;
  } else {
    dout_m_unacked_req = (sc_uint<1> ) (dut_And_1Ux1U_1U_4_16_out1.read());
  }
}
// resource: dut_And_1Ux1U_1U_4  instance: dut_And_1Ux1U_1U_4_16
void dut::dut_And_1Ux1U_1U_4_16(){
  dut_And_1Ux1U_1U_4_16_out1 = (sc_uint<1> ) (dout_busy.read() & dout_vld.read()
                               );
}
// resource: dut_Xor_1Ux1U_1U_4  instance: dut_Xor_1Ux1U_1U_4_14
void dut::dut_Xor_1Ux1U_1U_4_14(){
  dut_Xor_1Ux1U_1U_4_14_out1 = (sc_uint<1> ) (dout_m_req_m_trig_req.read() ^ 
                               dout_m_req_m_prev_trig_req.read());
}
// resource: regr_1b
void dut::drive_dout_m_req_m_prev_trig_req(){
  if ( (rst.read() == 0ULL) ) {
    dout_m_req_m_prev_trig_req = 0ULL;
  } else {
    dout_m_req_m_prev_trig_req = dout_m_req_m_trig_req.read();
  }
}
// resource: dut_Not_1U_1U_4  instance: dut_Not_1U_1U_4_17
void dut::dut_Not_1U_1U_4_17(){
  dut_Not_1U_1U_4_17_out1 = !dout_m_req_m_trig_req.read();
}
