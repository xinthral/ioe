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
TestSuite::TestSuite() {
}

/**
 * Initiates the Test for the Actor Module
*/
void TestSuite::CaseActor() { TestActors* ta = new TestActors(); }

/**
 * Initiates the Test for the Balance Module
*/
void TestSuite::CaseBalance() { }

/**
 * Default Deconstructor
*/
TestSuite::~TestSuite() {}

/**
 * Module Entry Point
*/
int main(int argc, char const *argv[]) {
    Logger* log = Logger::GetInstance();
    char buf[1024];
    if (argc < 2) {
        sprintf(buf, "Usage: %s [options]\n", Utilz::FileName(__FILE__).c_str());
        log->named_log(__FILE__, buf);
        exit(-1);
    }
    TestSuite ts;

    int choice = 0;
    choice = atoi(argv[1]);
    switch (choice) {
        case 1:
            log->named_log(__FILE__, "Selected Actor Case...");
            ts.CaseActor();
            break;
        case 2:
            log->named_log(__FILE__, "Selected Balance Case...");
            ts.CaseBalance();
            break;
        case 3:
        default:
            log->named_log(__FILE__, "Default Case");
            break;
    }
    return 0;
}
