/**
 * Test Suite is meant to be a collection of unit testing
 * with the idea of reaching 100% coverage of testing, while 
 * providing a command line utility for reference when
 * developing or debugging.
*/
#include "test.h"

/**
 * Default Constructor
*/
TestSuite::TestSuite() {
    conf = ConfigManager::GetInstance();
    log  = Logger::GetInstance();
    log->named_log(__FILE__, "Tester Loaded!");
}

/**
 * Run full set of test on Actor
*/
void TestSuite::test_actor() {
    this->actor_base_attack();
    this->actor_base_defense();
    this->actor_base_health();
}

/**
 * Are actors getting proper base values?
*/
void TestSuite::actor_base_attack() {
    log->named_log(__FILE__, "Testing Base Attack Value for Actors");
    int cnf_atk = conf->get_attack();
    dummy = new Actor();
    assert(cnf_atk == dummy->get_attack());
}

/**
 * Are actors getting proper base values?
*/
void TestSuite::actor_base_defense() {
    log->named_log(__FILE__, "Testing Base Defense Value for Actors");
    int cnf_def = conf->get_defense();
    dummy = new Actor();
    assert(cnf_def == dummy->get_defense());
}

/**
 * Are actors getting proper base values?
*/
void TestSuite::actor_base_health() {
    log->named_log(__FILE__, "Testing Base Health Value for Actors");
    int cnf_hlt = conf->get_health();
    dummy = new Actor();
    assert(cnf_hlt == dummy->get_health());
}

/**
 * Default Deconstructor
*/
TestSuite::~TestSuite() {}

/**
 * Module Entry Point
*/
int main(int argc, char const *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [options]\n", Utilz::FileName(__FILE__).c_str());
        exit(-1);
    }
    TestSuite ts;
    ts.test_actor();
    return 0;
}
