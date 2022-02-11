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

/* This file defines the module "System", which is the top-level
   module in the simulation. See the file main.cc, which shows how a
   SystemC simulation is created and run. */

#include <systemc.h>  /* SystemC definitions. */
#include <esc.h>      /* Cadence ESC functions and utilities. */
#include <stratus_hls.h>  /* Cadence Stratus definitions. */
#include <cynw_p2p.h> /* The cynw_p2p communication channel. */

#include "defines.h"  /* common definitions. */

/* Include the local header files that define the modules to be
   instantiated. */

#include "tb.h"       /* The testbench module. */
#include "dut_wrap.h" /* The DUT module. Need dut_wrap.h, not dut.h. */
#include "stream_16X8.h"   /* Generated stream interface classes */


SC_MODULE( System )
{
    dut_wrapper m_dut;
    tb m_tb;

    sc_clock clk;
    sc_signal< bool > rst;

    cynw_p2p< input_data, ioConfig > m_tb_dut;
    cynw_p2p< output_data, ioConfig > m_dut_tb;

    stream_16X8::chan<ioConfig> m_stream_tb_dut;
    stream_16X8::chan<ioConfig> m_stream_dut_tb;

    SC_CTOR( System )
        : clk( "clk", CLOCK_PERIOD, SC_NS )
        , rst( "rst" )
        , m_tb( "tb" )
        , m_tb_dut( "tb_dut" )
        , m_dut( "dut" )
        , m_dut_tb( "dut_tb" )
        , m_stream_dut_tb( "stream_dut_tb" )
        , m_stream_tb_dut( "stream_tb_dut" )
    {
        /* Connect the clk/rst and input/output ports of the testbench
             and DUT to the local signals. */

        m_tb.clk( clk );
        m_tb.rst( rst );
        m_dut.clk( clk );
        m_dut.rst( rst );

        m_stream_tb_dut.clk_rst( clk, rst );
        m_stream_dut_tb.clk_rst( clk, rst );

        m_tb.out( m_tb_dut );

        m_dut.in( m_tb_dut );
        m_dut.out( m_dut_tb );

        m_tb.in( m_dut_tb );

        m_dut.streamin( m_stream_tb_dut );
        m_dut.streamout( m_stream_dut_tb );

        m_tb.streamin( m_stream_dut_tb );
        m_tb.streamout( m_stream_tb_dut );
    }

};

#endif /* SYSTEM_H */
