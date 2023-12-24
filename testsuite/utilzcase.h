#ifndef TESTUTILZ_H
#define TESTUTILZ_H

#include "basecase.h"

class TestUtilz : public BaseCase {
protected:
  char msgHead[64];
  char msgTail[128];
private:
public:
  TestUtilz();
  void test_all();
  void test_StringToArray();
  void test_StringToArray_TrailingSpace();
  ~TestUtilz();
};

#endif // TESTUTILZ_H //
