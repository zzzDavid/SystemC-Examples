///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2017 Cadence Design Systems, Inc. All rights reserved worldwide.
//
// The code contained herein is the proprietary and confidential information
// of Cadence or its licensors, and is supplied subject to a previously
// executed license and maintenance agreement between Cadence and customer.
// This code is intended for use with Cadence high-level synthesis tools and
// may not be used with other high-level synthesis tools. Permission is only
// granted to distribute the code as indicated. Cadence grants permission for
// customer to distribute a copy of this code to any partner to aid in designing
// or verifying the customer's intellectual property, as long as such
// distribution includes a restriction of no additional distributions from the
// partner, unless the partner receives permission directly from Cadence.
//
// ALL CODE FURNISHED BY CADENCE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
// KIND, AND CADENCE SPECIFICALLY DISCLAIMS ANY WARRANTY OF NONINFRINGEMENT,
// FITNESS FOR A PARTICULAR PURPOSE OR MERCHANTABILITY. CADENCE SHALL NOT BE
// LIABLE FOR ANY COSTS OF PROCUREMENT OF SUBSTITUTES, LOSS OF PROFITS,
// INTERRUPTION OF BUSINESS, OR FOR ANY OTHER SPECIAL, CONSEQUENTIAL OR
// INCIDENTAL DAMAGES, HOWEVER CAUSED, WHETHER FOR BREACH OF WARRANTY,
// CONTRACT, TORT, NEGLIGENCE, STRICT LIABILITY OR OTHERWISE.
//
////////////////////////////////////////////////////////////////////////////////

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
	cynw_p2p < input_t >::in	din;	// The input P2P port
	cynw_p2p < output_t >::out	dout;	// The output P2P port

	SC_CTOR( dut )
	: clk( "clk" )
	, rst( "rst" )
	, din( "din" )
	, dout( "dout" )
	{
// LAB EXERCISE: Add directives for FLAT, REG, and MEM configs
// NEW
#if defined(MEM)
        HLS_MAP_TO_MEMORY( mem, "RAM_64x8" );
#endif
#if defined(REG)
        HLS_MAP_TO_REG_BANK( mem );
#endif

		SC_CTHREAD( thread1, clk.pos() );
		reset_signal_is( rst, 0 );

		// Connect the clk and rst signals to the modular interface ports
		din.clk_rst( clk, rst );
		dout.clk_rst( clk, rst );
	}

	// Declare the array
	sc_uint<8> mem[64];

	void thread1(); // the thread function
};

#endif // DUT_H
