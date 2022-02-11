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

#ifndef stream_16X8_H
#define stream_16X8_H

#include <systemc.h>
#include <cynthhl.h>
#include <cynw_comm_util.h>
#include <string>
#include <tlm.h>
#include <esc.h>
#if BDW_USE_SCV
#include <scv.h>
#endif

using namespace cynw;

#if defined STRATUS  &&  ! defined CYN_DONT_SUPPRESS_MSGS
#pragma hls_suppress_msgs NOTE
#pragma hls_ip_def
#endif	// STRATUS  &&  CYN_DONT_SUPPRESS_MSGS

struct stream_16X8
{
  template <typename HLS_L=CYN::PIN> class chan;
  template <typename HLS_L=CYN::PIN> class direct;
  template <typename HLS_L=CYN::PIN> class in;
  template <typename HLS_L=CYN::PIN> class out;
  template <typename HLS_L=CYN::PIN> class base_in;
  template <typename HLS_L=CYN::PIN> class base_out;

  class base_in_pin;
  class base_in_tlm;
  class base_out_pin;
  class base_out_tlm;

  enum { 
      w_II=1, 
      r_II=2,
      writer_II=1, 
      reader_II=2
  };

#if ! defined(STRATUS_HLS)
  
  struct in_param_t {
      sc_uint<8> P1[16];
      in_param_t()
      {}
  
      in_param_t( sc_uint<8> (&in_param)[16]) {
          sc_uint<5> i;
  
  
          i = 0ULL;
          while ( (sc_uint<1>) (i < 16ULL) ) {
            (P1)[i] = (in_param)[i];
            i = (i + 1ULL);
          }
      }
      void get( sc_uint<8> (&in_param)[16]) {
          sc_uint<5> i_0;
  
  
          i_0 = 0ULL;
          while ( (sc_uint<1>) (i_0 < 16ULL) ) {
            (in_param)[i_0] = (P1)[i_0];
            i_0 = (i_0 + 1ULL);
          }
      }
  
      void reset_io() {}
  };
  typedef in_param_t* tlm_io_t;
#endif
  


}; // struct stream_16X8


#if ! defined(STRATUS_HLS)
inline std::ostream& operator << ( std::ostream& os, const stream_16X8::in_param_t&  x)
{ return os; }

#endif



template <typename HLS_L>
class stream_16X8::chan
  : public sc_module
  , public cynw_clk_rst
{
  public:
    SC_HAS_PROCESS(chan);

    chan( sc_module_name name =
              sc_module_name( sc_gen_unique_name("stream_16X8_chan") ) )
      : sc_module(name)
	      {
      SC_METHOD(gen_r_vld);
        sensitive << ( fifo_dsel );
        sensitive << ( w_vld );
      
        SC_METHOD(gen_in_busy);
        sensitive << ( fifo_dsel );
        sensitive << ( r_busy );
      
        SC_METHOD(gen_fifo_addr);
        sensitive << clk.pos();
        dont_initialize();
      
        SC_METHOD(gen_fifo_out);
        sensitive << ( fifo_dsel );
        sensitive << ( P1_1 );
        sensitive << ( P1_0 );
        sensitive << ( w_data );
      
        SC_METHOD(gen_fifo_data);
        sensitive << clk.pos();
        dont_initialize();
      
      HLS_SUPPRESS_MSG_SYM(1435ULL, w_data);
      HLS_SUPPRESS_MSG_SYM(1433ULL, w_data);
      HLS_SUPPRESS_MSG_SYM(1435ULL, r_data);
      HLS_SUPPRESS_MSG_SYM(1433ULL, r_data);

    }
	
    
    void gen_r_vld(){
      r_vld = (sc_uint<1> ) ((w_vld.read()||(fifo_dsel.read() != 0ULL)));
    }
    void gen_in_busy(){
      w_busy = (sc_uint<1> ) ((r_busy.read() && (fifo_dsel.read() == 2ULL)));
    }
    void gen_fifo_addr(){
      if ( rst_active() ) {
        HLS_DEFINE_PROTOCOL("hls_reset_block");
        HLS_REMOVE_CONTROL(OFF,"stream_16X8");
        fifo_dsel = 0ULL;
      } else {
        {
          HLS_DPOPT_REGION(0ULL, "gen_fifo_addr");
          if ( (w_vld.read() && (r_busy.read() && (fifo_dsel.read() != 2ULL))) ) {
            fifo_dsel = (fifo_dsel.read() + 1ULL);
          } else {
            if ( (!w_vld.read() && (!r_busy.read() && (fifo_dsel.read() != 0ULL))) )
             {
              fifo_dsel = fifo_dsel.read() - 1ULL;
            } 
          }
        }
      }
    }
    void gen_fifo_out(){
      switch( (sc_uint<2>)(fifo_dsel.read()) ) {
      case 2ULL: 
        r_data = P1_1.read();
        break;
      case 1ULL: 
        r_data = P1_0.read();
        break;
      default:
        r_data = w_data.read();
        break;
      }
    }
    void gen_fifo_data(){
      rst_active();
      {
        HLS_DPOPT_REGION(2ULL, "gen_fifo_data");
        if ( (w_vld.read() && ( ((fifo_dsel.read() != 2ULL)||!r_busy.read()) )) ) {
          P1_1 = P1_0.read();
          P1_0 = w_data.read();
        } 
      }
    }


    sc_signal< sc_uint<32> > r_data;
    sc_signal< sc_uint<32> > w_data;
    sc_signal< sc_uint<32> > P1_0;
    sc_signal< sc_uint<32> > P1_1;
    sc_signal< bool > r_busy;
    sc_signal< bool > w_vld;
    sc_signal< bool > w_busy;
    sc_signal< bool > r_vld;
    sc_signal< sc_uint<2> > fifo_dsel;


};


template <typename HLS_L>
class stream_16X8::direct
  : public sc_module
  , public cynw_clk_rst
{
  public:
    SC_HAS_PROCESS(direct);
    
    typedef CYN::PIN  p2p_level;

    direct( sc_module_name name=sc_module_name( sc_gen_unique_name("stream_16X8_direct") ) )
      : sc_module(name)
      , r_data("r_data")
      , w_data("w_data")
      , P1_0("P1_0")
      , P1_1("P1_1")
      , trig_req("trig_req")
      , prev_trig_req("prev_trig_req")
      , next_trig_req("next_trig_req")
      , m_unacked_req("m_unacked_req")
      , m_write_stalling("m_write_stalling")
      , m_busy_req("m_busy_req")
      , m_data_is_valid("m_data_is_valid")
      , m_data_is_invalid("m_data_is_invalid")
      , m_read_stalling("m_read_stalling")
      , m_read_stall_context("m_read_stall_context")
      , m_write_stall_context("m_write_stall_context")
      , r_busy("r_busy")
      , w_vld("w_vld")
      , w_busy("w_busy")
      , r_vld("r_vld")
      , fifo_dsel("fifo_dsel")

      , m_max_delay(HLS_CALC_TIMING)
      ,  m_dpopt_opts(DPOPT_DISABLE)
      , m_w_tx_stream(0), m_w_ws_tx_stream(0), m_r_tx_stream(0), m_r_ws_tx_stream(0)
      , m_stream_name(std::string("sc_main.") + std::string(this->name()))
      , m_msg_events(0)
    {
      SC_METHOD(write_sync);
        sensitive << clk.pos();
        dont_initialize();
      
        SC_METHOD(gen_vld);
        sensitive << ( prev_trig_req );
        sensitive << ( trig_req );
        sensitive << ( m_unacked_req );
      
        SC_METHOD(gen_out_stalling);
        sensitive << ( w_vld );
        sensitive << ( w_busy );
      
        SC_METHOD(gen_dv);
        sensitive << ( r_busy );
        sensitive << ( r_vld );
      
        SC_METHOD(gen_busy);
        sensitive << ( m_busy_req );
        sensitive << ( m_read_stalling );
      
        SC_METHOD(save_trig);
        sensitive << clk.pos();
        dont_initialize();
      
        SC_METHOD(gen_next_trig);
        sensitive << ( trig_req );
      
        SC_METHOD(gen_r_vld_0);
        sensitive << ( fifo_dsel );
        sensitive << ( w_vld );
      
        SC_METHOD(gen_in_busy_0);
        sensitive << ( fifo_dsel );
        sensitive << ( r_busy );
      
        SC_METHOD(gen_fifo_addr_0);
        sensitive << clk.pos();
        dont_initialize();
      
        SC_METHOD(gen_fifo_out_0);
        sensitive << ( fifo_dsel );
        sensitive << ( P1_1 );
        sensitive << ( P1_0 );
        sensitive << ( w_data );
      
        SC_METHOD(gen_fifo_data_0);
        sensitive << clk.pos();
        dont_initialize();
      
      HLS_FLATTEN_ARRAY(write_ws);
      HLS_FLATTEN_ARRAY(read_ws);
      HLS_SUPPRESS_MSG_SYM(513ULL, m_busy_req);
      HLS_SUPPRESS_MSG_SYM(938ULL, read_ws);
      HLS_SUPPRESS_MSG_SYM(2934ULL, read_ws);
      HLS_SUPPRESS_MSG_SYM(2588ULL, read_ws);
      HLS_SUPPRESS_MSG_SYM(1435ULL, w_data);
      HLS_SUPPRESS_MSG_SYM(1433ULL, w_data);
      HLS_SUPPRESS_MSG_SYM(1435ULL, r_data);
      HLS_SUPPRESS_MSG_SYM(1433ULL, r_data);
      HLS_SET_IS_BOUNDED(m_max_delay, "");
      HLS_SET_IS_BOUNDED(m_dpopt_opts, "");

    }

    sc_signal< sc_uint<32> > r_data;
    sc_signal< sc_uint<32> > w_data;
    sc_signal< sc_uint<32> > P1_0;
    sc_signal< sc_uint<32> > P1_1;
    sc_uint<8> read_ws[8];
    sc_uint<8> write_ws[4];
    sc_uint<32> data_tmp;
    sc_signal< sc_uint<1> > trig_req;
    sc_signal< sc_uint<1> > prev_trig_req;
    sc_signal< sc_uint<1> > next_trig_req;
    sc_signal< sc_uint<1> > m_unacked_req;
    sc_signal< sc_uint<1> > m_write_stalling;
    sc_signal< sc_uint<1> > m_busy_req;
    sc_signal< sc_uint<1> > m_data_is_valid;
    sc_signal< sc_uint<1> > m_data_is_invalid;
    sc_signal< sc_uint<1> > m_read_stalling;
    sc_signal< sc_uint<1> > m_read_stall_context;
    sc_signal< sc_uint<1> > m_write_stall_context;
    sc_signal< bool > r_busy;
    sc_signal< bool > w_vld;
    sc_signal< bool > w_busy;
    sc_signal< bool > r_vld;
    sc_signal< sc_uint<2> > fifo_dsel;
    sc_uint<1> m_write_valid_tx;
    sc_uint<1> m_read_valid_tx;
    sc_uint<1> m_data_was_valid;
    sc_uint<5> m_r_x;
    sc_uint<5> m_w_x;
    sc_int<5> refl_index;
    double m_max_delay;
    unsigned int m_dpopt_opts;
    sc_uint<1> m_ws_data_was_valid;


    sc_uint<1> new_vld;
    
    void write_sync(){
      if ( rst_active() ) {
        HLS_DEFINE_PROTOCOL("hls_reset_block_0");
        HLS_REMOVE_CONTROL(OFF,"stream_16X8_0");
        m_unacked_req = 0ULL;
      } else {
        m_unacked_req = m_write_stalling.read();
      }
    }
    void gen_vld(){
      {
        HLS_DPOPT_REGION(2ULL, "gen_vld");
        w_vld = (sc_uint<1> ) ((m_unacked_req.read()||trig_req.read() ^ 
                prev_trig_req.read()));
      }
    }
    void gen_out_stalling(){
      m_write_stalling = (w_busy.read() && w_vld.read());
    }
    void gen_dv(){
      {
        HLS_DPOPT_REGION(2ULL, "gen_dv");
        new_vld = (r_vld.read() && !r_busy.read());
        m_data_is_valid = new_vld;
        m_data_is_invalid = !new_vld;
      }
    }
    void gen_busy(){
      if ( (m_busy_req.read() == 0ULL) ) {
        r_busy = (sc_uint<1> ) (m_read_stalling.read());
      } else {
        r_busy = (sc_uint<1> ) (1ULL);
      }
    }
    void save_trig(){
      if ( rst_active() ) {
        HLS_DEFINE_PROTOCOL("hls_reset_block_1");
        HLS_REMOVE_CONTROL(OFF,"stream_16X8_1");
        prev_trig_req = 0ULL;
      } else {
        prev_trig_req = trig_req.read();
      }
    }
    void gen_next_trig(){
      next_trig_req = !trig_req.read();
    }
    void gen_r_vld_0(){
      r_vld = (sc_uint<1> ) ((w_vld.read()||(fifo_dsel.read() != 0ULL)));
    }
    void gen_in_busy_0(){
      w_busy = (sc_uint<1> ) ((r_busy.read() && (fifo_dsel.read() == 2ULL)));
    }
    void gen_fifo_addr_0(){
      if ( rst_active() ) {
        HLS_DEFINE_PROTOCOL("hls_reset_block_2");
        HLS_REMOVE_CONTROL(OFF,"stream_16X8_2");
        fifo_dsel = 0ULL;
      } else {
        {
          HLS_DPOPT_REGION(0ULL, "gen_fifo_addr_0");
          if ( (w_vld.read() && (r_busy.read() && (fifo_dsel.read() != 2ULL))) ) {
            fifo_dsel = (fifo_dsel.read() + 1ULL);
          } else {
            if ( (!w_vld.read() && (!r_busy.read() && (fifo_dsel.read() != 0ULL))) )
             {
              fifo_dsel = fifo_dsel.read() - 1ULL;
            } 
          }
        }
      }
    }
    void gen_fifo_out_0(){
      switch( (sc_uint<2>)(fifo_dsel.read()) ) {
      case 2ULL: 
        r_data = P1_1.read();
        break;
      case 1ULL: 
        r_data = P1_0.read();
        break;
      default:
        r_data = w_data.read();
        break;
      }
    }
    void gen_fifo_data_0(){
      rst_active();
      {
        HLS_DPOPT_REGION(2ULL, "gen_fifo_data_0");
        if ( (w_vld.read() && ( ((fifo_dsel.read() != 2ULL)||!r_busy.read()) )) ) {
          P1_1 = P1_0.read();
          P1_0 = w_data.read();
        } 
      }
    }


    sc_uint<5> r_x() const {
        return m_r_x;
    }
    
    sc_uint<5> r_x_new() const {
        return m_r_x ;
    }
    
    sc_uint<1> r_x_done() const {
        return (m_r_x == 2ULL);
    }
    
    sc_uint<1> r_done() const {
        return (m_r_x == 2ULL);
    }
    
    sc_uint<5> w_x() const {
        return m_w_x;
    }
    
    sc_uint<1> w_x_done() const {
        return (m_w_x == 4ULL);
    }
    
    sc_uint<1> w_done() const {
        return (m_w_x == 4ULL);
    }
    
    void r_set_size( int new_xsz=0 ) {
#ifndef STRATUS
      esc_report_error( esc_warning, "\n\t%s: set_size() called for an interface that does not have the Variable Limits option set.", sc_module::name() );
#endif
    }void w_set_size( int new_xsz=0 ) {
#ifndef STRATUS
      esc_report_error( esc_warning, "\n\t%s: set_size() called for an interface that does not have the Variable Limits option set.", sc_module::name() );
#endif
    }


    

    

    void start_of_simulation()
    {
      esc_trace(r_data);
      esc_trace(w_data);
      esc_trace(r_busy);
      esc_trace(w_vld);
      esc_trace(w_busy);
      esc_trace(r_vld);

    }

    void w_reset()
    { 
	msg_event_occurred(msg_w_reset_done);
	
	m_write_valid_tx = 1ULL;
	{
	  HLS_DEFINE_PROTOCOL("write_reset");
	  trig_req = 0ULL;
	}

	HLS_SUPPRESS_MSG_SYM( 408, *this );
    }
    void writer_reset()
    { 
      w_reset();
    }

    void w_start_tx( sc_uint<1> valid_tx=true )
    {
	writer_set_data_is_valid( valid_tx );
	

	w_tx_stream()->begin_tx();

	
	m_w_x = 0ULL;
	(write_ws)[0LL] = 0ULL;
	(write_ws)[1LL] = 0ULL;
	(write_ws)[2LL] = 0ULL;
	(write_ws)[3LL] = 0ULL;

    }
    void writer_start_tx( sc_uint<1> valid_tx=true )
    {
      w_start_tx( valid_tx);
    }

    void w_end_tx()
    {
	

	w_tx_stream()->end_tx();

    }
    void writer_end_tx()
    {
       w_end_tx();
    }

    void r_reset()
    {
	msg_event_occurred(msg_r_reset_done);
	
	m_read_valid_tx = 1ULL;
	{
	  HLS_DEFINE_PROTOCOL("read_reset");
	  m_busy_req = 1ULL;
	  m_read_stalling = 0ULL;
	}
	HLS_SET_STALL_VALUE(m_read_stalling, 1ULL, 1ULL, &m_read_stall_context, &
	m_busy_req);
	HLS_SET_OUTPUT_OPTIONS(m_read_stalling, ASYNC_NO_HOLD);
	HLS_SET_OUTPUT_DELAY(m_read_stalling, HLS_CLOCK_PERIOD - HLS_FU_CLOCK_PERIOD * 
	0.500000);

	HLS_SUPPRESS_MSG_SYM( 408, *this );
    }
    void reader_reset()
    {
       r_reset();
    }

    bool r_start_tx( sc_uint<1> valid_tx=true )
    {
        

	r_set_data_is_valid( valid_tx );
	r_tx_stream()->begin_tx();

	
	m_r_x = 0ULL;
	(read_ws)[0LL] = 0ULL;
	(read_ws)[1LL] = 0ULL;
	(read_ws)[2LL] = 0ULL;
	(read_ws)[3LL] = 0ULL;
	(read_ws)[4LL] = 0ULL;
	(read_ws)[5LL] = 0ULL;
	(read_ws)[6LL] = 0ULL;
	(read_ws)[7LL] = 0ULL;
	HLS_REMOVE_CONTROL("stream_16X8_3");

	return r_data_is_valid();
    }
    bool reader_start_tx( sc_uint<1> valid_tx=true )
    {
      return r_start_tx( valid_tx );
    }

    void r_end_tx()
    {
	r_tx_stream()->end_tx();

	

    }
    void reader_end_tx()
    {
       r_end_tx();
    }

    bool w_data_is_valid()
    {
      return m_write_valid_tx;
    }
    bool writer_data_is_valid()
    {
      return  w_data_is_valid();
    }

    void w_set_data_is_valid( sc_uint<1> valid_tx )
    {
      m_write_valid_tx = valid_tx;;
    }
    void writer_set_data_is_valid( sc_uint<1> valid_tx )
    {
       w_set_data_is_valid( valid_tx );
    }

    bool r_data_is_valid()
    {
      return m_read_valid_tx;
    }
    bool reader_data_is_valid()
    {
      return r_data_is_valid();
    }

    void r_set_data_is_valid( sc_uint<1> valid_tx )
    {
            m_read_valid_tx = valid_tx;;
    }
    void reader_set_data_is_valid( sc_uint<1> valid_tx )
    {
       r_set_data_is_valid( valid_tx );
    }

    sc_uint<1> read_write( sc_uint<8> new_value, 
                           sc_uint<8> (&in_ws)[8],
                           unsigned int actions =CYNIF_DO_WRITE | CYNIF_DO_ADVANCE | CYNIF_DO_READ )
    {
            #if ! defined(STRATUS_HLS)
	  esc_report_error( esc_warning, "\n\t%s: read_write() not supported for this interface.\n", name() );
	return false;
	#endif
    }

    sc_uint<1> read( sc_uint<8> new_value, 
                       sc_uint<8> (&in_ws)[8],
		       bool advance=false )
    {
      return read_write( new_value, 
                         in_ws,
			 CYNIF_DO_READ | (advance ? CYNIF_DO_ADVANCE : 0) );
    }

    sc_uint<1> write( sc_uint<8> new_value,
                      bool advance=true )
    {
      sc_uint<8> in_ws[8];

      return read_write( new_value, 
                         in_ws,
			 CYNIF_DO_WRITE | (advance ? CYNIF_DO_ADVANCE : 0));
    }

    sc_uint<1> advance()
    {
      sc_uint<8> new_value;

      sc_uint<8> in_ws[8];

      HLS_FLATTEN_ARRAY(in_ws);

      return read_write( new_value, 
                         in_ws,
			 CYNIF_DO_ADVANCE );
    }

    sc_uint<1> poll( sc_uint<8> (&in_ws)[8] )
    {
	msg_event_check(msg_r_reset_done);
#ifndef STRATUS
	if ( r_x_done() ) {
	    esc_report_error( esc_warning, "\n\t%s: poll() called for more than %d accesses for channel 'stream_16X8'\n", sc_module::name(), 2 );
	}
#endif
	m_check_get_before_next &= ~1;
	r_ws_tx_stream()->begin_tx();
	r_ws_tx_stream()->record_attrib("X", (int)r_x());
	sc_uint<2> i_1;
	
	HLS_REMOVE_CONTROL("stream_16X8_4");
	i_1 = 0ULL;
	while ( (sc_uint<1>) (i_1 < 2ULL) ) {
	  HLS_UNROLL_LOOP(ON,"tmp");
	  {
	    HLS_DEFINE_PROTOCOL("read_start_iter");
	    m_busy_req = !m_read_valid_tx;
	    wait( 1LL );
	    m_data_was_valid = m_data_is_valid.read() & m_read_valid_tx;
	    m_busy_req = 1ULL;
	    data_tmp = r_data.read();
	  }
	  (read_ws)[0LL] = (read_ws)[4LL];
	  (read_ws)[1LL] = (read_ws)[5LL];
	  (read_ws)[2LL] = (read_ws)[6LL];
	  (read_ws)[3LL] = (read_ws)[7LL];
	  (read_ws)[4LL] = data_tmp.range(31,24);
	  (read_ws)[5LL] = data_tmp.range(23,16);
	  (read_ws)[6LL] = data_tmp.range(15,8);
	  (read_ws)[7LL] = data_tmp;
	  i_1 = (i_1 + 1ULL);
	}
	m_r_x = (m_r_x + 1ULL);
	(in_ws)[7LL] = (read_ws)[7LL];
	(in_ws)[6LL] = (read_ws)[6LL];
	(in_ws)[5LL] = (read_ws)[5LL];
	(in_ws)[4LL] = (read_ws)[4LL];
	(in_ws)[3LL] = (read_ws)[3LL];
	(in_ws)[2LL] = (read_ws)[2LL];
	(in_ws)[1LL] = (read_ws)[1LL];
	(in_ws)[0LL] = (read_ws)[0LL];
	r_ws_tx_stream()->record_attrib("P1", in_ws);
	r_ws_tx_stream()->end_tx();

	return m_ws_data_was_valid;
    }

    void get( sc_uint<8> (&in_ws)[8] )
    {
	msg_event_check(msg_r_reset_done);
#ifndef STRATUS
	if ( r_x_done() ) {
	    esc_report_error( esc_warning, "\n\t%s: get() called for more than %d accesses for channel 'stream_16X8'\n", sc_module::name(), 2 );
	}
#endif
	m_check_get_before_next &= ~1;
	r_ws_tx_stream()->begin_tx();
	r_ws_tx_stream()->record_attrib("X", (int)r_x());
	sc_uint<2> i_2;
	
	HLS_REMOVE_CONTROL("stream_16X8_5");
	i_2 = 0ULL;
	while ( (sc_uint<1>) (i_2 < 2ULL) ) {
	  HLS_UNROLL_LOOP(ON,"tmp_0");
	  {
	    HLS_DEFINE_PROTOCOL("read_start_iter_1");
	    m_busy_req = !m_read_valid_tx;
	    do {
	     HLS_DEFINE_STALL_LOOP(ALL,"get_0", &m_read_stall_context);
	     HLS_DEFINE_PROTOCOL("read_start_iter_0");
	     wait( 1LL );
	    } while ( m_data_is_invalid.read() & m_read_valid_tx );
	    m_busy_req = 1ULL;
	    m_data_was_valid = m_read_valid_tx;
	    data_tmp = r_data.read();
	  }
	  (read_ws)[0LL] = (read_ws)[4LL];
	  (read_ws)[1LL] = (read_ws)[5LL];
	  (read_ws)[2LL] = (read_ws)[6LL];
	  (read_ws)[3LL] = (read_ws)[7LL];
	  (read_ws)[4LL] = data_tmp.range(31,24);
	  (read_ws)[5LL] = data_tmp.range(23,16);
	  (read_ws)[6LL] = data_tmp.range(15,8);
	  (read_ws)[7LL] = data_tmp;
	  i_2 = (i_2 + 1ULL);
	}
	m_r_x = (m_r_x + 1ULL);
	(in_ws)[7LL] = (read_ws)[7LL];
	(in_ws)[6LL] = (read_ws)[6LL];
	(in_ws)[5LL] = (read_ws)[5LL];
	(in_ws)[4LL] = (read_ws)[4LL];
	(in_ws)[3LL] = (read_ws)[3LL];
	(in_ws)[2LL] = (read_ws)[2LL];
	(in_ws)[1LL] = (read_ws)[1LL];
	(in_ws)[0LL] = (read_ws)[0LL];
	r_ws_tx_stream()->record_attrib("P1", in_ws);
	r_ws_tx_stream()->end_tx();

    }

        
    sc_uint<1> m_mt_err_issued;
    void need_mt_error()
    {
      #if STRATUS
      HLS_MESSAGE(2891);
      #else
      if (!m_mt_err_issued)
        esc_report_error( esc_error, "\n\tstream_16X8: Must set the Multi Threaded option to use the non-blocking API"  );
      m_mt_err_issued = 1;
      #endif
    }
    
    bool data_was_valid()
    {
        need_mt_error();
        return false;
    }
    
    bool nb_can_get()
    {
        need_mt_error();
        return false;
    }
    
    void get_start( bool busy_val=false )
    {
        need_mt_error();
    }
    
    void get_end()
    {
        need_mt_error();
    }
    
    bool nb_get( sc_uint<8> (&in_ws)[8] )
    {
        need_mt_error();
        return false;
    }
    
    void latch_value( sc_uint<1> valid_tx=true )
    {
        need_mt_error();
    }
    
    void set_state( unsigned which, unsigned value )
    {
        need_mt_error();
    }

    void enable_dpopt( double md=HLS_CALC_TIMING )
    {
	 m_max_delay = md;
	 m_dpopt_opts = 0;
    }

    void put( sc_uint<8> (&out_ws)[4] )
    {
	msg_event_check(msg_w_reset_done);
#ifndef STRATUS
	if ( w_x_done() ) {
	    esc_report_error( esc_warning, "\n\t%s: put() called for more than %d accesses for channel 'stream_16X8'\n", sc_module::name(), 4 );
	}
#endif
	w_ws_tx_stream()->begin_tx();
	w_ws_tx_stream()->record_attrib("X", (int)w_x());
	w_ws_tx_stream()->record_attrib("P1", out_ws);
	
	(write_ws)[3LL] = (out_ws)[3LL];
	(write_ws)[2LL] = (out_ws)[2LL];
	(write_ws)[1LL] = (out_ws)[1LL];
	(write_ws)[0LL] = (out_ws)[0LL];
	HLS_COALESCE_LOOP(CONSERVATIVE,"stream_16X8_6");
	HLS_DEFINE_PROTOCOL("write_end_iter_0");
	w_data = ( (sc_uint<32> )(sc_bv<32>)((sc_bv<24>)((sc_bv<16>)((sc_bv<8>)((
	         write_ws)[0LL]), 
	         (sc_bv<8>)((write_ws)[1LL])), 
	         (sc_bv<8>)((write_ws)[2LL])), 
	         (sc_bv<8>)((write_ws)[3LL])) );
	trig_req = !m_write_valid_tx ^ next_trig_req.read();
	do {
	 HLS_DEFINE_STALL_LOOP(ALL,"put", 0ULL);
	 HLS_DEFINE_PROTOCOL("write_end_iter");
	 wait( 1LL );
	} while ( (m_write_stalling.read() == 1ULL) );
	m_w_x = (m_w_x + 1ULL);
	w_ws_tx_stream()->end_tx();

    }

    
    cynw_scv_tx_stream* w_tx_stream()
    {
#if !STRATUS
      if (m_w_tx_stream == 0) {
        esc_enable_scv_logging();
        m_w_tx_stream = new cynw_scv_tx_stream( (m_stream_name + "_w").c_str(), esc_get_scv_tr_db(), "writer_tx" );
      }
      return m_w_tx_stream;
#else
      return 0;
#endif
    }
    
    cynw_scv_tx_stream* w_ws_tx_stream()
    {
#if !STRATUS
      if (m_w_ws_tx_stream == 0) {
        esc_enable_scv_logging();
        m_w_ws_tx_stream = new cynw_scv_tx_stream( (m_stream_name + "_w" + "_ws").c_str(), esc_get_scv_tr_db(), "writer_ws" );
      }
      return m_w_ws_tx_stream;
#else
      return 0;
#endif
    }
    
    cynw_scv_tx_stream* m_w_tx_stream;
    cynw_scv_tx_stream* m_w_ws_tx_stream;
    int m_w_alg_base;

    
    cynw_scv_tx_stream* r_tx_stream()
    {
#if !STRATUS
      if (m_r_tx_stream == 0) {
        esc_enable_scv_logging();
        m_r_tx_stream = new cynw_scv_tx_stream( (m_stream_name + "_r").c_str(), esc_get_scv_tr_db(), "reader_tx" );
      }
      return m_r_tx_stream;
#else
      return 0;
#endif
    }
    
    cynw_scv_tx_stream* r_ws_tx_stream()
    {
#if !STRATUS
      if (m_r_ws_tx_stream == 0) {
        esc_enable_scv_logging();
        m_r_ws_tx_stream = new cynw_scv_tx_stream( (m_stream_name + "_r" + "_ws").c_str(), esc_get_scv_tr_db(), "reader_ws" );
      }
      return m_r_ws_tx_stream;
#else
      return 0;
#endif
    }
    
    cynw_scv_tx_stream* m_r_tx_stream;
    cynw_scv_tx_stream* m_r_ws_tx_stream;
    int m_r_alg_base;

    std::string m_stream_name;
    sc_uint<2> m_check_get_before_next;
    unsigned m_msg_events;
    enum msg_event_t { msg_r_reset_done=0, msg_w_reset_done=1, msg_num_codes=2 } ;
    
    void msg_event_occurred( msg_event_t msg ) {
        #ifndef STRATUS
        m_msg_events |= (1 << msg);
        #endif
    }
    void msg_event_check( msg_event_t msg ) {
        #ifndef STRATUS
        if ( (m_msg_events & (1 << msg)) == 0 ) {
            switch (msg) {
                case msg_r_reset_done:    
                    esc_report_error( esc_warning, "\n\t%s: Missing reset() call for reader side of stream interface.\n", sc_module::name() );
                    break;
                case msg_w_reset_done:    
                    esc_report_error( esc_warning, "\n\t%s: Missing reset() call for writer side of stream interface.\n", sc_module::name() );
                    break;
                default:
                    break;
            }
            m_msg_events |= (1 << (msg + msg_num_codes));
        }
        msg_event_occurred(msg);
        #endif
    }

};


class stream_16X8::base_in_pin
{
  public:
    HLS_METAPORT;
    
    base_in_pin( const char* name=sc_gen_unique_name("stream_16X8_in") )
      : r_data(HLS_CAT_NAMES(name,"r_data"))
      , m_busy_req(HLS_CAT_NAMES(name,"m_busy_req"))
      , m_data_is_valid(HLS_CAT_NAMES(name,"m_data_is_valid"))
      , m_data_is_invalid(HLS_CAT_NAMES(name,"m_data_is_invalid"))
      , m_read_stalling(HLS_CAT_NAMES(name,"m_read_stalling"))
      , m_read_stall_context(HLS_CAT_NAMES(name,"m_read_stall_context"))
      , r_busy(HLS_CAT_NAMES(name,"r_busy"))
      , r_vld(HLS_CAT_NAMES(name,"r_vld"))

      , m_max_delay(HLS_CALC_TIMING)
      , m_dpopt_opts(DPOPT_DISABLE)
    {}

    sc_in< sc_uint<32> > r_data;
    sc_uint<8> read_ws[8];
    sc_uint<32> data_tmp;
    sc_signal< sc_uint<1> > m_busy_req;
    sc_signal< sc_uint<1> > m_data_is_valid;
    sc_signal< sc_uint<1> > m_data_is_invalid;
    sc_signal< sc_uint<1> > m_read_stalling;
    sc_signal< sc_uint<1> > m_read_stall_context;
    sc_out< bool > r_busy;
    sc_in< bool > r_vld;
    sc_uint<1> m_read_valid_tx;
    sc_uint<1> m_data_was_valid;
    sc_uint<5> m_r_x;
    sc_int<5> refl_index;
    double m_max_delay;
    unsigned int m_dpopt_opts;
    sc_uint<1> m_ws_data_was_valid;


    template <class HLS_C>
    void bind( HLS_C& c )
    {
        cynw_mark_hierarchical_binding( &c );
        r_data(c.r_data);
        r_busy(c.r_busy);
        r_vld(c.r_vld);
    }
    
    template <class HLS_C>
    void operator()( HLS_C& c )
    {
        bind(c);
    }


};

template <typename HLS_L>
class stream_16X8::base_in
  : public stream_16X8::base_in_pin
  , public cynw_clk_rst_facade
{
  public:
    typedef stream_16X8::base_in_pin base_type;
    
    base_in( const char* name=sc_gen_unique_name("stream_16X8_base_in") )
      : base_type(name)
    {
    }

    template <class HLS_C>
    void bind( HLS_C& c )
    {
        cynw_mark_hierarchical_binding( &c );
        r_data(c.r_data);
        r_busy(c.r_busy);
        r_vld(c.r_vld);
    }
    
    template <class HLS_C>
    void operator()( HLS_C& c )
    {
        bind(c);
    }

};

template <typename HLS_L>
class stream_16X8::in
  : public stream_16X8::base_in_pin
  , public sc_module
  , public cynw_clk_rst
{
  public:
    SC_HAS_PROCESS(in);
    HLS_EXPOSE_PORTS( OFF, clk, rst );

    typedef stream_16X8::base_in_pin base_type;
    typedef CYN::PIN  p2p_level;

    
    in( sc_module_name name=sc_module_name( sc_gen_unique_name("stream_16X8_in") ) )
      : base_type(name)
      , sc_module(name)
      , m_stream_name(std::string("sc_main.") + std::string(this->name()))
      , m_tx_stream(0), m_ws_tx_stream(0)
      , m_msg_events(0)
    {
      SC_METHOD(gen_dv_0);
        sensitive << ( r_busy );
        sensitive << ( r_vld );
      
        SC_METHOD(gen_busy_0);
        sensitive << ( m_busy_req );
        sensitive << ( m_read_stalling );
      
      HLS_FLATTEN_ARRAY(read_ws);
      HLS_SUPPRESS_MSG_SYM(513ULL, m_busy_req);
      HLS_SUPPRESS_MSG_SYM(938ULL, read_ws);
      HLS_SUPPRESS_MSG_SYM(2934ULL, read_ws);
      HLS_SUPPRESS_MSG_SYM(2588ULL, read_ws);
      HLS_SUPPRESS_MSG_SYM(1435ULL, r_data);
      HLS_SUPPRESS_MSG_SYM(1433ULL, r_data);
      HLS_SET_IS_BOUNDED(m_max_delay, "");
      HLS_SET_IS_BOUNDED(m_dpopt_opts, "");

    }

    template <class HLS_C>
    void bind( HLS_C& c )
    {
        cynw_mark_hierarchical_binding( &c );
        r_data(c.r_data);
        r_busy(c.r_busy);
        r_vld(c.r_vld);
    }
    
    template <class HLS_C>
    void operator()( HLS_C& c )
    {
        bind(c);
    }


    sc_uint<1> new_vld_0;
    
    void gen_dv_0(){
      {
        HLS_DPOPT_REGION(2ULL, "gen_dv_0");
        new_vld_0 = (r_vld.read() && !r_busy.read());
        m_data_is_valid = new_vld_0;
        m_data_is_invalid = !new_vld_0;
      }
    }
    void gen_busy_0(){
      if ( (m_busy_req.read() == 0ULL) ) {
        r_busy = (sc_uint<1> ) (m_read_stalling.read());
      } else {
        r_busy = (sc_uint<1> ) (1ULL);
      }
    }


    sc_uint<5> x() const {
        return m_r_x;
    }
    
    sc_uint<5> x_new() const {
        return m_r_x ;
    }
    
    sc_uint<1> x_done() const {
        return (m_r_x == 2ULL);
    }
    
    sc_uint<1> r_x_done() const {
        return x_done();
    }
    
    sc_uint<1> done() const {
        return (m_r_x == 2ULL);
    }
    
    void set_size( int new_xsz=0 ) {
#ifndef STRATUS
      esc_report_error( esc_warning, "\n\t%s: set_size() called for an interface that does not have the Variable Limits option set.", sc_module::name() );
#endif
    }


    

    

    void reset()
    {
	msg_event_occurred(msg_r_reset_done);
	
	m_read_valid_tx = 1ULL;
	{
	  HLS_DEFINE_PROTOCOL("read_reset_0");
	  m_busy_req = 1ULL;
	  m_read_stalling = 0ULL;
	}
	HLS_SET_STALL_VALUE(m_read_stalling, 1ULL, 1ULL, &m_read_stall_context, &
	m_busy_req);
	HLS_SET_OUTPUT_OPTIONS(m_read_stalling, ASYNC_NO_HOLD);
	HLS_SET_OUTPUT_DELAY(m_read_stalling, HLS_CLOCK_PERIOD - HLS_FU_CLOCK_PERIOD * 
	0.500000);

	HLS_SUPPRESS_MSG_SYM( 408, *this );
    }

    bool start_tx( sc_uint<1> valid_tx=true )
    {
        

	set_data_is_valid( valid_tx );
	tx_stream()->begin_tx();

	
	m_r_x = 0ULL;
	(read_ws)[0LL] = 0ULL;
	(read_ws)[1LL] = 0ULL;
	(read_ws)[2LL] = 0ULL;
	(read_ws)[3LL] = 0ULL;
	(read_ws)[4LL] = 0ULL;
	(read_ws)[5LL] = 0ULL;
	(read_ws)[6LL] = 0ULL;
	(read_ws)[7LL] = 0ULL;
	HLS_REMOVE_CONTROL("stream_16X8_7");

	return data_is_valid();
    }

    void end_tx()
    {
	tx_stream()->end_tx();

	

    }

    void get( sc_uint<8> (&in_ws)[8] )
    {
	msg_event_check(msg_r_reset_done);
#ifndef STRATUS
	if ( r_x_done() ) {
	    esc_report_error( esc_warning, "\n\t%s: get() called for more than %d accesses for channel 'stream_16X8'\n", sc_module::name(), 2 );
	}
#endif
	m_check_get_before_next &= ~1;
	ws_tx_stream()->begin_tx();
	ws_tx_stream()->record_attrib("X", (int)x());
	sc_uint<2> i_3;
	
	HLS_REMOVE_CONTROL("stream_16X8_8");
	i_3 = 0ULL;
	while ( (sc_uint<1>) (i_3 < 2ULL) ) {
	  HLS_UNROLL_LOOP(ON,"tmp_1");
	  {
	    HLS_DEFINE_PROTOCOL("read_start_iter_3");
	    m_busy_req = !m_read_valid_tx;
	    do {
	     HLS_DEFINE_STALL_LOOP(ALL,"get_2", &m_read_stall_context);
	     HLS_DEFINE_PROTOCOL("read_start_iter_2");
	     wait( 1LL );
	    } while ( m_data_is_invalid.read() & m_read_valid_tx );
	    m_busy_req = 1ULL;
	    m_data_was_valid = m_read_valid_tx;
	    data_tmp = r_data.read();
	  }
	  (read_ws)[0LL] = (read_ws)[4LL];
	  (read_ws)[1LL] = (read_ws)[5LL];
	  (read_ws)[2LL] = (read_ws)[6LL];
	  (read_ws)[3LL] = (read_ws)[7LL];
	  (read_ws)[4LL] = data_tmp.range(31,24);
	  (read_ws)[5LL] = data_tmp.range(23,16);
	  (read_ws)[6LL] = data_tmp.range(15,8);
	  (read_ws)[7LL] = data_tmp;
	  i_3 = (i_3 + 1ULL);
	}
	m_r_x = (m_r_x + 1ULL);
	(in_ws)[7LL] = (read_ws)[7LL];
	(in_ws)[6LL] = (read_ws)[6LL];
	(in_ws)[5LL] = (read_ws)[5LL];
	(in_ws)[4LL] = (read_ws)[4LL];
	(in_ws)[3LL] = (read_ws)[3LL];
	(in_ws)[2LL] = (read_ws)[2LL];
	(in_ws)[1LL] = (read_ws)[1LL];
	(in_ws)[0LL] = (read_ws)[0LL];
	ws_tx_stream()->record_attrib("P1", in_ws);
	ws_tx_stream()->end_tx();

    }

    sc_uint<1> poll( sc_uint<8> (&in_ws)[8] )
    {
	msg_event_check(msg_r_reset_done);
#ifndef STRATUS
	if ( r_x_done() ) {
	    esc_report_error( esc_warning, "\n\t%s: poll() called for more than %d accesses for channel 'stream_16X8'\n", sc_module::name(), 2 );
	}
#endif
	m_check_get_before_next &= ~1;
	ws_tx_stream()->begin_tx();
	ws_tx_stream()->record_attrib("X", (int)x());
	sc_uint<2> i_4;
	
	HLS_REMOVE_CONTROL("stream_16X8_9");
	i_4 = 0ULL;
	while ( (sc_uint<1>) (i_4 < 2ULL) ) {
	  HLS_UNROLL_LOOP(ON,"tmp_2");
	  {
	    HLS_DEFINE_PROTOCOL("read_start_iter_4");
	    m_busy_req = !m_read_valid_tx;
	    wait( 1LL );
	    m_data_was_valid = m_data_is_valid.read() & m_read_valid_tx;
	    m_busy_req = 1ULL;
	    data_tmp = r_data.read();
	  }
	  (read_ws)[0LL] = (read_ws)[4LL];
	  (read_ws)[1LL] = (read_ws)[5LL];
	  (read_ws)[2LL] = (read_ws)[6LL];
	  (read_ws)[3LL] = (read_ws)[7LL];
	  (read_ws)[4LL] = data_tmp.range(31,24);
	  (read_ws)[5LL] = data_tmp.range(23,16);
	  (read_ws)[6LL] = data_tmp.range(15,8);
	  (read_ws)[7LL] = data_tmp;
	  i_4 = (i_4 + 1ULL);
	}
	m_r_x = (m_r_x + 1ULL);
	(in_ws)[7LL] = (read_ws)[7LL];
	(in_ws)[6LL] = (read_ws)[6LL];
	(in_ws)[5LL] = (read_ws)[5LL];
	(in_ws)[4LL] = (read_ws)[4LL];
	(in_ws)[3LL] = (read_ws)[3LL];
	(in_ws)[2LL] = (read_ws)[2LL];
	(in_ws)[1LL] = (read_ws)[1LL];
	(in_ws)[0LL] = (read_ws)[0LL];
	ws_tx_stream()->record_attrib("P1", in_ws);
	ws_tx_stream()->end_tx();

	return m_ws_data_was_valid;
    }


        
    sc_uint<1> m_mt_err_issued;
    void need_mt_error()
    {
      #if STRATUS
      HLS_MESSAGE(2891);
      #else
      if (!m_mt_err_issued)
        esc_report_error( esc_error, "\n\tstream_16X8: Must set the Multi Threaded option to use the non-blocking API"  );
      m_mt_err_issued = 1;
      #endif
    }
    
    bool data_was_valid()
    {
        need_mt_error();
        return false;
    }
    
    bool nb_can_get()
    {
        need_mt_error();
        return false;
    }
    
    void get_start( bool busy_val=false )
    {
        need_mt_error();
    }
    
    void get_end()
    {
        need_mt_error();
    }
    
    bool nb_get( sc_uint<8> (&in_ws)[8] )
    {
        need_mt_error();
        return false;
    }
    
    void latch_value( sc_uint<1> valid_tx=true )
    {
        need_mt_error();
    }
    
    void set_state( unsigned which, unsigned value )
    {
        need_mt_error();
    }



    void enable_dpopt( double md=HLS_CALC_TIMING )
    {
	 m_max_delay = md;
	 m_dpopt_opts = 0;
    }

    bool data_is_valid()
    {
      return m_read_valid_tx;
    }

    void set_data_is_valid( sc_uint<1> valid_tx )
    {
            m_read_valid_tx = valid_tx;;
    }

    
    cynw_scv_tx_stream* tx_stream()
    {
#if !STRATUS
      if (m_tx_stream == 0) {
        esc_enable_scv_logging();
        m_tx_stream = new cynw_scv_tx_stream( (m_stream_name + "_r").c_str(), esc_get_scv_tr_db(), "reader_tx" );
      }
      return m_tx_stream;
#else
      return 0;
#endif
    }
    
    cynw_scv_tx_stream* ws_tx_stream()
    {
#if !STRATUS
      if (m_ws_tx_stream == 0) {
        esc_enable_scv_logging();
        m_ws_tx_stream = new cynw_scv_tx_stream( (m_stream_name + "_r" + "_ws").c_str(), esc_get_scv_tr_db(), "reader_ws" );
      }
      return m_ws_tx_stream;
#else
      return 0;
#endif
    }
    
    cynw_scv_tx_stream* m_tx_stream;
    cynw_scv_tx_stream* m_ws_tx_stream;
    int m_alg_base;

    std::string m_stream_name;
    sc_uint<2> m_check_get_before_next;
    unsigned m_msg_events;
    enum msg_event_t { msg_r_reset_done=0, msg_w_reset_done=1, msg_num_codes=2 } ;
    
    void msg_event_occurred( msg_event_t msg ) {
        #ifndef STRATUS
        m_msg_events |= (1 << msg);
        #endif
    }
    void msg_event_check( msg_event_t msg ) {
        #ifndef STRATUS
        if ( (m_msg_events & (1 << msg)) == 0 ) {
            switch (msg) {
                case msg_r_reset_done:    
                    esc_report_error( esc_warning, "\n\t%s: Missing reset() call for reader side of stream interface.\n", sc_module::name() );
                    break;
                case msg_w_reset_done:    
                    esc_report_error( esc_warning, "\n\t%s: Missing reset() call for writer side of stream interface.\n", sc_module::name() );
                    break;
                default:
                    break;
            }
            m_msg_events |= (1 << (msg + msg_num_codes));
        }
        msg_event_occurred(msg);
        #endif
    }

};

class stream_16X8::base_out_pin
{
  public:
    HLS_METAPORT;
    
    base_out_pin( const char* name=sc_gen_unique_name("stream_16X8_out") )
      : w_data(HLS_CAT_NAMES(name,"w_data"))
      , trig_req(HLS_CAT_NAMES(name,"trig_req"))
      , prev_trig_req(HLS_CAT_NAMES(name,"prev_trig_req"))
      , next_trig_req(HLS_CAT_NAMES(name,"next_trig_req"))
      , m_unacked_req(HLS_CAT_NAMES(name,"m_unacked_req"))
      , m_write_stalling(HLS_CAT_NAMES(name,"m_write_stalling"))
      , m_write_stall_context(HLS_CAT_NAMES(name,"m_write_stall_context"))
      , w_vld(HLS_CAT_NAMES(name,"w_vld"))
      , w_busy(HLS_CAT_NAMES(name,"w_busy"))

      , m_arg(HLS_CAT_NAMES(name,"m_arg"))
    {}

    sc_out< sc_uint<32> > w_data;
    sc_uint<8> write_ws[4];
    sc_signal< sc_uint<1> > trig_req;
    sc_signal< sc_uint<1> > prev_trig_req;
    sc_signal< sc_uint<1> > next_trig_req;
    sc_signal< sc_uint<1> > m_unacked_req;
    sc_signal< sc_uint<1> > m_write_stalling;
    sc_signal< sc_uint<1> > m_write_stall_context;
    sc_out< bool > w_vld;
    sc_in< bool > w_busy;
    sc_uint<1> m_write_valid_tx;
    sc_uint<5> m_w_x;


    template <class HLS_C>
    void bind( HLS_C& c )
    {
        cynw_mark_hierarchical_binding( &c );
        w_data(c.w_data);
        w_vld(c.w_vld);
        w_busy(c.w_busy);
    }
    
    template <class HLS_C>
    void operator()( HLS_C& c )
    {
        bind(c);
    }


    sc_signal<bool> m_arg;
};

template <typename HLS_L>
class stream_16X8::base_out
  : public stream_16X8::base_out_pin
  , public cynw_clk_rst_facade
{
  public:
    typedef stream_16X8::base_out_pin base_type;
    
    base_out( const char* name=sc_gen_unique_name("stream_16X8_base_out") )
      : base_type(name)
    {
    }

    template <class HLS_C>
    void bind( HLS_C& c )
    {
        cynw_mark_hierarchical_binding( &c );
        w_data(c.w_data);
        w_vld(c.w_vld);
        w_busy(c.w_busy);
    }
    
    template <class HLS_C>
    void operator()( HLS_C& c )
    {
        bind(c);
    }

};

template <typename HLS_L>
class stream_16X8::out
  : public stream_16X8::base_out_pin
  , public sc_module
  , public cynw_clk_rst
{
  public:
    SC_HAS_PROCESS(out);
    HLS_EXPOSE_PORTS( OFF, clk, rst );

    typedef stream_16X8::base_out_pin base_type;
    
    out( sc_module_name name=sc_module_name( sc_gen_unique_name("stream_16X8_out") ) )
      : base_type(name)
      , sc_module(name)
      , m_stream_name(std::string("sc_main.") + std::string(this->name()))
      , m_tx_stream(0), m_ws_tx_stream(0)
      , m_msg_events(0)
    {
      SC_METHOD(write_sync_0);
        sensitive << clk.pos();
        dont_initialize();
      
        SC_METHOD(gen_vld_0);
        sensitive << ( prev_trig_req );
        sensitive << ( trig_req );
        sensitive << ( m_unacked_req );
      
        SC_METHOD(gen_out_stalling_0);
        sensitive << ( w_vld );
        sensitive << ( w_busy );
      
        SC_METHOD(save_trig_0);
        sensitive << clk.pos();
        dont_initialize();
      
        SC_METHOD(gen_next_trig_0);
        sensitive << ( trig_req );
      
      HLS_FLATTEN_ARRAY(write_ws);
      HLS_SUPPRESS_MSG_SYM(1435ULL, w_data);
      HLS_SUPPRESS_MSG_SYM(1433ULL, w_data);

    }

    
    void write_sync_0(){
      if ( rst_active() ) {
        HLS_DEFINE_PROTOCOL("hls_reset_block_3");
        HLS_REMOVE_CONTROL(OFF,"stream_16X8_10");
        m_unacked_req = 0ULL;
      } else {
        m_unacked_req = m_write_stalling.read();
      }
    }
    void gen_vld_0(){
      {
        HLS_DPOPT_REGION(2ULL, "gen_vld_0");
        w_vld = (sc_uint<1> ) ((m_unacked_req.read()||trig_req.read() ^ 
                prev_trig_req.read()));
      }
    }
    void gen_out_stalling_0(){
      m_write_stalling = (w_busy.read() && w_vld.read());
    }
    void save_trig_0(){
      if ( rst_active() ) {
        HLS_DEFINE_PROTOCOL("hls_reset_block_4");
        HLS_REMOVE_CONTROL(OFF,"stream_16X8_11");
        prev_trig_req = 0ULL;
      } else {
        prev_trig_req = trig_req.read();
      }
    }
    void gen_next_trig_0(){
      next_trig_req = !trig_req.read();
    }


    sc_uint<5> x() const {
        return m_w_x;
    }
    
    sc_uint<1> x_done() const {
        return (m_w_x == 4ULL);
    }
    
    sc_uint<1> w_x_done() const {
        return x_done();
    }
    
    sc_uint<1> done() const {
        return (m_w_x == 4ULL);
    }
    
    void set_size( int new_xsz=0 ) {
#ifndef STRATUS
      esc_report_error( esc_warning, "\n\t%s: set_size() called for an interface that does not have the Variable Limits option set.", sc_module::name() );
#endif
    }


    template <class HLS_C>
    void bind( HLS_C& c )
    {
        cynw_mark_hierarchical_binding( &c );
        w_data(c.w_data);
        w_vld(c.w_vld);
        w_busy(c.w_busy);
    }
    
    template <class HLS_C>
    void operator()( HLS_C& c )
    {
        bind(c);
    }



    void reset()
    { 
	msg_event_occurred(msg_w_reset_done);
	
	m_write_valid_tx = 1ULL;
	{
	  HLS_DEFINE_PROTOCOL("write_reset_0");
	  trig_req = 0ULL;
	}

	HLS_SUPPRESS_MSG_SYM( 408, *this );
    }

    void start_tx( sc_uint<1> valid_tx=true )
    {
	set_data_is_valid( valid_tx );
	

	tx_stream()->begin_tx();

	
	m_w_x = 0ULL;
	(write_ws)[0LL] = 0ULL;
	(write_ws)[1LL] = 0ULL;
	(write_ws)[2LL] = 0ULL;
	(write_ws)[3LL] = 0ULL;

    }

    void end_tx()
    {
	

	tx_stream()->end_tx();

    }

    void put( sc_uint<8> (&out_ws)[4] )
    {
	msg_event_check(msg_w_reset_done);
#ifndef STRATUS
	if ( w_x_done() ) {
	    esc_report_error( esc_warning, "\n\t%s: put() called for more than %d accesses for channel 'stream_16X8'\n", sc_module::name(), 4 );
	}
#endif
	ws_tx_stream()->begin_tx();
	ws_tx_stream()->record_attrib("X", (int)x());
	ws_tx_stream()->record_attrib("P1", out_ws);
	
	(write_ws)[3LL] = (out_ws)[3LL];
	(write_ws)[2LL] = (out_ws)[2LL];
	(write_ws)[1LL] = (out_ws)[1LL];
	(write_ws)[0LL] = (out_ws)[0LL];
	HLS_COALESCE_LOOP(CONSERVATIVE,"stream_16X8_12");
	HLS_DEFINE_PROTOCOL("write_end_iter_2");
	w_data = ( (sc_uint<32> )(sc_bv<32>)((sc_bv<24>)((sc_bv<16>)((sc_bv<8>)((
	         write_ws)[0LL]), 
	         (sc_bv<8>)((write_ws)[1LL])), 
	         (sc_bv<8>)((write_ws)[2LL])), 
	         (sc_bv<8>)((write_ws)[3LL])) );
	trig_req = !m_write_valid_tx ^ next_trig_req.read();
	do {
	 HLS_DEFINE_STALL_LOOP(ALL,"put_0", 0ULL);
	 HLS_DEFINE_PROTOCOL("write_end_iter_1");
	 wait( 1LL );
	} while ( (m_write_stalling.read() == 1ULL) );
	m_w_x = (m_w_x + 1ULL);
	ws_tx_stream()->end_tx();

    }

    bool data_is_valid()
    {
      return m_write_valid_tx;
    }

    void set_data_is_valid( sc_uint<1> valid_tx )
    {
      m_write_valid_tx = valid_tx;;
    }

    
    cynw_scv_tx_stream* tx_stream()
    {
#if !STRATUS
      if (m_tx_stream == 0) {
        esc_enable_scv_logging();
        m_tx_stream = new cynw_scv_tx_stream( (m_stream_name + "_w").c_str(), esc_get_scv_tr_db(), "writer_tx" );
      }
      return m_tx_stream;
#else
      return 0;
#endif
    }
    
    cynw_scv_tx_stream* ws_tx_stream()
    {
#if !STRATUS
      if (m_ws_tx_stream == 0) {
        esc_enable_scv_logging();
        m_ws_tx_stream = new cynw_scv_tx_stream( (m_stream_name + "_w" + "_ws").c_str(), esc_get_scv_tr_db(), "writer_ws" );
      }
      return m_ws_tx_stream;
#else
      return 0;
#endif
    }
    
    cynw_scv_tx_stream* m_tx_stream;
    cynw_scv_tx_stream* m_ws_tx_stream;
    int m_alg_base;

    std::string m_stream_name;
    unsigned m_msg_events;
    enum msg_event_t { msg_r_reset_done=0, msg_w_reset_done=1, msg_num_codes=2 } ;
    
    void msg_event_occurred( msg_event_t msg ) {
        #ifndef STRATUS
        m_msg_events |= (1 << msg);
        #endif
    }
    void msg_event_check( msg_event_t msg ) {
        #ifndef STRATUS
        if ( (m_msg_events & (1 << msg)) == 0 ) {
            switch (msg) {
                case msg_r_reset_done:    
                    esc_report_error( esc_warning, "\n\t%s: Missing reset() call for reader side of stream interface.\n", sc_module::name() );
                    break;
                case msg_w_reset_done:    
                    esc_report_error( esc_warning, "\n\t%s: Missing reset() call for writer side of stream interface.\n", sc_module::name() );
                    break;
                default:
                    break;
            }
            m_msg_events |= (1 << (msg + msg_num_codes));
        }
        msg_event_occurred(msg);
        #endif
    }

};

#if ! defined(STRATUS_HLS)
template <>
class stream_16X8::chan<CYN::TLM>
  : public tlm::tlm_fifo<tlm_io_t>
  , public cynw_clk_rst_facade
{
  public:
	    chan( const char* name=sc_gen_unique_name("stream_16X8_chan") ) {}
};

template <>
class stream_16X8::direct<CYN::TLM>
  : public sc_module
  , public cynw_clk_rst_facade
{
  public:
    typedef CYN::TLM  p2p_level;

    direct( sc_module_name name=sc_module_name( sc_gen_unique_name("stream_16X8_direct") ) )
      : sc_module(name)
      , m_write_buf( new in_param_t )
      , m_read_buf( new in_param_t )
      , m_chan(name,1)
      , m_w_tx_stream(0), m_w_ws_tx_stream(0), m_r_tx_stream(0), m_r_ws_tx_stream(0)
      , m_stream_name(std::string("sc_main.") + std::string(::sc_core::sc_get_curr_simcontext()->hierarchy_curr()->name()) + std::string(".") + std::string(name))
      , m_msg_events(0)
    {
    }

    in_param_t* m_write_buf;
    in_param_t* m_read_buf;
        int m_r_x;
    int m_w_x;
    int refl_index;

    
    sc_uint<5> r_x() const {
        return m_r_x;
    }
    
    sc_uint<5> r_x_new() const {
        return m_r_x ;
    }
    
    sc_uint<1> r_x_done() const {
        return (m_r_x == 2ULL);
    }
    
    sc_uint<1> r_done() const {
        return (m_r_x == 2ULL);
    }
    
    sc_uint<5> w_x() const {
        return m_w_x;
    }
    
    sc_uint<1> w_x_done() const {
        return (m_w_x == 4ULL);
    }
    
    sc_uint<1> w_done() const {
        return (m_w_x == 4ULL);
    }
    
    void r_set_size( int new_xsz=0 ) {
#ifndef STRATUS
      esc_report_error( esc_warning, "\n\t%s: set_size() called for an interface that does not have the Variable Limits option set.", sc_module::name() );
#endif
    }void w_set_size( int new_xsz=0 ) {
#ifndef STRATUS
      esc_report_error( esc_warning, "\n\t%s: set_size() called for an interface that does not have the Variable Limits option set.", sc_module::name() );
#endif
    }


    

    

    void w_reset()
    { 
	msg_event_occurred(msg_w_reset_done);
    }
    void writer_reset()
    {
       w_reset();
    }

    void r_reset()
    {
	msg_event_occurred(msg_r_reset_done);
		
	while ( (*this) .m_chan. nb_can_get() ) {
	  stream_16X8::tlm_io_t val;
	  (*this) .m_chan. nb_get( val );
	}

    }
    void reader_reset()
    {
       r_reset();
    }

    void w_start_tx( sc_uint<1> valid_tx=true )
    {
	w_set_data_is_valid( valid_tx );
	        m_w_x = 0;
	m_write_buf->reset_io();
	w_tx_stream()->begin_tx();

    }
    void writer_start_tx( sc_uint<1> valid_tx=true )
    {
      w_start_tx( valid_tx );
    }

    void w_end_tx()
    {
          cynw_wait_while_cond( !(*this).m_chan. nb_can_put(), (*this).m_chan. ok_to_put() );
          (*this).m_chan. nb_put( m_write_buf );
          m_write_buf = new in_param_t;

      w_tx_stream()->end_tx();

    }
    void writer_end_tx()
    {
       w_end_tx();
    }

    bool r_start_tx( sc_uint<1> valid_tx=true )
    {
	        m_r_x = 0;
	m_read_buf->reset_io();
	m_use_beh_latched = false;
	r_tx_stream()->begin_tx();

	return r_data_is_valid();
    }
    bool reader_start_tx( sc_uint<1> valid_tx=true )
    {
      return r_start_tx( valid_tx=true );
    }

    void r_end_tx()
    {
      r_tx_stream()->end_tx();

    }
    void reader_end_tx()
    {
      r_end_tx();
    }

    void put( sc_uint<8> (&out_ws)[4] )
    {
      msg_event_check(msg_w_reset_done);
      if (m_w_x <= 3LL) {
          int ix;
          for ( ix=0; ix < 4; ix++ ) {
              m_write_buf->P1[(m_w_x * 4) + ix] = out_ws[ix];
          }
      } else {
          esc_report_error( esc_warning, "\n\t%s: put() called too many times for parameter 'P1' in channel 'stream_16X8'\n", sc_module::name() );
      }
      w_ws_tx_stream()->begin_tx();
      w_ws_tx_stream()->record_attrib("X", (int)w_x());
      w_ws_tx_stream()->record_attrib("P1", out_ws);
      w_ws_tx_stream()->end_tx();
      
      m_w_x = (m_w_x + 1ULL);

    }

    int do_trim_index( int coord, int max_val )
    {
	  
	  if ( (sc_uint<1>) (coord < 0LL) ) {
	    coord = 0LL;
	  } else {
	    if ( (sc_uint<1>) (coord > max_val) ) {
	      coord = max_val;
	    } 
	  }

	  return  coord;
    }

    void get( sc_uint<8> (&in_ws)[8] )
    {
      msg_event_check(msg_r_reset_done);
      m_check_get_before_next &= ~1;
      int x_orig = m_r_x;
      int iya = 0;
      if (!(m_r_x != 0 || m_use_beh_latched)) {
          cynw_wait_while_cond( !(*this).m_chan. nb_can_get(), (*this).m_chan. ok_to_get() );
          delete m_read_buf;
          (*this).m_chan. nb_get( m_read_buf );
      }
      int ix, ixb;
      ixb = (x_orig * 8);
      for ( ix=0; ix < 8; ix++ ) {
          int ixc = do_trim_index( ixb+ix, 15LL );
          in_ws[ix] = m_read_buf->P1[ixc];
      }
#ifndef STRATUS
      if ( r_x_done() ) {
          esc_report_error( esc_warning, "\n\t%s: get() called for more than %d accesses for channel 'stream_16X8'\n", sc_module::name(), 2 );
      }
#endif
      r_ws_tx_stream()->begin_tx();
      r_ws_tx_stream()->record_attrib("X", (int)r_x());
      
      m_r_x = (m_r_x + 1ULL);
      r_ws_tx_stream()->record_attrib("P1", in_ws);
      r_ws_tx_stream()->end_tx();
      m_data_was_valid = true;

    }

    bool poll( sc_uint<8> (&in_ws)[8] )
    {
      msg_event_check(msg_r_reset_done);
      m_check_get_before_next &= ~1;
      int x_orig = m_r_x;
      int iya = 0;
      if (!(m_r_x != 0 || m_use_beh_latched)) {
          if ( ! (*this).m_chan. nb_can_get() ) {
              cynw_wait_if_cond( last_poll_was_now() );
              set_last_poll();
          }
          if ( (m_data_was_valid = (*this).m_chan. nb_can_get()) ) {
              delete m_read_buf;
              (*this).m_chan. nb_get( m_read_buf );
          } else {
              return false;
          }
      }
      int ix, ixb;
      ixb = (x_orig * 8);
      for ( ix=0; ix < 8; ix++ ) {
          int ixc = do_trim_index( ixb+ix, 15LL );
          in_ws[ix] = m_read_buf->P1[ixc];
      }
#ifndef STRATUS
      if ( r_x_done() ) {
          esc_report_error( esc_warning, "\n\t%s: poll() called for more than %d accesses for channel 'stream_16X8'\n", sc_module::name(), 2 );
      }
#endif
      r_ws_tx_stream()->begin_tx();
      r_ws_tx_stream()->record_attrib("X", (int)r_x());
      
      m_r_x = (m_r_x + 1ULL);
      r_ws_tx_stream()->record_attrib("P1", in_ws);
      r_ws_tx_stream()->end_tx();
      m_data_was_valid = true;

      return m_data_was_valid;
    }

    sc_uint<1> read_write( sc_uint<8> new_value, 
                           sc_uint<8> (&in_ws)[8],
                           unsigned int actions =CYNIF_DO_WRITE | CYNIF_DO_ADVANCE | CYNIF_DO_READ )
    {
            #if ! defined(STRATUS_HLS)
	  esc_report_error( esc_warning, "\n\t%s: read_write() not supported for this interface.\n", sc_module::name() );
	return false;
	#endif
    }

    sc_uint<1> read( sc_uint<8> new_value, 
                     sc_uint<8> (&in_ws)[8],
		     bool advance=false )
    {
      return read_write( new_value, 
                         in_ws,
			 CYNIF_DO_READ | (advance ? CYNIF_DO_ADVANCE : 0) );
    }

    sc_uint<1> write( sc_uint<8> new_value,
                      bool advance=true )
		
    {
      sc_uint<8> in_ws[8];

      HLS_FLATTEN_ARRAY(in_ws);

      return read_write( new_value, 
                         in_ws,
			 CYNIF_DO_WRITE | (advance ? CYNIF_DO_ADVANCE : 0));
    }

    sc_uint<1> advance()
    {
      sc_uint<8> new_value;

      sc_uint<8> in_ws[8];

      HLS_FLATTEN_ARRAY(in_ws);

      return read_write( new_value, 
                         in_ws,
			 CYNIF_DO_ADVANCE );
    }

    bool nb_get( sc_uint<8> (&in_ws)[8] )
    {
      msg_event_check(msg_r_reset_done);
      m_check_get_before_next &= ~1;
      int x_orig = m_r_x;
      int iya = 0;
      if (!(m_r_x != 0 || m_use_beh_latched)) {
          if ( ! (*this).m_chan. nb_can_get() ) {
              cynw_wait_if_cond( last_poll_was_now() );
              set_last_poll();
          }
          if ( (m_data_was_valid = (*this).m_chan. nb_can_get()) ) {
              delete m_read_buf;
              (*this).m_chan. nb_get( m_read_buf );
          } else {
              return false;
          }
      }
      int ix, ixb;
      ixb = (x_orig * 8);
      for ( ix=0; ix < 8; ix++ ) {
          int ixc = do_trim_index( ixb+ix, 15LL );
          in_ws[ix] = m_read_buf->P1[ixc];
      }
#ifndef STRATUS
      if ( r_x_done() ) {
          esc_report_error( esc_warning, "\n\t%s: get() called for more than %d accesses for channel 'stream_16X8'\n", sc_module::name(), 2 );
      }
#endif
      r_ws_tx_stream()->begin_tx();
      r_ws_tx_stream()->record_attrib("X", (int)r_x());
      
      m_r_x = (m_r_x + 1ULL);
      r_ws_tx_stream()->record_attrib("P1", in_ws);
      r_ws_tx_stream()->end_tx();
      m_data_was_valid = true;

      return m_data_was_valid;
    }


    bool data_was_valid()
    {
	return m_data_was_valid;
    }

    bool nb_can_get()
    {
            return (m_r_x != 0 || m_use_beh_latched || (*this).m_chan. nb_can_get());
    }

    const sc_event& ok_to_get() const
    {
      return m_chan. ok_to_get();
    }

    void get_start( bool busy_val=false )
    {
      if (!busy_val)
      {
	m_data_was_valid = false;
	      }
    }

    void get_end()
    {
    }

    void latch_value( bool do_latch=true )
    {
      m_data_was_valid = (m_r_x != 0 || m_use_beh_latched || (*this).m_chan. nb_can_get());
      if ( m_data_was_valid && do_latch && !m_use_beh_latched )
      {
	m_use_beh_latched = true;
      	delete m_read_buf;
	m_chan.nb_get( m_read_buf );
      }
    }

    void set_state( unsigned which, unsigned value )
    {
      switch (which) {
	case CYNW_SET_DATA_WAS_VALID  :
	  m_data_was_valid = value;
	  break;
	default:
	  break;
      }
    }

    bool last_poll_was_now()
    {
      return (last_poll_time() == sc_time_stamp().to_double());
    }
    double last_poll_time()
    {
      return m_last_poll_time;
    }
    void set_last_poll()
    {
      m_last_poll_time = sc_time_stamp().to_double();
    }
    void clear_last_poll()
    {
      m_last_poll_time = -1.0;
    }

    double m_last_poll_time;
    bool m_data_was_valid;
    bool m_use_beh_latched;

    void enable_dpopt( double md=HLS_CALC_TIMING )
    {}

    bool w_data_is_valid()
    {
      return m_write_valid_tx;
    }
    bool writer_data_is_valid()
    {
      return w_data_is_valid();
    }

    void w_set_data_is_valid( sc_uint<1> valid_tx )
    {
      m_write_valid_tx = valid_tx;;
    }
    void writer_set_data_is_valid( sc_uint<1> valid_tx )
    {
       w_set_data_is_valid( valid_tx );
    }

    bool r_data_is_valid()
    {
      return m_read_valid_tx;
    }
    bool reader_data_is_valid()
    {
      return r_data_is_valid();
    }

    void r_set_data_is_valid( sc_uint<1> valid_tx )
    {
            m_read_valid_tx = valid_tx;;
    }
    void reader_set_data_is_valid( sc_uint<1> valid_tx )
    {
       r_set_data_is_valid( valid_tx );
    }

    sc_uint<1> m_read_valid_tx;
    sc_uint<1> m_write_valid_tx;

    tlm::tlm_fifo<tlm_io_t> m_chan;
    
    cynw_scv_tx_stream* w_tx_stream()
    {
#if !STRATUS
      if (m_w_tx_stream == 0) {
        esc_enable_scv_logging();
        m_w_tx_stream = new cynw_scv_tx_stream( (m_stream_name + "_w").c_str(), esc_get_scv_tr_db(), "writer_tx" );
      }
      return m_w_tx_stream;
#else
      return 0;
#endif
    }
    
    cynw_scv_tx_stream* w_ws_tx_stream()
    {
#if !STRATUS
      if (m_w_ws_tx_stream == 0) {
        esc_enable_scv_logging();
        m_w_ws_tx_stream = new cynw_scv_tx_stream( (m_stream_name + "_w" + "_ws").c_str(), esc_get_scv_tr_db(), "writer_ws" );
      }
      return m_w_ws_tx_stream;
#else
      return 0;
#endif
    }
    
    cynw_scv_tx_stream* m_w_tx_stream;
    cynw_scv_tx_stream* m_w_ws_tx_stream;
    int m_w_alg_base;

    
    cynw_scv_tx_stream* r_tx_stream()
    {
#if !STRATUS
      if (m_r_tx_stream == 0) {
        esc_enable_scv_logging();
        m_r_tx_stream = new cynw_scv_tx_stream( (m_stream_name + "_r").c_str(), esc_get_scv_tr_db(), "reader_tx" );
      }
      return m_r_tx_stream;
#else
      return 0;
#endif
    }
    
    cynw_scv_tx_stream* r_ws_tx_stream()
    {
#if !STRATUS
      if (m_r_ws_tx_stream == 0) {
        esc_enable_scv_logging();
        m_r_ws_tx_stream = new cynw_scv_tx_stream( (m_stream_name + "_r" + "_ws").c_str(), esc_get_scv_tr_db(), "reader_ws" );
      }
      return m_r_ws_tx_stream;
#else
      return 0;
#endif
    }
    
    cynw_scv_tx_stream* m_r_tx_stream;
    cynw_scv_tx_stream* m_r_ws_tx_stream;
    int m_r_alg_base;

    std::string m_stream_name;
    sc_uint<2> m_check_get_before_next;
    unsigned m_msg_events;
    enum msg_event_t { msg_r_reset_done=0, msg_w_reset_done=1, msg_num_codes=2 } ;
    
    void msg_event_occurred( msg_event_t msg ) {
        #ifndef STRATUS
        m_msg_events |= (1 << msg);
        #endif
    }
    void msg_event_check( msg_event_t msg ) {
        #ifndef STRATUS
        if ( (m_msg_events & (1 << msg)) == 0 ) {
            switch (msg) {
                case msg_r_reset_done:    
                    esc_report_error( esc_warning, "\n\t%s: Missing reset() call for reader side of stream interface.\n", sc_module::name() );
                    break;
                case msg_w_reset_done:    
                    esc_report_error( esc_warning, "\n\t%s: Missing reset() call for writer side of stream interface.\n", sc_module::name() );
                    break;
                default:
                    break;
            }
            m_msg_events |= (1 << (msg + msg_num_codes));
        }
        msg_event_occurred(msg);
        #endif
    }

};

class stream_16X8::base_in_tlm
    : public sc_port< tlm::tlm_fifo_get_if<tlm_io_t> >
{
  public:
    HLS_METAPORT;
    
    base_in_tlm( const char* name=sc_gen_unique_name("stream_16X8_in") )
    {}


    template <class HLS_C>
    void operator()( HLS_C& c )
    {
        bind(c);
    }


};

template <>
class stream_16X8::base_in<CYN::TLM>
  : public stream_16X8::base_in_tlm
  , public cynw_clk_rst_facade
{
  public:
    typedef stream_16X8::base_in_tlm base_type;

    base_in( const char* name=sc_gen_unique_name("stream_16X8_base_in") )
      : base_type(name)
    {}

    template <class HLS_C>
    void operator()( HLS_C& c )
    {
        bind(c);
    }


};

template <>
class stream_16X8::in<CYN::TLM>
  : public stream_16X8::base_in_tlm
  , public sc_module
  , public cynw_clk_rst_facade
{
  public:
    typedef stream_16X8::base_in_tlm base_type;
    typedef CYN::TLM  p2p_level;
    
    in( sc_module_name name=sc_module_name( sc_gen_unique_name("stream_16X8_in") ) )
      : base_type(name)
      , sc_module(name)
      , m_read_buf( new in_param_t )
      , m_tx_stream(0), m_ws_tx_stream(0)
      , m_stream_name(std::string("sc_main.") + std::string(::sc_core::sc_get_curr_simcontext()->hierarchy_curr()->name()) + std::string(".") + std::string(name))
      , m_msg_events(0)
    {
    }

    in_param_t* m_read_buf;
        int m_r_x;
    int refl_index;
    
    template <class HLS_C>
    void operator()( HLS_C& c )
    {
        bind(c);
    }

    void reset()
    { 
	msg_event_occurred(msg_r_reset_done);
		
	while ( (*this) -> nb_can_get() ) {
	  stream_16X8::tlm_io_t val;
	  (*this) -> nb_get( val );
	}

    }

    sc_uint<5> x() const {
        return m_r_x;
    }
    
    sc_uint<5> x_new() const {
        return m_r_x ;
    }
    
    sc_uint<1> x_done() const {
        return (m_r_x == 2ULL);
    }
    
    sc_uint<1> r_x_done() const {
        return x_done();
    }
    
    sc_uint<1> done() const {
        return (m_r_x == 2ULL);
    }
    
    void set_size( int new_xsz=0 ) {
#ifndef STRATUS
      esc_report_error( esc_warning, "\n\t%s: set_size() called for an interface that does not have the Variable Limits option set.", sc_module::name() );
#endif
    }


    

    

    bool start_tx( sc_uint<1> valid_tx=true )
    {
	set_data_is_valid( valid_tx );
	        m_r_x = 0;
	m_read_buf->reset_io();
	m_use_beh_latched = false;
	tx_stream()->begin_tx();

	return data_is_valid();
    }

    void end_tx()
    {
	tx_stream()->end_tx();

    }

    int do_trim_index( int coord, int max_val )
    {
	
	if ( (sc_uint<1>) (coord < 0LL) ) {
	  coord = 0LL;
	} else {
	  if ( (sc_uint<1>) (coord > max_val) ) {
	    coord = max_val;
	  } 
	}

	  return  coord;
    }

    void get( sc_uint<8> (&in_ws)[8] )
    {
      msg_event_check(msg_r_reset_done);
      m_check_get_before_next &= ~1;
      int x_orig = m_r_x;
      int iya = 0;
      if (!(m_r_x != 0 || m_use_beh_latched)) {
          cynw_wait_while_cond( !(*this)-> nb_can_get(), (*this)-> ok_to_get() );
          delete m_read_buf;
          (*this)-> nb_get( m_read_buf );
      }
      int ix, ixb;
      ixb = (x_orig * 8);
      for ( ix=0; ix < 8; ix++ ) {
          int ixc = do_trim_index( ixb+ix, 15LL );
          in_ws[ix] = m_read_buf->P1[ixc];
      }
#ifndef STRATUS
      if ( r_x_done() ) {
          esc_report_error( esc_warning, "\n\t%s: get() called for more than %d accesses for channel 'stream_16X8'\n", sc_module::name(), 2 );
      }
#endif
      ws_tx_stream()->begin_tx();
      ws_tx_stream()->record_attrib("X", (int)x());
      
      m_r_x = (m_r_x + 1ULL);
      ws_tx_stream()->record_attrib("P1", in_ws);
      ws_tx_stream()->end_tx();
      m_data_was_valid = true;

    }

    bool poll( sc_uint<8> (&in_ws)[8] )
    {
      msg_event_check(msg_r_reset_done);
      m_check_get_before_next &= ~1;
      int x_orig = m_r_x;
      int iya = 0;
      if (!(m_r_x != 0 || m_use_beh_latched)) {
          if ( ! (*this)-> nb_can_get() ) {
              cynw_wait_if_cond( last_poll_was_now() );
              set_last_poll();
          }
          if ( (m_data_was_valid = (*this)-> nb_can_get()) ) {
              delete m_read_buf;
              (*this)-> nb_get( m_read_buf );
          } else {
              return false;
          }
      }
      int ix, ixb;
      ixb = (x_orig * 8);
      for ( ix=0; ix < 8; ix++ ) {
          int ixc = do_trim_index( ixb+ix, 15LL );
          in_ws[ix] = m_read_buf->P1[ixc];
      }
#ifndef STRATUS
      if ( r_x_done() ) {
          esc_report_error( esc_warning, "\n\t%s: poll() called for more than %d accesses for channel 'stream_16X8'\n", sc_module::name(), 2 );
      }
#endif
      ws_tx_stream()->begin_tx();
      ws_tx_stream()->record_attrib("X", (int)x());
      
      m_r_x = (m_r_x + 1ULL);
      ws_tx_stream()->record_attrib("P1", in_ws);
      ws_tx_stream()->end_tx();
      m_data_was_valid = true;

      return m_data_was_valid;
    }

    bool nb_get( sc_uint<8> (&in_ws)[8] )
    {
      msg_event_check(msg_r_reset_done);
      m_check_get_before_next &= ~1;
      int x_orig = m_r_x;
      int iya = 0;
      if (!(m_r_x != 0 || m_use_beh_latched)) {
          if ( ! (*this)-> nb_can_get() ) {
              cynw_wait_if_cond( last_poll_was_now() );
              set_last_poll();
          }
          if ( (m_data_was_valid = (*this)-> nb_can_get()) ) {
              delete m_read_buf;
              (*this)-> nb_get( m_read_buf );
          } else {
              return false;
          }
      }
      int ix, ixb;
      ixb = (x_orig * 8);
      for ( ix=0; ix < 8; ix++ ) {
          int ixc = do_trim_index( ixb+ix, 15LL );
          in_ws[ix] = m_read_buf->P1[ixc];
      }
#ifndef STRATUS
      if ( r_x_done() ) {
          esc_report_error( esc_warning, "\n\t%s: get() called for more than %d accesses for channel 'stream_16X8'\n", sc_module::name(), 2 );
      }
#endif
      ws_tx_stream()->begin_tx();
      ws_tx_stream()->record_attrib("X", (int)x());
      
      m_r_x = (m_r_x + 1ULL);
      ws_tx_stream()->record_attrib("P1", in_ws);
      ws_tx_stream()->end_tx();
      m_data_was_valid = true;

      return m_data_was_valid;
    }


    bool data_was_valid()
    {
	return m_data_was_valid;
    }

    bool nb_can_get()
    {
            return (m_r_x != 0 || m_use_beh_latched || (*this)-> nb_can_get());
    }

    const sc_event& ok_to_get() const
    {
      return (*this)->ok_to_get();
    }

    void get_start( bool busy_val=false )
    {
      if (!busy_val)
      {
	m_data_was_valid = false;
	      }
    }

    void get_end()
    {
    }

    void latch_value( bool do_latch=true )
    {
      m_data_was_valid = (m_r_x != 0 || m_use_beh_latched || (*this)-> nb_can_get());
      if ( m_data_was_valid && do_latch && !m_use_beh_latched )
      {
	m_use_beh_latched = true;
      	delete m_read_buf;
	(*this)->nb_get( m_read_buf );
      }
    }

    void set_state( unsigned which, unsigned value )
    {
      switch (which) {
	case CYNW_SET_DATA_WAS_VALID  :
	  m_data_was_valid = value;
	  break;
	default:
	  break;
      }
    }

    bool last_poll_was_now()
    {
      return (last_poll_time() == sc_time_stamp().to_double());
    }
    double last_poll_time()
    {
      return m_last_poll_time;
    }
    void set_last_poll()
    {
      m_last_poll_time = sc_time_stamp().to_double();
    }
    void clear_last_poll()
    {
      m_last_poll_time = -1.0;
    }

    double m_last_poll_time;
    bool m_data_was_valid;
    bool m_use_beh_latched;

    void enable_dpopt( double md=HLS_CALC_TIMING )
    {}

    bool data_is_valid()
    {
      return m_read_valid_tx;
    }

    void set_data_is_valid( sc_uint<1> valid_tx )
    {
            m_read_valid_tx = valid_tx;;
    }

    sc_uint<1> m_read_valid_tx;

    
    cynw_scv_tx_stream* tx_stream()
    {
#if !STRATUS
      if (m_tx_stream == 0) {
        esc_enable_scv_logging();
        m_tx_stream = new cynw_scv_tx_stream( (m_stream_name + "_r").c_str(), esc_get_scv_tr_db(), "reader_tx" );
      }
      return m_tx_stream;
#else
      return 0;
#endif
    }
    
    cynw_scv_tx_stream* ws_tx_stream()
    {
#if !STRATUS
      if (m_ws_tx_stream == 0) {
        esc_enable_scv_logging();
        m_ws_tx_stream = new cynw_scv_tx_stream( (m_stream_name + "_r" + "_ws").c_str(), esc_get_scv_tr_db(), "reader_ws" );
      }
      return m_ws_tx_stream;
#else
      return 0;
#endif
    }
    
    cynw_scv_tx_stream* m_tx_stream;
    cynw_scv_tx_stream* m_ws_tx_stream;
    int m_alg_base;

    std::string m_stream_name;
    sc_uint<2> m_check_get_before_next;
    unsigned m_msg_events;
    enum msg_event_t { msg_r_reset_done=0, msg_w_reset_done=1, msg_num_codes=2 } ;
    
    void msg_event_occurred( msg_event_t msg ) {
        #ifndef STRATUS
        m_msg_events |= (1 << msg);
        #endif
    }
    void msg_event_check( msg_event_t msg ) {
        #ifndef STRATUS
        if ( (m_msg_events & (1 << msg)) == 0 ) {
            switch (msg) {
                case msg_r_reset_done:    
                    esc_report_error( esc_warning, "\n\t%s: Missing reset() call for reader side of stream interface.\n", sc_module::name() );
                    break;
                case msg_w_reset_done:    
                    esc_report_error( esc_warning, "\n\t%s: Missing reset() call for writer side of stream interface.\n", sc_module::name() );
                    break;
                default:
                    break;
            }
            m_msg_events |= (1 << (msg + msg_num_codes));
        }
        msg_event_occurred(msg);
        #endif
    }

};

class stream_16X8::base_out_tlm
    : public sc_port< tlm::tlm_fifo_put_if<tlm_io_t> >
{
  public:
    HLS_METAPORT;
    
    base_out_tlm( const char* name=sc_gen_unique_name("stream_16X8_out") )
    {}


    template <class HLS_C>
    void operator()( HLS_C& c )
    {
        bind(c);
    }

};

template <>
class stream_16X8::base_out<CYN::TLM>
  : public stream_16X8::base_out_tlm
  , public cynw_clk_rst_facade
{
  public:
    typedef stream_16X8::base_out_tlm base_type;
    
    base_out( const char* name=sc_gen_unique_name("stream_16X8_base_out") )
      : base_type(name)
    {
    }

    template <class HLS_C>
    void operator()( HLS_C& c )
    {
        bind(c);
    }

};

template <>
class stream_16X8::out<CYN::TLM>
  : public stream_16X8::base_out_tlm
  , public sc_module
  , public cynw_clk_rst_facade
{
  public:

    typedef stream_16X8::base_out_tlm base_type;
    
    in_param_t* m_write_buf;
        int m_w_x;

    out( sc_module_name name=sc_module_name(sc_gen_unique_name("stream_16X8_out") ) )
      : base_type(name)
      , sc_module(name)
      , m_write_buf( new in_param_t )
      , m_stream_name(std::string("sc_main.") + std::string(::sc_core::sc_get_curr_simcontext()->hierarchy_curr()->name()) + std::string(".") + std::string(name))
      , m_msg_events(0)
    {
    }

    template <class HLS_C>
    void operator()( HLS_C& c )
    {
        bind(c);
    }

    void reset()
    { 
	msg_event_occurred(msg_w_reset_done);
    }

    sc_uint<5> x() const {
        return m_w_x;
    }
    
    sc_uint<1> x_done() const {
        return (m_w_x == 4ULL);
    }
    
    sc_uint<1> w_x_done() const {
        return x_done();
    }
    
    sc_uint<1> done() const {
        return (m_w_x == 4ULL);
    }
    
    void set_size( int new_xsz=0 ) {
#ifndef STRATUS
      esc_report_error( esc_warning, "\n\t%s: set_size() called for an interface that does not have the Variable Limits option set.", sc_module::name() );
#endif
    }


    void start_tx( sc_uint<1> valid_tx=true )
    {
	set_data_is_valid( valid_tx );
	        m_w_x = 0;
	m_write_buf->reset_io();
	tx_stream()->begin_tx();

    }

    void end_tx()
    {
            cynw_wait_while_cond( !(*this)-> nb_can_put(), (*this)-> ok_to_put() );
            (*this)-> nb_put( m_write_buf );
            m_write_buf = new in_param_t;

	tx_stream()->end_tx();

    }

    void put( sc_uint<8> (&out_ws)[4] )
    {
      msg_event_check(msg_w_reset_done);
      if (m_w_x <= 3LL) {
          int ix;
          for ( ix=0; ix < 4; ix++ ) {
              m_write_buf->P1[(m_w_x * 4) + ix] = out_ws[ix];
          }
      } else {
          esc_report_error( esc_warning, "\n\t%s: put() called too many times for parameter 'P1' in channel 'stream_16X8'\n", sc_module::name() );
      }
      ws_tx_stream()->begin_tx();
      ws_tx_stream()->record_attrib("X", (int)x());
      ws_tx_stream()->record_attrib("P1", out_ws);
      ws_tx_stream()->end_tx();
      
      m_w_x = (m_w_x + 1ULL);

    }

    bool data_is_valid()
    {
      return m_write_valid_tx;
    }

    void set_data_is_valid( sc_uint<1> valid_tx )
    {
      m_write_valid_tx = valid_tx;;
    }

    sc_uint<1> m_write_valid_tx;

    
    cynw_scv_tx_stream* tx_stream()
    {
#if !STRATUS
      if (m_tx_stream == 0) {
        esc_enable_scv_logging();
        m_tx_stream = new cynw_scv_tx_stream( (m_stream_name + "_w").c_str(), esc_get_scv_tr_db(), "writer_tx" );
      }
      return m_tx_stream;
#else
      return 0;
#endif
    }
    
    cynw_scv_tx_stream* ws_tx_stream()
    {
#if !STRATUS
      if (m_ws_tx_stream == 0) {
        esc_enable_scv_logging();
        m_ws_tx_stream = new cynw_scv_tx_stream( (m_stream_name + "_w" + "_ws").c_str(), esc_get_scv_tr_db(), "writer_ws" );
      }
      return m_ws_tx_stream;
#else
      return 0;
#endif
    }
    
    cynw_scv_tx_stream* m_tx_stream;
    cynw_scv_tx_stream* m_ws_tx_stream;
    int m_alg_base;

    std::string m_stream_name;
    unsigned m_msg_events;
    enum msg_event_t { msg_r_reset_done=0, msg_w_reset_done=1, msg_num_codes=2 } ;
    
    void msg_event_occurred( msg_event_t msg ) {
        #ifndef STRATUS
        m_msg_events |= (1 << msg);
        #endif
    }
    void msg_event_check( msg_event_t msg ) {
        #ifndef STRATUS
        if ( (m_msg_events & (1 << msg)) == 0 ) {
            switch (msg) {
                case msg_r_reset_done:    
                    esc_report_error( esc_warning, "\n\t%s: Missing reset() call for reader side of stream interface.\n", sc_module::name() );
                    break;
                case msg_w_reset_done:    
                    esc_report_error( esc_warning, "\n\t%s: Missing reset() call for writer side of stream interface.\n", sc_module::name() );
                    break;
                default:
                    break;
            }
            m_msg_events |= (1 << (msg + msg_num_codes));
        }
        msg_event_occurred(msg);
        #endif
    }

};

#endif

#endif

