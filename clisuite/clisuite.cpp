/*! 
 * @class   CLISuite clisuite.cpp clisuite.h
 * @brief   Command Line Interface for Engine.
*/
#include "clisuite.h"

//! Extern Variable Declaration
std::string _CNF_ = "docs/engine.ini";

/*!
 * @brief   Function to parse user input for a command 
*/
void parse_user_input(std::string input) {
  std::vector<std::string> cmds;
  cnf->get_authorized_cli_commands(cmds);
  for (auto c : cmds) {
    std::cout << "CMD: " << c << std::endl;
  }
}

/*!
 * @brief   Helper Function to parse input
*/
bool parse_input(std::string input, std::string criteria) {
  //! Establish Variables 
  size_t found = input.find(criteria);
  if (found != std::string::npos) { return false; }
  return true;
}

/*!
 * @brief   Helper Function to display help
*/
void print_help() {
  //! Load Logger Object
  Logger* log = Logger::GetInstance();

  //! Get File Name
  std::string fileName = Utilz::FileName(__FILE__);

  //! Display Help 
  char buf[64];
  sprintf(buf, "\nUsage: ./%s <bool|debug>", fileName.c_str()); 
  log->raw_log(buf);
  log->raw_log("Param:\n  <bool|debug> - Debugging Flag\n");
  exit(-1);
}

/*!
 * @brief   Module Entry Point
*/
int main(int argc, char const *argv[]) {
  //! Conditional Check
  if (argc < 2) { print_help(); return 0; }
  if (strcmp(argv[1], "-h") == 0) { print_help(); return 0; }

  //! Declare Variables
  size_t found;
  bool vshContinue = false;
  std::string prompt = "> ";
  std::string rawInput;
  Logger* log = Logger::GetInstance();
  log->named_log(__FILE__, "CLI Suite Loaded!");

  //! Input Switch Case
  char _input = argv[1][0];
  switch (_input) {
    case '0': 
      return 0;
    case '1':
      log->named_log(__FILE__, "Engine Firing up...");
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

  log->named_log(__FILE__, "Engine Winding down...");
  log->named_log(__FILE__, "Summary:\n(Output Event Analysis)");
  return 0;
}
