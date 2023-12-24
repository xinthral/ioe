/*!
 * @class   HelpSuite helpsuite.h helpsuite.cpp
 * @brief   Command Line Tool (CLI) for the HelpSuite
 * @details Helper Suite is meant to parse Doxygen outputs, and 
 *      provide a commandline utility for quick reference 
 *      while developing or debugging.
*/
#include "helpsuite.h"

/*!
 * @brief   Default Constructor
*/
HelpSuite::HelpSuite() { 
  cnf = ConfigManager::GetInstance();
  log = Logger::GetInstance();
  log->named_log(__FILE__, "Helper Loaded!");
}

/*!
 * @overload
 * @brief   Debugging Constructor
 * @param[in] _debug Debugging option 
*/
HelpSuite::HelpSuite(bool _debug) : HelpSuite() { }

/*!
 * @brief   FIXME: Needs desc
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
 * @brief   FIXME: Needs desc
*/
void HelpSuite::ActorHelp() { HelpActor* ha = new HelpActor(); }

/*!
 * @brief   FIXME: Needs desc
*/
void HelpSuite::BalanceHelp() { HelpBalance* hb = new HelpBalance(); }

/*!
 * @brief   FIXME: Needs desc
*/
void HelpSuite::BattleHelp() { HelpBattle* hb = new HelpBattle(); }

/*!
 * @brief   FIXME: Needs desc
*/
void HelpSuite::CombatHelp() { HelpCombat* hc = new HelpCombat(); }

/*!
 * @brief   FIXME: Needs desc
*/
void HelpSuite::ItemHelp() { HelpItem* hi = new HelpItem(); }

/*!
 * @brief   FIXME: Needs desc
*/
void HelpSuite::PlayerHelp() { HelpPlayer* hp = new HelpPlayer(); }

/*!
 * @brief   FIXME: Needs desc
*/
void HelpSuite::StageHelp() { HelpStage* hs = new HelpStage(); }

/*!
 * @brief   FIXME: Needs desc
*/
void HelpSuite::ToonHelp() { HelpToon* hs = new HelpToon(); }

/*!
 * @brief   FIXME: Needs desc
*/
void HelpSuite::UtilzHelp() { HelpUtilz* hs = new HelpUtilz(); }

/*!
 * @brief   Helper hook for CLI Tool to display help details
*/
void HelpSuite::_help() { print_help(); }

/*!
 * @brief   Default Deconstructor
*/
HelpSuite::~HelpSuite() {}

/*!
 * @brief   Static Function to display help details
*/
void print_help() {
  Logger* log = Logger::GetInstance();
  std::string fileName = Utilz::FileName(__FILE__);
  char buf[64];
  sprintf(buf, "Usage: %s.exe [option]\n", fileName.c_str()); 
  log->raw_log(buf);
  log->raw_log("HelpSuite CLI Tool\n");
  log->raw_log("A helper system, to give the developer/debugger" \
    " a quality-of-life option for hunting down all my stupid." \
    " This can be used in conjuction with the TestSuite in order to"\
    " maximize the benefit of the CLI Debugging Suite.\n");
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
  log->raw_log("\t [0] - Default Help to rule them all\n");
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
      log->named_log(__FILE__, "Displaying full HelpSuite");
      hs.HelpAll();
  }
  return 0;
}
