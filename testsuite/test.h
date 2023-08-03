#ifndef TEST_H
#define TEST_H

#include <cassert>
#include <iostream>
#include "../actor.h"
#include "../config.h"
#include "../logger.h"

class TestSuite {
protected:
    ConfigManager* conf;
    Logger* log;
    Actor* dummy;
public:
    TestSuite();
    void test_actor();
    void actor_base_attack();
    void actor_base_defense();
    void actor_base_health();
    ~TestSuite();
};

#endif // TEST_H //