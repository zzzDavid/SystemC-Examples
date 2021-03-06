`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 17 2020 14:06:15 EST (Nov 17 2020 19:06:15 UTC)

module dut_DECODE_64U_5_1(in1, out1);
  input [5:0] in1;
  output [63:0] out1;
  wire [5:0] in1;
  wire [63:0] out1;
  wire n_0, n_1, n_2, n_3, n_4, n_5, n_6, n_7;
  wire n_8, n_9, n_10, n_11, n_12, n_13, n_14, n_15;
  wire n_16, n_17, n_23, n_28, n_48, n_50, n_64, n_66;
  wire n_70, n_74, n_77, n_78, n_80, n_82, n_85, n_88;
  wire n_91, n_92, n_94, n_96;
  NOR2X1 g498(.A (n_50), .B (n_74), .Y (out1[59]));
  NOR2X1 g493(.A (n_94), .B (n_96), .Y (out1[39]));
  NOR2X1 g519(.A (n_91), .B (n_96), .Y (out1[38]));
  NOR2X1 g520(.A (n_94), .B (n_92), .Y (out1[37]));
  NOR2X1 g552(.A (n_91), .B (n_92), .Y (out1[36]));
  NOR2X1 g521(.A (n_94), .B (n_88), .Y (out1[35]));
  NOR2X1 g553(.A (n_91), .B (n_88), .Y (out1[34]));
  NOR2BX1 g538(.AN (n_85), .B (n_94), .Y (out1[33]));
  NOR2BX1 g544(.AN (n_85), .B (n_91), .Y (out1[32]));
  NOR2X1 g501(.A (n_82), .B (n_80), .Y (out1[31]));
  NOR2X1 g531(.A (n_82), .B (n_77), .Y (out1[30]));
  NOR2X1 g496(.A (n_80), .B (n_78), .Y (out1[29]));
  NOR2X1 g523(.A (n_77), .B (n_78), .Y (out1[28]));
  NOR2X1 g515(.A (n_80), .B (n_88), .Y (out1[11]));
  NOR2X1 g491(.A (n_80), .B (n_74), .Y (out1[27]));
  NOR2X1 g508(.A (n_77), .B (n_74), .Y (out1[26]));
  NOR2X1 g509(.A (n_80), .B (n_70), .Y (out1[25]));
  NOR2X1 g548(.A (n_77), .B (n_70), .Y (out1[24]));
  NOR2X1 g511(.A (n_66), .B (n_74), .Y (out1[19]));
  NOR2BX1 g512(.AN (n_64), .B (n_74), .Y (out1[18]));
  NOR2X1 g545(.A (n_66), .B (n_70), .Y (out1[17]));
  NOR2BX1 g536(.AN (n_64), .B (n_70), .Y (out1[16]));
  NOR2X1 g492(.A (n_80), .B (n_96), .Y (out1[15]));
  NOR2X1 g513(.A (n_77), .B (n_96), .Y (out1[14]));
  NOR2X1 g514(.A (n_80), .B (n_92), .Y (out1[13]));
  NOR2X1 g547(.A (n_77), .B (n_92), .Y (out1[12]));
  NOR2X1 g551(.A (n_77), .B (n_88), .Y (out1[10]));
  NOR2BX1 g516(.AN (n_85), .B (n_80), .Y (out1[9]));
  NOR2BX1 g543(.AN (n_85), .B (n_77), .Y (out1[8]));
  NOR2X1 g517(.A (n_66), .B (n_96), .Y (out1[7]));
  NOR2BX1 g518(.AN (n_64), .B (n_96), .Y (out1[6]));
  NOR2X1 g550(.A (n_66), .B (n_92), .Y (out1[5]));
  NOR2BX1 g522(.AN (n_64), .B (n_92), .Y (out1[4]));
  NOR2X1 g494(.A (n_48), .B (n_74), .Y (out1[58]));
  NOR2X1 g537(.A (n_50), .B (n_70), .Y (out1[57]));
  NOR2X1 g529(.A (n_48), .B (n_70), .Y (out1[56]));
  NOR2X1 g500(.A (n_82), .B (n_94), .Y (out1[55]));
  NOR2X1 g542(.A (n_82), .B (n_91), .Y (out1[54]));
  NOR2X1 g495(.A (n_78), .B (n_94), .Y (out1[53]));
  NOR2X1 g524(.A (n_78), .B (n_91), .Y (out1[52]));
  NOR2X1 g506(.A (n_94), .B (n_74), .Y (out1[51]));
  NOR2X1 g510(.A (n_91), .B (n_74), .Y (out1[50]));
  NOR2X1 g507(.A (n_94), .B (n_70), .Y (out1[49]));
  NOR2X1 g549(.A (n_91), .B (n_70), .Y (out1[48]));
  NOR2X1 g499(.A (n_50), .B (n_96), .Y (out1[47]));
  NOR2X1 g497(.A (n_48), .B (n_96), .Y (out1[46]));
  NOR2X1 g535(.A (n_50), .B (n_92), .Y (out1[45]));
  NOR2X1 g527(.A (n_48), .B (n_92), .Y (out1[44]));
  NOR2X1 g532(.A (n_82), .B (n_66), .Y (out1[23]));
  NOR2X1 g528(.A (n_48), .B (n_88), .Y (out1[42]));
  NOR2BX1 g530(.AN (n_85), .B (n_48), .Y (out1[40]));
  NOR2X1 g541(.A (n_66), .B (n_28), .Y (out1[1]));
  NOR2X1 g546(.A (n_66), .B (n_88), .Y (out1[3]));
  NOR2BX1 g526(.AN (n_64), .B (n_78), .Y (out1[20]));
  NOR2X1 g540(.A (n_50), .B (n_28), .Y (out1[41]));
  NOR2X1 g503(.A (n_82), .B (n_48), .Y (out1[62]));
  NOR2X1 g525(.A (n_66), .B (n_78), .Y (out1[21]));
  NOR2X1 g539(.A (n_88), .B (n_23), .Y (out1[2]));
  NOR2X1 g505(.A (n_23), .B (n_28), .Y (out1[0]));
  NOR2X1 g533(.A (n_82), .B (n_23), .Y (out1[22]));
  NOR2X1 g504(.A (n_50), .B (n_78), .Y (out1[61]));
  NOR2X1 g502(.A (n_48), .B (n_78), .Y (out1[60]));
  NOR2X1 g534(.A (n_50), .B (n_88), .Y (out1[43]));
  NOR2X1 g490(.A (n_82), .B (n_50), .Y (out1[63]));
  NAND2X4 g567(.A (in1[1]), .B (n_13), .Y (n_96));
  NAND2X4 g562(.A (in1[0]), .B (n_14), .Y (n_80));
  NAND2X4 g566(.A (in1[0]), .B (n_12), .Y (n_94));
  NAND2X4 g570(.A (n_17), .B (n_15), .Y (n_91));
  NAND2X4 g569(.A (n_17), .B (n_9), .Y (n_77));
  NAND2X4 g568(.A (in1[1]), .B (n_7), .Y (n_74));
  NAND2X4 g571(.A (n_16), .B (n_10), .Y (n_70));
  NAND2X4 g564(.A (n_16), .B (n_5), .Y (n_92));
  INVX2 g554(.A (n_64), .Y (n_23));
  INVX2 g555(.A (n_85), .Y (n_28));
  NAND2X4 g565(.A (in1[0]), .B (n_2), .Y (n_66));
  NAND2X4 g563(.A (in1[1]), .B (n_1), .Y (n_88));
  NAND2X6 g557(.A (n_17), .B (n_0), .Y (n_48));
  NAND2X6 g560(.A (n_16), .B (n_3), .Y (n_78));
  NOR2X2 g582(.A (in1[3]), .B (n_11), .Y (n_15));
  NOR2X2 g583(.A (in1[5]), .B (n_8), .Y (n_14));
  NOR2X2 g580(.A (in1[4]), .B (n_4), .Y (n_13));
  NOR3X4 g561(.A (in1[1]), .B (in1[4]), .C (in1[2]), .Y (n_85));
  NAND3X4 g558(.A (in1[2]), .B (in1[4]), .C (in1[1]), .Y (n_82));
  NAND3X4 g556(.A (in1[3]), .B (in1[5]), .C (in1[0]), .Y (n_50));
  NOR2X2 g578(.A (in1[3]), .B (n_11), .Y (n_12));
  NOR2X2 g576(.A (in1[2]), .B (n_6), .Y (n_10));
  NOR2X2 g577(.A (in1[5]), .B (n_8), .Y (n_9));
  NOR2X2 g579(.A (in1[2]), .B (n_6), .Y (n_7));
  NOR2X2 g581(.A (in1[4]), .B (n_4), .Y (n_5));
  NOR3X4 g559(.A (in1[0]), .B (in1[5]), .C (in1[3]), .Y (n_64));
  CLKAND2X3 g572(.A (in1[4]), .B (in1[2]), .Y (n_3));
  NOR2X4 g573(.A (in1[5]), .B (in1[3]), .Y (n_2));
  NOR2X4 g574(.A (in1[4]), .B (in1[2]), .Y (n_1));
  CLKAND2X3 g575(.A (in1[5]), .B (in1[3]), .Y (n_0));
  CLKINVX12 g586(.A (in1[5]), .Y (n_11));
  INVX2 g585(.A (in1[0]), .Y (n_17));
  INVX2 g589(.A (in1[1]), .Y (n_16));
  CLKINVX12 g587(.A (in1[3]), .Y (n_8));
  CLKINVX4 g588(.A (in1[2]), .Y (n_4));
  CLKINVX4 g584(.A (in1[4]), .Y (n_6));
endmodule


