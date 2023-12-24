/*!
 * @class   TestItem itemcase.cpp itemcase.h
 * @brief   Test for the Base Item 
*/

#include "itemcase.h"

/*!
 * @brief   Default Constructor
*/
TestItem::TestItem() : BaseCase(__FILE__) {
  BaseCase::log->named_log(__FILE__, "Testing Base Items!");
}

/*!
 * @brief   Default Deconstructor
*/
TestItem::~TestItem() { }
