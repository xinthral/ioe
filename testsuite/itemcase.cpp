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
  this->test_rarity();
  this->test_type();
}

/*!
 * @todo    Run full set of test on module 
*/
void TestItem::test_rarity() {
  ItemRarity junk = ItemRarity::JUNK;
  Item* check = new Item("TestItem");
  check->set_rarity(junk);
  assertm(check->get_rarity() == junk, "Item rarity does not match creation type");
  sprintf(buf, "%s [%s] %s", msgHead, "item rarity", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestItem::test_type() {
  ItemType ring = ItemType::RING;
  Item* check = new Item("TestItem");
  check->set_type(ring);
  assertm(check->get_type() == ring, "Item Type does not match creation type");
  sprintf(buf, "%s [%s] %s", msgHead, "item type", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Default Deconstructor
*/
TestItem::~TestItem() { }
