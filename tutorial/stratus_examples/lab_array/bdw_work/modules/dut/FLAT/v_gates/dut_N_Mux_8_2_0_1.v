`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 17 2020 14:07:18 EST (Nov 17 2020 19:07:18 UTC)

module dut_N_Mux_8_2_0_1(in3, in2, ctrl1, out1);
  input [7:0] in3, in2;
  input ctrl1;
  output [7:0] out1;
  wire [7:0] in3, in2;
  wire ctrl1;
  wire [7:0] out1;
  wire n_0, n_1, n_2, n_3, n_4, n_5, n_6, n_7;
  wire n_8, n_9, n_10, n_11, n_12, n_13, n_14, n_15;
  OAI21X4 g85(.A0 (ctrl1), .A1 (n_2), .B0 (n_14), .Y (out1[5]));
  OAI21X4 g86(.A0 (ctrl1), .A1 (n_5), .B0 (n_12), .Y (out1[6]));
  OAI21X4 g83(.A0 (ctrl1), .A1 (n_7), .B0 (n_15), .Y (out1[7]));
  OAI21X4 g82(.A0 (ctrl1), .A1 (n_0), .B0 (n_10), .Y (out1[4]));
  OAI21X4 g81(.A0 (ctrl1), .A1 (n_3), .B0 (n_13), .Y (out1[1]));
  OAI21X4 g88(.A0 (ctrl1), .A1 (n_6), .B0 (n_8), .Y (out1[2]));
  OAI21X4 g87(.A0 (ctrl1), .A1 (n_4), .B0 (n_9), .Y (out1[3]));
  OAI21X4 g84(.A0 (ctrl1), .A1 (n_1), .B0 (n_11), .Y (out1[0]));
  NAND2X8 g91(.A (in2[7]), .B (ctrl1), .Y (n_15));
  NAND2X8 g93(.A (in2[5]), .B (ctrl1), .Y (n_14));
  NAND2X8 g89(.A (in2[1]), .B (ctrl1), .Y (n_13));
  NAND2X8 g90(.A (in2[6]), .B (ctrl1), .Y (n_12));
  NAND2X8 g95(.A (in2[0]), .B (ctrl1), .Y (n_11));
  NAND2X8 g92(.A (in2[4]), .B (ctrl1), .Y (n_10));
  NAND2X8 g94(.A (in2[3]), .B (ctrl1), .Y (n_9));
  NAND2X8 g96(.A (in2[2]), .B (ctrl1), .Y (n_8));
  CLKINVX4 g100(.A (in3[7]), .Y (n_7));
  CLKINVX4 g104(.A (in3[2]), .Y (n_6));
  CLKINVX4 g97(.A (in3[6]), .Y (n_5));
  CLKINVX4 g103(.A (in3[3]), .Y (n_4));
  CLKINVX4 g99(.A (in3[1]), .Y (n_3));
  CLKINVX4 g101(.A (in3[5]), .Y (n_2));
  CLKINVX4 g98(.A (in3[0]), .Y (n_1));
  CLKINVX4 g102(.A (in3[4]), .Y (n_0));
endmodule

