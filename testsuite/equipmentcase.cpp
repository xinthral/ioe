#include "equipmentcase.h"

/*!
 * @def     __FILENAME__
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

TestEquipment::TestEquipment() : TestEquipment(0) {}

TestEquipment::TestEquipment(int granularity) : BaseCase(__FILENAME__) {
  set_granularity(granularity);
  BaseCase::log->named_log(__FILENAME__, "Testing Equipment!");
  sprintf(this->msgHead, "Tested");
  sprintf(this->msgTail, "for Equipment!");
  _equip = nullptr;
  this->test_all();
}

void TestEquipment::test_all() {
  test_default_multipliers();
  test_label();
  test_multiplier_validation();
  test_profile_sword();
  test_profile_shield();
  test_profile_staff();
  test_profile_ring();
  test_profile_relic();
  test_profile_backpack();
}

void TestEquipment::test_default_multipliers() {
  if (this->_granularity >= 1) {
    PROFILE_FUNCTION();
  }
  PROFILE_NAMED("Equipment_Multipliers");
  delete _equip;
  _equip = new Equipment();
  record(_equip->get_damage_multiplier()  == 0.0f, "Default damage_multiplier not 0.0f");
  record(_equip->get_damage_mitigation()  == 0.0f, "Default damage_mitigation not 0.0f");
  record(_equip->get_flux_multiplier()    == 0.0f, "Default flux_multiplier not 0.0f");
  record(_equip->get_flux_mitigation()    == 0.0f, "Default flux_mitigation not 0.0f");
  record(_equip->get_health_multiplier()  == 0.0f, "Default health_multiplier not 0.0f");
  record(_equip->get_health_mitigation()  == 0.0f, "Default health_mitigation not 0.0f");
  sprintf(buf, "%s [%s] %s", msgHead, "default multipliers", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestEquipment::test_label() {
  if (this->_granularity >= 1) {
    PROFILE_FUNCTION();
  }
  PROFILE_NAMED("Item_Label");
  delete _equip;
  _equip = new Equipment("Excalibur", SWORD);
  record(strcmp(_equip->get_label(), "Excalibur") == 0, "Equipment label mismatch");
  sprintf(buf, "%s [%s] %s", msgHead, "equipment label", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestEquipment::test_multiplier_validation() {
  if (this->_granularity >= 1) {
    PROFILE_FUNCTION();
  }
  PROFILE_NAMED("Equipment_Multipliers");
  delete _equip;
  _equip = new Equipment();
  _equip->set_damage_multiplier(3.0f);
  record(_equip->get_damage_multiplier() == 0.0f, "Multiplier should reject values > 2.0");
  _equip->set_damage_multiplier(-1.0f);
  record(_equip->get_damage_multiplier() == 0.0f, "Multiplier should reject negative values");
  _equip->set_damage_multiplier(1.5f);
  record(_equip->get_damage_multiplier() == 1.5f, "Multiplier should accept values in [0, 2.0]");
  sprintf(buf, "%s [%s] %s", msgHead, "multiplier validation", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestEquipment::test_profile_sword() {
  if (this->_granularity >= 1) {
    PROFILE_FUNCTION();
  }
  PROFILE_NAMED("Equipment_Profiles");
  delete _equip;
  _equip = new Equipment("Sword", SWORD);
  record(_equip->get_damage_multiplier() == 1.5f, "SWORD damage_multiplier should be 1.5f");
  record(_equip->get_damage_mitigation() == 1.0f, "SWORD damage_mitigation should be 1.0f");
  sprintf(buf, "%s [%s] %s", msgHead, "SWORD profile", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestEquipment::test_profile_shield() {
  if (this->_granularity >= 1) {
    PROFILE_FUNCTION();
  }
  PROFILE_NAMED("Equipment_Profiles");
  delete _equip;
  _equip = new Equipment("Shield", SHIELD);
  record(_equip->get_damage_mitigation() == 1.5f, "SHIELD damage_mitigation should be 1.5f");
  record(_equip->get_damage_multiplier() == 1.0f, "SHIELD damage_multiplier should be 1.0f");
  sprintf(buf, "%s [%s] %s", msgHead, "SHIELD profile", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestEquipment::test_profile_staff() {
  if (this->_granularity >= 1) {
    PROFILE_FUNCTION();
  }
  PROFILE_NAMED("Equipment_Profiles");
  delete _equip;
  _equip = new Equipment("Staff", STAFF);
  record(_equip->get_flux_multiplier() == 1.5f, "STAFF flux_multiplier should be 1.5f");
  record(_equip->get_damage_multiplier() == 1.0f, "STAFF damage_multiplier should be 1.0f");
  sprintf(buf, "%s [%s] %s", msgHead, "STAFF profile", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestEquipment::test_profile_ring() {
  if (this->_granularity >= 1) {
    PROFILE_FUNCTION();
  }
  PROFILE_NAMED("Equipment_Profiles");
  delete _equip;
  _equip = new Equipment("Ring", RING);
  record(_equip->get_damage_multiplier() == 1.2f, "RING damage_multiplier should be 1.2f");
  record(_equip->get_flux_multiplier()   == 1.2f, "RING flux_multiplier should be 1.2f");
  sprintf(buf, "%s [%s] %s", msgHead, "RING profile", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestEquipment::test_profile_relic() {
  if (this->_granularity >= 1) {
    PROFILE_FUNCTION();
  }
  PROFILE_NAMED("Equipment_Profiles");
  delete _equip;
  _equip = new Equipment("Relic", RELIC);
  record(_equip->get_health_multiplier() == 1.5f, "RELIC health_multiplier should be 1.5f");
  record(_equip->get_damage_multiplier() == 1.0f, "RELIC damage_multiplier should be 1.0f");
  sprintf(buf, "%s [%s] %s", msgHead, "RELIC profile", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

void TestEquipment::test_profile_backpack() {
  if (this->_granularity >= 1) {
    PROFILE_FUNCTION();
  }
  PROFILE_NAMED("Equipment_Profiles");
  delete _equip;
  _equip = new Equipment("Backpack", BACKPACK);
  record(_equip->get_damage_multiplier() == 1.0f, "BACKPACK damage_multiplier should be 1.0f");
  record(_equip->get_health_multiplier() == 1.0f, "BACKPACK health_multiplier should be 1.0f");
  sprintf(buf, "%s [%s] %s", msgHead, "BACKPACK profile", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

TestEquipment::~TestEquipment() { delete _equip; }
