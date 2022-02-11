`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 17 2020 14:06:12 EST (Nov 17 2020 19:06:12 UTC)

module dut_LessThan_8Sx8S_1U_4(in2, in1, out1);
  input [7:0] in2, in1;
  output out1;
  wire [7:0] in2, in1;
  wire out1;
  wire gt_33_58_n_0, gt_33_58_n_1, gt_33_58_n_2, gt_33_58_n_3,
       gt_33_58_n_4, gt_33_58_n_5, gt_33_58_n_6, gt_33_58_n_7;
  wire gt_33_58_n_8, gt_33_58_n_9, gt_33_58_n_10, gt_33_58_n_11,
       gt_33_58_n_12, gt_33_58_n_13, gt_33_58_n_14, gt_33_58_n_15;
  wire gt_33_58_n_16, gt_33_58_n_17, gt_33_58_n_18, gt_33_58_n_19,
       gt_33_58_n_20, gt_33_58_n_21;
  OAI21X1 gt_33_58_g295(.A0 (gt_33_58_n_3), .A1 (gt_33_58_n_21), .B0
       (gt_33_58_n_5), .Y (out1));
  OAI211X1 gt_33_58_g296(.A0 (gt_33_58_n_10), .A1 (gt_33_58_n_15), .B0
       (gt_33_58_n_17), .C0 (gt_33_58_n_20), .Y (gt_33_58_n_21));
  OAI211X1 gt_33_58_g297(.A0 (gt_33_58_n_2), .A1 (in2[4]), .B0
       (gt_33_58_n_19), .C0 (gt_33_58_n_4), .Y (gt_33_58_n_20));
  AOI31X1 gt_33_58_g298(.A0 (gt_33_58_n_12), .A1 (gt_33_58_n_7), .A2
       (gt_33_58_n_18), .B0 (gt_33_58_n_10), .Y (gt_33_58_n_19));
  OAI211X1 gt_33_58_g299(.A0 (gt_33_58_n_1), .A1 (in2[2]), .B0
       (gt_33_58_n_8), .C0 (gt_33_58_n_16), .Y (gt_33_58_n_18));
  AND2XL gt_33_58_g300(.A (gt_33_58_n_5), .B (gt_33_58_n_13), .Y
       (gt_33_58_n_17));
  OAI21X1 gt_33_58_g301(.A0 (in1[1]), .A1 (gt_33_58_n_6), .B0
       (gt_33_58_n_14), .Y (gt_33_58_n_16));
  AOI32X1 gt_33_58_g302(.A0 (in2[4]), .A1 (gt_33_58_n_2), .A2
       (gt_33_58_n_4), .B0 (in2[5]), .B1 (gt_33_58_n_0), .Y
       (gt_33_58_n_15));
  OAI2BB1X1 gt_33_58_g303(.A0N (in1[1]), .A1N (gt_33_58_n_6), .B0
       (in2[1]), .Y (gt_33_58_n_14));
  NAND2X1 gt_33_58_g304(.A (in2[6]), .B (gt_33_58_n_11), .Y
       (gt_33_58_n_13));
  NAND3X1 gt_33_58_g305(.A (in2[2]), .B (gt_33_58_n_1), .C
       (gt_33_58_n_8), .Y (gt_33_58_n_12));
  NOR2X1 gt_33_58_g306(.A (in1[6]), .B (gt_33_58_n_3), .Y
       (gt_33_58_n_11));
  NAND2BX1 gt_33_58_g307(.AN (gt_33_58_n_3), .B (gt_33_58_n_9), .Y
       (gt_33_58_n_10));
  NAND2BXL gt_33_58_g308(.AN (in2[6]), .B (in1[6]), .Y (gt_33_58_n_9));
  NAND2BX1 gt_33_58_g309(.AN (in2[3]), .B (in1[3]), .Y (gt_33_58_n_8));
  NAND2BXL gt_33_58_g310(.AN (in1[3]), .B (in2[3]), .Y (gt_33_58_n_7));
  NOR2BX1 gt_33_58_g311(.AN (in1[0]), .B (in2[0]), .Y (gt_33_58_n_6));
  NAND2BXL gt_33_58_g312(.AN (in1[7]), .B (in2[7]), .Y (gt_33_58_n_5));
  NAND2BX1 gt_33_58_g313(.AN (in2[5]), .B (in1[5]), .Y (gt_33_58_n_4));
  NOR2BX1 gt_33_58_g314(.AN (in1[7]), .B (in2[7]), .Y (gt_33_58_n_3));
  INVX1 gt_33_58_g315(.A (in1[4]), .Y (gt_33_58_n_2));
  INVX1 gt_33_58_g316(.A (in1[2]), .Y (gt_33_58_n_1));
  INVX1 gt_33_58_g317(.A (in1[5]), .Y (gt_33_58_n_0));
endmodule

