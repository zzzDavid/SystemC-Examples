/****************************************************************************
*
*  Copyright (c) 2017, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/


#ifndef _DUT_SC_WRAP_INCLUDED_
#define _DUT_SC_WRAP_INCLUDED_

#include <systemc.h>

struct dut;

#include "cynw_p2p.h"
#include "cyn_enums.h"
#include "RAM_64x8.h"


// Declaration of wrapper with BEH level ports

SC_MODULE(dut_wrapper)
{
public:

	sc_in< bool > clk;
	sc_in< bool > rst;
	cynw::cynw_p2p_base_in <sc_dt::sc_uint <(int)8 >, CYN::cyn_enum <(int)1 > > din;
	cynw::cynw_p2p_base_out <sc_dt::sc_uint <(int)11 >, CYN::cyn_enum <(int)1 > > dout;
	RAM_64x8::port <CYN::cyn_enum <(int)1 >, sc_dt::sc_uint <(int)8 >, (HLS::HLS_INDEX_MAPPING_OPTIONS)256 > mem;

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    
    
	// create the netlist
    void InitInstances( );
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    

	SC_HAS_PROCESS(dut_wrapper);

    	dut_wrapper( sc_module_name name = sc_module_name( sc_gen_unique_name("dut")) )
		: sc_module(name)
		  ,clk("clk")
		  	,rst("rst")
		  	,din("din")
		  	,dout("dout")
		  	,mem("mem")
		  	

		  ,dut0(0)

    {
        InitInstances( );
		InitThreads();
    }

    // destructor
    ~dut_wrapper()
    {
        DeleteInstances();
    }

	dut* dut0;
};

#endif /* _DUT_SC_WRAP_INCLUDED_ */
