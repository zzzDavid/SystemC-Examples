`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 16 2020 23:44:45 EST (Nov 17 2020 04:44:45 UTC)

module dut_DECODE_4U_3_4(in1, out1);
  input [1:0] in1;
  output [3:0] out1;
  wire [1:0] in1;
  wire [3:0] out1;
  AND2XL g30(.A (in1[1]), .B (in1[0]), .Y (out1[3]));
  NOR2BX1 g31(.AN (in1[1]), .B (in1[0]), .Y (out1[2]));
  NOR2BX1 g32(.AN (in1[0]), .B (in1[1]), .Y (out1[1]));
  NOR2X1 g33(.A (in1[1]), .B (in1[0]), .Y (out1[0]));
endmodule

