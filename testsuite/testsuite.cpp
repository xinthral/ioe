/**
 * Test Suite is meant to be a collection of unit testing
 * with the idea of reaching 100% coverage of testing, while 
 * providing a command line utility for reference when
 * developing or debugging.
*/
#include "testsuite.h"

/**
 * Default Constructor
*/
TestSuite::TestSuite() {}

/**
 * Default Deconstructor
*/
TestSuite::~TestSuite() {}

/**
 * Module Entry Point
*/
int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [options]\n", Utilz::FileName(__FILE__).c_str());
        exit(-1);
    }
    TestSuite ts;
    return 0;
}
