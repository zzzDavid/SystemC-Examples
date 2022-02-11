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
INCLUDEPATH += memlib/c_parts

SOURCES += \ 
		./dut.cc \ 
		./main.cc \ 
		./system.cc \ 
		./tb.cc \ 
		main.cc \ 
		system.cc \ 
		tb.cc \ 
		dut.cc \ 
		/work/shared/users/phd/jl3952/tutorials/systemc/stratus_examples/lab_explicit_mem/memlib/c_parts/RAM_64x8.cc \ 

HEADERS += \ 
		./defines.h \ 
		./dut.h \ 
		./system.h \ 
		./tb.h \ 
		system.h \ 
		tb.h \ 
		dut.h \ 
		/work/shared/users/phd/jl3952/tutorials/systemc/stratus_examples/lab_explicit_mem/memlib/c_parts/RAM_64x8.h \ 

OTHER_FILES += \ 
		Makefile \ 
		/work/shared/users/phd/jl3952/tutorials/systemc/stratus_examples/lab_explicit_mem/project.tcl \ 

