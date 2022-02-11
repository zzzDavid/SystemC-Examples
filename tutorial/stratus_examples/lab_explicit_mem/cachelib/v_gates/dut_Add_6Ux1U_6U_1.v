`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 17 2020 14:53:14 EST (Nov 17 2020 19:53:14 UTC)

module dut_Add_6Ux1U_6U_1(in2, in1, out1);
  input [5:0] in2;
  input in1;
  output [5:0] out1;
  wire [5:0] in2;
  wire in1;
  wire [5:0] out1;
  wire inc_add_35_2_n_0, inc_add_35_2_n_2, inc_add_35_2_n_3,
       inc_add_35_2_n_4, inc_add_35_2_n_5, inc_add_35_2_n_6,
       inc_add_35_2_n_7, inc_add_35_2_n_8;
  wire inc_add_35_2_n_9, inc_add_35_2_n_11, inc_add_35_2_n_13,
       inc_add_35_2_n_15, inc_add_35_2_n_28, inc_add_35_2_n_30;
  MXI2X1 inc_add_35_2_g50(.A (inc_add_35_2_n_3), .B (in2[5]), .S0
       (inc_add_35_2_n_15), .Y (out1[5]));
  MXI2XL inc_add_35_2_g51(.A (inc_add_35_2_n_5), .B (in2[3]), .S0
       (inc_add_35_2_n_0), .Y (out1[3]));
  NOR2X2 inc_add_35_2_g53(.A (inc_add_35_2_n_4), .B
       (inc_add_35_2_n_13), .Y (inc_add_35_2_n_15));
  MXI2XL inc_add_35_2_g54(.A (inc_add_35_2_n_2), .B (in2[2]), .S0
       (inc_add_35_2_n_30), .Y (out1[2]));
  NAND2X4 inc_add_35_2_g57(.A (inc_add_35_2_n_9), .B
       (inc_add_35_2_n_11), .Y (inc_add_35_2_n_13));
  MXI2XL inc_add_35_2_g59(.A (in2[1]), .B (inc_add_35_2_n_6), .S0
       (inc_add_35_2_n_28), .Y (out1[1]));
  NOR2X6 inc_add_35_2_g60(.A (inc_add_35_2_n_6), .B (inc_add_35_2_n_8),
       .Y (inc_add_35_2_n_11));
  MXI2XL inc_add_35_2_g61(.A (inc_add_35_2_n_7), .B (in2[0]), .S0
       (in1), .Y (out1[0]));
  NOR2X4 inc_add_35_2_g62(.A (inc_add_35_2_n_5), .B (inc_add_35_2_n_2),
       .Y (inc_add_35_2_n_9));
  NAND2X8 inc_add_35_2_g63(.A (in2[0]), .B (in1), .Y
       (inc_add_35_2_n_8));
  INVX1 inc_add_35_2_g64(.A (in2[0]), .Y (inc_add_35_2_n_7));
  CLKINVX2 inc_add_35_2_g65(.A (in2[1]), .Y (inc_add_35_2_n_6));
  CLKINVX2 inc_add_35_2_g66(.A (in2[3]), .Y (inc_add_35_2_n_5));
  INVX1 inc_add_35_2_g67(.A (in2[4]), .Y (inc_add_35_2_n_4));
  INVXL inc_add_35_2_g68(.A (in2[5]), .Y (inc_add_35_2_n_3));
  CLKINVX2 inc_add_35_2_g69(.A (in2[2]), .Y (inc_add_35_2_n_2));
  MXI2XL inc_add_35_2_g2(.A (in2[4]), .B (inc_add_35_2_n_4), .S0
       (inc_add_35_2_n_13), .Y (out1[4]));
  NOR2BX1 inc_add_35_2_g70(.AN (inc_add_35_2_n_11), .B
       (inc_add_35_2_n_2), .Y (inc_add_35_2_n_0));
  BUFX2 inc_add_35_2_fopt(.A (inc_add_35_2_n_8), .Y
       (inc_add_35_2_n_28));
  BUFX2 inc_add_35_2_fopt72(.A (inc_add_35_2_n_11), .Y
       (inc_add_35_2_n_30));
endmodule

