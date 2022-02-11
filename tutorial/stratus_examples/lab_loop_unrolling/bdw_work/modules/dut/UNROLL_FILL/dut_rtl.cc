// Generated by stratus_hls 17.20-p100  (88533.190925)
// Tue Nov 17 22:53:07 2020
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
    ,dut_Add_4Sx2S_5S_4_16_in2("dut_Add_4Sx2S_5S_4_16_in2")
    ,gs_ctrl5("gs_ctrl5")
    ,dut_Add_3Sx2S_3S_4_13_in2("dut_Add_3Sx2S_3S_4_13_in2")
    ,gs_ctrl4("gs_ctrl4")
    ,gs_ctrl3("gs_ctrl3")
    ,gs_ctrl2("gs_ctrl2")
    ,gs_ctrl1("gs_ctrl1")
    ,gs_ctrl0("gs_ctrl0")
    ,dut_Add_3Sx2S_3S_4_13_out1("dut_Add_3Sx2S_3S_4_13_out1")
    ,dut_LessThan_4Sx4S_1U_4_15_out1("dut_LessThan_4Sx4S_1U_4_15_out1")
    ,dut_Add_4Sx2S_5S_4_16_out1("dut_Add_4Sx2S_5S_4_16_out1")
    ,dut_Add_4Sx2S_4S_4_14_out1("dut_Add_4Sx2S_4S_4_14_out1")
    ,s_reg_12("s_reg_12")
    ,dut_Not_1U_1U_4_6_out1("dut_Not_1U_1U_4_6_out1")
    ,dut_And_1Ux1U_1U_4_11_out1("dut_And_1Ux1U_1U_4_11_out1")
    ,dut_Not_1U_1U_4_12_out1("dut_Not_1U_1U_4_12_out1")
    ,dout_m_req_m_trig_req("dout_m_req_m_trig_req")
    ,din_m_busy_req_0("din_m_busy_req_0")
    ,dut_Add_11Ux8U_11U_4_18_out1("dut_Add_11Ux8U_11U_4_18_out1")
    ,dut_LessThan_5Sx5S_1U_4_17_out1("dut_LessThan_5Sx5S_1U_4_17_out1")
    ,global_state("global_state")
    ,stall0("stall0")
    ,dut_RAM_8X8_1_my_array_1_DIN("dut_RAM_8X8_1_my_array_1_DIN")
    ,dut_RAM_8X8_1_my_array_1_CE("dut_RAM_8X8_1_my_array_1_CE")
    ,dut_RAM_8X8_1_my_array_1_RW("dut_RAM_8X8_1_my_array_1_RW")
    ,dut_RAM_8X8_1_my_array_1_in1("dut_RAM_8X8_1_my_array_1_in1")
    ,dut_RAM_8X8_1_my_array_1_out1("dut_RAM_8X8_1_my_array_1_out1")
{
  dut_RAM_8X8_1_my_array_1 = new dut_RAM_8X8_1("dut_RAM_8X8_1_my_array_1");
  dut_RAM_8X8_1_my_array_1->DIN(dut_RAM_8X8_1_my_array_1_DIN);
  dut_RAM_8X8_1_my_array_1->CE(dut_RAM_8X8_1_my_array_1_CE);
  dut_RAM_8X8_1_my_array_1->RW(dut_RAM_8X8_1_my_array_1_RW);
  dut_RAM_8X8_1_my_array_1->in1(dut_RAM_8X8_1_my_array_1_in1);
  dut_RAM_8X8_1_my_array_1->out1(dut_RAM_8X8_1_my_array_1_out1);
  dut_RAM_8X8_1_my_array_1->clk(clk);

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

  SC_METHOD(drive_s_reg_12);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_dut_RAM_8X8_1_my_array_1_in1);
  sensitive << ( gs_ctrl0 );
  sensitive << ( dut_Add_3Sx2S_3S_4_13_out1 );
  sensitive << ( s_reg_12 );
  sensitive << ( dut_LessThan_4Sx4S_1U_4_15_out1 );

  SC_METHOD(drive_dut_RAM_8X8_1_my_array_1_DIN);
  sensitive << ( gs_ctrl1 );
  sensitive << ( din_data );
  sensitive << ( dout_data );
  sensitive << ( dut_RAM_8X8_1_my_array_1_out1 );

  SC_METHOD(drive_dut_RAM_8X8_1_my_array_1_CE);
  sensitive << ( stall0 );
  sensitive << ( gs_ctrl2 );

  SC_METHOD(drive_dut_RAM_8X8_1_my_array_1_RW);
  sensitive << ( stall0 );
  sensitive << ( gs_ctrl3 );
  sensitive << ( dut_LessThan_4Sx4S_1U_4_15_out1 );

  SC_METHOD(drive_dut_Add_3Sx2S_3S_4_13_in2);
  sensitive << ( gs_ctrl4 );
  sensitive << ( s_reg_12 );

  SC_METHOD(dut_Add_3Sx2S_3S_4_13);
  sensitive << ( dut_Add_3Sx2S_3S_4_13_in2 );

  SC_METHOD(dut_Add_4Sx2S_4S_4_14);
  sensitive << ( s_reg_12 );

  SC_METHOD(dut_LessThan_4Sx4S_1U_4_15);
  sensitive << ( s_reg_12 );

  SC_METHOD(drive_dut_Add_4Sx2S_5S_4_16_in2);
  sensitive << ( gs_ctrl5 );
  sensitive << ( s_reg_12 );

  SC_METHOD(dut_Add_4Sx2S_5S_4_16);
  sensitive << ( dut_Add_4Sx2S_5S_4_16_in2 );

  SC_METHOD(dut_LessThan_5Sx5S_1U_4_17);
  sensitive << ( s_reg_12 );

  SC_METHOD(dut_Add_11Ux8U_11U_4_18);
  sensitive << ( dut_RAM_8X8_1_my_array_1_out1 );
  sensitive << ( dout_data );

  SC_METHOD(drive_global_state);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_global_state_next);
  sensitive << ( global_state );
  sensitive << ( dut_LessThan_4Sx4S_1U_4_15_out1 );
  sensitive << ( dut_LessThan_5Sx5S_1U_4_17_out1 );

  SC_METHOD(drive_gs_ctrl0);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_gs_ctrl1);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_gs_ctrl2);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_gs_ctrl3);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_gs_ctrl4);
  sensitive << clk.pos();
  dont_initialize();

  SC_METHOD(drive_gs_ctrl5);
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
// resource: mux_11bx4i
// resource: regr_11b
void dut::drive_dout_data(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<5>)(global_state.read()) ) {
    case 1ULL: case 11ULL: 
      dout_data = (sc_uint<11> ) (din_data.read());
      break;
    case 14ULL: 
      dout_data = 0ULL;
      break;
    case 15ULL: 
      if ( dut_LessThan_5Sx5S_1U_4_17_out1.read() ) {
        /* state19 */
        dout_data = dut_Add_11Ux8U_11U_4_18_out1.read();
      } else {
        dout_data = (sc_uint<11> ) (dut_Add_11Ux8U_11U_4_18_out1.read().range(10
                    ,3));
      }
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
      switch( (sc_uint<5>)(global_state.read()) ) {
      case 0ULL: case 10ULL: case 17ULL: 
        din_m_busy_req_0 = 0ULL;
        break;
      case 1ULL: case 11ULL: 
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
      switch( (sc_uint<5>)(global_state.read()) ) {
      case 9ULL: 
        dout_m_req_m_trig_req = (sc_uint<1> ) (dut_Not_1U_1U_4_12_out1.read());
        break;
      case 15ULL: 
        if ( dut_LessThan_5Sx5S_1U_4_17_out1.read() );
        else {
          dout_m_req_m_trig_req = (sc_uint<1> ) (dut_Not_1U_1U_4_12_out1.read())
          ;
        }
        break;
      }
    }
  }
}
// resource: mux_1bx3i
void dut::drive_stall0(){
  switch( (sc_uint<5>)(global_state.read()) ) {
  default:
    stall0 = 0ULL;
    break;
  case 1ULL: case 11ULL: 
    stall0 = dut_Not_1U_1U_4_6_out1.read();
    break;
  case 10ULL: case 17ULL: 
    stall0 = dut_And_1Ux1U_1U_4_11_out1.read();
    break;
  }
}
// resource: mux_5bx4i
// resource: regr_5b
void dut::drive_s_reg_12(){
  if ( stall0.read() );
  else {
    switch( (sc_uint<5>)(global_state.read()) ) {
    case 11ULL: 
      s_reg_12 = 0ULL;
      break;
    case 12ULL: 
      s_reg_12 = (sc_uint<5> ) (dut_Add_4Sx2S_4S_4_14_out1.read());
      break;
    case 13ULL: 
      s_reg_12 = (sc_uint<5> ) ((sc_int<4> )s_reg_12.read());
      break;
    case 14ULL: case 16ULL: 
      s_reg_12 = (sc_uint<5> ) (dut_Add_4Sx2S_5S_4_16_out1.read());
      break;
    }
  }
}
// resource: mux_3bx10i
void dut::drive_dut_RAM_8X8_1_my_array_1_in1(){
  switch( (sc_uint<4>)(gs_ctrl0.read()) ) {
  default:
    dut_RAM_8X8_1_my_array_1_in1 = 0ULL;
    break;
  case 1ULL: 
    dut_RAM_8X8_1_my_array_1_in1 = 1ULL;
    break;
  case 2ULL: 
    dut_RAM_8X8_1_my_array_1_in1 = 2ULL;
    break;
  case 3ULL: 
    dut_RAM_8X8_1_my_array_1_in1 = 3ULL;
    break;
  case 4ULL: 
    dut_RAM_8X8_1_my_array_1_in1 = 4ULL;
    break;
  case 5ULL: 
    dut_RAM_8X8_1_my_array_1_in1 = 5ULL;
    break;
  case 6ULL: 
    dut_RAM_8X8_1_my_array_1_in1 = 6ULL;
    break;
  case 7ULL: 
    dut_RAM_8X8_1_my_array_1_in1 = 7ULL;
    break;
  case 8ULL: 
    dut_RAM_8X8_1_my_array_1_in1 = (sc_uint<3> ) (dut_Add_3Sx2S_3S_4_13_out1
                                   .read());
    break;
  case 9ULL: 
    dut_RAM_8X8_1_my_array_1_in1 = (sc_uint<3> )s_reg_12.read();
    break;
  case 10ULL: 
    if ( dut_LessThan_4Sx4S_1U_4_15_out1.read() ) {
      dut_RAM_8X8_1_my_array_1_in1 = (sc_uint<3> ) (dut_Add_3Sx2S_3S_4_13_out1
                                     .read());
    } else {
      /* state16 */
      dut_RAM_8X8_1_my_array_1_in1 = 7ULL;
    }
    break;
  }
}
// resource: mux_8bx3i
void dut::drive_dut_RAM_8X8_1_my_array_1_DIN(){
  switch( (sc_uint<2>)(gs_ctrl1.read()) ) {
  default:
    dut_RAM_8X8_1_my_array_1_DIN = din_data.read();
    break;
  case 1ULL: 
    dut_RAM_8X8_1_my_array_1_DIN = (sc_uint<8> )dout_data.read();
    break;
  case 2ULL: 
    dut_RAM_8X8_1_my_array_1_DIN = dut_RAM_8X8_1_my_array_1_out1.read();
    break;
  }
}
// resource: mux_1bx2i
void dut::drive_dut_RAM_8X8_1_my_array_1_CE(){
  if ( stall0.read() ) {
    dut_RAM_8X8_1_my_array_1_CE = 0ULL;
  } else {
    if ( gs_ctrl2.read() ) {
      dut_RAM_8X8_1_my_array_1_CE = 1ULL;
    } else {
      dut_RAM_8X8_1_my_array_1_CE = 0ULL;
    }
  }
}
// resource: mux_1bx2i
void dut::drive_dut_RAM_8X8_1_my_array_1_RW(){
  if ( stall0.read() ) {
    dut_RAM_8X8_1_my_array_1_RW = 0ULL;
  } else {
    switch( (sc_uint<2>)(gs_ctrl3.read()) ) {
    default:
      dut_RAM_8X8_1_my_array_1_RW = 0ULL;
      break;
    case 1ULL: 
      dut_RAM_8X8_1_my_array_1_RW = 1ULL;
      break;
    case 2ULL: 
      if ( dut_LessThan_4Sx4S_1U_4_15_out1.read() ) {
        dut_RAM_8X8_1_my_array_1_RW = 0ULL;
      } else {
        dut_RAM_8X8_1_my_array_1_RW = 1ULL;
      }
      break;
    }
  }
}
// resource: mux_3bx2i
void dut::drive_dut_Add_3Sx2S_3S_4_13_in2(){
  if ( gs_ctrl4.read() ) {
    dut_Add_3Sx2S_3S_4_13_in2 = (sc_int<3> )s_reg_12.read();
  } else {
    dut_Add_3Sx2S_3S_4_13_in2 = 0LL;
  }
}
// resource: dut_Add_3Sx2S_3S_4  instance: dut_Add_3Sx2S_3S_4_13
void dut::dut_Add_3Sx2S_3S_4_13(){
  dut_Add_3Sx2S_3S_4_13_out1 = (/*cliff*/sc_int<32>)(dut_Add_3Sx2S_3S_4_13_in2
                               .read() + 1LL);
}
// resource: dut_Add_4Sx2S_4S_4  instance: dut_Add_4Sx2S_4S_4_14
void dut::dut_Add_4Sx2S_4S_4_14(){
  dut_Add_4Sx2S_4S_4_14_out1 = (/*cliff*/sc_int<32>)((sc_int<4> )s_reg_12.read()
                                + 1LL);
}
// resource: dut_LessThan_4Sx4S_1U_4  instance: dut_LessThan_4Sx4S_1U_4_15
void dut::dut_LessThan_4Sx4S_1U_4_15(){
  dut_LessThan_4Sx4S_1U_4_15_out1 = (/*imp*/sc_uint<1>)((sc_int<4> )s_reg_12
                                    .read() < (sc_int<4> )7LL);
}
// resource: mux_4bx2i
void dut::drive_dut_Add_4Sx2S_5S_4_16_in2(){
  if ( gs_ctrl5.read() ) {
    dut_Add_4Sx2S_5S_4_16_in2 = (sc_int<4> )s_reg_12.read();
  } else {
    dut_Add_4Sx2S_5S_4_16_in2 = 0LL;
  }
}
// resource: dut_Add_4Sx2S_5S_4  instance: dut_Add_4Sx2S_5S_4_16
void dut::dut_Add_4Sx2S_5S_4_16(){
  dut_Add_4Sx2S_5S_4_16_out1 = (/*cliff*/sc_int<32>)(dut_Add_4Sx2S_5S_4_16_in2
                               .read() + 1LL);
}
// resource: dut_LessThan_5Sx5S_1U_4  instance: dut_LessThan_5Sx5S_1U_4_17
void dut::dut_LessThan_5Sx5S_1U_4_17(){
  dut_LessThan_5Sx5S_1U_4_17_out1 = (/*imp*/sc_uint<1>)((sc_int<5> )s_reg_12
                                    .read() < (sc_int<5> )8LL);
}
// resource: dut_Add_11Ux8U_11U_4  instance: dut_Add_11Ux8U_11U_4_18
void dut::dut_Add_11Ux8U_11U_4_18(){
  dut_Add_11Ux8U_11U_4_18_out1 = (dout_data.read() + 
                                 dut_RAM_8X8_1_my_array_1_out1.read());
}
// resource: regr_5b
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
// resource: mux_5bx5i
void dut::drive_global_state_next(){
  switch( (sc_uint<5>)(global_state.read()) ) {
  default:
    global_state_next = (global_state.read() + 1ULL);
    break;
  case 10ULL: case 17ULL: 
    global_state_next = 11ULL;
    break;
  case 13ULL: 
    if ( dut_LessThan_4Sx4S_1U_4_15_out1.read() ) {
      global_state_next = 12ULL;
    } else {
      global_state_next = (global_state.read() + 1ULL);
    }
    break;
  case 14ULL: case 16ULL: 
    global_state_next = 15ULL;
    break;
  case 15ULL: 
    if ( dut_LessThan_5Sx5S_1U_4_17_out1.read() ) {
      global_state_next = (global_state.read() + 1ULL);
    } else {
      global_state_next = 17ULL;
    }
    break;
  }
}
// resource: mux_4bx11i
// resource: regr_4b
void dut::drive_gs_ctrl0(){
  if ( (rst.read() == 0ULL) ) {
    gs_ctrl0 = 0ULL;
  } else {
    if ( stall0.read() );
    else {
      switch( (sc_uint<5>)(global_state_next.read()) ) {
      default:
        gs_ctrl0 = 0ULL;
        break;
      case 2ULL: 
        gs_ctrl0 = 1ULL;
        break;
      case 3ULL: 
        gs_ctrl0 = 2ULL;
        break;
      case 4ULL: 
        gs_ctrl0 = 3ULL;
        break;
      case 5ULL: 
        gs_ctrl0 = 4ULL;
        break;
      case 6ULL: 
        gs_ctrl0 = 5ULL;
        break;
      case 7ULL: 
        gs_ctrl0 = 6ULL;
        break;
      case 8ULL: 
        gs_ctrl0 = 7ULL;
        break;
      case 11ULL: 
        gs_ctrl0 = 8ULL;
        break;
      case 12ULL: case 16ULL: 
        gs_ctrl0 = 9ULL;
        break;
      case 13ULL: 
        gs_ctrl0 = 10ULL;
        break;
      }
    }
  }
}
// resource: mux_2bx3i
// resource: regr_2b
void dut::drive_gs_ctrl1(){
  if ( (rst.read() == 0ULL) ) {
    gs_ctrl1 = 0ULL;
  } else {
    if ( stall0.read() );
    else {
      switch( (sc_uint<5>)(global_state_next.read()) ) {
      default:
        gs_ctrl1 = 0ULL;
        break;
      case 2ULL: case 3ULL: case 4ULL: case 5ULL: case 6ULL: case 7ULL: case 
      8ULL: case 13ULL: 
        gs_ctrl1 = 1ULL;
        break;
      case 12ULL: 
        gs_ctrl1 = 2ULL;
        break;
      }
    }
  }
}
// resource: mux_1bx2i
// resource: regr_1b
void dut::drive_gs_ctrl2(){
  if ( (rst.read() == 0ULL) ) {
    gs_ctrl2 = 0ULL;
  } else {
    if ( stall0.read() );
    else {
      switch( (sc_uint<5>)(global_state_next.read()) ) {
      default:
        gs_ctrl2 = 0ULL;
        break;
      case 1ULL: case 2ULL: case 3ULL: case 4ULL: case 5ULL: case 6ULL: case 
      7ULL: case 8ULL: case 11ULL: case 12ULL: case 13ULL: case 14ULL: case 
      16ULL: 
        gs_ctrl2 = 1ULL;
        break;
      }
    }
  }
}
// resource: mux_2bx3i
// resource: regr_2b
void dut::drive_gs_ctrl3(){
  if ( (rst.read() == 0ULL) ) {
    gs_ctrl3 = 0ULL;
  } else {
    if ( stall0.read() );
    else {
      switch( (sc_uint<5>)(global_state_next.read()) ) {
      default:
        gs_ctrl3 = 0ULL;
        break;
      case 1ULL: case 2ULL: case 3ULL: case 4ULL: case 5ULL: case 6ULL: case 
      7ULL: case 8ULL: case 12ULL: 
        gs_ctrl3 = 1ULL;
        break;
      case 13ULL: 
        gs_ctrl3 = 2ULL;
        break;
      }
    }
  }
}
// resource: mux_1bx2i
// resource: regr_1b
void dut::drive_gs_ctrl4(){
  if ( (rst.read() == 0ULL) ) {
    gs_ctrl4 = 0ULL;
  } else {
    if ( stall0.read() );
    else {
      switch( (sc_uint<5>)(global_state_next.read()) ) {
      default:
        gs_ctrl4 = 0ULL;
        break;
      case 13ULL: 
        gs_ctrl4 = 1ULL;
        break;
      }
    }
  }
}
// resource: mux_1bx2i
// resource: regr_1b
void dut::drive_gs_ctrl5(){
  if ( (rst.read() == 0ULL) ) {
    gs_ctrl5 = 0ULL;
  } else {
    if ( stall0.read() );
    else {
      switch( (sc_uint<5>)(global_state_next.read()) ) {
      default:
        gs_ctrl5 = 0ULL;
        break;
      case 16ULL: 
        gs_ctrl5 = 1ULL;
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