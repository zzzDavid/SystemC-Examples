/****************************************************************************
*
*  Copyright (c) 2017, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/


#ifndef _ADD_ONE_SC_FOREIGN_INCLUDED_
#define _ADD_ONE_SC_FOREIGN_INCLUDED_

#include <systemc.h>

#if !defined(XM_SYSTEMC) && defined(NC_SYSTEMC)
#define xmsc_foreign_module ncsc_foreign_module
#endif


// Declaration of wrapper with RTL level ports

struct add_one : public xmsc_foreign_module
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


    const char* hdl_name() const { return "add_one"; }
    
	add_one( sc_module_name name )
		: xmsc_foreign_module(name)
		  ,clk("clk")
		  	,rst("rst")
		  	,add_one_x_busy("add_one_x_busy")
		  	,add_one_x_vld("add_one_x_vld")
		  	,add_one_x_data("add_one_x_data")
		  	,add_one_return_busy("add_one_return_busy")
		  	,add_one_return_vld("add_one_return_vld")
		  	,add_one_return_data("add_one_return_data")
		  	

		
    {
    }

};

#endif /* _ADD_ONE_SC_FOREIGN_INCLUDED_ */
