#include "xtoon.h"

Toon::Toon() {
    this->set_id(-1);
}

Toon::Toon(int id) {
    this->set_id(id);
}

//@Override
int Toon::get_attack() {
    return this->attack;
}

//@Override
int Toon::get_defense() {
    return this->defense;
}

Toon::~Toon() {}