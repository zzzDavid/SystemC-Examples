`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 17 2020 22:54:34 EST (Nov 18 2020 03:54:34 UTC)

module dut_Add_4U_1_4(in2, in1, out1);
  input [3:0] in2, in1;
  output [3:0] out1;
  wire [3:0] in2, in1;
  wire [3:0] out1;
  wire add_35_2_n_0, add_35_2_n_1, add_35_2_n_3, add_35_2_n_5;
  XNOR2X1 add_35_2_g97(.A (add_35_2_n_0), .B (add_35_2_n_5), .Y
       (out1[3]));
  ADDFX1 add_35_2_g98(.A (add_35_2_n_3), .B (in1[2]), .CI (in2[2]), .CO
       (add_35_2_n_5), .S (out1[2]));
  ADDFX1 add_35_2_g99(.A (add_35_2_n_1), .B (in1[1]), .CI (in2[1]), .CO
       (add_35_2_n_3), .S (out1[1]));
  ADDHX1 add_35_2_g100(.A (in2[0]), .B (in1[0]), .CO (add_35_2_n_1), .S
       (out1[0]));
  XNOR2X1 add_35_2_g101(.A (in2[3]), .B (in1[3]), .Y (add_35_2_n_0));
endmodule

