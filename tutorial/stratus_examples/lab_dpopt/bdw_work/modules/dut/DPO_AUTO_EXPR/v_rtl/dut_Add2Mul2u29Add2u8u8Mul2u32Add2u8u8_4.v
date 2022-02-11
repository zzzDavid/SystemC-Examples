`timescale 1ps / 1ps
/*****************************************************************************
    Verilog RTL Description
    
    Generated at: 11:34:51 EST (-0500), Wednesday 18 November 2020
    Generated on: zhang-x1.ece.cornell.edu
    Generated by: jl3952 (Jie Liu)
    
    Created by: Stratus DpOpt 2017.1.02 
    Copyright (c) 2014-2015 Cadence Design Systems. All rights reserved worldwide.
    
    Cadence Design Systems proprietary and confidential
    ===================================================
    
    May contain information that incorporates Cadence Design Systems CellMath
    and other inventions claimed in Pending U.S. Patents.
    
    May contain Cadence Design Systems Trade Secrets of which use, disclosure or
    reproduction is contractually restricted or prohibited.  For more
    information, contact your legal department before any use, disclosure or
    reproduction.
*******************************************************************************/

module dut_Add2Mul2u29Add2u8u8Mul2u32Add2u8u8_4 (
	in6,
	in5,
	in4,
	in3,
	in2,
	in1,
	out1
	); /* architecture "behavioural" */ 
input [7:0] in6,
	in5;
input [31:0] in4;
input [7:0] in3,
	in2;
input [28:0] in1;
output [31:0] out1;
wire [31:0] asc001;
wire [8:0] asc002,
	asc003;

assign asc002 = 
	+(in6)
	+(in5);

assign asc003 = 
	+(in3)
	+(in2);

wire [31:0] asc001_tmp_0;
assign asc001_tmp_0 = 
	+(in4 * asc002);
assign asc001 = asc001_tmp_0
	+(in1 * asc003);

assign out1 = asc001;
endmodule

/* CADENCE  v7jzTwo= : u9/ySgnYtBlWxVDRUQkU4ug= ** DO NOT EDIT THIS LINE ******/

