`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 18 2020 11:30:57 EST (Nov 18 2020 16:30:57 UTC)

module dut_Mul_8Ux8U_16U_4(in2, in1, out1);
  input [7:0] in2, in1;
  output [15:0] out1;
  wire [7:0] in2, in1;
  wire [15:0] out1;
  wire mul_34_8_n_0, mul_34_8_n_1, mul_34_8_n_2, mul_34_8_n_3,
       mul_34_8_n_4, mul_34_8_n_5, mul_34_8_n_6, mul_34_8_n_7;
  wire mul_34_8_n_8, mul_34_8_n_9, mul_34_8_n_10, mul_34_8_n_11,
       mul_34_8_n_12, mul_34_8_n_13, mul_34_8_n_14, mul_34_8_n_15;
  wire mul_34_8_n_16, mul_34_8_n_17, mul_34_8_n_18, mul_34_8_n_20,
       mul_34_8_n_21, mul_34_8_n_22, mul_34_8_n_23, mul_34_8_n_24;
  wire mul_34_8_n_25, mul_34_8_n_26, mul_34_8_n_27, mul_34_8_n_28,
       mul_34_8_n_29, mul_34_8_n_30, mul_34_8_n_31, mul_34_8_n_32;
  wire mul_34_8_n_33, mul_34_8_n_34, mul_34_8_n_35, mul_34_8_n_36,
       mul_34_8_n_37, mul_34_8_n_38, mul_34_8_n_39, mul_34_8_n_40;
  wire mul_34_8_n_41, mul_34_8_n_42, mul_34_8_n_43, mul_34_8_n_44,
       mul_34_8_n_45, mul_34_8_n_46, mul_34_8_n_47, mul_34_8_n_48;
  wire mul_34_8_n_49, mul_34_8_n_50, mul_34_8_n_51, mul_34_8_n_52,
       mul_34_8_n_53, mul_34_8_n_54, mul_34_8_n_55, mul_34_8_n_56;
  wire mul_34_8_n_57, mul_34_8_n_58, mul_34_8_n_59, mul_34_8_n_60,
       mul_34_8_n_61, mul_34_8_n_62, mul_34_8_n_63, mul_34_8_n_64;
  wire mul_34_8_n_65, mul_34_8_n_66, mul_34_8_n_67, mul_34_8_n_68,
       mul_34_8_n_69, mul_34_8_n_70, mul_34_8_n_71, mul_34_8_n_72;
  wire mul_34_8_n_73, mul_34_8_n_74, mul_34_8_n_75, mul_34_8_n_76,
       mul_34_8_n_77, mul_34_8_n_78, mul_34_8_n_79, mul_34_8_n_80;
  wire mul_34_8_n_81, mul_34_8_n_82, mul_34_8_n_83, mul_34_8_n_84,
       mul_34_8_n_85, mul_34_8_n_86, mul_34_8_n_87, mul_34_8_n_88;
  wire mul_34_8_n_89, mul_34_8_n_90, mul_34_8_n_91, mul_34_8_n_92,
       mul_34_8_n_93, mul_34_8_n_94, mul_34_8_n_95, mul_34_8_n_96;
  wire mul_34_8_n_97, mul_34_8_n_98, mul_34_8_n_99, mul_34_8_n_100,
       mul_34_8_n_101, mul_34_8_n_102, mul_34_8_n_103, mul_34_8_n_104;
  wire mul_34_8_n_105, mul_34_8_n_106, mul_34_8_n_107, mul_34_8_n_108,
       mul_34_8_n_109, mul_34_8_n_110, mul_34_8_n_111, mul_34_8_n_112;
  wire mul_34_8_n_113, mul_34_8_n_114, mul_34_8_n_115, mul_34_8_n_116,
       mul_34_8_n_117, mul_34_8_n_118, mul_34_8_n_119, mul_34_8_n_120;
  wire mul_34_8_n_121, mul_34_8_n_122, mul_34_8_n_123, mul_34_8_n_124,
       mul_34_8_n_125, mul_34_8_n_126, mul_34_8_n_127, mul_34_8_n_129;
  wire mul_34_8_n_130, mul_34_8_n_131, mul_34_8_n_132, mul_34_8_n_133,
       mul_34_8_n_134, mul_34_8_n_135, mul_34_8_n_136, mul_34_8_n_137;
  wire mul_34_8_n_138, mul_34_8_n_139, mul_34_8_n_140, mul_34_8_n_141,
       mul_34_8_n_142, mul_34_8_n_143, mul_34_8_n_144, mul_34_8_n_145;
  wire mul_34_8_n_146, mul_34_8_n_147, mul_34_8_n_148, mul_34_8_n_149,
       mul_34_8_n_150, mul_34_8_n_151, mul_34_8_n_152, mul_34_8_n_153;
  wire mul_34_8_n_154, mul_34_8_n_155, mul_34_8_n_156, mul_34_8_n_157,
       mul_34_8_n_158, mul_34_8_n_159, mul_34_8_n_160, mul_34_8_n_161;
  wire mul_34_8_n_163, mul_34_8_n_164, mul_34_8_n_165, mul_34_8_n_166,
       mul_34_8_n_167, mul_34_8_n_168, mul_34_8_n_169, mul_34_8_n_170;
  wire mul_34_8_n_171, mul_34_8_n_172, mul_34_8_n_173, mul_34_8_n_174,
       mul_34_8_n_175, mul_34_8_n_176, mul_34_8_n_178, mul_34_8_n_179;
  wire mul_34_8_n_180, mul_34_8_n_181, mul_34_8_n_182, mul_34_8_n_183,
       mul_34_8_n_184, mul_34_8_n_186, mul_34_8_n_187, mul_34_8_n_188;
  wire mul_34_8_n_189, mul_34_8_n_190, mul_34_8_n_191, mul_34_8_n_192,
       mul_34_8_n_193, mul_34_8_n_194, mul_34_8_n_195, mul_34_8_n_196;
  wire mul_34_8_n_197, mul_34_8_n_198, mul_34_8_n_199, mul_34_8_n_200,
       mul_34_8_n_201, mul_34_8_n_202, mul_34_8_n_203, mul_34_8_n_205;
  wire mul_34_8_n_206, mul_34_8_n_207, mul_34_8_n_208, mul_34_8_n_209,
       mul_34_8_n_210, mul_34_8_n_211, mul_34_8_n_213, mul_34_8_n_214;
  wire mul_34_8_n_215, mul_34_8_n_216, mul_34_8_n_217, mul_34_8_n_218,
       mul_34_8_n_219, mul_34_8_n_220, mul_34_8_n_221, mul_34_8_n_222;
  wire mul_34_8_n_223, mul_34_8_n_224, mul_34_8_n_225, mul_34_8_n_226,
       mul_34_8_n_227, mul_34_8_n_228, mul_34_8_n_229, mul_34_8_n_231;
  wire mul_34_8_n_232, mul_34_8_n_233, mul_34_8_n_234, mul_34_8_n_236,
       mul_34_8_n_237, mul_34_8_n_238, mul_34_8_n_241, mul_34_8_n_242;
  wire mul_34_8_n_243, mul_34_8_n_246, mul_34_8_n_247, mul_34_8_n_249,
       mul_34_8_n_250;
  XNOR2X1 mul_34_8_g2564(.A (mul_34_8_n_179), .B (mul_34_8_n_250), .Y
       (out1[15]));
  ADDFX1 mul_34_8_g2565(.A (mul_34_8_n_249), .B (mul_34_8_n_195), .CI
       (mul_34_8_n_171), .CO (mul_34_8_n_250), .S (out1[14]));
  OAI21X1 mul_34_8_g2566(.A0 (mul_34_8_n_201), .A1 (mul_34_8_n_246),
       .B0 (mul_34_8_n_199), .Y (mul_34_8_n_249));
  XNOR2X1 mul_34_8_g2567(.A (mul_34_8_n_207), .B (mul_34_8_n_247), .Y
       (out1[13]));
  OAI21X1 mul_34_8_g2568(.A0 (mul_34_8_n_224), .A1 (mul_34_8_n_243),
       .B0 (mul_34_8_n_227), .Y (mul_34_8_n_247));
  OA21X1 mul_34_8_g2569(.A0 (mul_34_8_n_224), .A1 (mul_34_8_n_243), .B0
       (mul_34_8_n_227), .Y (mul_34_8_n_246));
  XNOR2X1 mul_34_8_g2570(.A (mul_34_8_n_234), .B (mul_34_8_n_243), .Y
       (out1[12]));
  XNOR2X1 mul_34_8_g2571(.A (mul_34_8_n_233), .B (mul_34_8_n_242), .Y
       (out1[11]));
  AOI221X1 mul_34_8_g2572(.A0 (mul_34_8_n_232), .A1 (mul_34_8_n_231),
       .B0 (mul_34_8_n_223), .B1 (mul_34_8_n_218), .C0
       (mul_34_8_n_241), .Y (mul_34_8_n_243));
  OAI21X1 mul_34_8_g2573(.A0 (mul_34_8_n_216), .A1 (mul_34_8_n_237),
       .B0 (mul_34_8_n_217), .Y (mul_34_8_n_242));
  NAND2X1 mul_34_8_g2574(.A (mul_34_8_n_226), .B (mul_34_8_n_238), .Y
       (mul_34_8_n_241));
  XNOR2X1 mul_34_8_g2575(.A (mul_34_8_n_229), .B (mul_34_8_n_237), .Y
       (out1[10]));
  XNOR2X1 mul_34_8_g2576(.A (mul_34_8_n_228), .B (mul_34_8_n_236), .Y
       (out1[9]));
  NAND3BXL mul_34_8_g2577(.AN (mul_34_8_n_222), .B (mul_34_8_n_225), .C
       (mul_34_8_n_232), .Y (mul_34_8_n_238));
  AOI21X1 mul_34_8_g2578(.A0 (mul_34_8_n_225), .A1 (mul_34_8_n_221),
       .B0 (mul_34_8_n_231), .Y (mul_34_8_n_237));
  OAI21X1 mul_34_8_g2579(.A0 (mul_34_8_n_197), .A1 (mul_34_8_n_222),
       .B0 (mul_34_8_n_200), .Y (mul_34_8_n_236));
  XNOR2X1 mul_34_8_g2580(.A (mul_34_8_n_206), .B (mul_34_8_n_222), .Y
       (out1[8]));
  NOR2BX1 mul_34_8_g2581(.AN (mul_34_8_n_227), .B (mul_34_8_n_224), .Y
       (mul_34_8_n_234));
  NAND2XL mul_34_8_g2582(.A (mul_34_8_n_226), .B (mul_34_8_n_223), .Y
       (mul_34_8_n_233));
  NOR2BX1 mul_34_8_g2583(.AN (mul_34_8_n_223), .B (mul_34_8_n_216), .Y
       (mul_34_8_n_232));
  OAI21X1 mul_34_8_g2584(.A0 (mul_34_8_n_200), .A1 (mul_34_8_n_214),
       .B0 (mul_34_8_n_215), .Y (mul_34_8_n_231));
  XNOR2X1 mul_34_8_g2585(.A (mul_34_8_n_202), .B (mul_34_8_n_213), .Y
       (out1[7]));
  NOR2XL mul_34_8_g2586(.A (mul_34_8_n_218), .B (mul_34_8_n_216), .Y
       (mul_34_8_n_229));
  NAND2BX1 mul_34_8_g2587(.AN (mul_34_8_n_214), .B (mul_34_8_n_215), .Y
       (mul_34_8_n_228));
  NAND2X1 mul_34_8_g2588(.A (mul_34_8_n_219), .B (mul_34_8_n_192), .Y
       (mul_34_8_n_227));
  NAND2XL mul_34_8_g2589(.A (mul_34_8_n_208), .B (mul_34_8_n_220), .Y
       (mul_34_8_n_226));
  NOR2X1 mul_34_8_g2590(.A (mul_34_8_n_197), .B (mul_34_8_n_214), .Y
       (mul_34_8_n_225));
  NOR2X1 mul_34_8_g2591(.A (mul_34_8_n_219), .B (mul_34_8_n_192), .Y
       (mul_34_8_n_224));
  OR2XL mul_34_8_g2592(.A (mul_34_8_n_208), .B (mul_34_8_n_220), .Y
       (mul_34_8_n_223));
  INVX1 mul_34_8_g2593(.A (mul_34_8_n_222), .Y (mul_34_8_n_221));
  AOI221X1 mul_34_8_g2594(.A0 (mul_34_8_n_172), .A1 (mul_34_8_n_203),
       .B0 (mul_34_8_n_186), .B1 (mul_34_8_n_203), .C0
       (mul_34_8_n_205), .Y (mul_34_8_n_222));
  ADDFX1 mul_34_8_g2595(.A (mul_34_8_n_165), .B (mul_34_8_n_139), .CI
       (mul_34_8_n_169), .CO (mul_34_8_n_219), .S (mul_34_8_n_220));
  INVX1 mul_34_8_g2596(.A (mul_34_8_n_217), .Y (mul_34_8_n_218));
  NAND2X1 mul_34_8_g2597(.A (mul_34_8_n_210), .B (mul_34_8_n_209), .Y
       (mul_34_8_n_217));
  NOR2X1 mul_34_8_g2598(.A (mul_34_8_n_210), .B (mul_34_8_n_209), .Y
       (mul_34_8_n_216));
  NAND2X1 mul_34_8_g2599(.A (mul_34_8_n_193), .B (mul_34_8_n_211), .Y
       (mul_34_8_n_215));
  NOR2X1 mul_34_8_g2600(.A (mul_34_8_n_193), .B (mul_34_8_n_211), .Y
       (mul_34_8_n_214));
  OAI21X1 mul_34_8_g2601(.A0 (mul_34_8_n_182), .A1 (mul_34_8_n_198),
       .B0 (mul_34_8_n_181), .Y (mul_34_8_n_213));
  XNOR2X1 mul_34_8_g2602(.A (mul_34_8_n_188), .B (mul_34_8_n_198), .Y
       (out1[6]));
  ADDFX1 mul_34_8_g2603(.A (mul_34_8_n_155), .B (mul_34_8_n_141), .CI
       (mul_34_8_n_174), .CO (mul_34_8_n_210), .S (mul_34_8_n_211));
  ADDFX1 mul_34_8_g2604(.A (mul_34_8_n_166), .B (mul_34_8_n_149), .CI
       (mul_34_8_n_173), .CO (mul_34_8_n_208), .S (mul_34_8_n_209));
  NAND2BX1 mul_34_8_g2605(.AN (mul_34_8_n_201), .B (mul_34_8_n_199), .Y
       (mul_34_8_n_207));
  NOR2BX1 mul_34_8_g2606(.AN (mul_34_8_n_200), .B (mul_34_8_n_197), .Y
       (mul_34_8_n_206));
  OAI21X1 mul_34_8_g2607(.A0 (mul_34_8_n_181), .A1 (mul_34_8_n_190),
       .B0 (mul_34_8_n_189), .Y (mul_34_8_n_205));
  XNOR2X1 mul_34_8_g2608(.A (mul_34_8_n_167), .B (mul_34_8_n_187), .Y
       (out1[5]));
  NOR2X1 mul_34_8_g2609(.A (mul_34_8_n_182), .B (mul_34_8_n_190), .Y
       (mul_34_8_n_203));
  NAND2BX1 mul_34_8_g2610(.AN (mul_34_8_n_190), .B (mul_34_8_n_189), .Y
       (mul_34_8_n_202));
  NOR2X1 mul_34_8_g2611(.A (mul_34_8_n_191), .B (mul_34_8_n_196), .Y
       (mul_34_8_n_201));
  NAND2X1 mul_34_8_g2612(.A (mul_34_8_n_183), .B (mul_34_8_n_194), .Y
       (mul_34_8_n_200));
  NAND2X1 mul_34_8_g2613(.A (mul_34_8_n_191), .B (mul_34_8_n_196), .Y
       (mul_34_8_n_199));
  NOR2X1 mul_34_8_g2614(.A (mul_34_8_n_186), .B (mul_34_8_n_172), .Y
       (mul_34_8_n_198));
  NOR2X1 mul_34_8_g2615(.A (mul_34_8_n_183), .B (mul_34_8_n_194), .Y
       (mul_34_8_n_197));
  ADDFX1 mul_34_8_g2616(.A (mul_34_8_n_146), .B (mul_34_8_n_79), .CI
       (mul_34_8_n_153), .CO (mul_34_8_n_195), .S (mul_34_8_n_196));
  ADDFX1 mul_34_8_g2617(.A (mul_34_8_n_142), .B (mul_34_8_n_158), .CI
       (mul_34_8_n_156), .CO (mul_34_8_n_193), .S (mul_34_8_n_194));
  ADDFX1 mul_34_8_g2618(.A (mul_34_8_n_168), .B (mul_34_8_n_147), .CI
       (mul_34_8_n_138), .CO (mul_34_8_n_191), .S (mul_34_8_n_192));
  NOR2X1 mul_34_8_g2619(.A (mul_34_8_n_175), .B (mul_34_8_n_184), .Y
       (mul_34_8_n_190));
  NAND2X1 mul_34_8_g2620(.A (mul_34_8_n_175), .B (mul_34_8_n_184), .Y
       (mul_34_8_n_189));
  NOR2BX1 mul_34_8_g2621(.AN (mul_34_8_n_181), .B (mul_34_8_n_182), .Y
       (mul_34_8_n_188));
  NAND2X1 mul_34_8_g2622(.A (mul_34_8_n_145), .B (mul_34_8_n_180), .Y
       (mul_34_8_n_187));
  NOR2X1 mul_34_8_g2623(.A (mul_34_8_n_163), .B (mul_34_8_n_180), .Y
       (mul_34_8_n_186));
  XNOR2X1 mul_34_8_g2624(.A (mul_34_8_n_178), .B (mul_34_8_n_154), .Y
       (out1[4]));
  ADDFX1 mul_34_8_g2625(.A (mul_34_8_n_150), .B (mul_34_8_n_134), .CI
       (mul_34_8_n_143), .CO (mul_34_8_n_183), .S (mul_34_8_n_184));
  NOR2X1 mul_34_8_g2626(.A (mul_34_8_n_159), .B (mul_34_8_n_176), .Y
       (mul_34_8_n_182));
  NAND2X1 mul_34_8_g2627(.A (mul_34_8_n_159), .B (mul_34_8_n_176), .Y
       (mul_34_8_n_181));
  NAND2BX1 mul_34_8_g2628(.AN (mul_34_8_n_144), .B (mul_34_8_n_178), .Y
       (mul_34_8_n_180));
  XNOR2X1 mul_34_8_g2629(.A (mul_34_8_n_135), .B (mul_34_8_n_170), .Y
       (mul_34_8_n_179));
  ADDFX1 mul_34_8_g2630(.A (mul_34_8_n_161), .B (mul_34_8_n_123), .CI
       (mul_34_8_n_131), .CO (mul_34_8_n_178), .S (out1[3]));
  ADDFX1 mul_34_8_g2631(.A (mul_34_8_n_151), .B (mul_34_8_n_90), .CI
       (mul_34_8_n_129), .CO (mul_34_8_n_175), .S (mul_34_8_n_176));
  ADDFX1 mul_34_8_g2632(.A (mul_34_8_n_157), .B (mul_34_8_n_109), .CI
       (mul_34_8_n_21), .CO (mul_34_8_n_173), .S (mul_34_8_n_174));
  OAI21X1 mul_34_8_g2633(.A0 (mul_34_8_n_145), .A1 (mul_34_8_n_163),
       .B0 (mul_34_8_n_164), .Y (mul_34_8_n_172));
  ADDFX1 mul_34_8_g2634(.A (mul_34_8_n_152), .B (mul_34_8_n_124), .CI
       (mul_34_8_n_20), .CO (mul_34_8_n_170), .S (mul_34_8_n_171));
  ADDFX1 mul_34_8_g2635(.A (mul_34_8_n_148), .B (mul_34_8_n_106), .CI
       (mul_34_8_n_16), .CO (mul_34_8_n_168), .S (mul_34_8_n_169));
  NAND2BX1 mul_34_8_g2636(.AN (mul_34_8_n_163), .B (mul_34_8_n_164), .Y
       (mul_34_8_n_167));
  ADDFX1 mul_34_8_g2637(.A (mul_34_8_n_140), .B (mul_34_8_n_110), .CI
       (mul_34_8_n_14), .CO (mul_34_8_n_165), .S (mul_34_8_n_166));
  NAND2X1 mul_34_8_g2638(.A (mul_34_8_n_136), .B (mul_34_8_n_160), .Y
       (mul_34_8_n_164));
  NOR2X1 mul_34_8_g2639(.A (mul_34_8_n_136), .B (mul_34_8_n_160), .Y
       (mul_34_8_n_163));
  ADDFX1 mul_34_8_g2640(.A (mul_34_8_n_126), .B (mul_34_8_n_121), .CI
       (mul_34_8_n_76), .CO (mul_34_8_n_161), .S (out1[2]));
  ADDFX1 mul_34_8_g2641(.A (mul_34_8_n_130), .B (mul_34_8_n_91), .CI
       (mul_34_8_n_92), .CO (mul_34_8_n_159), .S (mul_34_8_n_160));
  ADDFX1 mul_34_8_g2642(.A (mul_34_8_n_95), .B (mul_34_8_n_117), .CI
       (mul_34_8_n_15), .CO (mul_34_8_n_157), .S (mul_34_8_n_158));
  ADDFX1 mul_34_8_g2643(.A (mul_34_8_n_133), .B (mul_34_8_n_107), .CI
       (mul_34_8_n_88), .CO (mul_34_8_n_155), .S (mul_34_8_n_156));
  NAND2BX1 mul_34_8_g2644(.AN (mul_34_8_n_144), .B (mul_34_8_n_145), .Y
       (mul_34_8_n_154));
  ADDFX1 mul_34_8_g2645(.A (mul_34_8_n_112), .B (mul_34_8_n_98), .CI
       (mul_34_8_n_22), .CO (mul_34_8_n_152), .S (mul_34_8_n_153));
  ADDFX1 mul_34_8_g2646(.A (mul_34_8_n_118), .B (mul_34_8_n_85), .CI
       (mul_34_8_n_99), .CO (mul_34_8_n_150), .S (mul_34_8_n_151));
  ADDFX1 mul_34_8_g2647(.A (mul_34_8_n_105), .B (in2[1]), .CI
       (mul_34_8_n_97), .CO (mul_34_8_n_148), .S (mul_34_8_n_149));
  ADDFX1 mul_34_8_g2648(.A (mul_34_8_n_104), .B (mul_34_8_n_24), .CI
       (mul_34_8_n_108), .CO (mul_34_8_n_146), .S (mul_34_8_n_147));
  NAND2X1 mul_34_8_g2649(.A (mul_34_8_n_132), .B (mul_34_8_n_137), .Y
       (mul_34_8_n_145));
  NOR2X1 mul_34_8_g2650(.A (mul_34_8_n_132), .B (mul_34_8_n_137), .Y
       (mul_34_8_n_144));
  ADDFX1 mul_34_8_g2651(.A (mul_34_8_n_102), .B (mul_34_8_n_89), .CI
       (mul_34_8_n_111), .CO (mul_34_8_n_142), .S (mul_34_8_n_143));
  ADDFX1 mul_34_8_g2652(.A (mul_34_8_n_101), .B (in2[1]), .CI
       (mul_34_8_n_93), .CO (mul_34_8_n_140), .S (mul_34_8_n_141));
  ADDFX1 mul_34_8_g2653(.A (mul_34_8_n_103), .B (mul_34_8_n_100), .CI
       (mul_34_8_n_6), .CO (mul_34_8_n_138), .S (mul_34_8_n_139));
  ADDFX1 mul_34_8_g2654(.A (mul_34_8_n_96), .B (mul_34_8_n_116), .CI
       (mul_34_8_n_75), .CO (mul_34_8_n_136), .S (mul_34_8_n_137));
  XNOR2X1 mul_34_8_g2655(.A (mul_34_8_n_124), .B (mul_34_8_n_127), .Y
       (mul_34_8_n_135));
  ADDHX1 mul_34_8_g2656(.A (mul_34_8_n_115), .B (mul_34_8_n_119), .CO
       (mul_34_8_n_133), .S (mul_34_8_n_134));
  ADDHX1 mul_34_8_g2657(.A (mul_34_8_n_114), .B (mul_34_8_n_94), .CO
       (mul_34_8_n_132), .S (mul_34_8_n_131));
  ADDHX1 mul_34_8_g2658(.A (mul_34_8_n_113), .B (mul_34_8_n_120), .CO
       (mul_34_8_n_129), .S (mul_34_8_n_130));
  AOI21X1 mul_34_8_g2659(.A0 (mul_34_8_n_67), .A1 (mul_34_8_n_125), .B0
       (mul_34_8_n_126), .Y (out1[1]));
  XNOR2X1 mul_34_8_g2660(.A (mul_34_8_n_23), .B (mul_34_8_n_122), .Y
       (mul_34_8_n_127));
  NOR2X1 mul_34_8_g2661(.A (mul_34_8_n_67), .B (mul_34_8_n_125), .Y
       (mul_34_8_n_126));
  OAI22X1 mul_34_8_g2662(.A0 (mul_34_8_n_62), .A1 (mul_34_8_n_87), .B0
       (mul_34_8_n_9), .B1 (mul_34_8_n_58), .Y (mul_34_8_n_123));
  AOI21X1 mul_34_8_g2663(.A0 (in2[7]), .A1 (mul_34_8_n_84), .B0
       (mul_34_8_n_82), .Y (mul_34_8_n_122));
  OAI22X1 mul_34_8_g2664(.A0 (mul_34_8_n_65), .A1 (mul_34_8_n_87), .B0
       (mul_34_8_n_9), .B1 (mul_34_8_n_62), .Y (mul_34_8_n_121));
  AOI22X1 mul_34_8_g2665(.A0 (mul_34_8_n_29), .A1 (mul_34_8_n_86), .B0
       (in2[0]), .B1 (mul_34_8_n_64), .Y (mul_34_8_n_125));
  OAI22X1 mul_34_8_g2666(.A0 (mul_34_8_n_63), .A1 (mul_34_8_n_87), .B0
       (mul_34_8_n_9), .B1 (mul_34_8_n_60), .Y (mul_34_8_n_120));
  OAI22X1 mul_34_8_g2667(.A0 (mul_34_8_n_59), .A1 (mul_34_8_n_87), .B0
       (mul_34_8_n_9), .B1 (mul_34_8_n_61), .Y (mul_34_8_n_119));
  OAI22X1 mul_34_8_g2668(.A0 (mul_34_8_n_60), .A1 (mul_34_8_n_87), .B0
       (mul_34_8_n_9), .B1 (mul_34_8_n_59), .Y (mul_34_8_n_118));
  OAI22X1 mul_34_8_g2669(.A0 (mul_34_8_n_61), .A1 (mul_34_8_n_87), .B0
       (mul_34_8_n_6), .B1 (mul_34_8_n_9), .Y (mul_34_8_n_117));
  OAI22X1 mul_34_8_g2670(.A0 (mul_34_8_n_58), .A1 (mul_34_8_n_87), .B0
       (mul_34_8_n_9), .B1 (mul_34_8_n_63), .Y (mul_34_8_n_116));
  AOI21X1 mul_34_8_g2671(.A0 (mul_34_8_n_56), .A1 (mul_34_8_n_84), .B0
       (mul_34_8_n_82), .Y (mul_34_8_n_124));
  AOI221X1 mul_34_8_g2672(.A0 (in2[6]), .A1 (in2[5]), .B0 (in1[0]), .B1
       (mul_34_8_n_0), .C0 (mul_34_8_n_1), .Y (mul_34_8_n_115));
  AOI221X1 mul_34_8_g2673(.A0 (in1[0]), .A1 (in2[1]), .B0 (in2[2]), .B1
       (mul_34_8_n_17), .C0 (mul_34_8_n_7), .Y (mul_34_8_n_114));
  AOI221X1 mul_34_8_g2674(.A0 (in1[0]), .A1 (in2[3]), .B0 (in2[4]), .B1
       (mul_34_8_n_18), .C0 (mul_34_8_n_8), .Y (mul_34_8_n_113));
  AO22XL mul_34_8_g2675(.A0 (mul_34_8_n_80), .A1 (mul_34_8_n_84), .B0
       (mul_34_8_n_56), .B1 (mul_34_8_n_81), .Y (mul_34_8_n_112));
  OAI22X1 mul_34_8_g2676(.A0 (mul_34_8_n_26), .A1 (mul_34_8_n_83), .B0
       (mul_34_8_n_57), .B1 (mul_34_8_n_30), .Y (mul_34_8_n_111));
  OAI22X1 mul_34_8_g2677(.A0 (mul_34_8_n_66), .A1 (mul_34_8_n_83), .B0
       (mul_34_8_n_68), .B1 (mul_34_8_n_30), .Y (mul_34_8_n_110));
  OAI22X1 mul_34_8_g2678(.A0 (mul_34_8_n_53), .A1 (mul_34_8_n_83), .B0
       (mul_34_8_n_66), .B1 (mul_34_8_n_30), .Y (mul_34_8_n_109));
  OAI22X1 mul_34_8_g2679(.A0 (mul_34_8_n_54), .A1 (mul_34_8_n_83), .B0
       (mul_34_8_n_55), .B1 (mul_34_8_n_30), .Y (mul_34_8_n_108));
  OAI22X1 mul_34_8_g2680(.A0 (mul_34_8_n_57), .A1 (mul_34_8_n_83), .B0
       (mul_34_8_n_53), .B1 (mul_34_8_n_30), .Y (mul_34_8_n_107));
  OAI22X1 mul_34_8_g2681(.A0 (mul_34_8_n_68), .A1 (mul_34_8_n_83), .B0
       (mul_34_8_n_54), .B1 (mul_34_8_n_30), .Y (mul_34_8_n_106));
  OAI22X1 mul_34_8_g2682(.A0 (mul_34_8_n_46), .A1 (mul_34_8_n_78), .B0
       (mul_34_8_n_34), .B1 (mul_34_8_n_52), .Y (mul_34_8_n_105));
  OAI2BB1X1 mul_34_8_g2683(.A0N (mul_34_8_n_43), .A1N (mul_34_8_n_77),
       .B0 (mul_34_8_n_74), .Y (mul_34_8_n_104));
  AOI21X1 mul_34_8_g2684(.A0 (in2[3]), .A1 (mul_34_8_n_69), .B0
       (mul_34_8_n_72), .Y (mul_34_8_n_103));
  OAI22X1 mul_34_8_g2685(.A0 (mul_34_8_n_40), .A1 (mul_34_8_n_78), .B0
       (mul_34_8_n_31), .B1 (mul_34_8_n_52), .Y (mul_34_8_n_102));
  OAI22X1 mul_34_8_g2686(.A0 (mul_34_8_n_45), .A1 (mul_34_8_n_78), .B0
       (mul_34_8_n_46), .B1 (mul_34_8_n_52), .Y (mul_34_8_n_101));
  OAI22X1 mul_34_8_g2687(.A0 (mul_34_8_n_34), .A1 (mul_34_8_n_78), .B0
       (mul_34_8_n_42), .B1 (mul_34_8_n_52), .Y (mul_34_8_n_100));
  OAI22X1 mul_34_8_g2688(.A0 (mul_34_8_n_39), .A1 (mul_34_8_n_78), .B0
       (mul_34_8_n_40), .B1 (mul_34_8_n_52), .Y (mul_34_8_n_99));
  AOI21X1 mul_34_8_g2689(.A0 (in2[5]), .A1 (mul_34_8_n_77), .B0
       (mul_34_8_n_73), .Y (mul_34_8_n_98));
  OAI2BB1X1 mul_34_8_g2690(.A0N (mul_34_8_n_44), .A1N (mul_34_8_n_69),
       .B0 (mul_34_8_n_71), .Y (mul_34_8_n_97));
  OAI22X1 mul_34_8_g2691(.A0 (mul_34_8_n_36), .A1 (mul_34_8_n_70), .B0
       (mul_34_8_n_38), .B1 (mul_34_8_n_51), .Y (mul_34_8_n_96));
  OAI22X1 mul_34_8_g2692(.A0 (mul_34_8_n_35), .A1 (mul_34_8_n_70), .B0
       (mul_34_8_n_33), .B1 (mul_34_8_n_51), .Y (mul_34_8_n_95));
  OAI22X1 mul_34_8_g2693(.A0 (mul_34_8_n_27), .A1 (mul_34_8_n_70), .B0
       (mul_34_8_n_36), .B1 (mul_34_8_n_51), .Y (mul_34_8_n_94));
  AO22XL mul_34_8_g2694(.A0 (mul_34_8_n_32), .A1 (mul_34_8_n_69), .B0
       (mul_34_8_n_44), .B1 (mul_34_8_n_50), .Y (mul_34_8_n_93));
  OAI22X1 mul_34_8_g2695(.A0 (mul_34_8_n_25), .A1 (mul_34_8_n_78), .B0
       (mul_34_8_n_39), .B1 (mul_34_8_n_52), .Y (mul_34_8_n_92));
  OAI22X1 mul_34_8_g2696(.A0 (mul_34_8_n_38), .A1 (mul_34_8_n_70), .B0
       (mul_34_8_n_37), .B1 (mul_34_8_n_51), .Y (mul_34_8_n_91));
  OAI22X1 mul_34_8_g2697(.A0 (mul_34_8_n_37), .A1 (mul_34_8_n_70), .B0
       (mul_34_8_n_41), .B1 (mul_34_8_n_51), .Y (mul_34_8_n_90));
  OAI22X1 mul_34_8_g2698(.A0 (mul_34_8_n_41), .A1 (mul_34_8_n_70), .B0
       (mul_34_8_n_35), .B1 (mul_34_8_n_51), .Y (mul_34_8_n_89));
  OAI22X1 mul_34_8_g2699(.A0 (mul_34_8_n_31), .A1 (mul_34_8_n_78), .B0
       (mul_34_8_n_45), .B1 (mul_34_8_n_52), .Y (mul_34_8_n_88));
  INVX1 mul_34_8_g2700(.A (mul_34_8_n_87), .Y (mul_34_8_n_86));
  NAND2X1 mul_34_8_g2701(.A (mul_34_8_n_9), .B (mul_34_8_n_28), .Y
       (mul_34_8_n_87));
  NOR2X1 mul_34_8_g2702(.A (mul_34_8_n_2), .B (mul_34_8_n_30), .Y
       (mul_34_8_n_85));
  INVX1 mul_34_8_g2703(.A (mul_34_8_n_83), .Y (mul_34_8_n_84));
  NAND2X1 mul_34_8_g2704(.A (mul_34_8_n_49), .B (mul_34_8_n_30), .Y
       (mul_34_8_n_83));
  NOR2X1 mul_34_8_g2705(.A (mul_34_8_n_1), .B (mul_34_8_n_30), .Y
       (mul_34_8_n_82));
  INVX1 mul_34_8_g2706(.A (mul_34_8_n_30), .Y (mul_34_8_n_81));
  INVX1 mul_34_8_g2707(.A (mul_34_8_n_55), .Y (mul_34_8_n_80));
  INVX1 mul_34_8_g2708(.A (mul_34_8_n_24), .Y (mul_34_8_n_79));
  INVX1 mul_34_8_g2709(.A (mul_34_8_n_78), .Y (mul_34_8_n_77));
  NOR2X1 mul_34_8_g2710(.A (mul_34_8_n_2), .B (mul_34_8_n_51), .Y
       (mul_34_8_n_76));
  NOR2X1 mul_34_8_g2711(.A (mul_34_8_n_2), .B (mul_34_8_n_52), .Y
       (mul_34_8_n_75));
  NAND2X1 mul_34_8_g2712(.A (mul_34_8_n_47), .B (mul_34_8_n_52), .Y
       (mul_34_8_n_78));
  INVX1 mul_34_8_g2713(.A (mul_34_8_n_73), .Y (mul_34_8_n_74));
  INVX1 mul_34_8_g2714(.A (mul_34_8_n_71), .Y (mul_34_8_n_72));
  INVX1 mul_34_8_g2715(.A (mul_34_8_n_70), .Y (mul_34_8_n_69));
  NOR2X1 mul_34_8_g2716(.A (mul_34_8_n_8), .B (mul_34_8_n_52), .Y
       (mul_34_8_n_73));
  NAND2X1 mul_34_8_g2717(.A (in2[3]), .B (mul_34_8_n_50), .Y
       (mul_34_8_n_71));
  NAND2X1 mul_34_8_g2718(.A (mul_34_8_n_48), .B (mul_34_8_n_51), .Y
       (mul_34_8_n_70));
  INVX1 mul_34_8_g2719(.A (mul_34_8_n_64), .Y (mul_34_8_n_65));
  INVX1 mul_34_8_g2720(.A (mul_34_8_n_51), .Y (mul_34_8_n_50));
  MXI2XL mul_34_8_g2721(.A (mul_34_8_n_1), .B (in2[7]), .S0 (in2[6]),
       .Y (mul_34_8_n_49));
  MXI2XL mul_34_8_g2722(.A (mul_34_8_n_7), .B (in2[3]), .S0 (in2[2]),
       .Y (mul_34_8_n_48));
  MXI2XL mul_34_8_g2723(.A (mul_34_8_n_8), .B (in2[5]), .S0 (in2[4]),
       .Y (mul_34_8_n_47));
  AOI22X1 mul_34_8_g2724(.A0 (in1[4]), .A1 (mul_34_8_n_1), .B0
       (in2[7]), .B1 (mul_34_8_n_3), .Y (mul_34_8_n_68));
  OR2XL mul_34_8_g2725(.A (mul_34_8_n_6), .B (out1[0]), .Y
       (mul_34_8_n_67));
  AOI22X1 mul_34_8_g2726(.A0 (in1[3]), .A1 (mul_34_8_n_1), .B0
       (in2[7]), .B1 (mul_34_8_n_4), .Y (mul_34_8_n_66));
  OAI22X1 mul_34_8_g2727(.A0 (mul_34_8_n_13), .A1 (in2[1]), .B0
       (mul_34_8_n_6), .B1 (in1[1]), .Y (mul_34_8_n_64));
  AOI22X1 mul_34_8_g2728(.A0 (in1[4]), .A1 (mul_34_8_n_6), .B0
       (in2[1]), .B1 (mul_34_8_n_3), .Y (mul_34_8_n_63));
  AOI22X1 mul_34_8_g2729(.A0 (in1[2]), .A1 (mul_34_8_n_6), .B0
       (in2[1]), .B1 (mul_34_8_n_5), .Y (mul_34_8_n_62));
  AOI22X1 mul_34_8_g2730(.A0 (in1[7]), .A1 (mul_34_8_n_6), .B0
       (in2[1]), .B1 (mul_34_8_n_12), .Y (mul_34_8_n_61));
  AOI22X1 mul_34_8_g2731(.A0 (in1[5]), .A1 (mul_34_8_n_6), .B0
       (in2[1]), .B1 (mul_34_8_n_11), .Y (mul_34_8_n_60));
  AOI22X1 mul_34_8_g2732(.A0 (in1[6]), .A1 (mul_34_8_n_6), .B0
       (in2[1]), .B1 (mul_34_8_n_10), .Y (mul_34_8_n_59));
  AOI22X1 mul_34_8_g2733(.A0 (in1[3]), .A1 (mul_34_8_n_6), .B0
       (in2[1]), .B1 (mul_34_8_n_4), .Y (mul_34_8_n_58));
  AOI22X1 mul_34_8_g2734(.A0 (in1[1]), .A1 (mul_34_8_n_1), .B0
       (in2[7]), .B1 (mul_34_8_n_13), .Y (mul_34_8_n_57));
  OAI22X1 mul_34_8_g2735(.A0 (mul_34_8_n_12), .A1 (in2[7]), .B0
       (mul_34_8_n_1), .B1 (in1[7]), .Y (mul_34_8_n_56));
  AOI22X1 mul_34_8_g2736(.A0 (in1[6]), .A1 (mul_34_8_n_1), .B0
       (in2[7]), .B1 (mul_34_8_n_10), .Y (mul_34_8_n_55));
  AOI22X1 mul_34_8_g2737(.A0 (in1[5]), .A1 (mul_34_8_n_1), .B0
       (in2[7]), .B1 (mul_34_8_n_11), .Y (mul_34_8_n_54));
  AOI22X1 mul_34_8_g2738(.A0 (in1[2]), .A1 (mul_34_8_n_1), .B0
       (in2[7]), .B1 (mul_34_8_n_5), .Y (mul_34_8_n_53));
  MX2X1 mul_34_8_g2739(.A (mul_34_8_n_7), .B (in2[3]), .S0 (in2[4]), .Y
       (mul_34_8_n_52));
  MX2X1 mul_34_8_g2740(.A (mul_34_8_n_6), .B (in2[1]), .S0 (in2[2]), .Y
       (mul_34_8_n_51));
  INVX1 mul_34_8_g2741(.A (mul_34_8_n_42), .Y (mul_34_8_n_43));
  INVX1 mul_34_8_g2742(.A (mul_34_8_n_32), .Y (mul_34_8_n_33));
  OAI22X1 mul_34_8_g2743(.A0 (mul_34_8_n_2), .A1 (in2[1]), .B0
       (mul_34_8_n_6), .B1 (in1[0]), .Y (mul_34_8_n_29));
  OAI22X1 mul_34_8_g2744(.A0 (mul_34_8_n_6), .A1 (in2[0]), .B0
       (mul_34_8_n_9), .B1 (in2[1]), .Y (mul_34_8_n_28));
  AOI22X1 mul_34_8_g2745(.A0 (in1[0]), .A1 (mul_34_8_n_7), .B0
       (in2[3]), .B1 (mul_34_8_n_2), .Y (mul_34_8_n_27));
  AOI22X1 mul_34_8_g2746(.A0 (in1[0]), .A1 (mul_34_8_n_1), .B0
       (in2[7]), .B1 (mul_34_8_n_2), .Y (mul_34_8_n_26));
  AOI22X1 mul_34_8_g2747(.A0 (in1[0]), .A1 (mul_34_8_n_8), .B0
       (in2[5]), .B1 (mul_34_8_n_2), .Y (mul_34_8_n_25));
  AOI22X1 mul_34_8_g2748(.A0 (in1[5]), .A1 (mul_34_8_n_8), .B0
       (in2[5]), .B1 (mul_34_8_n_11), .Y (mul_34_8_n_46));
  AOI22X1 mul_34_8_g2749(.A0 (in1[4]), .A1 (mul_34_8_n_8), .B0
       (in2[5]), .B1 (mul_34_8_n_3), .Y (mul_34_8_n_45));
  OAI22X1 mul_34_8_g2750(.A0 (mul_34_8_n_12), .A1 (in2[3]), .B0
       (mul_34_8_n_7), .B1 (in1[7]), .Y (mul_34_8_n_44));
  AOI22X1 mul_34_8_g2751(.A0 (in1[7]), .A1 (mul_34_8_n_8), .B0
       (in2[5]), .B1 (mul_34_8_n_12), .Y (mul_34_8_n_42));
  AOI22X1 mul_34_8_g2752(.A0 (in1[4]), .A1 (mul_34_8_n_7), .B0
       (in2[3]), .B1 (mul_34_8_n_3), .Y (mul_34_8_n_41));
  AOI22X1 mul_34_8_g2753(.A0 (in1[2]), .A1 (mul_34_8_n_8), .B0
       (in2[5]), .B1 (mul_34_8_n_5), .Y (mul_34_8_n_40));
  AOI22X1 mul_34_8_g2754(.A0 (in1[1]), .A1 (mul_34_8_n_8), .B0
       (in2[5]), .B1 (mul_34_8_n_13), .Y (mul_34_8_n_39));
  AOI22X1 mul_34_8_g2755(.A0 (in1[2]), .A1 (mul_34_8_n_7), .B0
       (in2[3]), .B1 (mul_34_8_n_5), .Y (mul_34_8_n_38));
  AOI22X1 mul_34_8_g2756(.A0 (in1[3]), .A1 (mul_34_8_n_7), .B0
       (in2[3]), .B1 (mul_34_8_n_4), .Y (mul_34_8_n_37));
  AOI22X1 mul_34_8_g2757(.A0 (in1[1]), .A1 (mul_34_8_n_7), .B0
       (in2[3]), .B1 (mul_34_8_n_13), .Y (mul_34_8_n_36));
  AOI22X1 mul_34_8_g2758(.A0 (in1[5]), .A1 (mul_34_8_n_7), .B0
       (in2[3]), .B1 (mul_34_8_n_11), .Y (mul_34_8_n_35));
  AOI22X1 mul_34_8_g2759(.A0 (in1[6]), .A1 (mul_34_8_n_8), .B0
       (in2[5]), .B1 (mul_34_8_n_10), .Y (mul_34_8_n_34));
  OAI22X1 mul_34_8_g2760(.A0 (mul_34_8_n_10), .A1 (in2[3]), .B0
       (mul_34_8_n_7), .B1 (in1[6]), .Y (mul_34_8_n_32));
  AOI22X1 mul_34_8_g2761(.A0 (in1[3]), .A1 (mul_34_8_n_8), .B0
       (in2[5]), .B1 (mul_34_8_n_4), .Y (mul_34_8_n_31));
  MX2X1 mul_34_8_g2762(.A (mul_34_8_n_8), .B (in2[5]), .S0 (in2[6]), .Y
       (mul_34_8_n_30));
  NAND2X1 mul_34_8_g2764(.A (in1[7]), .B (in2[7]), .Y (mul_34_8_n_23));
  NOR2X1 mul_34_8_g2765(.A (mul_34_8_n_11), .B (mul_34_8_n_1), .Y
       (mul_34_8_n_22));
  NOR2X1 mul_34_8_g2766(.A (mul_34_8_n_13), .B (mul_34_8_n_1), .Y
       (mul_34_8_n_21));
  NOR2X1 mul_34_8_g2767(.A (mul_34_8_n_10), .B (mul_34_8_n_1), .Y
       (mul_34_8_n_20));
  NAND2X1 mul_34_8_g2768(.A (in1[4]), .B (in2[7]), .Y (mul_34_8_n_24));
  NAND2X1 mul_34_8_g2769(.A (mul_34_8_n_2), .B (mul_34_8_n_7), .Y
       (mul_34_8_n_18));
  NAND2X1 mul_34_8_g2770(.A (mul_34_8_n_2), .B (mul_34_8_n_6), .Y
       (mul_34_8_n_17));
  NOR2X1 mul_34_8_g2771(.A (mul_34_8_n_2), .B (mul_34_8_n_9), .Y
       (out1[0]));
  NOR2X1 mul_34_8_g2772(.A (mul_34_8_n_4), .B (mul_34_8_n_1), .Y
       (mul_34_8_n_16));
  NOR2X1 mul_34_8_g2773(.A (mul_34_8_n_2), .B (mul_34_8_n_1), .Y
       (mul_34_8_n_15));
  NOR2X1 mul_34_8_g2774(.A (mul_34_8_n_5), .B (mul_34_8_n_1), .Y
       (mul_34_8_n_14));
  INVX1 mul_34_8_g2775(.A (in1[1]), .Y (mul_34_8_n_13));
  INVX1 mul_34_8_g2776(.A (in1[7]), .Y (mul_34_8_n_12));
  INVX1 mul_34_8_g2777(.A (in1[5]), .Y (mul_34_8_n_11));
  INVX1 mul_34_8_g2778(.A (in1[6]), .Y (mul_34_8_n_10));
  INVX1 mul_34_8_g2779(.A (in2[0]), .Y (mul_34_8_n_9));
  INVX1 mul_34_8_g2780(.A (in2[5]), .Y (mul_34_8_n_8));
  INVX1 mul_34_8_g2781(.A (in2[3]), .Y (mul_34_8_n_7));
  INVX1 mul_34_8_g2782(.A (in2[1]), .Y (mul_34_8_n_6));
  INVX1 mul_34_8_g2784(.A (in1[2]), .Y (mul_34_8_n_5));
  INVX1 mul_34_8_g2785(.A (in1[3]), .Y (mul_34_8_n_4));
  INVX1 mul_34_8_g2786(.A (in1[4]), .Y (mul_34_8_n_3));
  INVX1 mul_34_8_g2787(.A (in1[0]), .Y (mul_34_8_n_2));
  INVX1 mul_34_8_g2788(.A (in2[7]), .Y (mul_34_8_n_1));
  NAND2BX1 mul_34_8_g2(.AN (in2[6]), .B (mul_34_8_n_8), .Y
       (mul_34_8_n_0));
endmodule

