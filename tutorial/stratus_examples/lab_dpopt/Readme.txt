//**************************************************
// Copyright 2015 Cadence Design Systems, Inc.
// All Rights Reserved.
//
//**************************************************

Stratus HLS Training Lab: Datapath Optimization

This directory contains a complete Stratus HLS training lab
project. It defines a synthesizable DUT module and a testbench in
SystemC.

This is a modified version of the loop pipelining training lab. The
lab is designed to show the use of the Datapath Optimizer (DPOPT)
technology in Stratus.

For more details on the basic behavior of the TB/DUT, see the
pipelining lab (lab_pipelining). This lab does not involve loop
pipelining. It focuses on using the HLS_DPOPT_REGION directive to
create custom datapath components. The complex calculations in the DUT
can be optimized by using this technique.

Files in the project:

project.tcl	Stratus HLS project configuration file.
Makefile	Main makefile.
defines.h	The file that defines the data structure being passed
		from the TB to the DUT.
main.cc		Defines sc_main, the SystemC-required "main" function.
system.h	Defines the top-level System module.
dut.h/dut.cc	Defines the DUT module.
tb.h/tb.cc	Defines the testbench module.
stimulus.dat The stimulus data read by the testbench and sent to the design.
golden.dat	The golden results, used for checking each simulation.

Lab Instructions
----------------

% cd <training_install_dir>/lab_dpopt (this directory)
% stratus_ide &

1. Modify the project.tcl file to add HLS configs

# LAB EXERCISE: ADD configurations to use various --dpopt_auto options
#               and the HLS_DPOPT_REGION directive
# NEW
#define_hls_config      dut     DPO_AUTO_OP     -DLAT=3 --dpopt_auto=op
#define_hls_config      dut     DPO_AUTO_EXPR   -DLAT=3 --dpopt_auto=expr
#define_hls_config      dut     DPO_INLINE      -DLAT=2 -DDPOPT_ALL


2. Add sim_config for each HLS config:

# LAB EXERCISE: ADD a simulation configuration for each synthesis configuration
# NEW
#define_sim_config DPO_AUTO_OP_V        {dut RTL_V DPO_AUTO_OP}
#define_sim_config DPO_AUTO_EXPR_V      {dut RTL_V DPO_AUTO_EXPR}
#define_sim_config DPO_AUTO_OPEXPR_V    {dut RTL_V DPO_AUTO_OPEXPR }
#define_sim_config DPO_INLINE_V         {dut RTL_V DPO_INLINE}


3. Add the synthesis directive to the dut.cc file:

#if defined(DPO_INLINE)
            HLS_DPOPT_REGION("dpopt_part");
#endif

The HLS_DPOPT_REGION directive causes a single datapath component 
to be created for this block of code for this configuration.

The other configurations test the effect of the --dpopt_auto
command-line option. The option applies to the entire source, and
Stratus HLS selects the operations/expressions to optimize.


4. Synthesize and simulate all of the sim configs. Observe the results.

The summary hls configs table shows the effect of the
directive/option on hardware area. By default, DPOPT tries to minimize
latency, at the expense of area. This reduces the register count, but
increases the combinational area, as seen in the reports.

To look at the reported latency from the simulations, click on the
sim configs branch to open the simulation summary table. The latency
for the BASIC_V is 11 cycles, DPO_AUTO_OP_V and DPO_AUTO_EXPR_V are 
both 4 cycles, and DPO_INLINE_V (which creates the custom DPOPT part
'entirecomputation') is 3 cycles.


