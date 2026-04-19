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
  {"reset",     11},
  {"create",    12},
  {"inventory", 13},
};

CLISuite::CLISuite(bool debug) {
  this->cnf    = ConfigManager::GetInstance(debug);
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
    snprintf(this->buf, sizeof(this->buf), "\t[\t%-*s]", lead, s.c_str());
    this->log->named_log(__FILENAME__, this->buf);
  }
}

void CLISuite::displayRunTime() {
  std::chrono::duration<double> time_d = (std::chrono::steady_clock::now() - this->start_time);
  snprintf(this->buf, sizeof(this->buf), "Experiment Duration: %.02fmin", (time_d / 60.00));
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
  snprintf(buf, sizeof(buf), "\nUsage: %s.exe [bool|debug]", fileName.c_str());
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
      this->cnf->reload_state(true);
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
    case 12:  //! Create Item
      cmd_create(cmdline);
      break;
    case 13:  //! List Inventory
      cmd_inventory();
      break;
    default:
      snprintf(this->buf, sizeof(this->buf), "Unimplemented Command: %s", input.c_str());
      log->named_log(__FILENAME__, this->buf);
      break;
  }
  appendCommandHistory(input);
}

static const std::unordered_map<std::string, std::string> _HELPMAP = {
  {"help",      "help [command]             - show this list, or describe a command"},
  {"quit",      "quit                       - exit the CLI shell"},
  {"exit",      "exit                       - exit the CLI shell"},
  {"reload",    "reload                     - reload engine.ini config from disk"},
  {"name",      "name <count>               - generate <count> random names"},
  {"chain",     "chain <a> [b] ...          - echo a sequence of tokens"},
  {"runtime",   "runtime                    - print elapsed session time"},
  {"prompt",    "prompt <symbol>            - change the shell prompt symbol"},
  {"spawn",     "spawn <player|toon> [name] - create an actor in the next free slot"},
  {"fight",     "fight <pve|pvp|eve>        - start combat between spawned actors"},
  {"step",      "step                       - advance combat one cycle and show status"},
  {"status",    "status                     - print health and state of all spawned actors"},
  {"reset",     "reset                      - delete all actors and clear combat state"},
  {"create",    "create <type> [name]       - create an item and add it to inventory\n"
                "  Types: sword, shield, staff, ring, relic, backpack\n"
                "  Run 'help create <type>' for details on a specific type"},
  {"inventory", "inventory                  - list all items in the session inventory"},
};

static const std::unordered_map<std::string, std::string> _CREATEHELP = {
  {"sword",    "sword                       - melee weapon.  Boosts damage_multiplier (x1.5)"},
  {"shield",   "shield                      - defensive gear. Boosts damage_mitigation (x1.5)"},
  {"staff",    "staff                       - arcane focus.  Boosts flux_multiplier (x1.5)"},
  {"ring",     "ring                        - accessory.     Boosts damage and flux (x1.2 each)"},
  {"relic",    "relic                       - ancient item.  Boosts health_multiplier (x1.5)"},
  {"backpack", "backpack                    - wearable container. Neutral stats. Can hold any item.\n"
               "                              Future: stored item weights halved while worn"},
};

void CLISuite::cli_help(std::vector<std::string>& cmdline) {
  if (cmdline.size() >= 3 && cmdline[1] == "create") {
    auto it = _CREATEHELP.find(cmdline[2]);
    if (it != _CREATEHELP.end()) {
      printf("%s\n", it->second.c_str());
    } else {
      snprintf(this->buf, sizeof(this->buf), "Unknown create type: %s", cmdline[2].c_str());
      log->named_log(__FILENAME__, this->buf);
    }
    return;
  }
  if (cmdline.size() >= 2) {
    auto it = _HELPMAP.find(cmdline[1]);
    if (it != _HELPMAP.end()) {
      printf("%s\n", it->second.c_str());
    } else {
      snprintf(this->buf, sizeof(this->buf), "Unknown command: %s", cmdline[1].c_str());
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


void CLISuite::cmd_spawn(std::vector<std::string>& cmdline) {
  if (cmdline.size() < 2) {
    log->named_log(__FILENAME__, "Usage: spawn <player|toon> [name]");
    return;
  }
  const std::string& type = cmdline[1];
  std::string name = (cmdline.size() >= 3) ? cmdline[2] : lex->generateName(1);

  if (type == "player") {
    if      (!p1) { p1 = new Player(name, 1); snprintf(buf, sizeof(buf), "Spawned Player 1: %s", name.c_str()); }
    else if (!p2) { p2 = new Player(name, 2); snprintf(buf, sizeof(buf), "Spawned Player 2: %s", name.c_str()); }
    else          { snprintf(buf, sizeof(buf), "Both player slots occupied. Use reset to clear."); }
  } else if (type == "toon") {
    if      (!t1) { t1 = new Toon(name); snprintf(buf, sizeof(buf), "Spawned Toon 1: %s", name.c_str()); }
    else if (!t2) { t2 = new Toon(name); snprintf(buf, sizeof(buf), "Spawned Toon 2: %s", name.c_str()); }
    else          { snprintf(buf, sizeof(buf), "Both toon slots occupied. Use reset to clear."); }
  } else {
    snprintf(buf, sizeof(buf), "Unknown type: %s - use player or toon.", type.c_str());
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
    if (!p1 || !t1) { log->named_log(__FILENAME__, "fight pve requires p1 and t1 - use spawn"); return; }
    battle->startPVE(p1, t1);
    log->named_log(__FILENAME__, "PvE combat started. Use step to advance.");
  } else if (mode == "pvp") {
    if (!p1 || !p2) { log->named_log(__FILENAME__, "fight pvp requires p1 and p2 - use spawn"); return; }
    battle->startPVP(p1, p2);
    log->named_log(__FILENAME__, "PvP combat started. Use step to advance.");
  } else if (mode == "eve") {
    if (!t1 || !t2) { log->named_log(__FILENAME__, "fight eve requires t1 and t2 - use spawn"); return; }
    battle->startEVE(t1, t2);
    log->named_log(__FILENAME__, "EvE combat started. Use step to advance.");
  } else {
    snprintf(buf, sizeof(buf), "Unknown mode: %s - use pve, pvp, or eve.", mode.c_str());
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
    snprintf(buf, sizeof(buf), "[%s] %-16s | HP: %3d | %-8s | %s",
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

static const std::unordered_map<std::string, ItemType> _TYPEMAP = {
  {"relic",   RELIC},
  {"ring",    RING},
  {"shield",  SHIELD},
  {"staff",   STAFF},
  {"sword",   SWORD},
  {"backpack",BACKPACK},
};

void CLISuite::cmd_create(std::vector<std::string>& cmdline) {
  if (cmdline.size() < 2) {
    log->named_log(__FILENAME__, "Usage: create <sword|shield|staff|ring|relic|backpack> [name]");
    return;
  }
  const std::string& typeStr = cmdline[1];
  auto it = _TYPEMAP.find(typeStr);
  if (it == _TYPEMAP.end()) {
    snprintf(buf, sizeof(buf), "Unknown item type: %s", typeStr.c_str());
    log->named_log(__FILENAME__, buf);
    return;
  }
  ItemType type = it->second;
  std::string name = (cmdline.size() >= 3) ? cmdline[2] : lex->generateName(1);

  Item* item = nullptr;
  if (type == BACKPACK) {
    item = new Backpack(name.c_str());
  } else {
    item = new Equipment(name.c_str(), type);
  }
  inventory.push_back(item);
  snprintf(buf, sizeof(buf), "Created %s: %s (inventory: %zu)", typeStr.c_str(), name.c_str(), inventory.size());
  log->named_log(__FILENAME__, buf);
}

void CLISuite::cmd_inventory() {
  if (inventory.empty()) {
    log->named_log(__FILENAME__, "Inventory is empty. Use: create <type> [name]");
    return;
  }
  snprintf(buf, sizeof(buf), "Inventory (%zu items):", inventory.size());
  log->named_log(__FILENAME__, buf);
  for (size_t i = 0; i < inventory.size(); i++) {
    snprintf(buf, sizeof(buf), "  [%zu] %s", i, inventory[i]->get_label());
    log->named_log(__FILENAME__, buf);
  }
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
  for (Item* i : inventory) { delete i; }
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
  CLISuite* cli;
  Logger* log = Logger::GetInstance();                 //!< Establish Logger Object
  size_t found;
  std::string prompt = ">";
  std::string rawInput;
  log->named_log(__FILENAME__, "CLI Suite Loaded!");

  //! Input Switch Case
  char _input = argv[1][0];
  log->named_log(__FILENAME__, "Engine Firing up...");
  vshContinue = true;
  switch (_input) {
    case '0': 
      cli = new CLISuite(false);
      break;
    case '1':
      cli = new CLISuite(true);
      break;
    default: 
      CLISuite::print_help();
      return 0;
  }

  //! Interactive Shell
  /* ********************************** */
  while (vshContinue == true && cli != nullptr) {
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
