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
#include "directives.h"

// The thread function for the design
void dut::thread1()
{
    {
        HLS_DEFINE_PROTOCOL( "reset" );
        din.reset();
        dout.reset();
        wait();
    }

    input_t tmp = din.get();                // get the first value
    for( int i = 0; i < 8; i++ )
    {
        // LAB: Macro is used to identify this location as a potential
        // place for directives to go.
        FILL_LOOP;
        my_array[i] = tmp;                  // fill the array
    }
    dout.put( tmp );                        // output the first value

    while( true )
    {
        output_t out_val;
        tmp = din.get();                    // get the next value
        for( int i = 0; i < 7; i++ )
        {
            // LAB: Macro is used to identify this location as a potential
            // place for directives to go.
            SHIFT_LOOP;
            my_array[i] = my_array[i+1];    // shift the stored values
        }
        my_array[7] = tmp;

        sc_uint<11> sum = 0;
        for( int i = 0; i < 8; i++ )
        {
            // LAB: Macro is used to identify this location as a potential
            // place for directives to go.
            SUM_LOOP;
            sum += my_array[i];             // sum the stored values
        }

        out_val = sum / 8;         // compute the average
        dout.put( out_val );                // output the result
    }
}
