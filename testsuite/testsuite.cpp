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
 * @brief   Initiates the Test for the Combat Module
*/
void TestSuite::CaseCombat() { TestCombat* tc = new TestCombat(); }

/*!
 * @brief   Initiates the Test for the Combat Module
*/
void TestSuite::CaseConfig() { TestConfig* tf = new TestConfig(); }

/*!
 * @brief   Initiates the Test for the Combat Module
*/
void TestSuite::CasePlayer() { TestPlayer* tp = new TestPlayer(); }

/*!
 * @brief   Initiates the Test for the Combat Module
*/
void TestSuite::CaseStage() { TestStage* tg = new TestStage(); }

/*!
 * @brief   Initiates the Test for the Combat Module
*/
void TestSuite::CaseToon() { TestToon* tt = new TestToon(); }

/*!
 * @brief   Initiates the Test for the Combat Module
*/
void TestSuite::CaseUtilz() { TestUtilz* tu = new TestUtilz(); }

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
    log->raw_log("\t[4] - Test Config Module");
    log->raw_log("\t[5] - Test Player Module");
    log->raw_log("\t[6] - Test Stage Module");
    log->raw_log("\t[7] - Test Toon Module");
    log->raw_log("\t[8] - Test Utilz Module");
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
            sprintf(buf, "Config TestCase Completed...");
            ts.CaseConfig();
            break;
        case 5:
            sprintf(buf, "Player TestCase Completed...");
            ts.CasePlayer();
            break;
        case 6:
            sprintf(buf, "Stage TestCase Completed...");
            ts.CaseStage();
            break;
        case 7:
            sprintf(buf, "Toon TestCase Completed...");
            ts.CaseToon();
            break;
        case 8:
            sprintf(buf, "Utilz TestCase Completed...");
            ts.CaseUtilz();
            break;
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        default:
            sprintf(buf, "All TestCases' Completed...");
            ts.CaseActor();
            ts.CaseBalance();
            ts.CaseCombat();
            ts.CaseConfig();
            ts.CasePlayer();
            ts.CaseStage();
            ts.CaseToon();
            ts.CaseUtilz();
            break;
    }
    
    log->named_log(__FILE__, buf);
    
    return 0;
}
