#include "itemcase.h"

/*!
 * @def     __FILENAME__
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

TestItem::TestItem() : BaseCase(__FILENAME__) {
  BaseCase::log->named_log(__FILENAME__, "Testing Base Items!");
  sprintf(this->msgHead, "Tested");
  sprintf(this->msgTail, "feature!");
  _item = nullptr;
  this->test_all();
}

void TestItem::test_all() {
  test_label();
  test_label_overflow();
  itemrarity();
  rarity_invalidation();
  itemtype();
  type_invalidation();
  test_backpack_type();
  test_weight();
}

void TestItem::test_label() {
  PROFILE_NAMED("Item_Label");
  delete _item;
  _item = new Item("Potion");
  record(strcmp(_item->get_label(), "Potion") == 0, "Item label mismatch on construction");
  sprintf(buf, "%s [%s] %s", msgHead, "item label", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestItem::test_label_overflow() {
  PROFILE_NAMED("Item_Label");
  delete _item;
  _item = new Item("LegalName");
  // 101-char string — exceeds the 100-char label buffer
  const char* overflow = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
  _item->set_label(overflow);
  record(strcmp(_item->get_label(), overflow) != 0, "set_label should reject strings >= 100 chars");
  sprintf(buf, "%s [%s] %s", msgHead, "label overflow rejection", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestItem::itemrarity() {
  PROFILE_NAMED("Item_Rarity");
  delete _item;
  _item = new Item("RarityTest");
  _item->set_rarity(ItemRarity::JUNK);
  record(_item->get_rarity() == ItemRarity::JUNK, "Item rarity does not match set value");
  _item->set_rarity(ItemRarity::UNIQUE);
  record(_item->get_rarity() == ItemRarity::UNIQUE, "Item rarity should accept UNIQUE");
  sprintf(buf, "%s [%s] %s", msgHead, "item rarity", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestItem::rarity_invalidation() {
  PROFILE_NAMED("Item_Rarity");
  delete _item;
  _item = new Item("RarityInvalid");
  ItemRarity bad = static_cast<ItemRarity>(-2);
  _item->set_rarity(bad);
  record(_item->get_rarity() != bad, "Item rarity should reject negative values");
  sprintf(buf, "%s [%s] %s", msgHead, "rarity invalidation", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestItem::itemtype() {
  PROFILE_NAMED("Item_Type");
  delete _item;
  _item = new Item("TypeTest");
  _item->set_type(ItemType::RING);
  record(_item->get_type() == ItemType::RING, "Item type does not match set value");
  _item->set_type(ItemType::SWORD);
  record(_item->get_type() == ItemType::SWORD, "Item type should accept SWORD");
  sprintf(buf, "%s [%s] %s", msgHead, "item type", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestItem::type_invalidation() {
  PROFILE_NAMED("Item_Type");
  delete _item;
  _item = new Item("TypeInvalid");
  ItemType bad = static_cast<ItemType>(-1);
  _item->set_type(bad);
  record(_item->get_type() != bad, "Item type should reject negative values");
  sprintf(buf, "%s [%s] %s", msgHead, "type invalidation", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestItem::test_backpack_type() {
  PROFILE_NAMED("Item_Type");
  delete _item;
  _item = new Item("BackpackTest");
  _item->set_type(ItemType::BACKPACK);
  record(_item->get_type() == ItemType::BACKPACK, "Item type should accept BACKPACK");
  sprintf(buf, "%s [%s] %s", msgHead, "BACKPACK type", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestItem::test_weight() {
  PROFILE_FUNCTION();
  delete _item;
  _item = new Item("WeightTest");
  record(_item->get_weight() == 0.0f, "Default item weight should be 0.0f");
  _item->set_weight(3.5f);
  record(_item->get_weight() == 3.5f, "Item weight get/set round-trip failed");
  sprintf(buf, "%s [%s] %s", msgHead, "weight", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

TestItem::~TestItem() { delete _item; }
