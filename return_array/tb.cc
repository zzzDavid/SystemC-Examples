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
  A.reset();
  omega.reset();
  M.reset();

  // Generate reset signal
  rst.write(0);
  wait(2);
  rst.write(1);
  wait();

  // read p2p ports from shared_memory
  sc_uint<32> *A_arg = (sc_uint<32> *)shmat(131119, nullptr, 0);
  sc_uint<32> A_ = A_arg[0];
  sc_uint<32> *omega_arg = (sc_uint<32> *)shmat(131120, nullptr, 0);
  sc_uint<32> omega_ = omega_arg[0];
  sc_uint<32> *M_arg = (sc_uint<32> *)shmat(131121, nullptr, 0);
  sc_uint<32> M_ = M_arg[0];

  // read off-chip memories from shared memory

  std::cout << "Off-chip memory initialization done\n";

  // Write input P2P ports
  A.put(A_);
  omega.put(omega_);
  M.put(M_);
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
