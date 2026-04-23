#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include <vector>
#include "config.h"
#include "equipment.h"
#include "strategy.h"
#include "utilz.h"

//! Actor Combat States
enum CombatState {
  IDLE,
  PATROL,
  FIGHT,
  FLEE,
  HIDE,
  FOLLOW
};
extern enum CombatState combatState;

static inline const char* combatStateStr(CombatState s) {
  switch(s) {
    case IDLE:   return "IDLE";
    case PATROL: return "PATROL";
    case FIGHT:  return "FIGHT";
    case FLEE:   return "FLEE";
    case HIDE:   return "HIDE";
    case FOLLOW: return "FOLLOW";
    default:     return "UNKNOWN";
  }
}

//! Actor Health States
enum HealthState {
  HEALTHY,
  HURTING,
  CRITICAL,
  SICK,
  DEAD
};
extern enum HealthState healthState;

static inline const char* healthStateStr(HealthState s) {
  switch(s) {
    case HEALTHY:  return "HEALTHY";
    case HURTING:  return "HURTING";
    case CRITICAL: return "CRITICAL";
    case SICK:     return "SICK";
    case DEAD:     return "DEAD";
    default:       return "UNKNOWN";
  }
}

/*!
 * @class   Actor actor.h actor.cpp
 * @brief   The base class for all Toon and Player types.
*/
class Actor {
protected:
  ConfigManager* cnf;       //!< ConfigManager Instantiation
  Logger* log;              //!< Logging Handler Instantiation
  CombatState aiState;      //!< Current AI CombatState
  HealthState condition;    //!< Current Health State
  std::string name;         //!< Name of Actor
  int id;                   //!< ID of Actor
  int level;                //!< Level of Actor
  int baseAttack;           //!< Attack Damage
  int attack;               //!< Attack Value  (@override)
  int baseDefense;          //!< Defense Value
  int defense;              //!< Defense Value (@override)
  int baseHealth;           //!< Health Value
  int health;               //!< Health Value  (@override)
  int baseFlux;             //!< Flux Value
  int flux;                 //!< Flux Value    (@override)
  char buf[256];            //!< Buffer Value for Logger outputs
  std::vector<Equipment*> equipped; //!< Currently equipped items
  CombatStrategy* _strategy;        //!< Modular combat behaviour (owned by Actor)

private:
public:
  /*!
   * @brief   Default Constructor 
  */
  Actor();

  /*!
   * @overload
   * @brief   Overloaded Constructor 
   * @param[in] name - Name of Actor
  */
  Actor(std::string);

  /*!
   * @brief   Conditional Combat Check 
   * @details Confirm if Actor is currently fighting
   * @returns Boolean answer 
  */
  bool isFighting();

  /*!
   * @brief   Conditional Health Check 
   * @details Confirm if Actor is not dead
   * @returns Boolean answer 
  */
  bool isAlive();

  /*!
   * @brief   Return Attack Attribute
   * @returns Base Attack Value 
  */
  int get_baseAttack();
  int get_attack();
  void set_attack(int);

  /*!
   * @brief   Return Defense Attribute
   * @returns Base Defense Value 
  */
  int get_baseDefense();
  int get_defense();
  void set_defense(int);

  /*!
   * @brief   Return Flux Attribute
   * @returns Flux Value
  */
  int get_baseFlux();
  int get_flux();

  /*!
   * @brief   Return Health Attribute
   * @returns Base Health Value 
  */
  int get_baseHealth();
  int get_health();
  void set_health(int);

  /*!
   * @brief   Return ID Attribute
   * @returns Identity Reference Number
  */
  int get_id();

  int get_level();

  /*!
   * @brief   Return Name Attribute
   * @returns Name Value 
  */
  std::string get_name();

  /*!
   * @brief   ReAssign Actor Flux Value
   * @details Set Flux Attribute 
   * @param[in] flux - New Flux Value
  */
  void set_flux(int);

  /*!
   * @brief   ReAssign Actor ID number
   * @details Set ID Attribute
   * @param[in] id - Identity Reference Number
  */
  void set_id(int);

  /*!
   * @brief   ReAssign Actor Level number
   * @details Set Level Attribute
   * @param[in] level - New Level Value
  */
  void set_level(int);

  /*!
   * @brief   ReAssign Actor Name
   * @details Set Name Attribute
   * @param[in] name - New Name Value
  */
  void set_name(std::string);

  /*!
   * @brief   Return Combat State 
   * @returns Current Combat State of the character.
  */
  CombatState get_combatstate();

  /*!
   * @brief   ReAssign Combat State
   * @param[in] state Current State of the Combat AI 
  */
  void set_combatstate(CombatState);

  /*!
   * @brief   Calculates Current Damage Output
   *          including multipliers and reducers
   * @returns Final Damage Value
  */
  virtual int output_damage();

  /*!
   * @brief   Set Combat State to Idling
  */
  void set_combat_idle();

  /*!
   * @brief   Set Combat State to Patrolling 
  */
  void set_combat_patrol();

  /*!
   * @brief   Set Combat State to Fighting 
  */
  void set_combat_fight();

  /*!
   * @brief   Set Combat State to Fleeing 
  */
  void set_combat_flee();

  /*!
   * @brief   Set Combat State to Following 
  */
  void set_combat_follow();

  /*!
   * @brief   Return Health State
   * @returns Current Health State of the character.
  */
  HealthState get_healthstate();

  /*!
   * @brief   ReAssign Health State
  */
  void set_healthstate(HealthState);

  /*!
   * @brief   Calculates and adjust damage received
   *          including multiplier and reducers
   * @returns Final Damage Value
  */
  virtual int receive_damage(int);

  /*!
   * @brief   Set Health State to Healthy
  */
  void set_health_healthy();

  /*!
   * @brief   Set Health State to Hurting
  */
  void set_health_hurting();

  /*!
   * @brief   Set Health State to Critical 
  */
  void set_health_critical();

  /*!
   * @brief   Set Health State to Sick 
  */
  void set_health_sick();

  /*!
   * @brief   Set Health State to Dead 
  */
  void set_health_dead();

  /*!
   * @brief   Equip an item onto this actor.
   * @details Rejects if: slot is full (16 items), an item of the same ItemType
   *          is already equipped, or the item is UNIQUE and one is already worn.
   * @param[in] item - Pointer to the Equipment to equip
   * @returns true if equipped successfully, false if rejected
  */
  bool equip(Equipment*);

  /*!
   * @brief   Unequip the item occupying the given type slot.
   * @details Reverses the item's multipliers from the actor's stats.
   * @param[in] type - The ItemType slot to clear
   * @returns true if an item was removed, false if the slot was empty
  */
  bool unequip(ItemType);

  /*!
   * @brief   Return all currently equipped items.
   * @returns Const reference to the equipped item vector
  */
  const std::vector<Equipment*>& get_equipped() const;

  /*!
   * @brief   Replace the actor's combat strategy
   * @details Takes ownership of the provided pointer and deletes the previous strategy.
   *          Use make_strategy(StyleType) to construct the desired style.
   * @param[in] s  Heap-allocated CombatStrategy to adopt
  */
  void set_strategy(CombatStrategy* s);

  /*!
   * @brief   Return the actor's current combat strategy
  */
  CombatStrategy* get_strategy() const;

  /*!
   * @brief   Helper Hook used in CLI Help System
  */
  void _help();

  /*!
   * @brief   Default Deconstructor
  */
  virtual ~Actor();
};

#endif // ACTOR_H //
