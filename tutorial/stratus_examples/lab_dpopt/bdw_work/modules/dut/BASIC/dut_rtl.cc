// Generated by stratus_hls 17.20-p100  (88533.190925)
// Wed Nov 18 11:32:36 2020
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
    ,dut_Xor_1Ux1U_1U_4_9_out1("dut_Xor_1Ux1U_1U_4_9_out1")
    ,dout_m_unacked_req("dout_m_unacked_req")
    ,dut_Or_1Ux1U_1U_4_10_out1("dut_Or_1Ux1U_1U_4_10_out1")
    ,dut_N_Muxb_1_2_0_4_1_out1("dut_N_Muxb_1_2_0_4_1_out1")
    ,dut_And_1Ux1U_1U_4_5_out1("dut_And_1Ux1U_1U_4_5_out1")
    ,dut_Not_1U_1U_4_4_out1("dut_Not_1U_1U_4_4_out1")
    ,dut_Or_1Ux1U_1U_4_2_out1("dut_Or_1Ux1U_1U_4_2_out1")
    ,din_m_unvalidated_req("din_m_unvalidated_req")
    ,dut_And_1Ux1U_1U_4_3_out1("dut_And_1Ux1U_1U_4_3_out1")
    ,global_state_next("global_state_next")
    ,dut_Add_32Ux32U_32U_4_26_in1("dut_Add_32Ux32U_32U_4_26_in1")
    ,gs_ctrl2("gs_ctrl2")
    ,dut_Mul_32Ux32U_32U_4_14_in1("dut_Mul_32Ux32U_32U_4_14_in1")
    ,gs_ctrl1("gs_ctrl1")
    ,dut_Mul_32Ux32U_32U_4_14_in2("dut_Mul_32Ux32U_32U_4_14_in2")
    ,gs_ctrl0("gs_ctrl0")
    ,s_reg_52("s_reg_52")
    ,dut_Add_8Ux8U_9U_4_25_out1("dut_Add_8Ux8U_9U_4_25_out1")
    ,dut_Add_8Ux8U_9U_4_20_out1("dut_Add_8Ux8U_9U_4_20_out1")
    ,dut_Add_9Ux8U_10U_4_19_out1("dut_Add_9Ux8U_10U_4_19_out1")
    ,dut_Add_8Ux8U_9U_4_15_out1("dut_Add_8Ux8U_9U_4_15_out1")
    ,s_reg_51("s_reg_51")
    ,s_reg_50("s_reg_50")
    ,dut_Add_16Ux16U_17U_4_23_out1("dut_Add_16Ux16U_17U_4_23_out1")
    ,s_reg_49("s_reg_49")
    ,dut_Add_9Ux8U_10U_4_17_out1("dut_Add_9Ux8U_10U_4_17_out1")
    ,dut_Add_8Ux8U_9U_4_13_out1("dut_Add_8Ux8U_9U_4_13_out1")
    ,s_reg_48("s_reg_48")
    ,s_reg_47("s_reg_47")
    ,s_reg_46("s_reg_46")
    ,s_reg_45("s_reg_45")
    ,s_reg_44("s_reg_44")
    ,s_reg_43("s_reg_43")
    ,s_reg_42("s_reg_42")
    ,s_reg_41("s_reg_41")
    ,dut_Not_1U_1U_4_6_out1("dut_Not_1U_1U_4_6_out1")
    ,dut_And_1Ux1U_1U_4_11_out1("dut_And_1Ux1U_1U_4_11_out1")
    ,dut_Not_1U_1U_4_12_out1("dut_Not_1U_1U_4_12_out1")
    ,dout_m_req_m_trig_req("dout_m_req_m_trig_req")
    ,din_m_busy_req_0("din_m_busy_req_0")
    ,dut_Add_32Ux32U_32U_4_26_out1("dut_Add_32Ux32U_32U_4_26_out1")
    ,dut_Mul_32Ux32U_32U_4_14_out1("dut_Mul_32Ux32U_32U_4_14_out1")
    ,global_state("global_state")
    ,stall0("stall0")
{
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
  sensitive << ( dut_Not_1U_1U_4_6_out1 );
  sensitive << ( dut_And_1Ux1U_1U_4_11_out1 );

  SC_METHOD(drive_s_reg_41);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_42);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_43);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_44);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_45);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_46);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_47);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_48);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_49);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_50);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_51);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_52);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(dut_Add_8Ux8U_9U_4_13);
  sensitive << ( din_data_e );
  sensitive << ( din_data_d );

  SC_METHOD(drive_dut_Mul_32Ux32U_32U_4_14_in2);
  sensitive << ( gs_ctrl0 );
  sensitive << ( s_reg_45 );
  sensitive << ( s_reg_41 );
  sensitive << ( s_reg_46 );
  sensitive << ( s_reg_51 );
  sensitive << ( s_reg_52 );
  sensitive << ( dout_data );

  SC_METHOD(drive_dut_Mul_32Ux32U_32U_4_14_in1);
  sensitive << ( gs_ctrl1 );
  sensitive << ( s_reg_43 );
  sensitive << ( s_reg_42 );
  sensitive << ( s_reg_47 );
  sensitive << ( s_reg_48 );
  sensitive << ( s_reg_51 );
  sensitive << ( s_reg_44 );
  sensitive << ( s_reg_50 );

  SC_METHOD(dut_Mul_32Ux32U_32U_4_14);
  sensitive << ( dut_Mul_32Ux32U_32U_4_14_in1 );
  sensitive << ( dut_Mul_32Ux32U_32U_4_14_in2 );

  SC_METHOD(dut_Add_8Ux8U_9U_4_15);
  sensitive << ( s_reg_42 );
  sensitive << ( s_reg_41 );

  SC_METHOD(dut_Add_9Ux8U_10U_4_17);
  sensitive << ( s_reg_49 );
  sensitive << ( s_reg_48 );

  SC_METHOD(dut_Add_9Ux8U_10U_4_19);
  sensitive << ( s_reg_45 );
  sensitive << ( s_reg_51 );

  SC_METHOD(dut_Add_8Ux8U_9U_4_20);
  sensitive << ( s_reg_47 );
  sensitive << ( s_reg_46 );

  SC_METHOD(dut_Add_16Ux16U_17U_4_23);
  sensitive << ( dout_data );
  sensitive << ( s_reg_49 );

  SC_METHOD(dut_Add_8Ux8U_9U_4_25);
  sensitive << ( s_reg_45 );
  sensitive << ( s_reg_43 );

  SC_METHOD(drive_dut_Add_32Ux32U_32U_4_26_in1);
  sensitive << ( gs_ctrl2 );
  sensitive << ( s_reg_49 );
  sensitive << ( s_reg_50 );
  sensitive << ( s_reg_52 );

  SC_METHOD(dut_Add_32Ux32U_32U_4_26);
  sensitive << ( dut_Add_32Ux32U_32U_4_26_in1 );
  sensitive << ( dout_data );

  SC_METHOD(drive_global_state);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_global_state_next);
  sensitive << ( global_state );

  SC_METHOD(drive_gs_ctrl0);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_gs_ctrl1);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_gs_ctrl2);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_din_busy);
  sensitive << ( dut_And_1Ux1U_1U_4_3_out1 );

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

  SC_METHOD(dut_Not_1U_1U_4_6);
  sensitive << ( dut_And_1Ux1U_1U_4_5_out1 );

  SC_METHOD(drive_din_m_unvalidated_req);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(dut_N_Muxb_1_2_0_4_1);
  sensitive << ( din_m_busy_req_0 );
  sensitive << ( din_m_unvalidated_req );
  sensitive << ( din_vld );

  SC_METHOD(drive_dout_vld);
  sensitive << ( dut_Or_1Ux1U_1U_4_10_out1 );

  SC_METHOD(dut_Or_1Ux1U_1U_4_10);
  sensitive << ( dut_Xor_1Ux1U_1U_4_9_out1 );
  sensitive << ( dout_m_unacked_req );

  SC_METHOD(drive_dout_m_unacked_req);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(dut_And_1Ux1U_1U_4_11);
  sensitive << ( dout_vld );
  sensitive << ( dout_busy );

  SC_METHOD(dut_Xor_1Ux1U_1U_4_9);
  sensitive << ( dout_m_req_m_prev_trig_req );
  sensitive << ( dout_m_req_m_trig_req );

  SC_METHOD(drive_dout_m_req_m_prev_trig_req);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(dut_Not_1U_1U_4_12);
  sensitive << ( dout_m_req_m_trig_req );

}
// resource: mux_32bx3i
// resource: regr_32b
void dut::drive_dout_data(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<4>)(global_state.read()) ) {
    case 2ULL: 
      dout_data = (sc_uint<32> ) ((sc_uint<16> )dut_Mul_32Ux32U_32U_4_14_out1
                  .read());
      break;
    case 7ULL: case 10ULL: case 12ULL: 
      dout_data = dut_Mul_32Ux32U_32U_4_14_out1.read();
      break;
    case 8ULL: case 11ULL: 
      dout_data = dut_Add_32Ux32U_32U_4_26_out1.read();
      break;
    }
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
      switch( (sc_uint<4>)(global_state.read()) ) {
      case 0ULL: case 13ULL: 
        din_m_busy_req_0 = 0ULL;
        break;
      case 1ULL: 
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
      switch( (sc_uint<4>)(global_state.read()) ) {
      case 12ULL: 
        dout_m_req_m_trig_req = (sc_uint<1> ) (dut_Not_1U_1U_4_12_out1.read());
        break;
      }
    }
  }
}
// resource: mux_1bx3i
void dut::drive_stall0(){
  switch( (sc_uint<4>)(global_state.read()) ) {
  default:
    stall0 = 0ULL;
    break;
  case 1ULL: 
    stall0 = dut_Not_1U_1U_4_6_out1.read();
    break;
  case 13ULL: 
    stall0 = dut_And_1Ux1U_1U_4_11_out1.read();
    break;
  }
}
// resource: regr_8b
void dut::drive_s_reg_41(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<4>)(global_state.read()) ) {
    case 1ULL: 
      s_reg_41 = din_data_a.read();
      break;
    }
  }
}
// resource: regr_8b
void dut::drive_s_reg_42(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<4>)(global_state.read()) ) {
    case 1ULL: 
      s_reg_42 = din_data_b.read();
      break;
    }
  }
}
// resource: regr_8b
void dut::drive_s_reg_43(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<4>)(global_state.read()) ) {
    case 1ULL: 
      s_reg_43 = din_data_d.read();
      break;
    }
  }
}
// resource: regr_8b
void dut::drive_s_reg_44(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<4>)(global_state.read()) ) {
    case 1ULL: 
      s_reg_44 = din_data_e.read();
      break;
    }
  }
}
// resource: regr_8b
void dut::drive_s_reg_45(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<4>)(global_state.read()) ) {
    case 1ULL: 
      s_reg_45 = din_data_c.read();
      break;
    }
  }
}
// resource: regr_8b
void dut::drive_s_reg_46(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<4>)(global_state.read()) ) {
    case 1ULL: 
      s_reg_46 = din_data_g.read();
      break;
    }
  }
}
// resource: regr_8b
void dut::drive_s_reg_47(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<4>)(global_state.read()) ) {
    case 1ULL: 
      s_reg_47 = din_data_h.read();
      break;
    }
  }
}
// resource: mux_10bx2i
// resource: regr_10b
void dut::drive_s_reg_48(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<4>)(global_state.read()) ) {
    case 1ULL: 
      s_reg_48 = (sc_uint<10> ) (dut_Add_8Ux8U_9U_4_13_out1.read());
      break;
    case 3ULL: 
      s_reg_48 = dut_Add_9Ux8U_10U_4_17_out1.read();
      break;
    }
  }
}
// resource: mux_17bx3i
// resource: regr_17b
void dut::drive_s_reg_49(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<4>)(global_state.read()) ) {
    case 1ULL: 
      s_reg_49 = (sc_uint<17> ) (din_data_f.read());
      break;
    case 3ULL: 
      s_reg_49 = (sc_uint<17> ) ((sc_uint<16> )dut_Mul_32Ux32U_32U_4_14_out1
                 .read());
      break;
    case 6ULL: 
      s_reg_49 = dut_Add_16Ux16U_17U_4_23_out1.read();
      break;
    }
  }
}
// resource: mux_32bx2i
// resource: regr_32b
void dut::drive_s_reg_50(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<4>)(global_state.read()) ) {
    case 4ULL: 
      s_reg_50 = (sc_uint<32> ) ((sc_uint<16> )dut_Mul_32Ux32U_32U_4_14_out1
                 .read());
      break;
    case 10ULL: 
      s_reg_50 = dut_Add_32Ux32U_32U_4_26_out1.read();
      break;
    }
  }
}
// resource: mux_10bx4i
// resource: regr_10b
void dut::drive_s_reg_51(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<4>)(global_state.read()) ) {
    case 2ULL: case 9ULL: 
      s_reg_51 = (sc_uint<10> ) (dut_Add_8Ux8U_9U_4_15_out1.read());
      break;
    case 4ULL: 
      s_reg_51 = dut_Add_9Ux8U_10U_4_19_out1.read();
      break;
    case 5ULL: 
      s_reg_51 = (sc_uint<10> ) (dut_Add_8Ux8U_9U_4_20_out1.read());
      break;
    case 7ULL: 
      s_reg_51 = (sc_uint<10> ) (dut_Add_8Ux8U_9U_4_25_out1.read());
      break;
    }
  }
}
// resource: mux_32bx3i
// resource: regr_32b
void dut::drive_s_reg_52(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<4>)(global_state.read()) ) {
    case 5ULL: 
      s_reg_52 = (sc_uint<32> ) ((sc_uint<20> )dut_Mul_32Ux32U_32U_4_14_out1
                 .read());
      break;
    case 6ULL: 
      s_reg_52 = (sc_uint<32> ) ((sc_uint<29> )dut_Mul_32Ux32U_32U_4_14_out1
                 .read());
      break;
    case 9ULL: 
      s_reg_52 = dut_Mul_32Ux32U_32U_4_14_out1.read();
      break;
    }
  }
}
// resource: dut_Add_8Ux8U_9U_4  instance: dut_Add_8Ux8U_9U_4_13
void dut::dut_Add_8Ux8U_9U_4_13(){
  dut_Add_8Ux8U_9U_4_13_out1 = (din_data_d.read() + din_data_e.read());
}
// resource: mux_32bx6i
void dut::drive_dut_Mul_32Ux32U_32U_4_14_in2(){
  switch( (sc_uint<3>)(gs_ctrl0.read()) ) {
  default:
    dut_Mul_32Ux32U_32U_4_14_in2 = (sc_uint<32> ) (s_reg_45.read());
    break;
  case 1ULL: 
    dut_Mul_32Ux32U_32U_4_14_in2 = (sc_uint<32> ) (s_reg_41.read());
    break;
  case 2ULL: 
    dut_Mul_32Ux32U_32U_4_14_in2 = (sc_uint<32> ) (s_reg_46.read());
    break;
  case 3ULL: 
    dut_Mul_32Ux32U_32U_4_14_in2 = (sc_uint<32> ) (s_reg_51.read());
    break;
  case 4ULL: 
    dut_Mul_32Ux32U_32U_4_14_in2 = s_reg_52.read();
    break;
  case 5ULL: 
    dut_Mul_32Ux32U_32U_4_14_in2 = dout_data.read();
    break;
  }
}
// resource: mux_32bx7i
void dut::drive_dut_Mul_32Ux32U_32U_4_14_in1(){
  switch( (sc_uint<3>)(gs_ctrl1.read()) ) {
  default:
    dut_Mul_32Ux32U_32U_4_14_in1 = (sc_uint<32> ) (s_reg_43.read());
    break;
  case 1ULL: 
    dut_Mul_32Ux32U_32U_4_14_in1 = (sc_uint<32> ) (s_reg_42.read());
    break;
  case 2ULL: 
    dut_Mul_32Ux32U_32U_4_14_in1 = (sc_uint<32> ) (s_reg_47.read());
    break;
  case 3ULL: 
    dut_Mul_32Ux32U_32U_4_14_in1 = (sc_uint<32> ) (s_reg_48.read());
    break;
  case 4ULL: 
    dut_Mul_32Ux32U_32U_4_14_in1 = (sc_uint<32> ) (s_reg_51.read());
    break;
  case 5ULL: 
    dut_Mul_32Ux32U_32U_4_14_in1 = (sc_uint<32> ) (s_reg_44.read());
    break;
  case 6ULL: 
    dut_Mul_32Ux32U_32U_4_14_in1 = s_reg_50.read();
    break;
  }
}
// resource: dut_Mul_32Ux32U_32U_4  instance: dut_Mul_32Ux32U_32U_4_14
void dut::dut_Mul_32Ux32U_32U_4_14(){
  dut_Mul_32Ux32U_32U_4_14_out1 = dut_Mul_32Ux32U_32U_4_14_in2.read() * 
                                  dut_Mul_32Ux32U_32U_4_14_in1.read();
}
// resource: dut_Add_8Ux8U_9U_4  instance: dut_Add_8Ux8U_9U_4_15
void dut::dut_Add_8Ux8U_9U_4_15(){
  dut_Add_8Ux8U_9U_4_15_out1 = (s_reg_41.read() + s_reg_42.read());
}
// resource: dut_Add_9Ux8U_10U_4  instance: dut_Add_9Ux8U_10U_4_17
void dut::dut_Add_9Ux8U_10U_4_17(){
  dut_Add_9Ux8U_10U_4_17_out1 = ((sc_uint<9> )s_reg_48.read() + (sc_uint<8> )
                                s_reg_49.read());
}
// resource: dut_Add_9Ux8U_10U_4  instance: dut_Add_9Ux8U_10U_4_19
void dut::dut_Add_9Ux8U_10U_4_19(){
  dut_Add_9Ux8U_10U_4_19_out1 = ((sc_uint<9> )s_reg_51.read() + s_reg_45.read())
  ;
}
// resource: dut_Add_8Ux8U_9U_4  instance: dut_Add_8Ux8U_9U_4_20
void dut::dut_Add_8Ux8U_9U_4_20(){
  dut_Add_8Ux8U_9U_4_20_out1 = (s_reg_46.read() + s_reg_47.read());
}
// resource: dut_Add_16Ux16U_17U_4  instance: dut_Add_16Ux16U_17U_4_23
void dut::dut_Add_16Ux16U_17U_4_23(){
  dut_Add_16Ux16U_17U_4_23_out1 = ((sc_uint<16> )s_reg_49.read() + (sc_uint<16> 
                                  )dout_data.read());
}
// resource: dut_Add_8Ux8U_9U_4  instance: dut_Add_8Ux8U_9U_4_25
void dut::dut_Add_8Ux8U_9U_4_25(){
  dut_Add_8Ux8U_9U_4_25_out1 = (s_reg_43.read() + s_reg_45.read());
}
// resource: mux_32bx3i
void dut::drive_dut_Add_32Ux32U_32U_4_26_in1(){
  switch( (sc_uint<2>)(gs_ctrl2.read()) ) {
  default:
    dut_Add_32Ux32U_32U_4_26_in1 = (sc_uint<32> ) (s_reg_49.read());
    break;
  case 1ULL: 
    dut_Add_32Ux32U_32U_4_26_in1 = s_reg_50.read();
    break;
  case 2ULL: 
    dut_Add_32Ux32U_32U_4_26_in1 = s_reg_52.read();
    break;
  }
}
// resource: dut_Add_32Ux32U_32U_4  instance: dut_Add_32Ux32U_32U_4_26
void dut::dut_Add_32Ux32U_32U_4_26(){
  dut_Add_32Ux32U_32U_4_26_out1 = (dout_data.read() + 
                                  dut_Add_32Ux32U_32U_4_26_in1.read());
}
// resource: regr_4b
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
// resource: mux_4bx2i
void dut::drive_global_state_next(){
  switch( (sc_uint<4>)(global_state.read()) ) {
  default:
    global_state_next = (global_state.read() + 1ULL);
    break;
  case 0ULL: case 13ULL: 
    global_state_next = 1ULL;
    break;
  }
}
// resource: mux_3bx6i
// resource: regr_3b
void dut::drive_gs_ctrl0(){
  if ( (rst.read() == 0ULL) ) {
    gs_ctrl0 = 0ULL;
  } else {
    if ( stall0.read() );
    else {
      switch( (sc_uint<4>)(global_state_next.read()) ) {
      default:
        gs_ctrl0 = 0ULL;
        break;
      case 3ULL: 
        gs_ctrl0 = 1ULL;
        break;
      case 4ULL: 
        gs_ctrl0 = 2ULL;
        break;
      case 5ULL: 
        gs_ctrl0 = 3ULL;
        break;
      case 6ULL: case 7ULL: case 9ULL: 
        gs_ctrl0 = 4ULL;
        break;
      case 10ULL: case 12ULL: 
        gs_ctrl0 = 5ULL;
        break;
      }
    }
  }
}
// resource: mux_3bx7i
// resource: regr_3b
void dut::drive_gs_ctrl1(){
  if ( (rst.read() == 0ULL) ) {
    gs_ctrl1 = 0ULL;
  } else {
    if ( stall0.read() );
    else {
      switch( (sc_uint<4>)(global_state_next.read()) ) {
      default:
        gs_ctrl1 = 0ULL;
        break;
      case 3ULL: 
        gs_ctrl1 = 1ULL;
        break;
      case 4ULL: 
        gs_ctrl1 = 2ULL;
        break;
      case 5ULL: 
        gs_ctrl1 = 3ULL;
        break;
      case 6ULL: case 9ULL: case 10ULL: 
        gs_ctrl1 = 4ULL;
        break;
      case 7ULL: 
        gs_ctrl1 = 5ULL;
        break;
      case 12ULL: 
        gs_ctrl1 = 6ULL;
        break;
      }
    }
  }
}
// resource: mux_2bx3i
// resource: regr_2b
void dut::drive_gs_ctrl2(){
  if ( (rst.read() == 0ULL) ) {
    gs_ctrl2 = 0ULL;
  } else {
    if ( stall0.read() );
    else {
      switch( (sc_uint<4>)(global_state_next.read()) ) {
      default:
        gs_ctrl2 = 0ULL;
        break;
      case 10ULL: 
        gs_ctrl2 = 1ULL;
        break;
      case 11ULL: 
        gs_ctrl2 = 2ULL;
        break;
      }
    }
  }
}
void dut::drive_din_busy(){
  din_busy = (sc_uint<1> ) (dut_And_1Ux1U_1U_4_3_out1.read());
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
// resource: dut_Not_1U_1U_4  instance: dut_Not_1U_1U_4_6
void dut::dut_Not_1U_1U_4_6(){
  dut_Not_1U_1U_4_6_out1 = !dut_And_1Ux1U_1U_4_5_out1.read();
}
// resource: regr_1b
void dut::drive_din_m_unvalidated_req(){
  if ( (rst.read() == 0ULL) ) {
    din_m_unvalidated_req = 1ULL;
  } else {
    din_m_unvalidated_req = (sc_uint<1> ) (dut_N_Muxb_1_2_0_4_1_out1.read());
  }
}
// resource: dut_N_Muxb_1_2_0_4
void dut::dut_N_Muxb_1_2_0_4_1(){
  if ( din_m_busy_req_0.read() ) {
    dut_N_Muxb_1_2_0_4_1_out1 = (sc_uint<1> ) (din_m_unvalidated_req.read());
  } else {
    dut_N_Muxb_1_2_0_4_1_out1 = (sc_uint<1> ) (din_vld.read());
  }
}
void dut::drive_dout_vld(){
  dout_vld = (sc_uint<1> ) (dut_Or_1Ux1U_1U_4_10_out1.read());
}
// resource: dut_Or_1Ux1U_1U_4  instance: dut_Or_1Ux1U_1U_4_10
void dut::dut_Or_1Ux1U_1U_4_10(){
  dut_Or_1Ux1U_1U_4_10_out1 = dout_m_unacked_req.read() | (sc_uint<1>)
                              dut_Xor_1Ux1U_1U_4_9_out1.read();
}
// resource: regr_1b
void dut::drive_dout_m_unacked_req(){
  if ( (rst.read() == 0ULL) ) {
    dout_m_unacked_req = 0ULL;
  } else {
    dout_m_unacked_req = (sc_uint<1> ) (dut_And_1Ux1U_1U_4_11_out1.read());
  }
}
// resource: dut_And_1Ux1U_1U_4  instance: dut_And_1Ux1U_1U_4_11
void dut::dut_And_1Ux1U_1U_4_11(){
  dut_And_1Ux1U_1U_4_11_out1 = (sc_uint<1> ) (dout_busy.read() & dout_vld.read()
                               );
}
// resource: dut_Xor_1Ux1U_1U_4  instance: dut_Xor_1Ux1U_1U_4_9
void dut::dut_Xor_1Ux1U_1U_4_9(){
  dut_Xor_1Ux1U_1U_4_9_out1 = (sc_uint<1> ) (dout_m_req_m_trig_req.read() ^ 
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
// resource: dut_Not_1U_1U_4  instance: dut_Not_1U_1U_4_12
void dut::dut_Not_1U_1U_4_12(){
  dut_Not_1U_1U_4_12_out1 = !dout_m_req_m_trig_req.read();
}
