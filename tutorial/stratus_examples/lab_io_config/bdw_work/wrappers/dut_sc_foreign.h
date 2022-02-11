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

	
#if defined ( ioConfig_TLM )
	
	sc_in< bool > clk;
	sc_in< bool > rst;
	
	
#else
	
	sc_in< bool > clk;
	sc_in< bool > rst;
	
#endif


    const char* hdl_name() const { return "dut"; }
    
	dut( sc_module_name name )
		: ncsc_foreign_module(name)
		  
#if defined ( ioConfig_TLM )
		  
		  ,clk("clk")
		  	,rst("rst")
		  	
		  
#else
		  
		  ,clk("clk")
		  	,rst("rst")
		  	
#endif
		  

		
    {
    }

};

#endif /* _DUT_SC_FOREIGN_INCLUDED_ */
