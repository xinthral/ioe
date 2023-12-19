/*!
 * @class   Player player.h player.cpp
 * @brief   Construct containing Player data representing the
 *          virtual avatar within the engine.
*/
#include "player.h"

/*!
 * @brief   Default Constructor
 * @details If no values are provided, then default
 *          values are initialized as (1, 1, 1).
*/
Player::Player() {
  log = Logger::GetInstance();
  sprintf(buf, "Level %d Player initiated.", level);
  log->named_log(__FILE__, buf);
}

/*!
 * @overload
 * @brief   Level Intialized Constructor
 * @param[in] level - Level of the Player
 * @param[in] power - Cummulative Power of Player
 * @param[in] block - Defense of the Player
*/
Player::Player(int level, int power, int block) : Player() { 
  this->level = level;
  this->power = power;
  this->block = block;
}

/*!
 * @overload
 * @brief   Constructor Initializor
 * @param[in] name  - Name of the Player
 * @param[in] level - Level of the Player
 * @param[in] power - Cummulative Power of Player
 * @param[in] block - Defense of the Player
*/
Player::Player(std::string name, int level, int power, int block) : 
  Player(level, power, block) {
    this->name = name;
}

/*!
 * @brief   Helper Hook used in CLI Help System
*/
void Player::_help() {
  char* helpline = (char*)"LeaderBoard Helpline!";
  log->named_log(__FILE__, helpline);
}

/*!
 * @brief   Default Deconstructor
*/
Player::~Player() { }
