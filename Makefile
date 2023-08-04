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
RRM := rmdir /s /q
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
DOCS = doc
UTIL := actor config logger utilz
LIBRARIES := helpsuite testsuite
OBJ := $(patsubst %.cpp, %.o, $(wildcard *.cpp))

# GNU Make Compilation Macros: 
# https://stackoverflow.com/questions/3220277/what-do-the-makefile-symbols-and-mean#3220288
# all: library.cpp main.cpp
# $@ evaluates to all
# $< evaluates to library.cpp
# $^ evaluates to library.cpp main.cpp

# Ask gnuMake to return a list of *.o files from their source counterpart
# SRCFILES := $(patsubst %.cpp, %.o, $(wildcard *.cpp))

# Compile Engine
$(EXEC): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^

# Compile TestSuite
$(TEST): $(patsubst %.cpp, %.o, $(UTIL *.cpp)) 
	$(MAKE) -C ./suitetest

# Compile HelpSuite
$(HELP): $(patsubst %.cpp, %.o, $(UTIL *.cpp))
	$(MAKE) -C ./suitehelp

# Compile Documents 
$(DOCS): docs/conf.dox 
	$(DOXYGEN) $<
	
# Build Object files
build: $(OBJ)

# Compile Full porgram
all: $(EXEC) $(TEST) $(HELP) $(DOCS) 
	$(call ./docs/library_linker.bat)
	$(shell ./docs/library_linker.sh)

# Template function to compile defined objects files
# Dynamically assign *.o to be compiled from its source counterpart
%.o: %.cpp %.h
	$(CC) $(CXFLAGS) -c -o $@ $< 

delink:
	$(shell unlink lib/*)
	$(call rmdir lib/*)

clean:
	$(RM) *.exe *.stackdump $(EXEC) 
	$(RM) *.o *.so *.a *.i 
	$(foreach d, $(LIBRARIES), $(MAKE) clean -C $d &&) true 2>&1 >/dev/null

cleanall:
	$(MAKE) clean
	$(RRM) html
	$(RRM) latex
# $(RRM) lib
# $(delink)

.PHONY: all build cleanall clean delink helper maji tester 
