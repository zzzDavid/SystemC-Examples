/****************************************************************************
*
*  Copyright (c) 2017, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/


#ifndef _ADD_ONE_SC_WRAP_INCLUDED_
#define _ADD_ONE_SC_WRAP_INCLUDED_

#include <systemc.h>

struct add_one;

#include "cynw_p2p.h"
#include "hls_enums.h"


// Declaration of wrapper with BEH level ports

SC_MODULE(add_one_wrapper)
{
public:

	sc_in< bool > clk;
	sc_in< bool > rst;
	cynw::cynw_p2p_base_in <sc_dt::sc_int <(int)32 >, HLS::hls_enum <(int)1 > > add_one_x;
	cynw::cynw_p2p_base_out <sc_dt::sc_int <(int)32 >, HLS::hls_enum <(int)1 > > add_one_return;

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    
    
	// create the netlist
    void InitInstances( sc_int< 32 > _A[10]);
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    

	SC_HAS_PROCESS(add_one_wrapper);

        add_one_wrapper( sc_core::sc_module_name name, sc_int< 32 > _A[10] )
		: sc_module(name)
		  ,clk("clk")
		  	,rst("rst")
		  	,add_one_x("add_one_x")
		  	,add_one_return("add_one_return")
		  	

		  ,add_one0(0)

    {
        InitInstances( _A);
		InitThreads();
    }

    // destructor
    ~add_one_wrapper()
    {
        DeleteInstances();
    }

	add_one* add_one0;
};

#endif /* _ADD_ONE_SC_WRAP_INCLUDED_ */
