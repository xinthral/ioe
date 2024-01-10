#ifndef TESTLEXICON_H
#define TESTLEXICON_H

#include "basecase.h"
#include "../core/lexicon.h"

/*!
 * @class   TestLexicon lexiconcase.cpp lexiconcase.h
 * @brief   Test for the Lexicon
*/
class TestLexicon : public BaseCase {
protected:
private:
  Lexicon* lex;   //!< Placeholder Lexicon Object
public:
  /*!
   * @brief   Default Constructor
  */
  TestLexicon();

  /*!
   * @brief   Run full set of test on module 
  */
  void test_all();

  /*!
   * @brief   Validate the name generation feature
  */
  void generateName(int);

  /*!
   * @brief Validate the Lexicon swap still holds true
  */
  void lexigraphChangeSize();

  /*!
   * @brief   Default Deconstructor
  */
  ~TestLexicon();
};

#endif // TESTLEXICON_H //
