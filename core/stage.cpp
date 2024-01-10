#include "stage.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

//! Singleton Instance
StageManager* StageManager::_singleton = NULL;
//! Mutex Lock
std::mutex StageManager::_mutex;

/*!
 * @todo    Protected Constructor
*/
StageManager::StageManager(const std::string _name) : name(_name) {
  log = Logger::GetInstance();
  maxCrew = 10;
  sprintf(buf, "StageManager Established: %s", this->name.c_str());
  log->named_log(Utilz::FileName(__FILENAME__), buf);
}


/*!
 * @todo    Singleton Constructor
*/
StageManager* StageManager::GetInstance(const std::string& name) {
  //! Acquire Instance Mutex
  std::lock_guard<std::mutex> lock(_mutex);
  //! If singleton already exists, return instance
  if (_singleton == NULL) { _singleton = new StageManager(name); }
  return _singleton;
}

/*!
 * @todo    Returns the name attribute
*/
std::string StageManager::get_name() { return this->name; }

/*!
 * @todo    StageManager Loads the Scene with Actors
 * @note    FIXME
*/
void StageManager::casting_call(int size, std::vector<Toon*>& npcs) { 
  Toon* t;
  for (int i = 0; i < size; i++) {
    sprintf(buf, "Toon_%d", i);
    t = new Toon(buf);
    npcs.push_back(t);
  }
}


/*!
 * @todo    Helper Hook used in CLI Help System
*/
void StageManager::_help() {
  std::string helpline = "\nStageManager Helpline!\n";
  helpline += "\n";
  log->named_log(__FILENAME__, helpline);
}

/*!
 * @todo    Default Constructor
*/
StageManager::~StageManager() { }
