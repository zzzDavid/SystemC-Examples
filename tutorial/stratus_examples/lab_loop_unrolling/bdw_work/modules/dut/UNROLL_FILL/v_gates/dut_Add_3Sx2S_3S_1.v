`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 17 2020 22:52:59 EST (Nov 18 2020 03:52:59 UTC)

module dut_Add_3Sx2S_3S_1(in2, in1, out1);
  input [2:0] in2;
  input [1:0] in1;
  output [2:0] out1;
  wire [2:0] in2;
  wire [1:0] in1;
  wire [2:0] out1;
  wire add_35_2_n_0, add_35_2_n_1, add_35_2_n_2, add_35_2_n_3,
       add_35_2_n_4, add_35_2_n_5, add_35_2_n_6, add_35_2_n_8;
  wire add_35_2_n_10, add_35_2_n_12, add_35_2_n_19;
  MXI2XL add_35_2_g43(.A (add_35_2_n_8), .B (add_35_2_n_19), .S0
       (add_35_2_n_12), .Y (out1[2]));
  OAI21X1 add_35_2_g44(.A0 (add_35_2_n_3), .A1 (add_35_2_n_4), .B0
       (add_35_2_n_5), .Y (add_35_2_n_12));
  MXI2XL add_35_2_g45(.A (add_35_2_n_3), .B (add_35_2_n_10), .S0
       (add_35_2_n_1), .Y (out1[1]));
  INVX1 add_35_2_g46(.A (add_35_2_n_3), .Y (add_35_2_n_10));
  NAND2X1 add_35_2_g49(.A (add_35_2_n_6), .B (add_35_2_n_0), .Y
       (add_35_2_n_8));
  MXI2XL add_35_2_g50(.A (add_35_2_n_2), .B (in2[0]), .S0 (in1[0]), .Y
       (out1[0]));
  NAND2X1 add_35_2_g51(.A (in2[2]), .B (in1[1]), .Y (add_35_2_n_6));
  NAND2X1 add_35_2_g53(.A (in2[1]), .B (in1[1]), .Y (add_35_2_n_5));
  NOR2X1 add_35_2_g55(.A (in2[1]), .B (in1[1]), .Y (add_35_2_n_4));
  NAND2X2 add_35_2_g56(.A (in2[0]), .B (in1[0]), .Y (add_35_2_n_3));
  INVX1 add_35_2_g59(.A (in2[0]), .Y (add_35_2_n_2));
  NOR2BX1 add_35_2_g2(.AN (add_35_2_n_5), .B (add_35_2_n_4), .Y
       (add_35_2_n_1));
  OR2XL add_35_2_g60(.A (in2[2]), .B (in1[1]), .Y (add_35_2_n_0));
  INVXL add_35_2_fopt(.A (add_35_2_n_8), .Y (add_35_2_n_19));
endmodule
