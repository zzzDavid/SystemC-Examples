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

/* This file defines the module "dut", which is synthesizable. It is
   instantiated in the top-level module System (see system.h). */

#include <systemc.h>  /* SystemC definitions. */
#include <esc.h>      /* Cadence ESC functions and utilities. */
#include <stratus_hls.h>  /* Cadence Stratus definitions. */
#include <cynw_p2p.h> /* The cynw_p2p communication channel. */
#include "stream_16X8.h"   /* Generated stream interface classes */
#include "defines.h"  /* definitions common to the TB and DUT. */
#include "directives.h"  /* Synthesis directives. */


SC_MODULE( dut )
{
    sc_in_clk clk;
    sc_in< bool > rst;

    cynw_p2p< input_data, ioConfig >::in  in;
    cynw_p2p< output_data, ioConfig >::out out;

    stream_16X8::in<ioConfig> streamin;
    stream_16X8::out<ioConfig> streamout;

    SC_CTOR( dut )
        : clk( "clk" )
        , rst( "rst" )
        , in( "in" )
        , out( "out" )
        , streamin( "streamin" )
        , streamout( "streamout" )
    {
        SC_CTHREAD( thread1, clk.pos() );
        reset_signal_is( rst, false );

        in.clk_rst( clk, rst );
        out.clk_rst( clk, rst );

        streamin.clk_rst( clk, rst );
        streamout.clk_rst( clk, rst );

    }

    sc_uint<8> x[8];
    sc_uint<8> y[4];
    sc_uint<8> data[16];

    void thread1();
};

#endif /* DUT_H */
