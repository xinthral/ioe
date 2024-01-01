#ifndef TESTUTILZ_H
#define TESTUTILZ_H

#include "basecase.h"

class TestUtilz : public BaseCase {
protected:
private:
public:
  TestUtilz();
  void test_all();
  void test_StringToArray();
  void test_StringToArray_TrailingSpace();
  ~TestUtilz();
};

#endif // TESTUTILZ_H //
