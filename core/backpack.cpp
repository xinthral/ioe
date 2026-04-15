#include "backpack.h"

/*!
 * @def     __FILENAME__
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

Backpack::Backpack() : Backpack("Backpack") {}

Backpack::Backpack(const char* name) : Equipment(name, BACKPACK) {}

bool Backpack::add_item(Item* item) {
  if (!item) {
    log->named_log(__FILENAME__, "Cannot add null item to backpack.");
    return false;
  }
  contents.push_back(item);
  sprintf(buf, "Added to backpack: %s", item->get_label());
  log->named_log(__FILENAME__, buf);
  return true;
}

bool Backpack::remove_item(const char* label) {
  for (auto it = contents.begin(); it != contents.end(); ++it) {
    if (strcmp((*it)->get_label(), label) == 0) {
      sprintf(buf, "Removed from backpack: %s", label);
      log->named_log(__FILENAME__, buf);
      contents.erase(it);
      return true;
    }
  }
  sprintf(buf, "Item not found in backpack: %s", label);
  log->named_log(__FILENAME__, buf);
  return false;
}

const std::vector<Item*>& Backpack::get_items() const {
  return contents;
}

void Backpack::_help() {
  std::string helpline = "\nBackpack Helpline!"
  "\n\tA wearable container. Can hold any item type."
  "\n\tFuture: stored item weights are halved while worn."
  "\n";
  log->named_log(__FILENAME__, helpline);
}

Backpack::~Backpack() {}
