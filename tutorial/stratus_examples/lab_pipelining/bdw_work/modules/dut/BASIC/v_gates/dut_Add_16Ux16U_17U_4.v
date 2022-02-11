`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 18 2020 17:49:19 EST (Nov 18 2020 22:49:19 UTC)

module dut_Add_16Ux16U_17U_4(in2, in1, out1);
  input [15:0] in2, in1;
  output [16:0] out1;
  wire [15:0] in2, in1;
  wire [16:0] out1;
  wire add_35_2_n_0, add_35_2_n_1, add_35_2_n_2, add_35_2_n_3,
       add_35_2_n_4, add_35_2_n_5, add_35_2_n_6, add_35_2_n_7;
  wire add_35_2_n_8, add_35_2_n_9, add_35_2_n_10, add_35_2_n_11,
       add_35_2_n_12, add_35_2_n_13, add_35_2_n_14, add_35_2_n_15;
  wire add_35_2_n_16, add_35_2_n_17, add_35_2_n_18, add_35_2_n_19,
       add_35_2_n_20, add_35_2_n_21, add_35_2_n_22, add_35_2_n_23;
  wire add_35_2_n_24, add_35_2_n_25, add_35_2_n_26, add_35_2_n_27,
       add_35_2_n_28, add_35_2_n_29, add_35_2_n_30, add_35_2_n_31;
  wire add_35_2_n_32, add_35_2_n_33, add_35_2_n_34, add_35_2_n_35,
       add_35_2_n_36, add_35_2_n_37, add_35_2_n_38, add_35_2_n_39;
  wire add_35_2_n_40, add_35_2_n_41, add_35_2_n_42, add_35_2_n_43,
       add_35_2_n_44, add_35_2_n_45, add_35_2_n_46, add_35_2_n_48;
  wire add_35_2_n_49, add_35_2_n_50, add_35_2_n_51, add_35_2_n_53,
       add_35_2_n_54, add_35_2_n_55, add_35_2_n_58, add_35_2_n_59;
  wire add_35_2_n_61, add_35_2_n_62, add_35_2_n_63, add_35_2_n_65,
       add_35_2_n_67, add_35_2_n_68, add_35_2_n_69, add_35_2_n_72;
  wire add_35_2_n_73, add_35_2_n_74, add_35_2_n_75, add_35_2_n_79,
       add_35_2_n_81, add_35_2_n_82, add_35_2_n_86;
  XNOR2X1 add_35_2_g542(.A (add_35_2_n_29), .B (add_35_2_n_86), .Y
       (out1[15]));
  OAI21XL add_35_2_g543(.A0 (add_35_2_n_5), .A1 (add_35_2_n_82), .B0
       (add_35_2_n_1), .Y (add_35_2_n_86));
  XNOR2X1 add_35_2_g544(.A (add_35_2_n_28), .B (add_35_2_n_82), .Y
       (out1[14]));
  XNOR2X1 add_35_2_g545(.A (add_35_2_n_26), .B (add_35_2_n_81), .Y
       (out1[13]));
  XNOR2X1 add_35_2_g546(.A (add_35_2_n_33), .B (add_35_2_n_79), .Y
       (out1[11]));
  AOI21X1 add_35_2_g547(.A0 (add_35_2_n_31), .A1 (add_35_2_n_75), .B0
       (add_35_2_n_42), .Y (add_35_2_n_82));
  OAI2BB1X1 add_35_2_g548(.A0N (add_35_2_n_15), .A1N (add_35_2_n_75),
       .B0 (add_35_2_n_8), .Y (add_35_2_n_81));
  XNOR2X1 add_35_2_g549(.A (add_35_2_n_27), .B (add_35_2_n_75), .Y
       (out1[12]));
  OAI21X1 add_35_2_g550(.A0 (add_35_2_n_17), .A1 (add_35_2_n_74), .B0
       (add_35_2_n_16), .Y (add_35_2_n_79));
  OAI21X1 add_35_2_g551(.A0 (add_35_2_n_45), .A1 (add_35_2_n_73), .B0
       (add_35_2_n_54), .Y (out1[16]));
  XNOR2X1 add_35_2_g552(.A (add_35_2_n_36), .B (add_35_2_n_74), .Y
       (out1[10]));
  XNOR2X1 add_35_2_g553(.A (add_35_2_n_35), .B (add_35_2_n_72), .Y
       (out1[9]));
  NAND2BX1 add_35_2_g554(.AN (add_35_2_n_49), .B (add_35_2_n_73), .Y
       (add_35_2_n_75));
  NOR2X1 add_35_2_g555(.A (add_35_2_n_43), .B (add_35_2_n_69), .Y
       (add_35_2_n_74));
  NAND2X1 add_35_2_g556(.A (add_35_2_n_32), .B (add_35_2_n_69), .Y
       (add_35_2_n_73));
  OAI21XL add_35_2_g557(.A0 (add_35_2_n_2), .A1 (add_35_2_n_67), .B0
       (add_35_2_n_6), .Y (add_35_2_n_72));
  XNOR2X1 add_35_2_g558(.A (add_35_2_n_34), .B (add_35_2_n_67), .Y
       (out1[8]));
  XNOR2X1 add_35_2_g559(.A (add_35_2_n_24), .B (add_35_2_n_68), .Y
       (out1[7]));
  NOR3X1 add_35_2_g560(.A (add_35_2_n_67), .B (add_35_2_n_0), .C
       (add_35_2_n_2), .Y (add_35_2_n_69));
  OAI21X1 add_35_2_g561(.A0 (add_35_2_n_19), .A1 (add_35_2_n_63), .B0
       (add_35_2_n_12), .Y (add_35_2_n_68));
  AOI211XL add_35_2_g562(.A0 (add_35_2_n_41), .A1 (add_35_2_n_44), .B0
       (add_35_2_n_65), .C0 (add_35_2_n_30), .Y (add_35_2_n_67));
  XNOR2X1 add_35_2_g563(.A (add_35_2_n_37), .B (add_35_2_n_63), .Y
       (out1[6]));
  OAI2BB1X1 add_35_2_g564(.A0N (add_35_2_n_41), .A1N (add_35_2_n_62),
       .B0 (add_35_2_n_10), .Y (add_35_2_n_65));
  XNOR2X1 add_35_2_g565(.A (add_35_2_n_38), .B (add_35_2_n_61), .Y
       (out1[5]));
  NOR2X1 add_35_2_g566(.A (add_35_2_n_44), .B (add_35_2_n_62), .Y
       (add_35_2_n_63));
  NOR2X1 add_35_2_g567(.A (add_35_2_n_18), .B (add_35_2_n_59), .Y
       (add_35_2_n_62));
  NAND2X1 add_35_2_g568(.A (add_35_2_n_14), .B (add_35_2_n_59), .Y
       (add_35_2_n_61));
  XNOR2X1 add_35_2_g569(.A (add_35_2_n_25), .B (add_35_2_n_58), .Y
       (out1[4]));
  NAND2BX1 add_35_2_g570(.AN (add_35_2_n_22), .B (add_35_2_n_58), .Y
       (add_35_2_n_59));
  ADDFX1 add_35_2_g571(.A (add_35_2_n_55), .B (in1[3]), .CI (in2[3]),
       .CO (add_35_2_n_58), .S (out1[3]));
  ADDFX1 add_35_2_g572(.A (add_35_2_n_51), .B (in1[2]), .CI (in2[2]),
       .CO (add_35_2_n_55), .S (out1[2]));
  AOI211XL add_35_2_g573(.A0 (add_35_2_n_40), .A1 (add_35_2_n_42), .B0
       (add_35_2_n_53), .C0 (add_35_2_n_39), .Y (add_35_2_n_54));
  OAI21X1 add_35_2_g574(.A0 (add_35_2_n_45), .A1 (add_35_2_n_50), .B0
       (add_35_2_n_11), .Y (add_35_2_n_53));
  ADDFX1 add_35_2_g575(.A (add_35_2_n_46), .B (in1[1]), .CI (in2[1]),
       .CO (add_35_2_n_51), .S (out1[1]));
  INVX1 add_35_2_g576(.A (add_35_2_n_49), .Y (add_35_2_n_50));
  OAI211X1 add_35_2_g577(.A0 (add_35_2_n_16), .A1 (add_35_2_n_7), .B0
       (add_35_2_n_48), .C0 (add_35_2_n_20), .Y (add_35_2_n_49));
  NAND2XL add_35_2_g578(.A (add_35_2_n_32), .B (add_35_2_n_43), .Y
       (add_35_2_n_48));
  ADDHX1 add_35_2_g579(.A (in2[0]), .B (in1[0]), .CO (add_35_2_n_46),
       .S (out1[0]));
  NAND2X1 add_35_2_g580(.A (add_35_2_n_40), .B (add_35_2_n_31), .Y
       (add_35_2_n_45));
  OAI21X1 add_35_2_g581(.A0 (add_35_2_n_14), .A1 (add_35_2_n_18), .B0
       (add_35_2_n_21), .Y (add_35_2_n_44));
  OAI21X1 add_35_2_g582(.A0 (add_35_2_n_6), .A1 (add_35_2_n_0), .B0
       (add_35_2_n_23), .Y (add_35_2_n_43));
  OAI21X1 add_35_2_g583(.A0 (add_35_2_n_8), .A1 (add_35_2_n_3), .B0
       (add_35_2_n_9), .Y (add_35_2_n_42));
  NOR2X1 add_35_2_g584(.A (add_35_2_n_1), .B (add_35_2_n_4), .Y
       (add_35_2_n_39));
  NAND2BX1 add_35_2_g585(.AN (add_35_2_n_18), .B (add_35_2_n_21), .Y
       (add_35_2_n_38));
  NOR2X1 add_35_2_g586(.A (add_35_2_n_13), .B (add_35_2_n_19), .Y
       (add_35_2_n_41));
  NOR2BX1 add_35_2_g587(.AN (add_35_2_n_12), .B (add_35_2_n_19), .Y
       (add_35_2_n_37));
  NOR2BX1 add_35_2_g588(.AN (add_35_2_n_16), .B (add_35_2_n_17), .Y
       (add_35_2_n_36));
  NAND2BX1 add_35_2_g589(.AN (add_35_2_n_0), .B (add_35_2_n_23), .Y
       (add_35_2_n_35));
  NOR2BX1 add_35_2_g590(.AN (add_35_2_n_6), .B (add_35_2_n_2), .Y
       (add_35_2_n_34));
  NOR2X1 add_35_2_g591(.A (add_35_2_n_4), .B (add_35_2_n_5), .Y
       (add_35_2_n_40));
  NAND2BX1 add_35_2_g592(.AN (add_35_2_n_7), .B (add_35_2_n_20), .Y
       (add_35_2_n_33));
  NOR2X1 add_35_2_g593(.A (add_35_2_n_12), .B (add_35_2_n_13), .Y
       (add_35_2_n_30));
  NAND2BX1 add_35_2_g594(.AN (add_35_2_n_4), .B (add_35_2_n_11), .Y
       (add_35_2_n_29));
  NOR2X1 add_35_2_g595(.A (add_35_2_n_7), .B (add_35_2_n_17), .Y
       (add_35_2_n_32));
  NOR2BX1 add_35_2_g596(.AN (add_35_2_n_15), .B (add_35_2_n_3), .Y
       (add_35_2_n_31));
  NOR2BX1 add_35_2_g597(.AN (add_35_2_n_1), .B (add_35_2_n_5), .Y
       (add_35_2_n_28));
  NAND2X1 add_35_2_g598(.A (add_35_2_n_8), .B (add_35_2_n_15), .Y
       (add_35_2_n_27));
  NAND2BX1 add_35_2_g599(.AN (add_35_2_n_3), .B (add_35_2_n_9), .Y
       (add_35_2_n_26));
  NAND2BX1 add_35_2_g600(.AN (add_35_2_n_22), .B (add_35_2_n_14), .Y
       (add_35_2_n_25));
  NAND2BX1 add_35_2_g601(.AN (add_35_2_n_13), .B (add_35_2_n_10), .Y
       (add_35_2_n_24));
  NAND2X1 add_35_2_g602(.A (in2[9]), .B (in1[9]), .Y (add_35_2_n_23));
  NOR2X1 add_35_2_g603(.A (in2[4]), .B (in1[4]), .Y (add_35_2_n_22));
  NAND2X1 add_35_2_g604(.A (in2[5]), .B (in1[5]), .Y (add_35_2_n_21));
  NAND2X1 add_35_2_g605(.A (in2[11]), .B (in1[11]), .Y (add_35_2_n_20));
  NOR2X1 add_35_2_g606(.A (in2[6]), .B (in1[6]), .Y (add_35_2_n_19));
  NOR2X1 add_35_2_g607(.A (in2[5]), .B (in1[5]), .Y (add_35_2_n_18));
  NOR2X1 add_35_2_g608(.A (in2[10]), .B (in1[10]), .Y (add_35_2_n_17));
  NAND2X1 add_35_2_g609(.A (in2[10]), .B (in1[10]), .Y (add_35_2_n_16));
  OR2XL add_35_2_g610(.A (in2[12]), .B (in1[12]), .Y (add_35_2_n_15));
  NAND2X1 add_35_2_g611(.A (in2[4]), .B (in1[4]), .Y (add_35_2_n_14));
  NOR2X1 add_35_2_g612(.A (in2[7]), .B (in1[7]), .Y (add_35_2_n_13));
  NAND2X1 add_35_2_g613(.A (in2[6]), .B (in1[6]), .Y (add_35_2_n_12));
  NAND2X1 add_35_2_g614(.A (in2[15]), .B (in1[15]), .Y (add_35_2_n_11));
  NAND2X1 add_35_2_g615(.A (in2[7]), .B (in1[7]), .Y (add_35_2_n_10));
  NAND2X1 add_35_2_g616(.A (in2[13]), .B (in1[13]), .Y (add_35_2_n_9));
  NAND2X1 add_35_2_g617(.A (in2[12]), .B (in1[12]), .Y (add_35_2_n_8));
  NOR2X1 add_35_2_g618(.A (in2[11]), .B (in1[11]), .Y (add_35_2_n_7));
  NAND2X1 add_35_2_g619(.A (in2[8]), .B (in1[8]), .Y (add_35_2_n_6));
  NOR2X1 add_35_2_g620(.A (in2[14]), .B (in1[14]), .Y (add_35_2_n_5));
  NOR2X1 add_35_2_g621(.A (in2[15]), .B (in1[15]), .Y (add_35_2_n_4));
  NOR2X1 add_35_2_g622(.A (in2[13]), .B (in1[13]), .Y (add_35_2_n_3));
  NOR2X1 add_35_2_g623(.A (in2[8]), .B (in1[8]), .Y (add_35_2_n_2));
  NAND2X1 add_35_2_g624(.A (in2[14]), .B (in1[14]), .Y (add_35_2_n_1));
  NOR2X1 add_35_2_g625(.A (in2[9]), .B (in1[9]), .Y (add_35_2_n_0));
endmodule

