//**************************************************
// Copyright 2015 Cadence Design Systems, Inc.
// All Rights Reserved.
//
//**************************************************


This directory contains an example of a Stratus project that is
appropriate for use as a template for a filter-style design that takes 
a single input and produces a single output. 

The example uses the cynw_p2p classes to implement the input and output
protocols. The testbench passes in a single value. The data type of the
value, in this case 8 bits, is controlled by a typedef in the defines.h file.

The DUT performs a trivial calculation (input_val * 7) in the function
thread1(), and outputs the result.

This design is a template that you can use to try out simple things
with Stratus. Just copy this directory and edit the "dut.cc" file
to define an algorithm you would like to synthesize.

