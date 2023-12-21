#ifndef HELPSTAGE_H
#define HELPSTAGE_H

#include "basehelp.h"

class HelpStage : public BaseHelp {
protected:
private:
  StageManager* _stage;
public:
  HelpStage();
  ~HelpStage();
};

#endif // HELPSTAGE_H //