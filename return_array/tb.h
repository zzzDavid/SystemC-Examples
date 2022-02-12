#ifndef TB_H
#define TB_H
#include <cynw_p2p.h>
SC_MODULE(tb)
{
  sc_in<bool>	clk;
  sc_out<bool>	rst;
  sc_in<bool>	finish;

  // memories
  sc_uint<32> *A;
  sc_uint<32> *omega;
  sc_uint<32> *alloc_A_b;

  // p2p ports
  cynw_p2p<sc_uint<32>>::base_out	M;

  SC_HAS_PROCESS(tb);
  tb( sc_module_name name, sc_uint<32> _A[8], sc_uint<32> _omega[4], sc_uint<32> _alloc_A_b[8])
  : clk("clk")
  , rst("rst")
  , finish("finish")
  , M("M")
  , A(_A)
  , omega(_omega)
  , alloc_A_b(_alloc_A_b)
  {
    SC_CTHREAD(source, clk.pos());
    SC_CTHREAD(sink, clk.pos());
  }

  void source();
  void sink();
};

#endif // TB_H