/*!
 * @class   TestSuite testsuite.h testsuite.cpp
 * @brief   Command Line Tool (CLI) for Tester 
 * @details Test Suite is meant to be a collection of unit testing
 *          with the idea of reaching 100% coverage of testing, 
 *          while providing a command line utility for reference 
 *          when developing or debugging.
*/
#include "testsuite.h"

/*!
 * @brief   Default Constructor
*/
TestSuite::TestSuite() { }

/*!
 * @brief   Initiates the Test for the Actor Module
*/
void TestSuite::CaseActor() { TestActors* ta = new TestActors(); }

/*!
 * @brief   Initiates the Test for the Balance Module
*/
void TestSuite::CaseBalance() { TestBalance* tb = new TestBalance(); }

/*!
 * @brief   Initiates the Test for the Balance Module
*/
void TestSuite::CaseCombat() { TestCombat* tc = new TestCombat(); }

/*!
 * @brief   Default Deconstructor
*/
TestSuite::~TestSuite() { }

/*!
 * @brief   Static Function to display help details
*/
void print_help() { 
    Logger* log = Logger::GetInstance();
    char buf[32];
    std::string fileName = Utilz::FileName(__FILE__);
    sprintf(buf, "Usage: %s [NUMBER]\n", fileName.c_str()); 
    log->raw_log(buf);
    log->raw_log("TestSuite CLI Tool\n");
    log->raw_log("A testing system, to give the developer/debugger" \
        " a quality-of-life option for hunting down all my stupid." \
        " This can be used in conjuction with the HelpSuite in order to"\
        " maximize the benefit of the CLI Debugging Suite.\n");
    log->raw_log("\t[1] - Test Actor Module");
    log->raw_log("\t[2] - Test Balance Module");
    log->raw_log("\t[3] - Test Combat Module");
    log->raw_log("\t[0] - Default Test to rule them all\n");
    exit(-1);
}

/*!
 * @brief   Module Entry Point
*/
int main(int argc, char const *argv[]) {
    if (argc < 2) { print_help(); }

    TestSuite ts;
    Logger* log = Logger::GetInstance();
    char buf[32];
    int choice = 0;
    choice = atoi(argv[1]);
    
    switch (choice) {
        case 1:
            sprintf(buf, "Actor TestCase Completed...");
            ts.CaseActor();
            break;
        case 2:
            sprintf(buf, "Balance TestCase Completed...");
            ts.CaseBalance();
            break;
        case 3:
            sprintf(buf, "Combat TestCase Completed...");
            ts.CaseCombat();
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        default:
            sprintf(buf, "All TestCases' Completed...");
            ts.CaseActor();
            ts.CaseBalance();
            ts.CaseCombat();
            break;
    }
    
    log->named_log(__FILE__, buf);
    
    return 0;
}
