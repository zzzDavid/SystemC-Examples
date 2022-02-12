#ifndef _SYSTEM_H_
#define _SYSTEM_H_
#include <systemc.h>
#include <esc.h>
#include <stratus_hls.h>
#include <cynw_p2p.h>
#include "tb.h"
#include "dut_wrap.h"
SC_MODULE(System)
{
  sc_clock clk_sig;
  sc_signal<bool> rst_sig;
  sc_signal<bool> finish;
  
  sc_int<32> A[10];
  sc_int<32> B[10];
  sc_int<32> D[10];

  dut_wrapper *m_dut;
  tb *m_tb;
  SC_CTOR(System)
  : clk_sig("clk_sig", CLOCK_PERIOD, SC_NS)
  , rst_sig("rst_sig")
  , finish("finish")
  {
    m_dut = new dut_wrapper("dut_wrapper", A, B, D);
    m_dut->clk(clk_sig);
    m_dut->rst(rst_sig);
    m_dut->finish(finish);

    m_tb = new tb("tb", A, B, D);
    m_tb->clk(clk_sig);
    m_tb->rst(rst_sig);
    m_tb->finish(finish);

  }

  ~System()
  {
    delete m_tb;
    delete m_dut;
  }
};

#endif // _SYSTEM_H_