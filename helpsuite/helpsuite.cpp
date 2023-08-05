/**
 * Helper Suite is meant to parse Doxygen outputs, and provide
 * a commandline utility for quick reference while developing 
 * or debugging.
*/
#include "helpsuite.h"

/**
 * Default Constructor
*/
HelpSuite::HelpSuite() { }

/**
 * @overload
 * Debugging Constructor
 * @param[in] _debug Debugging option 
*/
HelpSuite::HelpSuite(bool _debug) {
    cnf = ConfigManager::GetInstance();
    log = Logger::GetInstance();
    log->named_log(__FILE__, "Helper Loaded!");
}

/**
 * Default Deconstructor
*/
HelpSuite::~HelpSuite() {}

/**
 * Module Entry Point
*/
int main(int argc, char const *argv[]) {
    HelpSuite h;
    return 0;
}
