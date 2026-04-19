#ifndef XENGINE_H
#define XENGINE_H

#include <chrono>
#include <iostream>
#include <string.h>
#include <unordered_map>
#include <vector>
#include "../core/actor.h"
#include "../core/audio.h"
#include "../core/backpack.h"
#include "../core/balance.h"
#include "../core/battle.h"
#include "../core/ciphers.h"
#include "../core/combat.h"
#include "../core/config.h"
#include "../core/equipment.h"
#include "../core/lexicon.h"
#include "../core/logger.h"
#include "../core/player.h"
#include "../core/stage.h"
#include "../core/toon.h"

/*! 
 * @class   CLISuite clisuite.cpp clisuite.h
 * @brief   Command Line Interface (CLI) for Engine.
*/

class CLISuite {
protected:
private:
  ConfigManager *cnf;   //!< Establish ConfigManager Object
  Lexicon       *lex;   //!< Establish Lexicon Object
  Battle        *battle;//!< Establish Battle Object
  Logger        *log;   //!< Establish Logger Object
  Player *p1, *p2;             //!< Player slots
  Toon   *t1, *t2;             //!< Toon slots
  std::vector<Item*> inventory; //!< Session item inventory

  std::vector<std::string> history;
  std::chrono::time_point<std::chrono::steady_clock> start_time;
  std::string prompt;
  char buf[128];

public:

  /*!
   * @brief   Helper Function to display help
  */
  CLISuite(bool);

  std::string getPrompt();
  void setPrompt(std::string);


  /*!
   * @brief   Helper Function to display help
  */
  int appendCommandHistory(std::string);

  /*!
   * @brief   Helper Function to display help
  */
  void displayCommandHistory();

  /*!
   * @brief   Helper Function to display help
  */
  void displayRunTime();

  /*!
   * @brief   Parse and dispatch a raw input string from the REPL loop.
   * @details Splits the input into tokens using Utilz::StringToArray. The first
   *          token is matched against the authorized command list from ConfigManager.
   *          If a match is found, the full token list is forwarded to run_command
   *          for dispatch. Unrecognized commands and blank lines are silently ignored.
   * @param[in] input - Raw string from std::getline
  */
  void parse_user_input(std::string);

  /*!
   * @brief   Helper Function to display help
  */
  void run_command(const std::string,std::vector<std::string>&);

  /*!
   * @brief   Helper Function to display help
  */
  static void print_help();

  /*!
   * @brief   Print help for all commands, or a single command if one is given.
   * @details Usage: help [command]
   *          With no argument, lists every authorized command with a one-line description.
   *          With an argument, prints the description for that command only.
   * @param[in] cmdline - Token list from the REPL (cmdline[1] is the optional command name)
  */
  void cli_help(std::vector<std::string>&);

  /*!
   * @brief   Spawn a Player or Toon into the session
   * @details Usage: spawn <player|toon> [name]
  */
  void cmd_spawn(std::vector<std::string>&);

  /*!
   * @brief   Start a combat session between spawned actors
   * @details Usage: fight <pve|pvp|eve>
  */
  void cmd_fight(std::vector<std::string>&);

  /*!
   * @brief   Advance combat by one cycle and print actor status
  */
  void cmd_step();

  /*!
   * @brief   Print the current state of all spawned actors
  */
  void cmd_status();

  /*!
   * @brief   Delete all spawned actors and clear combat state
  */
  void cmd_reset();

  /*!
   * @brief   Create an item and add it to the session inventory
   * @details Usage: create <sword|shield|staff|ring|relic|backpack> [name]
  */
  void cmd_create(std::vector<std::string>&);

  /*!
   * @brief   List all items in the session inventory
  */
  void cmd_inventory();

  ~CLISuite();
};

/*!
 * @brief   Command dispatch map - defined in clisuite.cpp
*/
extern std::unordered_map<std::string, int> _CMDMAP;

#endif // XENGINE_H //
