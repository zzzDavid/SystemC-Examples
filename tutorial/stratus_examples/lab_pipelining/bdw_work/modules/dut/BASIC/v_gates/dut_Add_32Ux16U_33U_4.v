`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 18 2020 17:49:00 EST (Nov 18 2020 22:49:00 UTC)

module dut_Add_32Ux16U_33U_4(in2, in1, out1);
  input [31:0] in2;
  input [15:0] in1;
  output [32:0] out1;
  wire [31:0] in2;
  wire [15:0] in1;
  wire [32:0] out1;
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
       add_35_2_n_44, add_35_2_n_45, add_35_2_n_46, add_35_2_n_47;
  wire add_35_2_n_48, add_35_2_n_50, add_35_2_n_51, add_35_2_n_52,
       add_35_2_n_53, add_35_2_n_55, add_35_2_n_56, add_35_2_n_57;
  wire add_35_2_n_60, add_35_2_n_61, add_35_2_n_63, add_35_2_n_64,
       add_35_2_n_65, add_35_2_n_67, add_35_2_n_69, add_35_2_n_70;
  wire add_35_2_n_71, add_35_2_n_74, add_35_2_n_75, add_35_2_n_76,
       add_35_2_n_77, add_35_2_n_80, add_35_2_n_81, add_35_2_n_82;
  wire add_35_2_n_84, add_35_2_n_85, add_35_2_n_86, add_35_2_n_87,
       add_35_2_n_88, add_35_2_n_91, add_35_2_n_92, add_35_2_n_93;
  wire add_35_2_n_98, add_35_2_n_99, add_35_2_n_105, add_35_2_n_107,
       add_35_2_n_108, add_35_2_n_110, add_35_2_n_113, add_35_2_n_115;
  wire add_35_2_n_117, add_35_2_n_119;
  ADDHX1 add_35_2_g966(.A (in2[31]), .B (add_35_2_n_119), .CO
       (out1[32]), .S (out1[31]));
  ADDHX1 add_35_2_g967(.A (in2[30]), .B (add_35_2_n_117), .CO
       (add_35_2_n_119), .S (out1[30]));
  ADDHX1 add_35_2_g968(.A (in2[29]), .B (add_35_2_n_115), .CO
       (add_35_2_n_117), .S (out1[29]));
  ADDHX1 add_35_2_g969(.A (in2[28]), .B (add_35_2_n_113), .CO
       (add_35_2_n_115), .S (out1[28]));
  ADDHX1 add_35_2_g970(.A (in2[27]), .B (add_35_2_n_110), .CO
       (add_35_2_n_113), .S (out1[27]));
  XNOR2X1 add_35_2_g971(.A (in2[25]), .B (add_35_2_n_108), .Y
       (out1[25]));
  ADDHX1 add_35_2_g972(.A (in2[26]), .B (add_35_2_n_107), .CO
       (add_35_2_n_110), .S (out1[26]));
  XNOR2X1 add_35_2_g973(.A (in2[24]), .B (add_35_2_n_105), .Y
       (out1[24]));
  NAND2BX1 add_35_2_g974(.AN (add_35_2_n_105), .B (in2[24]), .Y
       (add_35_2_n_108));
  NOR2X1 add_35_2_g975(.A (add_35_2_n_0), .B (add_35_2_n_105), .Y
       (add_35_2_n_107));
  XNOR2X1 add_35_2_g976(.A (in2[23]), .B (add_35_2_n_99), .Y
       (out1[23]));
  NAND2BX1 add_35_2_g977(.AN (add_35_2_n_99), .B (in2[23]), .Y
       (add_35_2_n_105));
  XNOR2X1 add_35_2_g978(.A (in2[19]), .B (add_35_2_n_92), .Y
       (out1[19]));
  XNOR2X1 add_35_2_g979(.A (in2[21]), .B (add_35_2_n_93), .Y
       (out1[21]));
  XNOR2X1 add_35_2_g980(.A (in2[17]), .B (add_35_2_n_87), .Y
       (out1[17]));
  XNOR2X1 add_35_2_g981(.A (add_35_2_n_28), .B (add_35_2_n_98), .Y
       (out1[15]));
  XNOR2X1 add_35_2_g982(.A (in2[22]), .B (add_35_2_n_91), .Y
       (out1[22]));
  NAND2BX1 add_35_2_g983(.AN (add_35_2_n_91), .B (in2[22]), .Y
       (add_35_2_n_99));
  OAI21XL add_35_2_g984(.A0 (add_35_2_n_17), .A1 (add_35_2_n_85), .B0
       (add_35_2_n_1), .Y (add_35_2_n_98));
  XNOR2X1 add_35_2_g985(.A (in2[20]), .B (add_35_2_n_86), .Y
       (out1[20]));
  XNOR2X1 add_35_2_g986(.A (add_35_2_n_29), .B (add_35_2_n_85), .Y
       (out1[14]));
  XNOR2X1 add_35_2_g987(.A (add_35_2_n_31), .B (add_35_2_n_84), .Y
       (out1[13]));
  XNOR2X1 add_35_2_g988(.A (in2[18]), .B (add_35_2_n_88), .Y
       (out1[18]));
  NAND2BX1 add_35_2_g989(.AN (add_35_2_n_86), .B (in2[20]), .Y
       (add_35_2_n_93));
  NAND2BX1 add_35_2_g990(.AN (add_35_2_n_88), .B (in2[18]), .Y
       (add_35_2_n_92));
  NAND3BXL add_35_2_g991(.AN (add_35_2_n_86), .B (in2[21]), .C
       (in2[20]), .Y (add_35_2_n_91));
  XNOR2X1 add_35_2_g992(.A (add_35_2_n_27), .B (add_35_2_n_80), .Y
       (out1[11]));
  XNOR2X1 add_35_2_g993(.A (in2[16]), .B (add_35_2_n_81), .Y
       (out1[16]));
  OR2XL add_35_2_g994(.A (add_35_2_n_25), .B (add_35_2_n_81), .Y
       (add_35_2_n_88));
  NAND2X1 add_35_2_g995(.A (in2[16]), .B (add_35_2_n_82), .Y
       (add_35_2_n_87));
  NAND4BX1 add_35_2_g996(.AN (add_35_2_n_25), .B (add_35_2_n_82), .C
       (in2[18]), .D (in2[19]), .Y (add_35_2_n_86));
  AOI21X1 add_35_2_g997(.A0 (add_35_2_n_33), .A1 (add_35_2_n_77), .B0
       (add_35_2_n_45), .Y (add_35_2_n_85));
  OAI2BB1X1 add_35_2_g998(.A0N (add_35_2_n_13), .A1N (add_35_2_n_77),
       .B0 (add_35_2_n_8), .Y (add_35_2_n_84));
  XNOR2X1 add_35_2_g999(.A (add_35_2_n_26), .B (add_35_2_n_77), .Y
       (out1[12]));
  INVX1 add_35_2_g1000(.A (add_35_2_n_82), .Y (add_35_2_n_81));
  OAI21X1 add_35_2_g1001(.A0 (add_35_2_n_47), .A1 (add_35_2_n_76), .B0
       (add_35_2_n_56), .Y (add_35_2_n_82));
  OAI21X1 add_35_2_g1002(.A0 (add_35_2_n_2), .A1 (add_35_2_n_75), .B0
       (add_35_2_n_21), .Y (add_35_2_n_80));
  XNOR2X1 add_35_2_g1003(.A (add_35_2_n_35), .B (add_35_2_n_75), .Y
       (out1[10]));
  XNOR2X1 add_35_2_g1004(.A (add_35_2_n_30), .B (add_35_2_n_74), .Y
       (out1[9]));
  NAND2BX1 add_35_2_g1005(.AN (add_35_2_n_51), .B (add_35_2_n_76), .Y
       (add_35_2_n_77));
  NAND2X1 add_35_2_g1006(.A (add_35_2_n_43), .B (add_35_2_n_71), .Y
       (add_35_2_n_76));
  NOR2X1 add_35_2_g1007(.A (add_35_2_n_46), .B (add_35_2_n_71), .Y
       (add_35_2_n_75));
  OAI21XL add_35_2_g1008(.A0 (add_35_2_n_4), .A1 (add_35_2_n_69), .B0
       (add_35_2_n_5), .Y (add_35_2_n_74));
  XNOR2X1 add_35_2_g1009(.A (add_35_2_n_36), .B (add_35_2_n_69), .Y
       (out1[8]));
  XNOR2X1 add_35_2_g1010(.A (add_35_2_n_40), .B (add_35_2_n_70), .Y
       (out1[7]));
  NOR3X1 add_35_2_g1011(.A (add_35_2_n_69), .B (add_35_2_n_19), .C
       (add_35_2_n_4), .Y (add_35_2_n_71));
  OAI21X1 add_35_2_g1012(.A0 (add_35_2_n_14), .A1 (add_35_2_n_65), .B0
       (add_35_2_n_3), .Y (add_35_2_n_70));
  AOI211XL add_35_2_g1013(.A0 (add_35_2_n_42), .A1 (add_35_2_n_44), .B0
       (add_35_2_n_67), .C0 (add_35_2_n_32), .Y (add_35_2_n_69));
  XNOR2X1 add_35_2_g1014(.A (add_35_2_n_39), .B (add_35_2_n_65), .Y
       (out1[6]));
  OAI2BB1X1 add_35_2_g1015(.A0N (add_35_2_n_42), .A1N (add_35_2_n_64),
       .B0 (add_35_2_n_23), .Y (add_35_2_n_67));
  XNOR2X1 add_35_2_g1016(.A (add_35_2_n_38), .B (add_35_2_n_63), .Y
       (out1[5]));
  NOR2X1 add_35_2_g1017(.A (add_35_2_n_44), .B (add_35_2_n_64), .Y
       (add_35_2_n_65));
  NOR2X1 add_35_2_g1018(.A (add_35_2_n_16), .B (add_35_2_n_61), .Y
       (add_35_2_n_64));
  NAND2X1 add_35_2_g1019(.A (add_35_2_n_7), .B (add_35_2_n_61), .Y
       (add_35_2_n_63));
  XNOR2X1 add_35_2_g1020(.A (add_35_2_n_37), .B (add_35_2_n_60), .Y
       (out1[4]));
  NAND2BX1 add_35_2_g1021(.AN (add_35_2_n_10), .B (add_35_2_n_60), .Y
       (add_35_2_n_61));
  ADDFX1 add_35_2_g1022(.A (add_35_2_n_57), .B (in1[3]), .CI (in2[3]),
       .CO (add_35_2_n_60), .S (out1[3]));
  ADDFX1 add_35_2_g1023(.A (add_35_2_n_53), .B (in1[2]), .CI (in2[2]),
       .CO (add_35_2_n_57), .S (out1[2]));
  AOI211XL add_35_2_g1024(.A0 (add_35_2_n_34), .A1 (add_35_2_n_45), .B0
       (add_35_2_n_55), .C0 (add_35_2_n_41), .Y (add_35_2_n_56));
  OAI21XL add_35_2_g1025(.A0 (add_35_2_n_47), .A1 (add_35_2_n_52), .B0
       (add_35_2_n_9), .Y (add_35_2_n_55));
  ADDFX1 add_35_2_g1026(.A (add_35_2_n_48), .B (in1[1]), .CI (in2[1]),
       .CO (add_35_2_n_53), .S (out1[1]));
  INVX1 add_35_2_g1027(.A (add_35_2_n_51), .Y (add_35_2_n_52));
  OAI211X1 add_35_2_g1028(.A0 (add_35_2_n_21), .A1 (add_35_2_n_15), .B0
       (add_35_2_n_50), .C0 (add_35_2_n_24), .Y (add_35_2_n_51));
  NAND2X1 add_35_2_g1029(.A (add_35_2_n_43), .B (add_35_2_n_46), .Y
       (add_35_2_n_50));
  ADDHX1 add_35_2_g1030(.A (in2[0]), .B (in1[0]), .CO (add_35_2_n_48),
       .S (out1[0]));
  NAND2X1 add_35_2_g1031(.A (add_35_2_n_34), .B (add_35_2_n_33), .Y
       (add_35_2_n_47));
  OAI21X1 add_35_2_g1032(.A0 (add_35_2_n_5), .A1 (add_35_2_n_19), .B0
       (add_35_2_n_22), .Y (add_35_2_n_46));
  OAI21X1 add_35_2_g1033(.A0 (add_35_2_n_8), .A1 (add_35_2_n_18), .B0
       (add_35_2_n_11), .Y (add_35_2_n_45));
  OAI21X1 add_35_2_g1034(.A0 (add_35_2_n_7), .A1 (add_35_2_n_16), .B0
       (add_35_2_n_12), .Y (add_35_2_n_44));
  NOR2X1 add_35_2_g1035(.A (add_35_2_n_1), .B (add_35_2_n_20), .Y
       (add_35_2_n_41));
  NOR2X1 add_35_2_g1036(.A (add_35_2_n_15), .B (add_35_2_n_2), .Y
       (add_35_2_n_43));
  NOR2X1 add_35_2_g1037(.A (add_35_2_n_6), .B (add_35_2_n_14), .Y
       (add_35_2_n_42));
  NAND2BX1 add_35_2_g1038(.AN (add_35_2_n_6), .B (add_35_2_n_23), .Y
       (add_35_2_n_40));
  NOR2BX1 add_35_2_g1039(.AN (add_35_2_n_3), .B (add_35_2_n_14), .Y
       (add_35_2_n_39));
  NAND2BX1 add_35_2_g1040(.AN (add_35_2_n_16), .B (add_35_2_n_12), .Y
       (add_35_2_n_38));
  NAND2BX1 add_35_2_g1041(.AN (add_35_2_n_10), .B (add_35_2_n_7), .Y
       (add_35_2_n_37));
  NOR2BX1 add_35_2_g1042(.AN (add_35_2_n_5), .B (add_35_2_n_4), .Y
       (add_35_2_n_36));
  NOR2BX1 add_35_2_g1043(.AN (add_35_2_n_21), .B (add_35_2_n_2), .Y
       (add_35_2_n_35));
  NOR2X1 add_35_2_g1044(.A (add_35_2_n_3), .B (add_35_2_n_6), .Y
       (add_35_2_n_32));
  NAND2BX1 add_35_2_g1045(.AN (add_35_2_n_18), .B (add_35_2_n_11), .Y
       (add_35_2_n_31));
  NAND2BX1 add_35_2_g1046(.AN (add_35_2_n_19), .B (add_35_2_n_22), .Y
       (add_35_2_n_30));
  NOR2X1 add_35_2_g1047(.A (add_35_2_n_20), .B (add_35_2_n_17), .Y
       (add_35_2_n_34));
  NOR2BX1 add_35_2_g1048(.AN (add_35_2_n_1), .B (add_35_2_n_17), .Y
       (add_35_2_n_29));
  NAND2BX1 add_35_2_g1049(.AN (add_35_2_n_20), .B (add_35_2_n_9), .Y
       (add_35_2_n_28));
  NAND2BX1 add_35_2_g1050(.AN (add_35_2_n_15), .B (add_35_2_n_24), .Y
       (add_35_2_n_27));
  NOR2BX1 add_35_2_g1051(.AN (add_35_2_n_13), .B (add_35_2_n_18), .Y
       (add_35_2_n_33));
  NAND2X1 add_35_2_g1052(.A (add_35_2_n_8), .B (add_35_2_n_13), .Y
       (add_35_2_n_26));
  NAND2X1 add_35_2_g1053(.A (in2[17]), .B (in2[16]), .Y
       (add_35_2_n_25));
  NAND2X1 add_35_2_g1054(.A (in2[11]), .B (in1[11]), .Y
       (add_35_2_n_24));
  NAND2X1 add_35_2_g1055(.A (in2[7]), .B (in1[7]), .Y (add_35_2_n_23));
  NAND2X1 add_35_2_g1056(.A (in2[9]), .B (in1[9]), .Y (add_35_2_n_22));
  NAND2X1 add_35_2_g1057(.A (in2[10]), .B (in1[10]), .Y
       (add_35_2_n_21));
  NOR2X1 add_35_2_g1058(.A (in2[15]), .B (in1[15]), .Y (add_35_2_n_20));
  NOR2X1 add_35_2_g1059(.A (in2[9]), .B (in1[9]), .Y (add_35_2_n_19));
  NOR2X1 add_35_2_g1060(.A (in2[13]), .B (in1[13]), .Y (add_35_2_n_18));
  NOR2X1 add_35_2_g1061(.A (in2[14]), .B (in1[14]), .Y (add_35_2_n_17));
  NOR2X1 add_35_2_g1062(.A (in2[5]), .B (in1[5]), .Y (add_35_2_n_16));
  NOR2X1 add_35_2_g1063(.A (in2[11]), .B (in1[11]), .Y (add_35_2_n_15));
  NOR2X1 add_35_2_g1064(.A (in2[6]), .B (in1[6]), .Y (add_35_2_n_14));
  OR2X1 add_35_2_g1065(.A (in2[12]), .B (in1[12]), .Y (add_35_2_n_13));
  NAND2X1 add_35_2_g1066(.A (in2[25]), .B (in2[24]), .Y (add_35_2_n_0));
  NAND2X1 add_35_2_g1067(.A (in2[5]), .B (in1[5]), .Y (add_35_2_n_12));
  NAND2X1 add_35_2_g1068(.A (in2[13]), .B (in1[13]), .Y
       (add_35_2_n_11));
  NOR2X1 add_35_2_g1069(.A (in2[4]), .B (in1[4]), .Y (add_35_2_n_10));
  NAND2X1 add_35_2_g1070(.A (in2[15]), .B (in1[15]), .Y (add_35_2_n_9));
  NAND2X1 add_35_2_g1071(.A (in2[12]), .B (in1[12]), .Y (add_35_2_n_8));
  NAND2X1 add_35_2_g1072(.A (in2[4]), .B (in1[4]), .Y (add_35_2_n_7));
  NOR2X1 add_35_2_g1073(.A (in2[7]), .B (in1[7]), .Y (add_35_2_n_6));
  NAND2X1 add_35_2_g1074(.A (in2[8]), .B (in1[8]), .Y (add_35_2_n_5));
  NOR2X1 add_35_2_g1075(.A (in2[8]), .B (in1[8]), .Y (add_35_2_n_4));
  NAND2X1 add_35_2_g1076(.A (in2[6]), .B (in1[6]), .Y (add_35_2_n_3));
  NOR2X1 add_35_2_g1077(.A (in2[10]), .B (in1[10]), .Y (add_35_2_n_2));
  NAND2X1 add_35_2_g1078(.A (in2[14]), .B (in1[14]), .Y (add_35_2_n_1));
endmodule

