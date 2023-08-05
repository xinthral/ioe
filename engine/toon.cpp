#include "toon.h"

/**
 * Default Constructor
*/
Toon::Toon() { this->set_id(-1); }

/**
 * @overload
 * Constructor Initializor
 * @param :<int|id> - Character Identity Number
*/
Toon::Toon(int id) { this->set_id(id); }

/**
 * @copydoc Actor::get_attack()
*/
int Toon::get_attack() { return this->attack; }

/**
 * @copydoc Actor::get_defense()
*/
int Toon::get_defense() { return this->defense; }

/**
 * Helper Hook used in CLI Help System
*/
void Toon::_help() {}

/**
 * Default Deconstructor
*/
Toon::~Toon() {}