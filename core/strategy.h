#ifndef STRATEGY_H
#define STRATEGY_H

#include <cstdlib>

/*!
 * @brief   Identifies which combat style to instantiate via make_strategy()
*/
enum class StyleType { BALANCED, AGGRESSIVE, DEFENSIVE, BERSERKER, COWARDLY };

/*!
 * @class   CombatStrategy strategy.h strategy.cpp
 * @brief   Abstract base for modular combat behaviour attached to any Actor
 * @details Each concrete strategy owns its own hit_chance, crit_chance, dodge_chance,
 *          and crit_mult values and defines three resolution steps:
 *            - resolve_attack()  — applies miss/crit to a base damage value
 *            - resolve_defense() — applies dodge to incoming damage
 *            - should_flee()     — returns true when the actor should disengage
 *
 *          Assign to any Actor via Actor::set_strategy(). The default is BalancedStyle.
*/
class CombatStrategy {
protected:
  float _hit_chance;    //!< Probability [0,1] of landing an attack
  float _crit_chance;   //!< Probability [0,1] of a critical hit given a landed attack
  float _dodge_chance;  //!< Probability [0,1] of fully avoiding incoming damage
  int   _crit_mult;     //!< Damage multiplier applied on a critical hit

  float roll() const { return static_cast<float>(rand()) / static_cast<float>(RAND_MAX); }

public:
  /*!
   * @brief   Apply hit chance and crit chance to a base damage value
   * @param[in] base  Raw damage from the attacker's stats
   * @returns Final attack damage; 0 on a miss
  */
  virtual int resolve_attack(int base) = 0;

  /*!
   * @brief   Apply dodge chance to incoming damage
   * @param[in] incoming  Damage value after attacker's resolution
   * @returns Damage to actually apply; 0 on a dodge
  */
  virtual int resolve_defense(int incoming) = 0;

  /*!
   * @brief   Decide whether the actor should flee at the given HP value
   * @param[in] hp  Actor's current health
   * @returns true if the actor should set its combat state to FLEE
  */
  virtual bool should_flee(int hp) = 0;

  /*!
   * @brief   Human-readable strategy name for logging
  */
  virtual const char* get_name() const = 0;

  virtual ~CombatStrategy() = default;

  float hit_chance()   const { return _hit_chance; }
  float crit_chance()  const { return _crit_chance; }
  float dodge_chance() const { return _dodge_chance; }
  int   crit_mult()    const { return _crit_mult; }
};

/*!
 * @class   BalancedStyle strategy.h
 * @brief   Standard combat behaviour — 85% hit / 10% crit / 15% dodge / 2× crit, never flees
*/
class BalancedStyle : public CombatStrategy {
public:
  BalancedStyle();
  int  resolve_attack(int base)  override;
  int  resolve_defense(int dmg)  override;
  bool should_flee(int hp)       override;
  const char* get_name() const   override { return "Balanced"; }
};

/*!
 * @class   AggressiveStyle strategy.h
 * @brief   Offence-first behaviour — 90% hit / 25% crit / 5% dodge / 2× crit, never flees
*/
class AggressiveStyle : public CombatStrategy {
public:
  AggressiveStyle();
  int  resolve_attack(int base)  override;
  int  resolve_defense(int dmg)  override;
  bool should_flee(int hp)       override;
  const char* get_name() const   override { return "Aggressive"; }
};

/*!
 * @class   DefensiveStyle strategy.h
 * @brief   Survival-first behaviour — 75% hit / 5% crit / 35% dodge / 2× crit, flees below 20% HP
*/
class DefensiveStyle : public CombatStrategy {
public:
  DefensiveStyle();
  int  resolve_attack(int base)  override;
  int  resolve_defense(int dmg)  override;
  bool should_flee(int hp)       override;
  const char* get_name() const   override { return "Defensive"; }
};

/*!
 * @class   BerserkerStyle strategy.h
 * @brief   High-risk behaviour — 70% hit / 30% crit / 5% dodge / 3× crit, never flees
*/
class BerserkerStyle : public CombatStrategy {
public:
  BerserkerStyle();
  int  resolve_attack(int base)  override;
  int  resolve_defense(int dmg)  override;
  bool should_flee(int hp)       override;
  const char* get_name() const   override { return "Berserker"; }
};

/*!
 * @class   CowardlyStyle strategy.h
 * @brief   Evasion-first behaviour — 70% hit / 5% crit / 40% dodge / 1× crit, flees below 50% HP
*/
class CowardlyStyle : public CombatStrategy {
public:
  CowardlyStyle();
  int  resolve_attack(int base)  override;
  int  resolve_defense(int dmg)  override;
  bool should_flee(int hp)       override;
  const char* get_name() const   override { return "Cowardly"; }
};

/*!
 * @brief   Factory: construct and return a heap-allocated strategy for the given StyleType
 * @param[in] type  Desired combat style
 * @returns Pointer to newly allocated CombatStrategy; caller takes ownership
*/
CombatStrategy* make_strategy(StyleType type);

#endif // STRATEGY_H //
