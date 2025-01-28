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
  sprintf(this->msgHead, "Tested");
  sprintf(this->msgTail, "feature!");
  this->test_all();
}

/*!
 * @todo    Run full set of test on module 
*/
void TestItem::test_all() {
  this->test_type();
}

/*!
 * @todo    Run full set of test on module 
*/
void TestItem::test_rarity() {}

void TestItem::test_type() {
  ItemRarity junk = ItemRarity::JUNK;
  Item* check = new Item("TestItem");
  check->set_rarity(junk);
  assertm(check->get_rarity() == junk, "Item Type does not match creation type");
  sprintf(buf, "%s [%s] %s", msgHead, "item type", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Default Deconstructor
*/
TestItem::~TestItem() { }
