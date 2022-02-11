`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 18 2020 11:31:09 EST (Nov 18 2020 16:31:09 UTC)

module dut_Add_8Ux8U_9U_4(in2, in1, out1);
  input [7:0] in2, in1;
  output [8:0] out1;
  wire [7:0] in2, in1;
  wire [8:0] out1;
  wire add_35_2_n_0, add_35_2_n_1, add_35_2_n_2, add_35_2_n_3,
       add_35_2_n_4, add_35_2_n_5, add_35_2_n_6, add_35_2_n_7;
  wire add_35_2_n_8, add_35_2_n_9, add_35_2_n_10, add_35_2_n_11,
       add_35_2_n_12, add_35_2_n_13, add_35_2_n_14, add_35_2_n_15;
  wire add_35_2_n_16, add_35_2_n_17, add_35_2_n_18, add_35_2_n_19,
       add_35_2_n_20, add_35_2_n_21, add_35_2_n_22, add_35_2_n_24;
  wire add_35_2_n_26, add_35_2_n_28, add_35_2_n_29, add_35_2_n_31,
       add_35_2_n_32, add_35_2_n_34, add_35_2_n_35, add_35_2_n_36;
  wire add_35_2_n_40;
  XNOR2X1 add_35_2_g253(.A (add_35_2_n_17), .B (add_35_2_n_40), .Y
       (out1[7]));
  OAI21X1 add_35_2_g254(.A0 (add_35_2_n_0), .A1 (add_35_2_n_34), .B0
       (add_35_2_n_8), .Y (add_35_2_n_40));
  OAI211X1 add_35_2_g255(.A0 (add_35_2_n_8), .A1 (add_35_2_n_6), .B0
       (add_35_2_n_36), .C0 (add_35_2_n_24), .Y (out1[8]));
  XNOR2X1 add_35_2_g256(.A (add_35_2_n_14), .B (add_35_2_n_34), .Y
       (out1[6]));
  XNOR2X1 add_35_2_g257(.A (add_35_2_n_13), .B (add_35_2_n_35), .Y
       (out1[5]));
  AOI31X1 add_35_2_g258(.A0 (add_35_2_n_18), .A1 (add_35_2_n_16), .A2
       (add_35_2_n_32), .B0 (add_35_2_n_5), .Y (add_35_2_n_36));
  OAI21X1 add_35_2_g259(.A0 (add_35_2_n_7), .A1 (add_35_2_n_31), .B0
       (add_35_2_n_11), .Y (add_35_2_n_35));
  AOI21X1 add_35_2_g260(.A0 (add_35_2_n_16), .A1 (add_35_2_n_32), .B0
       (add_35_2_n_21), .Y (add_35_2_n_34));
  XNOR2X1 add_35_2_g261(.A (add_35_2_n_20), .B (add_35_2_n_31), .Y
       (out1[4]));
  INVX1 add_35_2_g262(.A (add_35_2_n_32), .Y (add_35_2_n_31));
  OAI21X1 add_35_2_g263(.A0 (add_35_2_n_12), .A1 (add_35_2_n_29), .B0
       (add_35_2_n_4), .Y (add_35_2_n_32));
  XNOR2X1 add_35_2_g264(.A (add_35_2_n_19), .B (add_35_2_n_28), .Y
       (out1[3]));
  AOI21X1 add_35_2_g265(.A0 (add_35_2_n_2), .A1 (add_35_2_n_26), .B0
       (add_35_2_n_9), .Y (add_35_2_n_29));
  OAI2BB1X1 add_35_2_g266(.A0N (add_35_2_n_2), .A1N (add_35_2_n_26),
       .B0 (add_35_2_n_10), .Y (add_35_2_n_28));
  XNOR2X1 add_35_2_g267(.A (add_35_2_n_15), .B (add_35_2_n_26), .Y
       (out1[2]));
  ADDFX1 add_35_2_g268(.A (add_35_2_n_22), .B (in1[1]), .CI (in2[1]),
       .CO (add_35_2_n_26), .S (out1[1]));
  NAND2XL add_35_2_g269(.A (add_35_2_n_18), .B (add_35_2_n_21), .Y
       (add_35_2_n_24));
  ADDHX1 add_35_2_g270(.A (in2[0]), .B (in1[0]), .CO (add_35_2_n_22),
       .S (out1[0]));
  OAI21X1 add_35_2_g271(.A0 (add_35_2_n_11), .A1 (add_35_2_n_1), .B0
       (add_35_2_n_3), .Y (add_35_2_n_21));
  NOR2BX1 add_35_2_g272(.AN (add_35_2_n_11), .B (add_35_2_n_7), .Y
       (add_35_2_n_20));
  NAND2BX1 add_35_2_g273(.AN (add_35_2_n_12), .B (add_35_2_n_4), .Y
       (add_35_2_n_19));
  NOR2X1 add_35_2_g274(.A (add_35_2_n_6), .B (add_35_2_n_0), .Y
       (add_35_2_n_18));
  OR2XL add_35_2_g275(.A (add_35_2_n_5), .B (add_35_2_n_6), .Y
       (add_35_2_n_17));
  NOR2X1 add_35_2_g276(.A (add_35_2_n_1), .B (add_35_2_n_7), .Y
       (add_35_2_n_16));
  NAND2X1 add_35_2_g277(.A (add_35_2_n_10), .B (add_35_2_n_2), .Y
       (add_35_2_n_15));
  NOR2BX1 add_35_2_g278(.AN (add_35_2_n_8), .B (add_35_2_n_0), .Y
       (add_35_2_n_14));
  NAND2BX1 add_35_2_g279(.AN (add_35_2_n_1), .B (add_35_2_n_3), .Y
       (add_35_2_n_13));
  INVX1 add_35_2_g280(.A (add_35_2_n_10), .Y (add_35_2_n_9));
  NOR2X1 add_35_2_g281(.A (in2[3]), .B (in1[3]), .Y (add_35_2_n_12));
  NAND2X1 add_35_2_g282(.A (in2[4]), .B (in1[4]), .Y (add_35_2_n_11));
  NAND2X1 add_35_2_g283(.A (in2[2]), .B (in1[2]), .Y (add_35_2_n_10));
  NAND2X1 add_35_2_g284(.A (in2[6]), .B (in1[6]), .Y (add_35_2_n_8));
  NOR2X1 add_35_2_g285(.A (in2[4]), .B (in1[4]), .Y (add_35_2_n_7));
  NOR2X1 add_35_2_g286(.A (in2[7]), .B (in1[7]), .Y (add_35_2_n_6));
  AND2XL add_35_2_g287(.A (in2[7]), .B (in1[7]), .Y (add_35_2_n_5));
  NAND2X1 add_35_2_g288(.A (in2[3]), .B (in1[3]), .Y (add_35_2_n_4));
  NAND2X1 add_35_2_g289(.A (in2[5]), .B (in1[5]), .Y (add_35_2_n_3));
  OR2X1 add_35_2_g290(.A (in2[2]), .B (in1[2]), .Y (add_35_2_n_2));
  NOR2X1 add_35_2_g291(.A (in2[5]), .B (in1[5]), .Y (add_35_2_n_1));
  NOR2X1 add_35_2_g292(.A (in2[6]), .B (in1[6]), .Y (add_35_2_n_0));
endmodule

