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
  this->ClockHelp();
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
void HelpSuite::CipherHelp() { HelpCipher* hf = new HelpCipher(); }

/*!
 * @todo    FIXME: Needs desc
*/
void HelpSuite::ClockHelp() { HelpClock* hc = new HelpClock(); }

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
void HelpSuite::LexiconHelp() { HelpLexicon* hi = new HelpLexicon(); }

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
	int i = 0;
  sprintf(buf, "Usage: %s.exe [option]\n", fileName.c_str()); 
  log->raw_log(buf);
  log->raw_log("HelpSuite CLI Tool\n");
  log->raw_log("A helper system, to give the developer/debugger" \
    " a quality-of-life option for hunting down all my stupid." \
    " This can be used in conjuction with the TestSuite in order to"\
    " maximize the benefit of the CLI Debugging Suite.\n");
  sprintf(buf, "\t [%d] - Default Help to rule them all", i++); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Actor details", i++); log->raw_log(buf);
  sprintf(buf, "\t [%d] - BalanceController details", i++); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Battle details", i++); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Cipher details", i++); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Clock details", i++); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Combat details", i++); log->raw_log(buf);
  sprintf(buf, "\t [%d] - HelpSuit details", i++); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Item details", i++); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Lexicon details", i++); log->raw_log(buf);
  sprintf(buf, "\t[%d] - Player details", i++); log->raw_log(buf);
  sprintf(buf, "\t[%d] - StageManager details", i++); log->raw_log(buf);
  sprintf(buf, "\t[%d] - Toon details", i++); log->raw_log(buf);
  sprintf(buf, "\t[%d] - Utilz details", i++); log->raw_log(buf);
  sprintf(buf, "\n"); log->raw_log(buf);
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
    case 4: //! Display Cipher Help Details
      hs.CipherHelp();
      break;
    case 5: //! Display Clock Help Details
      hs.ClockHelp();
      break;
    case 6: //! Display Combat Help Details
      hs.CombatHelp();
      break;
    case 7: //! Display HelpSuite Helper Details
      hs._help();
      break;
    case 8: //! Display Item Help Details
      hs.ItemHelp();
      break;
    case 9: //! Display Lexicon Help Details
      hs.LexiconHelp();
      break;
    case 10: //! Display Player Help Details
      hs.PlayerHelp();
      break;
    case 11: //! Display Stage Help Details
      hs.StageHelp();
      break;
    case 12: //! Display Toon Help Details
      hs.ToonHelp();
      break;
    case 13: //! Display Utilz Help Details
      hs.UtilzHelp();
      break;
    default:
      log->named_log(__FILENAME__, "Displaying full HelpSuite");
      hs.HelpAll();
  }
  return 0;
}
