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
  int baseAttack;           //!< Attack Damage (@override)
  int baseDefense;          //!< Defense Value (@override)
  int baseHealth;           //!< Health Value (@override)
  int baseFlux;             //!< Flux Value (@override)
  char buf[128];            //!< Buffer Value for Logger outputs

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
   * @return  Boolean answer 
  */
  bool isFighting();

  /*!
   * @brief   Conditional Health Check 
   * @details Confirm if Actor is not dead
   * @return  Boolean answer 
  */
  bool isAlive();

  /*!
   * @brief   Return Attack Attribute
   * @return  Base Attack Value 
  */
  int get_attack();

  /*!
   * @brief   Return Defense Attribute
   * @return  Base Defense Value 
  */
  int get_defense();

  /*!
   * @brief   Return Flux Attribute
   * @return  Flux Value
  */
  int get_flux();

  /*!
   * @brief   Return Health Attribute
   * @return  Base Health Value 
  */
  int get_health();

  /*!
   * @brief   Return ID Attribute
   * @return  Identity Reference Number
  */
  int get_id();

  /*!
   * @brief   Return Name Attribute
   * @return  Name Value 
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
   * @return  Current Combat State of the character.
  */
  CombatState get_combatstate();

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

  /*!
   * @brief   Return Health State
   * @return  Current Health State of the character.
  */
  HealthState get_healthstate();

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
   * @brief   Helper Hook used in CLI Help System
  */
  void _help();

  /*!
   * @brief   Default Deconstructor 
  */
  ~Actor();
};

#endif // ACTOR_H //
