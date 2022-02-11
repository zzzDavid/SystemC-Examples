// Generated by stratus_hls 17.20-p100  (88533.190925)
// Tue Nov 17 22:54:34 2020
// from dut.cc
#include "dut_rtl.h"

struct dut;
dut::dut(sc_module_name name) : sc_module(name) 
    ,clk("clk")
    ,rst("rst")
    ,din_busy("din_busy")
    ,din_vld("din_vld")
    ,din_data("din_data")
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
    ,dut_Add_11Ux8U_11U_4_15_in1("dut_Add_11Ux8U_11U_4_15_in1")
    ,gs_ctrl1("gs_ctrl1")
    ,dut_Add_11Ux8U_11U_4_15_in2("dut_Add_11Ux8U_11U_4_15_in2")
    ,gs_ctrl0("gs_ctrl0")
    ,s_reg_25("s_reg_25")
    ,s_reg_24("s_reg_24")
    ,s_reg_23("s_reg_23")
    ,s_reg_22("s_reg_22")
    ,s_reg_21("s_reg_21")
    ,s_reg_20("s_reg_20")
    ,s_reg_19("s_reg_19")
    ,dut_Not_1U_1U_4_6_out1("dut_Not_1U_1U_4_6_out1")
    ,dut_And_1Ux1U_1U_4_11_out1("dut_And_1Ux1U_1U_4_11_out1")
    ,dut_Not_1U_1U_4_12_out1("dut_Not_1U_1U_4_12_out1")
    ,dout_m_req_m_trig_req("dout_m_req_m_trig_req")
    ,din_m_busy_req_0("din_m_busy_req_0")
    ,dut_Add_11Ux8U_11U_4_15_out1("dut_Add_11Ux8U_11U_4_15_out1")
    ,dut_Add_9Ux8U_10U_4_14_out1("dut_Add_9Ux8U_10U_4_14_out1")
    ,dut_Add_8Ux8U_9U_4_13_out1("dut_Add_8Ux8U_9U_4_13_out1")
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

  SC_METHOD(drive_s_reg_23);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_24);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_s_reg_25);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(dut_Add_8Ux8U_9U_4_13);
  sensitive << ( s_reg_20 );
  sensitive << ( s_reg_19 );

  SC_METHOD(dut_Add_9Ux8U_10U_4_14);
  sensitive << ( s_reg_20 );
  sensitive << ( dout_data );

  SC_METHOD(drive_dut_Add_11Ux8U_11U_4_15_in2);
  sensitive << ( gs_ctrl0 );
  sensitive << ( dout_data );

  SC_METHOD(drive_dut_Add_11Ux8U_11U_4_15_in1);
  sensitive << ( gs_ctrl1 );
  sensitive << ( s_reg_21 );
  sensitive << ( s_reg_22 );
  sensitive << ( s_reg_23 );
  sensitive << ( s_reg_24 );
  sensitive << ( s_reg_25 );

  SC_METHOD(dut_Add_11Ux8U_11U_4_15);
  sensitive << ( dut_Add_11Ux8U_11U_4_15_in1 );
  sensitive << ( dut_Add_11Ux8U_11U_4_15_in2 );

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
// resource: mux_11bx5i
// resource: regr_11b
void dut::drive_dout_data(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<4>)(global_state.read()) ) {
    case 1ULL: 
      dout_data = (sc_uint<11> ) (din_data.read());
      break;
    case 2ULL: case 9ULL: 
      dout_data = (sc_uint<11> ) (dut_Add_8Ux8U_9U_4_13_out1.read());
      break;
    case 3ULL: 
      dout_data = (sc_uint<11> ) (dut_Add_9Ux8U_10U_4_14_out1.read());
      break;
    case 4ULL: case 5ULL: case 6ULL: case 7ULL: 
      dout_data = dut_Add_11Ux8U_11U_4_15_out1.read();
      break;
    case 8ULL: 
      dout_data = (sc_uint<11> ) (dut_Add_11Ux8U_11U_4_15_out1.read().range(10,3
                  ));
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
      case 0ULL: case 2ULL: case 9ULL: 
        din_m_busy_req_0 = 0ULL;
        break;
      case 1ULL: case 3ULL: 
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
      case 1ULL: case 8ULL: 
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
  case 1ULL: case 3ULL: 
    stall0 = dut_Not_1U_1U_4_6_out1.read();
    break;
  case 2ULL: case 9ULL: 
    stall0 = dut_And_1Ux1U_1U_4_11_out1.read();
    break;
  }
}
// resource: mux_8bx2i
// resource: regr_8b
void dut::drive_s_reg_19(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<4>)(global_state.read()) ) {
    case 1ULL: 
      s_reg_19 = din_data.read();
      break;
    case 2ULL: case 9ULL: 
      s_reg_19 = s_reg_20.read();
      break;
    }
  }
}
// resource: mux_8bx2i
// resource: regr_8b
void dut::drive_s_reg_20(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<4>)(global_state.read()) ) {
    case 1ULL: 
      s_reg_20 = din_data.read();
      break;
    case 2ULL: case 9ULL: 
      s_reg_20 = s_reg_21.read();
      break;
    }
  }
}
// resource: mux_8bx2i
// resource: regr_8b
void dut::drive_s_reg_21(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<4>)(global_state.read()) ) {
    case 1ULL: 
      s_reg_21 = din_data.read();
      break;
    case 2ULL: case 9ULL: 
      s_reg_21 = s_reg_22.read();
      break;
    }
  }
}
// resource: mux_8bx2i
// resource: regr_8b
void dut::drive_s_reg_22(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<4>)(global_state.read()) ) {
    case 1ULL: 
      s_reg_22 = din_data.read();
      break;
    case 2ULL: case 9ULL: 
      s_reg_22 = s_reg_23.read();
      break;
    }
  }
}
// resource: mux_8bx2i
// resource: regr_8b
void dut::drive_s_reg_23(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<4>)(global_state.read()) ) {
    case 1ULL: 
      s_reg_23 = din_data.read();
      break;
    case 2ULL: case 9ULL: 
      s_reg_23 = s_reg_24.read();
      break;
    }
  }
}
// resource: mux_8bx2i
// resource: regr_8b
void dut::drive_s_reg_24(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<4>)(global_state.read()) ) {
    case 1ULL: 
      s_reg_24 = din_data.read();
      break;
    case 2ULL: case 9ULL: 
      s_reg_24 = s_reg_25.read();
      break;
    }
  }
}
// resource: regr_8b
void dut::drive_s_reg_25(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<4>)(global_state.read()) ) {
    case 1ULL: case 3ULL: 
      s_reg_25 = din_data.read();
      break;
    }
  }
}
// resource: dut_Add_8Ux8U_9U_4  instance: dut_Add_8Ux8U_9U_4_13
void dut::dut_Add_8Ux8U_9U_4_13(){
  dut_Add_8Ux8U_9U_4_13_out1 = (s_reg_19.read() + s_reg_20.read());
}
// resource: dut_Add_9Ux8U_10U_4  instance: dut_Add_9Ux8U_10U_4_14
void dut::dut_Add_9Ux8U_10U_4_14(){
  dut_Add_9Ux8U_10U_4_14_out1 = ((sc_uint<9> )dout_data.read() + s_reg_20.read()
                                );
}
// resource: mux_11bx2i
void dut::drive_dut_Add_11Ux8U_11U_4_15_in2(){
  if ( gs_ctrl0.read() ) {
    dut_Add_11Ux8U_11U_4_15_in2 = (sc_uint<11> ) ((sc_uint<10> )dout_data.read()
                                  );
  } else {
    dut_Add_11Ux8U_11U_4_15_in2 = dout_data.read();
  }
}
// resource: mux_8bx5i
void dut::drive_dut_Add_11Ux8U_11U_4_15_in1(){
  switch( (sc_uint<3>)(gs_ctrl1.read()) ) {
  default:
    dut_Add_11Ux8U_11U_4_15_in1 = s_reg_21.read();
    break;
  case 1ULL: 
    dut_Add_11Ux8U_11U_4_15_in1 = s_reg_22.read();
    break;
  case 2ULL: 
    dut_Add_11Ux8U_11U_4_15_in1 = s_reg_23.read();
    break;
  case 3ULL: 
    dut_Add_11Ux8U_11U_4_15_in1 = s_reg_24.read();
    break;
  case 4ULL: 
    dut_Add_11Ux8U_11U_4_15_in1 = s_reg_25.read();
    break;
  }
}
// resource: dut_Add_11Ux8U_11U_4  instance: dut_Add_11Ux8U_11U_4_15
void dut::dut_Add_11Ux8U_11U_4_15(){
  dut_Add_11Ux8U_11U_4_15_out1 = (dut_Add_11Ux8U_11U_4_15_in2.read() + 
                                 dut_Add_11Ux8U_11U_4_15_in1.read());
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
  case 2ULL: case 9ULL: 
    global_state_next = 3ULL;
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
      switch( (sc_uint<4>)(global_state_next.read()) ) {
      default:
        gs_ctrl0 = 0ULL;
        break;
      case 5ULL: 
        gs_ctrl0 = 1ULL;
        break;
      }
    }
  }
}
// resource: mux_3bx5i
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
      case 5ULL: 
        gs_ctrl1 = 1ULL;
        break;
      case 6ULL: 
        gs_ctrl1 = 2ULL;
        break;
      case 7ULL: 
        gs_ctrl1 = 3ULL;
        break;
      case 8ULL: 
        gs_ctrl1 = 4ULL;
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
