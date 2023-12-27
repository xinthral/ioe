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
Player::Player() : Player("P1", 1, 1, 1) {
  log = Logger::GetInstance();
  const std::string fbuff = __FILE__;
  sprintf(buf, "%s Level %d Player initiated.", level);
  log->named_log(fbuff, buf);
}

/*!
 * @overload
 * @brief   Level Intialized Constructor
 * @param[in] level - Level of the Player
 * @param[in] power - Cummulative Power of Player
 * @param[in] block - Defense of the Player
*/
Player::Player(int level, int power, int block) : Player("Player" + level, level, power, block) { }

/*!
 * @overload
 * @brief   Constructor Initializor
 * @param[in] name  - Name of the Player
 * @param[in] level - Level of the Player
 * @param[in] power - Cummulative Power of Player
 * @param[in] block - Defense of the Player
*/
Player::Player(std::string name, int level, int power, int block) {
  // Get the current time
  auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

  // Convert the current time to a local time structure
  std::tm* localTime = std::localtime(&currentTime);

  // Extract seconds from the local time structure
  int seconds = localTime->tm_sec;

  this->set_id(seconds);
  this->set_name(name);
}

/*!
 * @brief   Helper Hook used in CLI Help System
*/
void Player::_help() {
  std::string helpline = "\nPlayer Helpline!\n";
  helpline += "\n\tThe player class is meant to be the primary class object that holds player data.";
  helpline += "\nThinking that it would be initiated as is, but instantiated by another class, this would";
  helpline += "\nallow for character specializations.";
  helpline += "\n";
  log->named_log(__FILE__, helpline);
}

/*!
 * @brief   Default Deconstructor
*/
Player::~Player() { }
