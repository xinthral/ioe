#include "balanced.h"

TestBalance::TestBalance() {
    BaseCase::log->named_log(__FILE__, "Testing Actors!");
    this->baseAtk = BaseCase::cnf->get_attack();
    this->baseDef = BaseCase::cnf->get_defense();
    this->baseHlt = BaseCase::cnf->get_health();
    this->test_balance();
}

void TestBalance::test_balance() { this->def_atk_ratio(); }

void TestBalance::def_atk_ratio() { }

TestBalance::~TestBalance() {}