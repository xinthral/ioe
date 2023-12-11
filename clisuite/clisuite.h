#ifndef XENGINE_H
#define XENGINE_H

#include <iostream>
#include <string.h>
#include <vector>
#include "../core/actor.h"
#include "../core/balance.h"
#include "../core/battle.h"
#include "../core/combat.h"
#include "../core/config.h"
#include "../core/logger.h"
#include "../core/player.h"
#include "../core/stage.h"
#include "../core/toon.h"

ConfigManager* cnf;

void parse_user_input(std::string);
bool parse_input(std::string,std::string);
void print_help();

#endif // XENGINE_H //`