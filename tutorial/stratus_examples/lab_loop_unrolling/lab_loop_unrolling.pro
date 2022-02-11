#################################################
# Stratus IDE project file generated;
#################################################
QT       += core

QT       -= gui

CONFIG   += console
CONFIG   -= app_bundle

STRATUSHOME = $$(STRATUS_HOME)
SYSTEMCHOME = $$(SYSTEMC)

TEMPLATE = app
INCLUDEPATH += $${SYSTEMCHOME}/include
INCLUDEPATH += $${SYSTEMCHOME}/include/tlm
INCLUDEPATH += $${STRATUSHOME}/share/stratus/include
INCLUDEPATH += ./bdw_work/wrappers
INCLUDEPATH += ./

SOURCES += \ 
		./dut.cc \ 
		./main.cc \ 
		./system.cc \ 
		./tb.cc \ 
		main.cc \ 
		tb.cc \ 
		dut.cc \ 

HEADERS += \ 
		./defines.h \ 
		./directives.h \ 
		./dut.h \ 
		./system.h \ 
		./tb.h \ 
		tb.h \ 
		dut.h \ 

OTHER_FILES += \ 
		Makefile \ 
		/work/shared/users/phd/jl3952/tutorials/systemc/stratus_examples/lab_loop_unrolling/project.tcl \ 

