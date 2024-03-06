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
  this->cnf = ConfigManager::GetInstance();
  this->lex = new Lexicon();
  this->log = Logger::GetInstance();
  this->combat = new Combat();
  this->start_time = std::chrono::steady_clock::now();
  this->prompt = ">";
}

std::string CLISuite::getPrompt() { return this->prompt; }

int CLISuite::appendCommandHistory(std::string incoming) {
  this->history.push_back(incoming);
  return this->history.size();
}

void CLISuite::displayCommandHistory() {
  this->log->named_log(__FILENAME__, "Command History Summation:");
  for (auto s : this->history) {
    this->log->named_log(__FILENAME__, s);
  }
}

void CLISuite::displayRunTime() {
  std::chrono::duration<double> time_d = (std::chrono::steady_clock::now() - this->start_time);
  sprintf(this->buf, "Experiment Duration: %.02fmin", (time_d / 60.00)); 
  this->log->named_log(__FILENAME__, buf);
}

/*! @todo    Helper Function to display help */
void CLISuite::print_help() {
  //! Establish Logger Object
  Logger* log = Logger::GetInstance();
  //! Get File Name
  std::string fileName = Utilz::FileName(__FILENAME__);

  //! Display Help 
  char buf[128];
  sprintf(buf, "\nUsage: %s.exe [bool|debug]", fileName.c_str()); 
  log->raw_log(buf);
  log->raw_log("\tdebug - Debugging Flag\n");
}

/*! @todo    Run Engine Commands */
void CLISuite::run_command(const std::string input, std::vector<std::string>& cmdline) {
  std::string tmp;
  int value = 0, idx = -1;
  idx = _CMDMAP[input];

  switch(idx) {
    case 0:   //! Help Info
      cli_help();
      break;
    case 1:   //! Exit Shell
      vshContinue = false;
      break;
    case 2:   //! Reload Config Options
      this->cnf->reload_state();
      break;
    case 3:   //! Generate Name 
      value = atoi(cmdline[1].c_str());
      for (int i = 0; i < value; i++) {
        tmp = lex->generateName(1);
        printf("%s", tmp.c_str()); 
      }
      printf("\n"); 
      break;
    case 4:   //! Chain Command 
      cmdline.erase(cmdline.begin());
      for (std::string c : cmdline) { printf("_ : %s\n", c.c_str()); }
      break;
    case 5:   //! Run Time
      this->displayRunTime();
      break;
    case 6:   //! Unimplemented Command 
    case 7:   //! Unimplemented Command 
    case 8:   //! Unimplemented Command 
    default:
      sprintf(this->buf, "Unimplemented Command: %s", input.c_str());
      log->named_log(__FILENAME__, this->buf);
      break;
  }
  this->history.push_back(input);
}

/*! @todo    Static Helper File for the CLISuite */
void CLISuite::cli_help() {
  ConfigManager* cnf = ConfigManager::GetInstance();
  std::vector<std::string> cmds;
  cnf->get_authorizedCommands(cmds);
  printf("Commands:\n");
  for (auto c : cmds) { printf(": %s\n", c.c_str()); }
}

/*! @todo   Function to parse user input for a command */
void CLISuite::parse_user_input(std::string input) {
  std::vector<std::string> cmds;
  std::vector<std::string> cmdline;
  Utilz::StringToArray(input, cmdline);
  char* token = strtok((char*)input.c_str(), " \n");
  cnf->get_authorizedCommands(cmds);
  if (std::find(cmds.begin(), cmds.end(), token) != cmds.end()) { this->run_command(token, cmdline); }
}

bool CLISuite::parse_input(const std::string input, const std::string criteria) {
  //! Establish Variables 
  size_t found = input.find(criteria);
  if (found != std::string::npos) { return false; }
  return true;
}

CLISuite::~CLISuite() { 
  this->displayRunTime(); 
  this->displayCommandHistory();
}

/*!
 * @brief   Module Entry Point
*/
int main(int argc, const char *argv[]) {
  //! Conditional Check
  if (argc < 2) { CLISuite::print_help(); return 0; }
  if (strcmp(argv[1], "-h") == 0) { CLISuite::print_help(); return 0; }

  //! Declare Variables
  CLISuite* cli = new CLISuite();
  Logger* log = Logger::GetInstance();                 //!< Establish Logger Object
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
      break;
    default: 
      CLISuite::print_help();
      return 0;
  }

  //! Interactive Shell
  /* ********************************** */
  while (vshContinue == true) {
    printf("%s ", cli->getPrompt().c_str());        //! Display Message Prompt
    std::getline(std::cin, rawInput);               //! Get User Input
    cli->parse_user_input(rawInput);                //! Parse User Input
  }
  /* ********************************** */

  log->named_log(__FILENAME__, "Engine Winding down...");
  log->named_log(__FILENAME__, "Summary: (Output Event Analysis)");
  if (cli) { delete cli; }
  return 0;
}
