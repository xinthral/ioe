#ifndef XENGINE_H
#define XENGINE_H

// #include <windows.h> Both needed for sleep()
// #include <unistd.h>  Both needed for sleep()

#include <stdio.h>
#include <string>
#include <vector>
#include "xactor.h"
#include "xbalance.h"
#include "xbattle.h"
#include "xcombat.h"
#include "xconfig.h"
#include "xlogger.h"
#include "xplayer.h"
#include "xstage.h"
#include "xtoon.h"

const double LEVELS[] = {1, 3, 5, 8, 13, 21};
const int MAXLVL = 80;
double    BAS = 5.0;
const int SPN = 8;
const int ATK = 24;
const int DEF = 32;
const int SKP = 1;

#endif // XENGINE_H //