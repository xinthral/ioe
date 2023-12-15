/*! 
 * @class   CLISuite clisuite.cpp clisuite.h
 * @brief   Command Line Interface for Engine.
*/
#include "clisuite.h"

//! Extern Variable Declaration
std::string __cnf_ = "docs/engine.ini";
Logger* _log = Logger::GetInstance();
ConfigManager* _cnf = ConfigManager::GetInstance();

/*!
 * @brief   Function to parse user input for a command 
*/
void parse_user_input(std::string input) {
  std::vector<std::string> cmds;
  char* token = strtok((char*)input.c_str(), " \n");
  _cnf->get_authorized_cli_commands(cmds);
  char buf[64];
  if (std::find(cmds.begin(), cmds.end(), token) != cmds.end()) {
    sprintf(buf, "Authorized command: %s!", token);
    _log->named_log(__FILE__, buf);
    // __FIXME: Now that the commands are authorized, do something with them.
  }
}

/*!
 * @brief   Helper Function to parse input
*/
bool parse_input(const std::string input, const std::string criteria) {
  //! Establish Variables 
  size_t found = input.find(criteria);
  if (found != std::string::npos) { return false; }
  return true;
}

/*!
 * @brief   Helper Function to display help
*/
void print_help() {
  //! Get File Name
  std::string fileName = Utilz::FileName(__FILE__);

  //! Display Help 
  char buf[64];
  sprintf(buf, "\nUsage: ./%s [bool|debug]", fileName.c_str()); 
  _log->raw_log(buf);
  _log->raw_log("\tdebug - Debugging Flag\n");
  exit(0);
}

/*!
 * @brief   Run Engine Commands
*/
void run_command(const std::string input) {
  std::vector<std::string> cmds;
  _cnf->get_authorized_cli_commands(cmds);
  int idx = 0;
  for (std::vector<std::string>::iterator itr = cmds.begin(); itr != cmds.end(); ++itr, ++idx) {
    if (strcmp((*itr).c_str(), input.c_str()) == 0) {

    }
  }
}

/*!
 * @brief   Module Entry Point
*/
int main(int argc, const char *argv[]) {
  //! Conditional Check
  if (argc < 2) { print_help(); return 0; }
  if (strcmp(argv[1], "-h") == 0) { print_help(); return 0; }

  //! Declare Variables
  size_t found;
  bool vshContinue = false;
  std::string prompt = "> ";
  std::string rawInput;
  _log->named_log(__FILE__, "CLI Suite Loaded!");

  //! Input Switch Case
  char _input = argv[1][0];
  switch (_input) {
    case '0': 
      return 0;
    case '1':
      _log->named_log(__FILE__, "Engine Firing up...");
      vshContinue = true;
      break;
    default: 
      print_help();
      return 0;
  }

  //! Interactive Shell
  /* ********************************** */
  while (vshContinue == true) {
    printf("%s", prompt.c_str());                  //! Display Message Prompt
    std::getline(std::cin, rawInput);              //! Get User Input
    vshContinue = parse_input(rawInput, "!exit");  //! Conditional to end Shell
    parse_user_input(rawInput);
  }
  /* ********************************** */

  _log->named_log(__FILE__, "Engine Winding down...");
  _log->named_log(__FILE__, "Summary:\n(Output Event Analysis)");
  return 0;
}
