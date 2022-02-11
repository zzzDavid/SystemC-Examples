/****************************************************************************
*
*  Copyright (c) 2017, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/


#ifndef _DUT_SC_FOREIGN_INCLUDED_
#define _DUT_SC_FOREIGN_INCLUDED_

#include <systemc.h>


// Declaration of wrapper with RTL level ports

struct dut : public ncsc_foreign_module
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


    const char* hdl_name() const { return "dut"; }
    
	dut( sc_module_name name )
		: ncsc_foreign_module(name)
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
    }

};

#endif /* _DUT_SC_FOREIGN_INCLUDED_ */
