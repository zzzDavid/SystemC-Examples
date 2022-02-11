
// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 16 2020 23:44:33 EST (Nov 17 2020 04:44:33 UTC)

module test_mux_1_4(data0, data1, data2, data3, ctrl, out);
  input [0:0] data0, data1, data2, data3;
  input [3:0] ctrl;
  output [0:0] out;
  wire [0:0] data0, data1, data2, data3;
  wire [3:0] ctrl;
  wire [0:0] out;
  wire n_0, n_1;
  NAND2X1 g36(.A (n_1), .B (n_0), .Y (out));
  AOI22X1 g37(.A0 (data1), .A1 (ctrl[1]), .B0 (data2), .B1 (ctrl[2]),
       .Y (n_1));
  AOI22X1 g38(.A0 (data0), .A1 (ctrl[0]), .B0 (data3), .B1 (ctrl[3]),
       .Y (n_0));
endmodule

