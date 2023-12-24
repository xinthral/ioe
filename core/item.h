#ifndef ITEM_H
#define ITEM_H 

#include "logger.h"

class Item {
protected:
private:
  Logger*             log;
  char                buf[1024];

public:
  Item();
  void _help();
  ~Item();
};

#endif  // ITEM_H //
