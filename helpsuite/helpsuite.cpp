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
  this->HelpActor();
}

/*!
 * @brief   FIXME: Needs desc
*/
void HelpSuite::HelpActor() { new ActorHelp(); }

/*!
 * @brief   Helper hook for CLI Tool to display help details
*/
void HelpSuite::_help() { 
  print_help();
}

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
  log->raw_log("\t[1] - HelpSuit details");
  log->raw_log("\t[2] - Actor details");
  log->raw_log("\t[0] - Default Help to rule them all\n");
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
    case 1:
      hs._help();
      break;
    case 2:
      hs.HelpActor();
      break;
    default:
      log->named_log(__FILE__, "Default HelpSuite Msg");
      hs.HelpAll();
  }
  return 0;
}
