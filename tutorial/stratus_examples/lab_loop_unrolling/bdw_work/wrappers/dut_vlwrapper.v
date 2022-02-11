/****************************************************************************
*
*  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/
/****************************************************************************
*
* Verilog Verification wrapper module for the dut module.
*
* This module contains the followng items:
*	- A foreign module definition for use in instantiatin the type_wrapper module
*      which contains the BEH module instance.
*	- An instance of the type_wrapper foreign module.
*   - alwyas blocks each type_wrapper output.
*
****************************************************************************/

`timescale 1 ps / 1 ps

module dut_vlwrapper(
      clk,
       rst,
       din_busy,
       din_vld,
       din_data,
       dout_busy,
       dout_vld,
       dout_data

    );

	input clk;
	input rst;
	output din_busy;
	reg din_busy;
	wire m_din_busy;
	input din_vld;
	input [7:0] din_data;
	input dout_busy;
	output dout_vld;
	reg dout_vld;
	wire m_dout_vld;
	output [10:0] dout_data;
	reg[10:0] dout_data;
	wire [10:0] m_dout_data;


    // Instantiate the Verilog module that instantiates the SystemC module
    dut_type_wrapper dut_sc(
        .clk(clk),
         .rst(rst),
         .din_busy(m_din_busy),
         .din_vld(din_vld),
         .din_data(din_data),
         .dout_busy(dout_busy),
         .dout_vld(m_dout_vld),
         .dout_data(m_dout_data)

    );

    // Always blocks for non-blocking assignments of type_wrapper outputs to
    // Verilog Verificatoin wrapper outputs.

    always @(m_din_busy)
     begin
      din_busy <= m_din_busy;
     end
    always @(m_dout_vld)
     begin
      dout_vld <= m_dout_vld;
     end
    always @(m_dout_data)
     begin
      dout_data <= m_dout_data;
     end


endmodule

// This is an internal module that instantiates the user's SystemC input module
// using the Incisive foreign module instantiation feature.
// The name of the module and the names of the inputs and outputs must match
// with those defined in the SystemC type_wrapper module
module dut_type_wrapper(
      clk,
       rst,
       din_busy,
       din_vld,
       din_data,
       dout_busy,
       dout_vld,
       dout_data

    ) (* integer foreign = "SystemC";
    *);

	input clk;
	input rst;
	output din_busy;
	input din_vld;
	input [7:0] din_data;
	input dout_busy;
	output dout_vld;
	output [10:0] dout_data;


endmodule
