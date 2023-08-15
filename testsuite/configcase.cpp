/*!
 * @class   TestConfig configcase.cpp configcase.h
 * @brief   Testing for the ConfigManager 
*/
#include "configcase.h"

/*!
 * @brief   Default Constructor
*/
TestConfig::TestConfig() {
    BaseCase::log->named_log(__FILE__, "Testing the ConfigManager!");
    sprintf(msgHead, "Tested");
    sprintf(msgTail, "for the ConfigManager!");
    test_mapping();
}

/*!
 * @brief   Test All of Key-Value Mapping for Settings
*/
void TestConfig::test_mapping() { 
    this->test_addConfig(); 
    this->test_remConfig(); 
}

/*!
 * @brief   Default Constructor
*/
void TestConfig::test_addConfig() {
    size_t starter = BaseCase::cnf->get_settingsSize();
    BaseCase::cnf->add_setting("test", "added");
    size_t finisher = BaseCase::cnf->get_settingsSize();
    sprintf(this->msgNote, "ConfigManager didn't add test config\t<--\n%d - %d", finisher, starter);
    assertm(finisher - starter == 1, this->msgNote);
    sprintf(buf, "%s %s %s", this->msgHead, "[adding] a config option", this->msgTail);
    BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Default Constructor
*/
void TestConfig::test_remConfig() {
    size_t starter = BaseCase::cnf->get_settingsSize();
    BaseCase::cnf->rem_setting("test");
    size_t finisher = BaseCase::cnf->get_settingsSize();
    sprintf(this->msgNote, "ConfigManager didn't remove test config\t<--\n%d - %d", starter, finisher);
    assertm(starter - finisher == 1, this->msgNote);
    sprintf(buf, "%s %s %s", this->msgHead, "[removing] a config option", this->msgTail);
    BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Default Deconstructor
*/
TestConfig::~TestConfig() {}