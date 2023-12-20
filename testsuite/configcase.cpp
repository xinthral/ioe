/*!
 * @class   TestConfig configcase.cpp configcase.h
 * @brief   Testing for the ConfigManager 
*/
#include "configcase.h"

/*!
 * @brief   Default Constructor
*/
TestConfig::TestConfig() : BaseCase(__FILE__) {
  BaseCase::log->named_log(__FILE__, "Testing the ConfigManager!");
  sprintf(msgHead, "Tested");
  sprintf(msgTail, "for the ConfigManager!");
  this->test_all();
}

/*!
 * @brief   Run full set of test on module 
*/
void TestConfig::test_all() {
  test_mapping();
  test_listOfCommands();
}

/*!
 * @brief   Test All of Key-Value Mappings for Settings
*/
void TestConfig::test_mapping() { 
  size_t initialSize = BaseCase::cnf->get_settingsSize();
  this->test_addConfig(); 
  this->test_remConfig(); 
  size_t finalSize = BaseCase::cnf->get_settingsSize();
  assertm(finalSize - initialSize == 0, "ConfigManager failed config mappings");
  sprintf(buf, "%s %s %s", this->msgHead, "[mapping] of config options", this->msgTail);
  BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Add a new config 
*/
void TestConfig::test_addConfig() {
  size_t initialSize = BaseCase::cnf->get_settingsSize();
  BaseCase::cnf->add_setting("test", "added");
  size_t finalSize = BaseCase::cnf->get_settingsSize();
  assertm(finalSize - initialSize == 1, "ConfigManager failed to add a test config");
  sprintf(buf, "%s %s %s", this->msgHead, "[adding] a config option", this->msgTail);
  BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Remove a config option
*/
void TestConfig::test_remConfig() {
  size_t initialSize = BaseCase::cnf->get_settingsSize();
  BaseCase::cnf->rem_setting("test");
  size_t finalSize = BaseCase::cnf->get_settingsSize();
  assertm(initialSize - finalSize == 1, "ConfigManager failed to remove a test config");
  sprintf(buf, "%s %s %s", this->msgHead, "[removing] a config option", this->msgTail);
  BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Evaluate return type for get_authorized_cli_commands()
*/
void TestConfig::test_listOfCommands() {
  std::vector<std::string> commands;
  BaseCase::cnf->get_authorizedCommands(commands);
  assertm((commands.size() > 1), "ConfigManager failed to return the list of commands");
  sprintf(buf, "%s %s %s", this->msgHead, "[valid] authorized commands config option", this->msgTail);
  BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Default Deconstructor
*/
TestConfig::~TestConfig() {}