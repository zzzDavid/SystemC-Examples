#ifndef TB_H
#define TB_H
#include <cynw_p2p.h>
SC_MODULE(tb)
{
  sc_in<bool>	clk;
  sc_out<bool>	rst;
  sc_in<bool>	finish;

  sc_int<32> *A;
  sc_int<32> *B;
  sc_int<32> *D;

  // memories

  SC_HAS_PROCESS(tb);
  tb( sc_module_name name, sc_int<32> _A[10], sc_int<32> _B[10], sc_int<32> _D[10])
  : clk("clk")
  , rst("rst")
  , finish("finish")
  , A(_A)
  , B(_B)
  , D(_D)
  {
    SC_CTHREAD(source, clk.pos());
    SC_CTHREAD(sink, clk.pos());
  }

  void source();
  void sink();
};

#endif // TB_H