#include "dut.h"
void dut::thread1()
{
  {
    HLS_DEFINE_PROTOCOL("reset");
    finish.write(0);
    find_max_x_out.reset();
    find_max_return_in.reset();
    wait();
  }
  while( true ) 
  {
    i: for (sc_int<32> i = 0; i < 4; ++i) {
      A[(i * 2)] = (A[(i * 2)] + 1);
    }
    C_x: for (sc_int<32> x = 0; x < 10; ++x) {
      C[x] = ((sc_int<32>)(((sc_int<64>)A[x]) * ((sc_int<64>)B[x])));
    }
    compute0_x1: for (sc_int<32> x1 = 0; x1 < 10; ++x1) {
      find_max_x_out.put(x1);
      compute0[x1] = find_max_return_in.get();
    }
    D_x2: for (sc_int<32> x2 = 0; x2 < 10; ++x2) {
      D[x2] = ((sc_int<32>)(((sc_int<34>)(((sc_int<33>)C[x2]) + ((sc_int<33>)compute0[x2]))) + ((sc_int<34>)B[x2])));
    }
    finish.write(true);
  }
}
