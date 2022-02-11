// Generated by stratus_hls 17.20-p100  (88533.190925)
// Tue Nov 17 22:54:34 2020
// from dut.cc

`timescale 1ps / 1ps

      
module dut(clk, rst, din_busy, din_vld, din_data, dout_busy, dout_vld, dout_data);

      input clk;
      input rst;
      input din_vld;
      input [7:0] din_data;
      input dout_busy;
      output din_busy;
      output dout_vld;
      output [10:0] dout_data;
      reg [10:0] dout_data;
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
      reg[3:0] global_state_next;
      reg[7:0] dut_Add_11Ux8U_11U_4_15_in1;
      reg[2:0] gs_ctrl1;
      reg[10:0] dut_Add_11Ux8U_11U_4_15_in2;
      reg gs_ctrl0;
      reg[7:0] s_reg_25;
      reg[7:0] s_reg_24;
      reg[7:0] s_reg_23;
      reg[7:0] s_reg_22;
      reg[7:0] s_reg_21;
      reg[7:0] s_reg_20;
      reg[7:0] s_reg_19;
      wire dut_Not_1U_1U_4_6_out1;
      wire dut_And_1Ux1U_1U_4_11_out1;
      wire dut_Not_1U_1U_4_12_out1;
      reg dout_m_req_m_trig_req;
      reg din_m_busy_req_0;
      wire[10:0] dut_Add_11Ux8U_11U_4_15_out1;
      wire[9:0] dut_Add_9Ux8U_10U_4_14_out1;
      wire[8:0] dut_Add_8Ux8U_9U_4_13_out1;
      reg[3:0] global_state;
      reg stall0;

         // resource: mux_11bx5i
         // resource: regr_11
         always @(posedge clk)
          begin :drive_dout_data
            if (stall0) begin
            end
            else begin
               case (global_state) 

                  4'd01: begin
                     dout_data <= {3'b000, din_data};
                  end
                  
                  4'd02, 4'd09: begin
                     dout_data <= {2'b00, dut_Add_8Ux8U_9U_4_13_out1};
                  end
                  
                  4'd03: begin
                     dout_data <= {1'b0, dut_Add_9Ux8U_10U_4_14_out1};
                  end
                  
                  4'd04, 4'd05, 4'd06, 4'd07: begin
                     dout_data <= dut_Add_11Ux8U_11U_4_15_out1;
                  end
                  
                  4'd08: begin
                     dout_data <= {3'b000, dut_Add_11Ux8U_11U_4_15_out1[10:3]};
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

                     4'd00, 4'd02, 4'd09: begin
                        din_m_busy_req_0 <= 1'd0;
                     end
                     
                     4'd01, 4'd03: begin
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

                     4'd01, 4'd08: begin
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

               4'd01, 4'd03: begin
                  stall0 = dut_Not_1U_1U_4_6_out1;
               end
               
               4'd02, 4'd09: begin
                  stall0 = dut_And_1Ux1U_1U_4_11_out1;
               end
               
               default: begin
                  stall0 = 1'b0;
               end
               
            endcase

         end

         // resource: mux_8bx2i
         // resource: regr_8
         always @(posedge clk)
          begin :drive_s_reg_19
            if (stall0) begin
            end
            else begin
               case (global_state) 

                  4'd01: begin
                     s_reg_19 <= din_data;
                  end
                  
                  4'd02, 4'd09: begin
                     s_reg_19 <= s_reg_20;
                  end
                  
               endcase

            end
         end

         // resource: mux_8bx2i
         // resource: regr_8
         always @(posedge clk)
          begin :drive_s_reg_20
            if (stall0) begin
            end
            else begin
               case (global_state) 

                  4'd01: begin
                     s_reg_20 <= din_data;
                  end
                  
                  4'd02, 4'd09: begin
                     s_reg_20 <= s_reg_21;
                  end
                  
               endcase

            end
         end

         // resource: mux_8bx2i
         // resource: regr_8
         always @(posedge clk)
          begin :drive_s_reg_21
            if (stall0) begin
            end
            else begin
               case (global_state) 

                  4'd01: begin
                     s_reg_21 <= din_data;
                  end
                  
                  4'd02, 4'd09: begin
                     s_reg_21 <= s_reg_22;
                  end
                  
               endcase

            end
         end

         // resource: mux_8bx2i
         // resource: regr_8
         always @(posedge clk)
          begin :drive_s_reg_22
            if (stall0) begin
            end
            else begin
               case (global_state) 

                  4'd01: begin
                     s_reg_22 <= din_data;
                  end
                  
                  4'd02, 4'd09: begin
                     s_reg_22 <= s_reg_23;
                  end
                  
               endcase

            end
         end

         // resource: mux_8bx2i
         // resource: regr_8
         always @(posedge clk)
          begin :drive_s_reg_23
            if (stall0) begin
            end
            else begin
               case (global_state) 

                  4'd01: begin
                     s_reg_23 <= din_data;
                  end
                  
                  4'd02, 4'd09: begin
                     s_reg_23 <= s_reg_24;
                  end
                  
               endcase

            end
         end

         // resource: mux_8bx2i
         // resource: regr_8
         always @(posedge clk)
          begin :drive_s_reg_24
            if (stall0) begin
            end
            else begin
               case (global_state) 

                  4'd01: begin
                     s_reg_24 <= din_data;
                  end
                  
                  4'd02, 4'd09: begin
                     s_reg_24 <= s_reg_25;
                  end
                  
               endcase

            end
         end

         // resource: regr_8
         always @(posedge clk)
          begin :drive_s_reg_25
            if (stall0) begin
            end
            else begin
               case (global_state) 

                  4'd01, 4'd03: begin
                     s_reg_25 <= din_data;
                  end
                  
               endcase

            end
         end

         // resource: dut_Add_8Ux8U_9U_4  instance: dut_Add_8Ux8U_9U_4_13
         assign dut_Add_8Ux8U_9U_4_13_out1 = {1'b0, s_reg_19} + {1'b0, s_reg_20};

         // resource: dut_Add_9Ux8U_10U_4  instance: dut_Add_9Ux8U_10U_4_14
         assign dut_Add_9Ux8U_10U_4_14_out1 = {1'b0, dout_data[8:0]} + {2'b00, s_reg_20};

         // resource: mux_11bx2i
         always @(dout_data or gs_ctrl0)
          begin :drive_dut_Add_11Ux8U_11U_4_15_in2
            if (gs_ctrl0) begin
               dut_Add_11Ux8U_11U_4_15_in2 = {1'b0, dout_data[9:0]};
            end
            else begin
               dut_Add_11Ux8U_11U_4_15_in2 = dout_data;
            end
         end

         // resource: mux_8bx5i
         always @(s_reg_21 or s_reg_22 or s_reg_23 or s_reg_24 or s_reg_25 or gs_ctrl1)
          begin :drive_dut_Add_11Ux8U_11U_4_15_in1
            case (gs_ctrl1) 

               3'd1: begin
                  dut_Add_11Ux8U_11U_4_15_in1 = s_reg_22;
               end
               
               3'd2: begin
                  dut_Add_11Ux8U_11U_4_15_in1 = s_reg_23;
               end
               
               3'd3: begin
                  dut_Add_11Ux8U_11U_4_15_in1 = s_reg_24;
               end
               
               3'd4: begin
                  dut_Add_11Ux8U_11U_4_15_in1 = s_reg_25;
               end
               
               default: begin
                  dut_Add_11Ux8U_11U_4_15_in1 = s_reg_21;
               end
               
            endcase

         end

         // resource: dut_Add_11Ux8U_11U_4  instance: dut_Add_11Ux8U_11U_4_15
         assign dut_Add_11Ux8U_11U_4_15_out1 = dut_Add_11Ux8U_11U_4_15_in2 + {3'b000, dut_Add_11Ux8U_11U_4_15_in1};

         // resource: regr_4
         always @(posedge clk)
          begin :drive_global_state
            if (rst == 1'b0) begin
               global_state <= 4'd00;
            end
            else begin
               if (stall0) begin
               end
               else begin
                  global_state <= global_state_next;
               end
            end
         end

         // resource: mux_4bx2i
         always @(global_state)
          begin :drive_global_state_next
            case (global_state) 

               4'd02, 4'd09: begin
                  global_state_next = 4'd03;
               end
               
               default: begin
                  global_state_next = global_state + 4'd01;
               end
               
            endcase

         end

         // resource: mux_1bx2i
         // resource: regr_1
         always @(posedge clk)
          begin :drive_gs_ctrl0
            if (rst == 1'b0) begin
               gs_ctrl0 <= 1'b0;
            end
            else begin
               if (stall0) begin
               end
               else begin
                  case (global_state_next) 

                     4'd05: begin
                        gs_ctrl0 <= 1'b1;
                     end
                     
                     default: begin
                        gs_ctrl0 <= 1'b0;
                     end
                     
                  endcase

               end
            end
         end

         // resource: mux_3bx5i
         // resource: regr_3
         always @(posedge clk)
          begin :drive_gs_ctrl1
            if (rst == 1'b0) begin
               gs_ctrl1 <= 3'd0;
            end
            else begin
               if (stall0) begin
               end
               else begin
                  case (global_state_next) 

                     4'd05: begin
                        gs_ctrl1 <= 3'd1;
                     end
                     
                     4'd06: begin
                        gs_ctrl1 <= 3'd2;
                     end
                     
                     4'd07: begin
                        gs_ctrl1 <= 3'd3;
                     end
                     
                     4'd08: begin
                        gs_ctrl1 <= 3'd4;
                     end
                     
                     default: begin
                        gs_ctrl1 <= 3'd0;
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

