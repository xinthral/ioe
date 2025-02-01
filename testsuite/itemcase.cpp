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
  this->itemrarity();
  this->rarity_invalidation();
  this->itemtype();
}

/*!
 * @todo    Run full set of test on module 
*/
void TestItem::itemrarity() {
  PROFILE_FUNCTION();
  ItemRarity junk = ItemRarity::JUNK;
  Item* check = new Item("TestItem");
  check->set_rarity(junk);
  assertm(check->get_rarity() == junk, "Item rarity does not match creation type");
  sprintf(buf, "%s [%s] %s", msgHead, "item rarity", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestItem::rarity_invalidation() {
  PROFILE_FUNCTION();
  ItemRarity junk = static_cast<ItemRarity>(-2);
  Item* check = new Item("TestItem");
  check->set_rarity(junk);
  assertm(check->get_rarity() != junk, "Item rarity should not allow negatives");
  sprintf(buf, "%s [%s] %s", msgHead, "item rarity invalidation", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestItem::itemtype() {
  PROFILE_FUNCTION();
  ItemType ring = ItemType::RING;
  Item* check = new Item("TestItem");
  check->set_type(ring);
  assertm(check->get_type() == ring, "Item Type does not match creation type");
  sprintf(buf, "%s [%s] %s", msgHead, "item type", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestItem::type_invalidation() {
  PROFILE_FUNCTION();
  ItemType ring = static_cast<ItemType>(-1);
  Item* check = new Item("TestItem");
  check->set_type(ring);
  assertm(check->get_type() != ring, "Item Type should not allow negatives");
  sprintf(buf, "%s [%s] %s", msgHead, "item type invalidation", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @todo    Default Deconstructor
*/
TestItem::~TestItem() { }
