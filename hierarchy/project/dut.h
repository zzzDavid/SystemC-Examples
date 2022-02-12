#include <cynw_p2p.h>
#include "find_max_wrap.h" // BUG
SC_MODULE(dut) 
{
  sc_in<bool> clk;
  sc_in<bool> rst;
  sc_out<bool> finish;

  // port definitions
  sc_int<32>	*A;
  sc_int<32>	*B;
  sc_int<32>	*D;

  // submodule instantiations
  find_max_wrapper *find_max_inst	= new find_max_wrapper("find_max", A, B); // BUG
  // channels
  cynw_p2p < sc_int<32> >::chan	find_max_x_channel;
  cynw_p2p < sc_int<32> >::chan	find_max_return_channel;
  // ports
  cynw_p2p < sc_int<32> >::out find_max_x_out;
  cynw_p2p < sc_int<32> >::in find_max_return_in;
  sc_int<32> C[10];
  sc_int<32> C_partitioned;
  sc_int<32> compute0[10];

  void thread1();

  SC_HAS_PROCESS(dut);
  dut(sc_module_name name, sc_int<32> _A[10], sc_int<32> _B[10], sc_int<32> _D[10])
  : clk( "clk" )
  , rst( "rst" )
  , find_max_x_channel("find_max_x_channel")
  , find_max_return_channel("find_max_return_channel")
  , A(_A)
  , B(_B)
  , D(_D)
  {
    SC_CTHREAD(thread1, clk.pos());
    reset_signal_is(rst, 0);
    // Ports to interface with find_max
    find_max_x_out(find_max_x_channel);
    find_max_return_in(find_max_return_channel);
    find_max_x_out.clk_rst(clk, rst);
    find_max_return_in.clk_rst(clk, rst);

    // find_max
    find_max_inst->find_max_x(find_max_x_channel);
    find_max_inst->find_max_return(find_max_return_channel);
    find_max_inst->clk(clk);
    find_max_inst->rst(rst);
    HLS_MAP_TO_REG_BANK(C);
  }

};

