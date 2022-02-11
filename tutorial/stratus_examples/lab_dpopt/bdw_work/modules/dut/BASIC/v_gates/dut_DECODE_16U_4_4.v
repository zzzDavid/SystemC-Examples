`timescale 1ps / 1ps

// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 18 2020 11:32:35 EST (Nov 18 2020 16:32:35 UTC)

module dut_DECODE_16U_4_4(in1, out1);
  input [3:0] in1;
  output [15:0] out1;
  wire [3:0] in1;
  wire [15:0] out1;
  wire n_5, n_7, n_10, n_11, n_14, n_16, n_19, n_21;
  NOR2X1 g135(.A (n_19), .B (n_21), .Y (out1[10]));
  NOR2X1 g134(.A (n_7), .B (n_21), .Y (out1[12]));
  NOR2X1 g132(.A (n_16), .B (n_19), .Y (out1[11]));
  NOR2BX1 g123(.AN (n_14), .B (n_10), .Y (out1[1]));
  NOR2X1 g124(.A (n_11), .B (n_16), .Y (out1[15]));
  NOR2BX1 g122(.AN (n_14), .B (n_16), .Y (out1[9]));
  NOR2BX1 g120(.AN (n_14), .B (n_21), .Y (out1[8]));
  NOR2X1 g125(.A (n_11), .B (n_10), .Y (out1[7]));
  NOR2BX1 g130(.AN (n_5), .B (n_19), .Y (out1[2]));
  NOR2X1 g133(.A (n_10), .B (n_7), .Y (out1[5]));
  NOR2BX1 g129(.AN (n_5), .B (n_7), .Y (out1[4]));
  NOR2X1 g128(.A (n_10), .B (n_19), .Y (out1[3]));
  NOR2BX1 g127(.AN (n_5), .B (n_11), .Y (out1[6]));
  AND2XL g131(.A (n_14), .B (n_5), .Y (out1[0]));
  NOR2X1 g121(.A (n_11), .B (n_21), .Y (out1[14]));
  NOR2X1 g126(.A (n_16), .B (n_7), .Y (out1[13]));
  NAND2BX1 g136(.AN (in1[0]), .B (in1[3]), .Y (n_21));
  NOR2X1 g137(.A (in1[2]), .B (in1[1]), .Y (n_14));
  NAND2X1 g141(.A (in1[3]), .B (in1[0]), .Y (n_16));
  NAND2BX1 g142(.AN (in1[1]), .B (in1[2]), .Y (n_7));
  NOR2X1 g140(.A (in1[3]), .B (in1[0]), .Y (n_5));
  NAND2BX1 g143(.AN (in1[2]), .B (in1[1]), .Y (n_19));
  NAND2BX1 g139(.AN (in1[3]), .B (in1[0]), .Y (n_10));
  NAND2X1 g138(.A (in1[2]), .B (in1[1]), .Y (n_11));
endmodule

