#ifndef TESTCIPHERS_H
#define TESTCIPHERS_H

#include "basecase.h"
#include "../core/ciphers.h"
#include "../core/lexicon.h"

class TestCiphers : public BaseCase {
protected:
  xCiphers* cipher;
  std::string decoded;
  std::string encoded;
private:
public:
  TestCiphers();
  void test_all();
  void displayMatrix();
  void encode();
  void decode();
  void generateMatrix();
  ~TestCiphers();
};

#endif // TESTCIPHERS_H //
