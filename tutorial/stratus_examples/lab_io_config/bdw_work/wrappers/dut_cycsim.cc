/****************************************************************************
*
*  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/

#ifdef NCSC
#include <string>
typedef std::string sc_string;
#define SYSTEMC_VERSION 20070314
#endif

#include "dut_cycsim.h"
#include "esc_catrace.h"
#include "verilated.h"
#include "Vdut_rtl.h"


class Vdut_rtl;

class dut_cycsimV : public dut_cycsim
{
    // Port declarations inherited from parent class

    // These signals are used to connect ports that need type conversion to the RTL ports
    
#if defined ( ioConfig_TLM )
    
    
    
#else
    
    
#endif


    // The following threads are used to do the type conversion.
    
#if defined ( ioConfig_TLM )
    
    
    
#else
    
    
#endif


    SC_HAS_PROCESS(dut_cycsimV);

public:

    dut_cycsimV( sc_module_name in_name=sc_module_name(sc_gen_unique_name(" dut") ) )
        : dut_cycsim(in_name)
    {
        // instantiate the verilated module
        dut_cyc0 = new Vdut_rtl( "Vdut" );
        // generate port connections
        
#if defined ( ioConfig_TLM )
        
        		esc_report_error( esc_fatal, "Cannot instantiate non-synthesizable ioConfig 'TLM' for module 'dut' within an parent module with a pin-level interface.");
        
        
#else
        
        		esc_report_error( esc_fatal, "Cannot instantiate non-synthesizable ioConfig 'PIN' for module 'dut' within an parent module with a pin-level interface.");
        
#endif


        // setup the type conversion threads
        
#if defined ( ioConfig_TLM )
        
        
        
#else
        
        
#endif


        TraceFileType* tfp = esc_get_ca_trace_file();
        if ( tfp )
        {
            dut_cyc0->trace(tfp,99);
        }
    };

    ~dut_cycsimV()
    {
        delete dut_cyc0;
    }

    void end_of_elaboration()
    {
        esc_open_ca_trace_file();
    }

    void end_of_simulation()
    {
        esc_close_ca_trace_file();
    }

protected:
    Vdut_rtl* dut_cyc0;
};

dut_cycsim* dut_cycsim_factory()
{
    return new dut_cycsimV("dut");
}

class dut_linkup
{
public:
    dut_linkup() {
        extern dut_cycsim* (*dut_cycsim_factory_p)();
        dut_cycsim_factory_p = &dut_cycsim_factory;
    }
};

// Create the one instance of the factory for this verilated model.
dut_linkup dut_cycsimV_link;


