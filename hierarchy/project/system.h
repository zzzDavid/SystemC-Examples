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
  cynw_p2p<sc_int<32>> B;
  cynw_p2p<sc_int<32>> D;
  dut_wrapper *m_dut;
  tb *m_tb;
  SC_CTOR(System)
  : clk_sig("clk_sig", CLOCK_PERIOD, SC_NS)
  , rst_sig("rst_sig")
  , B("B")  , D("D")  , finish("finish")
  {
    m_dut = new dut_wrapper("dut_wrapper");
    m_dut->clk(clk_sig);
    m_dut->rst(rst_sig);
    m_dut->B(B);
    m_dut->D(D);
    m_dut->finish(finish);

    m_tb = new tb("tb");
    m_tb->clk(clk_sig);
    m_tb->rst(rst_sig);
    m_tb->B(B);
    m_tb->D(D);
    m_tb->finish(finish);

  }

  ~System()
  {
    delete m_tb;
    delete m_dut;
  }
};

#endif // _SYSTEM_H_