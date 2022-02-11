#include <cynw_p2p.h>
SC_MODULE(find_max) 
{
  sc_in<bool> clk;
  sc_in<bool> rst;
  // port definitions
  cynw_p2p < sc_int<32> >::in	_top_find_max_A;
  cynw_p2p < sc_int<32> >::in	_top_find_max_B;
  cynw_p2p < sc_int<32> >::in	_top_find_max_x;

  // submodule instantiations
  add_one	add_one_inst;
  cynw_p2p < sc_int<32> >	add_one__top_find_max_A;
  cynw_p2p < sc_int<32> >	add_one__top_find_max_x;

  void thread1();

  SC_HAS_PROCESS(find_max);
  find_max(sc_module_name name)
  : clk( "clk" )
  , rst( "rst" )
  , _top_find_max_A( "_top_find_max_A" )
  , _top_find_max_B( "_top_find_max_B" )
  , _top_find_max_x( "_top_find_max_x" )
  {
    SC_CTHREAD(thread1, clk.pos());
    reset_signal_is(rst, 0);
    _top_find_max_A.clk_rst(clk, rst);
    _top_find_max_B.clk_rst(clk, rst);
    _top_find_max_x.clk_rst(clk, rst);

    // add_one
    add_one_inst._top_add_one_A(add_one__top_find_max_A);
    add_one_inst._top_add_one_x(add_one__top_find_max_x);
    add_one_inst.clk(clk);
    add_one_inst.rst(rst);
  }

};

