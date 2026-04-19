#ifndef TESTCIPHERS_H
#define TESTCIPHERS_H

#include "basecase.h"
#include "../core/ciphers.h"
#include "../core/lexicon.h"

/*!
 * @class   TestCiphers leadercase.cpp leadercase.h
 * @brief   Test for the TestCiphers
*/
class TestCiphers : public BaseCase {
protected:
private:
  xCiphers* cipher;       //!< Placeholder Cipher Object
  std::string decoded;    //!< Placeholder for decoded strings
  std::string encoded;    //!< Placeholder for encoded strings

public:
  /*!
   * @brief   Default Constructor
  */
  TestCiphers();

  /*!
   * @brief   Overloaded Constructor — sets profiling granularity before running tests
   * @param[in] granularity  Level of profiling detail (0 = named only, 1 = per-method + named)
  */
  TestCiphers(int granularity);

  /*!
   * @brief   Run full set of test on module 
  */
  void test_all();

  /*!
   * @brief   FIXME
  */
  void displayMatrix();

  /*!
   * @brief   Ensuring that the cipher can properly decode a message
   * @note    TestCiphers::encode() needs to take place before TestCiphers::decode()
  */
  void encode();

  /*!
   * @brief   Ensuring that the cipher can properly encode a message
   * @note    TestCiphers::encode() needs to take place before TestCiphers::decode()
  */
  void decode();

  /*!
   * @brief   Generates Cipher Matrices'
  */
  void generateMatrix();

  /*!
   * @brief   Generates Cipher after changing the lexigraph
  */
  void swappedLexigraph();

  /*!
   * @brief   Default Deconstructor
  */
  ~TestCiphers();
};

#endif // TESTCIPHERS_H //
