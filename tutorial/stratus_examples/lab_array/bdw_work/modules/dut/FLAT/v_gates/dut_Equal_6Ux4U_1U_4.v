`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 17 2020 14:07:06 EST (Nov 17 2020 19:07:06 UTC)

module dut_Equal_6Ux4U_1U_4(in2, in1, out1);
  input [5:0] in2;
  input [3:0] in1;
  output out1;
  wire [5:0] in2;
  wire [3:0] in1;
  wire out1;
  wire n_0, n_1, n_2, n_3, n_4;
  NOR3XL g51(.A (n_4), .B (in2[5]), .C (in2[4]), .Y (out1));
  NAND4XL g52(.A (n_1), .B (n_2), .C (n_3), .D (n_0), .Y (n_4));
  XNOR2X1 g53(.A (in2[3]), .B (in1[3]), .Y (n_3));
  XNOR2X1 g55(.A (in2[1]), .B (in1[1]), .Y (n_2));
  XNOR2X1 g56(.A (in2[2]), .B (in1[2]), .Y (n_1));
  XNOR2X1 g54(.A (in2[0]), .B (in1[0]), .Y (n_0));
endmodule

