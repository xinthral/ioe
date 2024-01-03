#ifndef TESTLEXICON_H
#define TESTLEXICON_H

#include "basecase.h"
#include "../core/lexicon.h"

class TestLexicon : public BaseCase {
protected:
  Lexicon* lex;
private:
public:
  TestLexicon();
  void test_all();
  void generateName(int);
  void lexigraphChangeSize();
  ~TestLexicon();
};

#endif // TESTLEXICON_H //
