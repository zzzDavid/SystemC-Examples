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
* This file contains the add_one_type_wrapper module
* for use in the verilog verification wrapper add_one_vlwrapper.v
* It creats an instance of the add_one module and has threads
* for converting the BEH ports to RTL level ports on the wrapper.
*
****************************************************************************/


#ifndef _ADD_ONE_TYPE_WRAP_INCLUDED_
#define _ADD_ONE_TYPE_WRAP_INCLUDED_


#include <systemc.h>
#include "add_one.h"


// Declaration of wrapper with RTL level ports

SC_MODULE(add_one_type_wrapper)
{
public:

	sc_in< bool > clk;
	sc_in< bool > rst;
	sc_out< bool > add_one_x_busy;
	sc_in< bool > add_one_x_vld;
	sc_in< sc_int< 32 > > add_one_x_data;
	sc_in< bool > add_one_return_busy;
	sc_out< bool > add_one_return_vld;
	sc_out< sc_int< 32 > > add_one_return_data;

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    
    

	// create the netlist
    void InitInstances();
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    

	SC_HAS_PROCESS(add_one_type_wrapper);

	add_one_type_wrapper( sc_module_name name = sc_module_name( sc_gen_unique_name("add_one")) )
		: sc_module(name)
		  ,clk("clk")
		  	,rst("rst")
		  	,add_one_x_busy("add_one_x_busy")
		  	,add_one_x_vld("add_one_x_vld")
		  	,add_one_x_data("add_one_x_data")
		  	,add_one_return_busy("add_one_return_busy")
		  	,add_one_return_vld("add_one_return_vld")
		  	,add_one_return_data("add_one_return_data")
		  	

		  ,add_one0(0)
		

    {
        InitInstances();
        InitThreads();
		end_module();
    }


    // destructor
    ~add_one_type_wrapper()
    {
        DeleteInstances();
    }


protected:
	add_one* add_one0;
};

#endif /*  */
