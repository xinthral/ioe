#ifndef HELPPLAYER_H
#define HELPPLAYER_H

#include "basehelp.h"

class HelpPlayer : public BaseHelp {
protected:
  Player* ptest;
private:
public:
  HelpPlayer();
  ~HelpPlayer();
};

#endif // HELPPLAYER_H //
