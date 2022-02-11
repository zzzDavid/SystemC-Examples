#include "find_max.h"
void find_max::thread1()
{
  {
    HLS_DEFINE_PROTOCOL("reset");
    _top_find_max_A.reset();
    _top_find_max_B.reset();
    _top_find_max_x.reset();
    wait();
  }
  while( true ) 
  {
            if (_top_find_max_B.get() < _top_find_max_A.get()) {
      return add_one(_top_find_max_A, _top_find_max_x);
    } else {
      return       _top_find_max_B.get();
    }
  }
}
