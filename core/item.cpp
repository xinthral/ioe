
#include "item.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor 
*/
Item::Item() { 
    log = Logger::GetInstance();
    log->named_log(__FILENAME__, "New Item Established.");
}

/*!
 * @todo    Helper Hook used in CLI Help System
*/
void Item::_help() { 
  std::string helpline = "\nItem Helpline!\n";
  helpline += "\n";
  log->named_log(__FILENAME__, helpline);
}

/*!
 * @todo    Default Deconstructor 
*/
Item::~Item() { }
