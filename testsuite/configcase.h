#ifndef TESTCONFIG_H
#define TESTCONFIG_H

#include <cassert>
#include "basecase.h"

/*!
 * @class   TestConfig configcase.cpp configcase.h
 * @brief   Testing for the ConfigManager 
*/
class TestConfig : public BaseCase {
protected:
private:
  char buf[128];          //! Buffer Value for Logger outputs
  char msgHead[32];       //! Logging Output Formatting, leading
  char msgNote[256];      //! Buffer Value for Results outputs
  char msgTail[32];       //! Logging Output Formatting, trailing
public:
  /*!
   * @brief   Default Constructor
  */
  TestConfig();

  /*!
   * @brief   Run full set of test on module 
  */
  void test_all();

  /*!
   * @brief   Test All of Key-Value Mappings for Settings
  */
  void mapping();

  /*!
   * @brief   Add a new config 
  */
  void addConfig();

  /*!
   * @brief   Remove a config option
  */
  void remConfig();

  /*!
   * @brief   Evaluate return type for get_authorized_cli_commands()
  */
  void listOfCommands();

  /*!
   * @brief   Default Deconstructor
  */
  ~TestConfig();
};

#endif // TESTCONFIG_H //
