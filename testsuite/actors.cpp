#include "actors.h"

TestActors::TestActors() {
    BaseCase::log->named_log(__FILE__, "Testing Actors!");
    this->test_actor();
}

/**
 * Run full set of test on Actor
*/
void TestActors::test_actor() {
    this->base_attack();
    this->base_defense();
    this->base_health();
}

/**
 * Are actors getting proper base values?
*/
void TestActors::base_attack() {
    int cnf_atk = conf->get_attack();
    this->dummy = new Actor();
    assert(cnf_atk == this->dummy->get_attack());
    BaseCase::log->named_log(__FILE__, "Tested Base Attack Value for Actors");
}

/**
 * Are actors getting proper base values?
*/
void TestActors::base_defense() {
    int cnf_def = conf->get_defense();
    this->dummy = new Actor();
    assertm(cnf_def == this->dummy->get_defense(), "Actor Defense Mismatch\t<--");
    BaseCase::log->named_log(__FILE__, "Tested Base Defense Value for Actors");
}

/**
 * Are actors getting proper base values?
*/
void TestActors::base_health() {
    int cnf_hlt = conf->get_health();
    this->dummy = new Actor();
    assert(cnf_hlt == this->dummy->get_health());
    BaseCase::log->named_log(__FILE__, "Tested Base Health Value for Actors");
}

TestActors::~TestActors() {}