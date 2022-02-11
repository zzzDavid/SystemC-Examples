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

void tb::source()
{
    /* The source thread, generating data sent to the DUT. */

    int j, i;
    input_data d;
    char str[STREAM_SIZE]; // 16

    /* Reset P2P and I/F ports. */
    out.reset();
    streamout.reset();

    /* Start with a reset, active low. */
    rst.write( false );
    wait();		/* wait 1 clock cycle. */
    rst.write( true );	/* Negate reset. */
    wait();
    printf( "Source: out of reset\n" );

    sprintf( str, "Hello %d!!", 1 );
    printf( "TB source: %s\n", str );

    /* Send a "1" to the DUT */
    d = (input_data) 1;
    out.put( d ); 

    streamout.start_tx();
    j = 0;
    do
    {
        for( i = 0; i < 4; i++ )
        {
            y[i] = str[i+( j*4 )];
            //cout << "Source: Sending y[" << i << "]= " << (char)y[i] << endl;
        }
        streamout.put( y );
        j++;
    }
    while( !streamout.done() );
    streamout.end_tx();

    start_time = sc_time_stamp();

    sprintf( str, "World %d!!", 2 );
    printf( "TB source: %s\n", str );

    /* Send a "2" to the DUT */
    d = (input_data) 2;
    out.put( d );

    streamout.start_tx();
    j = 0;
    do
    {
        for( i = 0; i < 4; i++ )
        {
            y[i] = str[i+( j*4 )];
            //cout << "Source: Sending " << (char)y[i] << endl;
        }
        streamout.put( y );
        j++;
    }
    while( !streamout.done() );
    streamout.end_tx();

    start_time = sc_time_stamp();

    /* Guard against a misbahaving DUT. */
    wait( 5000 );
    printf( "Warning: Stopping simulation from TB source, possible runaway simulation. Check results.\n" );
    esc_stop();
}

void tb::sink()
{
    /* The sink thread receives output data from the DUT. */

    /* First, we need to determine the clock period so we can measure
       latency in terms of clock cycles. This is accomplished through
       some SystemC magic code using the "clk" port. */
    sc_clock * clk_p = DCAST<sc_clock *>( clk.get_interface() );
    clock_period = clk_p->period(); /* get period from the sc_clock object. */

    /* Initialization. Reset the input port. */
    in.reset();
    streamin.reset();

    /* Wait to receive output from the DUT. */
    output_data q;
    int i, j;
    char str[STREAM_SIZE];

    streamin.start_tx();
    j = 0;
    do
    {
        streamin.get( x );
        for( i = 0; i < 8; i++ )
        {
            str[j*8+i] = x[i];
            //cout << "Sink: Receiving x[" << i << "]= " << (char)str[j*8+i] << endl;
        }
        j++;
    }
    while( !streamin.done() );
    streamin.end_tx();

    q = in.get();

    printf( "%i: %s\n", (int)q, str );
    if( ofile )
    {
        fprintf( ofile, "%i: %s\n", (int)q, str );
    }

    // Measure the latency to receive one output.
    end_time = sc_time_stamp();
    double latency = ( end_time - start_time ) / clock_period;
    // Record the latency in the simulation report.
    esc_log_latency( "dut", ( unsigned ) latency, "dut_latency" );
    printf( "Sink: Latency for iteration %i is %g cycles.\n", 1, latency );

    streamin.start_tx();
    j = 0;
    do
    {
        streamin.get( x );
        for( i = 0; i < 8; i++ )
        {
            str[j*8+i] = x[i];
            //cout << "Sink: Receiving x[" << i << "]= " << (char)str[j*8+i] << endl;
        }
        j++;
    }
    while( !streamin.done() );
    streamin.end_tx();

    q = in.get();

    printf( "%i: %s\n", ( int ) q, str );
    if( ofile )
    {
        fprintf( ofile, "%i: %s\n", ( int ) q, str );
    }

    // Measure the latency to receive one output.
    end_time = sc_time_stamp();
    latency = ( end_time - start_time ) / clock_period;
    // Record the latency in the simulation report.
    esc_log_latency( "dut", ( unsigned ) latency, "dut_latency" );
    printf( "Sink: Latency for iteration %i is %g cycles.\n", 2, latency );

    // Received all outputs so stop the simulation.
    esc_stop();
}
