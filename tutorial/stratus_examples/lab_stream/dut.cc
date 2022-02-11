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
    /* The first part of the code is the reset logic. */
    {
        HLS_DEFINE_PROTOCOL( "reset" );
        in.reset();
        out.reset();
        streamin.reset();
        streamout.reset();
        wait();
    }

    while( true )
    {
        input_data d;
        output_data q;
        int j;
        int i;

        d = in.get();

        j = 0;
        streamin.start_tx();
        do
        {
            streamin.get( x );
            for( i = 0; i < 8; i++ )
            {
                data[j*8+i] = x[i];
                //cout << "DUT: received x[" << i << "]= " << (char)x[i] << endl;
            }
            j++;
        }
        while( !streamin.x_done() );
        streamin.end_tx();

        j = 0;
        streamout.start_tx();
        do
        {
            for( i = 0; i < 4; i++ )
            {
                y[i] = data[i+j*4];
                //cout << "DUT: sending y[" << i << "]= " << (char)y[i] << endl;
            }
            streamout.put( y );
            j++;
        }
        while( !streamout.x_done() );
        streamout.end_tx();

        q = d;
        out.put( q );
    }
}
