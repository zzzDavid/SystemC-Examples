#include "tb.h"
#include <sys/ipc.h>
#include <sys/shm.h>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <getopt.h>
#include <esc.h>
#include <stdint.h>
#include <iostream>
#include <string>

void tb::source() {
  std::cout << "Testbench source thread starts\n";

  // P2P port reset
  M.reset();

  // Generate reset signal
  rst.write(0);
  wait(2);
  rst.write(1);
  wait();

  sc_uint<32> M_ = 17;

  // write input and output data
  for (unsigned i = 0; i < 8; i++) {
    A[i] = i;
  }
  for (unsigned i = 0; i < 4; i++) {
    omega[i] = (i+1) * 2;
  }

  std::cout << "Off-chip memory initialization done\n";

  // Write input P2P ports
  M.put(M_);
}

void tb::sink() {
  std::cout << "Testbench sink thread starts\n";
  wait(); // wait for reset signal
  std::cout << "Testbench sink thread wait done\n";
  do {wait();} while (!finish.read());

  FILE* result_p = fopen("./result.bin", "wb");
  int res[8];
  for (unsigned i = 0; i < 8; i++) {
    res[i] = (int)alloc_A_b[i];
  }
  fwrite(res, 4, 8, result_p);
  fclose(result_p);

  std::cout << "Testbench normal turn off.\n";
  esc_stop();
}
