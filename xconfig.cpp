#include "xconfig.h"

/* Singleton Instance */
ConfigManager* ConfigManager::_singleton = NULL;
std::mutex ConfigManager::_mutex;

ConfigManager::ConfigManager() { 
    printf("ConfigManager Established.\n");
    load_config(false); 
}

ConfigManager* ConfigManager::GetInstance() {
    // Acquire Instance Mutex
    std::lock_guard<std::mutex> lock(_mutex);
    // If singleton already exists, return instance
    if (_singleton == NULL) { _singleton = new ConfigManager(); }
    return _singleton;
}

size_t ConfigManager::add_setting(const std::string& option, const std::string& value) {
    settings[option] = value;
    return settings.size();
}

size_t ConfigManager::rem_setting(const std::string& option) {
    settings.erase(option);
    return settings.size();
}

void ConfigManager::display_state() {
    this->load_config(true);
}

bool ConfigManager::load_config(bool _debug) {
    // FIXME: Needs work to parse file
    std::size_t pos;
    std::string row;
    std::string opt;
    std::string val;
    std::size_t qsize;
    int cnt = 0;
    printf("Loading Config...\n");
    conf.open("engine.ini");                        // Open INI file for reading
    while (std::getline(conf, row)) {
        // printf("%d: %s\n", cnt++, row.c_str());
        pos = row.find(delim);                      // Locate Delimiter
        if (pos != std::string::npos){
            opt = row.substr(0, pos);               // Grab Option Name
            val = row.substr(pos+1, row.size()-1);  // Grab Option Value
            qsize = this->add_setting(opt, val);    // Load Setting
            cnt++;                                  // Increment Settings counter
            if (_debug) { printf("%10s%s%s\n", opt.c_str(), delim.c_str(), val.c_str()); }
        }
    }
    conf.close();                                   // Close INI file descriptor
    return cnt == qsize;
}

ConfigManager::~ConfigManager() {}