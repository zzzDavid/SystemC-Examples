`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 17 2020 14:53:10 EST (Nov 17 2020 19:53:10 UTC)

module dut_Xor_1Ux1U_1U_1(in2, in1, out1);
  input in2, in1;
  output out1;
  wire in2, in1;
  wire out1;
  wire n_0;
  MXI2X1 g10(.A (n_0), .B (in2), .S0 (in1), .Y (out1));
  CLKINVX4 g11(.A (in2), .Y (n_0));
endmodule

