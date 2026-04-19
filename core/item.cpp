
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
  log    = Logger::GetInstance();
  weight = 0.0f;
  strncpy(this->label, itemName, sizeof(this->label) - 1);
  this->label[sizeof(this->label) - 1] = '\0';
  log->named_log(__FILENAME__, "New Item Established.");
}

char* Item::get_label()       { return this->label; }
float Item::get_weight()      { return this->weight; }
void  Item::set_weight(float w) { this->weight = w; }

ItemRarity Item::get_rarity() {
  return _rarity;
}

ItemType Item::get_type() {
  return _type;
}

void Item::set_label(const char * name) {
  if (strlen(name) >= sizeof(this->label)) {
    this->log->named_log(__FILENAME__, "Warning: Label failed size comparison.");
    return;
  }
  strncpy(this->label, name, sizeof(this->label) - 1);
  this->label[sizeof(this->label) - 1] = '\0';
}

void Item::set_rarity(ItemRarity rarity) {
  int lower = static_cast<int>(ItemRarity::JUNK);
  int upper = static_cast<int>(ItemRarity::UNIQUE);
  if (lower <= rarity && rarity <= upper) {
    this->_rarity = rarity;
  } else {
    this->log->named_log(__FILENAME__, "Warning, Rarity out of range.");
  }
}

void Item::set_type(ItemType itemType) {
  int lower = static_cast<int>(ItemType::RELIC);
  int upper = static_cast<int>(ItemType::BACKPACK);
  if (lower <= itemType && itemType <= upper) {
    this->_type = itemType;
  } else {
    this->log->named_log(__FILENAME__, "Warning, Invalid Item Type.");
  }
}

/*!
 * @todo    Helper Hook used in CLI Help System
*/
void Item::_help() {
  std::string helpline = "\nItem Helpline!";
  helpline += "\n\tBase class for all items in the engine.";
  helpline += "\n\tSubclasses: Equipment, Backpack (and future: potions, scrolls, keys).";
  helpline += "\n\tKey members: label, weight, _rarity, _type.";
  helpline += "\n\tItemType values: RELIC, RING, SHIELD, STAFF, SWORD, BACKPACK";
  helpline += "\n\tItemRarity values: JUNK, COMMON, UNCOMMON, RARE, EPIC, LEGENDARY, UNIQUE";
  helpline += "\n\t  Note: only one UNIQUE item may be equipped to an Actor at a time.";
  helpline += "\n\tweight field — default 0.0f. Future: halved when stored in a worn Backpack.";
  helpline += "\n";
  log->named_log(__FILENAME__, helpline);
}

/*!
 * @todo    Default Deconstructor 
*/
Item::~Item() { }
