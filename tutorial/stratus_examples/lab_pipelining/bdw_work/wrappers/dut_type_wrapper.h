/****************************************************************************
*
*  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/
/****************************************************************************
*
* This file contains the dut_type_wrapper module
* for use in the verilog verification wrapper dut_vlwrapper.v
* It creats an instance of the dut module and has threads
* for converting the BEH ports to RTL level ports on the wrapper.
*
****************************************************************************/


#ifndef _DUT_TYPE_WRAP_INCLUDED_
#define _DUT_TYPE_WRAP_INCLUDED_


#include <systemc.h>
#include "dut.h"


// Declaration of wrapper with RTL level ports

SC_MODULE(dut_type_wrapper)
{
public:

	sc_in< bool > clk;
	sc_in< bool > rst;
	sc_out< bool > din_busy;
	sc_in< bool > din_vld;
	sc_in< sc_uint< 8 > > din_data_a;
	sc_in< sc_uint< 8 > > din_data_b;
	sc_in< sc_uint< 8 > > din_data_c;
	sc_in< sc_uint< 8 > > din_data_d;
	sc_in< sc_uint< 8 > > din_data_e;
	sc_in< sc_uint< 8 > > din_data_f;
	sc_in< sc_uint< 8 > > din_data_g;
	sc_in< sc_uint< 8 > > din_data_h;
	sc_in< bool > dout_busy;
	sc_out< bool > dout_vld;
	sc_out< sc_uint< 32 > > dout_data;

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    sc_signal< input_t > din_data;

    

	// create the netlist
    void InitInstances();
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    void thread_din_data();


	SC_HAS_PROCESS(dut_type_wrapper);

	dut_type_wrapper( sc_module_name name = sc_module_name( sc_gen_unique_name("dut")) )
		: sc_module(name)
		  ,clk("clk")
		  	,rst("rst")
		  	,din_busy("din_busy")
		  	,din_vld("din_vld")
		  	,din_data_a("din_data_a"),
		  din_data_b("din_data_b"),
		  din_data_c("din_data_c"),
		  din_data_d("din_data_d"),
		  din_data_e("din_data_e"),
		  din_data_f("din_data_f"),
		  din_data_g("din_data_g"),
		  din_data_h("din_data_h")
		  	,dout_busy("dout_busy")
		  	,dout_vld("dout_vld")
		  	,dout_data("dout_data")
		  	

		  ,dut0(0)
		

    {
        InitInstances();
        InitThreads();
		end_module();
    }


    // destructor
    ~dut_type_wrapper()
    {
        DeleteInstances();
    }


protected:
	dut* dut0;
};

#endif /*  */
