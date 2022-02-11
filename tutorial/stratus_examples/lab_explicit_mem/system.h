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

#ifndef SYSTEM_H
#define SYSTEM_H

#include <systemc.h>
#include <cynw_p2p.h>
#include "defines.h"
#include "tb.h"

// LAB EXERCISE: Include memory header file
// NEW
#include "memlib.h"

#include "dut_wrap.h" // use the generated wrapper for all HLS modules

SC_MODULE( System )
{
	// clock and reset signals
	sc_clock		clk_sig;
	sc_signal< bool >	rst_sig;

	// cynw_p2p channels
	cynw_p2p< input_t >	chan1;
	cynw_p2p< output_t >	chan2;

	// Declare pointers for the testbench and dut modules
	dut_wrapper	*m_dut; // use the generated wrapper for all HLS modules
	tb		*m_tb;

	// LAB EXERCISE: Declare a pointer for the memory
	// NEW
    RAM_64x8::wrapper<> *m_mem;

	SC_CTOR( System )
	: clk_sig( "clk_sig", CLOCK_PERIOD, SC_NS )
	, rst_sig( "rst_sig" )
	, chan1( "chan1" )
	, chan2( "chan2" )
	{
		// Connect the design module
		m_dut = new dut_wrapper( "dut_wrapper" );
		m_dut->clk( clk_sig );
		m_dut->rst( rst_sig );
		m_dut->din( chan1 );
		m_dut->dout( chan2 );
		
		// Connect the testbench
		m_tb = new tb( "tb" );
		m_tb->clk( clk_sig );
		m_tb->rst( rst_sig );
		m_tb->dout( chan1 );
		m_tb->din( chan2 );
		
		// LAB EXERCISE: Instantiate and connect the memory
		// NEW
        m_mem = new RAM_64x8::wrapper<>("mem");
        m_dut->mem( *m_mem );
        m_mem->clk_rst( clk_sig, rst_sig );
	}

	~System()
	{
		delete m_tb;
		delete m_dut;
	}
};

#endif // SYSTEM_H
