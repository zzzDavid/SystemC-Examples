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

// use a queue to hold the time that each sample was sent
// for latency calculations
#include <queue>
static std::queue<sc_time> time_queue;

////
// The source thread reads data from a file and sends it to the design
////
void tb::source()
{
    // Reset the outputs and cycle the design's reset
    dout.reset();
    rst.write( 0 ); // assert reset (active low)
    wait( 2 );
    rst.write( 1 ); // deassert reset
    wait();

    // Write a set of values to the dut
    open_stimulus_file(); // Open the input data file
    bool eof = false;
    while( eof == false )
    {
        input_t value = read_stimulus_value( eof );
        if( !eof )
        {
            dout.put( value );    // send the stimulus value
            time_queue.push( sc_time_stamp() );
        }
    }

    // If this reaches the timeout it is an error
    wait( 1000 );
    close_stimulus_file();
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

    open_response_file(); // Open the output data file

    // read data values until we have read the number that are
    // in the golden file
    int n_samples = count_golden_file();

    unsigned long total_latency = 0;
    for( unsigned long i = 0; i < n_samples; i++ )
    {
        output_t inVal = din.get();
        write_response_value( inVal );  // write to response file

        sc_time sent_time( time_queue.front() );
        time_queue.pop();
        unsigned long latency = clock_cycle( sc_time_stamp() - sent_time );
        total_latency += latency;
        cout << "Latency for sample " << i << " is " <<  latency << endl;
    }

    // log performance metrics
    unsigned long average_latency = total_latency / n_samples;
    esc_log_latency( "dut", average_latency, "average_latency" );
    cout << "Testbench sink thread read " << n_samples << " values. Average latency " << average_latency << "." << endl;

    close_response_file();
    esc_stop();
}

////
// Open the stimulus file
////
void tb::open_stimulus_file( const char * _name )
{
    const char * name = ( _name == NULL ? "stimulus.dat" : _name );

    stim_file.open( name );
    if( stim_file.fail() )
    {
        cerr << "Couldn't open " << name << " for reading." << endl;
        exit( 0 );
    }
}

////
// Read the next value from the stimulus file
// Set eof = true if there are no more values in the file
////
input_t tb::read_stimulus_value( bool & eof )
{
    input_t value;
    stim_file >> std::ws;
    eof = stim_file.eof();
    if( !eof )
    {
        stim_file >> value;
        eof = ( stim_file.eof() );
    }
    return value;
}

////
// Close the stimulus file
////
void tb::close_stimulus_file()
{
    stim_file.close();
}

////
// Open the response file
////
void tb::open_response_file( const char * _name )
{
    const char * name = ( _name == NULL ? "response.dat" : _name );

    // put output file in appropriate directory in bdw_work
    std::string filename = getenv( "BDW_SIM_CONFIG_DIR" );
    filename += "/";
    filename += name;
    resp_file.open( filename.c_str() );
    if( resp_file.fail() )
    {
        cerr << "Couldn't open " << filename << " for writing." << endl;
        exit( 0 );
    }
}

////
// Write a value to the response file
////
void tb::write_response_value( output_t value )
{
    resp_file << value << endl;
}

////
// Close the response file
////
void tb::close_response_file()
{
    resp_file.close();
}

////
// Count the number of values in the golden file
////
int tb::count_golden_file( const char * _name )
{
    const char * name = ( _name == NULL ? "golden.dat" : _name );
    ifstream golden_file;         // File stream containing expected values
    unsigned long i;
    output_t value;

    golden_file.open( name );
    if( golden_file.fail() )
    {
        cerr << "Couldn't open golden file " << name << "." << endl;
        exit( 0 );
    }

    golden_file >> std::ws;       // flush any white space
    for( i = 0; !golden_file.eof(); i++ )
    {
        golden_file >> value;
        golden_file >> std::ws;       // flush any white space
    }

    golden_file.close();

    return i;
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
