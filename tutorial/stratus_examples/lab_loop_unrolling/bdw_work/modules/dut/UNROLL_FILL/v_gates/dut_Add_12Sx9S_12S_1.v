`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 17 2020 22:52:57 EST (Nov 18 2020 03:52:57 UTC)

module dut_Add_12Sx9S_12S_1(in2, in1, out1);
  input [11:0] in2;
  input [8:0] in1;
  output [11:0] out1;
  wire [11:0] in2;
  wire [8:0] in1;
  wire [11:0] out1;
  wire add_35_2_n_1, add_35_2_n_11, add_35_2_n_12, add_35_2_n_13,
       add_35_2_n_14, add_35_2_n_15, add_35_2_n_16, add_35_2_n_17;
  wire add_35_2_n_18, add_35_2_n_19, add_35_2_n_20, add_35_2_n_21,
       add_35_2_n_22, add_35_2_n_23, add_35_2_n_24, add_35_2_n_25;
  wire add_35_2_n_26, add_35_2_n_28, add_35_2_n_29, add_35_2_n_30,
       add_35_2_n_31, add_35_2_n_32, add_35_2_n_33, add_35_2_n_34;
  wire add_35_2_n_35, add_35_2_n_36, add_35_2_n_37, add_35_2_n_38,
       add_35_2_n_39, add_35_2_n_40, add_35_2_n_41, add_35_2_n_42;
  wire add_35_2_n_43, add_35_2_n_44, add_35_2_n_45, add_35_2_n_46,
       add_35_2_n_47, add_35_2_n_48, add_35_2_n_49, add_35_2_n_50;
  wire add_35_2_n_51, add_35_2_n_52, add_35_2_n_53, add_35_2_n_54,
       add_35_2_n_55, add_35_2_n_56, add_35_2_n_57, add_35_2_n_58;
  wire add_35_2_n_59, add_35_2_n_60, add_35_2_n_61, add_35_2_n_62,
       add_35_2_n_63, add_35_2_n_64, add_35_2_n_65, add_35_2_n_67;
  wire add_35_2_n_68, add_35_2_n_69, add_35_2_n_70, add_35_2_n_71,
       add_35_2_n_72, add_35_2_n_73, add_35_2_n_75, add_35_2_n_76;
  wire add_35_2_n_77, add_35_2_n_101, add_35_2_n_102, add_35_2_n_103,
       add_35_2_n_109, add_35_2_n_110, add_35_2_n_113, add_35_2_n_117;
  wire add_35_2_n_118, add_35_2_n_119, add_35_2_n_120, add_35_2_n_121,
       add_35_2_n_122;
  MXI2XL add_35_2_g261(.A (add_35_2_n_50), .B (add_35_2_n_49), .S0
       (add_35_2_n_77), .Y (out1[10]));
  MXI2XL add_35_2_g262(.A (add_35_2_n_52), .B (add_35_2_n_51), .S0
       (add_35_2_n_76), .Y (out1[9]));
  OAI21X1 add_35_2_g263(.A0 (add_35_2_n_41), .A1 (add_35_2_n_102), .B0
       (add_35_2_n_54), .Y (add_35_2_n_77));
  OAI21X1 add_35_2_g264(.A0 (add_35_2_n_14), .A1 (add_35_2_n_102), .B0
       (add_35_2_n_31), .Y (add_35_2_n_76));
  OAI21X2 add_35_2_g265(.A0 (add_35_2_n_61), .A1 (add_35_2_n_103), .B0
       (add_35_2_n_65), .Y (add_35_2_n_75));
  OAI21X2 add_35_2_g271(.A0 (add_35_2_n_59), .A1 (add_35_2_n_68), .B0
       (add_35_2_n_63), .Y (add_35_2_n_73));
  OAI21X1 add_35_2_g272(.A0 (add_35_2_n_38), .A1 (add_35_2_n_113), .B0
       (add_35_2_n_58), .Y (add_35_2_n_72));
  OAI21X1 add_35_2_g273(.A0 (add_35_2_n_19), .A1 (add_35_2_n_113), .B0
       (add_35_2_n_15), .Y (add_35_2_n_71));
  OAI21X1 add_35_2_g276(.A0 (add_35_2_n_60), .A1 (add_35_2_n_113), .B0
       (add_35_2_n_64), .Y (add_35_2_n_70));
  OAI21X1 add_35_2_g277(.A0 (add_35_2_n_110), .A1 (add_35_2_n_118), .B0
       (add_35_2_n_17), .Y (add_35_2_n_69));
  NOR2X4 add_35_2_g280(.A (add_35_2_n_56), .B (add_35_2_n_67), .Y
       (add_35_2_n_68));
  NOR2X4 add_35_2_g281(.A (add_35_2_n_45), .B (add_35_2_n_118), .Y
       (add_35_2_n_67));
  OA21X1 add_35_2_g283(.A0 (add_35_2_n_30), .A1 (add_35_2_n_54), .B0
       (add_35_2_n_34), .Y (add_35_2_n_65));
  AOI2BB1X1 add_35_2_g284(.A0N (add_35_2_n_120), .A1N (add_35_2_n_58),
       .B0 (add_35_2_n_22), .Y (add_35_2_n_64));
  AOI21X2 add_35_2_g285(.A0 (add_35_2_n_53), .A1 (add_35_2_n_57), .B0
       (add_35_2_n_55), .Y (add_35_2_n_63));
  OAI21X4 add_35_2_g286(.A0 (add_35_2_n_16), .A1 (add_35_2_n_36), .B0
       (add_35_2_n_35), .Y (add_35_2_n_62));
  OR2XL add_35_2_g289(.A (add_35_2_n_30), .B (add_35_2_n_41), .Y
       (add_35_2_n_61));
  OR2XL add_35_2_g290(.A (add_35_2_n_121), .B (add_35_2_n_38), .Y
       (add_35_2_n_60));
  NAND2X1 add_35_2_g291(.A (add_35_2_n_53), .B (add_35_2_n_37), .Y
       (add_35_2_n_59));
  INVX1 add_35_2_g292(.A (add_35_2_n_57), .Y (add_35_2_n_58));
  OAI21X2 add_35_2_g293(.A0 (add_35_2_n_15), .A1 (add_35_2_n_20), .B0
       (add_35_2_n_33), .Y (add_35_2_n_57));
  OAI21X2 add_35_2_g294(.A0 (add_35_2_n_17), .A1 (add_35_2_n_28), .B0
       (add_35_2_n_32), .Y (add_35_2_n_56));
  OAI21X1 add_35_2_g295(.A0 (add_35_2_n_21), .A1 (add_35_2_n_25), .B0
       (add_35_2_n_24), .Y (add_35_2_n_55));
  OA21X1 add_35_2_g296(.A0 (add_35_2_n_31), .A1 (add_35_2_n_18), .B0
       (add_35_2_n_23), .Y (add_35_2_n_54));
  INVX1 add_35_2_g297(.A (add_35_2_n_51), .Y (add_35_2_n_52));
  INVX1 add_35_2_g298(.A (add_35_2_n_49), .Y (add_35_2_n_50));
  NAND2X2 add_35_2_g302(.A (add_35_2_n_29), .B (add_35_2_n_26), .Y
       (add_35_2_n_45));
  NOR2X1 add_35_2_g303(.A (add_35_2_n_25), .B (add_35_2_n_13), .Y
       (add_35_2_n_53));
  NOR2BX1 add_35_2_g304(.AN (add_35_2_n_23), .B (add_35_2_n_18), .Y
       (add_35_2_n_51));
  NOR2BX1 add_35_2_g305(.AN (add_35_2_n_34), .B (add_35_2_n_30), .Y
       (add_35_2_n_49));
  NAND2BX1 add_35_2_g307(.AN (add_35_2_n_19), .B (add_35_2_n_15), .Y
       (add_35_2_n_48));
  NAND2X1 add_35_2_g308(.A (add_35_2_n_17), .B (add_35_2_n_109), .Y
       (add_35_2_n_47));
  NAND2BX1 add_35_2_g309(.AN (add_35_2_n_14), .B (add_35_2_n_31), .Y
       (add_35_2_n_46));
  INVX1 add_35_2_g315(.A (add_35_2_n_37), .Y (add_35_2_n_38));
  NOR2BX1 add_35_2_g317(.AN (add_35_2_n_24), .B (add_35_2_n_25), .Y
       (add_35_2_n_44));
  NOR2BX1 add_35_2_g318(.AN (add_35_2_n_33), .B (add_35_2_n_20), .Y
       (add_35_2_n_43));
  NOR2X1 add_35_2_g319(.A (add_35_2_n_22), .B (add_35_2_n_119), .Y
       (add_35_2_n_42));
  OR2XL add_35_2_g320(.A (add_35_2_n_18), .B (add_35_2_n_14), .Y
       (add_35_2_n_41));
  NAND2X1 add_35_2_g321(.A (add_35_2_n_32), .B (add_35_2_n_29), .Y
       (add_35_2_n_40));
  XNOR2X1 add_35_2_g322(.A (in2[11]), .B (in1[8]), .Y (add_35_2_n_39));
  NOR2X1 add_35_2_g323(.A (add_35_2_n_20), .B (add_35_2_n_19), .Y
       (add_35_2_n_37));
  INVX1 add_35_2_g325(.A (add_35_2_n_28), .Y (add_35_2_n_29));
  NOR2X8 add_35_2_g327(.A (in2[1]), .B (in1[1]), .Y (add_35_2_n_36));
  NAND2X2 add_35_2_g328(.A (in2[1]), .B (in1[1]), .Y (add_35_2_n_35));
  NAND2X1 add_35_2_g329(.A (in2[10]), .B (in1[8]), .Y (add_35_2_n_34));
  NAND2X1 add_35_2_g330(.A (in2[5]), .B (in1[5]), .Y (add_35_2_n_33));
  NAND2X1 add_35_2_g331(.A (in2[3]), .B (in1[3]), .Y (add_35_2_n_32));
  NAND2X1 add_35_2_g332(.A (in2[8]), .B (in1[8]), .Y (add_35_2_n_31));
  NOR2X1 add_35_2_g333(.A (in2[10]), .B (in1[8]), .Y (add_35_2_n_30));
  NOR2X4 add_35_2_g334(.A (in2[3]), .B (in1[3]), .Y (add_35_2_n_28));
  NAND2X2 add_35_2_g335(.A (add_35_2_n_12), .B (add_35_2_n_11), .Y
       (add_35_2_n_26));
  NOR2X2 add_35_2_g336(.A (in2[7]), .B (in1[7]), .Y (add_35_2_n_25));
  INVX1 add_35_2_g337(.A (add_35_2_n_21), .Y (add_35_2_n_22));
  NAND2X1 add_35_2_g338(.A (in2[7]), .B (in1[7]), .Y (add_35_2_n_24));
  NAND2X1 add_35_2_g339(.A (in2[9]), .B (in1[8]), .Y (add_35_2_n_23));
  NAND2X1 add_35_2_g340(.A (in2[6]), .B (in1[6]), .Y (add_35_2_n_21));
  NOR2X4 add_35_2_g341(.A (in2[5]), .B (in1[5]), .Y (add_35_2_n_20));
  NOR2X1 add_35_2_g342(.A (in2[4]), .B (in1[4]), .Y (add_35_2_n_19));
  NOR2X1 add_35_2_g343(.A (in2[9]), .B (in1[8]), .Y (add_35_2_n_18));
  NAND2X2 add_35_2_g344(.A (in2[2]), .B (in1[2]), .Y (add_35_2_n_17));
  NAND2X4 add_35_2_g345(.A (in2[0]), .B (in1[0]), .Y (add_35_2_n_16));
  NAND2X2 add_35_2_g346(.A (in2[4]), .B (in1[4]), .Y (add_35_2_n_15));
  NOR2X1 add_35_2_g347(.A (in2[8]), .B (in1[8]), .Y (add_35_2_n_14));
  NOR2X1 add_35_2_g348(.A (in2[6]), .B (in1[6]), .Y (add_35_2_n_13));
  CLKINVX2 add_35_2_g349(.A (in2[2]), .Y (add_35_2_n_12));
  INVX1 add_35_2_g350(.A (in1[2]), .Y (add_35_2_n_11));
  CLKXOR2X1 add_35_2_g2(.A (add_35_2_n_48), .B (add_35_2_n_113), .Y
       (out1[4]));
  XNOR2X1 add_35_2_g352(.A (add_35_2_n_16), .B (add_35_2_n_1), .Y
       (out1[1]));
  XNOR2X1 add_35_2_g353(.A (add_35_2_n_47), .B (add_35_2_n_117), .Y
       (out1[2]));
  XNOR2X1 add_35_2_g354(.A (add_35_2_n_46), .B (add_35_2_n_101), .Y
       (out1[8]));
  XOR2XL add_35_2_g355(.A (add_35_2_n_44), .B (add_35_2_n_70), .Y
       (out1[7]));
  XOR2XL add_35_2_g356(.A (add_35_2_n_43), .B (add_35_2_n_71), .Y
       (out1[5]));
  XOR2XL add_35_2_g357(.A (add_35_2_n_42), .B (add_35_2_n_72), .Y
       (out1[6]));
  XNOR2X1 add_35_2_g358(.A (add_35_2_n_40), .B (add_35_2_n_69), .Y
       (out1[3]));
  XNOR2XL add_35_2_g359(.A (add_35_2_n_39), .B (add_35_2_n_75), .Y
       (out1[11]));
  NOR2BX1 add_35_2_g360(.AN (add_35_2_n_35), .B (add_35_2_n_36), .Y
       (add_35_2_n_1));
  CLKXOR2X1 add_35_2_g361(.A (in2[0]), .B (in1[0]), .Y (out1[0]));
  INVXL add_35_2_fopt(.A (add_35_2_n_102), .Y (add_35_2_n_101));
  CLKINVX1 add_35_2_fopt362(.A (add_35_2_n_73), .Y (add_35_2_n_102));
  CLKINVX2 add_35_2_fopt363(.A (add_35_2_n_73), .Y (add_35_2_n_103));
  CLKINVX1 add_35_2_fopt367(.A (add_35_2_n_110), .Y (add_35_2_n_109));
  CLKINVX1 add_35_2_fopt368(.A (add_35_2_n_26), .Y (add_35_2_n_110));
  BUFX3 add_35_2_fopt369(.A (add_35_2_n_68), .Y (add_35_2_n_113));
  INVXL add_35_2_fopt370(.A (add_35_2_n_118), .Y (add_35_2_n_117));
  CLKINVX4 add_35_2_fopt371(.A (add_35_2_n_62), .Y (add_35_2_n_118));
  BUFX2 add_35_2_fopt372(.A (add_35_2_n_120), .Y (add_35_2_n_119));
  INVXL add_35_2_fopt373(.A (add_35_2_n_122), .Y (add_35_2_n_120));
  INVXL add_35_2_fopt374(.A (add_35_2_n_122), .Y (add_35_2_n_121));
  INVXL add_35_2_fopt375(.A (add_35_2_n_13), .Y (add_35_2_n_122));
endmodule

