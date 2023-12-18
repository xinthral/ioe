/*!
 * @class   TestSuite testsuite.h testsuite.cpp
 * @brief   Command Line Tool (CLI) for Tester 
 * @details Test Suite is meant to be a collection of unit testing
 *      with the idea of reaching 100% coverage of testing, 
 *      while providing a command line utility for reference 
 *      when developing or debugging.
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
 * @brief   Initiates the Test for the BalanceController Module
*/
void TestSuite::CaseBalance() { TestBalance* tb = new TestBalance(); }

/*!
 * @brief   Initiates the Test for the Combat Module
*/
void TestSuite::CaseCombat() { TestCombat* tc = new TestCombat(); }

/*!
 * @brief   Initiates the Test for the ConfigManager Module
*/
void TestSuite::CaseConfig() { TestConfig* tf = new TestConfig(); }

/*!
 * @brief   Initiates the Test for the LeaderBoard Module 
*/
void TestSuite::CaseLeader() { TestLeader* tl = new TestLeader(); }

/*!
 * @brief   Initiates the Test for the Player Module
*/
void TestSuite::CasePlayer() { TestPlayer* tp = new TestPlayer(); }

/*!
 * @brief   Initiates the Test for the StageManager Module
*/
void TestSuite::CaseStage() { TestStage* tg = new TestStage(); }

/*!
 * @brief   Initiates the Test for the Toon Module
*/
void TestSuite::CaseToon() { TestToon* tt = new TestToon(); }

/*!
 * @brief   Initiates the Test for the Utilz Module
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
  log->raw_log("\t[5] - Test LeaderBoard Module");
  log->raw_log("\t[6] - Test Player Module");
  log->raw_log("\t[7] - Test Stage Module");
  log->raw_log("\t[8] - Test Toon Module");
  log->raw_log("\t[9] - Test Utilz Module");
  log->raw_log("\t[0] - Default Test to rule them all\n");
  exit(0);
}

/*!
 * @brief   Module Entry Point
*/
int main(int argc, char const *argv[]) {

  if (argc < 2) { print_help(); return 0; }
  if (strcmp(argv[1], "-h") == 0) { print_help(); return 0; }

  TestSuite ts;
  Logger* log = Logger::GetInstance();
  std::vector<std::thread> threadList;
  char buf[32];
  int choice = 0;
  choice = atoi(argv[1]);
  std::thread cact, cbal, ccom, ccon, clea, cpla, csta, ctoo, cuti;
  
  switch (choice) {
    case 1:
      sprintf(buf, "Actor TestCase Completed...");
      cact = std::thread(&TestSuite::CaseActor, &ts);
      threadList.emplace_back(std::move(cact));
      break;
    case 2:
      sprintf(buf, "Balance TestCase Completed...");
      cbal = std::thread(&TestSuite::CaseBalance, &ts);
      threadList.emplace_back(std::move(cbal));
      break;
    case 3:
      sprintf(buf, "Combat TestCase Completed...");
      ccom = std::thread(&TestSuite::CaseCombat, &ts);
      threadList.emplace_back(std::move(ccom));
      break;
    case 4:
      sprintf(buf, "Config TestCase Completed...");
      ccon = std::thread(&TestSuite::CaseConfig, &ts);
      threadList.emplace_back(std::move(ccon));
      break;
    case 5:
      sprintf(buf, "Leader TestCase Completed...");
      clea = std::thread(&TestSuite::CaseLeader, &ts);
      threadList.emplace_back(std::move(clea));
      break;
    case 6:
      sprintf(buf, "Player TestCase Completed...");
      cpla = std::thread(&TestSuite::CasePlayer, &ts);
      threadList.emplace_back(std::move(cpla));
      break;
    case 7:
      sprintf(buf, "Stage TestCase Completed...");
      csta = std::thread(&TestSuite::CaseStage, &ts);
      threadList.emplace_back(std::move(csta));
      break;
    case 8:
      sprintf(buf, "Toon TestCase Completed...");
      ctoo = std::thread(&TestSuite::CaseToon, &ts);
      threadList.emplace_back(std::move(ctoo));
      break;
    case 9:
      sprintf(buf, "Utilz TestCase Completed...");
      cuti = std::thread(&TestSuite::CaseUtilz, &ts);
      threadList.emplace_back(std::move(cuti));
      break;
    case 10:
    case 11:
    case 12:
    case 13:
    default:
      sprintf(buf, "All TestCases' Completed...");
      cact = std::thread(&TestSuite::CaseActor, &ts);
      threadList.emplace_back(std::move(cact));
      cbal = std::thread(&TestSuite::CaseBalance, &ts);
      threadList.emplace_back(std::move(cbal));
      ccom = std::thread(&TestSuite::CaseCombat, &ts);
      threadList.emplace_back(std::move(ccom));
      ccon = std::thread(&TestSuite::CaseConfig, &ts);
      threadList.emplace_back(std::move(ccon));
      clea = std::thread(&TestSuite::CaseLeader, &ts);
      threadList.emplace_back(std::move(clea));
      cpla = std::thread(&TestSuite::CasePlayer, &ts);
      threadList.emplace_back(std::move(cpla));
      csta = std::thread(&TestSuite::CaseStage, &ts);
      threadList.emplace_back(std::move(csta));
      ctoo = std::thread(&TestSuite::CaseToon, &ts);
      threadList.emplace_back(std::move(ctoo));
      cuti = std::thread(&TestSuite::CaseUtilz, &ts);
      threadList.emplace_back(std::move(cuti));
  }
  
  for (auto& t : threadList) { t.join(); }
  log->named_log(__FILE__, buf);
  return 0;
}
