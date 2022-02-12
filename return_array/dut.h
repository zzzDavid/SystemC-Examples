#include <cynw_p2p.h>
SC_MODULE(dut) 
{
  sc_in<bool> clk;
  sc_in<bool> rst;
  sc_out<bool> finish;

  // port definitions
  cynw_p2p < sc_uint<32> >::in	A;
  cynw_p2p < sc_uint<32> >::in	omega;
  cynw_p2p < sc_uint<32> >::in	M;
  sc_uint<32>	alloc_A_b[8];

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
  dut(sc_module_name dut)
  : clk( "clk" )
  , rst( "rst" )
  , M( "M" )
  , A( "A" )
  , omega( "omega" )
  {
    SC_CTHREAD(thread1, clk.pos());
    reset_signal_is(rst, 0);
    M.clk_rst(clk, rst);
    A.clk_rst(clk, rst);
    omega.clk_rst(clk, rst);
  }

};

