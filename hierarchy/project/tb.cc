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


  // Generate reset signal
  rst.write(0);
  wait(2);
  rst.write(1);
  wait();

  // read p2p ports from shared_memory
  sc_int<32> *A_arg = (sc_int<32> *)shmat(163871, nullptr, 0);
  for (unsigned i = 0; i < 10; i++) {
    A[i] = A_arg[i];
  }
  sc_int<32> *B_arg = (sc_int<32> *)shmat(163872, nullptr, 0);
  for (unsigned i = 0; i < 10; i++) {
    B[i] = B_arg[i];
  }  
  sc_int<32> *D_arg = (sc_int<32> *)shmat(163873, nullptr, 0);
  for (unsigned i = 0; i < 10; i++) {
    D[i] = D_arg[i];
  }
  // read off-chip memories from shared memory

  std::cout << "Off-chip memory initialization done\n";

  // Write input P2P ports
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
