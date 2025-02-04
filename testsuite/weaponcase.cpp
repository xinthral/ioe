#include "weaponcase.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

TestWeapon::TestWeapon() : BaseCase(__FILENAME__) {
  BaseCase::log->named_log(__FILENAME__, "Testing the Weapon Functionality!");
  sprintf(this->msgHead, "Tested");
  sprintf(this->msgTail, "for Weapons!");
  this->test_all();
}

void TestWeapon::test_all() {
  this->test_weapon_type();
}

void TestWeapon::test_weapon_type() {
  PROFILE_FUNCTION();
  ItemType staff = ItemType::STAFF;
  ItemType sword = ItemType::SWORD;
  Weapon * wep = new Weapon();
  wep->set_type(staff);
  assertm(wep->get_type() == staff, "Weapon type mismatch!\n");
  wep->set_type(sword);
  assertm(wep->get_type() == sword, "Weapon retype mismatch!\n");
  sprintf(buf, "%s [%s] %s", msgHead, "weapon type check", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

TestWeapon::~TestWeapon() {}