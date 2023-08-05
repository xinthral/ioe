#/**************************************
# Author: Xinthral 
# This was meant to be a modular make file which can compile any number of components
# in a directory dynamically.
#**************************************/

#pragma GCC diagnostic ignored "-Wmaybe-uniitialized"

# the compiler: gcc for C programs, g++ for C++ programs
CC = g++
DOXYGEN := doxygen
RRM := rm -rf

# Windows Variants
ifeq ($(OS), Windows_NT)
CC = c++
DOXYGEN := doxygen.exe
RM = del
RRM := del /S /Q /f
endif

# https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
# compiler flags:
#  	-g										- adds debugging information to the executable file
#  	-Wall									- is used to turn on most compiler warnings
#  	-Wextra									- turns on extra compiler checks unchecked by -Wall
# 	-O										- optimization level (ie -O3)
#  	-std									- compile with version compatibility
#  	-no-pie 								- do not produce a position-independent executable
#	-fPIC									- Format position-independent code
# Standard Compiler Options
CFLAGS = -g -Wno-format -Wno-sign-compare -Wno-maybe-uninitialized

# Extended Compiler Options
CXFLAGS = $(CFLAGS) -std=c++17 

# Extra Compiler Options
CXXFLAGS = $(CXFLAGS) -Wall -pedantic -O3

# Set GNU Shell
SHELL := /bin/bash

# Build targets
TEST = test
HELP = help
EXEC = maji 
ENGN = engine
DOCS = doc
LIBRARIES := engine helpsuite testsuite
OBJ := $(patsubst %.cpp, %.o, $(wildcard *.cpp))

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
	
# Build Object files
build: $(OBJ)

# Compile Full porgram
all: $(ENGN) $(TEST) $(HELP) $(DOCS) 

# Template function to compile defined objects files
# Dynamically assign *.o to be compiled from its source counterpart
%.o: %.cpp %.h
	$(CC) $(CXFLAGS) -c -o $@ $< 

clean:
	$(RM) *.exe *.stackdump $(EXEC) 
	$(RM) *.o *.so *.a *.i 
	$(foreach d, $(LIBRARIES), $(MAKE) clean -C $d &&) true 2>&1 >/dev/null

cleanall:
ifeq ($(OS), Windows_NT)
	$(RRM) html
	$(RRM) latex
	$(RRM) lib
else
	$(RRM) html/*
	$(RRM) latex/*
	$(RRM) lib/*
endif
	$(MAKE) clean
# $(delink)

.PHONY: all build cleanall clean helper maji tester 
