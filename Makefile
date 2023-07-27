#/**************************************
# Author: Xinthral 
# This was meant to be a modular make file which can compile any number of components
# in a directory dynamically.
#**************************************/

# the compiler: gcc for C programs, g++ for C++ programs
CC = g++

# Windows Variants
ifeq ($(OS), Windows_NT)
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
CFLAGS = -g -Wno-format -Wno-sign-compare

# Extended Compiler Options
CXFLAGS = $(CFLAGS) -std=c++2a 

# Extra Compiler Options
CXXFLAGS = $(CXFLAGS) -Wall -pedantic -O3

# Build targets
UTIL = utilz
TEST = test
EXEC = gengine 

# GNU Make Compilation Macros: 
# https://stackoverflow.com/questions/3220277/what-do-the-makefile-symbols-and-mean#3220288
# all: library.cpp main.cpp
# $@ evaluates to all
# $< evaluates to library.cpp
# $^ evaluates to library.cpp main.cpp

# Compile Full porgram
all: $(EXEC) 

# Ask gnuMake to return a list of *.o files from their source counterpart
# using pattern substitution and the wildcard macro
$(EXEC): $(patsubst %.cpp, %.o, $(wildcard *.cpp))
	$(CC) $(CXXFLAGS) -o $@ $^

# Template function to compile defined objects files
# Dynamically assign *.o to be compiled from its source counterpart
%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c -o $@ $< 

# xengine.o: xengine.cpp
# 	$(CC) $(CFLAGS) -c -o $@ $< 


clean:
	$(RM) *.o *.so *.a *.i *.exe *.stackdump $(UTIL) $(TEST) $(EXEC) 