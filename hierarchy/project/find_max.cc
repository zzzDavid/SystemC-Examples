#include "find_max.h"
void find_max::thread1()
{
  {
    HLS_DEFINE_PROTOCOL("reset");
    find_max_x.reset();
    find_max_return.reset();
    add_one_x_out.reset();
    add_one_return_in.reset();
    wait();
  }
  while( true ) 
  {
    sc_int<32> x = find_max_x.get();
    if (B[x] < A[x]) {
      // return add_one(_top_find_max_A, _top_find_max_x);
      // BUG
      add_one_x_out.put(x);
      sc_int<32> value = add_one_return_in.get();
      find_max_return.put(value);
    } else {
      // BUG
      sc_int<32> value = B[x];
      find_max_return.put(value);
    }
  }
}
