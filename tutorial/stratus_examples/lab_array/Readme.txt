#**************************************************
# Copyright 2015 Cadence Design Systems, Inc.
# All Rights Reserved.
#
#**************************************************


This directory contains an example of a Stratus project that is
appropriate for use as a template for a pipelined filter-style design 
that accesses a memory.

The example uses the cynw_p2p classes to implement the input and output
protocols. The testbench passes in a single value. The data type of the
value, in this case 8 bits, is controlled by a typedef in the defines.h file.

The dut initializes the memory, then for each input value that it gets from
the input port, it reads from that address of the memory and puts the 
resulting value out to the output port.

This design is a template that you can use to try out simple things
with Stratus. Just copy this directory and edit the "dut.cc" file
to change the functionality to what you would like to see.
