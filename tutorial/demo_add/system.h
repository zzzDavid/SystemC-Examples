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

#ifndef _SYSTEM_H_
#define _SYSTEM_H_

// Include some required files.
#include <systemc.h>            // SystemC definitions.
#include <esc.h>                // Cadence ESC functions and utilities.
#include <stratus_hls.h>        // Cadence Stratus definitions.
#include <cynw_p2p.h>           // The cynw_p2p communication channel.
#include "defines.h"
#include "tb.h"
#include "dut_wrap.h"		// use the generated wrapper for all hls_modules

SC_MODULE( System )
{
	// clock and reset signals
	sc_clock clk_sig;
	sc_signal< bool > rst_sig;

	// cynw_p2p channels
	cynw_p2p< input_t >	in_chan_1;	// For data going into the design
	cynw_p2p< input_t >	in_chan_2;	// For data going into the design
	cynw_p2p< output_t >	out_chan;	// For data coming out of the design

	// The testbench and DUT modules.
	dut_wrapper	*m_dut;		// use the generated wrapper for the DUT hls module
	tb		*m_tb;

	SC_CTOR( System )
	: clk_sig( "clk_sig", CLOCK_PERIOD, SC_NS )
	, rst_sig( "rst_sig" )
	, in_chan_1( "in_chan_1" )
	, in_chan_2( "in_chan_2" )
	, out_chan( "out_chan" )
	{
		// Connect the design module
		m_dut = new dut_wrapper( "dut_wrapper" );
		m_dut->clk( clk_sig );
		m_dut->rst( rst_sig );
		m_dut->din_1( in_chan_1 );
		m_dut->din_2( in_chan_2 );
		m_dut->dout( out_chan );

		// Connect the testbench
		m_tb = new tb( "tb" );
		m_tb->clk( clk_sig );
		m_tb->rst( rst_sig );
		m_tb->dout_1( in_chan_1 );
		m_tb->dout_2( in_chan_2 );
		m_tb->din( out_chan );
	}

	~System()
	{
		delete m_tb;
		delete m_dut;
	}
};

#endif // _SYSTEM_H_
