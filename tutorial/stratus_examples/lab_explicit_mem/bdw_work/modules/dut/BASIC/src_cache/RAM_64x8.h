///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2017 Cadence Design Systems, Inc. All rights reserved worldwide.
//
// The code contained herein is the proprietary and confidential information
// of Cadence or its licensors, and is supplied subject to a previously
// executed license and maintenance agreement between Cadence and customer.
// This code is intended for use with Cadence high-level synthesis tools and
// may not be used with other high-level synthesis tools. Permission is only
// granted to distribute the code as indicated. Cadence grants permission for
// customer to distribute a copy of this code to any partner to aid in designing
// or verifying the customer's intellectual property, as long as such
// distribution includes a restriction of no additional distributions from the
// partner, unless the partner receives permission directly from Cadence.
//
// ALL CODE FURNISHED BY CADENCE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
// KIND, AND CADENCE SPECIFICALLY DISCLAIMS ANY WARRANTY OF NONINFRINGEMENT,
// FITNESS FOR A PARTICULAR PURPOSE OR MERCHANTABILITY. CADENCE SHALL NOT BE
// LIABLE FOR ANY COSTS OF PROCUREMENT OF SUBSTITUTES, LOSS OF PROFITS,
// INTERRUPTION OF BUSINESS, OR FOR ANY OTHER SPECIAL, CONSEQUENTIAL OR
// INCIDENTAL DAMAGES, HOWEVER CAUSED, WHETHER FOR BREACH OF WARRANTY,
// CONTRACT, TORT, NEGLIGENCE, STRICT LIABILITY OR OTHERWISE.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef RAM_64x8_H
#define RAM_64x8_H

#include "systemc.h"
#include "cynthhl.h"


#if !defined(STRATUS_VLG)
#include "cynw_comm_util.h"
#include "cynw_fifo.h"
#endif
#include "cynw_memory.h"
#if defined STRATUS  &&  ! defined CYN_DONT_SUPPRESS_MSGS
#pragma cyn_suppress_msgs NOTE
#pragma hls_ip_def NOTE
#endif	// STRATUS  &&  CYN_DONT_SUPPRESS_MSGS
#if !defined(STRATUS_VLG)
#endif


#if defined(STRATUS_VLG) || defined(STRATUS_HLS)
SC_MODULE(RAM_64x8)
#else
struct RAM_64x8
  : public sc_module,
    public cynw_memory_if< sc_uint<6>, sc_uint<8> >
#endif
    {
	HLS_EXTERNAL_MODULE;

   sc_in< bool > CLK;
   sc_in< bool > WE0;
   sc_in< sc_uint<8> > DIN0;
   sc_out< sc_uint<8> > DOUT0;
   sc_in< sc_uint<6> > A0;
   sc_uint<8> mem[64];
 
 
#ifdef STRATUS_HLS
   sc_uint<8> read0(sc_uint<6> A0, bool WE0=1);

#endif	// STRATUS_HLS
#ifdef STRATUS_HLS
   sc_uint<8> write0(sc_uint<6> A0, sc_uint<8> DIN0, bool WE0=0);

#endif	// STRATUS_HLS
   void nop0(bool WE0=1);

 
   void thread0();

 
#if defined(STRATUS_VLG)
   SC_CTOR( RAM_64x8 );

#else
   SC_HAS_PROCESS( RAM_64x8 );

   RAM_64x8( sc_module_name name = sc_module_name(sc_gen_unique_name("RAM_64x8")));
#endif
   static const unsigned long implemented;
   static const unsigned long pipelined;
   static const float area;
   static const float delay;
   static const float setup_time;
   static const unsigned long latency_WE0;
   static const unsigned long latency_DIN0;
   static const unsigned long latency_A0;
   static const unsigned long bits_per_maskbit_WM0;
   static const unsigned long reg_mem_inputs;
   static const unsigned long reg_mem_outputs;
   static const unsigned long regs_at_mem_inputs;
   static const unsigned long regs_at_mem_outputs;
   static const unsigned long no_spec_reads;
   static const unsigned long is_mem;
   static const unsigned long clock_multiplier;
   static const bool has_extra_ports;


   typedef sc_uint<6>                       address_type;
   typedef sc_uint<8>                      data_type;
   
    enum {
        pipeline_depth = 1,
        mem_size = 64,
        SIZE = 64,
        address_width = 6,
        data_width = 8
    };


#if !defined(STRATUS_VLG) && !defined(STRATUS_HLS)
   // 
   // cynw_memory_if
   //
   data_type get( const address_type& address )
   {

#if defined(__GNUC__) && defined(BDW_TRACE_MEMS)
        fprintf(stderr,"TRACE: %s: %s: read 0x%s from 0x%x\n", name(), sc_time_stamp().to_string().c_str(), mem[address.to_uint()].to_string(SC_HEX).c_str(), (int)address.to_uint());
#endif
        return mem[address.to_uint()];
   }
   void put( const address_type& address, const data_type& data )
   {

#if defined(__GNUC__) && defined(BDW_TRACE_MEMS)
        fprintf(stderr,"TRACE: %s: %s: write 0x%s to 0x%x\n", name(), sc_time_stamp().to_string().c_str(), data.to_string(SC_HEX).c_str(), (int)address.to_uint());
#endif
        mem[address.to_uint()] = data;

}

#endif

#if defined(__GNUC__) && BDW_USE_SCV
    cynw_scv_memory_tx_stream< sc_uint<6>, sc_uint<8> >* m_p1_tx_stream;
    cynw_scv_memory_tx< sc_uint<6>, sc_uint<8> > m_p1_tx_0;
#endif

    //
    // External memory classes.
    //

    template <typename HLS_L=CYN::PIN, typename HLS_ACCESS=sc_uint<8>, HLS::HLS_INDEX_MAPPING_OPTIONS HLS_MAPPING = HLS::COMPACT> class port;
    template <typename HLS_L=CYN::PIN> class ex_port;
    template <typename HLS_L=CYN::PIN> class reg_ex_port;
    template <typename HLS_L=CYN::PIN, typename HLS_ACCESS=sc_uint<8>, HLS::HLS_INDEX_MAPPING_OPTIONS HLS_MAPPING = HLS::COMPACT> class stall_port;
    template <typename HLS_L=CYN::PIN, typename HLS_ACCESS=sc_uint<8>, HLS::HLS_INDEX_MAPPING_OPTIONS HLS_MAPPING = HLS::COMPACT> class reg_port;
    template <typename HLS_L=CYN::PIN> class shared_2;
    template <typename HLS_L=CYN::PIN> class shared_3;
    template <typename HLS_L=CYN::PIN> class shared_4;
    template <typename HLS_L=CYN::PIN> class wrapper;
    template <typename HLS_L=CYN::PIN> struct types;

};

// 
// struct containing signals to which a metaport can be bound
// 
struct RAM_64x8_ext_signals_1
{
   sc_signal< bool > WE0;
   sc_signal< bool > REQ0;
   sc_signal< sc_uint<8> > DIN0;
   sc_signal< sc_uint<8> > DOUT0;
   sc_signal< sc_uint<6> > A0;

};

//
// Type declarations
//
// The members of this struct can be accessed directly to 
// identify a type related to this memory model.  This same
// struct is also a base class for most other types related
// to the memory, and so its members can be referenced as 
// members of those memory-related classes.
//
// The template parameter HLS_L can have the following values:
//
//	 PIN : Selects types for pin-level implementations.
//   TLM : Selects types for TLM implementations.
//   
// Note that since the memory model class itself if not 
// templated, only the PIN-level classes can be accessed via
// the main memory model class.
//
template <typename HLS_L>
struct RAM_64x8::types
{  
    typedef sc_uint<6>                       address_type;
    typedef sc_uint<8>                      data_type;
    typedef sc_int<8>                       signed_type;
    typedef RAM_64x8                             mem_type;
    typedef cynw_memory_if< address_type, data_type >    if_type;
    typedef RAM_64x8::wrapper<HLS_L>                  wrapper;

    typedef RAM_64x8::port<HLS_L,data_type>              port;
    typedef RAM_64x8::ex_port<HLS_L>                     ex_port;
    typedef RAM_64x8::reg_ex_port<HLS_L>                 reg_ex_port;
    typedef RAM_64x8::reg_port<HLS_L,data_type>          reg_port;
    typedef RAM_64x8::stall_port<HLS_L,data_type>        stall_port;
    typedef RAM_64x8::shared_2<HLS_L>                 shared_2;
    typedef RAM_64x8::shared_3<HLS_L>                 shared_3;
    typedef RAM_64x8::shared_4<HLS_L>                 shared_4;
    typedef RAM_64x8_ext_signals_1             ext_signals_1;

   
    enum {
        pipeline_depth = 1,
        mem_size = 64,
        SIZE = 64,
        address_width = 6,
        data_width = 8
    };

};


//
// Simple external memory wrapper.
//
// PIN-level version.
// Select this version by either omitting the HLS_L template argument,
// or by setting it to PIN.
// 
//
template <typename HLS_L>
class RAM_64x8::wrapper :
    public sc_module,
    public RAM_64x8_ext_signals_1,
    public RAM_64x8::types<HLS_L>
{
  public:
    typedef RAM_64x8::wrapper<HLS_L>                 this_type;
  public:
    SC_HAS_PROCESS(wrapper);
    wrapper( sc_module_name in_name=sc_module_name( sc_gen_unique_name("RAM_64x8")) )
      : sc_module(in_name)
      , model(basename())  
	  ,CLK("CLK")
    {

        model.WE0(WE0);
        model.DIN0(DIN0);
        model.A0(A0);
        model.DOUT0(DOUT0);
        model.CLK(CLK);
    }
    template <class T0,class T1>
    void clk_rst( T0 & CLK_in, T1 & rst_in, bool rah=false )
    {
        CLK(CLK_in);
    }
    template <class T0,class T1>
    void clk_rst_sync( T0 & CLK_in, T1 & rst_in, bool rah=false )
    {
        CLK(CLK_in);
    }
    template <class T0,class T1>
    void clk_rst_async( T0 & CLK_in, T1 & rst_in, bool rah=false )
    {
        CLK(CLK_in);
    }
    template <class T0>
    void clk_rst( T0 & CLK_in )
    {
        CLK(CLK_in);
    }

  public:
   typedef sc_uint<6>                       address_type;
   typedef sc_uint<8>                      data_type;


    //
    // Ports.
    //
        sc_in_clk CLK;

    // 
    // The memory model.
    //
    RAM_64x8            model;
};



template <typename HLS_L>
class RAM_64x8::shared_2 :
    public sc_module,
    public RAM_64x8::types<HLS_L>
{   
  public:
    typedef RAM_64x8::shared_2<HLS_L>               this_type;
   typedef sc_uint<6>                       address_type;
   typedef sc_uint<8>                      data_type;
  public:
    SC_HAS_PROCESS(shared_2);
    shared_2( sc_module_name in_name=sc_module_name( sc_gen_unique_name("RAM_64x8")) )
      : sc_module(in_name)
      , model(basename())
	  ,CLK("CLK")
    {

        model.WE0(intsigs.WE0);
        model.DIN0(intsigs.DIN0);
        model.A0(intsigs.A0);
        model.DOUT0(intsigs.DOUT0);
        model.CLK(CLK);

        SC_METHOD(mux_inputs);
        sensitive << if1.WE0;
        sensitive << if1.DIN0;
        sensitive << if1.A0;
        sensitive << if1.REQ0;
        sensitive << if2.WE0;
        sensitive << if2.DIN0;
        sensitive << if2.A0;
        sensitive << if2.REQ0;

        SC_METHOD(gen_out_1);
        sensitive << intsigs.DOUT0;

        SC_METHOD(gen_out_2);
        sensitive << intsigs.DOUT0;
    }
    template <class T0,class T1>
    void clk_rst( T0 & CLK_in, T1 & rst_in, bool rah=false )
    {
        CLK(CLK_in);
    }
    template <class T0,class T1>
    void clk_rst_sync( T0 & CLK_in, T1 & rst_in, bool rah=false )
    {
        CLK(CLK_in);
    }
    template <class T0,class T1>
    void clk_rst_async( T0 & CLK_in, T1 & rst_in, bool rah=false )
    {
        CLK(CLK_in);
    }
    template <class T0>
    void clk_rst( T0 & CLK_in )
    {
        CLK(CLK_in);
    }

  public:

    //
    // Ports.
    //
    sc_in_clk CLK;


    //
    // Interface signals.
    //
    RAM_64x8_ext_signals_1    if1;
    RAM_64x8_ext_signals_1    if2;

    // 
    // The memory model.
    //
    RAM_64x8                    model;

  public:

    RAM_64x8_ext_signals_1    intsigs;

    // 
    // MUX for inputs based on which input is active.
    // Precedence is given to the first port.
    // If neither port is active, the memory inputs are 
    // written to an inactive state.
    //
    void mux_inputs()
    {
        HLS_REMOVE_CONTROL(ON,"");
        if (if1.REQ0) {
            intsigs.WE0 = if1.WE0;
            intsigs.REQ0 = if1.REQ0;
        } else if (if2.REQ0) {
            intsigs.WE0 = if2.WE0;
            intsigs.REQ0 = if2.REQ0;
        } else {
            intsigs.WE0 = 1;
            intsigs.REQ0 = 0;
        }
        if (if1.REQ0) {
            intsigs.DIN0 = if1.DIN0;
            intsigs.A0 = if1.A0;
        } else {
            intsigs.DIN0 = if2.DIN0;
            intsigs.A0 = if2.A0;
        }

    }


    //
    // Method to transfer memory output to if1
    //
    void gen_out_1()
    {
        if1.DOUT0 = intsigs.DOUT0;
    }


    //
    // Method to transfer memory output to if2
    //
    void gen_out_2()
    {
        if2.DOUT0 = intsigs.DOUT0;
    }

};

template <typename HLS_L>
class RAM_64x8::shared_3 :
    public sc_module,
    public RAM_64x8::types<HLS_L>
{   
  public:
    typedef RAM_64x8::shared_3<HLS_L>               this_type;
   typedef sc_uint<6>                       address_type;
   typedef sc_uint<8>                      data_type;
  public:
    SC_HAS_PROCESS(shared_3);
    shared_3( sc_module_name in_name=sc_module_name( sc_gen_unique_name("RAM_64x8")) )
      : sc_module(in_name)
      , model(basename())
	  ,CLK("CLK")
    {

        model.WE0(intsigs.WE0);
        model.DIN0(intsigs.DIN0);
        model.A0(intsigs.A0);
        model.DOUT0(intsigs.DOUT0);
        model.CLK(CLK);

        SC_METHOD(mux_inputs);
        sensitive << if1.WE0;
        sensitive << if1.DIN0;
        sensitive << if1.A0;
        sensitive << if1.REQ0;
        sensitive << if2.WE0;
        sensitive << if2.DIN0;
        sensitive << if2.A0;
        sensitive << if2.REQ0;
        sensitive << if3.WE0;
        sensitive << if3.DIN0;
        sensitive << if3.A0;
        sensitive << if3.REQ0;

        SC_METHOD(gen_out_1);
        sensitive << intsigs.DOUT0;

        SC_METHOD(gen_out_2);
        sensitive << intsigs.DOUT0;

        SC_METHOD(gen_out_3);
        sensitive << intsigs.DOUT0;
    }
    template <class T0,class T1>
    void clk_rst( T0 & CLK_in, T1 & rst_in, bool rah=false )
    {
        CLK(CLK_in);
    }
    template <class T0,class T1>
    void clk_rst_sync( T0 & CLK_in, T1 & rst_in, bool rah=false )
    {
        CLK(CLK_in);
    }
    template <class T0,class T1>
    void clk_rst_async( T0 & CLK_in, T1 & rst_in, bool rah=false )
    {
        CLK(CLK_in);
    }
    template <class T0>
    void clk_rst( T0 & CLK_in )
    {
        CLK(CLK_in);
    }

  public:

    //
    // Ports.
    //
    sc_in_clk CLK;


    //
    // Interface signals.
    //
    RAM_64x8_ext_signals_1    if1;
    RAM_64x8_ext_signals_1    if2;
    RAM_64x8_ext_signals_1    if3;

    // 
    // The memory model.
    //
    RAM_64x8                    model;

  public:

    RAM_64x8_ext_signals_1    intsigs;

    // 
    // MUX for inputs based on which input is active.
    // Precedence is given to the first port.
    // If neither port is active, the memory inputs are 
    // written to an inactive state.
    //
    void mux_inputs()
    {
        HLS_REMOVE_CONTROL(ON,"");
        if (if1.REQ0) {
            intsigs.WE0 = if1.WE0;
            intsigs.REQ0 = if1.REQ0;
        } else if (if2.REQ0) {
            intsigs.WE0 = if2.WE0;
            intsigs.REQ0 = if2.REQ0;
        } else if (if3.REQ0) {
            intsigs.WE0 = if3.WE0;
            intsigs.REQ0 = if3.REQ0;
        } else {
            intsigs.WE0 = 1;
            intsigs.REQ0 = 0;
        }
        if (if1.REQ0) {
            intsigs.DIN0 = if1.DIN0;
            intsigs.A0 = if1.A0;
        } else if (if2.REQ0) {
            intsigs.DIN0 = if2.DIN0;
            intsigs.A0 = if2.A0;
        } else {
            intsigs.DIN0 = if3.DIN0;
            intsigs.A0 = if3.A0;
        }

    }


    //
    // Method to transfer memory output to if1
    //
    void gen_out_1()
    {
        if1.DOUT0 = intsigs.DOUT0;
    }


    //
    // Method to transfer memory output to if2
    //
    void gen_out_2()
    {
        if2.DOUT0 = intsigs.DOUT0;
    }


    //
    // Method to transfer memory output to if3
    //
    void gen_out_3()
    {
        if3.DOUT0 = intsigs.DOUT0;
    }

};

template <typename HLS_L>
class RAM_64x8::shared_4 :
    public sc_module,
    public RAM_64x8::types<HLS_L>
{   
  public:
    typedef RAM_64x8::shared_4<HLS_L>               this_type;
   typedef sc_uint<6>                       address_type;
   typedef sc_uint<8>                      data_type;
  public:
    SC_HAS_PROCESS(shared_4);
    shared_4( sc_module_name in_name=sc_module_name( sc_gen_unique_name("RAM_64x8")) )
      : sc_module(in_name)
      , model(basename())
	  ,CLK("CLK")
    {

        model.WE0(intsigs.WE0);
        model.DIN0(intsigs.DIN0);
        model.A0(intsigs.A0);
        model.DOUT0(intsigs.DOUT0);
        model.CLK(CLK);

        SC_METHOD(mux_inputs);
        sensitive << if1.WE0;
        sensitive << if1.DIN0;
        sensitive << if1.A0;
        sensitive << if1.REQ0;
        sensitive << if2.WE0;
        sensitive << if2.DIN0;
        sensitive << if2.A0;
        sensitive << if2.REQ0;
        sensitive << if3.WE0;
        sensitive << if3.DIN0;
        sensitive << if3.A0;
        sensitive << if3.REQ0;
        sensitive << if4.WE0;
        sensitive << if4.DIN0;
        sensitive << if4.A0;
        sensitive << if4.REQ0;

        SC_METHOD(gen_out_1);
        sensitive << intsigs.DOUT0;

        SC_METHOD(gen_out_2);
        sensitive << intsigs.DOUT0;

        SC_METHOD(gen_out_3);
        sensitive << intsigs.DOUT0;

        SC_METHOD(gen_out_4);
        sensitive << intsigs.DOUT0;
    }
    template <class T0,class T1>
    void clk_rst( T0 & CLK_in, T1 & rst_in, bool rah=false )
    {
        CLK(CLK_in);
    }
    template <class T0,class T1>
    void clk_rst_sync( T0 & CLK_in, T1 & rst_in, bool rah=false )
    {
        CLK(CLK_in);
    }
    template <class T0,class T1>
    void clk_rst_async( T0 & CLK_in, T1 & rst_in, bool rah=false )
    {
        CLK(CLK_in);
    }
    template <class T0>
    void clk_rst( T0 & CLK_in )
    {
        CLK(CLK_in);
    }

  public:

    //
    // Ports.
    //
    sc_in_clk CLK;


    //
    // Interface signals.
    //
    RAM_64x8_ext_signals_1    if1;
    RAM_64x8_ext_signals_1    if2;
    RAM_64x8_ext_signals_1    if3;
    RAM_64x8_ext_signals_1    if4;

    // 
    // The memory model.
    //
    RAM_64x8                    model;

  public:

    RAM_64x8_ext_signals_1    intsigs;

    // 
    // MUX for inputs based on which input is active.
    // Precedence is given to the first port.
    // If neither port is active, the memory inputs are 
    // written to an inactive state.
    //
    void mux_inputs()
    {
        HLS_REMOVE_CONTROL(ON,"");
        if (if1.REQ0) {
            intsigs.WE0 = if1.WE0;
            intsigs.REQ0 = if1.REQ0;
        } else if (if2.REQ0) {
            intsigs.WE0 = if2.WE0;
            intsigs.REQ0 = if2.REQ0;
        } else if (if3.REQ0) {
            intsigs.WE0 = if3.WE0;
            intsigs.REQ0 = if3.REQ0;
        } else if (if4.REQ0) {
            intsigs.WE0 = if4.WE0;
            intsigs.REQ0 = if4.REQ0;
        } else {
            intsigs.WE0 = 1;
            intsigs.REQ0 = 0;
        }
        if (if1.REQ0) {
            intsigs.DIN0 = if1.DIN0;
            intsigs.A0 = if1.A0;
        } else if (if2.REQ0) {
            intsigs.DIN0 = if2.DIN0;
            intsigs.A0 = if2.A0;
        } else if (if3.REQ0) {
            intsigs.DIN0 = if3.DIN0;
            intsigs.A0 = if3.A0;
        } else {
            intsigs.DIN0 = if4.DIN0;
            intsigs.A0 = if4.A0;
        }

    }


    //
    // Method to transfer memory output to if1
    //
    void gen_out_1()
    {
        if1.DOUT0 = intsigs.DOUT0;
    }


    //
    // Method to transfer memory output to if2
    //
    void gen_out_2()
    {
        if2.DOUT0 = intsigs.DOUT0;
    }


    //
    // Method to transfer memory output to if3
    //
    void gen_out_3()
    {
        if3.DOUT0 = intsigs.DOUT0;
    }


    //
    // Method to transfer memory output to if4
    //
    void gen_out_4()
    {
        if4.DOUT0 = intsigs.DOUT0;
    }

};

#if !defined(STRATUS_VLG)
//
// PIN-level metaport.
//
// Select this version by either omitting the HLS_L template argument,
// or by setting it to PIN.
//
template <typename HLS_L,typename HLS_ACCESS,HLS::HLS_INDEX_MAPPING_OPTIONS HLS_MAPPING>
class RAM_64x8::port
  : public RAM_64x8::types<HLS_L>
  , public cynw_clk_rst_facade
{
  public:
    HLS_METAPORT;
    typedef RAM_64x8::port<HLS_L,HLS_ACCESS,HLS_MAPPING>            this_type;
    typedef cynw_memory_ref< this_type, HLS_ACCESS, HLS_MAPPING > ref_type;
    typedef sc_uint<6>                       address_type;
    typedef sc_uint<8>                      data_type;
    typedef unsigned int                          mask_type;
    class shared_2;
    class shared_3;
    class shared_4;

    port( 
		const char* in_name=sc_gen_unique_name("port"),
		  unsigned options_in=0)
        : m_options(options_in|HLS_DEF_NO_CHAIN_MEM_IN | HLS_DEF_CHAIN_MEM_OUT | HLS_DEF_NO_SPEC_READS), 
          WE0( HLS_CAT_NAMES(in_name,"WE0") ),
        DIN0( HLS_CAT_NAMES(in_name,"DIN0") ),
        DOUT0( HLS_CAT_NAMES(in_name,"DOUT0") ),
        A0( HLS_CAT_NAMES(in_name,"A0") ),
        REQ0( HLS_CAT_NAMES(in_name,"REQ0") ),
          m_reset_done(false)
    {
        p_name = new char[strlen(in_name)+1];
        strcpy(p_name,in_name);
        m_tx_stream = 0;
        m_stream_name = (std::string("sc_main.") + std::string(::sc_core::sc_get_curr_simcontext()->hierarchy_curr()->name()) + std::string(".") + std::string(in_name));
    }

    ~port()
    {
        delete p_name;
	}

    CYNW_MEM_SQUARE_BRACKETS( ref_type )
  public:
	char* p_name;
	bool m_reset_done;

	const char* name() { return p_name; }

    cynw_scv_memory_tx_stream< address_type, data_type >* tx_stream()
    {
#if !STRATUS
      if (m_tx_stream == 0) {
        esc_enable_scv_logging();
        m_tx_stream = new cynw_scv_memory_tx_stream< address_type, data_type >( m_stream_name.c_str(), esc_get_scv_tr_db() );
	  }
      return m_tx_stream;
#else
      return 0;
#endif
    }

    void nb_get_start( const address_type& address )
    {
        this->WE0 = 1;
        this->A0 = address;
        this->REQ0 = 1;
    }
    bool nb_get( data_type& val )
    {
        val = this->DOUT0.read();
        return true;
    }
    sc_event_finder& value_changed()
    {
        return this->DOUT0.value_changed();
    }
    data_type get( const address_type& address )
    {
        HLS_DEFINE_FLOATING_PROTOCOL( 0.1000, 0.1000, 1, this, this->m_options|HLS::HLS_MEM_READ_FP|HLS::HLS_UNSTALLABLE_FP, address, "mem_read" );
        HLS_SET_OUTPUT_OPTIONS(this->A0,ASYNC_POWER_HOLD);
        this->check_reset();
        cynw_scv_memory_tx< address_type, data_type > tx = this->tx_stream()->begin_read_tx( address );
        nb_get_start(address);
        ::wait(1);
        nb_deassert();
        ::wait( 1 );
        if (this->m_options & HLS::HLS_USING_REG_PORT) {
            ::wait(1);
            ::wait(1);
        }
        if (this->m_options & HLS::HLS_USING_REG_EX_PORT) {
            ::wait(1);
            ::wait(1);
        }

        data_type val;
        nb_get(val);
        this->tx_stream()->end_read_tx( tx, val );
        return val;
    }
    void nb_put( const address_type& address, const data_type& data, const mask_type mask )
    {
        this->WE0 = 0;
        this->A0 = address;
        this->DIN0 = data;
        this->REQ0 = 1;
    }
    void put( const address_type& address, const data_type& data, mask_type mask )
    {
        HLS_DEFINE_FLOATING_PROTOCOL( 0.1000, 0.0, 1, this, this->m_options|HLS::HLS_MEM_WRITE_FP|HLS::HLS_USING_REG_EX_PORT, address, "mem_write" );
        HLS_SET_OUTPUT_OPTIONS(this->DIN0,ASYNC_POWER_HOLD);
        HLS_SET_OUTPUT_OPTIONS(this->A0,ASYNC_POWER_HOLD);
        this->check_reset();
        cynw_scv_memory_tx< address_type, data_type > tx = this->tx_stream()->begin_write_tx( address, data );
        nb_put(address,data,mask);
        ::wait(1);
        nb_deassert();
        this->tx_stream()->end_write_tx( tx );
    }
    void nb_put( const address_type& address, const data_type& data )
    {
        nb_put(address, data, ~0);
    }
    void put( const address_type& address, const data_type& data )
    {
        put(address, data, ~0);
    }
    void reset( bool control_only=true )
    {
        HLS_DEFINE_PROTOCOL("reset");
        this->m_reset_done = true;
        this->WE0 = 1;
        this->REQ0 = 0;
        if (!control_only) this->A0 = 0;
        if (!control_only) this->DIN0 = 0;
        HLS_SUPPRESS_MSG_SYM( 1435, this->A0 );
        HLS_SUPPRESS_MSG_SYM( 1435, this->DIN0 );
        HLS_SET_STALL_VALUE( this->WE0, 1);
    }

    void nb_deassert()
    {
        this->m_reset_done = true;
        this->WE0 = 1;
        this->REQ0 = 0;
    }

    void check_reset()
    {
#if !defined(STRATUS_HLS) && !defined(STRATUS_VLG) && !defined(BDW_EXTRACT)
        if (!m_reset_done)
        {
            printf("WARNING: Access to external memory port '%s' before calling reset()\n", name());
            m_reset_done = true;
        }
#endif
    }

    template <class W>
    void bind( W& iface )
    {
        this->WE0(iface.WE0);
        this->DIN0(iface.DIN0);
        this->DOUT0(iface.DOUT0);
        this->A0(iface.A0);
        this->REQ0(iface.REQ0);

    }

    template <class W>
    void operator()( W& iface )
    {
      bind(iface);
    }

  public:
	unsigned m_options;
    cynw_scv_memory_tx_stream< address_type, data_type >* m_tx_stream;
	std::string m_stream_name;

   sc_out< bool > WE0;
   sc_out< sc_uint<8> > DIN0;
   sc_in< sc_uint<8> > DOUT0;
   sc_out< sc_uint<6> > A0;
 
        sc_out<bool> REQ0;
};

#endif

#if !defined(STRATUS_VLG)
//
// PIN-level export metaport.
//
// Select this version by either omitting the HLS_L template argument,
// or by setting it to PIN.
//
template <typename HLS_L>
class RAM_64x8::ex_port
  : public RAM_64x8::types<HLS_L>
{
  public:
    HLS_METAPORT;
    typedef RAM_64x8::ex_port<HLS_L>            this_type;
   typedef sc_uint<6>                       address_type;
   typedef sc_uint<8>                      data_type;

    ex_port( const char* in_name=sc_gen_unique_name("ex_port") )
        : WE0( HLS_CAT_NAMES(in_name,"WE0") ),
        DIN0( HLS_CAT_NAMES(in_name,"DIN0") ),
        DOUT0( HLS_CAT_NAMES(in_name,"DOUT0") ),
        A0( HLS_CAT_NAMES(in_name,"A0") ),
        REQ0( HLS_CAT_NAMES(in_name,"REQ0") )
    {}

  public:


    template <class W>
    void bind( W& iface )
    {
        WE0(iface.WE0);
        DIN0(iface.DIN0);
        DOUT0(iface.DOUT0);
        A0(iface.A0);
        REQ0(iface.REQ0);

    }

    template <class W>
    void operator()( W& iface )
    {
      bind(iface);
    }

  public:

   sc_export< sc_signal_out_if< bool > > WE0;
   sc_export< sc_signal_out_if< sc_uint<8> > > DIN0;
   sc_export< sc_signal_in_if< sc_uint<8> > > DOUT0;
   sc_export< sc_signal_out_if< sc_uint<6> > > A0;
 
        sc_export< sc_signal_out_if<bool> > REQ0;
};

#endif

#if !defined(STRATUS_VLG)
//
// PIN-level export metaport with a register included.
//
// Select this version by either omitting the HLS_L template argument,
// or by setting it to PIN.
//
template <typename HLS_L>
class RAM_64x8::reg_ex_port
  : public RAM_64x8::ex_port<HLS_L>,
	public sc_module,
	public cynw_clk_rst

{
  public:
    typedef RAM_64x8::reg_ex_port<HLS_L>            this_type;
    typedef RAM_64x8::ex_port<HLS_L>            base_type;
   typedef sc_uint<6>                       address_type;
   typedef sc_uint<8>                      data_type;

    SC_HAS_PROCESS(this_type);

    reg_ex_port( sc_module_name in_name=sc_module_name( sc_gen_unique_name("reg_ex_port") ) )
        : base_type(in_name)
		, sc_module(in_name)
		, WE0_reg( HLS_CAT_NAMES(in_name,"WE0_reg") ),
        DIN0_reg( HLS_CAT_NAMES(in_name,"DIN0_reg") ),
        DOUT0_reg( HLS_CAT_NAMES(in_name,"DOUT0_reg") ),
        A0_reg( HLS_CAT_NAMES(in_name,"A0_reg") ),
        REQ0_reg( HLS_CAT_NAMES(in_name,"REQ0_reg") )
		, WE0_p( HLS_CAT_NAMES(in_name,"WE0_p") ),
        DIN0_p( HLS_CAT_NAMES(in_name,"DIN0_p") ),
        DOUT0_p( HLS_CAT_NAMES(in_name,"DOUT0_p") ),
        A0_p( HLS_CAT_NAMES(in_name,"A0_p") ),
        REQ0_p( HLS_CAT_NAMES(in_name,"REQ0_p") )
    {
        this->WE0(WE0_reg);
        this->DIN0(DIN0_reg);
        this->DOUT0(DOUT0_reg);
        this->A0(A0_reg);
        this->REQ0(REQ0_reg);


        SC_METHOD(do_reg);
        sensitive << clk.pos();
        dont_initialize();

	}

  public:


    template <class W>
    void bind( W& iface )
    {
        WE0_p(iface.WE0);
        DIN0_p(iface.DIN0);
        DOUT0_p(iface.DOUT0);
        A0_p(iface.A0);
        REQ0_p(iface.REQ0);

    }

    template <class W>
    void operator()( W& iface )
    {
      bind(iface);
    }

    void do_reg()
    {
        if ( rst_active() ) 
        {
	         HLS_SET_IS_RESET_BLOCK("do_reg");
            WE0_p = 1;
            REQ0_p = 0;
        } else {
            WE0_p.write( WE0_reg.read() );
            REQ0_p.write( REQ0_reg.read() );
            DIN0_p.write( DIN0_reg.read() );
            DOUT0_reg.write( DOUT0_p.read() );
            A0_p.write( A0_reg.read() );

        }
    }
  public:

        sc_signal< bool > WE0_reg;
        sc_signal< sc_uint<8> > DIN0_reg;
        sc_signal< sc_uint<8> > DOUT0_reg;
        sc_signal< sc_uint<6> > A0_reg;
        sc_signal< bool > REQ0_reg;
        sc_out< bool > WE0_p;
        sc_out< sc_uint<8> > DIN0_p;
        sc_out< sc_uint<6> > A0_p;
        sc_out< bool > REQ0_p;
        sc_in< sc_uint<8> > DOUT0_p;
};

#endif

#if !defined(STRATUS_VLG)
//
// PIN-level metaport with stalling support.
//
// Select this version by either omitting the HLS_L template argument,
// or by setting it to PIN.
//
template <typename HLS_L,typename HLS_ACCESS,HLS::HLS_INDEX_MAPPING_OPTIONS HLS_MAPPING>
class RAM_64x8::stall_port
  : public RAM_64x8::port<HLS_L,HLS_ACCESS,HLS_MAPPING>,
    public sc_module,
    public cynw_clk_rst
{
  public:
    typedef RAM_64x8::stall_port<HLS_L,HLS_ACCESS,HLS_MAPPING>       this_type;
    typedef RAM_64x8::port<HLS_L,HLS_ACCESS,HLS_MAPPING>       base_type;
    typedef cynw_memory_ref< this_type, HLS_ACCESS, HLS_MAPPING > ref_type;
    typedef sc_uint<6>                       address_type;
    typedef sc_uint<8>                      data_type;
    typedef unsigned int                          mask_type;

    SC_HAS_PROCESS(this_type);

    HLS_EXPOSE_PORT( OFF, clk );
    HLS_EXPOSE_PORT( OFF, rst );

    sc_signal<data_type> fifo_dout;
    sc_signal<bool> tx_start;
    sc_signal<bool> tx_end;
    sc_signal<bool> tx_running;
    sc_signal<bool> m_stalling;

    stall_port( 
	  sc_module_name in_name=sc_module_name( sc_gen_unique_name("port") ), unsigned options_in=0)
      : sc_module(in_name),
		cynw_clk_rst(in_name),
		base_type(in_name,options_in|HLS_DEF_NO_CHAIN_MEM_IN | HLS_DEF_CHAIN_MEM_OUT | HLS_DEF_NO_SPEC_READS),
		fifo(in_name),
        tx_start("tx_start"),
        tx_end("tx_end"),
        m_stalling("m_stalling")
    {

      fifo.stalling(m_stalling);
      fifo.start(tx_start);
      fifo.end(tx_end);
      fifo.running(tx_running);
      fifo.din(this->DOUT0);
      fifo.dout(fifo_dout);
      fifo.clk_rst(*this);

    }

    CYNW_MEM_SQUARE_BRACKETS( ref_type )

	CYNW_CLK_RST_FUNCS

  public:

    // 
    // Fifo for storing memory outputs during a stall.
    // Depth matches the latency of the memory.
    //
    cynw_stall_fifo< data_type, 1, HLS_L > fifo;


    void nb_get_start( const address_type& address )
    {
        this->WE0 = 1;
        this->A0 = address;
        this->REQ0 = 1;
        tx_start = 1;
    }
    bool nb_get( data_type& val )
    {
        val = this->fifo_dout.read();
        return true;
    }
    sc_event_finder& value_changed()
    {
        return this->fifo_dout.value_changed();
    }
    data_type get( const address_type& address )
    {
        HLS_DEFINE_FLOATING_PROTOCOL( 0.1000, -1, 1, this, this->m_options|HLS::HLS_MEM_READ_FP, address, "mem_read" );
        HLS_SET_OUTPUT_OPTIONS(this->A0,ASYNC_POWER_HOLD);
        this->check_reset();
        cynw_scv_memory_tx< address_type, data_type > tx = this->tx_stream()->begin_read_tx( address );
        nb_get_start(address);
        ::wait(1);
        nb_deassert();
        ::wait( 1 );
        if (this->m_options & HLS::HLS_USING_REG_PORT) {
            ::wait(1);
            ::wait(1);
        }
        if (this->m_options & HLS::HLS_USING_REG_EX_PORT) {
            ::wait(1);
            ::wait(1);
        }

        data_type val;
        nb_get(val);
        this->tx_stream()->end_read_tx( tx, val );
        return val;
    }
    void nb_put( const address_type& address, const data_type& data, const mask_type mask )
    {
        this->WE0 = 0;
        this->A0 = address;
        this->DIN0 = data;
        this->REQ0 = 1;
    }
    void put( const address_type& address, const data_type& data, mask_type mask )
    {
        HLS_DEFINE_FLOATING_PROTOCOL( 0.1000, 0.0, 1, this, this->m_options|HLS::HLS_MEM_WRITE_FP|HLS::HLS_USING_REG_EX_PORT, address, "mem_write" );
        HLS_SET_OUTPUT_OPTIONS(this->DIN0,ASYNC_POWER_HOLD);
        HLS_SET_OUTPUT_OPTIONS(this->A0,ASYNC_POWER_HOLD);
        this->check_reset();
        cynw_scv_memory_tx< address_type, data_type > tx = this->tx_stream()->begin_write_tx( address, data );
        nb_put(address,data,mask);
        ::wait(1);
        nb_deassert();
        this->tx_stream()->end_write_tx( tx );
    }
    void nb_put( const address_type& address, const data_type& data )
    {
        nb_put(address, data, ~0);
    }
    void put( const address_type& address, const data_type& data )
    {
        put(address, data, ~0);
    }
    void reset( bool control_only=true )
    {
        HLS_DEFINE_PROTOCOL("reset");
        this->m_reset_done = true;
        this->WE0 = 1;
        this->REQ0 = 0;
        if (!control_only) this->A0 = 0;
        if (!control_only) this->DIN0 = 0;
        HLS_SUPPRESS_MSG_SYM( 1435, this->A0 );
        HLS_SUPPRESS_MSG_SYM( 1435, this->DIN0 );
        tx_start = 0;
        cynw_assert_during_stall( m_stalling, 1 );
        HLS_SET_STALL_VALUE( this->WE0, 1);
    }

    void nb_deassert()
    {
        this->m_reset_done = true;
        this->WE0 = 1;
        this->REQ0 = 0;
        tx_start = 0;
    }

    template <class W>
    void bind( W& iface )
    {
        this->WE0(iface.WE0);
        this->DIN0(iface.DIN0);
        this->DOUT0(iface.DOUT0);
        this->A0(iface.A0);
        this->REQ0(iface.REQ0);

    }

    template <class W>
    void operator()( W& iface )
    {
      bind(iface);
    }
};
#endif

#if !defined(STRATUS_VLG)
//
// PIN-level metaport with an explicit register on DOUT support.
//
// Select this version by either omitting the HLS_L template argument,
// or by setting it to PIN.
//
template <typename HLS_L,typename HLS_ACCESS,HLS::HLS_INDEX_MAPPING_OPTIONS HLS_MAPPING>
class RAM_64x8::reg_port
  : public RAM_64x8::port<HLS_L,HLS_ACCESS,HLS_MAPPING>,
    public sc_module,
    public cynw_clk_rst
{
  public:
    typedef RAM_64x8::reg_port<HLS_L,HLS_ACCESS,HLS_MAPPING>       this_type;
    typedef RAM_64x8::port<HLS_L,HLS_ACCESS,HLS_MAPPING>       base_type;
    typedef cynw_memory_ref< this_type, HLS_ACCESS, HLS_MAPPING > ref_type;
    typedef sc_uint<6>                       address_type;
    typedef sc_uint<8>                      data_type;
    typedef unsigned int                          mask_type;

    SC_HAS_PROCESS(this_type);

    HLS_EXPOSE_PORT( OFF, clk );
    HLS_EXPOSE_PORT( OFF, rst );

    reg_port( 
	  sc_module_name in_name=sc_module_name( sc_gen_unique_name("port") ), 
	  unsigned options_in=0 )
      : sc_module(in_name)
	  ,	cynw_clk_rst(in_name)
	  ,	base_type(in_name,options_in|HLS_DEF_NO_CHAIN_MEM_IN | HLS_DEF_CHAIN_MEM_OUT | HLS_DEF_NO_SPEC_READS)
    {

	  SC_METHOD(do_reg_c);
      sensitive << clk.pos();
      dont_initialize();

	  SC_METHOD(do_reg_din);
      sensitive << clk.pos();
      dont_initialize();

	  SC_METHOD(do_reg_dout);
      sensitive << clk.pos();
      dont_initialize();

    }

    CYNW_MEM_SQUARE_BRACKETS( ref_type )

	CYNW_CLK_RST_FUNCS

  public:
    void nb_get_start( const address_type& address )
    {
        this->if_inner.WE0 = 1;
        this->if_inner.A0 = address;
        this->if_inner.REQ0 = 1;
    }
    bool nb_get( data_type& val )
    {
        val = this->if_inner.DOUT0.read();
        return true;
    }
    sc_event_finder& value_changed()
    {
        return this->if_inner.DOUT0.value_changed();
    }
    data_type get( const address_type& address )
    {
        HLS_DEFINE_FLOATING_PROTOCOL( HLS_REG_SETUP_TIME, HLS_REG_DELAY, 1, this, this->m_options|HLS::HLS_MEM_READ_FP|HLS::HLS_UNSTALLABLE_FP, address, "mem_read" );
        HLS_SET_OUTPUT_OPTIONS(this->if_inner.A0,ASYNC_POWER_HOLD);
        this->check_reset();
        cynw_scv_memory_tx< address_type, data_type > tx = this->tx_stream()->begin_read_tx( address );
        nb_get_start(address);
        ::wait(1);
        nb_deassert();
        ::wait( 3 );
        if (this->m_options & HLS::HLS_USING_REG_EX_PORT) {
            ::wait(1);
            ::wait(1);
        }

        data_type val;
        nb_get(val);
        this->tx_stream()->end_read_tx( tx, val );
        return val;
    }
    void nb_put( const address_type& address, const data_type& data, const mask_type mask )
    {
        this->if_inner.WE0 = 0;
        this->if_inner.A0 = address;
        this->if_inner.DIN0 = data;
        this->if_inner.REQ0 = 1;
    }
    void put( const address_type& address, const data_type& data, mask_type mask )
    {
        HLS_DEFINE_FLOATING_PROTOCOL( HLS_REG_SETUP_TIME, 0.0, 1, this, this->m_options|HLS::HLS_MEM_WRITE_FP|HLS::HLS_USING_REG_EX_PORT, address, "mem_write" );
        HLS_SET_OUTPUT_OPTIONS(this->if_inner.DIN0,ASYNC_POWER_HOLD);
        HLS_SET_OUTPUT_OPTIONS(this->if_inner.A0,ASYNC_POWER_HOLD);
        this->check_reset();
        cynw_scv_memory_tx< address_type, data_type > tx = this->tx_stream()->begin_write_tx( address, data );
        nb_put(address,data,mask);
        ::wait(1);
        nb_deassert();
        this->tx_stream()->end_write_tx( tx );
    }
    void nb_put( const address_type& address, const data_type& data )
    {
        nb_put(address, data, ~0);
    }
    void put( const address_type& address, const data_type& data )
    {
        put(address, data, ~0);
    }
    void reset( bool control_only=true )
    {
        HLS_DEFINE_PROTOCOL("reset");
        this->m_reset_done = true;
        this->if_inner.WE0 = 1;
        this->if_inner.REQ0 = 0;
        if (!control_only) this->if_inner.A0 = 0;
        if (!control_only) this->if_inner.DIN0 = 0;
        HLS_SUPPRESS_MSG_SYM( 1435, this->if_inner.A0 );
        HLS_SUPPRESS_MSG_SYM( 1435, this->if_inner.DIN0 );
        HLS_SET_STALL_VALUE( this->WE0, 1);
    }

    void nb_deassert()
    {
        this->m_reset_done = true;
        this->if_inner.WE0 = 1;
        this->if_inner.REQ0 = 0;
    }

    template <class W>
    void bind( W& iface )
    {
        this->WE0(iface.WE0);
        this->DIN0(iface.DIN0);
        this->DOUT0(iface.DOUT0);
        this->A0(iface.A0);
        this->REQ0(iface.REQ0);

    }

    template <class W>
    void operator()( W& iface )
    {
      bind(iface);
    }
    RAM_64x8_ext_signals_1    if_inner;

    void do_reg_c()
    {
        if ( rst_active() ) 
        {
            HLS_SET_IS_RESET_BLOCK("do_reg_c");
            this->WE0 = 1;
            this->REQ0 = 0;
        } else {
            this->WE0.write( if_inner.WE0.read() );
            this->REQ0.write( if_inner.REQ0.read() );

        }
    }

    void do_reg_din()
    {
	bool rst = rst_active(); 
            this->DIN0.write( if_inner.DIN0.read() );
            this->A0.write( if_inner.A0.read() );

    }

    void do_reg_dout()
    {
	bool rst = rst_active(); 
            if_inner.DOUT0.write( this->DOUT0.read() );

    }

};
#endif

#if !defined(STRATUS_VLG)
template <typename HLS_L,typename HLS_ACCESS,HLS::HLS_INDEX_MAPPING_OPTIONS HLS_MAPPING>
class RAM_64x8::port<HLS_L,HLS_ACCESS,HLS_MAPPING>::shared_2 :
    public sc_module,
	public cynw_clk_rst_facade
{   
  public:
    typedef RAM_64x8::port<HLS_L,HLS_ACCESS,HLS_MAPPING>           port_type;

    typedef typename port_type::shared_2                  this_type;
   typedef sc_uint<6>                  address_type;
   typedef sc_uint<8>                data_type;
  public:
    SC_HAS_PROCESS(shared_2);
    shared_2( sc_module_name in_name=sc_module_name( sc_gen_unique_name("shared_2") ), unsigned options_in=0)
      : sc_module(in_name)
      , m_port(in_name)
      , m_options(options_in)
    {


        SC_METHOD(mux_inputs);
        sensitive << if1.WE0;
        sensitive << if1.DIN0;
        sensitive << if1.A0;
        sensitive << if1.REQ0;
        sensitive << if2.WE0;
        sensitive << if2.DIN0;
        sensitive << if2.A0;
        sensitive << if2.REQ0;

        SC_METHOD(gen_out_1);
        sensitive << m_port.DOUT0;

        SC_METHOD(gen_out_2);
        sensitive << m_port.DOUT0;
    }

  public:

    //
    // Interface signals.
    //
    RAM_64x8_ext_signals_1    if1;
    RAM_64x8_ext_signals_1    if2;


    unsigned m_options;

    // 
    // MUX for inputs based on which input is active.
    // Precedence is given to the first port.
    // If neither port is active, the memory inputs are 
    // written to an inactive state.
    //
    void mux_inputs()
    {
        HLS_REMOVE_CONTROL(ON,"");
       if ( (m_options & (HLS::HLS_USING_REG_PORT | HLS::HLS_USING_REG_EX_PORT)) == 0 ) {
            HLS_SET_OUTPUT_DELAY( m_port.WE0, 0.1000 );
            HLS_SET_OUTPUT_DELAY( m_port.DIN0, 0.1000 );
            HLS_SET_OUTPUT_DELAY( m_port.A0, 0.1000 );
            HLS_SET_OUTPUT_DELAY( m_port.REQ0, 0.1000 );
       }
        if (if1.REQ0) {
            m_port.WE0 = if1.WE0;
            m_port.DIN0 = if1.DIN0;
            m_port.A0 = if1.A0;
            m_port.REQ0 = if1.REQ0;
        } else if (if2.REQ0) {
            m_port.WE0 = if2.WE0;
            m_port.DIN0 = if2.DIN0;
            m_port.A0 = if2.A0;
            m_port.REQ0 = if2.REQ0;
        } else {
            m_port.WE0 = 1;
            m_port.DIN0 = 0;
            m_port.A0 = 0;
            m_port.REQ0 = 0;

        }
    }


    //
    // Method to transfer memory output to if1
    //
    void gen_out_1()
    {
        if1.DOUT0 = m_port.DOUT0; 
    }
    


    //
    // Method to transfer memory output to if2
    //
    void gen_out_2()
    {
        if2.DOUT0 = m_port.DOUT0; 
    }
    


    template <class W>
    void bind( W& iface )
    {
        m_port.WE0(iface.WE0);
        m_port.DIN0(iface.DIN0);
        m_port.DOUT0(iface.DOUT0);
        m_port.A0(iface.A0);
        m_port.REQ0(iface.REQ0);

    }

    template <class W>
    void operator()( W& iface )
    {
      bind(iface);
    }

	port_type m_port;
};
#endif


#if !defined(STRATUS_VLG)
template <typename HLS_L,typename HLS_ACCESS,HLS::HLS_INDEX_MAPPING_OPTIONS HLS_MAPPING>
class RAM_64x8::port<HLS_L,HLS_ACCESS,HLS_MAPPING>::shared_3 :
    public sc_module,
	public cynw_clk_rst_facade
{   
  public:
    typedef RAM_64x8::port<HLS_L,HLS_ACCESS,HLS_MAPPING>           port_type;

    typedef typename port_type::shared_3                  this_type;
   typedef sc_uint<6>                  address_type;
   typedef sc_uint<8>                data_type;
  public:
    SC_HAS_PROCESS(shared_3);
    shared_3( sc_module_name in_name=sc_module_name( sc_gen_unique_name("shared_3") ), unsigned options_in=0)
      : sc_module(in_name)
      , m_port(in_name)
      , m_options(options_in)
    {


        SC_METHOD(mux_inputs);
        sensitive << if1.WE0;
        sensitive << if1.DIN0;
        sensitive << if1.A0;
        sensitive << if1.REQ0;
        sensitive << if2.WE0;
        sensitive << if2.DIN0;
        sensitive << if2.A0;
        sensitive << if2.REQ0;
        sensitive << if3.WE0;
        sensitive << if3.DIN0;
        sensitive << if3.A0;
        sensitive << if3.REQ0;

        SC_METHOD(gen_out_1);
        sensitive << m_port.DOUT0;

        SC_METHOD(gen_out_2);
        sensitive << m_port.DOUT0;

        SC_METHOD(gen_out_3);
        sensitive << m_port.DOUT0;
    }

  public:

    //
    // Interface signals.
    //
    RAM_64x8_ext_signals_1    if1;
    RAM_64x8_ext_signals_1    if2;
    RAM_64x8_ext_signals_1    if3;


    unsigned m_options;

    // 
    // MUX for inputs based on which input is active.
    // Precedence is given to the first port.
    // If neither port is active, the memory inputs are 
    // written to an inactive state.
    //
    void mux_inputs()
    {
        HLS_REMOVE_CONTROL(ON,"");
       if ( (m_options & (HLS::HLS_USING_REG_PORT | HLS::HLS_USING_REG_EX_PORT)) == 0 ) {
            HLS_SET_OUTPUT_DELAY( m_port.WE0, 0.1000 );
            HLS_SET_OUTPUT_DELAY( m_port.DIN0, 0.1000 );
            HLS_SET_OUTPUT_DELAY( m_port.A0, 0.1000 );
            HLS_SET_OUTPUT_DELAY( m_port.REQ0, 0.1000 );
       }
        if (if1.REQ0) {
            m_port.WE0 = if1.WE0;
            m_port.DIN0 = if1.DIN0;
            m_port.A0 = if1.A0;
            m_port.REQ0 = if1.REQ0;
        } else if (if2.REQ0) {
            m_port.WE0 = if2.WE0;
            m_port.DIN0 = if2.DIN0;
            m_port.A0 = if2.A0;
            m_port.REQ0 = if2.REQ0;
        } else if (if3.REQ0) {
            m_port.WE0 = if3.WE0;
            m_port.DIN0 = if3.DIN0;
            m_port.A0 = if3.A0;
            m_port.REQ0 = if3.REQ0;
        } else {
            m_port.WE0 = 1;
            m_port.DIN0 = 0;
            m_port.A0 = 0;
            m_port.REQ0 = 0;

        }
    }


    //
    // Method to transfer memory output to if1
    //
    void gen_out_1()
    {
        if1.DOUT0 = m_port.DOUT0; 
    }
    


    //
    // Method to transfer memory output to if2
    //
    void gen_out_2()
    {
        if2.DOUT0 = m_port.DOUT0; 
    }
    


    //
    // Method to transfer memory output to if3
    //
    void gen_out_3()
    {
        if3.DOUT0 = m_port.DOUT0; 
    }
    


    template <class W>
    void bind( W& iface )
    {
        m_port.WE0(iface.WE0);
        m_port.DIN0(iface.DIN0);
        m_port.DOUT0(iface.DOUT0);
        m_port.A0(iface.A0);
        m_port.REQ0(iface.REQ0);

    }

    template <class W>
    void operator()( W& iface )
    {
      bind(iface);
    }

	port_type m_port;
};
#endif


#if !defined(STRATUS_VLG)
template <typename HLS_L,typename HLS_ACCESS,HLS::HLS_INDEX_MAPPING_OPTIONS HLS_MAPPING>
class RAM_64x8::port<HLS_L,HLS_ACCESS,HLS_MAPPING>::shared_4 :
    public sc_module,
	public cynw_clk_rst_facade
{   
  public:
    typedef RAM_64x8::port<HLS_L,HLS_ACCESS,HLS_MAPPING>           port_type;

    typedef typename port_type::shared_4                  this_type;
   typedef sc_uint<6>                  address_type;
   typedef sc_uint<8>                data_type;
  public:
    SC_HAS_PROCESS(shared_4);
    shared_4( sc_module_name in_name=sc_module_name( sc_gen_unique_name("shared_4") ), unsigned options_in=0)
      : sc_module(in_name)
      , m_port(in_name)
      , m_options(options_in)
    {


        SC_METHOD(mux_inputs);
        sensitive << if1.WE0;
        sensitive << if1.DIN0;
        sensitive << if1.A0;
        sensitive << if1.REQ0;
        sensitive << if2.WE0;
        sensitive << if2.DIN0;
        sensitive << if2.A0;
        sensitive << if2.REQ0;
        sensitive << if3.WE0;
        sensitive << if3.DIN0;
        sensitive << if3.A0;
        sensitive << if3.REQ0;
        sensitive << if4.WE0;
        sensitive << if4.DIN0;
        sensitive << if4.A0;
        sensitive << if4.REQ0;

        SC_METHOD(gen_out_1);
        sensitive << m_port.DOUT0;

        SC_METHOD(gen_out_2);
        sensitive << m_port.DOUT0;

        SC_METHOD(gen_out_3);
        sensitive << m_port.DOUT0;

        SC_METHOD(gen_out_4);
        sensitive << m_port.DOUT0;
    }

  public:

    //
    // Interface signals.
    //
    RAM_64x8_ext_signals_1    if1;
    RAM_64x8_ext_signals_1    if2;
    RAM_64x8_ext_signals_1    if3;
    RAM_64x8_ext_signals_1    if4;


    unsigned m_options;

    // 
    // MUX for inputs based on which input is active.
    // Precedence is given to the first port.
    // If neither port is active, the memory inputs are 
    // written to an inactive state.
    //
    void mux_inputs()
    {
        HLS_REMOVE_CONTROL(ON,"");
       if ( (m_options & (HLS::HLS_USING_REG_PORT | HLS::HLS_USING_REG_EX_PORT)) == 0 ) {
            HLS_SET_OUTPUT_DELAY( m_port.WE0, 0.1000 );
            HLS_SET_OUTPUT_DELAY( m_port.DIN0, 0.1000 );
            HLS_SET_OUTPUT_DELAY( m_port.A0, 0.1000 );
            HLS_SET_OUTPUT_DELAY( m_port.REQ0, 0.1000 );
       }
        if (if1.REQ0) {
            m_port.WE0 = if1.WE0;
            m_port.DIN0 = if1.DIN0;
            m_port.A0 = if1.A0;
            m_port.REQ0 = if1.REQ0;
        } else if (if2.REQ0) {
            m_port.WE0 = if2.WE0;
            m_port.DIN0 = if2.DIN0;
            m_port.A0 = if2.A0;
            m_port.REQ0 = if2.REQ0;
        } else if (if3.REQ0) {
            m_port.WE0 = if3.WE0;
            m_port.DIN0 = if3.DIN0;
            m_port.A0 = if3.A0;
            m_port.REQ0 = if3.REQ0;
        } else if (if4.REQ0) {
            m_port.WE0 = if4.WE0;
            m_port.DIN0 = if4.DIN0;
            m_port.A0 = if4.A0;
            m_port.REQ0 = if4.REQ0;
        } else {
            m_port.WE0 = 1;
            m_port.DIN0 = 0;
            m_port.A0 = 0;
            m_port.REQ0 = 0;

        }
    }


    //
    // Method to transfer memory output to if1
    //
    void gen_out_1()
    {
        if1.DOUT0 = m_port.DOUT0; 
    }
    


    //
    // Method to transfer memory output to if2
    //
    void gen_out_2()
    {
        if2.DOUT0 = m_port.DOUT0; 
    }
    


    //
    // Method to transfer memory output to if3
    //
    void gen_out_3()
    {
        if3.DOUT0 = m_port.DOUT0; 
    }
    


    //
    // Method to transfer memory output to if4
    //
    void gen_out_4()
    {
        if4.DOUT0 = m_port.DOUT0; 
    }
    


    template <class W>
    void bind( W& iface )
    {
        m_port.WE0(iface.WE0);
        m_port.DIN0(iface.DIN0);
        m_port.DOUT0(iface.DOUT0);
        m_port.A0(iface.A0);
        m_port.REQ0(iface.REQ0);

    }

    template <class W>
    void operator()( W& iface )
    {
      bind(iface);
    }

	port_type m_port;
};
#endif


#if !defined(STRATUS_VLG)
//
// Simple memory model containing a SystemC array 
// to represent the memory.
//
class RAM_64x8_untimed_model
  : public sc_module,
    public cynw_memory_if< sc_uint<6>, sc_uint<8> >
{
  public:
    typedef RAM_64x8_untimed_model            this_type;
    typedef sc_uint<6>              address_type;
    typedef sc_uint<8>               data_type;
  public:
    SC_CTOR(RAM_64x8_untimed_model)
    {

        esc_enable_scv_logging();
        m_tx_stream = new cynw_scv_memory_tx_stream< sc_uint<6>, sc_uint<8> >( (std::string("sc_main.") + std::string(this->name())).c_str(), esc_get_scv_tr_db() );
    }

    data_type get( const address_type& address )
    {
        m_tx_stream->gen_read_tx( address.to_uint(), mem[address.to_uint()] );

#if defined(__GNUC__) && defined(BDW_TRACE_MEMS)
        fprintf(stderr,"TRACE: %s: %s: read 0x%s from 0x%x\n", name(), sc_time_stamp().to_string().c_str(), mem[address.to_uint()].to_string(SC_HEX).c_str(), (int)address.to_uint());
#endif
        return mem[address.to_uint()];
}


    void put( const address_type& address, const data_type& data )
    {
        m_tx_stream->gen_write_tx( address.to_uint(), data );

#if defined(__GNUC__) && defined(BDW_TRACE_MEMS)
        fprintf(stderr,"TRACE: %s: %s: write 0x%s to 0x%x\n", name(), sc_time_stamp().to_string().c_str(), data.to_string(SC_HEX).c_str(), (int)address.to_uint());
#endif
        mem[address.to_uint()] = data;
    }


    cynw_scv_memory_tx_stream< sc_uint<6>, sc_uint<8> >* m_tx_stream;

    // 
    // Array containing memory contents
    //
    sc_uint<8> mem[64];
};
#endif


#if !defined(STRATUS_VLG)
//
// TLM metaport.
//
// Select this version by setting the HLS_L template argument to TLM.
//
template <typename HLS_ACCESS,HLS::HLS_INDEX_MAPPING_OPTIONS HLS_MAPPING>
class RAM_64x8::port<CYN::TLM,HLS_ACCESS,HLS_MAPPING>
  : public RAM_64x8::types<CYN::TLM>,
    public cynw_clk_rst_facade,
    public sc_port< cynw_memory_if< sc_uint<6>, sc_uint<8> > >
{
  public:
    HLS_METAPORT;

    typedef RAM_64x8::port< CYN::TLM, HLS_ACCESS,HLS_MAPPING>   this_type;
    typedef cynw_memory_ref< this_type, HLS_ACCESS,HLS_MAPPING > ref_type;
    typedef RAM_64x8::types<CYN::TLM>     types;
    typedef sc_port< cynw_memory_if< sc_uint<6>, sc_uint<8> > > base_type;
    typedef sc_uint<6>                       address_type;
    typedef sc_uint<8>                      data_type;
    typedef unsigned int                          mask_type;
    class shared_2;
    class shared_3;
    class shared_4;

    port( const char* in_name=sc_gen_unique_name("port"), unsigned options_in=0 )
      : base_type(in_name)
    {
       m_tx_stream = 0;
       m_stream_name = (std::string("sc_main.") + std::string(this->name()));

	}

    CYNW_MEM_SQUARE_BRACKETS( ref_type )

    cynw_scv_memory_tx_stream< address_type, data_type >* tx_stream()
    {
#if !STRATUS
      if (m_tx_stream == 0) {
        esc_enable_scv_logging();
        m_tx_stream = new cynw_scv_memory_tx_stream< address_type, data_type >( m_stream_name.c_str(), esc_get_scv_tr_db() );
	  }
      return m_tx_stream;
#else
      return 0;
#endif
    }

  public:

    void nb_get_start( const address_type& address )
	{
		m_val = get(address);
	}

    bool nb_get( data_type& val )
    {

        val = m_val;
		return true;
    }

	sc_event_finder& value_changed()
	{
        return *(new sc_event_finder_t<cynw_memory_if< sc_uint<6>, sc_uint<8> > >(*this));
	}

    data_type get( const address_type& address )  
    {

		data_type data = (*this)->get(address);
        this->tx_stream()->gen_read_tx( address, data );
        return data;
    }

    void put( const address_type& address, const data_type& data )
    {
        this->tx_stream()->gen_write_tx( address, data );
        (*this)->put(address,data);
    }

    void nb_put( const address_type& address, const data_type& data )
    {
        (*this)->put(address,data);
    }
    

	void nb_deassert()
    {
    }

    void reset(  bool control_only=true )
    {
    }

  public:
    data_type m_val;
    cynw_scv_memory_tx_stream< address_type, data_type >* m_tx_stream;
    std::string m_stream_name;
};
#endif



#if !defined(STRATUS_VLG)
//
// TLM export metaport.
//
// Select this version by setting the HLS_L template argument to TLM.
//
template <>
class RAM_64x8::ex_port<CYN::TLM>
  : public RAM_64x8::types<CYN::TLM>,
    public sc_export< cynw_memory_if< sc_uint<6>, sc_uint<8> > >
{
  public:
    typedef RAM_64x8::ex_port< CYN::TLM>   this_type;
    typedef RAM_64x8::types<CYN::TLM>     types;
    typedef sc_export< cynw_memory_if< sc_uint<6>, sc_uint<8> > > base_type;
   typedef sc_uint<6>                       address_type;
   typedef sc_uint<8>                      data_type;

    ex_port( const char* name=0, unsigned options_in=0 )
      : base_type(name)
    {}

  public:

};
#endif


#if !defined(STRATUS_VLG)
//
// TLM registered export metaport.
//
// Select this version by setting the HLS_L template argument to TLM.
//
template <>
class RAM_64x8::reg_ex_port<CYN::TLM>
  : public RAM_64x8::types<CYN::TLM>,
    public sc_export< cynw_memory_if< sc_uint<6>, sc_uint<8> > >,
	public cynw_clk_rst_facade
{
  public:
    typedef RAM_64x8::reg_ex_port< CYN::TLM>   this_type;
    typedef RAM_64x8::types<CYN::TLM>     types;
    typedef sc_export< cynw_memory_if< sc_uint<6>, sc_uint<8> > > base_type;
   typedef sc_uint<6>                       address_type;
   typedef sc_uint<8>                      data_type;

    reg_ex_port( const char* name=0, unsigned options_in=0 )
      : base_type(name)
    {}

  public:
};
#endif


#if !defined(STRATUS_VLG)
//
// TLM metaport with stalling support.
//  
// Select this version by either omitting the HLS_L template argument,
// or by setting it to PIN.
//
template <typename HLS_ACCESS,HLS::HLS_INDEX_MAPPING_OPTIONS HLS_MAPPING>
class RAM_64x8::stall_port<CYN::TLM,HLS_ACCESS,HLS_MAPPING>
  : public RAM_64x8::port<CYN::TLM,HLS_ACCESS,HLS_MAPPING>
{   
  public:
    typedef RAM_64x8::port<CYN::TLM,HLS_ACCESS,HLS_MAPPING>  base_type;
        
    stall_port( const char* name=0, unsigned options_in=0 )
      : base_type(name)
    {   
    }
};
#endif


#if !defined(STRATUS_VLG)
//
// TLM metaport with stalling support.
//  
// Select this version by either omitting the HLS_L template argument,
// or by setting it to PIN.
//
template <typename HLS_ACCESS,HLS::HLS_INDEX_MAPPING_OPTIONS HLS_MAPPING>
class RAM_64x8::reg_port<CYN::TLM,HLS_ACCESS,HLS_MAPPING>
  : public RAM_64x8::port<CYN::TLM,HLS_ACCESS,HLS_MAPPING>
{   
  public:
    typedef RAM_64x8::port<CYN::TLM,HLS_ACCESS,HLS_MAPPING>  base_type;
    typedef RAM_64x8::reg_port<CYN::TLM,HLS_ACCESS,HLS_MAPPING>  this_type;
        
    reg_port( const char* name=0, unsigned options_in=0 )
      : base_type(name), if_inner(*this)
    {   
    }

	this_type& if_inner;
	
};
#endif


#if !defined(STRATUS_VLG)
template <typename HLS_ACCESS,HLS::HLS_INDEX_MAPPING_OPTIONS HLS_MAPPING>
class RAM_64x8::port<CYN::TLM,HLS_ACCESS,HLS_MAPPING>::shared_2 :
    public sc_module,
	public cynw_clk_rst_facade,
    public cynw_memory_if< sc_uint<6>, sc_uint<8> >
{
  public:
    typedef RAM_64x8::port<CYN::TLM,HLS_ACCESS,HLS_MAPPING>           port_type;

    typedef typename port_type::shared_2                  this_type;
   typedef sc_uint<6>                  address_type;
   typedef sc_uint<8>                data_type;
    typedef cynw_memory_if< sc_uint<6>, sc_uint<8> >  if_type;
  public:
    shared_2( sc_module_name in_name=sc_module_name( sc_gen_unique_name("port")), unsigned options_in=0 )
      : sc_module(in_name)
      , if1(*this), if2(*this), m_port(in_name)
    {
    }

    data_type get( const address_type& address )
    {
        return m_port.get(address);
    }

    void put( const address_type& address, const data_type& data )
    {
        m_port.put(address,data);
    }
	
    template <class W>
    void bind( W& iface )
    {
		m_port.bind(iface);
    }

    template <class W>
    void operator()( W& iface )
    {
		m_port.bind(iface);
    }

  public:
    //
    // Interfaces.
    //
    if_type&    if1;
    if_type&    if2;


	port_type	m_port;
};
#endif


#if !defined(STRATUS_VLG)
template <typename HLS_ACCESS,HLS::HLS_INDEX_MAPPING_OPTIONS HLS_MAPPING>
class RAM_64x8::port<CYN::TLM,HLS_ACCESS,HLS_MAPPING>::shared_3 :
    public sc_module,
	public cynw_clk_rst_facade,
    public cynw_memory_if< sc_uint<6>, sc_uint<8> >
{
  public:
    typedef RAM_64x8::port<CYN::TLM,HLS_ACCESS,HLS_MAPPING>           port_type;

    typedef typename port_type::shared_3                  this_type;
   typedef sc_uint<6>                  address_type;
   typedef sc_uint<8>                data_type;
    typedef cynw_memory_if< sc_uint<6>, sc_uint<8> >  if_type;
  public:
    shared_3( sc_module_name in_name=sc_module_name( sc_gen_unique_name("port")), unsigned options_in=0 )
      : sc_module(in_name)
      , if1(*this), if2(*this), if3(*this), m_port(in_name)
    {
    }

    data_type get( const address_type& address )
    {
        return m_port.get(address);
    }

    void put( const address_type& address, const data_type& data )
    {
        m_port.put(address,data);
    }
	
    template <class W>
    void bind( W& iface )
    {
		m_port.bind(iface);
    }

    template <class W>
    void operator()( W& iface )
    {
		m_port.bind(iface);
    }

  public:
    //
    // Interfaces.
    //
    if_type&    if1;
    if_type&    if2;
    if_type&    if3;


	port_type	m_port;
};
#endif


#if !defined(STRATUS_VLG)
template <typename HLS_ACCESS,HLS::HLS_INDEX_MAPPING_OPTIONS HLS_MAPPING>
class RAM_64x8::port<CYN::TLM,HLS_ACCESS,HLS_MAPPING>::shared_4 :
    public sc_module,
	public cynw_clk_rst_facade,
    public cynw_memory_if< sc_uint<6>, sc_uint<8> >
{
  public:
    typedef RAM_64x8::port<CYN::TLM,HLS_ACCESS,HLS_MAPPING>           port_type;

    typedef typename port_type::shared_4                  this_type;
   typedef sc_uint<6>                  address_type;
   typedef sc_uint<8>                data_type;
    typedef cynw_memory_if< sc_uint<6>, sc_uint<8> >  if_type;
  public:
    shared_4( sc_module_name in_name=sc_module_name( sc_gen_unique_name("port")), unsigned options_in=0 )
      : sc_module(in_name)
      , if1(*this), if2(*this), if3(*this), if4(*this), m_port(in_name)
    {
    }

    data_type get( const address_type& address )
    {
        return m_port.get(address);
    }

    void put( const address_type& address, const data_type& data )
    {
        m_port.put(address,data);
    }
	
    template <class W>
    void bind( W& iface )
    {
		m_port.bind(iface);
    }

    template <class W>
    void operator()( W& iface )
    {
		m_port.bind(iface);
    }

  public:
    //
    // Interfaces.
    //
    if_type&    if1;
    if_type&    if2;
    if_type&    if3;
    if_type&    if4;


	port_type	m_port;
};
#endif


#if !defined(STRATUS_VLG) && !defined(STRATUS_HLS)

//
// Simple external memory wrapper.
//
// TLM version.
// Select this version by setting the HLS_L template argument to TLM.
// 
template <>
class RAM_64x8::wrapper<CYN::TLM> :
    public sc_module,
    public RAM_64x8::types<CYN::TLM>,
    public cynw_memory_if< sc_uint<6>, sc_uint<8> >
{
  public:
    typedef RAM_64x8::wrapper<CYN::TLM>				this_type;
    typedef sc_uint<6>						    address_type;
    typedef sc_uint<8>						    data_type;
    typedef cynw_memory_if< address_type, data_type >   if_type;
  public:
    SC_HAS_PROCESS(wrapper);
    wrapper( sc_module_name in_name=sc_module_name( sc_gen_unique_name("RAM_64x8")) )
	  : sc_module(in_name)
      ,CLK("CLK") 

      , model(basename()) 
	{
	}
    template <class T0,class T1>
    void clk_rst( T0 & CLK_in, T1 & rst_in, bool rah=false )
    {
        CLK(CLK_in);
    }
    template <class T0,class T1>
    void clk_rst_sync( T0 & CLK_in, T1 & rst_in, bool rah=false )
    {
        CLK(CLK_in);
    }
    template <class T0,class T1>
    void clk_rst_async( T0 & CLK_in, T1 & rst_in, bool rah=false )
    {
        CLK(CLK_in);
    }
    template <class T0>
    void clk_rst( T0 & CLK_in )
    {
        CLK(CLK_in);
    }

    data_type get( const address_type& address )
    {
        return model.get(address);
    }

    void put( const address_type& address, const data_type& data )
    {
        model.put(address,data);
    }
  public:
    //
    // Ports.
    //
    sc_in_clk CLK;


    // 
    // The memory model.
    //
    RAM_64x8_untimed_model model;
};


#if !defined(STRATUS_VLG)
template <>
class RAM_64x8::shared_2<CYN::TLM> :
    public sc_module,
    public RAM_64x8::types<CYN::TLM>,
    public cynw_memory_if< sc_uint<6>, sc_uint<8> >
{
  public:
    typedef RAM_64x8::shared_2<CYN::TLM>           this_type;
    typedef sc_uint<6>                  address_type;
    typedef sc_uint<8>                   data_type;
    typedef cynw_memory_if< sc_uint<6>, sc_uint<8> >  if_type;
  public:
    SC_HAS_PROCESS(shared_2);
    shared_2( sc_module_name in_name=sc_module_name( sc_gen_unique_name("RAM_64x8")) )
      : sc_module(in_name) 
      ,CLK("CLK")
      , if1(*this), if2(*this), model(basename())
    {
    }
    template <class T0,class T1>
    void clk_rst( T0 & CLK_in, T1 & rst_in, bool rah=false )
    {
        CLK(CLK_in);
    }
    template <class T0,class T1>
    void clk_rst_sync( T0 & CLK_in, T1 & rst_in, bool rah=false )
    {
        CLK(CLK_in);
    }
    template <class T0,class T1>
    void clk_rst_async( T0 & CLK_in, T1 & rst_in, bool rah=false )
    {
        CLK(CLK_in);
    }
    template <class T0>
    void clk_rst( T0 & CLK_in )
    {
        CLK(CLK_in);
    }

    data_type get( const address_type& address )
    {
        return model.get(address);
    }

    void put( const address_type& address, const data_type& data )
    {
        model.put(address,data);
    }
  public:
    //
    // Ports.
    //
    sc_in_clk CLK;



    //
    // Interfaces.
    //
    if_type&    if1;
    if_type&    if2;

    // 
    // The memory model.
    //
    RAM_64x8_untimed_model model;

  public:
};
#endif


#if !defined(STRATUS_VLG)
template <>
class RAM_64x8::shared_3<CYN::TLM> :
    public sc_module,
    public RAM_64x8::types<CYN::TLM>,
    public cynw_memory_if< sc_uint<6>, sc_uint<8> >
{
  public:
    typedef RAM_64x8::shared_3<CYN::TLM>           this_type;
    typedef sc_uint<6>                  address_type;
    typedef sc_uint<8>                   data_type;
    typedef cynw_memory_if< sc_uint<6>, sc_uint<8> >  if_type;
  public:
    SC_HAS_PROCESS(shared_3);
    shared_3( sc_module_name in_name=sc_module_name( sc_gen_unique_name("RAM_64x8")) )
      : sc_module(in_name) 
      ,CLK("CLK")
      , if1(*this), if2(*this), if3(*this), model(basename())
    {
    }
    template <class T0,class T1>
    void clk_rst( T0 & CLK_in, T1 & rst_in, bool rah=false )
    {
        CLK(CLK_in);
    }
    template <class T0,class T1>
    void clk_rst_sync( T0 & CLK_in, T1 & rst_in, bool rah=false )
    {
        CLK(CLK_in);
    }
    template <class T0,class T1>
    void clk_rst_async( T0 & CLK_in, T1 & rst_in, bool rah=false )
    {
        CLK(CLK_in);
    }
    template <class T0>
    void clk_rst( T0 & CLK_in )
    {
        CLK(CLK_in);
    }

    data_type get( const address_type& address )
    {
        return model.get(address);
    }

    void put( const address_type& address, const data_type& data )
    {
        model.put(address,data);
    }
  public:
    //
    // Ports.
    //
    sc_in_clk CLK;



    //
    // Interfaces.
    //
    if_type&    if1;
    if_type&    if2;
    if_type&    if3;

    // 
    // The memory model.
    //
    RAM_64x8_untimed_model model;

  public:
};
#endif


#if !defined(STRATUS_VLG)
template <>
class RAM_64x8::shared_4<CYN::TLM> :
    public sc_module,
    public RAM_64x8::types<CYN::TLM>,
    public cynw_memory_if< sc_uint<6>, sc_uint<8> >
{
  public:
    typedef RAM_64x8::shared_4<CYN::TLM>           this_type;
    typedef sc_uint<6>                  address_type;
    typedef sc_uint<8>                   data_type;
    typedef cynw_memory_if< sc_uint<6>, sc_uint<8> >  if_type;
  public:
    SC_HAS_PROCESS(shared_4);
    shared_4( sc_module_name in_name=sc_module_name( sc_gen_unique_name("RAM_64x8")) )
      : sc_module(in_name) 
      ,CLK("CLK")
      , if1(*this), if2(*this), if3(*this), if4(*this), model(basename())
    {
    }
    template <class T0,class T1>
    void clk_rst( T0 & CLK_in, T1 & rst_in, bool rah=false )
    {
        CLK(CLK_in);
    }
    template <class T0,class T1>
    void clk_rst_sync( T0 & CLK_in, T1 & rst_in, bool rah=false )
    {
        CLK(CLK_in);
    }
    template <class T0,class T1>
    void clk_rst_async( T0 & CLK_in, T1 & rst_in, bool rah=false )
    {
        CLK(CLK_in);
    }
    template <class T0>
    void clk_rst( T0 & CLK_in )
    {
        CLK(CLK_in);
    }

    data_type get( const address_type& address )
    {
        return model.get(address);
    }

    void put( const address_type& address, const data_type& data )
    {
        model.put(address,data);
    }
  public:
    //
    // Ports.
    //
    sc_in_clk CLK;



    //
    // Interfaces.
    //
    if_type&    if1;
    if_type&    if2;
    if_type&    if3;
    if_type&    if4;

    // 
    // The memory model.
    //
    RAM_64x8_untimed_model model;

  public:
};
#endif

#endif // STRATUS_VLG
#endif // RAM_64x8_H

