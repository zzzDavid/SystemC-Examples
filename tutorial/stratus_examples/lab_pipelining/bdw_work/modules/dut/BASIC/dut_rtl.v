// Generated by stratus_hls 17.20-p100  (88533.190925)
// Wed Nov 18 17:51:45 2020
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
      wire dut_Xor_1Ux1U_1U_4_9_out1;
      wire dut_Or_1Ux1U_1U_4_10_out1;
      reg dut_N_Muxb_1_2_0_4_1_out1;
      wire dut_And_1Ux1U_1U_4_5_out1;
      wire dut_Not_1U_1U_4_4_out1;
      reg din_m_unvalidated_req;
      wire dut_Or_1Ux1U_1U_4_2_out1;
      wire dut_And_1Ux1U_1U_4_3_out1;
      reg[2:0] global_state_next;
      reg[16:0] dut_Add_32Ux17U_33U_4_24_in1;
      reg[31:0] dut_Add_32Ux17U_33U_4_24_in2;
      wire[31:0] dut_Mul_32Ux9U_32U_4_23_out1;
      wire[16:0] dut_Add_16Ux16U_17U_4_22_out1;
      reg[31:0] dut_Mul_32Ux9U_32U_4_20_in2;
      reg gs_ctrl4;
      reg[7:0] dut_Mul_8Ux8U_16U_4_19_in1;
      reg[7:0] dut_Mul_8Ux8U_16U_4_19_in2;
      reg[31:0] dut_Mul_33Ux32U_64U_4_18_in1;
      wire[8:0] dut_Add_8Ux8U_9U_4_25_out1;
      wire[31:0] dut_Add_32Ux32U_32U_4_30_out1;
      reg[32:0] dut_Mul_33Ux32U_64U_4_18_in2;
      wire[31:0] dut_Mul_32Ux9U_32U_4_20_out1;
      reg[1:0] gs_ctrl0;
      wire[9:0] dut_Add_9Ux8U_10U_4_16_out1;
      wire[9:0] dut_Add_9Ux8U_10U_4_15_out1;
      wire[8:0] dut_Add_8Ux8U_9U_4_14_out1;
      wire[8:0] dut_Add_8Ux8U_9U_4_13_out1;
      wire[63:0] dut_Mul_33Ux32U_64U_4_18_out1;
      wire[8:0] dut_Add_8Ux8U_9U_4_26_out1;
      wire[8:0] dut_Add_8Ux8U_9U_4_17_out1;
      reg[8:0] s_reg_25;
      reg[7:0] s_reg_24;
      reg[7:0] s_reg_23;
      reg[7:0] s_reg_22;
      reg[7:0] s_reg_21;
      reg[7:0] s_reg_20;
      reg[7:0] s_reg_19;
      reg[7:0] s_reg_18;
      wire dut_Not_1U_1U_4_6_out1;
      wire dut_And_1Ux1U_1U_4_11_out1;
      wire dut_Not_1U_1U_4_12_out1;
      reg dout_m_req_m_trig_req;
      reg din_m_busy_req_0;
      wire[32:0] dut_Add_32Ux17U_33U_4_24_out1;
      wire[15:0] dut_Mul_8Ux8U_16U_4_19_out1;
      reg[2:0] global_state;
      reg[63:0] s_reg_26;
      wire[1:0] dut_Div_64Ux2U_32U_4_33_in1;
      wire[31:0] dut_Div_64Ux2U_32U_4_33_out1;
      reg stall0;

         dut_Div_64Ux2U_32U_4 dut_Div_64Ux2U_32U_4_33(
                                .in2( s_reg_26 ),
                                .in1( dut_Div_64Ux2U_32U_4_33_in1 ),
                                .out1( dut_Div_64Ux2U_32U_4_33_out1 ),
                                .clk( clk ),
                                .stall( stall0 )
                              );

         // resource: mux_32bx3i
         // resource: regr_32
         always @(posedge clk)
          begin :drive_dout_data
            if (stall0) begin
            end
            else begin
               case (global_state) 

                  3'd1: begin
                     dout_data <= {16'b0000000000000000, dut_Mul_8Ux8U_16U_4_19_out1};
                  end
                  
                  3'd2: begin
                     dout_data <= dut_Add_32Ux17U_33U_4_24_out1[31:0];
                  end
                  
                  3'd5: begin
                     dout_data <= dut_Div_64Ux2U_32U_4_33_out1;
                  end
                  
               endcase

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
               if (stall0) begin
               end
               else begin
                  case (global_state) 

                     3'd0, 3'd6: begin
                        din_m_busy_req_0 <= 1'd0;
                     end
                     
                     3'd1: begin
                        din_m_busy_req_0 <= 1'd1;
                     end
                     
                  endcase

               end
            end
         end

         // resource: regr_1
         always @(posedge clk)
          begin :drive_dout_m_req_m_trig_req
            if (rst == 1'b0) begin
               dout_m_req_m_trig_req <= 1'd0;
            end
            else begin
               if (stall0) begin
               end
               else begin
                  case (global_state) 

                     3'd5: begin
                        dout_m_req_m_trig_req <= dut_Not_1U_1U_4_12_out1;
                     end
                     
                  endcase

               end
            end
         end

         // resource: mux_1bx3i
         always @(dut_Not_1U_1U_4_6_out1 or dut_And_1Ux1U_1U_4_11_out1 or global_state)
          begin :drive_stall0
            case (global_state) 

               3'd1: begin
                  stall0 = dut_Not_1U_1U_4_6_out1;
               end
               
               3'd6: begin
                  stall0 = dut_And_1Ux1U_1U_4_11_out1;
               end
               
               default: begin
                  stall0 = 1'b0;
               end
               
            endcase

         end

         // resource: regr_8
         always @(posedge clk)
          begin :drive_s_reg_18
            if (stall0) begin
            end
            else begin
               s_reg_18 <= din_data_a;
            end
         end

         // resource: regr_8
         always @(posedge clk)
          begin :drive_s_reg_19
            if (stall0) begin
            end
            else begin
               s_reg_19 <= din_data_b;
            end
         end

         // resource: regr_8
         always @(posedge clk)
          begin :drive_s_reg_20
            if (stall0) begin
            end
            else begin
               s_reg_20 <= din_data_d;
            end
         end

         // resource: regr_8
         always @(posedge clk)
          begin :drive_s_reg_21
            if (stall0) begin
            end
            else begin
               s_reg_21 <= din_data_e;
            end
         end

         // resource: regr_8
         always @(posedge clk)
          begin :drive_s_reg_22
            if (stall0) begin
            end
            else begin
               s_reg_22 <= din_data_c;
            end
         end

         // resource: regr_8
         always @(posedge clk)
          begin :drive_s_reg_23
            if (stall0) begin
            end
            else begin
               case (global_state) 

                  3'd1: begin
                     s_reg_23 <= din_data_g;
                  end
                  
               endcase

            end
         end

         // resource: regr_8
         always @(posedge clk)
          begin :drive_s_reg_24
            if (stall0) begin
            end
            else begin
               case (global_state) 

                  3'd1: begin
                     s_reg_24 <= din_data_h;
                  end
                  
               endcase

            end
         end

         // resource: mux_9bx2i
         // resource: regr_9
         always @(posedge clk)
          begin :drive_s_reg_25
            if (stall0) begin
            end
            else begin
               case (global_state) 

                  3'd1: begin
                     s_reg_25 <= dut_Add_8Ux8U_9U_4_17_out1;
                  end
                  
                  3'd2: begin
                     s_reg_25 <= dut_Add_8Ux8U_9U_4_26_out1;
                  end
                  
               endcase

            end
         end

         // resource: mux_64bx3i
         // resource: regr_64
         always @(posedge clk)
          begin :drive_s_reg_26
            if (stall0) begin
            end
            else begin
               case (global_state) 

                  3'd1: begin
                     s_reg_26 <= {44'b00000000000000000000000000000000000000000000, dut_Mul_33Ux32U_64U_4_18_out1[19:0]};
                  end
                  
                  3'd2: begin
                     s_reg_26 <= {32'b00000000000000000000000000000000, dut_Mul_33Ux32U_64U_4_18_out1[31:0]};
                  end
                  
                  3'd3: begin
                     s_reg_26 <= dut_Mul_33Ux32U_64U_4_18_out1;
                  end
                  
               endcase

            end
         end

         // resource: dut_Add_8Ux8U_9U_4  instance: dut_Add_8Ux8U_9U_4_13
         assign dut_Add_8Ux8U_9U_4_13_out1 = {1'b0, din_data_d} + {1'b0, din_data_e};

         // resource: dut_Add_8Ux8U_9U_4  instance: dut_Add_8Ux8U_9U_4_14
         assign dut_Add_8Ux8U_9U_4_14_out1 = {1'b0, din_data_a} + {1'b0, din_data_b};

         // resource: dut_Add_9Ux8U_10U_4  instance: dut_Add_9Ux8U_10U_4_15
         assign dut_Add_9Ux8U_10U_4_15_out1 = {1'b0, dut_Add_8Ux8U_9U_4_13_out1} + {2'b00, din_data_f};

         // resource: dut_Add_9Ux8U_10U_4  instance: dut_Add_9Ux8U_10U_4_16
         assign dut_Add_9Ux8U_10U_4_16_out1 = {1'b0, dut_Add_8Ux8U_9U_4_14_out1} + {2'b00, din_data_c};

         // resource: dut_Add_8Ux8U_9U_4  instance: dut_Add_8Ux8U_9U_4_17
         assign dut_Add_8Ux8U_9U_4_17_out1 = {1'b0, din_data_g} + {1'b0, din_data_h};

         // resource: mux_33bx3i
         always @(dut_Add_9Ux8U_10U_4_16_out1 or dut_Mul_32Ux9U_32U_4_20_out1[28:0] or dut_Add_32Ux17U_33U_4_24_out1 or gs_ctrl0)
          begin :drive_dut_Mul_33Ux32U_64U_4_18_in2
            case (gs_ctrl0) 

               2'd1: begin
                  dut_Mul_33Ux32U_64U_4_18_in2 = {4'b0000, dut_Mul_32Ux9U_32U_4_20_out1[28:0]};
               end
               
               2'd2: begin
                  dut_Mul_33Ux32U_64U_4_18_in2 = dut_Add_32Ux17U_33U_4_24_out1;
               end
               
               default: begin
                  dut_Mul_33Ux32U_64U_4_18_in2 = {23'b00000000000000000000000, dut_Add_9Ux8U_10U_4_16_out1};
               end
               
            endcase

         end

         // resource: mux_32bx3i
         always @(dut_Add_9Ux8U_10U_4_15_out1 or dut_Add_8Ux8U_9U_4_25_out1 or dut_Add_32Ux32U_32U_4_30_out1 or gs_ctrl0)
          begin :drive_dut_Mul_33Ux32U_64U_4_18_in1
            case (gs_ctrl0) 

               2'd1: begin
                  dut_Mul_33Ux32U_64U_4_18_in1 = {23'b00000000000000000000000, dut_Add_8Ux8U_9U_4_25_out1};
               end
               
               2'd2: begin
                  dut_Mul_33Ux32U_64U_4_18_in1 = dut_Add_32Ux32U_32U_4_30_out1;
               end
               
               default: begin
                  dut_Mul_33Ux32U_64U_4_18_in1 = {22'b0000000000000000000000, dut_Add_9Ux8U_10U_4_15_out1};
               end
               
            endcase

         end

         // resource: dut_Mul_33Ux32U_64U_4  instance: dut_Mul_33Ux32U_64U_4_18
         assign dut_Mul_33Ux32U_64U_4_18_out1 = {31'b0000000000000000000000000000000, dut_Mul_33Ux32U_64U_4_18_in2}*{32'b00000000000000000000000000000000, dut_Mul_33Ux32U_64U_4_18_in1};

         // resource: mux_8bx3i
         always @(din_data_a or s_reg_22 or s_reg_23 or gs_ctrl0)
          begin :drive_dut_Mul_8Ux8U_16U_4_19_in2
            case (gs_ctrl0) 

               2'd1: begin
                  dut_Mul_8Ux8U_16U_4_19_in2 = s_reg_22;
               end
               
               2'd2: begin
                  dut_Mul_8Ux8U_16U_4_19_in2 = s_reg_23;
               end
               
               default: begin
                  dut_Mul_8Ux8U_16U_4_19_in2 = din_data_a;
               end
               
            endcase

         end

         // resource: mux_8bx3i
         always @(din_data_b or s_reg_20 or s_reg_24 or gs_ctrl0)
          begin :drive_dut_Mul_8Ux8U_16U_4_19_in1
            case (gs_ctrl0) 

               2'd1: begin
                  dut_Mul_8Ux8U_16U_4_19_in1 = s_reg_20;
               end
               
               2'd2: begin
                  dut_Mul_8Ux8U_16U_4_19_in1 = s_reg_24;
               end
               
               default: begin
                  dut_Mul_8Ux8U_16U_4_19_in1 = din_data_b;
               end
               
            endcase

         end

         // resource: dut_Mul_8Ux8U_16U_4  instance: dut_Mul_8Ux8U_16U_4_19
         assign dut_Mul_8Ux8U_16U_4_19_out1 = {8'b00000000, dut_Mul_8Ux8U_16U_4_19_in2}*{8'b00000000, dut_Mul_8Ux8U_16U_4_19_in1};

         // resource: mux_32bx2i
         always @(dout_data or s_reg_26[31:0] or gs_ctrl4)
          begin :drive_dut_Mul_32Ux9U_32U_4_20_in2
            if (gs_ctrl4) begin
               dut_Mul_32Ux9U_32U_4_20_in2 = dout_data;
            end
            else begin
               dut_Mul_32Ux9U_32U_4_20_in2 = s_reg_26[31:0];
            end
         end

         // resource: dut_Mul_32Ux9U_32U_4  instance: dut_Mul_32Ux9U_32U_4_20
         assign dut_Mul_32Ux9U_32U_4_20_out1 = dut_Mul_32Ux9U_32U_4_20_in2*{23'b00000000000000000000000, s_reg_25};

         // resource: dut_Add_16Ux16U_17U_4  instance: dut_Add_16Ux16U_17U_4_22
         assign dut_Add_16Ux16U_17U_4_22_out1 = {1'b0, dout_data[15:0]} + {1'b0, dut_Mul_8Ux8U_16U_4_19_out1};

         // resource: dut_Mul_32Ux9U_32U_4  instance: dut_Mul_32Ux9U_32U_4_23
         assign dut_Mul_32Ux9U_32U_4_23_out1 = {3'b000, dut_Mul_32Ux9U_32U_4_20_out1[28:0]}*{{23'b00000000000000000000000, 1'b0}, s_reg_21};

         // resource: mux_32bx2i
         always @(dout_data or dut_Mul_32Ux9U_32U_4_23_out1 or gs_ctrl4)
          begin :drive_dut_Add_32Ux17U_33U_4_24_in2
            if (gs_ctrl4) begin
               dut_Add_32Ux17U_33U_4_24_in2 = dout_data;
            end
            else begin
               dut_Add_32Ux17U_33U_4_24_in2 = dut_Mul_32Ux9U_32U_4_23_out1;
            end
         end

         // resource: mux_17bx2i
         always @(dut_Mul_8Ux8U_16U_4_19_out1 or dut_Add_16Ux16U_17U_4_22_out1 or gs_ctrl4)
          begin :drive_dut_Add_32Ux17U_33U_4_24_in1
            if (gs_ctrl4) begin
               dut_Add_32Ux17U_33U_4_24_in1 = {1'b0, dut_Mul_8Ux8U_16U_4_19_out1};
            end
            else begin
               dut_Add_32Ux17U_33U_4_24_in1 = dut_Add_16Ux16U_17U_4_22_out1;
            end
         end

         // resource: dut_Add_32Ux17U_33U_4  instance: dut_Add_32Ux17U_33U_4_24
         assign dut_Add_32Ux17U_33U_4_24_out1 = {1'b0, dut_Add_32Ux17U_33U_4_24_in2} + {16'b0000000000000000, dut_Add_32Ux17U_33U_4_24_in1};

         // resource: dut_Add_8Ux8U_9U_4  instance: dut_Add_8Ux8U_9U_4_25
         assign dut_Add_8Ux8U_9U_4_25_out1 = {1'b0, s_reg_20} + {1'b0, s_reg_22};

         // resource: dut_Add_8Ux8U_9U_4  instance: dut_Add_8Ux8U_9U_4_26
         assign dut_Add_8Ux8U_9U_4_26_out1 = {1'b0, s_reg_18} + {1'b0, s_reg_19};

         // resource: dut_Add_32Ux32U_32U_4  instance: dut_Add_32Ux32U_32U_4_30
         assign dut_Add_32Ux32U_32U_4_30_out1 = dut_Mul_32Ux9U_32U_4_20_out1 + s_reg_26[31:0];

         // thread: drive_dut_Div_64Ux2U_32U_4_33_in1
         assign dut_Div_64Ux2U_32U_4_33_in1 = 2'd3;

         // resource: regr_3
         always @(posedge clk)
          begin :drive_global_state
            if (rst == 1'b0) begin
               global_state <= 3'd0;
            end
            else begin
               if (stall0) begin
               end
               else begin
                  global_state <= global_state_next;
               end
            end
         end

         // resource: mux_3bx2i
         always @(global_state)
          begin :drive_global_state_next
            case (global_state) 

               3'd0, 3'd6: begin
                  global_state_next = 3'd1;
               end
               
               default: begin
                  global_state_next = global_state + 3'd1;
               end
               
            endcase

         end

         // resource: mux_2bx3i
         // resource: regr_2
         always @(posedge clk)
          begin :drive_gs_ctrl0
            if (rst == 1'b0) begin
               gs_ctrl0 <= 2'd0;
            end
            else begin
               if (stall0) begin
               end
               else begin
                  case (global_state_next) 

                     3'd2: begin
                        gs_ctrl0 <= 2'd1;
                     end
                     
                     3'd3: begin
                        gs_ctrl0 <= 2'd2;
                     end
                     
                     default: begin
                        gs_ctrl0 <= 2'd0;
                     end
                     
                  endcase

               end
            end
         end

         // resource: mux_1bx2i
         // resource: regr_1
         always @(posedge clk)
          begin :drive_gs_ctrl4
            if (rst == 1'b0) begin
               gs_ctrl4 <= 1'b0;
            end
            else begin
               if (stall0) begin
               end
               else begin
                  case (global_state_next) 

                     3'd3: begin
                        gs_ctrl4 <= 1'b1;
                     end
                     
                     default: begin
                        gs_ctrl4 <= 1'b0;
                     end
                     
                  endcase

               end
            end
         end

         // thread: drive_din_busy
         assign din_busy = dut_And_1Ux1U_1U_4_3_out1;

         // resource: dut_Or_1Ux1U_1U_4  instance: dut_Or_1Ux1U_1U_4_2
         assign dut_Or_1Ux1U_1U_4_2_out1 = din_m_unvalidated_req | din_vld;

         // resource: dut_And_1Ux1U_1U_4  instance: dut_And_1Ux1U_1U_4_3
         assign dut_And_1Ux1U_1U_4_3_out1 = dut_Or_1Ux1U_1U_4_2_out1 & din_m_busy_req_0;

         // resource: dut_Not_1U_1U_4  instance: dut_Not_1U_1U_4_4
         assign dut_Not_1U_1U_4_4_out1 = !dut_And_1Ux1U_1U_4_3_out1;

         // resource: dut_And_1Ux1U_1U_4  instance: dut_And_1Ux1U_1U_4_5
         assign dut_And_1Ux1U_1U_4_5_out1 = dut_Not_1U_1U_4_4_out1 & din_vld;

         // resource: dut_Not_1U_1U_4  instance: dut_Not_1U_1U_4_6
         assign dut_Not_1U_1U_4_6_out1 = !dut_And_1Ux1U_1U_4_5_out1;

         // resource: regr_1
         always @(posedge clk)
          begin :drive_din_m_unvalidated_req
            if (rst == 1'b0) begin
               din_m_unvalidated_req <= 1'd1;
            end
            else begin
               din_m_unvalidated_req <= dut_N_Muxb_1_2_0_4_1_out1;
            end
         end

         // resource:dut_N_Muxb_1_2_0_4
         always @(din_vld or din_m_busy_req_0 or din_m_unvalidated_req)
          begin :dut_N_Muxb_1_2_0_4_1
            if (din_m_busy_req_0) begin
               dut_N_Muxb_1_2_0_4_1_out1 = din_m_unvalidated_req;
            end
            else begin
               dut_N_Muxb_1_2_0_4_1_out1 = din_vld;
            end
         end

         // thread: drive_dout_vld
         assign dout_vld = dut_Or_1Ux1U_1U_4_10_out1;

         // resource: dut_Or_1Ux1U_1U_4  instance: dut_Or_1Ux1U_1U_4_10
         assign dut_Or_1Ux1U_1U_4_10_out1 = dout_m_unacked_req | dut_Xor_1Ux1U_1U_4_9_out1;

         // resource: regr_1
         always @(posedge clk)
          begin :drive_dout_m_unacked_req
            if (rst == 1'b0) begin
               dout_m_unacked_req <= 1'd0;
            end
            else begin
               dout_m_unacked_req <= dut_And_1Ux1U_1U_4_11_out1;
            end
         end

         // resource: dut_And_1Ux1U_1U_4  instance: dut_And_1Ux1U_1U_4_11
         assign dut_And_1Ux1U_1U_4_11_out1 = dout_busy & dout_vld;

         // resource: dut_Xor_1Ux1U_1U_4  instance: dut_Xor_1Ux1U_1U_4_9
         assign dut_Xor_1Ux1U_1U_4_9_out1 = dout_m_req_m_trig_req ^ dout_m_req_m_prev_trig_req;

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

         // resource: dut_Not_1U_1U_4  instance: dut_Not_1U_1U_4_12
         assign dut_Not_1U_1U_4_12_out1 = !dout_m_req_m_trig_req;


endmodule

