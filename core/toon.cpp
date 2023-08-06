#include "toon.h"

/*!
 * Default Constructor
*/
Toon::Toon() : Toon(-1, "Toon") { }

/*!
 * @overload
 * Constructor Initializor
 * @param[in] id - Character Identity Number
*/
Toon::Toon(int id) : Toon(id, "Toon") { }

/*!
 * @overload
 * Constructor Initializ
 * @param[in] name - Name of the Character
 * 
*/
Toon::Toon(std::string name) : Toon(-1, name) { }

/*!
 * @overload
 * Constructor Initializor
 * @param[in] id   - Character Identity Number
 * @param[in] name - Name of the Character
*/
Toon::Toon(int id, std::string name) { 
    this->set_id(id);
    this->set_name(name);
}

/*!
 * @copydoc Actor::get_name()
*/
std::string Toon::get_name() { return this->name; }

/*!
 * @copydoc Actor::get_attack()
*/
int Toon::get_attack() { return this->attack; }

/*!
 * @copydoc Actor::get_defense()
*/
int Toon::get_defense() { return this->defense; }

/*!
 * @copydoc Actor::set_name()
*/
void Toon::set_name(std::string name) { this->name = name; }

/*!
 * Helper Hook used in CLI Help System
*/
void Toon::_help() {}

/**
 * Default Deconstructor
*/
Toon::~Toon() {}