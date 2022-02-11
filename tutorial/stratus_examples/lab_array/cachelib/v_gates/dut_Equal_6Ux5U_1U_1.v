`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 17 2020 14:07:17 EST (Nov 17 2020 19:07:17 UTC)

module dut_Equal_6Ux5U_1U_1(in2, in1, out1);
  input [5:0] in2;
  input [4:0] in1;
  output out1;
  wire [5:0] in2;
  wire [4:0] in1;
  wire out1;
  wire n_0, n_1, n_2, n_3, n_4, n_5, n_6, n_7;
  wire n_8, n_9, n_10, n_11, n_12, n_13, n_14, n_15;
  wire n_16, n_17, n_18, n_19, n_20, n_21, n_22, n_23;
  wire n_24, n_25, n_26, n_27;
  NOR2X1 g69(.A (n_26), .B (n_27), .Y (out1));
  NAND2X1 g71(.A (n_24), .B (n_25), .Y (n_27));
  NAND3X2 g70(.A (n_18), .B (n_16), .C (n_23), .Y (n_26));
  NOR2X2 g72(.A (n_21), .B (n_20), .Y (n_25));
  NOR2X2 g73(.A (in2[5]), .B (n_22), .Y (n_24));
  NAND2X1 g74(.A (n_10), .B (n_15), .Y (n_23));
  NOR2X1 g75(.A (n_12), .B (n_19), .Y (n_22));
  NOR2X2 g76(.A (n_13), .B (n_17), .Y (n_21));
  NOR2X1 g77(.A (n_11), .B (n_14), .Y (n_20));
  NOR2X4 g79(.A (n_8), .B (n_3), .Y (n_19));
  NAND2X1 g80(.A (in2[4]), .B (n_1), .Y (n_18));
  NOR2X4 g82(.A (n_4), .B (n_5), .Y (n_17));
  NAND2X1 g83(.A (in1[4]), .B (n_6), .Y (n_16));
  NAND2X2 g85(.A (n_0), .B (n_9), .Y (n_15));
  NOR2X2 g86(.A (n_7), .B (n_2), .Y (n_14));
  NOR2X2 g84(.A (in2[2]), .B (in1[2]), .Y (n_13));
  NOR2X2 g81(.A (in2[1]), .B (in1[1]), .Y (n_12));
  NOR2X1 g87(.A (in2[0]), .B (in1[0]), .Y (n_11));
  NAND2X1 g78(.A (in2[3]), .B (in1[3]), .Y (n_10));
  CLKINVX2 g95(.A (in1[3]), .Y (n_9));
  CLKINVX12 g93(.A (in2[1]), .Y (n_8));
  CLKINVX4 g90(.A (in2[0]), .Y (n_7));
  INVX1 g92(.A (in2[4]), .Y (n_6));
  CLKINVX3 g91(.A (in1[2]), .Y (n_5));
  CLKINVX12 g89(.A (in2[2]), .Y (n_4));
  CLKINVX3 g97(.A (in1[1]), .Y (n_3));
  CLKINVX2 g96(.A (in1[0]), .Y (n_2));
  INVX1 g88(.A (in1[4]), .Y (n_1));
  CLKINVX4 g94(.A (in2[3]), .Y (n_0));
endmodule


