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

#include "dut_type_wrapper.h"


SC_MODULE_EXPORT(dut_type_wrapper)

// The following threads are used to connect RTL ports to the actual
// structured ports

#if defined ( ioConfig_TLM )



#else


#endif


void dut_type_wrapper::InitInstances()
{
    dut0 = new dut( "dut" );

    
#if defined ( ioConfig_TLM )
    
    		esc_report_error( esc_fatal, "Cannot instantiate non-synthesizable ioConfig 'TLM' for module 'dut' within an parent module with a pin-level interface.");
    
    
#else
    
    		esc_report_error( esc_fatal, "Cannot instantiate non-synthesizable ioConfig 'PIN' for module 'dut' within an parent module with a pin-level interface.");
    
#endif

}

void dut_type_wrapper::InitThreads()
{
    
#if defined ( ioConfig_TLM )
    
    
    
#else
    
    
#endif

}

void dut_type_wrapper::DeleteInstances()
{
        delete dut0;
        dut0 = 0;
}

