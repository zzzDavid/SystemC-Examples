//**************************************************
// Copyright 2015 Cadence Design Systems, Inc.
// All Rights Reserved.
//
//**************************************************


Stratus Training Lab: Loop Pipelining

This directory contains a complete Stratus training lab
project. It defines a synthesizable DUT module and a testbench in
SystemC.

The calculations have a long latency. In an un-pipelined main loop,
the DUT will receive one input struct, perform all the calculations,
and produce the output value before receiving the next input. This
means that the throughput of the DUT is 1 input/output per N cycles,
where N is the amount of time taken for the calculations.

When the main loop is pipelined, with a given initiation interval
(II), multiple data sets can be in processing at the same time. The
DUT will be ready to receive one input per II cycles, and produce one
output per II cycles. 

Files in the project:

project.tcl	Stratus project configuration file.
Makefile	Main makefile.
defines.h	The file that defines the data structure being passed
		from the TB to the DUT.
directives.h	The file that defines synthesis directives.
main.cc		Defines sc_main, the SystemC-required "main" function.
system.h	Defines the top-level System module.
dut.h/dut.cc	Defines the DUT module.
tb.h/tb.cc	Defines the testbench module.
golden.out	The golden results, used for checking each simulation.

Lab Instructions
----------------

Exercise 1: Loop Pipelining
---------------------------

% cd <training_install_dir>/lab_pipelining (this directory)
% stratus_ide &

1. Add several HLS configs to the project.tcl file, each for a
different initiation interval:

	    II1 -DII=1
            II2 -DII=2
	    II3 -DII=3

Each HLS config defines a macro II with different values. The II
macro will be used in the source code. 

2. Add the corresponding sim configs to the project.tcl file:

define_sim_config II1_V {dut RTL_V II1}
define_sim_config II2_V {dut RTL_V II2}
define_sim_config II3_V {dut RTL_V II3}

3. Synthesize and simulate these simConfigs:

B
ORIG_V

These are the behavioral and non-pipelined simulations. They will
complete successfully. Now simulate these sim configs:

II1_V 
II2_V 
II3_V 

These are the pipelined simulations. All of the pipelined simulations
fail!

Note that the simulations were stopped by the TB source thread. The TB
source thread sent 16 values, and then stopped sending more data. It
stopped the simulation after another 1000 cycles. The results file
contains fewer values than the expected 16. Both symptoms indicate
that the TB sink thread is still waiting for a value from the DUT. The
simulations fail because the pipeline is stalled, waiting for
input. This particular stall is a hard stall, meaning the entire
pipeline is frozen.

(See the training slides for a discussion on hard and soft pipeline
stalls.)

5. We will turn the hard stall into a soft stall that allows the
pipeline to drain (finish calculations on the data values already in
the pipeline to drain out).

This is done in the next lab exercise lab_pipelining_soft_stall.
