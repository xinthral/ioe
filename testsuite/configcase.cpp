#include "configcase.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor
*/
TestConfig::TestConfig() : BaseCase(__FILENAME__) {
  BaseCase::log->named_log(__FILENAME__, "Testing the ConfigManager!");
  sprintf(msgHead, "Tested");
  sprintf(msgTail, "for the ConfigManager!");
  this->test_all();
}

/*!
 * @todo    Run full set of test on module 
*/
void TestConfig::test_all() {
  mapping();
  listOfCommands();
}

/*!
 * @todo    Test All of Key-Value Mappings for Settings
*/
void TestConfig::mapping() { 
  size_t initialSize = BaseCase::cnf->get_settingsSize();
  this->addConfig(); 
  this->remConfig(); 
  size_t finalSize = BaseCase::cnf->get_settingsSize();
  assertm(finalSize - initialSize == 0, "ConfigManager failed config mappings");
  sprintf(buf, "%s %s %s", this->msgHead, "[mapping] of config options", this->msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Add a new config 
*/
void TestConfig::addConfig() {
  size_t initialSize = BaseCase::cnf->get_settingsSize();
  BaseCase::cnf->add_setting("test", "added");
  size_t finalSize = BaseCase::cnf->get_settingsSize();
  assertm(finalSize - initialSize == 1, "ConfigManager failed to add a test config");
  sprintf(buf, "%s %s %s", this->msgHead, "[adding] a config option", this->msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Remove a config option
*/
void TestConfig::remConfig() {
  size_t initialSize = BaseCase::cnf->get_settingsSize();
  BaseCase::cnf->rem_setting("test");
  size_t finalSize = BaseCase::cnf->get_settingsSize();
  assertm(initialSize - finalSize == 1, "ConfigManager failed to remove a test config");
  sprintf(buf, "%s %s %s", this->msgHead, "[removing] a config option", this->msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Evaluate return type for get_authorized_cli_commands()
*/
void TestConfig::listOfCommands() {
  std::vector<std::string> commands;
  BaseCase::cnf->get_authorizedCommands(commands);
  assertm((commands.size() > 1), "ConfigManager failed to return the list of commands");
  sprintf(buf, "%s %s %s", this->msgHead, "[valid] authorized commands config option", this->msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Default Deconstructor
*/
TestConfig::~TestConfig() {}
