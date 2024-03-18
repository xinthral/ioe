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
  std::string helpline = "\nToon Helpline!\n";
  helpline += "\n";
  log->named_log(__FILENAME__, helpline);
}

/*!
 * @todo    Default Deconstructor
*/
Toon::~Toon() { }
