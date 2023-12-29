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
CFLAGS = -g -Wno-format -Wno-sign-compare -Wno-uninitialized

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
CLIS = cli 
AUDI = audio
LIBRARIES := core audiosuite clisuite helpsuite testsuite 

# GNU Make Compilation Macros: 
# https://stackoverflow.com/questions/3220277/what-do-the-makefile-symbols-and-mean#3220288
# all: library.cpp main.cpp
# $@ evaluates to all
# $< evaluates to library.cpp
# $^ evaluates to library.cpp main.cpp

ifeq ($(OS), Windows_NT)
EXECLOC	:= .\\bin\\
else
EXECLOC	:= ./bin/
endif
	
# Compile Full porgram (order matters)
all: $(DOCS) $(ENGN) $(AUDI) $(CLIS) $(HELP) $(TEST)

# Compile Engine
$(ENGN): 
	$(MAKE) -C core 

# Compile CLISuite
$(CLIS):
	$(MAKE) -C clisuite

# Compile Audio
$(AUDI):
	$(MAKE) -C audiosuite 

# Compile HelpSuite
$(HELP): 
	$(MAKE) -C helpsuite

# Compile TestSuite
$(TEST): 
	$(MAKE) -C testsuite

# Compile Documents 
$(DOCS): docs/conf.dox
	$(DOXYGEN) $<

# PreCompile Object Files
build:
	$(foreach d, $(LIBRARIES), $(MAKE) build -C $d &&) true 2>&1 >/dev/null

clean:
	$(RM) *.stackdump $(EXEC) 
	$(RM) *.o *.so *.a *.i *.js *.html *.wasm 
	$(foreach d, $(LIBRARIES), $(MAKE) clean -C $d &&) true 2>&1 >/dev/null

cleanaudio:
	$(MAKE) clean -C audiosuite

cleancore:
	$(MAKE) clean -C core 

cleandoc:
ifeq ($(OS), Windows_NT)
	@powershell -ExecutionPolicy Bypass -File .\docs\docCleanup.ps1 
else
	find docs/html/ docs/latex/ docs/out/ ! -name .gitkeep -type f -delete
endif

cleanhelp:
	$(MAKE) clean -C helpsuite

cleantest:
	$(MAKE) clean -C testsuite

cleanall:
	$(RM) $(EXECLOC)helper.exe $(EXECLOC)mixer.exe $(EXECLOC)tester.exe $(EXECLOC)engine.exe
	$(MAKE) clean
	$(foreach d, $(LIBRARIES), $(MAKE) cleanall -C $d &&) true 2>&1 >/dev/null

.PHONY: all audio build clean cleanaudio cleancore cleandoc cleanhelp cleantest cleanall engine helper mixer tester 
