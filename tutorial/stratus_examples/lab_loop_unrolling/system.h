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

/* Include some required files. */

#include <systemc.h>  /* SystemC definitions. */
#include <esc.h>      /* Cadence ESC functions and utilities. */
#include <stratus_hls.h>  /* Cadence Stratus definitions. */
#include <cynw_p2p.h> /* The cynw_p2p communication channel. */

/* Include the local header files that define the modules to be instantiated. */

#include "tb.h"       /* The testbench module. */
#include "dut_wrap.h" /* The DUT module. Need dut_wrap.h, not dut.h. */


SC_MODULE( System )
{
public:

    /* Instantiated sub-modules. We instantiate the dut_wrapper module,
       rather than the dut module directly. This is because the dut
       module can exist in multiple versions (such as behavioral and
       synthesized RTL), and the wrapper module automatically selects
       between the versions based on the simulation configuration. */

    dut_wrapper DUT;
    tb TB;

    sc_clock clk_sig;
    sc_signal< bool > rst_sig;

    cynw_p2p< input_t > chan1; /* TB to DUT, using struct input_t. */
    cynw_p2p< output_t > chan2; /* DUT to TB, using type output_t. */


    SC_CTOR( System )
        : clk_sig( "clk_sig", CLOCK_PERIOD, SC_NS )
        , rst_sig( "rst_sig" )
        , TB( "TB" )
        , chan1( "chan1" )
        , DUT( "DUT" )
        , chan2( "chan2" )
    {
        TB.clk( clk_sig );
        TB.rst_out( rst_sig );

        DUT.clk( clk_sig );
        DUT.rst( rst_sig );

        TB.dout( chan1 );

        DUT.din( chan1 );
        DUT.dout( chan2 );

        TB.din( chan2 );
    }

};

#endif /* SYSTEM_H */
