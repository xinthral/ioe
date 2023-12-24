/*!
 * @class   Item item.cpp item.h
 * @brief   Item stuff
*/

#include "item.h"

/*!
 * @brief   Default Constructor 
*/
Item::Item() { 
    log = Logger::GetInstance();
    log->named_log(__FILE__, "New Item Established.");
}


/*!
 * @brief   Helper Hook used in CLI Help System
*/
void Item::_help() { 
  std::string helpline = "\nItem Helpline!\n";
  helpline += "\n";
  log->named_log(__FILE__, helpline);
}

Item::~Item() { }
