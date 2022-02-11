`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 17 2020 22:53:41 EST (Nov 18 2020 03:53:41 UTC)

module dut_Add_10Ux8U_10U_4(in2, in1, out1);
  input [9:0] in2;
  input [7:0] in1;
  output [9:0] out1;
  wire [9:0] in2;
  wire [7:0] in1;
  wire [9:0] out1;
  wire add_35_2_n_0, add_35_2_n_1, add_35_2_n_2, add_35_2_n_3,
       add_35_2_n_4, add_35_2_n_5, add_35_2_n_6, add_35_2_n_7;
  wire add_35_2_n_8, add_35_2_n_9, add_35_2_n_10, add_35_2_n_11,
       add_35_2_n_12, add_35_2_n_13, add_35_2_n_14, add_35_2_n_15;
  wire add_35_2_n_16, add_35_2_n_18, add_35_2_n_20, add_35_2_n_23,
       add_35_2_n_24, add_35_2_n_26, add_35_2_n_27, add_35_2_n_28;
  wire add_35_2_n_31, add_35_2_n_32, add_35_2_n_33;
  XNOR2X1 add_35_2_g293(.A (in2[9]), .B (add_35_2_n_33), .Y (out1[9]));
  XNOR2X1 add_35_2_g294(.A (in2[8]), .B (add_35_2_n_31), .Y (out1[8]));
  XNOR2X1 add_35_2_g295(.A (add_35_2_n_9), .B (add_35_2_n_32), .Y
       (out1[7]));
  NAND2BX1 add_35_2_g296(.AN (add_35_2_n_31), .B (in2[8]), .Y
       (add_35_2_n_33));
  OAI21X1 add_35_2_g297(.A0 (add_35_2_n_6), .A1 (add_35_2_n_27), .B0
       (add_35_2_n_1), .Y (add_35_2_n_32));
  AOI211XL add_35_2_g298(.A0 (add_35_2_n_13), .A1 (add_35_2_n_15), .B0
       (add_35_2_n_28), .C0 (add_35_2_n_14), .Y (add_35_2_n_31));
  XNOR2X1 add_35_2_g299(.A (add_35_2_n_12), .B (add_35_2_n_27), .Y
       (out1[6]));
  XNOR2X1 add_35_2_g300(.A (add_35_2_n_11), .B (add_35_2_n_26), .Y
       (out1[5]));
  OAI2BB1X1 add_35_2_g301(.A0N (add_35_2_n_13), .A1N (add_35_2_n_24),
       .B0 (add_35_2_n_4), .Y (add_35_2_n_28));
  NOR2X1 add_35_2_g302(.A (add_35_2_n_15), .B (add_35_2_n_24), .Y
       (add_35_2_n_27));
  OAI2BB1X1 add_35_2_g303(.A0N (add_35_2_n_8), .A1N (add_35_2_n_23),
       .B0 (add_35_2_n_2), .Y (add_35_2_n_26));
  XNOR2X1 add_35_2_g304(.A (add_35_2_n_10), .B (add_35_2_n_23), .Y
       (out1[4]));
  NOR3BX1 add_35_2_g305(.AN (add_35_2_n_23), .B (add_35_2_n_0), .C
       (add_35_2_n_7), .Y (add_35_2_n_24));
  ADDFX1 add_35_2_g306(.A (add_35_2_n_20), .B (in1[3]), .CI (in2[3]),
       .CO (add_35_2_n_23), .S (out1[3]));
  ADDFX1 add_35_2_g307(.A (add_35_2_n_18), .B (in1[2]), .CI (in2[2]),
       .CO (add_35_2_n_20), .S (out1[2]));
  ADDFX1 add_35_2_g308(.A (add_35_2_n_16), .B (in1[1]), .CI (in2[1]),
       .CO (add_35_2_n_18), .S (out1[1]));
  ADDHX1 add_35_2_g309(.A (in2[0]), .B (in1[0]), .CO (add_35_2_n_16),
       .S (out1[0]));
  OAI21X1 add_35_2_g310(.A0 (add_35_2_n_2), .A1 (add_35_2_n_0), .B0
       (add_35_2_n_5), .Y (add_35_2_n_15));
  NOR2X1 add_35_2_g311(.A (add_35_2_n_1), .B (add_35_2_n_3), .Y
       (add_35_2_n_14));
  NOR2X1 add_35_2_g312(.A (add_35_2_n_3), .B (add_35_2_n_6), .Y
       (add_35_2_n_13));
  NOR2BX1 add_35_2_g313(.AN (add_35_2_n_1), .B (add_35_2_n_6), .Y
       (add_35_2_n_12));
  NAND2BX1 add_35_2_g314(.AN (add_35_2_n_0), .B (add_35_2_n_5), .Y
       (add_35_2_n_11));
  NAND2X1 add_35_2_g315(.A (add_35_2_n_2), .B (add_35_2_n_8), .Y
       (add_35_2_n_10));
  NAND2BX1 add_35_2_g316(.AN (add_35_2_n_3), .B (add_35_2_n_4), .Y
       (add_35_2_n_9));
  INVX1 add_35_2_g317(.A (add_35_2_n_7), .Y (add_35_2_n_8));
  NOR2X1 add_35_2_g318(.A (in2[4]), .B (in1[4]), .Y (add_35_2_n_7));
  NOR2X1 add_35_2_g319(.A (in2[6]), .B (in1[6]), .Y (add_35_2_n_6));
  NAND2X1 add_35_2_g320(.A (in2[5]), .B (in1[5]), .Y (add_35_2_n_5));
  NAND2X1 add_35_2_g321(.A (in2[7]), .B (in1[7]), .Y (add_35_2_n_4));
  NOR2X1 add_35_2_g322(.A (in2[7]), .B (in1[7]), .Y (add_35_2_n_3));
  NAND2X1 add_35_2_g323(.A (in2[4]), .B (in1[4]), .Y (add_35_2_n_2));
  NAND2X1 add_35_2_g324(.A (in2[6]), .B (in1[6]), .Y (add_35_2_n_1));
  NOR2X1 add_35_2_g325(.A (in2[5]), .B (in1[5]), .Y (add_35_2_n_0));
endmodule


