#include "itemcase.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor
*/
TestItem::TestItem() : BaseCase(__FILENAME__) {
  BaseCase::log->named_log(__FILENAME__, "Testing Base Items!");
}

/*!
 * @todo    Run full set of test on module 
*/
void TestItem::test_all() {

}

/*!
 * @todo    Run full set of test on module 
*/
// void TestItem::() {}

/*!
 * @todo    Default Deconstructor
*/
TestItem::~TestItem() { }
