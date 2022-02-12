#include "add_one.h"
void add_one::thread1()
{
  {
    HLS_DEFINE_PROTOCOL("reset");
    add_one_x.reset();
    add_one_return.reset(); // BUG
    wait();
  }
  while( true ) 
  {
    // BUG
    sc_int<32> x = add_one_x.get();
    // return (    value + 1);
    add_one_return.put(A[x] + 1);
  }
}
