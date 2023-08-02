#include "helper.h"

HelpSuite::HelpSuite() {
    cm = ConfigManager::GetInstance();
    log = Logger::GetInstance();
    log->named_log(__FILE__, "Helper Loaded!");
}

HelpSuite::~HelpSuite() {}

int main(int argc, char const *argv[]) {
    HelpSuite h;
    return 0;
}
