#ifndef HELPITEM_H
#define HELPITEM_H

#include "basehelp.h"

class HelpItem : public BaseHelp {
protected:
private:
  Item* _item;
public:
  HelpItem();
  ~HelpItem();
};

#endif // HELPITEM_H //