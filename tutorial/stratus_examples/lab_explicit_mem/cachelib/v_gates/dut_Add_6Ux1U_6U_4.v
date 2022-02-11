`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 17 2020 14:53:09 EST (Nov 17 2020 19:53:09 UTC)

module dut_Add_6Ux1U_6U_4(in2, in1, out1);
  input [5:0] in2;
  input in1;
  output [5:0] out1;
  wire [5:0] in2;
  wire in1;
  wire [5:0] out1;
  wire inc_add_35_2_n_0, inc_add_35_2_n_2, inc_add_35_2_n_4,
       inc_add_35_2_n_6, inc_add_35_2_n_8;
  XNOR2X1 inc_add_35_2_g51(.A (in2[5]), .B (inc_add_35_2_n_8), .Y
       (out1[5]));
  XNOR2X1 inc_add_35_2_g52(.A (in2[4]), .B (inc_add_35_2_n_6), .Y
       (out1[4]));
  NAND2BX1 inc_add_35_2_g53(.AN (inc_add_35_2_n_6), .B (in2[4]), .Y
       (inc_add_35_2_n_8));
  XNOR2X1 inc_add_35_2_g54(.A (in2[3]), .B (inc_add_35_2_n_4), .Y
       (out1[3]));
  NAND2BX1 inc_add_35_2_g55(.AN (inc_add_35_2_n_4), .B (in2[3]), .Y
       (inc_add_35_2_n_6));
  XNOR2X1 inc_add_35_2_g56(.A (in2[2]), .B (inc_add_35_2_n_2), .Y
       (out1[2]));
  NAND2BX1 inc_add_35_2_g57(.AN (inc_add_35_2_n_2), .B (in2[2]), .Y
       (inc_add_35_2_n_4));
  XNOR2X1 inc_add_35_2_g58(.A (in2[1]), .B (inc_add_35_2_n_0), .Y
       (out1[1]));
  NAND2BX1 inc_add_35_2_g59(.AN (inc_add_35_2_n_0), .B (in2[1]), .Y
       (inc_add_35_2_n_2));
  XOR2XL inc_add_35_2_g60(.A (in2[0]), .B (in1), .Y (out1[0]));
  NAND2X1 inc_add_35_2_g61(.A (in2[0]), .B (in1), .Y
       (inc_add_35_2_n_0));
endmodule

