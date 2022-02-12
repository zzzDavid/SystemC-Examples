#include <cynw_p2p.h>
SC_MODULE(add_one) 
{
  sc_in<bool> clk;
  sc_in<bool> rst;
  sc_int<32> *A;
  // port definitions
  cynw_p2p < sc_int<32> >::in add_one_x;
  // BUG
  cynw_p2p < sc_int<32> >::out	add_one_return;


  void thread1();

  SC_HAS_PROCESS(add_one);
  add_one(sc_module_name name, sc_int<32> _A[10])
  : clk( "clk" )
  , rst( "rst" )
  , add_one_x( "_top_add_one_x" )
  , add_one_return( "_top_add_one_return" ) // BUG
  , A(_A)
  {
    SC_CTHREAD(thread1, clk.pos());
    reset_signal_is(rst, 0);
    add_one_x.clk_rst(clk, rst);
    add_one_return.clk_rst(clk, rst);
  }

};

