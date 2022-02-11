//
// Top-level Verilog module

// One of these modules is created for each testcase that involves
// co-simulation.  This one is for the 'DPO_INLINE_V' testcase.
// The top-level module contains:
//	- An instances of a co-simulation wrapper module for each instance
//	  simulating in Verilog.
//	- Hub initialization calls that load the shared library for the
//	  simulation.
//
// You can add any other legal Verilog to this template file, and it appear in
// the verilog module.

`timescale 1 ps / 1 ps

module top;

	// RTL wrapper instances for cosim.
	dut_cosim dut0();


	integer n_cur_time;
	initial n_cur_time=0;
	reg [63:0] cur_time;
	initial cur_time=0;

	`include "hub.v"

	// Load library and begin co-simulation.
	initial begin

        // For gate-level simulations we back-annotate the instances with delays
        // from the SDF file
        

		// Open the trace file if that's appropriate.
		if ( hubCurrentProjectDoesTrace( hub_trace_vcd ) )
			$dumpfile( "bdw_work/sims/DPO_INLINE_V/verilog.vcd" );
		if ( hubCurrentProjectDoesTrace( hub_trace_vcd ) ) begin
		$dumpvars( 0, dut0.clk );
		$dumpvars( 0, dut0.rst );
		$dumpvars( 0, dut0.din_busy );
		$dumpvars( 0, dut0.din_vld );
		$dumpvars( 0, dut0.din_data_a );
		$dumpvars( 0, dut0.din_data_b );
		$dumpvars( 0, dut0.din_data_c );
		$dumpvars( 0, dut0.din_data_d );
		$dumpvars( 0, dut0.din_data_e );
		$dumpvars( 0, dut0.din_data_f );
		$dumpvars( 0, dut0.din_data_g );
		$dumpvars( 0, dut0.din_data_h );
		$dumpvars( 0, dut0.dout_busy );
		$dumpvars( 0, dut0.dout_vld );
		$dumpvars( 0, dut0.dout_data );
			$dumpvars( 4, dut0.dut0 );
		end


		// If the SystemC shared library will be loaded using +qbSetOption+libdef=libname.so
		// from the Verilog simulator's command line, the following line can be left
		// out.  In order to load the shared library directly from Verilog, uncomment
		// the following line using either ther automatically generated SIM_EXEC string,
		// or a hard-coded string giving the path to the shared library.
		//hubLoadLibrary( "bdw_work/sims/DPO_INLINE_V/sim_DPO_INLINE_V.so", "" );

		// Begin a co-simulation.
		// This task returns after esc_end_cosim() is called from SystemC.
		hubStartCosim;
		#100 $stop;
	end
endmodule

//
// The following wrapper modules are used only for NCSim cosims.
//

`ifdef BDW_NCSC

module dut_nc_cosim(clk,
 rst,
 din_busy,
 din_vld,
 din_data_a,
 din_data_b,
 din_data_c,
 din_data_d,
 din_data_e,
 din_data_f,
 din_data_g,
 din_data_h,
 dout_busy,
 dout_vld,
 dout_data
);

input clk;
wire clk;
input rst;
wire rst;
output din_busy;
wire din_busy;
input din_vld;
wire din_vld;
input [7:0] din_data_a;
input [7:0] din_data_b;
input [7:0] din_data_c;
input [7:0] din_data_d;
input [7:0] din_data_e;
input [7:0] din_data_f;
input [7:0] din_data_g;
input [7:0] din_data_h;
wire[7:0] din_data_a;
wire[7:0] din_data_b;
wire[7:0] din_data_c;
wire[7:0] din_data_d;
wire[7:0] din_data_e;
wire[7:0] din_data_f;
wire[7:0] din_data_g;
wire[7:0] din_data_h;
input dout_busy;
wire dout_busy;
output dout_vld;
wire dout_vld;
output dout_data;
wire[31:0] dout_data;

dut dut0( .clk(clk),
 .rst(rst),
 .din_busy(din_busy),
 .din_vld(din_vld),
 .din_data_a(din_data_a),
 .din_data_b(din_data_b),
 .din_data_c(din_data_c),
 .din_data_d(din_data_d),
 .din_data_e(din_data_e),
 .din_data_f(din_data_f),
 .din_data_g(din_data_g),
 .din_data_h(din_data_h),
 .dout_busy(dout_busy),
 .dout_vld(dout_vld),
 .dout_data(dout_data)
 );

   `include "hub.v"

   initial begin

if ( hubCurrentProjectDoesTrace( hub_trace_vcd ) )
	$dumpfile( "bdw_work/sims/DPO_INLINE_V/verilog.vcd" );
if ( hubCurrentProjectDoesTrace( hub_trace_vcd ) ) begin
$dumpvars( 0, dut0.clk );
$dumpvars( 0, dut0.rst );
$dumpvars( 0, dut0.din_busy );
$dumpvars( 0, dut0.din_vld );
$dumpvars( 0, dut0.din_data_a );
$dumpvars( 0, dut0.din_data_b );
$dumpvars( 0, dut0.din_data_c );
$dumpvars( 0, dut0.din_data_d );
$dumpvars( 0, dut0.din_data_e );
$dumpvars( 0, dut0.din_data_f );
$dumpvars( 0, dut0.din_data_g );
$dumpvars( 0, dut0.din_data_h );
$dumpvars( 0, dut0.dout_busy );
$dumpvars( 0, dut0.dout_vld );
$dumpvars( 0, dut0.dout_data );
	$dumpvars( 4, dut0 );
end
   end

endmodule


`endif


