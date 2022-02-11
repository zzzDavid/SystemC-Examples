#include "add_one.h"
void add_one::thread1()
{
  {
    HLS_DEFINE_PROTOCOL("reset");
    _top_add_one_A.reset();
    _top_add_one_x.reset();
    wait();
  }
  while( true ) 
  {
    return (    _top_add_one_A.get() + 1);
  }
}
