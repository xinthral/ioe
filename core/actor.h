#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include "config.h"
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

//! Actor Health States
enum HealthState { 
  HEALTHY,
  HURTING,
  CRITICAL,
  SICK,
  DEAD
};
extern enum HealthState healthState;

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
  int baseAttack;           //!< Attack Damage
  int attack;               //!< Attack Value  (@override)
  int baseDefense;          //!< Defense Value
  int defense;              //!< Defense Value (@override)
  int baseHealth;           //!< Health Value
  int health;               //!< Health Value  (@override)
  int baseFlux;             //!< Flux Value
  int flux;                 //!< Flux Value    (@override)
  char buf[256];            //!< Buffer Value for Logger outputs

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

  /*!
   * @brief   Return Defense Attribute
   * @returns Base Defense Value 
  */
  int get_baseDefense();
  int get_defense();

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

  /*!
   * @brief   Return ID Attribute
   * @returns Identity Reference Number
  */
  int get_id();

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
  int output_damage();

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
  int receive_damage(int);

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
   * @brief   Helper Hook used in CLI Help System
  */
  void _help();

  /*!
   * @brief   Default Deconstructor 
  */
  ~Actor();
};

#endif // ACTOR_H //
