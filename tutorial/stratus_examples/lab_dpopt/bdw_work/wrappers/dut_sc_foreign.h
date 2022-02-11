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


    const char* hdl_name() const { return "dut"; }
    
	dut( sc_module_name name )
		: ncsc_foreign_module(name)
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
		  	

		
    {
    }

};

#endif /* _DUT_SC_FOREIGN_INCLUDED_ */
