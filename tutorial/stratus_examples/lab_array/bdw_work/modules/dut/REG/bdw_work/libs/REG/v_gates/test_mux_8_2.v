
// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 17 2020 14:06:00 EST (Nov 17 2020 19:06:00 UTC)

module test_mux_8_2(data0, data1, ctrl, out);
  input [7:0] data0, data1;
  input [1:0] ctrl;
  output [7:0] out;
  wire [7:0] data0, data1;
  wire [1:0] ctrl;
  wire [7:0] out;
  AO22XL g107(.A0 (data0[1]), .A1 (ctrl[0]), .B0 (data1[1]), .B1
       (ctrl[1]), .Y (out[1]));
  AO22XL g111(.A0 (data0[2]), .A1 (ctrl[0]), .B0 (data1[2]), .B1
       (ctrl[1]), .Y (out[2]));
  AO22XL g106(.A0 (data0[7]), .A1 (ctrl[0]), .B0 (data1[7]), .B1
       (ctrl[1]), .Y (out[7]));
  AO22XL g110(.A0 (data0[0]), .A1 (ctrl[0]), .B0 (data1[0]), .B1
       (ctrl[1]), .Y (out[0]));
  AO22XL g104(.A0 (data0[4]), .A1 (ctrl[0]), .B0 (data1[4]), .B1
       (ctrl[1]), .Y (out[4]));
  AO22XL g108(.A0 (data0[5]), .A1 (ctrl[0]), .B0 (data1[5]), .B1
       (ctrl[1]), .Y (out[5]));
  AO22XL g105(.A0 (data0[6]), .A1 (ctrl[0]), .B0 (data1[6]), .B1
       (ctrl[1]), .Y (out[6]));
  AO22XL g109(.A0 (data0[3]), .A1 (ctrl[0]), .B0 (data1[3]), .B1
       (ctrl[1]), .Y (out[3]));
endmodule

