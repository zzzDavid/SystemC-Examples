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
	sc_in< sc_uint< 8 > > din_data;
	sc_in< bool > dout_busy;
	sc_out< bool > dout_vld;
	sc_out< sc_uint< 11 > > dout_data;
	sc_out< bool > mem_WE0;
	sc_out< sc_uint< 8 > > mem_DIN0;
	sc_in< sc_uint< 8 > > mem_DOUT0;
	sc_out< sc_uint< 6 > > mem_A0;
	sc_out< bool > mem_REQ0;

    
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
		  	,din_busy("din_busy")
		  	,din_vld("din_vld")
		  	,din_data("din_data")
		  	,dout_busy("dout_busy")
		  	,dout_vld("dout_vld")
		  	,dout_data("dout_data")
		  	,mem_WE0("mem_WE0")
		  	,mem_DIN0("mem_DIN0")
		  	,mem_DOUT0("mem_DOUT0")
		  	,mem_A0("mem_A0")
		  	,mem_REQ0("mem_REQ0")
		  	

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
