#ifndef TB_H
#define TB_H
#include <cynw_p2p.h>
SC_MODULE(tb)
{
  sc_in<bool>	clk;
  sc_out<bool>	rst;
  sc_in<bool>	finish;

  // p2p ports
  cynw_p2p<sc_int<32>>::base_out	B;
  cynw_p2p<sc_int<32>>::base_in	D;

  // memories

  SC_HAS_PROCESS(tb);
  tb( sc_module_name name)
  : clk("clk")
  , rst("rst")
  , finish("finish")
  , B("B")
  , D("D")
  {
    SC_CTHREAD(source, clk.pos());
    SC_CTHREAD(sink, clk.pos());
  }

  void source();
  void sink();
};

#endif // TB_H