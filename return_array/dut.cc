#include "dut.h"
void dut::thread1()
{
  {
    HLS_DEFINE_PROTOCOL("reset");
    M.reset();
    A.reset();
    omega.reset();
    finish.write(0);
    wait();
  }
  while( true ) 
  {
    alloc_A_b_i: for (sc_int<32> i = 0; i < 8; ++i) {
      alloc_A_b[i] = 0U;
    }
        alloc_A_b[0] = A.get();
        alloc_A_b[1] = A.get();
        alloc_A_b[2] = A.get();
        alloc_A_b[3] = A.get();
        alloc_A_b[4] = A.get();
        alloc_A_b[5] = A.get();
        alloc_A_b[6] = A.get();
        alloc_A_b[7] = A.get();
    size_x: for (sc_int<32> x = 0; x < 1; ++x) {
      size = 1U;
    }
    half_x1: for (sc_int<32> x1 = 0; x1 < 1; ++x1) {
      half = 1U;
    }
    step_x2: for (sc_int<32> x2 = 0; x2 < 1; ++x2) {
      step = 8U;
    }
    k_x3: for (sc_int<32> x3 = 0; x3 < 1; ++x3) {
      k = 0U;
    }
    e_x4: for (sc_int<32> x4 = 0; x4 < 1; ++x4) {
      e = 0U;
    }
    l_x5: for (sc_int<32> x5 = 0; x5 < 1; ++x5) {
      l = 0U;
    }
    r_x6: for (sc_int<32> x6 = 0; x6 < 1; ++x6) {
      r = 0U;
    }
    t1_x7: for (sc_int<32> x7 = 0; x7 < 1; ++x7) {
      t1 = 0U;
    }
    t2_x8: for (sc_int<32> x8 = 0; x8 < 1; ++x8) {
      t2 = 0U;
    }
    i1: for (sc_int<32> i1 = 0; i1 < 3; ++i1) {
      half = size;
      size = (size << 1);
      step = (step >> 1);
      i2: for (sc_int<32> i2 = 0; i2 < (8U / size); ++i2) {
        k = 0U;
        i3: for (sc_int<32> i3 = 0; i3 < half; ++i3) {
          l = alloc_A_b[(i3 + (((sc_int<64>)i2) * ((sc_int<64>)size)))];
          m_x9: for (sc_int<32> x9 = 0; x9 < 1; ++x9) {
                                    m = ((((sc_uint<64>)alloc_A_b[((i3 + (((sc_int<64>)i2) * ((sc_int<64>)size))) + half)]) * ((sc_uint<64>)omega.get())) % ((sc_uint<64>)M.get()));
          }
          r = ((sc_uint<32>)m);
          m_x10: for (sc_int<32> x10 = 0; x10 < 1; ++x10) {
                        m_ = ((((sc_uint<33>)l) + ((sc_uint<33>)r)) % ((sc_uint<33>)M.get()));
          }
          t1 = ((sc_uint<32>)m_);
          m_x11: for (sc_int<32> x11 = 0; x11 < 1; ++x11) {
                                    m__ = ((((sc_uint<34>)(((sc_uint<33>)M.get()) + ((sc_uint<33>)l))) - ((sc_uint<34>)r)) % ((sc_uint<34>)M.get()));
          }
          t2 = ((sc_uint<32>)m__);
          alloc_A_b[(i3 + (((sc_int<64>)i2) * ((sc_int<64>)size)))] = t1;
          alloc_A_b[((i3 + (((sc_int<64>)i2) * ((sc_int<64>)size))) + half)] = t2;
          k = ((sc_uint<32>)(((sc_uint<33>)k) + ((sc_uint<33>)step)));
        }
      }
    }
    finish.write(true);
  }
}
