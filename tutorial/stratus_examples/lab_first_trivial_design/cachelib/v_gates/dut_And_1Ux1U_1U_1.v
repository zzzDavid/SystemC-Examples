`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 16 2020 23:44:42 EST (Nov 17 2020 04:44:42 UTC)

module dut_And_1Ux1U_1U_1(in2, in1, out1);
  input in2, in1;
  output out1;
  wire in2, in1;
  wire out1;
  wire n_0, n_1;
  NOR2X4 g8(.A (n_0), .B (n_1), .Y (out1));
  CLKINVX4 g9(.A (in1), .Y (n_1));
  CLKINVX12 g10(.A (in2), .Y (n_0));
endmodule


