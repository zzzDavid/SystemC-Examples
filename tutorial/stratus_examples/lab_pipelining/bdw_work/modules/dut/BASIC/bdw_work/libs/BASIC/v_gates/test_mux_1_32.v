
// Generated by Cadence Genus(TM) Synthesis Solution 17.11-s014_1
// Generated on: Nov 18 2020 17:47:48 EST (Nov 18 2020 22:47:48 UTC)

module test_mux_1_32(data0, data1, data2, data3, data4, data5, data6,
     data7, data8, data9, data10, data11, data12, data13, data14,
     data15, data16, data17, data18, data19, data20, data21, data22,
     data23, data24, data25, data26, data27, data28, data29, data30,
     data31, ctrl, out);
  input [0:0] data0, data1, data2, data3, data4, data5, data6, data7,
       data8, data9, data10, data11, data12, data13, data14, data15,
       data16, data17, data18, data19, data20, data21, data22, data23,
       data24, data25, data26, data27, data28, data29, data30, data31;
  input [31:0] ctrl;
  output [0:0] out;
  wire [0:0] data0, data1, data2, data3, data4, data5, data6, data7,
       data8, data9, data10, data11, data12, data13, data14, data15,
       data16, data17, data18, data19, data20, data21, data22, data23,
       data24, data25, data26, data27, data28, data29, data30, data31;
  wire [31:0] ctrl;
  wire [0:0] out;
  wire n_0, n_1, n_2, n_3, n_4, n_5, n_6, n_7;
  wire n_8, n_9, n_10, n_11, n_12, n_13, n_14, n_15;
  wire n_16, n_17, n_18, n_19;
  OR4X1 g1149(.A (n_17), .B (n_19), .C (n_18), .D (n_16), .Y (out));
  NAND4XL g1150(.A (n_10), .B (n_15), .C (n_5), .D (n_0), .Y (n_19));
  NAND4XL g1151(.A (n_1), .B (n_3), .C (n_13), .D (n_9), .Y (n_18));
  NAND4XL g1152(.A (n_4), .B (n_2), .C (n_14), .D (n_7), .Y (n_17));
  NAND4XL g1153(.A (n_6), .B (n_8), .C (n_11), .D (n_12), .Y (n_16));
  AOI22X1 g1160(.A0 (data28), .A1 (ctrl[28]), .B0 (data29), .B1
       (ctrl[29]), .Y (n_15));
  AOI22X1 g1154(.A0 (data19), .A1 (ctrl[19]), .B0 (data20), .B1
       (ctrl[20]), .Y (n_14));
  AOI22X1 g1159(.A0 (data3), .A1 (ctrl[3]), .B0 (data4), .B1 (ctrl[4]),
       .Y (n_13));
  AOI22X1 g1169(.A0 (data0), .A1 (ctrl[0]), .B0 (data8), .B1 (ctrl[8]),
       .Y (n_12));
  AOI22X1 g1168(.A0 (data9), .A1 (ctrl[9]), .B0 (data10), .B1
       (ctrl[10]), .Y (n_11));
  AOI22X1 g1155(.A0 (data30), .A1 (ctrl[30]), .B0 (data31), .B1
       (ctrl[31]), .Y (n_10));
  AOI22X1 g1161(.A0 (data1), .A1 (ctrl[1]), .B0 (data2), .B1 (ctrl[2]),
       .Y (n_9));
  AOI22X1 g1162(.A0 (data12), .A1 (ctrl[12]), .B0 (data13), .B1
       (ctrl[13]), .Y (n_8));
  AOI22X1 g1165(.A0 (data17), .A1 (ctrl[17]), .B0 (data18), .B1
       (ctrl[18]), .Y (n_7));
  AOI22X1 g1163(.A0 (data14), .A1 (ctrl[14]), .B0 (data15), .B1
       (ctrl[15]), .Y (n_6));
  AOI22X1 g1164(.A0 (data26), .A1 (ctrl[26]), .B0 (data27), .B1
       (ctrl[27]), .Y (n_5));
  AOI22X1 g1157(.A0 (data23), .A1 (ctrl[23]), .B0 (data25), .B1
       (ctrl[25]), .Y (n_4));
  AOI22X1 g1156(.A0 (data5), .A1 (ctrl[5]), .B0 (data6), .B1 (ctrl[6]),
       .Y (n_3));
  AOI22X1 g1166(.A0 (data21), .A1 (ctrl[21]), .B0 (data22), .B1
       (ctrl[22]), .Y (n_2));
  AOI22X1 g1158(.A0 (data7), .A1 (ctrl[7]), .B0 (data11), .B1
       (ctrl[11]), .Y (n_1));
  AOI22X1 g1167(.A0 (data16), .A1 (ctrl[16]), .B0 (data24), .B1
       (ctrl[24]), .Y (n_0));
endmodule

