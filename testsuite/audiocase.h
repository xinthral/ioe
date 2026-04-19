#ifndef TESTAUDIO_H
#define TESTAUDIO_H

#include "basecase.h"
#include "../audiosuite/wavdriver.h"
#include "../audiosuite/mp3driver.h"
#include "../audiosuite/flacdriver.h"

/*!
 * @class   TestAudio audiocase.h audiocase.cpp
 * @brief   Tests for the Audio driver modules (WAV, MP3, FLAC)
*/
class TestAudio : public BaseCase {
private:
  WavDriver*  wavDriver;
  Mp3Driver*  mp3Driver;
  FlacDriver* flacDriver;

public:
  /*!
   * @brief   Default Constructor
  */
  TestAudio();

  /*!
   * @brief   Overloaded Constructor — sets profiling granularity before running tests
   * @param[in] granularity  Level of profiling detail (0 = named only, 1 = per-method + named)
  */
  TestAudio(int granularity);

  /*!
   * @brief   Run full set of tests on all audio modules
  */
  void test_all();

  /*!
   * @brief   Validate WavDriver loads a file and returns non-empty data
  */
  void test_wav_loads();

  /*!
   * @brief   Validate WavDriver sample rate is non-zero
  */
  void test_wav_samplerate();

  /*!
   * @brief   Validate WavDriver channel count is non-zero
  */
  void test_wav_channels();

  /*!
   * @brief   Validate WavDriver bit depth is non-zero
  */
  void test_wav_bitdepth();

  /*!
   * @brief   Validate Mp3Driver loads a file and returns non-empty data
  */
  void test_mp3_loads();

  /*!
   * @brief   Validate Mp3Driver sample rate is non-zero
  */
  void test_mp3_samplerate();

  /*!
   * @brief   Validate Mp3Driver channel count is non-zero
  */
  void test_mp3_channels();

  /*!
   * @brief   Validate Mp3Driver reports 16-bit depth (dr_mp3 always decodes to s16)
  */
  void test_mp3_bitdepth();

  /*!
   * @brief   Validate FlacDriver loads a file and returns non-empty data
   * @note    Disabled - no FLAC samples in audiosuite/samples/
  */
  void test_flac_loads();

  /*!
   * @brief   Default Deconstructor
  */
  ~TestAudio();
};

#endif // TESTAUDIO_H //
