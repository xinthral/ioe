/*!
 * @class   Item item.cpp item.h
 * @brief   BaseClass for Items
 * @details Items will be inherited from this class, which will include consumables
 *          weapons, armor, quest items, keys, and any other items I come up with.
*/
#include "item.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor 
*/
Item::Item() { 
    log = Logger::GetInstance();
    log->named_log(__FILENAME__, "New Item Established.");
}


/*!
 * @brief   Helper Hook used in CLI Help System
*/
void Item::_help() { 
  std::string helpline = "\nItem Helpline!\n";
  helpline += "\n";
  log->named_log(__FILENAME__, helpline);
}

Item::~Item() { }
