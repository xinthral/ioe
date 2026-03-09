#ifndef XAPI_H
#define XAPI_H

#include <getopt.h>
#include <stdio.h>
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

class APIEngine {
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
  APIEngine();
  Player create_player();
  void parse_instruction();
  static void print_help();
  static void print_version();
};

#endif // XAPI_H //