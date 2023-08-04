#/**************************************
# Modulated Makefile
# This particular makefile is meant to work on Windows and Linux
# and designed to compile libraries
# @author 	Xinthral
# @date		3 Aug 2023
#**************************************/

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
CFLAGS = -g -Wno-format -Wno-sign-compare -Wno-maybe-uninitialized -Wno-unused-variable -std=c++17 

# Extended Compiler Options
CXFLAGS = -Wall -pedantic -O3 -fPIC

# Extra Compiler Options
CXXFLAGS = -shared -Wl,-soname,

# Build targets
EXEC = tester
UTIL := actor balance combat config logger stage utilz

# GNU Make Compilation Macros: 
# https://stackoverflow.com/questions/3220277/what-do-the-makefile-symbols-and-mean#3220288
# all: library.cpp main.cpp
# $@ evaluates to all
# $< evaluates to library.cpp
# $^ evaluates to library.cpp main.cpp

# Ask gnuMake to return a list of *.o files from their source counterpart
SRCFILES := $(patsubst %.cpp, %.o, $(wildcard *.cpp))
SRCFILES += $(foreach d, $(UTIL), ../$d.o)
SHAREDFL := libtestsuite.so.1

# Compile Full TestSuite 
testsuite: $(SRCFILES) 
	$(CC) $(CFLAGS) $(CXFLAGS) $^ -o $(EXEC) 

library: $(SRCFILES)
	$(CC) $(CFLAGS) -o $(SHAREDFL).1 $^ $(CXXFLAGS)$(SHAREDFL)

# Template function to compile defined objects files
# Dynamically assign *.o to be compiled from its source counterpart
%.o: %.cpp %.h
	$(CC) $(CFLAGS) $(CXFLAGS) -c -o $@ $<

clean:
	$(RM) *.o *.so* *.a *.i *.exe *.stackdump $(EXEC) 