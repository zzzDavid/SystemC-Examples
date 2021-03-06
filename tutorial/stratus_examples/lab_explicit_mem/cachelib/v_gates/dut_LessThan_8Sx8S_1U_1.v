`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 17 2020 14:53:14 EST (Nov 17 2020 19:53:14 UTC)

module dut_LessThan_8Sx8S_1U_1(in2, in1, out1);
  input [7:0] in2, in1;
  output out1;
  wire [7:0] in2, in1;
  wire out1;
  wire gt_33_58_n_0, gt_33_58_n_1, gt_33_58_n_2, gt_33_58_n_3,
       gt_33_58_n_4, gt_33_58_n_5, gt_33_58_n_6, gt_33_58_n_7;
  wire gt_33_58_n_8, gt_33_58_n_9, gt_33_58_n_10, gt_33_58_n_11,
       gt_33_58_n_12, gt_33_58_n_13, gt_33_58_n_14, gt_33_58_n_15;
  wire gt_33_58_n_17, gt_33_58_n_18, gt_33_58_n_19, gt_33_58_n_20,
       gt_33_58_n_21, gt_33_58_n_22, gt_33_58_n_23, gt_33_58_n_24;
  wire gt_33_58_n_25, gt_33_58_n_26, gt_33_58_n_27, gt_33_58_n_28,
       gt_33_58_n_29, gt_33_58_n_30, gt_33_58_n_32, gt_33_58_n_33;
  wire gt_33_58_n_34, gt_33_58_n_35, gt_33_58_n_37, gt_33_58_n_39,
       gt_33_58_n_57;
  NOR2X1 gt_33_58_g228(.A (gt_33_58_n_57), .B (gt_33_58_n_39), .Y
       (out1));
  AOI21X1 gt_33_58_g229(.A0 (gt_33_58_n_35), .A1 (gt_33_58_n_37), .B0
       (gt_33_58_n_27), .Y (gt_33_58_n_39));
  OAI21X1 gt_33_58_g231(.A0 (gt_33_58_n_30), .A1 (gt_33_58_n_34), .B0
       (gt_33_58_n_28), .Y (gt_33_58_n_37));
  AOI21X1 gt_33_58_g233(.A0 (gt_33_58_n_25), .A1 (gt_33_58_n_29), .B0
       (gt_33_58_n_33), .Y (gt_33_58_n_35));
  NOR2X1 gt_33_58_g234(.A (gt_33_58_n_23), .B (gt_33_58_n_32), .Y
       (gt_33_58_n_34));
  OAI2BB1X1 gt_33_58_g235(.A0N (gt_33_58_n_19), .A1N (gt_33_58_n_14),
       .B0 (gt_33_58_n_15), .Y (gt_33_58_n_33));
  AOI21X1 gt_33_58_g236(.A0 (gt_33_58_n_2), .A1 (gt_33_58_n_8), .B0
       (gt_33_58_n_11), .Y (gt_33_58_n_32));
  NAND2X2 gt_33_58_g238(.A (gt_33_58_n_18), .B (gt_33_58_n_22), .Y
       (gt_33_58_n_30));
  NAND2X2 gt_33_58_g239(.A (gt_33_58_n_10), .B (gt_33_58_n_21), .Y
       (gt_33_58_n_29));
  NOR2X1 gt_33_58_g240(.A (gt_33_58_n_26), .B (gt_33_58_n_24), .Y
       (gt_33_58_n_28));
  NAND2X1 gt_33_58_g241(.A (gt_33_58_n_15), .B (gt_33_58_n_14), .Y
       (gt_33_58_n_27));
  OAI2BB1X1 gt_33_58_g242(.A0N (in1[4]), .A1N (gt_33_58_n_5), .B0
       (gt_33_58_n_0), .Y (gt_33_58_n_26));
  INVX1 gt_33_58_g243(.A (gt_33_58_n_24), .Y (gt_33_58_n_25));
  NAND2X1 gt_33_58_g244(.A (gt_33_58_n_9), .B (gt_33_58_n_14), .Y
       (gt_33_58_n_24));
  NAND2X1 gt_33_58_g245(.A (gt_33_58_n_1), .B (gt_33_58_n_17), .Y
       (gt_33_58_n_23));
  NAND2X2 gt_33_58_g246(.A (gt_33_58_n_20), .B (gt_33_58_n_1), .Y
       (gt_33_58_n_22));
  NAND2X2 gt_33_58_g247(.A (gt_33_58_n_12), .B (gt_33_58_n_0), .Y
       (gt_33_58_n_21));
  NOR2X2 gt_33_58_g248(.A (in1[2]), .B (gt_33_58_n_7), .Y
       (gt_33_58_n_20));
  NOR2X1 gt_33_58_g250(.A (gt_33_58_n_4), .B (in1[6]), .Y
       (gt_33_58_n_19));
  NAND2BXL gt_33_58_g251(.AN (in1[3]), .B (in2[3]), .Y (gt_33_58_n_18));
  NAND2X1 gt_33_58_g252(.A (in1[2]), .B (gt_33_58_n_7), .Y
       (gt_33_58_n_17));
  INVX2 gt_33_58_g256(.A (gt_33_58_n_13), .Y (gt_33_58_n_14));
  NOR2X1 gt_33_58_g258(.A (gt_33_58_n_5), .B (in1[4]), .Y
       (gt_33_58_n_12));
  NOR2X1 gt_33_58_g259(.A (gt_33_58_n_3), .B (in1[1]), .Y
       (gt_33_58_n_11));
  NAND2BXL gt_33_58_g260(.AN (in1[5]), .B (in2[5]), .Y (gt_33_58_n_10));
  NAND2X1 gt_33_58_g261(.A (in1[6]), .B (gt_33_58_n_4), .Y
       (gt_33_58_n_9));
  NAND2X1 gt_33_58_g262(.A (in1[1]), .B (gt_33_58_n_3), .Y
       (gt_33_58_n_8));
  NAND2X2 gt_33_58_g263(.A (in2[7]), .B (gt_33_58_n_6), .Y
       (gt_33_58_n_15));
  NOR2X4 gt_33_58_g264(.A (in2[7]), .B (gt_33_58_n_6), .Y
       (gt_33_58_n_13));
  INVX1 gt_33_58_g266(.A (in2[2]), .Y (gt_33_58_n_7));
  INVX3 gt_33_58_g268(.A (in1[7]), .Y (gt_33_58_n_6));
  INVX1 gt_33_58_g269(.A (in2[4]), .Y (gt_33_58_n_5));
  INVX1 gt_33_58_g270(.A (in2[6]), .Y (gt_33_58_n_4));
  INVX1 gt_33_58_g271(.A (in2[1]), .Y (gt_33_58_n_3));
  NAND2BX1 gt_33_58_g2(.AN (in2[0]), .B (in1[0]), .Y (gt_33_58_n_2));
  NAND2BX4 gt_33_58_g273(.AN (in2[3]), .B (in1[3]), .Y (gt_33_58_n_1));
  NAND2BX4 gt_33_58_g274(.AN (in2[5]), .B (in1[5]), .Y (gt_33_58_n_0));
  INVXL gt_33_58_g277(.A (gt_33_58_n_14), .Y (gt_33_58_n_57));
endmodule


