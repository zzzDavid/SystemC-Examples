###############################################################################
#
# Copyright (c) 2017 Cadence Design Systems, Inc. All rights reserved worldwide.
#
# The code contained herein is the proprietary and confidential information
# of Cadence or its licensors, and is supplied subject to a previously
# executed license and maintenance agreement between Cadence and customer.
# This code is intended for use with Cadence high-level synthesis tools and
# may not be used with other high-level synthesis tools. Permission is only
# granted to distribute the code as indicated. Cadence grants permission for
# customer to distribute a copy of this code to any partner to aid in designing
# or verifying the customer's intellectual property, as long as such
# distribution includes a restriction of no additional distributions from the
# partner, unless the partner receives permission directly from Cadence.
#
# ALL CODE FURNISHED BY CADENCE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
# KIND, AND CADENCE SPECIFICALLY DISCLAIMS ANY WARRANTY OF NONINFRINGEMENT,
# FITNESS FOR A PARTICULAR PURPOSE OR MERCHANTABILITY. CADENCE SHALL NOT BE
# LIABLE FOR ANY COSTS OF PROCUREMENT OF SUBSTITUTES, LOSS OF PROFITS,
# INTERRUPTION OF BUSINESS, OR FOR ANY OTHER SPECIAL, CONSEQUENTIAL OR
# INCIDENTAL DAMAGES, HOWEVER CAUSED, WHETHER FOR BREACH OF WARRANTY,
# CONTRACT, TORT, NEGLIGENCE, STRICT LIABILITY OR OTHERWISE.
#
################################################################################

#
# Makefile - top-level project makefile
#
# list subdirectories that contain memory libraries
# (must be in subdirectories of the current directory)
MEMLIBS =

# list subdirectories that contain interface libraries
# (must be in subdirectories of the current directory)
IFLIBS =

# Uncomment this line to use the Insight debugger
BDW_DEBUG = 1

# The cmp_result target compares the simulation results with the
# golden results. The testbench writes out the results file (data.out)
# in the simulation configuration directory. The cmp_result target is
# automatically run at the end of each simulation. (See the
# endOfSimCommand definition in the project.tcl file.)

GOLD_FILE = golden.dat
RESULTS_FILE = $(BDW_SIM_CONFIG_DIR)/response.dat

cmp_result:
	@if [ -f $(RESULTS_FILE) ] ; then \
	  echo "****************************************" ; \
	  echo `date` ; \
	  echo "Performing Simulation Results Comparison" ; \
	  echo "for $(BDW_SIM_CONFIG) Simulation..." ; \
	  if diff $(RESULTS_FILE) $(GOLD_FILE) ; then \
	    echo "  $(BDW_SIM_CONFIG): SIMULATION PASSED" ; \
	    bdw_sim_pass ; \
	  else \
	    echo "  $(BDW_SIM_CONFIG): SIMULATION FAILED" ; \
	    bdw_sim_fail ; \
	  fi ; \
	  echo "****************************************" ; \
	else \
	  echo "****************************************" ; \
	  echo `date` ; \
	  echo "ERROR: Simulation output doesn't exist" ; \
	  echo "for $(BDW_SIM_CONFIG) Simulation..." ; \
	  echo "  $(BDW_SIM_CONFIG): SIMULATION FAILED" ; \
	  bdw_sim_fail ; \
	  echo "****************************************" ; \
	fi

basicTest:
	make sim_BASIC_CA

-include Makefile.prj

Makefile.prj : project.tcl
	@bdw_makegen

# Clean out undesirable junk files from the project directory
# Uses the automatically created clean_all target from Makefile.prj
clean: clean_all clean_libs
	@rm -f transcript vsim* *.wlf data.out
	@rm -f *~ *.bak *.BAK 
	@rm -rf work debussy* vfast*
	@rm -f Makefile.prj .log*
	@rm -f msg_help.html
	@rm -rf core  *.pro *.user
	@rm -rf core.* *.log .*.qws .*.check
	@rm -rf .stack* .parts*

CLEAN: clean
