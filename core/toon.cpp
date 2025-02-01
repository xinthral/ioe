#include "toon.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor
*/
Toon::Toon() : Toon(-1, "Toon_#-1") { }

/*!
 * @todo    Constructor Initializor
*/
Toon::Toon(int id) : Toon(id, "Toon") { 
  sprintf(buf, "Toon_#%d", id); 
  this->set_name(buf); 
}

/*!
 * @todo    Constructor Initializor
 * 
*/
Toon::Toon(std::string name) : Toon(-1, name) { }

/*!
 * @todo    Constructor Initializor
*/
Toon::Toon(int id, std::string name) {
  this->set_id(id);
  this->set_name(name);
}

/*!
 * @todo    Constructor Initializor
*/
Toon::Toon(std::string name, int level) : Toon(name) {
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

// /*!
//  * @note    
// */
// int Toon::receive_damage(int damage) {
//   int energy = damage;
//   this->health =  this->get_health() - energy;
//   return energy;
// }

/*!
 * @todo    Helper Hook used in CLI Help System
*/
void Toon::_help() {
  std::string helpline = "\nToon Helpline!"
  "\n";
  log->named_log(__FILENAME__, helpline);
}

/*!
 * @todo    Default Deconstructor
*/
Toon::~Toon() { }
