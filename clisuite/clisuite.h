#ifndef XENGINE_H
#define XENGINE_H

#include <chrono>
#include <iostream>
#include <string.h>
#include <vector>
#include "../core/actor.h"
#include "../core/audio.h"
#include "../core/balance.h"
#include "../core/battle.h"
#include "../core/ciphers.h"
#include "../core/combat.h"
#include "../core/config.h"
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
	ConfigManager *cnf;                     //!< Establish ConfigManager Object
	Lexicon *lex;                           //!< Establish Lexicon Object
  Player *p1, *p2;
  Toon *t1, *t2;
  Combat *combat;
  Logger *log;

  std::vector<std::string> history;
  std::chrono::time_point<std::chrono::steady_clock> start_time;
  std::string prompt;
  char buf[128];

public:

  /*!
   * @brief   Helper Function to display help
  */
  CLISuite();

  std::string getPrompt();

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
  * @brief   Function to parse user input for a command 
  * @param[in] input - Command string from the command line
  */
  void parse_user_input(std::string);

  /*!
   * @brief   Helper Function to parse input
   * @param[in] input - String to be searched through
   * @param[in] criteria - String being searched for
  */
  bool parse_input(const std::string, const std::string);

  /*!
   * @brief   Helper Function to display help
  */
  void run_command(const std::string,std::vector<std::string>&);

  /*!
   * @brief   Helper Function to display help
  */
  static void print_help();

  /*!
   * @brief   Static Helper File for the CLISuite
  */
  void cli_help();
  ~CLISuite();
};

/*!
 * @brief   Map
*/
std::unordered_map<std::string, int> _CMDMAP = {
  {"help",    0},
	{"quit",    1},
  {"exit",    1},
  {"reload",  2},
  {"name",    3},
  {"chain",   4},
	{"runtime", 5}
};

#endif // XENGINE_H //
