
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

/*!
 * @note FIXME: Needs developer note
*/
Item::Item(const char *itemName) {
  log = Logger::GetInstance();
  log->named_log(__FILENAME__, "New Item Established.");
}

/*!
 * @note FIXME: Needs developer note
*/
char * Item::get_label() {
  return this->label;
}

/*!
 * @note FIXME: Needs developer note
*/
char * Item::get_long_descriptor() {
  return this->long_descriptor;
}

/*!
 * @note FIXME: Needs developer note
*/

ItemRarity Item::get_rarity() {
  return this->_rarity;
}

/*!
 * @note FIXME: Needs developer note
*/
char * Item::get_short_descriptor() {
  return this->short_descriptor;
}

/*!
 * @note FIXME: Needs developer note
*/
ItemType Item::get_type() {
  return this->_type;
}

/*!
 * @note FIXME: Needs developer note
*/
void Item::set_label(const char * name) {
  if (sizeof(name) > sizeof(this->label)) {
    this->log->named_log(__FILENAME__, "Warning: Label failed size comparison.");
    return;
  }
  strcpy(this->label, name);
}

/*!
 * @note FIXME: Needs developer note
*/
void Item::set_long_descriptor(const char *details) {
  if (!details) {
    throw std::invalid_argument("details cannot be null");
  }

  int response = std::snprintf(this->long_descriptor, LD_MAX_LEN, "%s\n", details);

  if (response < 0) {
    throw std::runtime_error("long_descriptor failed to write due to encoding error");
  } else if (response >= LD_MAX_LEN) {
    throw std::overflow_error("long_descriptor buffer overflow detected");
  }
}

/*!
 * @note FIXME: Needs developer note
*/

void Item::set_rarity(ItemRarity rarity) {
  using UnderlyingType = std::underlying_type_t<ItemRarity>;

  constexpr UnderlyingType lower = static_cast<UnderlyingType>(ItemRarity::JUNK);
  constexpr UnderlyingType upper = static_cast<UnderlyingType>(ItemRarity::UNIQUE);

  if (lower <= static_cast<UnderlyingType>(rarity) && static_cast<UnderlyingType>(rarity) <= upper) {
    this->_rarity = rarity;
  } else {
    this->log->named_log(__FILENAME__, "Warning, Rarity out of range: " + std::to_string(static_cast<UnderlyingType>(rarity)));
  }
}

/*!
 * @note FIXME: Needs developer note
*/
void Item::set_short_descriptor(const char *details) {
  if (!details) {
    throw std::invalid_argument("details cannot be null");
  }

  int response = std::snprintf(this->short_descriptor, SD_MAX_LEN, "%s\n", details);

  if (response < 0) {
    throw std::runtime_error("short_descriptor failed to write due to encoding error");
  } else if (response >= SD_MAX_LEN) {
    throw std::overflow_error("short_descriptor buffer overflow detected");
  }
}

/*!
 * @note FIXME: Needs developer note
*/
void Item::set_type(ItemType itemType) {
  using UnderlyingType = std::underlying_type_t<ItemType>;

  constexpr UnderlyingType lower = static_cast<UnderlyingType>(ItemType::RELIC);
  constexpr UnderlyingType upper = static_cast<UnderlyingType>(ItemType::SWORD);

  if (lower <= static_cast<UnderlyingType>(itemType) && static_cast<UnderlyingType>(itemType) <= upper) {
    this->_type = itemType;
  } else {
    this->log->named_log(__FILENAME__, "Warning, Invalid Item Type: " +
          std::to_string(static_cast<UnderlyingType>(itemType)));
  }
}

/*!
 * @todo    Helper Hook used in CLI Help System
*/
void Item::_help() { 
  std::string helpline = "\nItem Helpline!"
  "\n\tThe item is an inherited class, contain most of the base code. This will also act as an interface with the"
  "\ninventory, maintaining accumulative/calculated totals for what your items add to your characters statistics."
  "\n";
  this->log->named_log(__FILENAME__, helpline);
}

/*!
 * @todo    Default Deconstructor 
*/
Item::~Item() { }
