///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2017 Cadence Design Systems, Inc. All rights reserved worldwide.
//
// The code contained herein is the proprietary and confidential information
// of Cadence or its licensors, and is supplied subject to a previously
// executed license and maintenance agreement between Cadence and customer.
// This code is intended for use with Cadence high-level synthesis tools and
// may not be used with other high-level synthesis tools. Permission is only
// granted to distribute the code as indicated. Cadence grants permission for
// customer to distribute a copy of this code to any partner to aid in designing
// or verifying the customer's intellectual property, as long as such
// distribution includes a restriction of no additional distributions from the
// partner, unless the partner receives permission directly from Cadence.
//
// ALL CODE FURNISHED BY CADENCE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
// KIND, AND CADENCE SPECIFICALLY DISCLAIMS ANY WARRANTY OF NONINFRINGEMENT,
// FITNESS FOR A PARTICULAR PURPOSE OR MERCHANTABILITY. CADENCE SHALL NOT BE
// LIABLE FOR ANY COSTS OF PROCUREMENT OF SUBSTITUTES, LOSS OF PROFITS,
// INTERRUPTION OF BUSINESS, OR FOR ANY OTHER SPECIAL, CONSEQUENTIAL OR
// INCIDENTAL DAMAGES, HOWEVER CAUSED, WHETHER FOR BREACH OF WARRANTY,
// CONTRACT, TORT, NEGLIGENCE, STRICT LIABILITY OR OTHERWISE.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _DIRECTIVES_H_
#define _DIRECTIVES_H_

// This file defines macros that are used as synthesis directives in the DUT
// module. For specific HLS configs (UNROLL_FILL and UNROLL_ALL), the macros are 
// defined as either HLS_UNROLL_LOOP directives, or defined as nothing.
// For any other HLS configs, #ifndefs are used to define the macros as nothing.


// Define a group of macros for each configuration
#ifdef UNROLL_FILL
#   define FILL_LOOP  HLS_UNROLL_LOOP( ON, "fill loop" )
#   define SHIFT_LOOP
#   define SUM_LOOP
#endif

#ifdef UNROLL_ALL
#   define FILL_LOOP  HLS_UNROLL_LOOP( ON, "fill loop" )
#   define SHIFT_LOOP HLS_UNROLL_LOOP( ON, "shift loop" )
#   define SUM_LOOP   HLS_UNROLL_LOOP( ON, "sum_loop")
#endif

// Define each macro as an empty string if it is not defined above
#ifndef FILL_LOOP
#   define FILL_LOOP
#endif
#ifndef SHIFT_LOOP
#   define SHIFT_LOOP
#endif
#ifndef SUM_LOOP
#   define SUM_LOOP
#endif

#endif // _DIRECTIVES_H_
