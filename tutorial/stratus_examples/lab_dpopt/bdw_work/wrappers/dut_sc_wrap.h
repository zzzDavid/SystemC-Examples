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

#include "input_t.h"
#include "cynw_p2p.h"
#include "cyn_enums.h"


// Declaration of wrapper with BEH level ports

SC_MODULE(dut_wrapper)
{
public:

	sc_in< bool > clk;
	sc_in< bool > rst;
	cynw::cynw_p2p_base_in <input_t, CYN::cyn_enum <(int)1 > > din;
	cynw::cynw_p2p_base_out <sc_dt::sc_uint <(int)32 >, CYN::cyn_enum <(int)1 > > dout;

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    sc_signal< sc_uint< 8 > > din_data_a;
    sc_signal< sc_uint< 8 > > din_data_b;
    sc_signal< sc_uint< 8 > > din_data_c;
    sc_signal< sc_uint< 8 > > din_data_d;
    sc_signal< sc_uint< 8 > > din_data_e;
    sc_signal< sc_uint< 8 > > din_data_f;
    sc_signal< sc_uint< 8 > > din_data_g;
    sc_signal< sc_uint< 8 > > din_data_h;

    
	// create the netlist
    void InitInstances( );
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    void thread_din_data_a();
    void thread_din_data_b();
    void thread_din_data_c();
    void thread_din_data_d();
    void thread_din_data_e();
    void thread_din_data_f();
    void thread_din_data_g();
    void thread_din_data_h();


	SC_HAS_PROCESS(dut_wrapper);

    	dut_wrapper( sc_module_name name = sc_module_name( sc_gen_unique_name("dut")) )
		: sc_module(name)
		  ,clk("clk")
		  	,rst("rst")
		  	,din("din")
		  	,dout("dout")
		  	

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
