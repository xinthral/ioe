#include "helpsuite.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor
*/
HelpSuite::HelpSuite() { 
  cnf = ConfigManager::GetInstance();
  log = Logger::GetInstance();
  log->named_log(__FILENAME__, "Helper Loaded!");
}

/*!
 * @todo    Debugging Constructor
*/
HelpSuite::HelpSuite(bool _debug) : HelpSuite() { }

/*!
 * @todo    FIXME: Needs desc
*/
void HelpSuite::HelpAll() { 
  this->_help();
  this->ActorHelp();
  this->BalanceHelp();
  this->BattleHelp();
  this->CombatHelp();
  this->ItemHelp();
  this->PlayerHelp();
  this->StageHelp();
  this->ToonHelp();
  this->UtilzHelp();
}

/*!
 * @todo    FIXME: Needs desc
*/
void HelpSuite::ActorHelp() { HelpActor* ha = new HelpActor(); }

/*!
 * @todo    FIXME: Needs desc
*/
void HelpSuite::BalanceHelp() { HelpBalance* hb = new HelpBalance(); }

/*!
 * @todo    FIXME: Needs desc
*/
void HelpSuite::BattleHelp() { HelpBattle* hb = new HelpBattle(); }

/*!
 * @todo    FIXME: Needs desc
*/
void HelpSuite::CombatHelp() { HelpCombat* hc = new HelpCombat(); }

/*!
 * @todo    FIXME: Needs desc
*/
void HelpSuite::ItemHelp() { HelpItem* hi = new HelpItem(); }

/*!
 * @todo    FIXME: Needs desc
*/
void HelpSuite::PlayerHelp() { HelpPlayer* hp = new HelpPlayer(); }

/*!
 * @todo    FIXME: Needs desc
*/
void HelpSuite::StageHelp() { HelpStage* hs = new HelpStage(); }

/*!
 * @todo    FIXME: Needs desc
*/
void HelpSuite::ToonHelp() { HelpToon* hs = new HelpToon(); }

/*!
 * @todo    FIXME: Needs desc
*/
void HelpSuite::UtilzHelp() { HelpUtilz* hs = new HelpUtilz(); }

/*!
 * @todo    Helper hook for CLI Tool to display help details
*/
void HelpSuite::_help() { print_help(); }

/*!
 * @todo    Default Deconstructor
*/
HelpSuite::~HelpSuite() {}

/*!
 * @todo    Static Function to display help details
*/
void print_help() {
  Logger* log = Logger::GetInstance();
  std::string fileName = Utilz::FileName(__FILENAME__);
  char buf[64];
  sprintf(buf, "Usage: %s.exe [option]\n", fileName.c_str()); 
  log->raw_log(buf);
  log->raw_log("HelpSuite CLI Tool\n");
  log->raw_log("A helper system, to give the developer/debugger" \
    " a quality-of-life option for hunting down all my stupid." \
    " This can be used in conjuction with the TestSuite in order to"\
    " maximize the benefit of the CLI Debugging Suite.\n");
  log->raw_log("\t [0] - Default Help to rule them all");
  log->raw_log("\t [1] - Actor details");
  log->raw_log("\t [2] - BalanceController details");
  log->raw_log("\t [3] - Battle details");
  log->raw_log("\t [4] - Combat details");
  log->raw_log("\t [5] - HelpSuit details");
  log->raw_log("\t [6] - Item details");
  log->raw_log("\t [7] - Player details");
  log->raw_log("\t [8] - StageManager details");
  log->raw_log("\t [9] - Toon details");
  log->raw_log("\t[10] - Utilz details");
  log->raw_log("\n");
}

/*!
 * @brief   Module Entry Point
*/
int main(int argc, char const *argv[]) {
  if (argc < 2 || strcmp(argv[1], "-h") == 0) { print_help(); return 0; }
  HelpSuite hs;
  Logger* log = Logger::GetInstance();
  int idx = atoi(argv[1]);
  switch(idx) {
    case 1: //! Display Actor Help Details
      hs.ActorHelp();
      break;
    case 2: //! Display Balance Help Details
      hs.BalanceHelp();
      break;
    case 3: //! Display Battle Help Details
      hs.BattleHelp();
      break;
    case 4: //! Display Combat Help Details
      hs.CombatHelp();
      break;
    case 5: //! Display HelpSuite Helper Details
      hs._help();
      break;
    case 6: //! Display Item Help Details
      hs.ItemHelp();
      break;
    case 7: //! Display Player Help Details
      hs.PlayerHelp();
      break;
    case 8: //! Display Stage Help Details
      hs.StageHelp();
      break;
    case 9: //! Display Toon Help Details
      hs.ToonHelp();
      break;
    case 10: //! Display Utilz Help Details
      hs.UtilzHelp();
      break;
    default:
      log->named_log(__FILENAME__, "Displaying full HelpSuite");
      hs.HelpAll();
  }
  return 0;
}
