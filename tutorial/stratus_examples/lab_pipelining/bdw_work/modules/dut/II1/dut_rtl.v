// Generated by stratus_hls 17.20-p100  (88533.190925)
// Thu Nov 19 00:05:12 2020
// from dut.cc

`timescale 1ps / 1ps

      
module dut(clk, rst, din_busy, din_vld, din_data_a, din_data_b, din_data_c, din_data_d, din_data_e, din_data_f, din_data_g, din_data_h, dout_busy, dout_vld, dout_data);

      input clk;
      input rst;
      input din_vld;
      input [7:0] din_data_a;
      input [7:0] din_data_b;
      input [7:0] din_data_c;
      input [7:0] din_data_d;
      input [7:0] din_data_e;
      input [7:0] din_data_f;
      input [7:0] din_data_g;
      input [7:0] din_data_h;
      input dout_busy;
      output din_busy;
      output dout_vld;
      output [31:0] dout_data;
      reg [31:0] dout_data;
      reg dout_m_req_m_prev_trig_req;
      reg dout_m_unacked_req;
      wire dut_Xor_1Ux1U_1U_4_14_out1;
      wire dut_Or_1Ux1U_1U_4_15_out1;
      wire dut_And_1Ux1U_1U_4_12_out1;
      wire dut_And_1Ux1U_1U_4_10_out1;
      wire dut_Not_1U_1U_4_9_out1;
      wire dut_And_1Ux1U_1U_4_11_out1;
      reg dut_N_Muxb_1_2_1_4_1_out1;
      wire dut_Or_1Ux1U_1U_4_6_out1;
      wire dut_And_1Ux1U_1U_4_5_out1;
      wire dut_Not_1U_1U_4_4_out1;
      wire dut_And_1Ux1U_1U_4_3_out1;
      reg din_m_unvalidated_req;
      wire dut_Or_1Ux1U_1U_4_2_out1;
      wire dut_Or_1Ux1U_1U_4_7_out1;
      reg cycle4_state;
      reg cycle3_state;
      reg cycle2_state;
      wire dut_And_1Ux1U_1U_4_16_out1;
      reg cycle6_state;
      reg vld_5;
      reg rdy_5;
      reg vld_4;
      reg rdy_4;
      wire en_3;
      reg vld_3;
      reg rdy_3;
      wire dut_Not_1U_1U_4_8_out1;
      reg vld_2;
      reg rdy_2;
      reg vld_1;
      reg rdy_1;
      reg iostall_1;
      reg vld_0;
      wire rdy_0;
      reg en_4;
      reg en_2;
      wire[63:0] dut_Mul_33Ux32U_64U_4_45_out1;
      wire[31:0] dut_Add_32Ux32U_32U_4_44_out1;
      wire[31:0] dut_Mul_32Ux9U_32U_4_43_out1;
      wire[32:0] dut_Add_32Ux16U_33U_4_42_out1;
      wire[8:0] dut_Add_8Ux8U_9U_4_38_out1;
      wire[31:0] dut_Mul_32Ux9U_32U_4_36_out1;
      wire[16:0] dut_Add_16Ux16U_17U_4_35_out1;
      wire[15:0] dut_Mul_8Ux8U_16U_4_34_out1;
      wire[15:0] dut_Mul_8Ux8U_16U_4_33_out1;
      wire[28:0] dut_Mul_20Ux9U_29U_4_32_out1;
      wire[19:0] dut_Mul_10Ux10U_20U_4_31_out1;
      wire[8:0] dut_Add_8Ux8U_9U_4_30_out1;
      wire[9:0] dut_Add_9Ux8U_10U_4_29_out1;
      wire[9:0] dut_Add_9Ux8U_10U_4_28_out1;
      reg[7:0] dut_N_Mux_8_2_0_4_27_out1;
      reg[7:0] din_m_stall_reg_h;
      reg[7:0] dut_N_Mux_8_2_0_4_26_out1;
      reg[7:0] din_m_stall_reg_g;
      wire[8:0] dut_Add_8Ux8U_9U_4_24_out1;
      reg[7:0] dut_N_Mux_8_2_0_4_23_out1;
      reg[7:0] din_m_stall_reg_f;
      reg[7:0] dut_N_Mux_8_2_0_4_22_out1;
      reg[7:0] din_m_stall_reg_c;
      reg[7:0] dut_N_Mux_8_2_0_4_21_out1;
      reg[7:0] din_m_stall_reg_e;
      reg[7:0] dut_N_Mux_8_2_0_4_20_out1;
      reg[7:0] din_m_stall_reg_d;
      reg[7:0] dut_N_Mux_8_2_0_4_19_out1;
      reg[7:0] din_m_stall_reg_b;
      reg[7:0] dut_N_Mux_8_2_0_4_18_out1;
      reg[7:0] din_m_stall_reg_a;
      reg din_m_stall_reg_full;
      wire[32:0] dut_Add_32Ux17U_33U_4_37_out1;
      reg[31:0] s_reg_9;
      wire[15:0] dut_Mul_8Ux8U_16U_4_41_out1;
      reg[15:0] s_reg_12;
      wire[31:0] dut_Mul_32Ux9U_32U_4_40_out1;
      reg[31:0] s_reg_11_slice;
      wire[8:0] dut_Add_8Ux8U_9U_4_39_out1;
      reg[8:0] s_reg_10;
      wire dut_Not_1U_1U_4_17_out1;
      reg cycle5_state;
      reg dout_m_req_m_trig_req;
      reg din_m_stalling;
      reg en_0;
      reg cycle1_state;
      reg en_1;
      reg global_state;
      reg din_m_busy_req_0;
      reg[31:0] s_reg_9_stage4;
      reg en_5;
      reg[63:0] s_reg_11_stage2;
      wire[1:0] dut_Div_64Ux2U_32U_4_46_in1;
      wire[31:0] dut_Div_64Ux2U_32U_4_46_out1;
      wire stall0;

         // thread: drive_stall0
         assign stall0 = 1'b0;

         dut_Div_64Ux2U_32U_4 dut_Div_64Ux2U_32U_4_46(
                                .in2( s_reg_11_stage2 ),
                                .in1( dut_Div_64Ux2U_32U_4_46_in1 ),
                                .out1( dut_Div_64Ux2U_32U_4_46_out1 ),
                                .clk( clk ),
                                .stall( stall0 )
                              );

         // resource: regr_32
         always @(posedge clk)
          begin :drive_dout_data
            if (en_5) begin
               dout_data <= s_reg_9_stage4;
            end
         end

         // resource: mux_1bx2i
         // resource: regr_1
         always @(posedge clk)
          begin :drive_din_m_busy_req_0
            if (rst == 1'b0) begin
               din_m_busy_req_0 <= 1'd1;
            end
            else begin
               if (global_state) begin
                  if (en_1) begin
                     if (cycle1_state) begin
                        if (en_0) begin
                           din_m_busy_req_0 <= 1'd0;
                        end
                     end
                     else begin
                        if (en_0) begin
                           din_m_busy_req_0 <= 1'd0;
                        end
                        else begin
                           din_m_busy_req_0 <= 1'd1;
                        end
                     end
                  end
                  else begin
                     if (en_0) begin
                        din_m_busy_req_0 <= 1'd0;
                     end
                  end
               end
            end
         end

         // resource: mux_1bx2i
         always @(en_0 or global_state)
          begin :drive_din_m_stalling
            if (global_state) begin
               if (en_0) begin
                  din_m_stalling = 1'd0;
               end
               else begin
                  din_m_stalling = 1'd1;
               end
            end
            else begin
               din_m_stalling = 1'd0;
            end
         end

         // resource: regr_1
         always @(posedge clk)
          begin :drive_dout_m_req_m_trig_req
            if (rst == 1'b0) begin
               dout_m_req_m_trig_req <= 1'd0;
            end
            else begin
               if (global_state) begin
                  if (en_5) begin
                     if (cycle5_state) begin
                     end
                     else begin
                        dout_m_req_m_trig_req <= dut_Not_1U_1U_4_17_out1;
                     end
                  end
               end
            end
         end

         // resource: regr_9
         always @(posedge clk)
          begin :drive_s_reg_10
            if (en_1) begin
               s_reg_10 <= dut_Add_8Ux8U_9U_4_39_out1;
            end
         end

         // resource: regr_32
         always @(posedge clk)
          begin :drive_s_reg_11
            if (en_1) begin
               s_reg_11_slice <= dut_Mul_32Ux9U_32U_4_40_out1;
            end
         end

         // resource: regr_16
         always @(posedge clk)
          begin :drive_s_reg_12
            if (en_1) begin
               s_reg_12 <= dut_Mul_8Ux8U_16U_4_41_out1;
            end
         end

         // resource: regr_32
         always @(posedge clk)
          begin :drive_s_reg_9
            if (en_1) begin
               s_reg_9 <= dut_Add_32Ux17U_33U_4_37_out1[31:0];
            end
         end

         // resource:dut_N_Mux_8_2_0_4
         always @(din_data_a or din_m_stall_reg_a or din_m_stall_reg_full)
          begin :dut_N_Mux_8_2_0_4_18
            if (din_m_stall_reg_full) begin
               dut_N_Mux_8_2_0_4_18_out1 = din_m_stall_reg_a;
            end
            else begin
               dut_N_Mux_8_2_0_4_18_out1 = din_data_a;
            end
         end

         // resource:dut_N_Mux_8_2_0_4
         always @(din_data_b or din_m_stall_reg_b or din_m_stall_reg_full)
          begin :dut_N_Mux_8_2_0_4_19
            if (din_m_stall_reg_full) begin
               dut_N_Mux_8_2_0_4_19_out1 = din_m_stall_reg_b;
            end
            else begin
               dut_N_Mux_8_2_0_4_19_out1 = din_data_b;
            end
         end

         // resource:dut_N_Mux_8_2_0_4
         always @(din_data_d or din_m_stall_reg_d or din_m_stall_reg_full)
          begin :dut_N_Mux_8_2_0_4_20
            if (din_m_stall_reg_full) begin
               dut_N_Mux_8_2_0_4_20_out1 = din_m_stall_reg_d;
            end
            else begin
               dut_N_Mux_8_2_0_4_20_out1 = din_data_d;
            end
         end

         // resource:dut_N_Mux_8_2_0_4
         always @(din_data_e or din_m_stall_reg_e or din_m_stall_reg_full)
          begin :dut_N_Mux_8_2_0_4_21
            if (din_m_stall_reg_full) begin
               dut_N_Mux_8_2_0_4_21_out1 = din_m_stall_reg_e;
            end
            else begin
               dut_N_Mux_8_2_0_4_21_out1 = din_data_e;
            end
         end

         // resource:dut_N_Mux_8_2_0_4
         always @(din_data_c or din_m_stall_reg_c or din_m_stall_reg_full)
          begin :dut_N_Mux_8_2_0_4_22
            if (din_m_stall_reg_full) begin
               dut_N_Mux_8_2_0_4_22_out1 = din_m_stall_reg_c;
            end
            else begin
               dut_N_Mux_8_2_0_4_22_out1 = din_data_c;
            end
         end

         // resource:dut_N_Mux_8_2_0_4
         always @(din_data_f or din_m_stall_reg_f or din_m_stall_reg_full)
          begin :dut_N_Mux_8_2_0_4_23
            if (din_m_stall_reg_full) begin
               dut_N_Mux_8_2_0_4_23_out1 = din_m_stall_reg_f;
            end
            else begin
               dut_N_Mux_8_2_0_4_23_out1 = din_data_f;
            end
         end

         // resource: dut_Add_8Ux8U_9U_4  instance: dut_Add_8Ux8U_9U_4_24
         assign dut_Add_8Ux8U_9U_4_24_out1 = {1'b0, dut_N_Mux_8_2_0_4_20_out1} + {1'b0, dut_N_Mux_8_2_0_4_21_out1};

         // resource: dut_Add_8Ux8U_9U_4  instance: dut_Add_8Ux8U_9U_4_39
         assign dut_Add_8Ux8U_9U_4_39_out1 = {1'b0, dut_N_Mux_8_2_0_4_18_out1} + {1'b0, dut_N_Mux_8_2_0_4_19_out1};

         // resource:dut_N_Mux_8_2_0_4
         always @(din_data_g or din_m_stall_reg_g or din_m_stall_reg_full)
          begin :dut_N_Mux_8_2_0_4_26
            if (din_m_stall_reg_full) begin
               dut_N_Mux_8_2_0_4_26_out1 = din_m_stall_reg_g;
            end
            else begin
               dut_N_Mux_8_2_0_4_26_out1 = din_data_g;
            end
         end

         // resource:dut_N_Mux_8_2_0_4
         always @(din_data_h or din_m_stall_reg_h or din_m_stall_reg_full)
          begin :dut_N_Mux_8_2_0_4_27
            if (din_m_stall_reg_full) begin
               dut_N_Mux_8_2_0_4_27_out1 = din_m_stall_reg_h;
            end
            else begin
               dut_N_Mux_8_2_0_4_27_out1 = din_data_h;
            end
         end

         // resource: dut_Add_9Ux8U_10U_4  instance: dut_Add_9Ux8U_10U_4_28
         assign dut_Add_9Ux8U_10U_4_28_out1 = {1'b0, dut_Add_8Ux8U_9U_4_24_out1} + {2'b00, dut_N_Mux_8_2_0_4_23_out1};

         // resource: dut_Add_9Ux8U_10U_4  instance: dut_Add_9Ux8U_10U_4_29
         assign dut_Add_9Ux8U_10U_4_29_out1 = {1'b0, dut_Add_8Ux8U_9U_4_39_out1} + {2'b00, dut_N_Mux_8_2_0_4_22_out1};

         // resource: dut_Add_8Ux8U_9U_4  instance: dut_Add_8Ux8U_9U_4_30
         assign dut_Add_8Ux8U_9U_4_30_out1 = {1'b0, dut_N_Mux_8_2_0_4_26_out1} + {1'b0, dut_N_Mux_8_2_0_4_27_out1};

         // resource: dut_Mul_10Ux10U_20U_4  instance: dut_Mul_10Ux10U_20U_4_31
         assign dut_Mul_10Ux10U_20U_4_31_out1 = {10'b0000000000, dut_Add_9Ux8U_10U_4_29_out1}*{10'b0000000000, dut_Add_9Ux8U_10U_4_28_out1};

         // resource: dut_Mul_20Ux9U_29U_4  instance: dut_Mul_20Ux9U_29U_4_32
         assign dut_Mul_20Ux9U_29U_4_32_out1 = {9'b000000000, dut_Mul_10Ux10U_20U_4_31_out1}*{20'b00000000000000000000, dut_Add_8Ux8U_9U_4_30_out1};

         // resource: dut_Mul_8Ux8U_16U_4  instance: dut_Mul_8Ux8U_16U_4_33
         assign dut_Mul_8Ux8U_16U_4_33_out1 = {8'b00000000, dut_N_Mux_8_2_0_4_22_out1}*{8'b00000000, dut_N_Mux_8_2_0_4_20_out1};

         // resource: dut_Mul_8Ux8U_16U_4  instance: dut_Mul_8Ux8U_16U_4_34
         assign dut_Mul_8Ux8U_16U_4_34_out1 = {8'b00000000, dut_N_Mux_8_2_0_4_18_out1}*{8'b00000000, dut_N_Mux_8_2_0_4_19_out1};

         // resource: dut_Add_16Ux16U_17U_4  instance: dut_Add_16Ux16U_17U_4_35
         assign dut_Add_16Ux16U_17U_4_35_out1 = {1'b0, dut_Mul_8Ux8U_16U_4_34_out1} + {1'b0, dut_Mul_8Ux8U_16U_4_33_out1};

         // resource: dut_Mul_32Ux9U_32U_4  instance: dut_Mul_32Ux9U_32U_4_36
         assign dut_Mul_32Ux9U_32U_4_36_out1 = {3'b000, dut_Mul_20Ux9U_29U_4_32_out1}*{{23'b00000000000000000000000, 1'b0}, dut_N_Mux_8_2_0_4_21_out1};

         // resource: dut_Add_32Ux17U_33U_4  instance: dut_Add_32Ux17U_33U_4_37
         assign dut_Add_32Ux17U_33U_4_37_out1 = {1'b0, dut_Mul_32Ux9U_32U_4_36_out1} + {16'b0000000000000000, dut_Add_16Ux16U_17U_4_35_out1};

         // resource: dut_Add_8Ux8U_9U_4  instance: dut_Add_8Ux8U_9U_4_38
         assign dut_Add_8Ux8U_9U_4_38_out1 = {1'b0, dut_N_Mux_8_2_0_4_20_out1} + {1'b0, dut_N_Mux_8_2_0_4_22_out1};

         // resource: dut_Mul_32Ux9U_32U_4  instance: dut_Mul_32Ux9U_32U_4_40
         assign dut_Mul_32Ux9U_32U_4_40_out1 = {3'b000, dut_Mul_20Ux9U_29U_4_32_out1}*{23'b00000000000000000000000, dut_Add_8Ux8U_9U_4_38_out1};

         // resource: dut_Mul_8Ux8U_16U_4  instance: dut_Mul_8Ux8U_16U_4_41
         assign dut_Mul_8Ux8U_16U_4_41_out1 = {8'b00000000, dut_N_Mux_8_2_0_4_26_out1}*{8'b00000000, dut_N_Mux_8_2_0_4_27_out1};

         // resource: dut_Add_32Ux16U_33U_4  instance: dut_Add_32Ux16U_33U_4_42
         assign dut_Add_32Ux16U_33U_4_42_out1 = {1'b0, s_reg_9} + {17'b00000000000000000, s_reg_12};

         // resource: dut_Mul_32Ux9U_32U_4  instance: dut_Mul_32Ux9U_32U_4_43
         assign dut_Mul_32Ux9U_32U_4_43_out1 = s_reg_9*{23'b00000000000000000000000, s_reg_10};

         // resource: dut_Add_32Ux32U_32U_4  instance: dut_Add_32Ux32U_32U_4_44
         assign dut_Add_32Ux32U_32U_4_44_out1 = dut_Mul_32Ux9U_32U_4_43_out1 + s_reg_11_slice;

         // resource: dut_Mul_33Ux32U_64U_4  instance: dut_Mul_33Ux32U_64U_4_45
         assign dut_Mul_33Ux32U_64U_4_45_out1 = {31'b0000000000000000000000000000000, dut_Add_32Ux16U_33U_4_42_out1}*{32'b00000000000000000000000000000000, dut_Add_32Ux32U_32U_4_44_out1};

         // thread: drive_dut_Div_64Ux2U_32U_4_46_in1
         assign dut_Div_64Ux2U_32U_4_46_in1 = 2'd3;

         // resource: regr_64
         always @(posedge clk)
          begin :drive_s_reg_11_stage2
            if (en_2) begin
               s_reg_11_stage2 <= dut_Mul_33Ux32U_64U_4_45_out1;
            end
         end

         // resource: regr_32
         always @(posedge clk)
          begin :drive_s_reg_9_stage4
            if (en_4) begin
               s_reg_9_stage4 <= dut_Div_64Ux2U_32U_4_46_out1;
            end
         end

         // resource: mux_1bx2i
         always @(vld_0 or rdy_0 or global_state)
          begin :drive_en_0
            if (global_state) begin
               en_0 = !vld_0 | rdy_0;
            end
            else begin
               en_0 = 1'b0;
            end
         end

         // resource: regr_1
         always @(posedge clk)
          begin :drive_vld_0
            vld_0 <= global_state;
         end

         // thread: drive_rdy_0
         assign rdy_0 = (!vld_1 | rdy_1) & !iostall_1;

         // resource: mux_1bx2i
         always @(vld_0 or vld_1 or rdy_1 or iostall_1 or global_state)
          begin :drive_en_1
            if (global_state) begin
               en_1 = (!vld_1 | rdy_1) & (!iostall_1 & vld_0);
            end
            else begin
               en_1 = 1'b0;
            end
         end

         // resource: mux_1bx2i
         // resource: regr_1
         always @(posedge clk)
          begin :drive_vld_1
            if (global_state) begin
               vld_1 <= !iostall_1 & vld_0 | vld_1 & !rdy_1;
            end
            else begin
               vld_1 <= 1'b0;
            end
         end

         // resource: mux_1bx2i
         always @(vld_2 or rdy_2 or global_state)
          begin :drive_rdy_1
            if (global_state) begin
               rdy_1 = !vld_2 | rdy_2;
            end
            else begin
               rdy_1 = 1'b0;
            end
         end

         // resource: mux_1bx2i
         always @(dut_Not_1U_1U_4_8_out1 or cycle1_state or global_state)
          begin :drive_iostall_1
            if (global_state) begin
               if (cycle1_state) begin
                  iostall_1 = 1'b0;
               end
               else begin
                  iostall_1 = dut_Not_1U_1U_4_8_out1;
               end
            end
            else begin
               iostall_1 = 1'b0;
            end
         end

         // resource: mux_1bx2i
         always @(vld_1 or vld_2 or rdy_2 or global_state)
          begin :drive_en_2
            if (global_state) begin
               en_2 = (!vld_2 | rdy_2) & vld_1;
            end
            else begin
               en_2 = 1'b0;
            end
         end

         // resource: mux_1bx2i
         // resource: regr_1
         always @(posedge clk)
          begin :drive_vld_2
            if (global_state) begin
               vld_2 <= vld_1 | vld_2 & !rdy_2;
            end
            else begin
               vld_2 <= 1'b0;
            end
         end

         // resource: mux_1bx2i
         always @(vld_3 or rdy_3 or global_state)
          begin :drive_rdy_2
            if (global_state) begin
               rdy_2 = !vld_3 | rdy_3;
            end
            else begin
               rdy_2 = 1'b0;
            end
         end

         // thread: drive_en_3
         assign en_3 = (!vld_3 | rdy_3) & vld_2;

         // resource: mux_1bx2i
         // resource: regr_1
         always @(posedge clk)
          begin :drive_vld_3
            if (global_state) begin
               vld_3 <= vld_2 | vld_3 & !rdy_3;
            end
            else begin
               vld_3 <= 1'b0;
            end
         end

         // resource: mux_1bx2i
         always @(vld_4 or rdy_4 or global_state)
          begin :drive_rdy_3
            if (global_state) begin
               rdy_3 = !vld_4 | rdy_4;
            end
            else begin
               rdy_3 = 1'b0;
            end
         end

         // resource: mux_1bx2i
         always @(vld_3 or vld_4 or rdy_4 or global_state)
          begin :drive_en_4
            if (global_state) begin
               en_4 = (!vld_4 | rdy_4) & vld_3;
            end
            else begin
               en_4 = 1'b0;
            end
         end

         // resource: mux_1bx2i
         // resource: regr_1
         always @(posedge clk)
          begin :drive_vld_4
            if (global_state) begin
               vld_4 <= vld_3 | vld_4 & !rdy_4;
            end
            else begin
               vld_4 <= 1'b0;
            end
         end

         // resource: mux_1bx2i
         always @(vld_5 or rdy_5 or global_state)
          begin :drive_rdy_4
            if (global_state) begin
               rdy_4 = !vld_5 | rdy_5;
            end
            else begin
               rdy_4 = 1'b0;
            end
         end

         // resource: mux_1bx2i
         always @(vld_4 or vld_5 or rdy_5 or global_state)
          begin :drive_en_5
            if (global_state) begin
               en_5 = (!vld_5 | rdy_5) & vld_4;
            end
            else begin
               en_5 = 1'b0;
            end
         end

         // resource: mux_1bx2i
         // resource: regr_1
         always @(posedge clk)
          begin :drive_vld_5
            if (global_state) begin
               vld_5 <= vld_4 | vld_5 & !rdy_5;
            end
            else begin
               vld_5 <= 1'b0;
            end
         end

         // resource: mux_1bx3i
         always @(dut_And_1Ux1U_1U_4_16_out1 or cycle6_state or global_state)
          begin :drive_rdy_5
            if (global_state) begin
               if (cycle6_state) begin
                  rdy_5 = 1'b1;
               end
               else begin
                  rdy_5 = !dut_And_1Ux1U_1U_4_16_out1;
               end
            end
            else begin
               rdy_5 = 1'b0;
            end
         end

         // resource: mux_1bx2i
         // resource: regr_1
         always @(posedge clk)
          begin :drive_cycle1_state
            if (global_state) begin
               if (en_0) begin
                  cycle1_state <= 1'b0;
               end
            end
            else begin
               cycle1_state <= 1'b1;
            end
         end

         // resource: mux_1bx2i
         // resource: regr_1
         always @(posedge clk)
          begin :drive_cycle2_state
            if (global_state) begin
               if (en_1) begin
                  cycle2_state <= cycle1_state;
               end
            end
            else begin
               cycle2_state <= 1'b1;
            end
         end

         // resource: mux_1bx2i
         // resource: regr_1
         always @(posedge clk)
          begin :drive_cycle3_state
            if (global_state) begin
               if (en_2) begin
                  cycle3_state <= cycle2_state;
               end
            end
            else begin
               cycle3_state <= 1'b1;
            end
         end

         // resource: mux_1bx2i
         // resource: regr_1
         always @(posedge clk)
          begin :drive_cycle4_state
            if (global_state) begin
               if (en_3) begin
                  cycle4_state <= cycle3_state;
               end
            end
            else begin
               cycle4_state <= 1'b1;
            end
         end

         // resource: mux_1bx2i
         // resource: regr_1
         always @(posedge clk)
          begin :drive_cycle5_state
            if (global_state) begin
               if (en_4) begin
                  cycle5_state <= cycle4_state;
               end
            end
            else begin
               cycle5_state <= 1'b1;
            end
         end

         // resource: mux_1bx2i
         // resource: regr_1
         always @(posedge clk)
          begin :drive_cycle6_state
            if (global_state) begin
               if (en_5) begin
                  cycle6_state <= cycle5_state;
               end
            end
            else begin
               cycle6_state <= 1'b1;
            end
         end

         // resource: regr_1
         always @(posedge clk)
          begin :drive_global_state
            if (rst == 1'b0) begin
               global_state <= 1'b0;
            end
            else begin
               global_state <= 1'b1;
            end
         end

         // thread: drive_din_busy
         assign din_busy = dut_Or_1Ux1U_1U_4_7_out1;

         // resource: dut_Or_1Ux1U_1U_4  instance: dut_Or_1Ux1U_1U_4_2
         assign dut_Or_1Ux1U_1U_4_2_out1 = din_m_unvalidated_req | din_vld;

         // resource: dut_And_1Ux1U_1U_4  instance: dut_And_1Ux1U_1U_4_3
         assign dut_And_1Ux1U_1U_4_3_out1 = dut_Or_1Ux1U_1U_4_2_out1 & din_m_busy_req_0;

         // resource: dut_Not_1U_1U_4  instance: dut_Not_1U_1U_4_4
         assign dut_Not_1U_1U_4_4_out1 = !dut_And_1Ux1U_1U_4_3_out1;

         // resource: dut_And_1Ux1U_1U_4  instance: dut_And_1Ux1U_1U_4_5
         assign dut_And_1Ux1U_1U_4_5_out1 = dut_Not_1U_1U_4_4_out1 & din_vld;

         // resource: dut_Or_1Ux1U_1U_4  instance: dut_Or_1Ux1U_1U_4_6
         assign dut_Or_1Ux1U_1U_4_6_out1 = dut_And_1Ux1U_1U_4_5_out1 | din_m_stall_reg_full;

         // resource: dut_Or_1Ux1U_1U_4  instance: dut_Or_1Ux1U_1U_4_7
         assign dut_Or_1Ux1U_1U_4_7_out1 = dut_And_1Ux1U_1U_4_3_out1 | din_m_stall_reg_full;

         // resource: dut_Not_1U_1U_4  instance: dut_Not_1U_1U_4_8
         assign dut_Not_1U_1U_4_8_out1 = !dut_Or_1Ux1U_1U_4_6_out1;

         // resource: regr_1
         always @(posedge clk)
          begin :drive_din_m_unvalidated_req
            if (rst == 1'b0) begin
               din_m_unvalidated_req <= 1'd1;
            end
            else begin
               din_m_unvalidated_req <= dut_N_Muxb_1_2_1_4_1_out1;
            end
         end

         // resource:dut_N_Muxb_1_2_1_4
         always @(din_vld or din_m_busy_req_0 or din_m_unvalidated_req)
          begin :dut_N_Muxb_1_2_1_4_1
            if (din_m_busy_req_0) begin
               dut_N_Muxb_1_2_1_4_1_out1 = din_m_unvalidated_req;
            end
            else begin
               dut_N_Muxb_1_2_1_4_1_out1 = din_vld;
            end
         end

         // resource: regr_8
         always @(posedge clk)
          begin :drive_din_m_stall_reg_h
            if (dut_And_1Ux1U_1U_4_11_out1) begin
               din_m_stall_reg_h <= din_data_h;
            end
         end

         // resource: regr_8
         always @(posedge clk)
          begin :drive_din_m_stall_reg_g
            if (dut_And_1Ux1U_1U_4_11_out1) begin
               din_m_stall_reg_g <= din_data_g;
            end
         end

         // resource: regr_8
         always @(posedge clk)
          begin :drive_din_m_stall_reg_f
            if (dut_And_1Ux1U_1U_4_11_out1) begin
               din_m_stall_reg_f <= din_data_f;
            end
         end

         // resource: regr_8
         always @(posedge clk)
          begin :drive_din_m_stall_reg_e
            if (dut_And_1Ux1U_1U_4_11_out1) begin
               din_m_stall_reg_e <= din_data_e;
            end
         end

         // resource: regr_8
         always @(posedge clk)
          begin :drive_din_m_stall_reg_d
            if (dut_And_1Ux1U_1U_4_11_out1) begin
               din_m_stall_reg_d <= din_data_d;
            end
         end

         // resource: regr_8
         always @(posedge clk)
          begin :drive_din_m_stall_reg_c
            if (dut_And_1Ux1U_1U_4_11_out1) begin
               din_m_stall_reg_c <= din_data_c;
            end
         end

         // resource: regr_8
         always @(posedge clk)
          begin :drive_din_m_stall_reg_b
            if (dut_And_1Ux1U_1U_4_11_out1) begin
               din_m_stall_reg_b <= din_data_b;
            end
         end

         // resource: regr_8
         always @(posedge clk)
          begin :drive_din_m_stall_reg_a
            if (dut_And_1Ux1U_1U_4_11_out1) begin
               din_m_stall_reg_a <= din_data_a;
            end
         end

         // resource: dut_Not_1U_1U_4  instance: dut_Not_1U_1U_4_9
         assign dut_Not_1U_1U_4_9_out1 = !din_m_stall_reg_full;

         // resource: dut_And_1Ux1U_1U_4  instance: dut_And_1Ux1U_1U_4_10
         assign dut_And_1Ux1U_1U_4_10_out1 = dut_Or_1Ux1U_1U_4_6_out1 & din_m_stalling;

         // resource: dut_And_1Ux1U_1U_4  instance: dut_And_1Ux1U_1U_4_11
         assign dut_And_1Ux1U_1U_4_11_out1 = dut_And_1Ux1U_1U_4_10_out1 & dut_Not_1U_1U_4_9_out1;

         // resource: regr_1
         always @(posedge clk)
          begin :drive_din_m_stall_reg_full
            if (rst == 1'b0) begin
               din_m_stall_reg_full <= 1'd0;
            end
            else begin
               din_m_stall_reg_full <= dut_And_1Ux1U_1U_4_12_out1;
            end
         end

         // resource: dut_And_1Ux1U_1U_4  instance: dut_And_1Ux1U_1U_4_12
         assign dut_And_1Ux1U_1U_4_12_out1 = dut_Or_1Ux1U_1U_4_6_out1 & din_m_stalling;

         // thread: drive_dout_vld
         assign dout_vld = dut_Or_1Ux1U_1U_4_15_out1;

         // resource: dut_Or_1Ux1U_1U_4  instance: dut_Or_1Ux1U_1U_4_15
         assign dut_Or_1Ux1U_1U_4_15_out1 = dout_m_unacked_req | dut_Xor_1Ux1U_1U_4_14_out1;

         // resource: regr_1
         always @(posedge clk)
          begin :drive_dout_m_unacked_req
            if (rst == 1'b0) begin
               dout_m_unacked_req <= 1'd0;
            end
            else begin
               dout_m_unacked_req <= dut_And_1Ux1U_1U_4_16_out1;
            end
         end

         // resource: dut_And_1Ux1U_1U_4  instance: dut_And_1Ux1U_1U_4_16
         assign dut_And_1Ux1U_1U_4_16_out1 = dout_busy & dout_vld;

         // resource: dut_Xor_1Ux1U_1U_4  instance: dut_Xor_1Ux1U_1U_4_14
         assign dut_Xor_1Ux1U_1U_4_14_out1 = dout_m_req_m_trig_req ^ dout_m_req_m_prev_trig_req;

         // resource: regr_1
         always @(posedge clk)
          begin :drive_dout_m_req_m_prev_trig_req
            if (rst == 1'b0) begin
               dout_m_req_m_prev_trig_req <= 1'd0;
            end
            else begin
               dout_m_req_m_prev_trig_req <= dout_m_req_m_trig_req;
            end
         end

         // resource: dut_Not_1U_1U_4  instance: dut_Not_1U_1U_4_17
         assign dut_Not_1U_1U_4_17_out1 = !dout_m_req_m_trig_req;


endmodule

