#/**************************************
# Modulated Makefile
# This particular makefile is meant to work on Windows and Linux
# and designed to compile libraries
# @author 	Xinthral
# @date		3 Aug 2023
#**************************************/

# Compiler: cc, c++, gcc, g++, emcc, em++ 
# cc for C programs on windows
# c++ for C++ programs on windows
# gcc for C programs on gnu
# g++ for C++ programs on gnu
# emcc for C programs for embedded languages
# em++ for C++ programs for embedded languages
CC = g++

# Windows Variants
ifeq ($(OS), Windows_NT)
# CC = emcc
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
CFLAGS = -g -Wno-format -Wno-sign-compare -Wno-uninitialized -std=c++17

# Extended Compiler Options
CXFLAGS = -Wall -pedantic -O3 -fPIC

# Extra Compiler Options
CXXFLAGS = -shared -Wl,-soname,

#
# compiler flags:
# -EXIT_RUNTIME to display output to console
# Emscriten Compiler Options
EFLAGS = -sEXIT_RUNTIME=1

# Build targets
EXEC    := helper
ifeq ($(OS), Windows_NT)
EXECLOC := ..\\$(EXEC)
# CXFLAGS := $(EFLAGS)
else
EXECLOC := ../$(EXEC)
endif
UTIL := actor balance combat config logger stage toon utilz

# Ask gnuMake to return a list of *.o files from their source counterpart
SRCFILES := $(patsubst %.cpp, %.o, $(wildcard *.cpp))
SRCFILES += $(foreach d, $(UTIL), ../$d.o)
SHAREDFL := libhelpsuite.so.1

# GNU Make Compilation Macros: 
# https://stackoverflow.com/questions/3220277/what-do-the-makefile-symbols-and-mean#3220288
# all: library.cpp main.cpp
# $@ evaluates to all
# $< evaluates to library.cpp
# $^ evaluates to library.cpp main.cpp

# Ask gnuMake to return a list of *.o files from their source counterpart
SRCFILES := $(patsubst %.cpp, %.o, $(wildcard *.cpp))
SRCFILES += $(foreach d, $(UTIL), ../core/$d.o)
SHAREDFL := libhelpsuite.so.1

# Compile Full HelpSuite 
helpsuite: $(SRCFILES) 
	$(CC) $(CFLAGS) $(CXFLAGS) $^ -o $(EXECLOC)

library: $(SRCFILES)
	$(CC) $(CFLAGS) -o $(SHAREDFL).1 $^ $(CXXFLAGS)$(SHAREDFL)

build: $(SRCFILES)

# Template function to compile defined objects files
# Dynamically assign *.o to be compiled from its source counterpart
%.o: %.cpp %.h
	$(CC) $(CFLAGS) $(CXFLAGS) -c $< -o $@

clean:
	$(RM) *.o *.so *.a *.i *.js *.html *.wasm *.stackdump 

cleanall:
	$(RM) $(EXECLOC) $(EXECLOC).*
	$(MAKE) clean