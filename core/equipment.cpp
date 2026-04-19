#include "equipment.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

const std::unordered_map<int, EquipmentProfile> Equipment::_PROFILES = {
  { RELIC,   { 1.0f, 1.0f, 1.0f, 1.0f, 1.5f, 1.0f } },
  { RING,    { 1.2f, 1.0f, 1.2f, 1.0f, 1.0f, 1.0f } },
  { SHIELD,  { 1.0f, 1.5f, 1.0f, 1.0f, 1.0f, 1.0f } },
  { STAFF,   { 1.0f, 1.0f, 1.5f, 1.0f, 1.0f, 1.0f } },
  { SWORD,   { 1.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f } },
  { BACKPACK,{ 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f } },
};

static void applyProfile(Equipment* e, ItemType type) {
  auto it = Equipment::_PROFILES.find(static_cast<int>(type));
  if (it == Equipment::_PROFILES.end()) return;
  const EquipmentProfile& p = it->second;
  e->set_damage_multiplier(p.damage_multiplier);
  e->set_damage_mitigation(p.damage_mitigation);
  e->set_flux_multiplier(p.flux_multiplier);
  e->set_flux_mitigation(p.flux_mitigation);
  e->set_health_multiplier(p.health_multiplier);
  e->set_health_mitigation(p.health_mitigation);
}

Equipment::Equipment() : Item() {
  damage_multiplier  = 0.0f;
  damage_mitigation  = 0.0f;
  flux_multiplier    = 0.0f;
  flux_mitigation    = 0.0f;
  health_multiplier  = 0.0f;
  health_mitigation  = 0.0f;
}

Equipment::Equipment(const char* itemName) : Item(itemName) {
  damage_multiplier  = 0.0f;
  damage_mitigation  = 0.0f;
  flux_multiplier    = 0.0f;
  flux_mitigation    = 0.0f;
  health_multiplier  = 0.0f;
  health_mitigation  = 0.0f;
}

Equipment::Equipment(const char* itemName, ItemType type) : Item(itemName) {
  damage_multiplier  = 0.0f;
  damage_mitigation  = 0.0f;
  flux_multiplier    = 0.0f;
  flux_mitigation    = 0.0f;
  health_multiplier  = 0.0f;
  health_mitigation  = 0.0f;
  set_type(type);
  applyProfile(this, type);
}

/*!
 * @note FIXME: Add Development notes
*/
float Equipment::get_damage_multiplier() {
  return this->damage_multiplier;
}

/*!
 * @note FIXME: Add Development notes
*/
float Equipment::get_damage_mitigation() {
  return this->damage_mitigation;
}

/*!
 * @note FIXME: Add Development notes
*/
float Equipment::get_flux_multiplier() {
  return this->flux_multiplier;
}

/*!
 * @note FIXME: Add Development notes
*/
float Equipment::get_flux_mitigation() {
  return this->flux_mitigation;
}

/*!
 * @note FIXME: Add Development notes
*/
float Equipment::get_health_multiplier() {
  return this->health_multiplier;
}

/*!
 * @note FIXME: Add Development notes
*/
float Equipment::get_health_mitigation() {
  return this->health_mitigation;
}

/*!
 * @note FIXME: Add Development notes
*/
void Equipment::set_damage_multiplier(float modifier) {
  if (validate_multiplier(modifier)) { 
    this->damage_multiplier = modifier;
  }
}

/*!
 * @note FIXME: Add Development notes
*/
void Equipment::set_damage_mitigation(float modifier) {
  if (validate_multiplier(modifier)) { 
    this->damage_mitigation = modifier;
  }
}

/*!
 * @note FIXME: Add Development notes
*/
void Equipment::set_flux_multiplier(float modifier) {
  if (validate_multiplier(modifier)) { 
    this->flux_multiplier = modifier;
  }
}

/*!
 * @note FIXME: Add Development notes
*/
void Equipment::set_flux_mitigation(float modifier) {
  if (validate_multiplier(modifier)) { 
    this->flux_mitigation = modifier;
  }
}

/*!
 * @note FIXME: Add Development notes
*/
void Equipment::set_health_multiplier(float modifier) {
  if (validate_multiplier(modifier)) { 
    this->health_multiplier = modifier;
  }
}

/*!
 * @note FIXME: Add Development notes
*/
void Equipment::set_health_mitigation(float modifier) {
  if (validate_multiplier(modifier)) { 
    this->health_mitigation = modifier;
  }
}

/*!
 * @note FIXME: Add Development notes
*/
bool Equipment::validate_multiplier(float modifier) {
  return (0 <= modifier && modifier <= 2.0);
}

void Equipment::_help() {
  std::string helpline = "\nEquipment Help Line";
  helpline += "\n\tWearable item base class. Extends Item, equippable onto Actors.";
  helpline += "\n\tStat multipliers (all default 0.0f — unset):";
  helpline += "\n\t  damage_multiplier  — scales Actor attack on equip";
  helpline += "\n\t  damage_mitigation  — scales Actor defense on equip";
  helpline += "\n\t  flux_multiplier    — scales Actor flux on equip";
  helpline += "\n\t  flux_mitigation    — scales Actor flux mitigation on equip";
  helpline += "\n\t  health_multiplier  — scales Actor health on equip";
  helpline += "\n\t  health_mitigation  — scales Actor health mitigation on equip";
  helpline += "\n\tDefault profiles per ItemType (applied via Equipment(name, ItemType)):";
  helpline += "\n\t  SWORD    — damage_multiplier x1.5";
  helpline += "\n\t  SHIELD   — damage_mitigation x1.5";
  helpline += "\n\t  STAFF    — flux_multiplier x1.5";
  helpline += "\n\t  RING     — damage_multiplier x1.2, flux_multiplier x1.2";
  helpline += "\n\t  RELIC    — health_multiplier x1.5";
  helpline += "\n\t  BACKPACK — neutral (use Backpack subclass for container behavior)";
  helpline += "\n\tValidation: multipliers are clamped to [0.0, 2.0].";
  helpline += "\n";
  this->log->named_log(__FILENAME__, helpline);
}

Equipment::~Equipment() {}