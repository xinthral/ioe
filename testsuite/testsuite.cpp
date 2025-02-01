#include "testsuite.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Static Function to display help details
*/
void print_help() { 
  Logger* log = Logger::GetInstance();
  char buf[32];
  int idx = -1;
  std::string fileName = Utilz::FileName(__FILENAME__);
  sprintf(buf, "Usage: %s.exe [NUMBER]\n", fileName.c_str()); 
  log->raw_log(buf);
  log->raw_log("TestSuite CLI Tool\n");
  log->raw_log("A testing system, to give the developer/debugger" \
    " a quality-of-life option for hunting down all my stupid." \
    " This can be used in conjuction with the HelpSuite in order to"\
    " maximize the benefit of the CLI Debugging Suite.\n");
  sprintf(buf, "\t[%d] - Threaded Test of Full Suite", idx); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Default Test to rule them all", ++idx); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Test Actor Module", ++idx); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Test Audio Module", ++idx); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Test BalanceController Module", ++idx); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Test Battle Module", ++idx); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Test Clock Module", ++idx); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Test Ciphers Module", ++idx); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Test Combat Module", ++idx); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Test ConfigManager Module", ++idx); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Test Item Module", ++idx); log->raw_log(buf);
  sprintf(buf, "\t[%d] - Test LeaderBoard Module", ++idx); log->raw_log(buf);
  sprintf(buf, "\t[%d] - Test Lexicon Module", ++idx); log->raw_log(buf);
  sprintf(buf, "\t[%d] - Test Player Module", ++idx); log->raw_log(buf);
  sprintf(buf, "\t[%d] - Test Stage Module", ++idx); log->raw_log(buf);
  sprintf(buf, "\t[%d] - Test Toon Module", ++idx); log->raw_log(buf);
  sprintf(buf, "\t[%d] - Test Utilz Module", ++idx); log->raw_log(buf);
  log->raw_log("\n");
  exit(0);
}

/*!
 * @todo    Default Constructor
*/
TestSuite::TestSuite() {
  log = Logger::GetInstance();
}

void TestSuite::TestAll() {
  this->CaseActor();
  this->CaseAudio();
  this->CaseBalance();
  this->CaseBattle();
  this->CaseClock();
  this->CaseCiphers();
  this->CaseCombat();
  this->CaseConfig();
  this->CaseItem();
  this->CaseLeader();
  this->CaseLexicon();
  this->CasePlayer();
  this->CaseStage();
  this->CaseToon();
  this->CaseUtilz();
}

/*!
 * @todo    Initiates the Test for the Actor Module
*/
void TestSuite::CaseActor() { TestActors* ta = new TestActors(); }

/*!
 * @todo    Initiates the Test for the Actor Module
*/
void TestSuite::CaseAudio() { TestAudio* ta = new TestAudio(); }

/*!
 * @todo    Initiates the Test for the BalanceController Module
*/
void TestSuite::CaseBalance() { TestBalance* tb = new TestBalance(); }

/*!
 * @todo    Initiates the Test for the BalanceController Module
*/
void TestSuite::CaseBattle() { TestBattle* tb = new TestBattle(); }

/*!
 * @todo    Initiates the Test for the Engine Clock
*/
void TestSuite::CaseClock() { TestClock* tc = new TestClock(); }

/*!
 * @todo    Initiates the Test for the Ciphers Module
*/
void TestSuite::CaseCiphers() { TestCiphers* tc = new TestCiphers(); }

/*!
 * @todo    Initiates the Test for the Combat Module
*/
void TestSuite::CaseCombat() { TestCombat* tc = new TestCombat(); }

/*!
 * @todo    Initiates the Test for the ConfigManager Module
*/
void TestSuite::CaseConfig() { TestConfig* tc = new TestConfig(); }

/*!
 * @todo    Initiates the Test for the Item Module
*/
void TestSuite::CaseItem() { TestItem* ti = new TestItem(); }

/*!
 * @todo    Initiates the Test for the LeaderBoard Module 
*/
void TestSuite::CaseLeader() { TestLeader* tl = new TestLeader(); }

/*!
 * @todo    Initiates the Test for the Lexicon Module 
*/
void TestSuite::CaseLexicon() { TestLexicon* tl = new TestLexicon(); }

/*!
 * @todo    Initiates the Test for the Player Module
*/
void TestSuite::CasePlayer() { TestPlayer* tp = new TestPlayer(); }

/*!
 * @todo    Initiates the Test for the StageManager Module
*/
void TestSuite::CaseStage() { TestStage* tg = new TestStage(); }

/*!
 * @todo    Initiates the Test for the Toon Module
*/
void TestSuite::CaseToon() { TestToon* tt = new TestToon(); }

/*!
 * @todo    Initiates the Test for the Utilz Module
*/
void TestSuite::CaseUtilz() { TestUtilz* tu = new TestUtilz(); }

/*!
 * @todo    Default Deconstructor
*/
TestSuite::~TestSuite() { }

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
  std::thread cact, caud, cbal, cbat, cclo, ccip, ccom, ccon, cite, clea, clex, cpla, csta, ctoo, cuti;
  
  switch (choice) {
    case -1:
      sprintf(buf, "All TestCases' Completed...");
      cact = std::thread(&TestSuite::CaseActor, &ts);
      threadList.emplace_back(std::move(cact));
      caud = std::thread(&TestSuite::CaseAudio, &ts);
      threadList.emplace_back(std::move(caud));
      cbal = std::thread(&TestSuite::CaseBalance, &ts);
      threadList.emplace_back(std::move(cbal));
      cbat = std::thread(&TestSuite::CaseBattle, &ts);
      threadList.emplace_back(std::move(cbat));
      cclo = std::thread(&TestSuite::CaseClock, &ts);
      threadList.emplace_back(std::move(cclo));
      ccip = std::thread(&TestSuite::CaseCiphers, &ts);
      threadList.emplace_back(std::move(ccip));
      ccom = std::thread(&TestSuite::CaseCombat, &ts);
      threadList.emplace_back(std::move(ccom));
      ccon = std::thread(&TestSuite::CaseConfig, &ts);
      threadList.emplace_back(std::move(ccon));
      cite = std::thread(&TestSuite::CaseItem, &ts);
      threadList.emplace_back(std::move(cite));
      clea = std::thread(&TestSuite::CaseLeader, &ts);
      threadList.emplace_back(std::move(clea));
      clex = std::thread(&TestSuite::CaseLexicon, &ts);
      threadList.emplace_back(std::move(clex));
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
      ts.TestAll();
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
      sprintf(buf, "Battle TestCase Completed...");
      ts.CaseBattle();
      break;
    case 5:
      sprintf(buf, "Clock TestCase Completed...");
      ts.CaseClock();
      break;
    case 6:
      sprintf(buf, "Ciphers TestCase Completed...");
      ts.CaseCiphers();
      break;
    case 7:
      sprintf(buf, "Combat TestCase Completed...");
      ts.CaseCombat();
      break;
    case 8:
      sprintf(buf, "Config TestCase Completed...");
      ts.CaseConfig();
      break;
    case 9:
      sprintf(buf, "Item TestCase Completed...");
      ts.CaseItem();
      break;
    case 10:
      sprintf(buf, "Leader TestCase Completed...");
      ts.CaseLeader();
      break;
    case 11:
      sprintf(buf, "Lexicon TestCase Completed...");
      ts.CaseLexicon();
      break;
    case 12:
      sprintf(buf, "Player TestCase Completed...");
      ts.CasePlayer();
      break;
    case 13:
      sprintf(buf, "Stage TestCase Completed...");
      ts.CaseStage();
      break;
    case 14:
      sprintf(buf, "Toon TestCase Completed...");
      ts.CaseToon();
      break;
    case 15:
      sprintf(buf, "Utilz TestCase Completed...");
      ts.CaseUtilz();
      break;
    default:
      sprintf(buf, "\nWarn :: Unknown Test, please review the list and try again.\n");
  }
  Profiler::report();
  log->named_log(__FILENAME__, buf);
  return 0;
}
