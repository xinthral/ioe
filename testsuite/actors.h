#ifndef TESTACTOR_H
#define TESTACTOR_H

#include "basecase.h"
#include "../actor.h"

class TestActors : public BaseCase {
protected:
    Actor* dummy;
public:
    TestActors();
    void test_actor();
    void base_attack();
    void base_defense(); 
    void base_health();
    ~TestActors();
};

#endif // TESTACTOR_H //