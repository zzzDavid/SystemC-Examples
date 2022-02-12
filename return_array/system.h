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

  // memories
  sc_uint<32> A[8];
  sc_uint<32> omega[4];
  sc_uint<32> alloc_A_b[8];
  // channels
  cynw_p2p<sc_uint<32>> M;
  // modules
  dut_wrapper *m_dut;
  tb *m_tb;

  SC_CTOR(System)
  : clk_sig("clk_sig", CLOCK_PERIOD, SC_NS)
  , rst_sig("rst_sig")
  , M("M")  
  , finish("finish")
  {
    m_dut = new dut_wrapper("dut_wrapper", A, omega, alloc_A_b);
    m_dut->clk(clk_sig);
    m_dut->rst(rst_sig);
    m_dut->M(M);
    m_dut->finish(finish);

    m_tb = new tb("tb", A, omega, alloc_A_b);
    m_tb->clk(clk_sig);
    m_tb->rst(rst_sig);
    m_tb->M(M);
    m_tb->finish(finish);
  }

  ~System()
  {
    delete m_tb;
    delete m_dut;
  }
};

#endif // _SYSTEM_H_