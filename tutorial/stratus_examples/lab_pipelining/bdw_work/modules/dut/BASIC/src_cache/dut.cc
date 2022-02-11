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

#include "dut.h"

void dut::thread1()
{
	output_t val1, val2, val3, output;
	{
		HLS_DEFINE_PROTOCOL( "reset" );
		din.reset();
		dout.reset();
		wait();
	}

	/* 	This lab adds synthesis directives for pipelining and latency.
		We will add a pipelining directive so that the II can be set
		directly from project.tcl.
	*/

	while( true )
	{
		// LAB EXERCISE: Add a HLS_PIPELINE_LOOP directive that is enabled when II is set.
		//		 Constrain the loop latency to exactly 6 cycles.

        HLS_CONSTRAIN_LATENCY(6, 6, "mainLatency");
#ifdef II
        HLS_PIPELINE_LOOP(HARD_STALL, II, "mainPipe");
#endif

		input_t input = din.get();

		val1 = ( input.a + input.b + input.c )
			* ( input.d + input.e + input.f )
			* ( input.g + input.h );

		val2 = ( input.a * input.b ) + ( input.c * input.d ) + ( input.e * val1 );

		val3 = ( input.a + input.b ) * val2 + ( input.c + input.d ) * val1;

		output = val3 * ( val2 + input.g * input.h ) / 3ULL;

		dout.put( output );
	}
}
