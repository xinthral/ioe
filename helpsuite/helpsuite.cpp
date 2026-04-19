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
  this->BackpackHelp();
  this->BalanceHelp();
  this->BattleHelp();
  this->CipherHelp();
  this->ClockHelp();
  this->CombatHelp();
  this->ConfigHelp();
  this->EquipmentHelp();
  this->ItemHelp();
  this->LeaderHelp();
  this->LexiconHelp();
  this->PlayerHelp();
  this->StageHelp();
  this->ToonHelp();
  this->UtilzHelp();
}

/*!
 * @todo    FIXME: Needs desc
*/
void HelpSuite::ActorHelp()     { HelpActor*     ha = new HelpActor();     }
void HelpSuite::BackpackHelp()  { HelpBackpack*  hb = new HelpBackpack();  }
void HelpSuite::EquipmentHelp() { HelpEquipment* he = new HelpEquipment(); }
void HelpSuite::LeaderHelp()    { HelpLeader*    hl = new HelpLeader();    }

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
void HelpSuite::ConfigHelp() { HelpConfig * hc = new HelpConfig(); }

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
  sprintf(buf, "\t [%d] - Default Help (all modules)", i++); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Actor details", i++); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Backpack details", i++); log->raw_log(buf);
  sprintf(buf, "\t [%d] - BalanceController details", i++); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Battle details", i++); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Cipher details", i++); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Clock details", i++); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Combat details", i++); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Config details", i++); log->raw_log(buf);
  sprintf(buf, "\t [%d] - Equipment details", i++); log->raw_log(buf);
  sprintf(buf, "\t[%d] - HelpSuite details", i++); log->raw_log(buf);
  sprintf(buf, "\t[%d] - Item details", i++); log->raw_log(buf);
  sprintf(buf, "\t[%d] - Leader details", i++); log->raw_log(buf);
  sprintf(buf, "\t[%d] - Lexicon details", i++); log->raw_log(buf);
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
    case 1:  hs.ActorHelp();     break;
    case 2:  hs.BackpackHelp();  break;
    case 3:  hs.BalanceHelp();   break;
    case 4:  hs.BattleHelp();    break;
    case 5:  hs.CipherHelp();    break;
    case 6:  hs.ClockHelp();     break;
    case 7:  hs.CombatHelp();    break;
    case 8:  hs.ConfigHelp();    break;
    case 9:  hs.EquipmentHelp(); break;
    case 10: hs._help();         break;
    case 11: hs.ItemHelp();      break;
    case 12: hs.LeaderHelp();    break;
    case 13: hs.LexiconHelp();   break;
    case 14: hs.PlayerHelp();    break;
    case 15: hs.StageHelp();     break;
    case 16: hs.ToonHelp();      break;
    case 17: hs.UtilzHelp();     break;
    default:
      log->named_log(__FILENAME__, "Displaying full HelpSuite");
      hs.HelpAll();
  }
  return 0;
}
