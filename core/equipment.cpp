#include "equipment.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

Equipment::Equipment() {}

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
  std::string helpline = "\nEquipment Help Line"
  "\n\tA base class for all wearable items."
  "\n";
  this->log->named_log(__FILENAME__, helpline);
}

Equipment::~Equipment() {}