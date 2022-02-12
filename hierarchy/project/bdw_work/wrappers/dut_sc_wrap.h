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
#include "hls_enums.h"


// Declaration of wrapper with BEH level ports

SC_MODULE(dut_wrapper)
{
public:

	sc_in< bool > clk;
	sc_in< bool > rst;
	sc_out< bool > finish;
	cynw::cynw_p2p_base_out <sc_dt::sc_int <(int)32 >, HLS::hls_enum <(int)1 > > find_max_x_out;
	cynw::cynw_p2p_base_in <sc_dt::sc_int <(int)32 >, HLS::hls_enum <(int)1 > > find_max_return_in;

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    
    
	// create the netlist
    void InitInstances( sc_int< 32 > _A[10], sc_int< 32 > _B[10], sc_int< 32 > _D[10]);
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    

	SC_HAS_PROCESS(dut_wrapper);

        dut_wrapper( sc_core::sc_module_name name, sc_int< 32 > _A[10], sc_int< 32 > _B[10], sc_int< 32 > _D[10] )
		: sc_module(name)
		  ,clk("clk")
		  	,rst("rst")
		  	,finish("finish")
		  	,find_max_x_out("find_max_x_out")
		  	,find_max_return_in("find_max_return_in")
		  	

		  ,dut0(0)

    {
        InitInstances( _A, _B, _D);
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
