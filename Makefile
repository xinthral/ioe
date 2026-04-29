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

# Engine-specific flags — relaxed for vendored single-headers (httplib.h, json.hpp)
EFLAGS = $(CXFLAGS) -Wno-deprecated-declarations -Wno-shadow -Wno-unused-parameter

# Set GNU Shell
# SHELL := /bin/bash

# Build targets
ENGN := engine
ENGNSRC := $(patsubst $(ENGN)/%.cpp, $(ENGN)/%.o, $(wildcard $(ENGN)/*.cpp))

CORE := core
CORESRC := $(patsubst $(CORE)/%.cpp, $(CORE)/%.o, $(wildcard $(CORE)/*.cpp))

AUDI := audiosuite
AUDISRC := $(patsubst $(AUDI)/%.cpp, $(AUDI)/%.o, $(wildcard $(AUDI)/*.cpp))

CLIS := clisuite
CLISSRC := $(patsubst $(CLIS)/%.cpp, $(CLIS)/%.o, $(wildcard $(CLIS)/*.cpp))

DOCS := docs

HELP := helpsuite
HELPSRC := $(patsubst $(HELP)/%.cpp, $(HELP)/%.o, $(wildcard $(HELP)/*.cpp))

TEST := testsuite
TESTSRC := $(patsubst $(TEST)/%.cpp, $(TEST)/%.o, $(wildcard $(TEST)/*.cpp))

AUDISRC += $(CORE)/audio.o $(CORE)/logger.o $(CORE)/config.o $(CORE)/utilz.o
CORESRC += $(TEST)/profiler.o
AUDIDRV := $(AUDI)/wavdriver.o $(AUDI)/mp3driver.o $(AUDI)/flacdriver.o
MODULES := $(CORE) $(AUDI) $(CLIS) $(HELP) $(TEST) $(ENGN)
SOURCES := $(CORESRC) $(CLISSRC) $(AUDISRC) $(HELPSRC) $(TESTSRC) $(ENGNSRC)

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
	@echo "  build      - Compile all object files without linking"
	@echo "  core       - Compile core engine object files only"
	@echo "  docs       - Generate Doxygen HTML documentation"
	@echo "  engine     - Build world server HTTP API  -> engine.exe"
	@echo "  serve      - Build and run world server on port 8081"
	@echo "  audiosuite - Build audio tools            -> audiosuite.exe"
	@echo "  clisuite   - Build interactive REPL       -> clisuite.exe"
	@echo "  helpsuite  - Build developer help CLI     -> helpsuite.exe"
	@echo "  testsuite  - Build test runner            -> testsuite.exe"
	@echo "  clean      - Remove all .o object files"
	@echo "  cleanall   - Remove .o files and .exe binaries"
	@echo "##################################################################"

# Compile Full porgram (order matters)
all: $(MODULES)

# PreCompile Object Files
build: $(SOURCES)

# Compile Audio
$(AUDI): $(AUDISRC)
	$(CC) $(CXFLAGS) $^ -o $@.exe

# Compile Engine
$(CORE): $(CORESRC)

# Compile CLISuite
$(CLIS): $(CORESRC) $(CLISSRC)
	$(CC) $(CXFLAGS) $^ -o $@.exe

# Compile World Server (links Winsock on Windows)
$(ENGN): $(CORESRC) $(ENGNSRC)
	$(CC) $(EFLAGS) $^ -o $@.exe -lws2_32

# Run World Server on default port
serve: $(ENGN)
	./$(ENGN).exe 8081

# Compile HelpSuite
$(HELP): $(CORESRC) $(HELPSRC)
	$(CC) $(CXFLAGS) $^ -o $@.exe

# Compile TestSuite
$(TEST): $(CORESRC) $(TESTSRC) $(AUDIDRV)
	$(CC) $(CXFLAGS) $^ -o $@.exe

# Compile Documents 
$(DOCS): docs/conf.dox
	$(DOXYGEN) $<

# Engine objects use relaxed flags — vendored headers (httplib.h, json.hpp) generate noise under -Wall
$(ENGN)/%.o: $(ENGN)/%.cpp $(ENGN)/%.h
	$(CC) $(EFLAGS) -c $< -o $@

%.o: %.cpp %.h
	$(CC) $(CXFLAGS) -c $< -o $@

# $(RRM) $(foreach d, $(MODULES),$d\\*.o $d\\*.so $d\\*.wasm) 2>&1 >/dev/null
clean:
	$(MAKE) cleanaudio
	$(MAKE)	cleancli
	$(MAKE) cleancore
	$(MAKE) cleanengine
	$(MAKE) cleanhelp
	$(MAKE) cleantest

cleanaudio:
	$(RRM) $(AUDI)$(SEPR)*.o
	$(RM) $(DOCS)$(SEPR)out$(SEPR)*.txt
	$(RM) $(DOCS)$(SEPR)out$(SEPR)*.png
	$(RM) $(DOCS)$(SEPR)out$(SEPR)*.gp

cleanbin:
	$(RM) *.exe

cleancli:
	$(RRM) $(CLIS)$(SEPR)*.o

cleanengine:
	$(RRM) $(ENGN)$(SEPR)*.o

cleancore:
	$(RRM) $(CORE)$(SEPR)*.o

cleanhelp:
	$(RRM) $(HELP)$(SEPR)*.o

cleantest:
	$(RRM) $(TEST)$(SEPR)*.o

cleandocs:
ifeq ($(OS), Windows_NT)
	@powershell -ExecutionPolicy Bypass -File .\docs\docCleanup.ps1 
else
	find docs/html/ docs/latex/ docs/out/ ! -name .gitkeep -type f -delete
endif

cleanall:
	$(MAKE) clean
	$(MAKE) cleanbin

.PHONY: all info audiosuite clisuite core docs engine serve helpsuite testsuite build clean cleanbin cleanaudio cleancore cleandocs cleanhelp cleantest cleanall