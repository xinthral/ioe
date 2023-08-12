#/**************************************
# Author: Xinthral 
# This was meant to be a modular make file which can compile any number of components
# in a directory dynamically.
#**************************************/

#pragma GCC diagnostic ignored "-Wmaybe-uniitialized"

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
CC = c++
RM = del

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
CFLAGS = -g -Wno-format -Wno-sign-compare -Wno-uninitialized

# Extended Compiler Options
CXFLAGS = $(CFLAGS) -std=c++17 

# Extra Compiler Options
CXXFLAGS = $(CXFLAGS) -Wall -pedantic -O3

# Build targets
EXEC = engine 
ifeq ($(OS), Windows_NT)
EXECLOC := ..\\

else
EXECLOC := ../
endif

# Ask gnuMake to return a list of *.o files from their source counterpart
SRCFILES := $(patsubst %.cpp, %.o, $(wildcard *.cpp))
SHAREDFL := libxengine.so.1

# GNU Make Compilation Macros: 
# https://stackoverflow.com/questions/3220277/what-do-the-makefile-symbols-and-mean#3220288
# all: library.cpp main.cpp
# $@ evaluates to all
# $< evaluates to library.cpp
# $^ evaluates to library.cpp main.cpp

# Compile Engine
engine: $(SRCFILES)
	$(CC) $(CXXFLAGS) $^ -o $(EXECLOC)$(EXEC)

# Build Object files
build: $(SRCFILES)

# Template function to compile defined objects files
# Dynamically assign *.o to be compiled from its source counterpart
%.o: %.cpp %.h
	$(CC) $(CXFLAGS) -c -o $@ $< 

clean:
	$(RM) *.o *.so *.a *.i *.exe *.stackdump *.html *.js *.wasm $(EXECLOC)*.wasm $(EXECLOC)$(EXEC) 