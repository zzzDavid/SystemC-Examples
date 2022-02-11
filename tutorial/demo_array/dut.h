

#ifndef DUT_H
#define DUT_H

#include <cynw_p2p.h>
#include "defines.h"

SC_MODULE( dut )
{
	// Declare the clock and reset ports
	sc_in< bool >	clk;
	sc_in< bool >	rst;

	// Declare the input port and the output port.
	// Structs input_t and output_t passed through the ports.
	cynw_p2p < input_t >::in	din_1;	// The input P2P port
	cynw_p2p < input_t >::in	din_2;	// The input P2P port
	cynw_p2p < output_t >::out	dout;	// The output P2P port

	SC_CTOR( dut )
	: clk( "clk" )
	, rst( "rst" )
	, din_1( "din_1" )
	, din_2( "din_2" )
	, dout( "dout" )
	{
// LAB EXERCISE: Add directives for FLAT, REG, and MEM configs
// NEW
//#if defined(MEM)
//        HLS_MAP_TO_MEMORY( mem, "ram_64x8" );
//#endif
//#if defined(REG)
//        HLS_MAP_TO_REG_BANK( mem );
//#endif

		SC_CTHREAD( thread1, clk.pos() );
		reset_signal_is( rst, 0 );

		// Connect the clk and rst signals to the modular interface ports
		din_1.clk_rst( clk, rst );
		din_2.clk_rst( clk, rst );
		dout.clk_rst( clk, rst );
	}

	// Declare the array
	// sc_uint<8> mem[64];

	void thread1(); // the thread function
};

// The thread function for the design
void dut::thread1()
{
	{
		HLS_DEFINE_PROTOCOL( "reset" );
		din_1.reset();
		din_2.reset();
		dout.reset();
		wait();
	}

	while( true )
    {
		input_t val_1 = din_1.get(); 
		input_t val_2 = din_2.get(); 
		output_t result = val_1 + val_2;
		dout.put( result );    
	}
}

#endif // DUT_H
