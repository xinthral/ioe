#include "backpackcase.h"

/*!
 * @def     __FILENAME__
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

TestBackpack::TestBackpack() : BaseCase(__FILENAME__) {
  BaseCase::log->named_log(__FILENAME__, "Testing Backpack!");
  sprintf(this->msgHead, "Tested");
  sprintf(this->msgTail, "for Backpack!");
  _pack = nullptr;
  this->test_all();
}

void TestBackpack::test_all() {
  test_label();
  test_type();
  test_add_item();
  test_add_null();
  test_remove_item();
  test_remove_nonexistent();
  test_get_items();
}

void TestBackpack::test_label() {
  PROFILE_NAMED("Item_Label");
  delete _pack;
  _pack = new Backpack("MyPack");
  record(strcmp(_pack->get_label(), "MyPack") == 0, "Backpack label mismatch");
  sprintf(buf, "%s [%s] %s", msgHead, "backpack label", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestBackpack::test_type() {
  PROFILE_NAMED("Item_Type");
  delete _pack;
  _pack = new Backpack();
  record(_pack->get_type() == BACKPACK, "Backpack ItemType should be BACKPACK");
  sprintf(buf, "%s [%s] %s", msgHead, "backpack type", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestBackpack::test_add_item() {
  PROFILE_NAMED("Backpack_Inventory");
  delete _pack;
  _pack = new Backpack();
  Item* item = new Item("Potion");
  bool result = _pack->add_item(item);
  record(result == true, "add_item should return true for valid item");
  record(_pack->get_items().size() == 1, "Backpack contents size should be 1 after add");
  sprintf(buf, "%s [%s] %s", msgHead, "backpack add_item", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestBackpack::test_add_null() {
  PROFILE_NAMED("Backpack_Inventory");
  delete _pack;
  _pack = new Backpack();
  bool result = _pack->add_item(nullptr);
  record(result == false, "add_item should return false for nullptr");
  record(_pack->get_items().size() == 0, "Backpack contents should remain empty after null add");
  sprintf(buf, "%s [%s] %s", msgHead, "backpack add null", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestBackpack::test_remove_item() {
  PROFILE_NAMED("Backpack_Inventory");
  delete _pack;
  _pack = new Backpack();
  Item* item = new Item("Scroll");
  _pack->add_item(item);
  bool result = _pack->remove_item("Scroll");
  record(result == true, "remove_item should return true when item exists");
  record(_pack->get_items().size() == 0, "Backpack contents should be empty after removal");
  sprintf(buf, "%s [%s] %s", msgHead, "backpack remove_item", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestBackpack::test_remove_nonexistent() {
  PROFILE_NAMED("Backpack_Inventory");
  delete _pack;
  _pack = new Backpack();
  bool result = _pack->remove_item("GhostItem");
  record(result == false, "remove_item should return false when item not found");
  sprintf(buf, "%s [%s] %s", msgHead, "backpack remove nonexistent", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestBackpack::test_get_items() {
  PROFILE_NAMED("Backpack_Inventory");
  delete _pack;
  _pack = new Backpack();
  _pack->add_item(new Item("ItemA"));
  _pack->add_item(new Item("ItemB"));
  _pack->add_item(new Item("ItemC"));
  record(_pack->get_items().size() == 3, "get_items should return 3 items");
  sprintf(buf, "%s [%s] %s", msgHead, "backpack get_items", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

TestBackpack::~TestBackpack() { delete _pack; }
