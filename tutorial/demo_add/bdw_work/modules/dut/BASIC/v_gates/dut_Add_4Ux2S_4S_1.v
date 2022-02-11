`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 20 2020 12:05:33 EST (Nov 20 2020 17:05:33 UTC)

module dut_Add_4Ux2S_4S_1(in2, in1, out1);
  input [3:0] in2;
  input [1:0] in1;
  output [3:0] out1;
  wire [3:0] in2;
  wire [1:0] in1;
  wire [3:0] out1;
  wire add_35_2_n_0, add_35_2_n_1, add_35_2_n_2, add_35_2_n_3,
       add_35_2_n_4, add_35_2_n_5, add_35_2_n_6, add_35_2_n_7;
  wire add_35_2_n_9, add_35_2_n_10, add_35_2_n_11, add_35_2_n_12,
       add_35_2_n_15, add_35_2_n_18, add_35_2_n_27, add_35_2_n_28;
  MXI2X1 add_35_2_g62(.A (add_35_2_n_9), .B (add_35_2_n_10), .S0
       (add_35_2_n_18), .Y (out1[3]));
  OAI21X2 add_35_2_g63(.A0 (add_35_2_n_5), .A1 (add_35_2_n_28), .B0
       (add_35_2_n_6), .Y (add_35_2_n_18));
  MXI2XL add_35_2_g64(.A (add_35_2_n_12), .B (add_35_2_n_11), .S0
       (add_35_2_n_27), .Y (out1[2]));
  OAI21X4 add_35_2_g66(.A0 (add_35_2_n_3), .A1 (add_35_2_n_4), .B0
       (add_35_2_n_7), .Y (add_35_2_n_15));
  INVX1 add_35_2_g69(.A (add_35_2_n_11), .Y (add_35_2_n_12));
  NOR2X1 add_35_2_g70(.A (add_35_2_n_0), .B (add_35_2_n_5), .Y
       (add_35_2_n_11));
  INVX1 add_35_2_g72(.A (add_35_2_n_9), .Y (add_35_2_n_10));
  XNOR2X1 add_35_2_g73(.A (in2[3]), .B (in1[1]), .Y (add_35_2_n_9));
  MXI2XL add_35_2_g74(.A (add_35_2_n_2), .B (in2[0]), .S0 (in1[0]), .Y
       (out1[0]));
  NAND2X2 add_35_2_g76(.A (in2[1]), .B (in1[1]), .Y (add_35_2_n_7));
  INVX1 add_35_2_g77(.A (add_35_2_n_0), .Y (add_35_2_n_6));
  NOR2X1 add_35_2_g79(.A (in2[2]), .B (in1[1]), .Y (add_35_2_n_5));
  NOR2X8 add_35_2_g80(.A (in2[1]), .B (in1[1]), .Y (add_35_2_n_4));
  NAND2X8 add_35_2_g81(.A (in2[0]), .B (in1[0]), .Y (add_35_2_n_3));
  INVX1 add_35_2_g82(.A (in2[0]), .Y (add_35_2_n_2));
  NOR2BX1 add_35_2_g2(.AN (add_35_2_n_7), .B (add_35_2_n_4), .Y
       (add_35_2_n_1));
  CLKAND2X2 add_35_2_g85(.A (in2[2]), .B (in1[1]), .Y (add_35_2_n_0));
  XNOR2X1 add_35_2_g86(.A (add_35_2_n_3), .B (add_35_2_n_1), .Y
       (out1[1]));
  INVXL add_35_2_fopt(.A (add_35_2_n_28), .Y (add_35_2_n_27));
  CLKINVX3 add_35_2_fopt87(.A (add_35_2_n_15), .Y (add_35_2_n_28));
endmodule
