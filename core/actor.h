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

class Actor {
protected:
  ConfigManager* cnf;       //!< ConfigManager Instantiation
  CombatState aiState;      //!< Current AI CombatState
  HealthState condition;    //!< Current Health State

  std::string name;         //!< Name of Actor
  int id;                   //!< ID of Actor
  int baseAttack;           //!< Attack Damage (@override)
  int baseDefense;          //!< Defense Value (@override)
  int baseHealth;           //!< Health Value (@override)
  int baseFlux;             //!< Flux Value (@override)

private:
  char buf[128];            //!< Buffer Value for Logger outputs

public:
  //! Constructors
  Actor();
  Actor(std::string);

  //! Status Checks
  bool isFighting();
  bool isAlive();

  //! Getters
  int get_attack();
  int get_defense();
  int get_flux();
  int get_health();
  int get_id();
  std::string get_name();
  
  //! Setters
  void set_flux(int);
  void set_id(int);
  void set_name(std::string);

  //! Combat States
  CombatState get_combatstate();
  void set_combatstate(CombatState);
  void set_combat_idle();
  void set_combat_patrol();
  void set_combat_fight();
  void set_combat_flee();
  void set_combat_follow();

  //! Health States
  HealthState get_healthstate();
  void set_healthstate(HealthState);
  void set_health_healthy();
  void set_health_hurting();
  void set_health_critical();
  void set_health_sick();
  void set_health_dead();

  //! Deconstructor
  ~Actor();
};

#endif // ACTOR_H //
