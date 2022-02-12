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
* Verilog Verification wrapper module for the add_one module.
*
* This module contains the followng items:
*	- A foreign module definition for use in instantiatin the type_wrapper module
*      which contains the BEH module instance.
*	- An instance of the type_wrapper foreign module.
*   - alwyas blocks each type_wrapper output.
*
****************************************************************************/

`timescale 1 ps / 1 ps

module add_one_vlwrapper(
      clk,
       rst,
       add_one_x_busy,
       add_one_x_vld,
       add_one_x_data,
       add_one_return_busy,
       add_one_return_vld,
       add_one_return_data

    );

	input clk;
	input rst;
	output add_one_x_busy;
	reg add_one_x_busy;
	wire m_add_one_x_busy;
	input add_one_x_vld;
	input [31:0] add_one_x_data;
	input add_one_return_busy;
	output add_one_return_vld;
	reg add_one_return_vld;
	wire m_add_one_return_vld;
	output [31:0] add_one_return_data;
	reg[31:0] add_one_return_data;
	wire [31:0] m_add_one_return_data;


    // Instantiate the Verilog module that instantiates the SystemC module
    add_one_type_wrapper add_one_sc(
        .clk(clk),
         .rst(rst),
         .add_one_x_busy(m_add_one_x_busy),
         .add_one_x_vld(add_one_x_vld),
         .add_one_x_data(add_one_x_data),
         .add_one_return_busy(add_one_return_busy),
         .add_one_return_vld(m_add_one_return_vld),
         .add_one_return_data(m_add_one_return_data)

    );

    // Always blocks for non-blocking assignments of type_wrapper outputs to
    // Verilog Verificatoin wrapper outputs.

    always @(m_add_one_x_busy)
     begin
      add_one_x_busy <= m_add_one_x_busy;
     end
    always @(m_add_one_return_vld)
     begin
      add_one_return_vld <= m_add_one_return_vld;
     end
    always @(m_add_one_return_data)
     begin
      add_one_return_data <= m_add_one_return_data;
     end


endmodule

// This is an internal module that instantiates the user's SystemC input module
// using the Incisive foreign module instantiation feature.
// The name of the module and the names of the inputs and outputs must match
// with those defined in the SystemC type_wrapper module
module add_one_type_wrapper(
      clk,
       rst,
       add_one_x_busy,
       add_one_x_vld,
       add_one_x_data,
       add_one_return_busy,
       add_one_return_vld,
       add_one_return_data

    ) (* integer foreign = "SystemC";
    *);

	input clk;
	input rst;
	output add_one_x_busy;
	input add_one_x_vld;
	input [31:0] add_one_x_data;
	input add_one_return_busy;
	output add_one_return_vld;
	output [31:0] add_one_return_data;


endmodule
