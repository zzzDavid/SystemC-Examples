//
// Verilog co-simulation wrapper module for the dut module.

// This module contains the followng items:
//	- An instance of the verilog RTL module created by cynthVLG.
//	- Wires and reg's connected to the ports of the RTL module.
//	- A clock generator using the project's clock frequency and connected to
//    the RTL module's clock port.
//
// The wires and reg's will be connected to sc_signals in the SystemC simulaton
// by esc_link_signals calls in the proxy module found in the dut_cosim.h 
// file.

`timescale 1 ps / 1 ps

module dut_cosim;

	reg clk;
	reg rst;
	wire din_1_busy;
	reg din_1_vld;
	reg[7:0] din_1_data;
	wire din_2_busy;
	reg din_2_vld;
	reg[7:0] din_2_data;
	reg dout_busy;
	wire dout_vld;
	wire[8:0] dout_data;


	`include "hub.v"

	dut dut0( .clk(clk),
	 .rst(rst),
	 .din_1_busy(din_1_busy),
	 .din_1_vld(din_1_vld),
	 .din_1_data(din_1_data),
	 .din_2_busy(din_2_busy),
	 .din_2_vld(din_2_vld),
	 .din_2_data(din_2_data),
	 .dout_busy(dout_busy),
	 .dout_vld(dout_vld),
	 .dout_data(dout_data) );


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
	always @( dut0.clk ) begin
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
	always @( dut0.rst ) begin
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
	reg din_1_vld_firstEdge;
	reg din_1_vld_initialized;
	reg din_1_vld_started;
	real din_1_vld_startTime;
	real din_1_vld_firstHalf;
	real din_1_vld_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    din_1_vld_firstEdge = 1'b1;
	    din_1_vld_startTime = 0.000;		// Offset from time 0 to first edge.
	    din_1_vld_firstHalf = 5.000;	// Delay for first half of cycle.
	    din_1_vld_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on din_1_vld_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( din_1_vld_initialized !== 1'b1 )
	        @( din_1_vld_initialized );
	
	    if ( din_1_vld_startTime > 0.0 ) begin
	        din_1_vld_started = #din_1_vld_startTime 1;
	    end
	    else begin
	        din_1_vld_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( dut0.din_1_vld ) begin
	    if ( din_1_vld_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( din_1_vld_started !== 1'b1 )
	        @( din_1_vld_started );
	
	    din_1_vld <= din_1_vld_firstEdge;
	    if ( din_1_vld_firstHalf > 0.0 ) begin
	        #din_1_vld_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        din_1_vld = ~din_1_vld_firstEdge;
	    end
	    else begin
	        din_1_vld = ~din_1_vld_firstEdge;
	    end
	    if ( din_1_vld_secondHalf > 0.0 ) begin
	        #din_1_vld_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg din_2_vld_firstEdge;
	reg din_2_vld_initialized;
	reg din_2_vld_started;
	real din_2_vld_startTime;
	real din_2_vld_firstHalf;
	real din_2_vld_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    din_2_vld_firstEdge = 1'b1;
	    din_2_vld_startTime = 0.000;		// Offset from time 0 to first edge.
	    din_2_vld_firstHalf = 5.000;	// Delay for first half of cycle.
	    din_2_vld_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on din_2_vld_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( din_2_vld_initialized !== 1'b1 )
	        @( din_2_vld_initialized );
	
	    if ( din_2_vld_startTime > 0.0 ) begin
	        din_2_vld_started = #din_2_vld_startTime 1;
	    end
	    else begin
	        din_2_vld_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( dut0.din_2_vld ) begin
	    if ( din_2_vld_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( din_2_vld_started !== 1'b1 )
	        @( din_2_vld_started );
	
	    din_2_vld <= din_2_vld_firstEdge;
	    if ( din_2_vld_firstHalf > 0.0 ) begin
	        #din_2_vld_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        din_2_vld = ~din_2_vld_firstEdge;
	    end
	    else begin
	        din_2_vld = ~din_2_vld_firstEdge;
	    end
	    if ( din_2_vld_secondHalf > 0.0 ) begin
	        #din_2_vld_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end
	// Variables that can be set externally
	reg dout_busy_firstEdge;
	reg dout_busy_initialized;
	reg dout_busy_started;
	real dout_busy_startTime;
	real dout_busy_firstHalf;
	real dout_busy_secondHalf;
	
	initial begin
	
	    // Only send values from SystemC to the simulator at clock edges.
	    hubSetOption("cycleOnly=1");
	
	    // Default values for config variables.  Values come from static clock.
	    dout_busy_firstEdge = 1'b1;
	    dout_busy_startTime = 0.000;		// Offset from time 0 to first edge.
	    dout_busy_firstHalf = 5.000;	// Delay for first half of cycle.
	    dout_busy_secondHalf = 5.000;	// Second half of cycle less offset value.
	
	    // Make sure that we detect the transition on dout_busy_initalized.
	    hubScheduleDelayedAssignments;
	
	    while ( dout_busy_initialized !== 1'b1 )
	        @( dout_busy_initialized );
	
	    if ( dout_busy_startTime > 0.0 ) begin
	        dout_busy_started = #dout_busy_startTime 1;
	    end
	    else begin
	        dout_busy_started = 1;
	    end
	end
	
	// Make sure that we process delayed assignments after the clock edge.
	always @( dut0.dout_busy ) begin
	    if ( dout_busy_started === 1'b1 ) begin
	        if ($time == top.cur_time) top.n_cur_time=top.n_cur_time-1;
	        else top.n_cur_time=0;
	        if (top.n_cur_time==0) begin
	            hubScheduleDelayedAssignments;
	        end
	    end
	end
	
	always begin
	    // Make sure our delays are non-zero before starting simulation.
	    while ( dout_busy_started !== 1'b1 )
	        @( dout_busy_started );
	
	    dout_busy <= dout_busy_firstEdge;
	    if ( dout_busy_firstHalf > 0.0 ) begin
	        #dout_busy_firstHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	        dout_busy = ~dout_busy_firstEdge;
	    end
	    else begin
	        dout_busy = ~dout_busy_firstEdge;
	    end
	    if ( dout_busy_secondHalf > 0.0 ) begin
	        #dout_busy_secondHalf;
	        if ($time==top.cur_time) begin
	            top.n_cur_time=top.n_cur_time+1;
	        end else begin
	            top.n_cur_time=1; top.cur_time=$time;
	        end
	    end
	end


endmodule
