`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 19 2020 00:45:38 EST (Nov 19 2020 05:45:38 UTC)

module dut_OrReduction_2S_1U_1(in1, out1);
  input [1:0] in1;
  output out1;
  wire [1:0] in1;
  wire out1;
  wire n_0, n_1;
  NAND2X2 g4(.A (n_0), .B (n_1), .Y (out1));
  INVX2 g5(.A (in1[0]), .Y (n_1));
  CLKINVX4 g6(.A (in1[1]), .Y (n_0));
endmodule


