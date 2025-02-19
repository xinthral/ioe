#/**************************************
# Author: Xinthral 
# This was meant to be a modular make file which can compile any number of components
# in a directory dynamically.
# pragma GCC diagnostic ignored "-Wmaybe-uniitialized"
#**************************************/

# Compiler: gcc for C programs, g++ for C++ programs
# emcc for embedded C programs, em++ for embedded C++ programs
CC := g++
DOXYGEN := doxygen
RRM := rm -rf
SEPR := /

# Windows Variants
ifeq ($(OS), Windows_NT)
CC := c++
DOXYGEN := doxygen.exe
RM := del
RRM := del /S /Q /f
SEPR := \\

endif

# https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
# compiler flags:
# -g										- adds debugging information to the executable file
# -Wall									- is used to turn on most compiler warnings
# -Wextra								- turns on extra compiler checks unchecked by -Wall
# -O										- optimization level (ie -O3)
# -std									- compile with version compatibility
# -no-pie								- do not produce a position-independent executable
# -fPIC									- Format position-independent code
# Standard Compiler Options
CFLAGS = -g -Wno-format -Wno-sign-compare -Wno-uninitialized

# Extended Compiler Options
CXFLAGS = $(CFLAGS) -std=c++20

# Extra Compiler Options
CXXFLAGS = $(CXFLAGS) -Wall -pedantic -O3

# Set GNU Shell
# SHELL := /bin/bash

# Build targets
CORE := core
CORESRC := $(patsubst $(CORE)/%.cpp, $(CORE)/%.o, $(wildcard $(CORE)/*.cpp))

TEST := testsuite
TESTSRC := $(patsubst $(TEST)/%.cpp, $(TEST)/%.o, $(wildcard $(TEST)/*.cpp))

AUDI := audiosuite
AUDISRC := $(patsubst $(AUDI)/%.cpp, $(AUDI)/%.o, $(wildcard $(AUDI)/*.cpp))
AUDISRC += $(CORE)/audio.o $(CORE)/logger.o $(CORE)/config.o $(CORE)/utilz.o $(TEST)/profiler.o

CLIS := clisuite
CLISSRC := $(patsubst $(CLIS)/%.cpp, $(CLIS)/%.o, $(wildcard $(CLIS)/*.cpp))
CLISSRC += $(TEST)/profiler.o

DOCS := docs

HELP := helpsuite
HELPSRC := $(patsubst $(HELP)/%.cpp, $(HELP)/%.o, $(wildcard $(HELP)/*.cpp))

MODULES := $(CORE) $(AUDI) $(CLIS) $(HELP) $(TEST)
SOURCES := $(CORESRC) $(CLISSRC) $(AUDISRC) $(HELPSRC) $(TESTSRC)

# GNU Make Compilation Macros: 
# https://stackoverflow.com/questions/3220277/what-do-the-makefile-symbols-and-mean#3220288
# all: library.cpp main.cpp
# $@ evaluates to all
# $< evaluates to library.cpp
# $^ evaluates to library.cpp main.cpp

info:
	@echo "##################################################################"
	@echo "Build Information for the Isles of Eris engine"
	@echo "Usage: make <str:option>"
	@echo "  build      - Builds the entire project into object files"
	@echo "  core       - Builds the core engine into object files"
	@echo "  audiosuite - Compiles the audio engine into a binary"
	@echo "  clisuite   - Compiles the core engine and the command line tool"
	@echo "  helpsuite  - Compiles the help command line tool (developer details)"
	@echo "  testsuite  - Compiles the test command line tool"
	@echo "##################################################################"

# Compile Full porgram (order matters)
all: $(MODULES)

# PreCompile Object Files
build: $(SOURCES)

# Compile Audio
$(AUDI).exe: $(AUDISRC) core/audio.o
	$(CC) $(CXFLAGS) -I/usr/include/python3.11 $^ -o $@
$(AUDI): $(AUDI).exe

# Compile Engine
$(CORE): $(CORESRC) 

# Compile CLISuite
$(CLIS).exe: $(CORESRC) $(CLISSRC)
	$(CC) $(CXFLAGS) $^ -o $@
$(CLIS): $(CLIS).exe

# Compile HelpSuite
$(HELP).exe: $(CORESRC) $(HELPSRC)
	$(CC) $(CXFLAGS) $^ -o $@
$(HELP): $(HELP).exe

# Compile TestSuite
$(TEST).exe: $(CORESRC) $(TESTSRC)
	$(CC) $(CXFLAGS) $^ -o $@
$(TEST): $(TEST).exe

# Compile Documents 
$(DOCS): docs/conf.dox
	$(DOXYGEN) $<

# Dynamically Compile any object file requested
%.o: %.cpp %.h
	$(CC) $(CXFLAGS) -c $< -o $@

# Clean up Object Files
clean:
	$(MAKE) cleanaudio
	$(MAKE)	cleancli
	$(MAKE) cleancore
	$(MAKE) cleanhelp
	$(MAKE) cleantest

# Clean up audiosuite and graph data
cleanaudio:
	$(RRM) $(AUDI)$(SEPR)*.o
	$(RM) $(DOCS)$(SEPR)out$(SEPR)*.txt
	$(RM) $(DOCS)$(SEPR)out$(SEPR)*.png
	$(RM) $(DOCS)$(SEPR)out$(SEPR)*.gp

# Clean up binary files
cleanbin:
	$(RM) *.exe

cleancli:
	$(RRM) $(CLIS)$(SEPR)*.o

cleancore:
	$(RRM) $(CORE)$(SEPR)*.o

cleanhelp:
	$(RRM) $(HELP)$(SEPR)*.o

cleantest:
	$(RRM) $(TEST)$(SEPR)*.o

cleandoc:
ifeq ($(OS), Windows_NT)
	@powershell -ExecutionPolicy Bypass -File .\docs\docCleanup.ps1 
else
	find docs/html/ docs/latex/ docs/out/ ! -name .gitkeep -type f -delete
endif

cleanall:
	$(MAKE) clean
	$(MAKE) cleanbin

.PHONY: all audiosuite core helpsuite testsuite build clean cleanbin cleanaudio cleancore cleandoc cleanhelp cleantest cleanall
