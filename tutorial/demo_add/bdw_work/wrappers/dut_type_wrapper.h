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
	sc_out< bool > din_1_busy;
	sc_in< bool > din_1_vld;
	sc_in< sc_uint< 8 > > din_1_data;
	sc_out< bool > din_2_busy;
	sc_in< bool > din_2_vld;
	sc_in< sc_uint< 8 > > din_2_data;
	sc_in< bool > dout_busy;
	sc_out< bool > dout_vld;
	sc_out< sc_uint< 9 > > dout_data;

    
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
		  	,din_1_busy("din_1_busy")
		  	,din_1_vld("din_1_vld")
		  	,din_1_data("din_1_data")
		  	,din_2_busy("din_2_busy")
		  	,din_2_vld("din_2_vld")
		  	,din_2_data("din_2_data")
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
