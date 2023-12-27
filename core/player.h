#ifndef PLAYER_H
#define PLAYER_H

#include <chrono>
#include <ctime>
#include "actor.h"
#include "logger.h"

class Player : public Actor {
private:
  Logger* log;                          //!< Log Manager Instantiation
  char buf[256];                        //!< Buffer Value for Logger outputs
  int bhealth  = Actor::baseHealth;     //!< Base Value inherited from Actor
  int bdefense = Actor::baseDefense;    //!< Base Value inherited from Actor
  int bflux    = Actor::baseFlux;       //!< Base Value inherited from Actor
  int block    = 1;                     //!< Block Value Adds to Damage Mitigation
  int health   = 1;                     //!< Health Value is the Damage Allowed Before Death
  int power    = 1;                     //!< Power Value Amplifies Abilies Used
  int level    = 1;                     //!< Level Value Associates Progression 
public:
  Player();
  Player(int, int, int);
  Player(std::string, int, int, int);
  void _help();
  ~Player();
};

#endif // PLAYER_H //
