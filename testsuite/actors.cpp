#include "actors.h"

TestActors::TestActors() {
    BaseCase::log->named_log(__FILE__, "Testing Actors!");
    sprintf(this->msgHead, "Tested");
    sprintf(this->msgTail, "for Actors!");
    test_actor();
}

/**
 * Run full set of test on Actor
*/
void TestActors::test_actor() {
    base_attack();
    base_defense();
    base_health();

    combatstate_idle();
    combatstate_patrol();
    combatstate_fight();
    combatstate_flee();
    combatstate_follow();
}

/**
 * Are actors getting proper base values?
*/
void TestActors::base_attack() {
    int cnf_atk = cnf->get_attack();
    sprintf(output, "%s %s %s", msgHead, "Base Attack Value", msgTail);
    dummy = new Actor();
    assert(cnf_atk == dummy->get_attack());
    BaseCase::log->named_log(__FILE__, output);
}

/**
 * Are actors getting proper base values?
*/
void TestActors::base_defense() {
    int cnf_def = cnf->get_defense();
    dummy = new Actor();
    sprintf(output, "%s %s %s", msgHead, "Base Defense Value", msgTail);
    assertm(cnf_def == dummy->get_defense(), "Actor Defense Mismatch\t<--");
    BaseCase::log->named_log(__FILE__, output);
}

/**
 * Are actors getting proper base values?
*/
void TestActors::base_health() {
    int cnf_hlt = cnf->get_health();
    sprintf(output, "%s %s %s", msgHead, "Base Health Value", msgTail);
    dummy = new Actor();
    assert(cnf_hlt == dummy->get_health());
    BaseCase::log->named_log(__FILE__, output);
}

/**
 * Are actors states getting set properly?
*/
void TestActors::combatstate_idle() { 
    dummy->set_combat_idle();
    sprintf(output, "%s %s %s", msgHead, "Idle Combatstate", msgTail);
    assert(IDLE == dummy->get_combatstate());
    BaseCase::log->named_log(__FILE__, output);
}

/**
 * Are actors states getting set properly?
*/
void TestActors::combatstate_patrol() { 
    dummy->set_combat_patrol();
    sprintf(output, "%s %s %s", msgHead, "Patrol Combatstate", msgTail);
    assert(PATROL == dummy->get_combatstate());
    BaseCase::log->named_log(__FILE__, output);
}

/**
 * Are actors states getting set properly?
*/
void TestActors::combatstate_fight() { 
    dummy->set_combat_fight();
    sprintf(output, "%s %s %s", msgHead, "Fight Combatstate", msgTail);
    assert(FIGHT == dummy->get_combatstate());
    BaseCase::log->named_log(__FILE__, output);
}

/**
 * Are actors states getting set properly?
*/
void TestActors::combatstate_flee() { 
    dummy->set_combat_flee();
    sprintf(output, "%s %s %s", msgHead, "Flee Combatstate", msgTail);
    assert(FLEE == dummy->get_combatstate());
    BaseCase::log->named_log(__FILE__, output);
}

/**
 * Are actors states getting set properly?
*/
void TestActors::combatstate_follow() { 
    dummy->set_combat_follow();
    sprintf(output, "%s %s %s", msgHead, "Follow Combatstate", msgTail);
    assert(FOLLOW == dummy->get_combatstate());
    BaseCase::log->named_log(__FILE__, output);
}


/**
 * Are actors states getting set properly?
*/
void TestActors::healthstate_healthy() { 
    dummy->set_health_healthy();
    sprintf(output, "%s %s %s", msgHead, "Healthy Healthstate", msgTail);
    assert(HEALTHY == dummy->get_healthstate());
    BaseCase::log->named_log(__FILE__, output);
}

/**
 * Are actors states getting set properly?
*/
void TestActors::healthstate_hurting() { 

}

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