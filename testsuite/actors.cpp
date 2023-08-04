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

    this->combatstate_idle();
}

/**
 * Are actors getting proper base values?
*/
void TestActors::base_attack() {
    int cnf_atk = cnf->get_attack();
    this->dummy = new Actor();
    assert(cnf_atk == this->dummy->get_attack());
    BaseCase::log->named_log(__FILE__, "Tested Base Attack Value for Actors");
}

/**
 * Are actors getting proper base values?
*/
void TestActors::base_defense() {
    int cnf_def = cnf->get_defense();
    this->dummy = new Actor();
    assertm(cnf_def == this->dummy->get_defense(), "Actor Defense Mismatch\t<--");
    BaseCase::log->named_log(__FILE__, "Tested Base Defense Value for Actors");
}

/**
 * Are actors getting proper base values?
*/
void TestActors::base_health() {
    int cnf_hlt = cnf->get_health();
    this->dummy = new Actor();
    assert(cnf_hlt == this->dummy->get_health());
    BaseCase::log->named_log(__FILE__, "Tested Base Health Value for Actors");
}

/**
 * Are actors states getting set properly?
*/
void TestActors::combatstate_idle() { 
    this->dummy->set_combat_idle();
    assert(0 == this->dummy->get_combatstate());
    BaseCase::log->named_log(__FILE__, "Tested Idle Combatstate for Actors");
}

/**
 * Are actors states getting set properly?
*/
void TestActors::combatstate_patrol() { }

/**
 * Are actors states getting set properly?
*/
void TestActors::combatstate_fight() { }

/**
 * Are actors states getting set properly?
*/
void TestActors::combatstate_flee() { }

/**
 * Are actors states getting set properly?
*/
void TestActors::combatstate_follow() { }


/**
 * Are actors states getting set properly?
*/
void TestActors::healthstate_healthy() { }

/**
 * Are actors states getting set properly?
*/
void TestActors::healthstate_hurting() { }

/**
 * Are actors states getting set properly?
*/
void TestActors::healthstate_critical() { }

/**
 * Are actors states getting set properly?
*/
void TestActors::healthstate_sick() { }

/**
 * Are actors states getting set properly?
*/
void TestActors::healthstate_dead() { }

TestActors::~TestActors() {}