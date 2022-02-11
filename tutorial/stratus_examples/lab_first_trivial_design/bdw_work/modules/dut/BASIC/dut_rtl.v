// Generated by stratus_hls 17.20-p100  (88533.190925)
// Mon Nov 16 23:44:47 2020
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
      reg[1:0] global_state_next;
      wire dut_Not_1U_1U_4_6_out1;
      wire dut_And_1Ux1U_1U_4_11_out1;
      wire dut_Not_1U_1U_4_12_out1;
      reg dout_m_req_m_trig_req;
      reg[1:0] global_state;
      reg din_m_busy_req_0;
      wire[10:0] dut_Mul_8Ux3U_11U_4_13_out1;
      reg stall0;

         // resource: regr_11
         always @(posedge clk)
          begin :drive_dout_data
            if (stall0) begin
            end
            else begin
               dout_data <= dut_Mul_8Ux3U_11U_4_13_out1;
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

                     2'd0, 2'd2: begin
                        din_m_busy_req_0 <= 1'd0;
                     end
                     
                     2'd1: begin
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

                     2'd1: begin
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

               2'd1: begin
                  stall0 = dut_Not_1U_1U_4_6_out1;
               end
               
               2'd2: begin
                  stall0 = dut_And_1Ux1U_1U_4_11_out1;
               end
               
               default: begin
                  stall0 = 1'b0;
               end
               
            endcase

         end

         // resource: dut_Mul_8Ux3U_11U_4  instance: dut_Mul_8Ux3U_11U_4_13
         assign dut_Mul_8Ux3U_11U_4_13_out1 = {3'b000, din_data}*11'd0007;

         // resource: regr_2
         always @(posedge clk)
          begin :drive_global_state
            if (rst == 1'b0) begin
               global_state <= 2'd0;
            end
            else begin
               if (stall0) begin
               end
               else begin
                  global_state <= global_state_next;
               end
            end
         end

         // resource: mux_2bx2i
         always @(global_state)
          begin :drive_global_state_next
            case (global_state) 

               2'd0, 2'd2: begin
                  global_state_next = 2'd1;
               end
               
               default: begin
                  global_state_next = global_state + 2'd1;
               end
               
            endcase

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

