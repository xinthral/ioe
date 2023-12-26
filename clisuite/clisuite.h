#ifndef XENGINE_H
#define XENGINE_H

#include <iostream>
#include <string.h>
#include <vector>
#include "../core/actor.h"
#include "../core/audio.h"
#include "../core/balance.h"
#include "../core/battle.h"
#include "../core/combat.h"
#include "../core/config.h"
#include "../core/logger.h"
#include "../core/player.h"
#include "../core/stage.h"
#include "../core/toon.h"

std::unordered_map<std::string, int> _CMDMAP = {
  {"help",    0},
  {"exit",    1},
  {"reload",  2},
  {"chain",   3},
  {"create",  4},
};

void parse_user_input(std::string);
bool parse_input(const std::string, const std::string);
void print_help();
void run_command(const std::string, std::vector<std::string>&);

#endif // XENGINE_H //
