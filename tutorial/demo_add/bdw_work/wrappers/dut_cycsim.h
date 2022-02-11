/****************************************************************************
 *
 *  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
 *
 *  This file contains confidential information that may not be
 *  distributed under any circumstances without the written permision
 *  of Cadence Design Systems.
 *
 ***************************************************************************/

#ifndef _DUT_CYCSIM_INCLUDED_
#define _DUT_CYCSIM_INCLUDED_

#include "systemc.h"
#include "cynthhl.h"

SC_MODULE(dut_cycsim)
{

	// Port declarations.
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


	dut_cycsim( sc_module_name in_name=sc_module_name(sc_gen_unique_name(" dut") ) )
		: sc_module(in_name)
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
		  	

    {
    };
};

#endif
