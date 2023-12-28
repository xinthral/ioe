/*!
 * @class   TestSuite testsuite.h testsuite.cpp
 * @brief   Command Line Tool (CLI) for the TestSuite
 * @details Test Suite is meant to be a collection of unit testing
 *          with the idea of reaching 100% coverage of testing, 
 *          while providing a command line utility for reference 
 *          when developing or debugging.
*/
#include "testsuite.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
TestSuite::TestSuite() { }

/*!
 * @brief   Initiates the Test for the Actor Module
*/
void TestSuite::CaseActor() { TestActors* ta = new TestActors(); }

/*!
 * @brief   Initiates the Test for the Actor Module
*/
void TestSuite::CaseAudio() { TestAudio* ta = new TestAudio(); }

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
 * @brief   Initiates the Test for the Item Module
*/
void TestSuite::CaseItem() { TestItem* ti = new TestItem(); }

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
  std::string fileName = Utilz::FileName(__FILENAME__);
  sprintf(buf, "Usage: %s.exe [NUMBER]\n", fileName.c_str()); 
  log->raw_log(buf);
  log->raw_log("TestSuite CLI Tool\n");
  log->raw_log("A testing system, to give the developer/debugger" \
    " a quality-of-life option for hunting down all my stupid." \
    " This can be used in conjuction with the HelpSuite in order to"\
    " maximize the benefit of the CLI Debugging Suite.\n");
  log->raw_log("\t[-1] - Threaded Test of Full Suite");
  log->raw_log("\t [0] - Default Test to rule them all");
  log->raw_log("\t [1] - Test Actor Module");
  log->raw_log("\t [2] - Test Audio Module");
  log->raw_log("\t [3] - Test BalanceController Module");
  log->raw_log("\t [4] - Test Combat Module");
  log->raw_log("\t [5] - Test ConfigManager Module");
  log->raw_log("\t [6] - Test Item Module");
  log->raw_log("\t [7] - Test LeaderBoard Module");
  log->raw_log("\t [8] - Test Player Module");
  log->raw_log("\t [9] - Test Stage Module");
  log->raw_log("\t[10] - Test Toon Module");
  log->raw_log("\t[11] - Test Utilz Module");
  log->raw_log("\n");
  exit(0);
}

/*!
 * @brief   Module Entry Point
*/
int main(int argc, char const *argv[]) {

  if (argc < 2) { print_help(); return 0; }
  if (strcmp(argv[1], "-h") == 0) { print_help(); return 0; }

  TestSuite ts = TestSuite();
  Logger* log = Logger::GetInstance();
  std::vector<std::thread> threadList;
  char buf[64];
  int choice = 0;
  choice = atoi(argv[1]);
  std::thread cact, caud, cbal, ccom, ccon, cite, clea, cpla, csta, ctoo, cuti;
  
  switch (choice) {
    case -1:
      sprintf(buf, "All TestCases' Completed...");
      cact = std::thread(&TestSuite::CaseActor, &ts);
      threadList.emplace_back(std::move(cact));
      caud = std::thread(&TestSuite::CaseAudio, &ts);
      threadList.emplace_back(std::move(caud));
      cbal = std::thread(&TestSuite::CaseBalance, &ts);
      threadList.emplace_back(std::move(cbal));
      ccom = std::thread(&TestSuite::CaseCombat, &ts);
      threadList.emplace_back(std::move(ccom));
      ccon = std::thread(&TestSuite::CaseConfig, &ts);
      threadList.emplace_back(std::move(ccon));
      cite = std::thread(&TestSuite::CaseItem, &ts);
      threadList.emplace_back(std::move(cite));
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
      for (auto& t : threadList) { t.join(); }
      break;
    case 0: 
      sprintf(buf, "All TestCases' Completed...");
      ts.CaseActor();
      ts.CaseAudio();
      ts.CaseBalance();
      ts.CaseCombat();
      ts.CaseConfig();
      ts.CaseItem();
      ts.CaseLeader();
      ts.CasePlayer();
      ts.CaseStage();
      ts.CaseToon();
      ts.CaseUtilz();
      break;
    case 1:
      sprintf(buf, "Actor TestCase Completed...");
      ts.CaseActor();
      break;
    case 2:
      sprintf(buf, "Audio TestCase Completed...");
      ts.CaseAudio();
      break;
    case 3:
      sprintf(buf, "Balance TestCase Completed...");
      ts.CaseBalance();
      break;
    case 4:
      sprintf(buf, "Combat TestCase Completed...");
      ts.CaseCombat();
      break;
    case 5:
      sprintf(buf, "Config TestCase Completed...");
      ts.CaseConfig();
      break;
    case 6:
      sprintf(buf, "Item TestCase Completed...");
      ts.CaseItem();
      break;
    case 7:
      sprintf(buf, "Leader TestCase Completed...");
      ts.CaseLeader();
      break;
    case 8:
      sprintf(buf, "Player TestCase Completed...");
      ts.CasePlayer();
      break;
    case 9:
      sprintf(buf, "Stage TestCase Completed...");
      ts.CaseStage();
      break;
    case 10:
      sprintf(buf, "Toon TestCase Completed...");
      ts.CaseToon();
      break;
    case 11:
      sprintf(buf, "Utilz TestCase Completed...");
      ts.CaseUtilz();
      break;
    case 12:
    case 13:
    default:
      sprintf(buf, "\nWarn :: Unknown Test, please review the list and try again.\n");
  }
  
  log->named_log(__FILENAME__, buf);
  return 0;
}
