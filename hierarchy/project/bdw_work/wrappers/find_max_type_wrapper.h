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
* This file contains the find_max_type_wrapper module
* for use in the verilog verification wrapper find_max_vlwrapper.v
* It creats an instance of the find_max module and has threads
* for converting the BEH ports to RTL level ports on the wrapper.
*
****************************************************************************/


#ifndef _FIND_MAX_TYPE_WRAP_INCLUDED_
#define _FIND_MAX_TYPE_WRAP_INCLUDED_


#include <systemc.h>
#include "find_max.h"


// Declaration of wrapper with RTL level ports

SC_MODULE(find_max_type_wrapper)
{
public:

	sc_in< bool > clk;
	sc_in< bool > rst;
	sc_out< bool > find_max_x_busy;
	sc_in< bool > find_max_x_vld;
	sc_in< sc_int< 32 > > find_max_x_data;
	sc_in< bool > find_max_return_busy;
	sc_out< bool > find_max_return_vld;
	sc_out< sc_int< 32 > > find_max_return_data;
	sc_in< bool > add_one_x_out_busy;
	sc_out< bool > add_one_x_out_vld;
	sc_out< sc_int< 32 > > add_one_x_out_data;
	sc_out< bool > add_one_return_in_busy;
	sc_in< bool > add_one_return_in_vld;
	sc_in< sc_int< 32 > > add_one_return_in_data;

    
    // These signals are used to connect structured ports or ports that need
    // type conversion to the RTL ports.
    
    

	// create the netlist
    void InitInstances();
    void InitThreads();

    // delete the netlist
    void DeleteInstances();

    // The following threads are used to connect structured ports to the actual
    // RTL ports.
    

	SC_HAS_PROCESS(find_max_type_wrapper);

	find_max_type_wrapper( sc_module_name name = sc_module_name( sc_gen_unique_name("find_max")) )
		: sc_module(name)
		  ,clk("clk")
		  	,rst("rst")
		  	,find_max_x_busy("find_max_x_busy")
		  	,find_max_x_vld("find_max_x_vld")
		  	,find_max_x_data("find_max_x_data")
		  	,find_max_return_busy("find_max_return_busy")
		  	,find_max_return_vld("find_max_return_vld")
		  	,find_max_return_data("find_max_return_data")
		  	,add_one_x_out_busy("add_one_x_out_busy")
		  	,add_one_x_out_vld("add_one_x_out_vld")
		  	,add_one_x_out_data("add_one_x_out_data")
		  	,add_one_return_in_busy("add_one_return_in_busy")
		  	,add_one_return_in_vld("add_one_return_in_vld")
		  	,add_one_return_in_data("add_one_return_in_data")
		  	

		  ,find_max0(0)
		

    {
        InitInstances();
        InitThreads();
		end_module();
    }


    // destructor
    ~find_max_type_wrapper()
    {
        DeleteInstances();
    }


protected:
	find_max* find_max0;
};

#endif /*  */
