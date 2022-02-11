#include <cynw_p2p.h>
SC_MODULE(dut) 
{
  sc_in<bool> clk;
  sc_in<bool> rst;
  sc_out<bool> finish;

  // port definitions
  sc_int<32>	A[10];
  cynw_p2p < sc_int<32> >::in	B;
  cynw_p2p < sc_int<32> >::out	D;

  // submodule instantiations
  find_max	find_max_inst;
  cynw_p2p < sc_int<32> >	find_max_A;
  cynw_p2p < sc_int<32> >	find_max_B;
  cynw_p2p < sc_int<32> >	find_max_x;
  sc_int<32> C[10];
  sc_int<32> C_partitioned;
  sc_int<32> compute0[10];

  void thread1();

  SC_HAS_PROCESS(dut);
  dut(sc_module_name name)
  : clk( "clk" )
  , rst( "rst" )
  , D( "D" )
  , B( "B" )
  {
    SC_CTHREAD(thread1, clk.pos());
    reset_signal_is(rst, 0);
    D.clk_rst(clk, rst);
    B.clk_rst(clk, rst);

    // find_max
    find_max_inst._top_find_max_A(find_max_A);
    find_max_inst._top_find_max_B(find_max_B);
    find_max_inst._top_find_max_x(find_max_x);
    find_max_inst.clk(clk);
    find_max_inst.rst(rst);
    HLS_MAP_TO_REG_BANK(C);
  }

};

