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
    sc_signal< uint32_t > din_data_I;
    sc_signal< uint32_t > dout_data_O;
    sc_signal< uint32_t > mem_DIN0_O;
    sc_signal< uint32_t > mem_DOUT0_I;
    sc_signal< uint32_t > mem_A0_O;


    // The following threads are used to do the type conversion.
    inline void thread_din_data_I() {
        din_data_I = (sc_uint<8>)din_data.read();
    };
    inline void thread_dout_data_O() {
        dout_data = dout_data_O.read();
    };
    inline void thread_mem_DIN0_O() {
        mem_DIN0 = mem_DIN0_O.read();
    };
    inline void thread_mem_DOUT0_I() {
        mem_DOUT0_I = (sc_uint<8>)mem_DOUT0.read();
    };
    inline void thread_mem_A0_O() {
        mem_A0 = mem_A0_O.read();
    };


    SC_HAS_PROCESS(dut_cycsimV);

public:

    dut_cycsimV( sc_module_name in_name=sc_module_name(sc_gen_unique_name(" dut") ) )
        : dut_cycsim(in_name)
    {
        // instantiate the verilated module
        dut_cyc0 = new Vdut_rtl( "Vdut" );
        // generate port connections
        dut_cyc0->clk(clk);
        dut_cyc0->rst(rst);
        dut_cyc0->din_busy(din_busy);
        dut_cyc0->din_vld(din_vld);
        dut_cyc0->din_data(din_data_I);
        dut_cyc0->dout_busy(dout_busy);
        dut_cyc0->dout_vld(dout_vld);
        dut_cyc0->dout_data(dout_data_O);
        dut_cyc0->mem_WE0(mem_WE0);
        dut_cyc0->mem_DIN0(mem_DIN0_O);
        dut_cyc0->mem_DOUT0(mem_DOUT0_I);
        dut_cyc0->mem_A0(mem_A0_O);
        dut_cyc0->mem_REQ0(mem_REQ0);


        // setup the type conversion threads
        SC_METHOD( thread_din_data_I);
            sensitive << din_data;
        SC_METHOD( thread_dout_data_O);
            sensitive << dout_data_O;
        SC_METHOD( thread_mem_DIN0_O);
            sensitive << mem_DIN0_O;
        SC_METHOD( thread_mem_DOUT0_I);
            sensitive << mem_DOUT0;
        SC_METHOD( thread_mem_A0_O);
            sensitive << mem_A0_O;


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


