#include "xactor.h"

Actor::Actor() {}
int Actor::get_id() { return this->id; }
void Actor::set_id(int _id) { this->id = _id; }
std::string Actor::get_name() { return this->name; }
void Actor::set_name(std::string _name) { this->name = _name; }
Actor::~Actor() {}