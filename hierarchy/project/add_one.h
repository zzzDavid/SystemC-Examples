#include <cynw_p2p.h>
SC_MODULE(add_one) 
{
  sc_in<bool> clk;
  sc_in<bool> rst;
  // port definitions
  cynw_p2p < sc_int<32> >::in	_top_add_one_A;
  cynw_p2p < sc_int<32> >::in	_top_add_one_x;


  void thread1();

  SC_HAS_PROCESS(add_one);
  add_one(sc_module_name name)
  : clk( "clk" )
  , rst( "rst" )
  , _top_add_one_A( "_top_add_one_A" )
  , _top_add_one_x( "_top_add_one_x" )
  {
    SC_CTHREAD(thread1, clk.pos());
    reset_signal_is(rst, 0);
    _top_add_one_A.clk_rst(clk, rst);
    _top_add_one_x.clk_rst(clk, rst);
  }

};

