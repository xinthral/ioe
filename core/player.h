#ifndef PLAYER_H
#define PLAYER_H

#include "actor.h"
#include "logger.h"

class Player : public Actor {
private:
  Logger* log;        //!< Log Manager Instantiation
  char buf[128];      //!< Buffer Value for Logger outputs
  int block   = 1;    //!< Block Value Adds to Damage Mitigation
  int health  = 1;    //!< Health Value is the Damage Allowed Before Death
  int level   = 1;    //!< Level Value Associates Progression 
  int power   = 1;    //!< Power Value Amplifies Abilies Used
public:
  Player();
  Player(int, int, int);
  Player(std::string, int, int, int);
  void _help();
  ~Player();
};

#endif // PLAYER_H //
