#/**************************************
# Author: Xinthral 
# This was meant to be a modular make file which can compile any number of components
# in a directory dynamically.
#**************************************/

#pragma GCC diagnostic ignored "-Wmaybe-uniitialized"

# Compiler: gcc for C programs, g++ for C++ programs
# emcc for embedded C programs, em++ for embedded C++ programs
DOXYGEN := doxygen
RRM := rm -rf

# Windows Variants
ifeq ($(OS), Windows_NT)
DOXYGEN := doxygen.exe
RM := del
RRM := del /S /Q /f

endif

# https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
# compiler flags:
#  	-g						- adds debugging information to the executable file
#  	-Wall					- is used to turn on most compiler warnings
#  	-Wextra					- turns on extra compiler checks unchecked by -Wall
# 	-O						- optimization level (ie -O3)
#  	-std					- compile with version compatibility
#  	-no-pie					- do not produce a position-independent executable
#	-fPIC					- Format position-independent code
# Standard Compiler Options
CFLAGS = -g -Wno-format -Wno-sign-compare -Wno-maybe-uninitialized

# Extended Compiler Options
CXFLAGS = $(CFLAGS) -std=c++17 

# Extra Compiler Options
CXXFLAGS = $(CXFLAGS) -Wall -pedantic -O3

# Set GNU Shell
SHELL := /bin/bash

# Build targets
ENGN = engine
TEST = test
HELP = help
DOCS = doc
LIBRARIES := helpsuite testsuite core

# GNU Make Compilation Macros: 
# https://stackoverflow.com/questions/3220277/what-do-the-makefile-symbols-and-mean#3220288
# all: library.cpp main.cpp
# $@ evaluates to all
# $< evaluates to library.cpp
# $^ evaluates to library.cpp main.cpp

# Compile Engine

$(ENGN): 
	$(MAKE) -C core 

# Compile TestSuite
$(TEST): 
	$(MAKE) -C testsuite

# Compile HelpSuite
$(HELP): 
	$(MAKE) -C helpsuite

# Compile Documents 
$(DOCS): docs/conf.dox
	$(DOXYGEN) $<
	
# Compile Full porgram
all: $(ENGN) $(TEST) $(HELP) $(DOCS) 

# PreCompile Object Files
build:
	$(MAKE) build -C core
	$(MAKE) build -C testsuite 
	$(MAKE) build -C helpsuite 

clean:
	$(RM) *.stackdump $(EXEC) 
	$(RM) *.o *.so *.a *.i 
	$(foreach d, $(LIBRARIES), $(MAKE) clean -C $d &&) true 2>&1 >/dev/null

cleandoc:
ifeq ($(OS), Windows_NT)
	$(RRM) docs\html
	$(RRM) docs\latex
else
	$(RRM) docs/html/*
	$(RRM) docs/latex/*
endif

cleanall:
	$(RM) *.exe
	$(MAKE) cleandoc
	$(MAKE) clean
	$(foreach d, $(LIBRARIES), $(MAKE) cleanall -C $d &&) true 2>&1 >/dev/null

.PHONY: all build cleanall cleandoc clean engine helper tester 
