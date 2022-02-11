//**************************************************
// Copyright 2015 Cadence Design Systems, Inc.
// All Rights Reserved.
//
//**************************************************


This directory contains a complete Stratus project. It defines a
synthesizable DUT module and a testbench in SystemC. In this project
the DUT and TB have 2 stream interfaces between them that they use to
pass a message.  The stream class is generated via the Interface
Generated. The stream objects are instantiated in the system.h
file. Ports for connecting to the streams are instantiated in the DUT
and TB.

Files in the project:

iflib           The Interface Library.
dut.h/dut.cc	Define the DUT module.
tb.h/tb.cc	Define the testbench module.
defines.h	The file that defines the data structure being passed
		from the TB to the DUT.
directives.h	The file that defines synthesis directives.
main.cc		Defines sc_main, the SystemC-required "main" function.
system.h	Defines the top-level System module.
project.tcl	Stratus project configuration file.
Makefile	Main makefile.
golden.out	The golden results, used for checking each simulation.

