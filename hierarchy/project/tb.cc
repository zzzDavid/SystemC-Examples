#include "tb.h"
#include <sys/ipc.h>
#include <sys/shm.h>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <getopt.h>
#include <esc.h>
#include <iostream>
#include <string>

void tb::source() {
  std::cout << "Testbench source thread starts\n";

  // P2P port reset
  B.reset();
  D.reset();

  // Generate reset signal
  rst.write(0);
  wait(2);
  rst.write(1);
  wait();

  // read p2p ports from shared_memory
  sc_int<32> *B_arg = (sc_int<32> *)shmat(163872, nullptr, 0);
  sc_int<32> B_ = B_arg[0];
  sc_int<32> *D_arg = (sc_int<32> *)shmat(163873, nullptr, 0);
  sc_int<32> D_ = D_arg[0];

  // read off-chip memories from shared memory

  std::cout << "Off-chip memory initialization done\n";

  // Write input P2P ports
  B.put(B_);
  D.put(D_);
}

void tb::sink() {
  std::cout << "Testbench sink thread starts\n";
  wait(); // wait for reset signal
  std::cout << "Testbench sink thread wait done\n";
  do {wait();} while (!finish.read());

  // Copy off-chip memories back to shared memory
  std::cout << "Testbench normal turn off.\n";
  esc_stop();
}
