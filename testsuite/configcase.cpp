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
    test_all();
}

/*!
 * @brief   Initiate all test
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
    sprintf(this->msgNote, "ConfigManager failed config mappings\t<--\n%d - %d", finalSize, initialSize);
    assertm(finalSize - initialSize == 0, this->msgNote);
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
    sprintf(this->msgNote, "ConfigManager failed to add a test config\t<--\n%d - %d", finalSize, initialSize);
    assertm(finalSize - initialSize == 1, this->msgNote);
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
    sprintf(this->msgNote, "ConfigManager failed to remove a test config\t<--\n%d - %d", initialSize, finalSize);
    assertm(initialSize - finalSize == 1, this->msgNote);
    sprintf(buf, "%s %s %s", this->msgHead, "[removing] a config option", this->msgTail);
    BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Evaluate return type for get_authorized_cli_commands()
*/
void TestConfig::test_listOfCommands() {
    const char* commandString = BaseCase::cnf->raw_config("CMDLIST").c_str();
 	char* token = strtok((char*)commandString, " ");
    BaseCase::log->timed_log(token);
    int steps = 2;
	while ((token = strtok(NULL, " "))) {
        BaseCase::log->timed_log(token);
        steps++;
	}
    sprintf(this->msgNote, "ConfigManager failed to return the appropriate type\t<--\n%d - %d", steps, "2");
    assertm(steps == 2, this->msgNote);
    sprintf(buf, "%s %s %s", this->msgHead, "[valid] authorized commands config option", this->msgTail);
    BaseCase::log->named_log(__FILE__, buf);
}

/*!
 * @brief   Default Deconstructor
*/
TestConfig::~TestConfig() {}