#include "xconfig.h"
// Singleton Instance
ConfigManager* ConfigManager::_singleton = NULL;
std::mutex ConfigManager::_mutex;

ConfigManager::ConfigManager() { 
    printf("ConfigManager Established.\n");
    load_config(); 
}

ConfigManager* ConfigManager::GetInstance() {
    // Acquire Instance Mutex
    std::lock_guard<std::mutex> lock(_mutex);
    // If singleton already exists, return instance
    if (_singleton == NULL) { _singleton = new ConfigManager(); }
    return _singleton;
}

bool ConfigManager::load_config() {
    // FIXME: Needs work to read file and parse
    std::string sec;
    std::string div;
    std::string key;
    printf("Loading Config...\n");
    conf.open("engine.ini");
    while (getline(conf, sec)) {
        printf("%s\n", sec.c_str());
    }
    conf.close();
    return true;
}