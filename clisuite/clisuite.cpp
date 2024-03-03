/*! 
 * @class   CLISuite clisuite.cpp clisuite.h
 * @brief   Command Line Interface (CLI) for Engine.
*/
#include "clisuite.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

//! Extern Variable Declaration
std::string  _cnf_ = "docs/engine.ini";
bool vshContinue = false;

CLISuite::CLISuite() { 
  this->log = Logger::GetInstance();
  this->combat = new Combat();
  this->start_time = std::clock(); 
}

CLISuite::~CLISuite() {
  char buf[512];
  sprintf(buf, "Experiment Duration: %.02fm\n", float(std::clock() - this->start_time) / 60'000);
  this->log->named_log(__FILENAME__, buf);
}

/*! @todo   Function to parse user input for a command */
void parse_user_input(std::string input) {
  ConfigManager* cnf = ConfigManager::GetInstance();
  std::vector<std::string> cmds;
  std::vector<std::string> cmdline;
  Utilz::StringToArray(input, cmdline);
  char* token = strtok((char*)input.c_str(), " \n");
  cnf->get_authorizedCommands(cmds);
  char buf[64];
  if (std::find(cmds.begin(), cmds.end(), token) != cmds.end()) { run_command(token, cmdline); }
}

/*!
 * @brief   Helper Function to parse input
 * @param[in] input - String to be searched through
 * @param[in] criteria - String being searched for
*/
bool parse_input(const std::string input, const std::string criteria) {
  //! Establish Variables 
  size_t found = input.find(criteria);
  if (found != std::string::npos) { return false; }
  return true;
}

/*! @todo    Helper Function to display help */
void print_help() {
  //! Establish Logger Object
  Logger* log = Logger::GetInstance();
  //! Get File Name
  std::string fileName = Utilz::FileName(__FILENAME__);

  //! Display Help 
  char buf[64];
  sprintf(buf, "\nUsage: %s.exe [bool|debug]", fileName.c_str()); 
  log->raw_log(buf);
  log->raw_log("\tdebug - Debugging Flag\n");
}

/*! @todo    Static Helper File for the CLISuite */
void cli_help() {
  ConfigManager* cnf = ConfigManager::GetInstance();
  std::vector<std::string> cmds;
  cnf->get_authorizedCommands(cmds);
  printf("Commands:\n");
  for (auto c : cmds) { printf(": %s\n", c.c_str()); }
}

/*! @todo    Run Engine Commands */
void run_command(const std::string input, std::vector<std::string>& cmdline) {
  ConfigManager* cnf = ConfigManager::GetInstance();   //!< Establish ConfigManager Object
  Lexicon* lex = new Lexicon();                        //!< Establish Lexicon Object
  Logger* log = Logger::GetInstance();                 //!< Establish Logger Object
  int value;
  char buf[256];
  std::string tmp;
  std::vector<std::string> cmds;
  cnf->get_authorizedCommands(cmds);
  int idx = _CMDMAP[input];

  switch(idx) {
    case 0:   //! Help Info
      cli_help();
      break;
    case 1:   //! Exit Shell
      vshContinue = false;
      break;
    case 2:   //! Reload Config Options
      cnf->reload_state();
      break;
    case 3:   //! Generate Name 
      value = atoi(cmdline[1].c_str());
      for (int i = 0; i < value; i++) {
        tmp = lex->generateName(1);
        printf("%s", tmp.c_str()); 
      }
      printf("\n"); 
      break;
    case 4:   //! Test Command 
      cmdline.erase(cmdline.begin());
      for (std::string c : cmdline) { printf("_ : %s\n", c.c_str()); }
      break;
    case 5:   //! Unimplemented Command 
    case 6:   //! Unimplemented Command 
    case 8:   //! Unimplemented Command 
    case 9:   //! Unimplemented Command 
    default:
      sprintf(buf, "Unimplemented Command: %s", input.c_str());
      log->named_log(__FILENAME__, buf);
      break;
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
  Logger* log = Logger::GetInstance();                 //!< Establish Logger Object
  CLISuite* cli;
  size_t found;
  std::string prompt = ">";
  std::string rawInput;
  log->named_log(__FILENAME__, "CLI Suite Loaded!");

  //! Input Switch Case
  char _input = argv[1][0];
  switch (_input) {
    case '0': 
      return 0;
    case '1':
      log->named_log(__FILENAME__, "Engine Firing up...");
      vshContinue = true;
      cli = new CLISuite();
      break;
    default: 
      print_help();
      return 0;
  }

  //! Interactive Shell
  /* ********************************** */
  while (vshContinue == true) {
    printf("%s ", prompt.c_str());                  //! Display Message Prompt
    std::getline(std::cin, rawInput);               //! Get User Input
    parse_user_input(rawInput);                     //! Parse User Input
    // vshContinue = parse_input(rawInput, "!exit");   //! Conditional to end Shell
  }
  /* ********************************** */

  log->named_log(__FILENAME__, "Engine Winding down...");
  log->named_log(__FILENAME__, "Summary:\n(Output Event Analysis)");
  if (cli) { delete cli; }
  return 0;
}
