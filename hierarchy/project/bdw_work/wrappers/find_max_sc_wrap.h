/****************************************************************************
*
*  Copyright (c) 2017, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/


#ifndef _FIND_MAX_SC_WRAP_INCLUDED_
#define _FIND_MAX_SC_WRAP_INCLUDED_

#include <systemc.h>

struct find_max;

#include "cynw_p2p.h"
#include "hls_enums.h"


// Declaration of wrapper with BEH level ports

SC_MODULE(find_max_wrapper)
{
public:

	sc_in< bool > clk;
	sc_in< bool > rst;
	cynw::cynw_p2p_base_in <sc_dt::sc_int <(int)32 >, HLS::hls_enum <(int)1 > > find_max_x;
	cynw::cynw_p2p_base_out <sc_dt::sc_int <(int)32 >, HLS::hls_enum <(int)1 > > find_max_return;
	cynw::cynw_p2p_base_out <sc_dt::sc_int <(int)32 >, HLS::hls_enum <(int)1 > > add_one_x_out;
	cynw::cynw_p2p_base_in <sc_dt::sc_int <(int)32 >, HLS::hls_enum <(int)1 > > add_one_return_in;

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    
    
	// create the netlist
    void InitInstances( sc_int< 32 > _A[10], sc_int< 32 > _B[10]);
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    

	SC_HAS_PROCESS(find_max_wrapper);

        find_max_wrapper( sc_core::sc_module_name name, sc_int< 32 > _A[10], sc_int< 32 > _B[10] )
		: sc_module(name)
		  ,clk("clk")
		  	,rst("rst")
		  	,find_max_x("find_max_x")
		  	,find_max_return("find_max_return")
		  	,add_one_x_out("add_one_x_out")
		  	,add_one_return_in("add_one_return_in")
		  	

		  ,find_max0(0)

    {
        InitInstances( _A, _B);
		InitThreads();
    }

    // destructor
    ~find_max_wrapper()
    {
        DeleteInstances();
    }

	find_max* find_max0;
};

#endif /* _FIND_MAX_SC_WRAP_INCLUDED_ */
