
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


// Generated by bdw_memgen 17.20-p100
// Tue Nov 17 13:57:35 EST 2020

#if defined STRATUS  &&  ! defined CYN_DONT_SUPPRESS_MSGS
#pragma cyn_suppress_msgs NOTE
#endif	// STRATUS  &&  CYN_DONT_SUPPRESS_MSGS
#include "RAM_64x8.h"
 
#ifdef STRATUS_HLS
   sc_uint<8> RAM_64x8::read0(sc_uint<6> A0, bool WE0) {
      sc_uint<8> DOUT0;
      CYN_BIND(WE0,this->WE0);
      CYN_BIND(A0,this->A0);
      CYN_BIND(DOUT0,this->DOUT0);
      HLS_CONFIG_INSTRUCTION( "access_port", 1 );
      DOUT0 = mem[A0];
      return DOUT0;
   }

#endif	// STRATUS_HLS
#ifdef STRATUS_HLS
   sc_uint<8> RAM_64x8::write0(sc_uint<6> A0, sc_uint<8> DIN0, bool WE0) {

      CYN_BIND(WE0,this->WE0);
      CYN_BIND(A0,this->A0);
      CYN_BIND(DIN0,this->DIN0);
      HLS_CONFIG_INSTRUCTION( "access_port", 1 );
      mem[A0] = DIN0;
      return DIN0;
   }

#endif	// STRATUS_HLS
#ifdef STRATUS_HLS
   void RAM_64x8::nop0(bool WE0) {
      CYN_BIND(WE0,this->WE0);
      HLS_CONFIG_INSTRUCTION( "access_port", 1 );
   }

#endif	// STRATUS_HLS
   void RAM_64x8::thread0() {
#if defined(__GNUC__) && BDW_USE_SCV
    if ( m_p1_tx_0.is_active() ) {
        m_p1_tx_stream->end_tx( m_p1_tx_0, DOUT0.read() );
    }
#endif
#if defined(__GNUC__)
      // Perform an address range check to prevent crashes on out of bounds
      // accesses in SystemC behavioral simulations.
      if((int)(A0.read()) <= 63) {
#endif
        if(WE0.read() == 0) {

#if defined(__GNUC__) && BDW_USE_SCV
            m_p1_tx_0 = m_p1_tx_stream->begin_write_tx( A0.read(), DIN0.read() );
#endif

#if defined(__GNUC__) && defined(BDW_TRACE_MEMS)
        fprintf(stderr,"TRACE: %s%s: %s: write 0x%s to 0x%x\n", name(), "", sc_time_stamp().to_string().c_str(), DIN0.read().to_string(SC_HEX).c_str(), (int)A0.read().to_uint());
#endif
        mem[A0.read().to_uint()] = DIN0.read();
#if defined(__GNUC__)
            sync_put(A0.read().to_uint());
#endif
        } else {

#if defined(__GNUC__) 
#if BDW_USE_SCV
            m_p1_tx_0 = m_p1_tx_stream->begin_read_tx( A0.read() );
#endif
            sync_get(A0.read().to_uint());
#endif

#if defined(__GNUC__) && defined(BDW_TRACE_MEMS)
        fprintf(stderr,"TRACE: %s: %s: read 0x%s from 0x%x\n", name(), sc_time_stamp().to_string().c_str(), mem[A0.read().to_uint()].to_string(SC_HEX).c_str(), (int)A0.read().to_uint());
#endif
        DOUT0 = mem[A0.read().to_uint()];
        }

#if defined(__GNUC__)
      }
#endif
  }
#if defined(STRATUS_VLG)
   RAM_64x8::RAM_64x8(const sc_module_name name)
      : sc_module( name ) ,CLK("CLK"),WE0("WE0"),DIN0("DIN0"),DOUT0("DOUT0"),A0("A0"), mem()
#else
   RAM_64x8::RAM_64x8( sc_module_name name)
      : sc_module( name ) ,CLK("CLK"),WE0("WE0"),DIN0("DIN0"),DOUT0("DOUT0"),A0("A0"), mem() 
#if defined(__GNUC__) 
		, m_iface(0)
#endif
#endif
   {
#ifdef STRATUS_HLS
      SC_CTHREAD( thread0, (CLK).pos() );
#else
      SC_METHOD( thread0 );
      sensitive << (CLK).pos();

#endif
#ifndef STRATUS_HLS
      dont_initialize();
#endif
#if defined(__GNUC__) && BDW_USE_SCV
    esc_enable_scv_logging();
    m_p1_tx_stream = new cynw_scv_memory_tx_stream< sc_uint<6>, sc_uint<8> >( (std::string("sc_main.") + std::string(this->name())).c_str(), esc_get_scv_tr_db() );
#endif
 
   }

const unsigned long RAM_64x8::implemented = 1;
const unsigned long RAM_64x8::pipelined = 1;
const float RAM_64x8::area = 4000.0000;
const float RAM_64x8::delay = 0.2000;
const float RAM_64x8::setup_time = 0.2000;
const unsigned long RAM_64x8::latency_WE0 = 1;
const unsigned long RAM_64x8::latency_DIN0 = 1;
const unsigned long RAM_64x8::latency_A0 = 1;
const unsigned long RAM_64x8::bits_per_maskbit_WM0 = 0;
const unsigned long RAM_64x8::reg_mem_inputs = 0;
const unsigned long RAM_64x8::reg_mem_outputs = 0;
const unsigned long RAM_64x8::regs_at_mem_inputs = 0;
const unsigned long RAM_64x8::regs_at_mem_outputs = 0;
const unsigned long RAM_64x8::no_spec_reads = 1;
const unsigned long RAM_64x8::is_mem = 1;
const unsigned long RAM_64x8::clock_multiplier = 0;
const bool RAM_64x8::has_extra_ports = false;
 