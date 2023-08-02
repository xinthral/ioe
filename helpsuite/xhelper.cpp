#include "xhelper.h"

int main(int argc, char const *argv[]) {
    ConfigManager* cm = ConfigManager::GetInstance();
    Logger* log = Logger::GetInstance();
    log->named_log(__FILE__, "Helper Loaded!");
    return 0;
}
