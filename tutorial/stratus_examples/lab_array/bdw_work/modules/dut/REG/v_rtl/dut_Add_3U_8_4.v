`timescale 1ps / 1ps
/*****************************************************************************
    Verilog RTL Description
    
    Generated at: 14:06:24 EST (-0500), Tuesday 17 November 2020
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

module dut_Add_3U_8_4 (
	in2,
	in1,
	out1
	); /* architecture "behavioural" */ 
input [2:0] in2,
	in1;
output [2:0] out1;
wire [2:0] asc001;

assign asc001 = 
	+(in2)
	+(in1);

assign out1 = asc001;
endmodule

/* CADENCE  urb3SQ4= : u9/ySgnYtBlWxVDRUQkU4ug= ** DO NOT EDIT THIS LINE ******/

