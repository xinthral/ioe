#include "strategy.h"

// ─── BalancedStyle ────────────────────────────────────────────────────────────

BalancedStyle::BalancedStyle() {
  _hit_chance   = 0.85f;
  _crit_chance  = 0.10f;
  _dodge_chance = 0.15f;
  _crit_mult    = 2;
}

int BalancedStyle::resolve_attack(int base) {
  if (roll() > _hit_chance)  return 0;
  if (roll() < _crit_chance) return base * _crit_mult;
  return base;
}

int BalancedStyle::resolve_defense(int dmg) {
  return (roll() < _dodge_chance) ? 0 : dmg;
}

bool BalancedStyle::should_flee(int) { return false; }

// ─── AggressiveStyle ──────────────────────────────────────────────────────────

AggressiveStyle::AggressiveStyle() {
  _hit_chance   = 0.90f;
  _crit_chance  = 0.25f;
  _dodge_chance = 0.05f;
  _crit_mult    = 2;
}

int AggressiveStyle::resolve_attack(int base) {
  if (roll() > _hit_chance)  return 0;
  if (roll() < _crit_chance) return base * _crit_mult;
  return base;
}

int AggressiveStyle::resolve_defense(int dmg) {
  return (roll() < _dodge_chance) ? 0 : dmg;
}

bool AggressiveStyle::should_flee(int) { return false; }

// ─── DefensiveStyle ───────────────────────────────────────────────────────────

DefensiveStyle::DefensiveStyle() {
  _hit_chance   = 0.75f;
  _crit_chance  = 0.05f;
  _dodge_chance = 0.35f;
  _crit_mult    = 2;
}

int DefensiveStyle::resolve_attack(int base) {
  if (roll() > _hit_chance)  return 0;
  if (roll() < _crit_chance) return base * _crit_mult;
  return base;
}

int DefensiveStyle::resolve_defense(int dmg) {
  return (roll() < _dodge_chance) ? 0 : dmg;
}

bool DefensiveStyle::should_flee(int hp) { return hp < 13; }  // ~20% of 64 HP

// ─── BerserkerStyle ───────────────────────────────────────────────────────────

BerserkerStyle::BerserkerStyle() {
  _hit_chance   = 0.70f;
  _crit_chance  = 0.30f;
  _dodge_chance = 0.05f;
  _crit_mult    = 3;
}

int BerserkerStyle::resolve_attack(int base) {
  if (roll() > _hit_chance)  return 0;
  if (roll() < _crit_chance) return base * _crit_mult;
  return base;
}

int BerserkerStyle::resolve_defense(int dmg) {
  return (roll() < _dodge_chance) ? 0 : dmg;
}

bool BerserkerStyle::should_flee(int) { return false; }

// ─── CowardlyStyle ────────────────────────────────────────────────────────────

CowardlyStyle::CowardlyStyle() {
  _hit_chance   = 0.70f;
  _crit_chance  = 0.05f;
  _dodge_chance = 0.40f;
  _crit_mult    = 1;
}

int CowardlyStyle::resolve_attack(int base) {
  if (roll() > _hit_chance)  return 0;
  if (roll() < _crit_chance) return base * _crit_mult;
  return base;
}

int CowardlyStyle::resolve_defense(int dmg) {
  return (roll() < _dodge_chance) ? 0 : dmg;
}

bool CowardlyStyle::should_flee(int hp) { return hp < 32; }  // ~50% of 64 HP

// ─── Factory ─────────────────────────────────────────────────────────────────

CombatStrategy* make_strategy(StyleType type) {
  switch (type) {
    case StyleType::AGGRESSIVE: return new AggressiveStyle();
    case StyleType::DEFENSIVE:  return new DefensiveStyle();
    case StyleType::BERSERKER:  return new BerserkerStyle();
    case StyleType::COWARDLY:   return new CowardlyStyle();
    default:                    return new BalancedStyle();
  }
}
