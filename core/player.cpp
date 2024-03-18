#include "player.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Constructor Initializor
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
 * @todo    Default Constructor
*/
Player::Player() : Player("Player1", 1, 1, 1) {
  log = Logger::GetInstance();
  sprintf(buf, "%s Level %d Player initiated.", "Player1", level);
  log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Level Intialized Constructor
*/
Player::Player(int level, int power, int block) : Player("Player" + level, level, power, block) { }

// /*!
//  * @note    
// */
// int Player::receive_damage(int damage) {
//   int energy = damage;
//   this->health = this->health - energy;
//   return energy;
// }

/*!
 * @todo    Helper Hook used in CLI Help System
*/
void Player::_help() {
  std::string helpline = "\nPlayer Helpline!\n";
  helpline += "\n\tThe player class is meant to be the primary class object that holds player data.";
  helpline += "\nThinking that it would be initiated as is, but instantiated by another class, this would";
  helpline += "\nallow for character specializations.";
  helpline += "\n";
  log->named_log(__FILENAME__, helpline);
}

/*!
 * @todo    Default Deconstructor
*/
Player::~Player() { }
