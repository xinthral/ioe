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
TestSuite::TestSuite() { }

/**
 * Initiates the Test for the Actor Module
*/
void TestSuite::CaseActor() { TestActors* ta = new TestActors(); }

/**
 * Initiates the Test for the Balance Module
*/
void TestSuite::CaseBalance() { }

/**
 * Initiates the Test for the Balance Module
*/
void TestSuite::CaseCombat() { }

/**
 * Default Deconstructor
*/
TestSuite::~TestSuite() { }

/**
 * Static Function to display help details
*/
void print_help() { 
    Logger* log = Logger::GetInstance();
    char buf[1024];
    sprintf(buf, "Usage: %s [NUMBER]\n", Utilz::FileName(__FILE__)); 
    log->named_log(__FILE__, buf);
    log->named_log(__FILE__, "\t-:1 - Test Actor Module");
    log->named_log(__FILE__, "\t-:2 - Test Balance Module");
    log->named_log(__FILE__, "\t-:3 - Test Combat Module");
    log->named_log(__FILE__, "\t-:0 - Default Test to rule them all\n");
    exit(-1);
}

/**
 * Module Entry Point
*/
int main(int argc, char const *argv[]) {
    if (argc < 2) { print_help(); }

    TestSuite ts;
    Logger* log = Logger::GetInstance();
    char buf[1024];
    int choice = 0;
    choice = atoi(argv[1]);
    
    switch (choice) {
        case 1:
            sprintf(buf, "Selected Actor Case...");
            ts.CaseActor();
            break;
        case 2:
            sprintf(buf, "Selected Balance Case...");
            ts.CaseBalance();
            break;
        case 3:
            sprintf(buf, "Selected Combat Case");
            ts.CaseCombat();
            break;
        default:
            log->named_log(__FILE__, "Default Case");
            break;
    }
    
    log->named_log(__FILE__, buf);
    return 0;
}
