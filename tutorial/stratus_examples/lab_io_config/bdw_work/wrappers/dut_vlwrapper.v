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
      `ifdef ioConfig_TLM
      
      clk,
       rst
      `endif
      `ifdef ioConfig_PIN
      
      clk,
       rst
      `endif

    );

	`ifdef ioConfig_TLM
	
	input clk;
	input rst;
	
	`endif
	`ifdef ioConfig_PIN
	
	input clk;
	input rst;
	
	`endif


    // Instantiate the Verilog module that instantiates the SystemC module
    dut_type_wrapper dut_sc(
        `ifdef ioConfig_TLM
        
        .clk(clk),
         .rst(rst)
        `endif
        `ifdef ioConfig_PIN
        
        .clk(clk),
         .rst(rst)
        `endif

    );

    // Always blocks for non-blocking assignments of type_wrapper outputs to
    // Verilog Verificatoin wrapper outputs.

    `ifdef ioConfig_TLM
    
    
    `endif
    `ifdef ioConfig_PIN
    
    
    `endif


endmodule

// This is an internal module that instantiates the user's SystemC input module
// using the Incisive foreign module instantiation feature.
// The name of the module and the names of the inputs and outputs must match
// with those defined in the SystemC type_wrapper module
module dut_type_wrapper(
      `ifdef ioConfig_TLM
      
      clk,
       rst
      `endif
      `ifdef ioConfig_PIN
      
      clk,
       rst
      `endif

    ) (* integer foreign = "SystemC";
    *);

	`ifdef ioConfig_TLM
	
	input clk;
	input rst;
	
	`endif
	`ifdef ioConfig_PIN
	
	input clk;
	input rst;
	
	`endif


endmodule
