/*!
 * @class   TestItem itemcase.cpp itemcase.h
 * @brief   Test for the Base Item 
*/

#include "itemcase.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @brief   Default Constructor
*/
TestItem::TestItem() : BaseCase(__FILENAME__) {
  BaseCase::log->named_log(__FILENAME__, "Testing Base Items!");
}

/*!
 * @brief   Default Deconstructor
*/
TestItem::~TestItem() { }
