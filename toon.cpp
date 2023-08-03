#include "toon.h"

/**
 * Default Constructor
*/
Toon::Toon() { this->set_id(-1); }

/**
 * @Overload
 * Constructor Initializor
 * @param :<int|id> - Character Identity Number
*/
Toon::Toon(int id) { this->set_id(id); }

/**
 * @Override
 * Returns Attack Attribute
 * @return :<int|attack>
*/
int Toon::get_attack() { return this->attack; }

/**
 * @Override
 * Returns Defense Attribute
 * @return :<int|defense>
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