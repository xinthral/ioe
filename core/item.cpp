
#include "item.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

/*!
 * @todo    Default Constructor 
*/
Item::Item() : Item::Item("Items") {}

Item::Item(const char itemName[]) {
  log = Logger::GetInstance();
  log->named_log(__FILENAME__, "New Item Established.");
}

char * Item::get_label() {
  return this->label;
}

ItemRarity Item::get_rarity() {
  return _rarity;
}

ItemType Item::get_type() {
  return _type;
}

void Item::set_label(const char * name) {
  if (sizeof(name) > sizeof(this->label)) {
    this->log->named_log(__FILENAME__, "Warning: Label failed size comparison.");
    return;
  }
  strcpy(this->label, name);
}

void Item::set_rarity(ItemRarity rarity) {
  int lower = static_cast<int>(ItemRarity::JUNK);
  int upper = static_cast<int>(ItemRarity::UNIQUE);
  if (lower <= rarity && rarity < upper) {
    this->_rarity = rarity;
  } else {
    this->log->named_log(__FILENAME__, "Warning, Rarity out of range.");
  }
}

void Item::set_type(ItemType itemType) {
  int lower = static_cast<int>(ItemType::RELIC);
  int upper = static_cast<int>(ItemType::SWORD);
  if (lower <= itemType && itemType < upper) {
    this->_type = itemType;
  } else {
    this->log->named_log(__FILENAME__, "Warning, Invalid Item Type.");
  }
}

/*!
 * @todo    Helper Hook used in CLI Help System
*/
void Item::_help() { 
  std::string helpline = "\nItem Helpline!"
  "\n";
  log->named_log(__FILENAME__, helpline);
}

/*!
 * @todo    Default Deconstructor 
*/
Item::~Item() { }
