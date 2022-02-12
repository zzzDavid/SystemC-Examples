//
// Verilog co-simulation wrapper module for the add_one module.

// This module contains the followng items:
//	- An instance of the verilog RTL module created by stratus_vlg.
//	- Wires and reg's connected to the ports of the RTL module.
//	- A clock generator using the project's clock frequency and connected to
//    the RTL module's clock port.
//
// The wires and reg's will be connected to sc_signals in the SystemC simulaton
// by esc_link_signals calls in the proxy module found in the add_one_cosim.h 
// file.

`timescale 1 ps / 1 ps

module add_one_cosim;

	reg clk;
	reg rst;
	wire add_one_x_busy;
	reg add_one_x_vld;
	reg[31:0] add_one_x_data;
	reg add_one_return_busy;
	wire add_one_return_vld;
	wire[31:0] add_one_return_data;


	`include "hub.v"

	add_one add_one0( .clk(clk),
	 .rst(rst),
	 .add_one_x_busy(add_one_x_busy),
	 .add_one_x_vld(add_one_x_vld),
	 .add_one_x_data(add_one_x_data),
	 .add_one_return_busy(add_one_return_busy),
	 .add_one_return_vld(add_one_return_vld),
	 .add_one_return_data(add_one_return_data) );


	// Variables that can be set externally
	reg clk_firstEdge;
	reg clk_initialized;
	reg clk_started;
	real clk_startTime;
	real clk_firstHalf;
	real clk_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    clk_firstEdge = 1'b1;
	    clk_startTime = 0.000;		// Offset from time 0 to first edge.
	    clk_firstHalf = 5.000;	// Delay for first half of cycle.
	    clk_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on clk_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( clk_initialized !== 1'b1 )
	        @( clk_initialized );
	
	    if ( clk_startTime > 0.0 ) begin
	        clk_started = #clk_startTime 1;
	    end
	    else begin
	        clk_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( add_one0.clk ) begin
	    if ( clk_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( clk_started !== 1'b1 )
	        @( clk_started );
	
	    clk <= clk_firstEdge;
	    if ( clk_firstHalf > 0.0 ) begin
	        #clk_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        clk = ~clk_firstEdge;
	    end
	    else begin
	        clk = ~clk_firstEdge;
	    end
	    if ( clk_secondHalf > 0.0 ) begin
	        #clk_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg rst_firstEdge;
	reg rst_initialized;
	reg rst_started;
	real rst_startTime;
	real rst_firstHalf;
	real rst_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    rst_firstEdge = 1'b1;
	    rst_startTime = 0.000;		// Offset from time 0 to first edge.
	    rst_firstHalf = 5.000;	// Delay for first half of cycle.
	    rst_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on rst_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( rst_initialized !== 1'b1 )
	        @( rst_initialized );
	
	    if ( rst_startTime > 0.0 ) begin
	        rst_started = #rst_startTime 1;
	    end
	    else begin
	        rst_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( add_one0.rst ) begin
	    if ( rst_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( rst_started !== 1'b1 )
	        @( rst_started );
	
	    rst <= rst_firstEdge;
	    if ( rst_firstHalf > 0.0 ) begin
	        #rst_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        rst = ~rst_firstEdge;
	    end
	    else begin
	        rst = ~rst_firstEdge;
	    end
	    if ( rst_secondHalf > 0.0 ) begin
	        #rst_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg add_one_x_vld_firstEdge;
	reg add_one_x_vld_initialized;
	reg add_one_x_vld_started;
	real add_one_x_vld_startTime;
	real add_one_x_vld_firstHalf;
	real add_one_x_vld_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    add_one_x_vld_firstEdge = 1'b1;
	    add_one_x_vld_startTime = 0.000;		// Offset from time 0 to first edge.
	    add_one_x_vld_firstHalf = 5.000;	// Delay for first half of cycle.
	    add_one_x_vld_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on add_one_x_vld_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( add_one_x_vld_initialized !== 1'b1 )
	        @( add_one_x_vld_initialized );
	
	    if ( add_one_x_vld_startTime > 0.0 ) begin
	        add_one_x_vld_started = #add_one_x_vld_startTime 1;
	    end
	    else begin
	        add_one_x_vld_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( add_one0.add_one_x_vld ) begin
	    if ( add_one_x_vld_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( add_one_x_vld_started !== 1'b1 )
	        @( add_one_x_vld_started );
	
	    add_one_x_vld <= add_one_x_vld_firstEdge;
	    if ( add_one_x_vld_firstHalf > 0.0 ) begin
	        #add_one_x_vld_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        add_one_x_vld = ~add_one_x_vld_firstEdge;
	    end
	    else begin
	        add_one_x_vld = ~add_one_x_vld_firstEdge;
	    end
	    if ( add_one_x_vld_secondHalf > 0.0 ) begin
	        #add_one_x_vld_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg add_one_return_busy_firstEdge;
	reg add_one_return_busy_initialized;
	reg add_one_return_busy_started;
	real add_one_return_busy_startTime;
	real add_one_return_busy_firstHalf;
	real add_one_return_busy_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    add_one_return_busy_firstEdge = 1'b1;
	    add_one_return_busy_startTime = 0.000;		// Offset from time 0 to first edge.
	    add_one_return_busy_firstHalf = 5.000;	// Delay for first half of cycle.
	    add_one_return_busy_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on add_one_return_busy_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( add_one_return_busy_initialized !== 1'b1 )
	        @( add_one_return_busy_initialized );
	
	    if ( add_one_return_busy_startTime > 0.0 ) begin
	        add_one_return_busy_started = #add_one_return_busy_startTime 1;
	    end
	    else begin
	        add_one_return_busy_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( add_one0.add_one_return_busy ) begin
	    if ( add_one_return_busy_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( add_one_return_busy_started !== 1'b1 )
	        @( add_one_return_busy_started );
	
	    add_one_return_busy <= add_one_return_busy_firstEdge;
	    if ( add_one_return_busy_firstHalf > 0.0 ) begin
	        #add_one_return_busy_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        add_one_return_busy = ~add_one_return_busy_firstEdge;
	    end
	    else begin
	        add_one_return_busy = ~add_one_return_busy_firstEdge;
	    end
	    if ( add_one_return_busy_secondHalf > 0.0 ) begin
	        #add_one_return_busy_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end


endmodule
