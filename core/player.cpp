#include "player.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Constructor Initializor
*/
Player::Player(std::string name, int level) {
  // Get the current time
  auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

  // Convert the current time to a local time structure
  std::tm* localTime = std::localtime(&currentTime);

  // Extract seconds from the local time structure
  int seconds = localTime->tm_sec;

  this->set_id(seconds);
  this->set_name(name);
  this->set_level(level);
  this->set_attack(level * this->get_baseAttack());
  this->set_defense(level * this->get_baseDefense());
  this->set_health(level * this->get_baseHealth());
}

/*!
 * @todo    Default Constructor
*/
Player::Player() : Player("Player1", 1) {
  log = Logger::GetInstance();
  sprintf(buf, "%s Level %d Player initiated.", "Player1", level);
  log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Level Intialized Constructor
*/
Player::Player(int level) : Player("Player" + level, level) {}

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
  std::string helpline = "\nPlayer Helpline!"
  "\n\n\tThe player class is meant to be the primary class object that holds player data."
  "\nThinking that it would be initiated as is, but instantiated by another class, this would"
  "\nallow for character specializations."
  "\n";
  log->named_log(__FILENAME__, helpline);
}

/*!
 * @todo    Default Deconstructor
*/
Player::~Player() {}
