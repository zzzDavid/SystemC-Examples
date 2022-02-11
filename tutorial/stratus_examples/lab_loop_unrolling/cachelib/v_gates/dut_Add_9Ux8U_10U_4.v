`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 17 2020 22:53:42 EST (Nov 18 2020 03:53:42 UTC)

module dut_Add_9Ux8U_10U_4(in2, in1, out1);
  input [8:0] in2;
  input [7:0] in1;
  output [9:0] out1;
  wire [8:0] in2;
  wire [7:0] in1;
  wire [9:0] out1;
  wire add_35_2_n_0, add_35_2_n_1, add_35_2_n_2, add_35_2_n_3,
       add_35_2_n_4, add_35_2_n_5, add_35_2_n_6, add_35_2_n_7;
  wire add_35_2_n_8, add_35_2_n_9, add_35_2_n_10, add_35_2_n_11,
       add_35_2_n_12, add_35_2_n_13, add_35_2_n_14, add_35_2_n_15;
  wire add_35_2_n_17, add_35_2_n_18, add_35_2_n_20, add_35_2_n_23,
       add_35_2_n_24, add_35_2_n_26, add_35_2_n_27, add_35_2_n_30;
  wire add_35_2_n_31;
  ADDHX1 add_35_2_g280(.A (in2[8]), .B (add_35_2_n_30), .CO (out1[9]),
       .S (out1[8]));
  XNOR2X1 add_35_2_g281(.A (add_35_2_n_8), .B (add_35_2_n_31), .Y
       (out1[7]));
  OAI21X1 add_35_2_g282(.A0 (add_35_2_n_4), .A1 (add_35_2_n_27), .B0
       (add_35_2_n_1), .Y (add_35_2_n_31));
  OAI211X1 add_35_2_g283(.A0 (add_35_2_n_9), .A1 (add_35_2_n_24), .B0
       (add_35_2_n_17), .C0 (add_35_2_n_3), .Y (add_35_2_n_30));
  XNOR2X1 add_35_2_g284(.A (add_35_2_n_12), .B (add_35_2_n_26), .Y
       (out1[5]));
  XNOR2X1 add_35_2_g285(.A (add_35_2_n_11), .B (add_35_2_n_27), .Y
       (out1[6]));
  NOR2BX1 add_35_2_g286(.AN (add_35_2_n_24), .B (add_35_2_n_13), .Y
       (add_35_2_n_27));
  OAI2BB1X1 add_35_2_g287(.A0N (add_35_2_n_5), .A1N (add_35_2_n_23),
       .B0 (add_35_2_n_7), .Y (add_35_2_n_26));
  XNOR2X1 add_35_2_g288(.A (add_35_2_n_10), .B (add_35_2_n_23), .Y
       (out1[4]));
  NAND3BXL add_35_2_g289(.AN (add_35_2_n_2), .B (add_35_2_n_23), .C
       (add_35_2_n_5), .Y (add_35_2_n_24));
  ADDFX1 add_35_2_g290(.A (add_35_2_n_20), .B (in1[3]), .CI (in2[3]),
       .CO (add_35_2_n_23), .S (out1[3]));
  ADDFX1 add_35_2_g291(.A (add_35_2_n_18), .B (in1[2]), .CI (in2[2]),
       .CO (add_35_2_n_20), .S (out1[2]));
  ADDFX1 add_35_2_g292(.A (add_35_2_n_15), .B (in1[1]), .CI (in2[1]),
       .CO (add_35_2_n_18), .S (out1[1]));
  OA22X1 add_35_2_g293(.A0 (add_35_2_n_9), .A1 (add_35_2_n_14), .B0
       (add_35_2_n_1), .B1 (add_35_2_n_0), .Y (add_35_2_n_17));
  ADDHX1 add_35_2_g294(.A (in2[0]), .B (in1[0]), .CO (add_35_2_n_15),
       .S (out1[0]));
  INVXL add_35_2_g295(.A (add_35_2_n_13), .Y (add_35_2_n_14));
  OAI21X1 add_35_2_g296(.A0 (add_35_2_n_7), .A1 (add_35_2_n_2), .B0
       (add_35_2_n_6), .Y (add_35_2_n_13));
  NAND2BX1 add_35_2_g297(.AN (add_35_2_n_2), .B (add_35_2_n_6), .Y
       (add_35_2_n_12));
  NOR2BX1 add_35_2_g298(.AN (add_35_2_n_1), .B (add_35_2_n_4), .Y
       (add_35_2_n_11));
  NAND2X1 add_35_2_g299(.A (add_35_2_n_7), .B (add_35_2_n_5), .Y
       (add_35_2_n_10));
  OR2XL add_35_2_g300(.A (add_35_2_n_0), .B (add_35_2_n_4), .Y
       (add_35_2_n_9));
  NAND2BX1 add_35_2_g301(.AN (add_35_2_n_0), .B (add_35_2_n_3), .Y
       (add_35_2_n_8));
  NAND2X1 add_35_2_g302(.A (in2[4]), .B (in1[4]), .Y (add_35_2_n_7));
  NAND2X1 add_35_2_g303(.A (in2[5]), .B (in1[5]), .Y (add_35_2_n_6));
  OR2XL add_35_2_g304(.A (in2[4]), .B (in1[4]), .Y (add_35_2_n_5));
  NOR2X1 add_35_2_g305(.A (in2[6]), .B (in1[6]), .Y (add_35_2_n_4));
  NAND2X1 add_35_2_g306(.A (in2[7]), .B (in1[7]), .Y (add_35_2_n_3));
  NOR2X1 add_35_2_g307(.A (in2[5]), .B (in1[5]), .Y (add_35_2_n_2));
  NAND2X1 add_35_2_g308(.A (in2[6]), .B (in1[6]), .Y (add_35_2_n_1));
  NOR2X1 add_35_2_g309(.A (in2[7]), .B (in1[7]), .Y (add_35_2_n_0));
endmodule


