#/**************************************
# Author: Xinthral 
# This was meant to be a modular make file which can compile any number of components
# in a directory dynamically.
#**************************************/

#pragma GCC diagnostic ignored "-Wmaybe-uniitialized"

# the compiler: gcc for C programs, g++ for C++ programs
CC = g++

# Windows Variants
ifeq ($(OS), Windows_NT)
CC = c++
RM = del
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

# Build targets
EXEC = core
ifeq ($(OS), Windows_NT)
EXECLOC := ..\$(EXEC)
else
EXECLOC := ../$(EXEC)
endif

# Ask gnuMake to return a list of *.o files from their source counterpart
SRCFILES := $(patsubst %.cpp, %.o, $(wildcard *.cpp))
# SRCFILES += $(foreach d, $(UTIL), ../$d.o)
SHAREDFL := libhelpsuite.so.1

# GNU Make Compilation Macros: 
# https://stackoverflow.com/questions/3220277/what-do-the-makefile-symbols-and-mean#3220288
# all: library.cpp main.cpp
# $@ evaluates to all
# $< evaluates to library.cpp
# $^ evaluates to library.cpp main.cpp

# Ask gnuMake to return a list of *.o files from their source counterpart
# SRCFILES := $(patsubst %.cpp, %.o, $(wildcard *.cpp))

# Compile Engine
engine: $(SRCFILES)
	$(CC) $(CXXFLAGS) $^ -o $(EXECLOC)

# Build Object files
build: $(SRFFILES)

# Template function to compile defined objects files
# Dynamically assign *.o to be compiled from its source counterpart
%.o: %.cpp %.h
	$(CC) $(CXFLAGS) -c -o $@ $< 

clean:
	$(RM) *.o *.so *.a *.i *.exe *.stackdump $(EXECLOC) 