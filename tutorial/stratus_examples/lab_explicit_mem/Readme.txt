//**************************************************
// Copyright 2015 Cadence Design Systems, Inc.
// All Rights Reserved.
//
//**************************************************


This directory contains a Stratus project that implements an explicit memory
outside of a SystemC HLS module.  Instead of a local arrayed variable in the
SC_MODULE, a ::port<> memory class is used for the external memory interface.
The algorithm in the clocked thread still does array accesses using square
brackets like a regular array, i.e. mem[i] = mem[i+1].

The student will take the existing lab_array lab design and make simple
changes to replace the existing internal array with an external memory port.


