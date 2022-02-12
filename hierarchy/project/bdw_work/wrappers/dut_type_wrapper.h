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
	sc_out< bool > finish;
	sc_in< bool > find_max_x_out_busy;
	sc_out< bool > find_max_x_out_vld;
	sc_out< sc_int< 32 > > find_max_x_out_data;
	sc_out< bool > find_max_return_in_busy;
	sc_in< bool > find_max_return_in_vld;
	sc_in< sc_int< 32 > > find_max_return_in_data;

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    
    

	// create the netlist
    void InitInstances();
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    

	SC_HAS_PROCESS(dut_type_wrapper);

	dut_type_wrapper( sc_module_name name = sc_module_name( sc_gen_unique_name("dut")) )
		: sc_module(name)
		  ,clk("clk")
		  	,rst("rst")
		  	,finish("finish")
		  	,find_max_x_out_busy("find_max_x_out_busy")
		  	,find_max_x_out_vld("find_max_x_out_vld")
		  	,find_max_x_out_data("find_max_x_out_data")
		  	,find_max_return_in_busy("find_max_return_in_busy")
		  	,find_max_return_in_vld("find_max_return_in_vld")
		  	,find_max_return_in_data("find_max_return_in_data")
		  	

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
