#include <cynw_p2p.h>
SC_MODULE(dut) 
{
  sc_in<bool> clk;
  sc_in<bool> rst;
  sc_out<bool> finish;

  // port definitions
  cynw_p2p < sc_uint<32> >::in	M;

  sc_uint<32> *A;
  sc_uint<32>	*alloc_A_b;
  sc_uint<32> *omega;

  sc_uint<32> size;
  sc_uint<32> half;
  sc_uint<32> step;
  sc_uint<32> k;
  sc_uint<32> e;
  sc_uint<32> l;
  sc_uint<32> r;
  sc_uint<32> t1;
  sc_uint<32> t2;
  sc_uint<64> m;
  sc_uint<33> m_;
  sc_uint<34> m__;

  void thread1();

  SC_HAS_PROCESS(dut);
  dut(sc_module_name dut, sc_uint<32> _A[8], sc_uint<32> _omega[4], sc_uint<32> _alloc_A_b[8])
  : clk( "clk" )
  , rst( "rst" )
  , M( "M" )
  , A(_A)
  , omega(_omega)
  , alloc_A_b(_alloc_A_b)
  {
    SC_CTHREAD(thread1, clk.pos());
    reset_signal_is(rst, 0);
    M.clk_rst(clk, rst);
  }
};

