`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 17 2020 22:53:44 EST (Nov 18 2020 03:53:44 UTC)

module dut_Add_10Ux8U_10U_1(in2, in1, out1);
  input [9:0] in2;
  input [7:0] in1;
  output [9:0] out1;
  wire [9:0] in2;
  wire [7:0] in1;
  wire [9:0] out1;
  wire add_35_2_n_1, add_35_2_n_2, add_35_2_n_3, add_35_2_n_9,
       add_35_2_n_12, add_35_2_n_14, add_35_2_n_15, add_35_2_n_16;
  wire add_35_2_n_18, add_35_2_n_19, add_35_2_n_20, add_35_2_n_21,
       add_35_2_n_22, add_35_2_n_23, add_35_2_n_24, add_35_2_n_25;
  wire add_35_2_n_26, add_35_2_n_27, add_35_2_n_28, add_35_2_n_29,
       add_35_2_n_30, add_35_2_n_31, add_35_2_n_32, add_35_2_n_33;
  wire add_35_2_n_34, add_35_2_n_35, add_35_2_n_36, add_35_2_n_37,
       add_35_2_n_38, add_35_2_n_39, add_35_2_n_40, add_35_2_n_41;
  wire add_35_2_n_42, add_35_2_n_43, add_35_2_n_44, add_35_2_n_45,
       add_35_2_n_46, add_35_2_n_47, add_35_2_n_48, add_35_2_n_49;
  wire add_35_2_n_50, add_35_2_n_51, add_35_2_n_52, add_35_2_n_53,
       add_35_2_n_54, add_35_2_n_55, add_35_2_n_56, add_35_2_n_57;
  wire add_35_2_n_58, add_35_2_n_59, add_35_2_n_60, add_35_2_n_61,
       add_35_2_n_83, add_35_2_n_84, add_35_2_n_85, add_35_2_n_88;
  wire add_35_2_n_89, add_35_2_n_91, add_35_2_n_93, add_35_2_n_97,
       add_35_2_n_100, add_35_2_n_101, add_35_2_n_102;
  MXI2XL add_35_2_g198(.A (add_35_2_n_14), .B (in2[9]), .S0
       (add_35_2_n_61), .Y (out1[9]));
  MXI2XL add_35_2_g199(.A (in2[8]), .B (add_35_2_n_12), .S0
       (add_35_2_n_60), .Y (out1[8]));
  MXI2XL add_35_2_g201(.A (add_35_2_n_38), .B (add_35_2_n_39), .S0
       (add_35_2_n_59), .Y (out1[5]));
  NOR2X1 add_35_2_g203(.A (add_35_2_n_12), .B (add_35_2_n_60), .Y
       (add_35_2_n_61));
  NOR2X2 add_35_2_g204(.A (add_35_2_n_49), .B (add_35_2_n_55), .Y
       (add_35_2_n_60));
  NOR2BX1 add_35_2_g206(.AN (add_35_2_n_24), .B (add_35_2_n_56), .Y
       (add_35_2_n_59));
  NOR2X1 add_35_2_g209(.A (add_35_2_n_50), .B (add_35_2_n_54), .Y
       (add_35_2_n_58));
  NOR2BX1 add_35_2_g210(.AN (add_35_2_n_31), .B (add_35_2_n_52), .Y
       (add_35_2_n_57));
  NOR2X1 add_35_2_g211(.A (add_35_2_n_25), .B (add_35_2_n_52), .Y
       (add_35_2_n_56));
  NOR2X2 add_35_2_g212(.A (add_35_2_n_45), .B (add_35_2_n_52), .Y
       (add_35_2_n_55));
  NOR2X1 add_35_2_g213(.A (add_35_2_n_46), .B (add_35_2_n_52), .Y
       (add_35_2_n_54));
  NOR2BX1 add_35_2_g214(.AN (add_35_2_n_101), .B (add_35_2_n_3), .Y
       (add_35_2_n_53));
  NOR2X4 add_35_2_g216(.A (add_35_2_n_44), .B (add_35_2_n_51), .Y
       (add_35_2_n_52));
  NOR2X4 add_35_2_g218(.A (add_35_2_n_34), .B (add_35_2_n_48), .Y
       (add_35_2_n_51));
  OAI21X1 add_35_2_g219(.A0 (add_35_2_n_15), .A1 (add_35_2_n_43), .B0
       (add_35_2_n_18), .Y (add_35_2_n_50));
  OAI21X2 add_35_2_g220(.A0 (add_35_2_n_41), .A1 (add_35_2_n_43), .B0
       (add_35_2_n_42), .Y (add_35_2_n_49));
  NOR2X2 add_35_2_g221(.A (add_35_2_n_2), .B (add_35_2_n_47), .Y
       (add_35_2_n_48));
  NOR2X2 add_35_2_g223(.A (add_35_2_n_19), .B (add_35_2_n_22), .Y
       (add_35_2_n_47));
  NAND2BX1 add_35_2_g225(.AN (add_35_2_n_15), .B (add_35_2_n_31), .Y
       (add_35_2_n_46));
  NAND2X1 add_35_2_g226(.A (add_35_2_n_40), .B (add_35_2_n_31), .Y
       (add_35_2_n_45));
  OAI21X2 add_35_2_g227(.A0 (add_35_2_n_16), .A1 (add_35_2_n_20), .B0
       (add_35_2_n_28), .Y (add_35_2_n_44));
  NOR2X1 add_35_2_g229(.A (add_35_2_n_1), .B (add_35_2_n_30), .Y
       (add_35_2_n_43));
  AOI2BB1X1 add_35_2_g230(.A0N (add_35_2_n_18), .A1N (add_35_2_n_21),
       .B0 (add_35_2_n_27), .Y (add_35_2_n_42));
  INVX1 add_35_2_g231(.A (add_35_2_n_40), .Y (add_35_2_n_41));
  INVX1 add_35_2_g232(.A (add_35_2_n_38), .Y (add_35_2_n_39));
  NAND2X2 add_35_2_g236(.A (add_35_2_n_23), .B (add_35_2_n_89), .Y
       (add_35_2_n_34));
  NOR2X1 add_35_2_g237(.A (add_35_2_n_21), .B (add_35_2_n_15), .Y
       (add_35_2_n_40));
  NOR2X1 add_35_2_g238(.A (add_35_2_n_1), .B (add_35_2_n_26), .Y
       (add_35_2_n_38));
  NAND2X1 add_35_2_g239(.A (add_35_2_n_100), .B (add_35_2_n_23), .Y
       (add_35_2_n_37));
  NAND2BX1 add_35_2_g240(.AN (add_35_2_n_25), .B (add_35_2_n_24), .Y
       (add_35_2_n_36));
  NAND2BX1 add_35_2_g241(.AN (add_35_2_n_15), .B (add_35_2_n_18), .Y
       (add_35_2_n_35));
  NOR2X1 add_35_2_g244(.A (add_35_2_n_24), .B (add_35_2_n_26), .Y
       (add_35_2_n_30));
  NAND2X1 add_35_2_g246(.A (add_35_2_n_28), .B (add_35_2_n_88), .Y
       (add_35_2_n_33));
  NOR2X1 add_35_2_g247(.A (add_35_2_n_27), .B (add_35_2_n_21), .Y
       (add_35_2_n_32));
  NOR2X1 add_35_2_g248(.A (add_35_2_n_2), .B (add_35_2_n_22), .Y
       (add_35_2_n_29));
  NOR2X1 add_35_2_g249(.A (add_35_2_n_26), .B (add_35_2_n_25), .Y
       (add_35_2_n_31));
  NAND2X1 add_35_2_g251(.A (in2[3]), .B (in1[3]), .Y (add_35_2_n_28));
  AND2X1 add_35_2_g252(.A (in2[7]), .B (in1[7]), .Y (add_35_2_n_27));
  NOR2X2 add_35_2_g254(.A (in2[5]), .B (in1[5]), .Y (add_35_2_n_26));
  NOR2X1 add_35_2_g255(.A (in2[4]), .B (in1[4]), .Y (add_35_2_n_25));
  NAND2X1 add_35_2_g256(.A (in2[4]), .B (in1[4]), .Y (add_35_2_n_24));
  NAND2X2 add_35_2_g257(.A (add_35_2_n_91), .B (add_35_2_n_93), .Y
       (add_35_2_n_23));
  NOR2X4 add_35_2_g260(.A (in2[1]), .B (in1[1]), .Y (add_35_2_n_22));
  NOR2X1 add_35_2_g261(.A (in2[7]), .B (in1[7]), .Y (add_35_2_n_21));
  NAND2X1 add_35_2_g262(.A (in2[2]), .B (in1[2]), .Y (add_35_2_n_20));
  NAND2X8 add_35_2_g263(.A (in2[0]), .B (in1[0]), .Y (add_35_2_n_19));
  NAND2X1 add_35_2_g264(.A (in2[6]), .B (in1[6]), .Y (add_35_2_n_18));
  NOR2X4 add_35_2_g265(.A (in2[3]), .B (in1[3]), .Y (add_35_2_n_16));
  NOR2X1 add_35_2_g266(.A (in2[6]), .B (in1[6]), .Y (add_35_2_n_15));
  INVXL add_35_2_g269(.A (in2[9]), .Y (add_35_2_n_14));
  INVX1 add_35_2_g272(.A (in2[8]), .Y (add_35_2_n_12));
  XNOR2X1 add_35_2_g2(.A (add_35_2_n_19), .B (add_35_2_n_29), .Y
       (out1[1]));
  NOR2BX2 add_35_2_g276(.AN (add_35_2_n_43), .B (add_35_2_n_57), .Y
       (add_35_2_n_9));
  CLKXOR2X1 add_35_2_g277(.A (add_35_2_n_37), .B (add_35_2_n_83), .Y
       (out1[2]));
  CLKXOR2X1 add_35_2_g278(.A (add_35_2_n_36), .B (add_35_2_n_97), .Y
       (out1[4]));
  CLKXOR2X1 add_35_2_g279(.A (add_35_2_n_35), .B (add_35_2_n_9), .Y
       (out1[6]));
  CLKXOR2X1 add_35_2_g280(.A (add_35_2_n_33), .B (add_35_2_n_53), .Y
       (out1[3]));
  XNOR2XL add_35_2_g281(.A (add_35_2_n_32), .B (add_35_2_n_58), .Y
       (out1[7]));
  NOR2BX1 add_35_2_g282(.AN (add_35_2_n_23), .B (add_35_2_n_84), .Y
       (add_35_2_n_3));
  CLKAND2X6 add_35_2_g283(.A (in2[1]), .B (in1[1]), .Y (add_35_2_n_2));
  AND2X1 add_35_2_g284(.A (in2[5]), .B (in1[5]), .Y (add_35_2_n_1));
  CLKXOR2X1 add_35_2_g285(.A (in2[0]), .B (in1[0]), .Y (out1[0]));
  INVXL add_35_2_fopt(.A (add_35_2_n_85), .Y (add_35_2_n_83));
  INVXL add_35_2_fopt286(.A (add_35_2_n_85), .Y (add_35_2_n_84));
  INVXL add_35_2_fopt287(.A (add_35_2_n_48), .Y (add_35_2_n_85));
  INVXL add_35_2_fopt288(.A (add_35_2_n_16), .Y (add_35_2_n_88));
  CLKINVX2 add_35_2_fopt289(.A (add_35_2_n_16), .Y (add_35_2_n_89));
  CLKINVX4 add_35_2_fopt290(.A (in2[2]), .Y (add_35_2_n_91));
  CLKINVX3 add_35_2_fopt291(.A (in1[2]), .Y (add_35_2_n_93));
  BUFX2 add_35_2_fopt292(.A (add_35_2_n_52), .Y (add_35_2_n_97));
  INVXL add_35_2_fopt293(.A (add_35_2_n_102), .Y (add_35_2_n_100));
  INVXL add_35_2_fopt294(.A (add_35_2_n_102), .Y (add_35_2_n_101));
  INVXL add_35_2_fopt295(.A (add_35_2_n_20), .Y (add_35_2_n_102));
endmodule


