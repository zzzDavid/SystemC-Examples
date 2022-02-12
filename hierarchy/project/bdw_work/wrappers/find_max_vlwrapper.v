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
* Verilog Verification wrapper module for the find_max module.
*
* This module contains the followng items:
*	- A foreign module definition for use in instantiatin the type_wrapper module
*      which contains the BEH module instance.
*	- An instance of the type_wrapper foreign module.
*   - alwyas blocks each type_wrapper output.
*
****************************************************************************/

`timescale 1 ps / 1 ps

module find_max_vlwrapper(
      clk,
       rst,
       find_max_x_busy,
       find_max_x_vld,
       find_max_x_data,
       find_max_return_busy,
       find_max_return_vld,
       find_max_return_data,
       add_one_x_out_busy,
       add_one_x_out_vld,
       add_one_x_out_data,
       add_one_return_in_busy,
       add_one_return_in_vld,
       add_one_return_in_data

    );

	input clk;
	input rst;
	output find_max_x_busy;
	reg find_max_x_busy;
	wire m_find_max_x_busy;
	input find_max_x_vld;
	input [31:0] find_max_x_data;
	input find_max_return_busy;
	output find_max_return_vld;
	reg find_max_return_vld;
	wire m_find_max_return_vld;
	output [31:0] find_max_return_data;
	reg[31:0] find_max_return_data;
	wire [31:0] m_find_max_return_data;
	input add_one_x_out_busy;
	output add_one_x_out_vld;
	reg add_one_x_out_vld;
	wire m_add_one_x_out_vld;
	output [31:0] add_one_x_out_data;
	reg[31:0] add_one_x_out_data;
	wire [31:0] m_add_one_x_out_data;
	output add_one_return_in_busy;
	reg add_one_return_in_busy;
	wire m_add_one_return_in_busy;
	input add_one_return_in_vld;
	input [31:0] add_one_return_in_data;


    // Instantiate the Verilog module that instantiates the SystemC module
    find_max_type_wrapper find_max_sc(
        .clk(clk),
         .rst(rst),
         .find_max_x_busy(m_find_max_x_busy),
         .find_max_x_vld(find_max_x_vld),
         .find_max_x_data(find_max_x_data),
         .find_max_return_busy(find_max_return_busy),
         .find_max_return_vld(m_find_max_return_vld),
         .find_max_return_data(m_find_max_return_data),
         .add_one_x_out_busy(add_one_x_out_busy),
         .add_one_x_out_vld(m_add_one_x_out_vld),
         .add_one_x_out_data(m_add_one_x_out_data),
         .add_one_return_in_busy(m_add_one_return_in_busy),
         .add_one_return_in_vld(add_one_return_in_vld),
         .add_one_return_in_data(add_one_return_in_data)

    );

    // Always blocks for non-blocking assignments of type_wrapper outputs to
    // Verilog Verificatoin wrapper outputs.

    always @(m_find_max_x_busy)
     begin
      find_max_x_busy <= m_find_max_x_busy;
     end
    always @(m_find_max_return_vld)
     begin
      find_max_return_vld <= m_find_max_return_vld;
     end
    always @(m_find_max_return_data)
     begin
      find_max_return_data <= m_find_max_return_data;
     end
    always @(m_add_one_x_out_vld)
     begin
      add_one_x_out_vld <= m_add_one_x_out_vld;
     end
    always @(m_add_one_x_out_data)
     begin
      add_one_x_out_data <= m_add_one_x_out_data;
     end
    always @(m_add_one_return_in_busy)
     begin
      add_one_return_in_busy <= m_add_one_return_in_busy;
     end


endmodule

// This is an internal module that instantiates the user's SystemC input module
// using the Incisive foreign module instantiation feature.
// The name of the module and the names of the inputs and outputs must match
// with those defined in the SystemC type_wrapper module
module find_max_type_wrapper(
      clk,
       rst,
       find_max_x_busy,
       find_max_x_vld,
       find_max_x_data,
       find_max_return_busy,
       find_max_return_vld,
       find_max_return_data,
       add_one_x_out_busy,
       add_one_x_out_vld,
       add_one_x_out_data,
       add_one_return_in_busy,
       add_one_return_in_vld,
       add_one_return_in_data

    ) (* integer foreign = "SystemC";
    *);

	input clk;
	input rst;
	output find_max_x_busy;
	input find_max_x_vld;
	input [31:0] find_max_x_data;
	input find_max_return_busy;
	output find_max_return_vld;
	output [31:0] find_max_return_data;
	input add_one_x_out_busy;
	output add_one_x_out_vld;
	output [31:0] add_one_x_out_data;
	output add_one_return_in_busy;
	input add_one_return_in_vld;
	input [31:0] add_one_return_in_data;


endmodule
