#include "clisuite.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

bool vshContinue = false;

//! Command dispatch map
std::unordered_map<std::string, int> _CMDMAP = {
  {"help",    0},
  {"quit",    1},
  {"exit",    1},
  {"reload",  2},
  {"name",    3},
  {"chain",   4},
  {"runtime", 5},
  {"prompt",  6},
  {"spawn",   7},
  {"fight",   8},
  {"step",    9},
  {"status",  10},
  {"reset",   11},
};

CLISuite::CLISuite() {
  this->cnf    = ConfigManager::GetInstance();
  this->lex    = new Lexicon();
  this->log    = Logger::GetInstance();
  this->battle = Battle::GetInstance();
  this->p1 = this->p2 = nullptr;
  this->t1 = this->t2 = nullptr;
  this->start_time = std::chrono::steady_clock::now();
  this->prompt = ">";
}

std::string CLISuite::getPrompt() { return this->prompt; }
void CLISuite::setPrompt(std::string input) { this->prompt = input; }

int CLISuite::appendCommandHistory(std::string incoming) {
  this->history.push_back(incoming);
  return this->history.size();
}

void CLISuite::displayCommandHistory() {
  this->log->named_log(__FILENAME__, "Command History Summation:");
  int lead = 12;
  for (auto s : this->history) {
    sprintf(this->buf, "\t[\t%-*s]", lead, s.c_str());
    this->log->named_log(__FILENAME__, this->buf);
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
      cli_help(cmdline);
      break;
    case 1:   //! Exit Shell
      vshContinue = false;
      break;
    case 2:   //! Reload Config Options
      this->cnf->reload_state();
      break;
    case 3:   //! Generate Name
      if (cmdline.size() < 2) { log->named_log(__FILENAME__, "Usage: name <count>"); break; }
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
    case 6:   //! Change Prompt
      if (cmdline.size() < 2) { log->named_log(__FILENAME__, "Usage: prompt <symbol>"); break; }
      this->setPrompt(cmdline[1]);
      break;
    case 7:   //! Spawn Actor
      cmd_spawn(cmdline);
      break;
    case 8:   //! Start Combat
      cmd_fight(cmdline);
      break;
    case 9:   //! Step Combat Cycle
      cmd_step();
      break;
    case 10:  //! Show Actor Status
      cmd_status();
      break;
    case 11:  //! Reset Combat State
      cmd_reset();
      break;
    default:
      sprintf(this->buf, "Unimplemented Command: %s", input.c_str());
      log->named_log(__FILENAME__, this->buf);
      break;
  }
  appendCommandHistory(input);
}

static const std::unordered_map<std::string, std::string> _HELPMAP = {
  {"help",    "help [command]          - show this list, or describe a command"},
  {"quit",    "quit                    - exit the CLI shell"},
  {"exit",    "exit                    - exit the CLI shell"},
  {"reload",  "reload                  - reload engine.ini config from disk"},
  {"name",    "name <count>            - generate <count> random names"},
  {"chain",   "chain <a> [b] ...       - echo a sequence of tokens"},
  {"runtime", "runtime                 - print elapsed session time"},
  {"prompt",  "prompt <symbol>         - change the shell prompt symbol"},
  {"spawn",   "spawn <player|toon> [name] - create an actor in the next free slot"},
  {"fight",   "fight <pve|pvp|eve>     - start combat between spawned actors"},
  {"step",    "step                    - advance combat one cycle and show status"},
  {"status",  "status                  - print health and state of all spawned actors"},
  {"reset",   "reset                   - delete all actors and clear combat state"},
};

void CLISuite::cli_help(std::vector<std::string>& cmdline) {
  if (cmdline.size() >= 2) {
    auto it = _HELPMAP.find(cmdline[1]);
    if (it != _HELPMAP.end()) {
      printf("%s\n", it->second.c_str());
    } else {
      sprintf(this->buf, "Unknown command: %s", cmdline[1].c_str());
      log->named_log(__FILENAME__, this->buf);
    }
    return;
  }
  std::vector<std::string> cmds;
  this->cnf->get_authorizedCommands(cmds);
  printf("Commands:\n");
  for (auto& c : cmds) {
    auto it = _HELPMAP.find(c);
    if (it != _HELPMAP.end()) { printf("  %s\n", it->second.c_str()); }
    else                      { printf("  %s\n", c.c_str()); }
  }
}

/*! @brief   Parse and dispatch a raw input string from the REPL loop */
void CLISuite::parse_user_input(std::string input) {
  std::vector<std::string> cmds;
  std::vector<std::string> cmdline;
  Utilz::StringToArray(input, cmdline);
  if (cmdline.empty()) { return; }
  const std::string& token = cmdline[0];
  cnf->get_authorizedCommands(cmds);
  if (std::find(cmds.begin(), cmds.end(), token) != cmds.end()) { this->run_command(token, cmdline); }
}

static const char* combatStateStr(CombatState s) {
  switch(s) {
    case IDLE:   return "IDLE";
    case PATROL: return "PATROL";
    case FIGHT:  return "FIGHT";
    case FLEE:   return "FLEE";
    case HIDE:   return "HIDE";
    case FOLLOW: return "FOLLOW";
    default:     return "UNKNOWN";
  }
}

static const char* healthStateStr(HealthState s) {
  switch(s) {
    case HEALTHY:  return "HEALTHY";
    case HURTING:  return "HURTING";
    case CRITICAL: return "CRITICAL";
    case SICK:     return "SICK";
    case DEAD:     return "DEAD";
    default:       return "UNKNOWN";
  }
}

void CLISuite::cmd_spawn(std::vector<std::string>& cmdline) {
  if (cmdline.size() < 2) {
    log->named_log(__FILENAME__, "Usage: spawn <player|toon> [name]");
    return;
  }
  const std::string& type = cmdline[1];
  std::string name = (cmdline.size() >= 3) ? cmdline[2] : lex->generateName(1);

  if (type == "player") {
    if      (!p1) { p1 = new Player(name, 1); sprintf(buf, "Spawned Player 1: %s", name.c_str()); }
    else if (!p2) { p2 = new Player(name, 2); sprintf(buf, "Spawned Player 2: %s", name.c_str()); }
    else          { sprintf(buf, "Both player slots occupied. Use reset to clear."); }
  } else if (type == "toon") {
    if      (!t1) { t1 = new Toon(name); sprintf(buf, "Spawned Toon 1: %s", name.c_str()); }
    else if (!t2) { t2 = new Toon(name); sprintf(buf, "Spawned Toon 2: %s", name.c_str()); }
    else          { sprintf(buf, "Both toon slots occupied. Use reset to clear."); }
  } else {
    sprintf(buf, "Unknown type: %s — use player or toon.", type.c_str());
  }
  log->named_log(__FILENAME__, buf);
}

void CLISuite::cmd_fight(std::vector<std::string>& cmdline) {
  if (cmdline.size() < 2) {
    log->named_log(__FILENAME__, "Usage: fight <pve|pvp|eve>");
    return;
  }
  const std::string& mode = cmdline[1];

  if (mode == "pve") {
    if (!p1 || !t1) { log->named_log(__FILENAME__, "fight pve requires p1 and t1 — use spawn"); return; }
    battle->startPVE(p1, t1);
    log->named_log(__FILENAME__, "PvE combat started. Use step to advance.");
  } else if (mode == "pvp") {
    if (!p1 || !p2) { log->named_log(__FILENAME__, "fight pvp requires p1 and p2 — use spawn"); return; }
    battle->startPVP(p1, p2);
    log->named_log(__FILENAME__, "PvP combat started. Use step to advance.");
  } else if (mode == "eve") {
    if (!t1 || !t2) { log->named_log(__FILENAME__, "fight eve requires t1 and t2 — use spawn"); return; }
    battle->startEVE(t1, t2);
    log->named_log(__FILENAME__, "EvE combat started. Use step to advance.");
  } else {
    sprintf(buf, "Unknown mode: %s — use pve, pvp, or eve.", mode.c_str());
    log->named_log(__FILENAME__, buf);
  }
}

void CLISuite::cmd_step() {
  bool pendingWork = true;
  battle->doCycleWork(pendingWork);
  if (!pendingWork) { log->named_log(__FILENAME__, "Combat concluded."); }
  cmd_status();
}

void CLISuite::cmd_status() {
  if (!p1 && !p2 && !t1 && !t2) {
    log->named_log(__FILENAME__, "No actors spawned. Use: spawn <player|toon> [name]");
    return;
  }
  auto printActor = [&](const char* slot, Actor* a) {
    sprintf(buf, "[%s] %-16s | HP: %3d | %-8s | %s",
      slot, a->get_name().c_str(), a->get_health(),
      healthStateStr(a->get_healthstate()),
      combatStateStr(a->get_combatstate()));
    log->named_log(__FILENAME__, buf);
  };
  if (p1) printActor("P1", p1);
  if (p2) printActor("P2", p2);
  if (t1) printActor("T1", t1);
  if (t2) printActor("T2", t2);
}

void CLISuite::cmd_reset() {
  delete p1; p1 = nullptr;
  delete p2; p2 = nullptr;
  delete t1; t1 = nullptr;
  delete t2; t2 = nullptr;
  log->named_log(__FILENAME__, "All actors cleared.");
}

CLISuite::~CLISuite() {
  delete p1; delete p2;
  delete t1; delete t2;
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
