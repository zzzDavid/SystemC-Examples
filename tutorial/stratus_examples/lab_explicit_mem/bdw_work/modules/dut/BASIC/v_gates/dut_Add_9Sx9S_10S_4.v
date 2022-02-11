`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 17 2020 14:53:07 EST (Nov 17 2020 19:53:07 UTC)

module dut_Add_9Sx9S_10S_4(in2, in1, out1);
  input [8:0] in2, in1;
  output [9:0] out1;
  wire [8:0] in2, in1;
  wire [9:0] out1;
  wire add_35_2_n_0, add_35_2_n_1, add_35_2_n_2, add_35_2_n_3,
       add_35_2_n_4, add_35_2_n_5, add_35_2_n_6, add_35_2_n_7;
  wire add_35_2_n_8, add_35_2_n_9, add_35_2_n_10, add_35_2_n_11,
       add_35_2_n_12, add_35_2_n_13, add_35_2_n_14, add_35_2_n_15;
  wire add_35_2_n_16, add_35_2_n_17, add_35_2_n_18, add_35_2_n_20,
       add_35_2_n_21, add_35_2_n_23, add_35_2_n_26, add_35_2_n_27;
  wire add_35_2_n_29, add_35_2_n_30, add_35_2_n_33, add_35_2_n_34;
  XNOR2X1 add_35_2_g289(.A (add_35_2_n_10), .B (add_35_2_n_34), .Y
       (out1[7]));
  AOI21X1 add_35_2_g290(.A0 (add_35_2_n_5), .A1 (add_35_2_n_33), .B0
       (add_35_2_n_9), .Y (out1[9]));
  XNOR2X1 add_35_2_g291(.A (add_35_2_n_12), .B (add_35_2_n_33), .Y
       (out1[8]));
  OAI21X1 add_35_2_g292(.A0 (add_35_2_n_7), .A1 (add_35_2_n_30), .B0
       (add_35_2_n_1), .Y (add_35_2_n_34));
  OAI211X1 add_35_2_g293(.A0 (add_35_2_n_15), .A1 (add_35_2_n_27), .B0
       (add_35_2_n_20), .C0 (add_35_2_n_6), .Y (add_35_2_n_33));
  XNOR2X1 add_35_2_g294(.A (add_35_2_n_14), .B (add_35_2_n_30), .Y
       (out1[6]));
  XNOR2X1 add_35_2_g295(.A (add_35_2_n_13), .B (add_35_2_n_29), .Y
       (out1[5]));
  NOR2BX1 add_35_2_g296(.AN (add_35_2_n_27), .B (add_35_2_n_16), .Y
       (add_35_2_n_30));
  OAI2BB1X1 add_35_2_g297(.A0N (add_35_2_n_8), .A1N (add_35_2_n_26),
       .B0 (add_35_2_n_3), .Y (add_35_2_n_29));
  XNOR2X1 add_35_2_g298(.A (add_35_2_n_11), .B (add_35_2_n_26), .Y
       (out1[4]));
  NAND3BXL add_35_2_g299(.AN (add_35_2_n_2), .B (add_35_2_n_26), .C
       (add_35_2_n_8), .Y (add_35_2_n_27));
  ADDFX1 add_35_2_g300(.A (add_35_2_n_23), .B (in1[3]), .CI (in2[3]),
       .CO (add_35_2_n_26), .S (out1[3]));
  ADDFX1 add_35_2_g301(.A (add_35_2_n_21), .B (in1[2]), .CI (in2[2]),
       .CO (add_35_2_n_23), .S (out1[2]));
  ADDFX1 add_35_2_g302(.A (add_35_2_n_18), .B (in1[1]), .CI (in2[1]),
       .CO (add_35_2_n_21), .S (out1[1]));
  OA22X1 add_35_2_g303(.A0 (add_35_2_n_15), .A1 (add_35_2_n_17), .B0
       (add_35_2_n_1), .B1 (add_35_2_n_4), .Y (add_35_2_n_20));
  ADDHX1 add_35_2_g304(.A (in2[0]), .B (in1[0]), .CO (add_35_2_n_18),
       .S (out1[0]));
  INVXL add_35_2_g305(.A (add_35_2_n_16), .Y (add_35_2_n_17));
  OAI21X1 add_35_2_g306(.A0 (add_35_2_n_3), .A1 (add_35_2_n_2), .B0
       (add_35_2_n_0), .Y (add_35_2_n_16));
  OR2XL add_35_2_g307(.A (add_35_2_n_4), .B (add_35_2_n_7), .Y
       (add_35_2_n_15));
  NOR2BX1 add_35_2_g308(.AN (add_35_2_n_1), .B (add_35_2_n_7), .Y
       (add_35_2_n_14));
  NAND2BX1 add_35_2_g309(.AN (add_35_2_n_2), .B (add_35_2_n_0), .Y
       (add_35_2_n_13));
  NAND2BX1 add_35_2_g310(.AN (add_35_2_n_9), .B (add_35_2_n_5), .Y
       (add_35_2_n_12));
  NAND2X1 add_35_2_g311(.A (add_35_2_n_3), .B (add_35_2_n_8), .Y
       (add_35_2_n_11));
  NAND2BX1 add_35_2_g312(.AN (add_35_2_n_4), .B (add_35_2_n_6), .Y
       (add_35_2_n_10));
  NOR2X1 add_35_2_g313(.A (in2[8]), .B (in1[8]), .Y (add_35_2_n_9));
  OR2XL add_35_2_g314(.A (in2[4]), .B (in1[4]), .Y (add_35_2_n_8));
  NOR2X1 add_35_2_g315(.A (in2[6]), .B (in1[6]), .Y (add_35_2_n_7));
  NAND2X1 add_35_2_g316(.A (in2[7]), .B (in1[7]), .Y (add_35_2_n_6));
  NAND2X1 add_35_2_g317(.A (in2[8]), .B (in1[8]), .Y (add_35_2_n_5));
  NOR2X1 add_35_2_g318(.A (in2[7]), .B (in1[7]), .Y (add_35_2_n_4));
  NAND2X1 add_35_2_g319(.A (in2[4]), .B (in1[4]), .Y (add_35_2_n_3));
  NOR2X1 add_35_2_g320(.A (in2[5]), .B (in1[5]), .Y (add_35_2_n_2));
  NAND2X1 add_35_2_g321(.A (in2[6]), .B (in1[6]), .Y (add_35_2_n_1));
  NAND2X1 add_35_2_g322(.A (in2[5]), .B (in1[5]), .Y (add_35_2_n_0));
endmodule

