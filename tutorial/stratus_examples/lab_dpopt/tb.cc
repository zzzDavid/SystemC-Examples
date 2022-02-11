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

#include "tb.h"
#include <esc.h>		// for the latency logging functions
#include <string>
#include <iostream>

// The source thread reads data from a file and sends it to the DUT
void tb::source()
{
	dout.reset();		// reset the outputs and cycle the design's reset
	rst.write( 0 );		// assert reset (active low)
	wait( 2 );		// wait 2 cycles
	rst.write( 1 );		// deassert reset
	wait();

	// Open the stimulus file
	char stim_file[256] = "stimulus.dat";
	infp = fopen( stim_file, "r" );
	if( infp == NULL )
	{
		cout << "Couldn't open stimulus.dat for reading." << endl;
		exit(0);
	}

	// Read stimulus values from file and send to DUT
	for( int i = 0; i < NUM; i++ )
	{
		input_t value;
    		int a, b, c, d, e, f, g, h;
		fscanf( infp, " %d %d %d %d %d %d %d %d\n", &a, &b, &c, &d, &e, &f, &g, &h );
		value.a = a; value.b = b; value.c = c; value.d = d; value.e = e; value.f = f; value.g = g; value.h = h;
		dout.put( value );			// send the stimulus value
		start_time[i] = sc_time_stamp();	// mark the time value was sent
	}

	// Guard condition: after 100000 cycles the sink() thread should have ended the simulation.
	// If we're still here, timeout and print error message.
	wait( 100000 );
    	fclose( infp );
	cout << "Error! TB source thread timed out!" << endl;
	esc_stop();
}

// The sink thread reads all the expected values from the design
void tb::sink()
{
	din.reset();
	wait();     // to synchronize with reset

	// Extract clock period from clk port
	sc_clock * clk_p = DCAST < sc_clock * >( clk.get_interface() );
	sc_time clock_period = clk_p->period();

	// Open the simulation results file
	char output_file[256];
	sprintf( output_file, "%s/response.dat", getenv("BDW_SIM_CONFIG_DIR") );
	outfp = fopen(output_file, "wb");
	if (outfp == NULL)
	{
		cout << "Couldn't open output.dat for writing." << endl;
		exit(0);
	}

	// Read outputs from DUT
	unsigned long total_latency = 0;
	for( int i = 0; i < NUM; i++ )
	{
		output_t inVal = din.get();
		fprintf( outfp, "%ld\n", (unsigned long)inVal );	// write value to response file

		// Calculate latency for this particular output
		unsigned long latency = (sc_time_stamp() - start_time[i]) / clock_period;
		cout << "Latency for sample " << i << " is " <<  latency << endl;

		// Keep running total of all latency cycles for later
		total_latency += latency;
	}

	// Calculate, log and print average latency
	unsigned long average_latency = total_latency / NUM;
	esc_log_latency( "dut", average_latency, "average_latency" );
	cout << "Average latency " << average_latency << "." << endl;

	// Close the results file and end the simulation
	fclose( outfp );
	esc_stop();
}
