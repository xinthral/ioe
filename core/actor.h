#ifndef ACTOR_H
#define ACTOR_H

// #include <stdexcept>
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
  Logger* log;              //!< Logging Handler Instantiation
  char buf[256];            //!< Buffer Value for Logger outputs

private:
  ConfigManager* cnf;       //!< ConfigManager Instantiation
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

  int get_attack();

  /*!
   * @brief   Return Attack Attribute
   * @returns Base Attack Value 
  */
  int get_baseAttack();

  /*!
   * @brief   Return Defense Attribute
   * @returns Base Defense Value 
  */
  int get_baseDefense();

  /*!
   * @brief   Return Flux Attribute
   * @returns Flux Value
  */
  int get_baseFlux();

  /*!
   * @brief   Return Health Attribute
   * @returns Base Health Value 
  */
  int get_baseHealth();

  /*!
   * @brief   Return Combat State 
   * @returns Current Combat State of the character.
  */
  CombatState get_combatstate();

  int get_defense();

  int get_flux();

  int get_health();

  /*!
   * @brief   Return Health State
   * @returns Current Health State of the character.
  */
  HealthState get_healthstate();

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
   * @brief   Conditional Health Check 
   * @details Confirm if Actor is not dead
   * @returns Boolean answer 
  */
  bool isAlive();

  /*!
   * @brief   Conditional Combat Check 
   * @details Confirm if Actor is currently fighting
   * @returns Boolean answer 
  */
  bool isFighting();

  /*!
   * @brief   Calculates Current Damage Output
   *          including multipliers and reducers
   * @returns Final Damage Value
  */
  int output_damage();

  /*!
   * @brief   Calculates and adjust damage received
   *          including multiplier and reducers
   * @returns Final Damage Value
  */
  int receive_damage(int);

  void set_attack(int);

  /*!
   * @brief   ReAssign Combat State
   * @param[in] state Current State of the Combat AI 
  */
  void set_combatstate(CombatState);

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

  void set_defense(int);

  /*!
   * @brief   ReAssign Actor Flux Value
   * @details Set Flux Attribute 
   * @param[in] flux - New Flux Value
  */
  void set_flux(int);

  void set_health(int);

  /*!
   * @brief   ReAssign Health State
  */
  void set_healthstate(HealthState);

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
   * @brief   Helper Hook used in CLI Help System
  */
  void _help();

  /*!
   * @brief   Default Deconstructor 
  */
  ~Actor();
};

#endif // ACTOR_H //
