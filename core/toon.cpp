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
 * @todo    Actor::get_name()
*/
std::string Toon::get_name() { return this->name; }

/*!
 * @todo    Actor::get_attack()
*/
int Toon::get_attack() { return this->attack; }

/*!
 * @todo    Actor::get_defense()
*/
int Toon::get_defense() { return this->defense; }

/*!
 * @todo    Actor::set_name()
*/
void Toon::set_name(std::string name) { this->name = name; }

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
