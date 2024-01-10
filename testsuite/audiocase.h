#ifndef TESTAUDIO_H
#define TESTAUDIO_H

#include "basecase.h"

/*!
 * @class   TestAudio audiocase.cpp audiocase.h
 * @brief   Test for the LeaderBoard
*/
class TestAudio : public BaseCase {
protected:
  char msgHead[32];   //!< Unified prefix for test
  char msgNote[64];   //!< Unified buffer for test
  char msgTail[16];   //!< Unified suffix for test

private:
  AudioDriver* audio; //!< Placeholder AudioDriver Object

public:
  /*!
   * @brief   Default Constructor
  */
  TestAudio();

  /*!
   * @brief   Run full set of test on module 
  */
  void test_all();

  /*!
   * @brief   Sample a Wavfile
  */
  void wavSampling();

  /*!
   * @brief   Default Deconstructor
  */
  ~TestAudio();
};

#endif // TESTAUDIO_H //
