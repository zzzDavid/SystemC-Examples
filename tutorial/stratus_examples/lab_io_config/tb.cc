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
#include <esc.h>                // for the latency logging functions
#include <string>
#include <iostream>
enum { num_samples = 5000000 };
// use a queue to hold the time that each sample was sent
// for latency calculations
#include <queue>
static std::queue<sc_time> time_queue;
static std::queue<output_t> value_queue;

////
// The source thread reads data from a file and sends it to the design
////
void tb::source()
{
    // Reset the outputs and cycle the design's reset
    dout.reset();
    rst_out.write( 0 ); // assert reset (active low)
    wait( 2 );
    rst_out.write( 1 ); // deassert reset
    wait();

    // Write a set of values to the dut
    for( int i = 0; i < num_samples; i++ )
    {
        input_t value = rand();
        dout.put( value );    // send the stimulus value
        time_queue.push( sc_time_stamp() );
        value_queue.push( value );
    }

    // If this reaches the timeout it is an error
    wait( 1000 );
    cerr << name() << " Error! Source timed out!" << endl;
    esc_stop();
}

////
// The sink thread reads all the expected values from the design
////
void tb::sink()
{
    din.reset();
    wait();     // to synchronize with reset

    bool passed = true;
    unsigned long total_latency = 0;
    for( unsigned long i = 0; i < num_samples; i++ )
    {
        output_t in_val = din.get();
        output_t golden_val = value_queue.front() * 7;
        value_queue.pop();

        if( in_val != golden_val )
        {
            passed = false;
        }

        sc_time sent_time( time_queue.front() );
        time_queue.pop();
        unsigned long latency = clock_cycle( sc_time_stamp() - sent_time );
        total_latency += latency;
        //cout << "Latency for sample " << i << " is " <<  latency << endl;
    }

    // log performance metrics
    unsigned long average_latency = total_latency / num_samples;
    esc_log_latency( "dut", average_latency, "average_latency" );
    cout << "Testbench sink thread read " << num_samples << " values. Average latency " << average_latency << "." << endl;
    cout << "SIMULATION " << ( passed ? "PASSED" : "FAILED" ) << endl;

    // record pass or fail to show up in the simConfig table
    if( passed )
    {
        esc_log_pass();
    }
    else
    {
        esc_log_fail();
    }


    esc_stop();
}


////
// Convert a time in simulation time units to clock cycles
////
int tb::clock_cycle( sc_time time )
{
    sc_clock * clk_p = DCAST < sc_clock * >( clk.get_interface() );
    sc_time clock_period = clk_p->period(); // get period from the sc_clock object.
    return ( int )( time / clock_period );

}
