#include <cynw_p2p.h>
#include "add_one_wrap.h" // BUG
SC_MODULE(find_max) 
{
  sc_in<bool> clk;
  sc_in<bool> rst;
  // port definitions
  cynw_p2p < sc_int<32> >::in	find_max_x;
  cynw_p2p < sc_int<32> >::out	find_max_return; // BUG

  cynw_p2p <sc_int<32>>::out add_one_x_out;
  cynw_p2p <sc_int<32>>::in add_one_return_in;


  sc_int<32> *A;
  sc_int<32> *B;

  // submodule instantiations
  add_one_wrapper *add_one_inst = new add_one_wrapper("add_one", A); // BUG
  cynw_p2p < sc_int<32> >	add_one_x;
  cynw_p2p < sc_int<32> >	add_one_return; // BUG

  void thread1();

  SC_HAS_PROCESS(find_max);
  find_max(sc_module_name name, sc_int<32> _A[10], sc_int<32> _B[10])
  : clk( "clk" )
  , rst( "rst" )
  , add_one_x( "add_one_x" )
  , add_one_return( "add_one_return" )
  , A(_A)
  , B(_B)
  {
    SC_CTHREAD(thread1, clk.pos());
    reset_signal_is(rst, 0);
    find_max_x.clk_rst(clk, rst);
    find_max_return.clk_rst(clk, rst);
    this->add_one_x_out(add_one_x);
    this->add_one_return_in(add_one_return);

    // add_one
    add_one_inst->add_one_x(add_one_x);
    add_one_inst->add_one_return(add_one_return);
    add_one_inst->clk(clk);
    add_one_inst->rst(rst);
  }

};

