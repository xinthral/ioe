/**
 * Helper Suite is meant to parse Doxygen outputs, and provide
 * a commandline utility for quick reference while developing 
 * or debugging.
*/
#include "helpsuite.h"

/**
 * Default Constructor
*/
HelpSuite::HelpSuite() { 
    cnf = ConfigManager::GetInstance();
    log = Logger::GetInstance();
    log->named_log(__FILE__, "Helper Loaded!");
}

/**
 * @overload
 * Debugging Constructor
 * @param[in] _debug Debugging option 
*/
HelpSuite::HelpSuite(bool _debug) : HelpSuite() { }


/**
 * Default Deconstructor
*/
HelpSuite::~HelpSuite() {}

/**
 * Static Function to display help details
*/
void print_help() { 
    Logger* log = Logger::GetInstance();
    char buf[64];
    std::string fileName = Utilz::FileName(__FILE__);
    sprintf(buf, "Usage: %s [NUMBER]\n", fileName.c_str()); 
    log->raw_log(buf);
    log->raw_log("HelpSuite CLI Tool\n");
    log->raw_log("A helper system, to give the developer/debugger" \
        " a quality-of-life option for hunting down all my stupid." \
        " This can be used in conjuction with the TestSuite in order to"\
        " maximize the benefit of the CLI Debugging Suite.\n");
    log->raw_log("\t[1] - HelpSuit details");
    log->raw_log("\t[2] - TestSuite details");
    log->raw_log("\t[0] - Default Help to rule them all\n");
    exit(-1);
}

/**
 * Module Entry Point
*/
int main(int argc, char const *argv[]) {
    if (argc < 2) { print_help(); }
    HelpSuite h;
    return 0;
}
