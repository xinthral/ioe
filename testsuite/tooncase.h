#ifndef TESTTOON_H
#define TESTTOON_H

#include "basecase.h"

class TestToon : public BaseCase {
protected:
private:
  char buf[1024];
  char msgHead[32];
  char msgTail[64];
public:
  TestToon();
  void test_all();
  void test_toonCreation();
  void test_toonCreation_id();
  void test_toonCreation_name();
  void test_toonCreation_both();
  ~TestToon();
};

#endif // TESTTOON_H //
