/****************************************************************************
*
*  Copyright (c) 2017, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/


#ifndef _FIND_MAX_SC_FOREIGN_INCLUDED_
#define _FIND_MAX_SC_FOREIGN_INCLUDED_

#include <systemc.h>

#if !defined(XM_SYSTEMC) && defined(NC_SYSTEMC)
#define xmsc_foreign_module ncsc_foreign_module
#endif


// Declaration of wrapper with RTL level ports

struct find_max : public xmsc_foreign_module
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


    const char* hdl_name() const { return "find_max"; }
    
	find_max( sc_module_name name )
		: xmsc_foreign_module(name)
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
		  	

		
    {
    }

};

#endif /* _FIND_MAX_SC_FOREIGN_INCLUDED_ */
