`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 17 2020 14:07:15 EST (Nov 17 2020 19:07:15 UTC)

module dut_Equal_6Ux1U_1U_1(in2, in1, out1);
  input [5:0] in2;
  input in1;
  output out1;
  wire [5:0] in2;
  wire in1;
  wire out1;
  wire n_0, n_1, n_2, n_3, n_4, n_5, n_6, n_7;
  NOR3X2 g30(.A (in2[1]), .B (n_7), .C (n_6), .Y (out1));
  NOR2X2 g31(.A (n_3), .B (n_5), .Y (n_7));
  NAND2X2 g32(.A (n_4), .B (n_2), .Y (n_6));
  NOR2X6 g34(.A (n_0), .B (n_1), .Y (n_5));
  NOR2X4 g35(.A (in2[5]), .B (in2[4]), .Y (n_4));
  NOR2X2 g33(.A (in2[0]), .B (in1), .Y (n_3));
  NOR2X2 g36(.A (in2[3]), .B (in2[2]), .Y (n_2));
  CLKINVX4 g37(.A (in1), .Y (n_1));
  CLKINVX12 g38(.A (in2[0]), .Y (n_0));
endmodule

