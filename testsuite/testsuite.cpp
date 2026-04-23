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
  sprintf(buf, "\t [%d] - Default Test to rule them all", ++idx); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Test Actor Module",            ++idx); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Test Audio Module",            ++idx); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Test Backpack Module",         ++idx); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Test BalanceController Module",++idx); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Test Battle Module",           ++idx); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Test Clock Module",            ++idx); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Test Ciphers Module",          ++idx); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Test Combat Module",           ++idx); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Test ConfigManager Module",    ++idx); log->raw_log(buf);
  sprintf(buf, "\t[%d] - Test Equipment Module",         ++idx); log->raw_log(buf);
  sprintf(buf, "\t[%d] - Test Item Module",              ++idx); log->raw_log(buf);
  sprintf(buf, "\t[%d] - Test LeaderBoard Module",       ++idx); log->raw_log(buf);
  sprintf(buf, "\t[%d] - Test Lexicon Module",           ++idx); log->raw_log(buf);
  sprintf(buf, "\t[%d] - Test Player Module",            ++idx); log->raw_log(buf);
  sprintf(buf, "\t[%d] - Test Stage Module",             ++idx); log->raw_log(buf);
  sprintf(buf, "\t[%d] - Test Strategy Module",          ++idx); log->raw_log(buf);
  sprintf(buf, "\t[%d] - Test Toon Module",              ++idx); log->raw_log(buf);
  sprintf(buf, "\t[%d] - Test Utilz Module",             ++idx); log->raw_log(buf);
  sprintf(buf, "\t[%d] - Test Weapon Module",            ++idx); log->raw_log(buf);
  log->raw_log("\n");
  exit(0);
}

/*!
 * @brief   Default Constructor
*/
TestSuite::TestSuite() {
  log = Logger::GetInstance();
}

void TestSuite::TestAll() {
  this->CaseActor(0);
  this->CaseAudio(0);
  this->CaseBackpack(0);
  this->CaseBalance(0);
  this->CaseBattle(0);
  this->CaseClock(0);
  this->CaseCiphers(0);
  this->CaseCombat(0);
  this->CaseConfig(0);
  this->CaseEquipment(0);
  this->CaseItem(0);
  this->CaseLeader(0);
  this->CaseLexicon(0);
  this->CasePlayer(0);
  this->CaseStage(0);
  this->CaseStrategy(0);
  this->CaseToon(0);
  this->CaseUtilz(0);
  this->CaseWeapon(0);
}

/*!
 * @brief    Initiates the Test for the Actor Module
 * @param[in] level  Profiling granularity passed to TestActors
*/
void TestSuite::CaseActor(int level) { TestActors ta(level); }

/*!
 * @brief    Initiates the Test for the Audio Module
 * @param[in] level  Profiling granularity passed to TestAudio
*/
void TestSuite::CaseAudio(int level) { TestAudio ta(level); }

/*!
 * @brief    Initiates the Test for the Backpack Module
 * @param[in] level  Profiling granularity passed to TestBackpack
*/
void TestSuite::CaseBackpack(int level)  { TestBackpack  tb(level); }

/*!
 * @brief    Initiates the Test for the BalanceController Module
 * @param[in] level  Profiling granularity passed to TestBalance
*/
void TestSuite::CaseBalance(int level) { TestBalance tb(level); }

/*!
 * @brief    Initiates the Test for the BattleManager Module
 * @param[in] level  Profiling granularity passed to TestBattle
*/
void TestSuite::CaseBattle(int level) { TestBattle tb(level); }

/*!
 * @brief    Initiates the Test for the Ciphers Module
 * @param[in] level  Profiling granularity passed to TestCiphers
*/
void TestSuite::CaseCiphers(int level) { TestCiphers tc(level); }

/*!
 * @brief    Initiates the Test for the Engine Clock
 * @param[in] level  Profiling granularity passed to TestClock
*/
void TestSuite::CaseClock(int level) { TestClock tc(level); }

/*!
 * @brief    Initiates the Test for the Combat Module
 * @param[in] level  Profiling granularity passed to TestCombat
*/
void TestSuite::CaseCombat(int level) { TestCombat tc(level); }

/*!
 * @brief    Initiates the Test for the ConfigManager Module
 * @param[in] level  Profiling granularity passed to TestConfig
*/
void TestSuite::CaseConfig(int level) { TestConfig tc(level); }

/*!
 * @brief    Initiates the Test for the Equipment Module
 * @param[in] level  Profiling granularity passed to TestEquipment
*/
void TestSuite::CaseEquipment(int level) { TestEquipment te(level); }

/*!
 * @brief    Initiates the Test for the Item Module
 * @param[in] level  Profiling granularity passed to TestItem
*/
void TestSuite::CaseItem(int level) { TestItem ti(level); }

/*!
 * @brief    Initiates the Test for the LeaderBoard Module
 * @param[in] level  Profiling granularity passed to TestLeader
*/
void TestSuite::CaseLeader(int level) { TestLeader tl(level); }

/*!
 * @brief    Initiates the Test for the Lexicon Module
 * @param[in] level  Profiling granularity passed to TestLexicon
*/
void TestSuite::CaseLexicon(int level) { TestLexicon tl(level); }

/*!
 * @brief    Initiates the Test for the Player Module
 * @param[in] level  Profiling granularity passed to TestPlayer
*/
void TestSuite::CasePlayer(int level) { TestPlayer tp(level); }

/*!
 * @brief    Initiates the Test for the StageManager Module
 * @param[in] level  Profiling granularity passed to TestStage
*/
void TestSuite::CaseStage(int level) { TestStage tg(level); }

/*!
 * @brief    Initiates the Test for the CombatStrategy Module
 * @param[in] level  Profiling granularity passed to TestStrategy
*/
void TestSuite::CaseStrategy(int level) { TestStrategy ts(level); }

/*!
 * @brief    Initiates the Test for the Toon Module
 * @param[in] level  Profiling granularity passed to TestToon
*/
void TestSuite::CaseToon(int level) { TestToon tt(level); }

/*!
 * @brief    Initiates the Test for the Utilz Module
 * @param[in] level  Profiling granularity passed to TestUtilz
*/
void TestSuite::CaseUtilz(int level) { TestUtilz tu(level); }

/*!
 * @brief    Initiates the Test for the Weapon Module
 * @param[in] level  Profiling granularity passed to TestWeapon
*/
void TestSuite::CaseWeapon(int level) { TestWeapon tw(level); }

/*!
 * @brief   Default Deconstructor
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
  char buf[128];
  int choice = 0;
  choice = atoi(argv[1]);
  std::thread cact, caud, cbac, cbal, cbat, cclo, ccip, ccom, ccon, cequ, cite, clea, clex, cpla, csta, ctoo, cuti, cwea;
  
  switch (choice) {
    case 0: 
      sprintf(buf, "All TestCases' Completed...");
      ts.TestAll();
      break;
    case 1:  sprintf(buf, "Actor TestCase Completed...");     ts.CaseActor(1);     break;
    case 2:  sprintf(buf, "Audio TestCase Completed...");     ts.CaseAudio(1);     break;
    case 3:  sprintf(buf, "Backpack TestCase Completed...");  ts.CaseBackpack(1);  break;
    case 4:  sprintf(buf, "Balance TestCase Completed...");   ts.CaseBalance(1);   break;
    case 5:  sprintf(buf, "Battle TestCase Completed...");    ts.CaseBattle(1);    break;
    case 6:  sprintf(buf, "Clock TestCase Completed...");     ts.CaseClock(1);     break;
    case 7:  sprintf(buf, "Ciphers TestCase Completed...");   ts.CaseCiphers(1);   break;
    case 8:  sprintf(buf, "Combat TestCase Completed...");    ts.CaseCombat(1);    break;
    case 9:  sprintf(buf, "Config TestCase Completed...");    ts.CaseConfig(1);    break;
    case 10: sprintf(buf, "Equipment TestCase Completed..."); ts.CaseEquipment(1); break;
    case 11: sprintf(buf, "Item TestCase Completed...");      ts.CaseItem(1);      break;
    case 12: sprintf(buf, "Leader TestCase Completed...");    ts.CaseLeader(1);    break;
    case 13: sprintf(buf, "Lexicon TestCase Completed...");   ts.CaseLexicon(1);   break;
    case 14: sprintf(buf, "Player TestCase Completed...");    ts.CasePlayer(1);    break;
    case 15: sprintf(buf, "Stage TestCase Completed...");     ts.CaseStage(1);     break;
    case 16: sprintf(buf, "Strategy TestCase Completed...");  ts.CaseStrategy(1);  break;
    case 17: sprintf(buf, "Toon TestCase Completed...");      ts.CaseToon(1);      break;
    case 18: sprintf(buf, "Utilz TestCase Completed...");     ts.CaseUtilz(1);     break;
    case 19: sprintf(buf, "Weapon TestCase Completed...");    ts.CaseWeapon(1);    break;
    default:
      sprintf(buf, "\nWarn :: Unknown Test, please review the list and try again.\n");
  }
  Profiler::report();
  log->named_log(__FILENAME__, buf);
  return 0;
}
