`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 17 2020 14:53:19 EST (Nov 17 2020 19:53:19 UTC)

module dut_Add_3U_1_4(in2, in1, out1);
  input [2:0] in2, in1;
  output [2:0] out1;
  wire [2:0] in2, in1;
  wire [2:0] out1;
  wire add_35_2_n_0, add_35_2_n_1, add_35_2_n_3;
  XNOR2X1 add_35_2_g68(.A (add_35_2_n_0), .B (add_35_2_n_3), .Y
       (out1[2]));
  ADDFX1 add_35_2_g69(.A (add_35_2_n_1), .B (in1[1]), .CI (in2[1]), .CO
       (add_35_2_n_3), .S (out1[1]));
  ADDHX1 add_35_2_g70(.A (in2[0]), .B (in1[0]), .CO (add_35_2_n_1), .S
       (out1[0]));
  XNOR2X1 add_35_2_g71(.A (in2[2]), .B (in1[2]), .Y (add_35_2_n_0));
endmodule


