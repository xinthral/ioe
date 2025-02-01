#include "balance.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

//! Singleton Instance
BalanceController* BalanceController::_singleton = NULL;
//! Lock Mutex 
std::mutex BalanceController::_mutex;

/*!
 * @brief   Default Constructor 
*/
BalanceController::BalanceController() {
  //! Load Configurations Objects
  cnf  = ConfigManager::GetInstance();
  log  = Logger::GetInstance();
  base = cnf->get_base();
  log->named_log(__FILENAME__, "BalanceController Loaded!");

  //! Conditional Check: Confirm Range
  int difficulty = cnf->get_difficulty();
  if (difficulty < 0 || difficulty > 5) {
    sprintf(buf, "level %d. Please Enter a value between 0 and 5\n", difficulty);
    log->timed_log(buf);
    log->raw_log(": Instatiating Balance Controller with invalid difficulty\n");
    exit(-1);
  }

  //! Conditional: Difficulty Curve
  switch(difficulty) {
    case 1: { DIF = Vasy; base = LEVELS[1]; break; }
    case 2: { DIF = Easy; base = LEVELS[2]; break; }
    case 3: { DIF = Norm; base = LEVELS[3]; break; }
    case 4: { DIF = Hard; base = LEVELS[4]; break; } 
    case 5: { DIF = Vard; base = LEVELS[5]; break; } 
    default  : { base = LEVELS[0]; break; }
  }
}

/*!
 * @todo    Singleton Constructor 
*/
BalanceController* BalanceController::GetInstance() {
  //! Acquire Instance Mutex
  std::lock_guard<std::mutex> lock(_mutex);
  //! If singleton already exists, return instance
  if (_singleton == NULL) { _singleton = new BalanceController(); }
  return _singleton;
}

/*!
 * @todo    Scaled value based on level
 * @note    y = δ^(χ/[π^π])
*/
double BalanceController::scalar(int level) {
  double x = level * 1.0;
  return pow(base, (x / pow(M_PI, M_PI)));
}

/*!
 * @todo    Display the current state of the base game attributes
*/
void BalanceController::display_state() {
  double scl = 0.0;
  int spn = this->span;
  int attack = this->atk;
  int defense = this->def;
  
  sprintf(buf, "%*s :: %*s :: %*s", 3, "Lvl", spn, "Attack", spn, "Defense");
  log->named_log(__FILENAME__, buf);
  for (int i = 0; i < MAXLVL; i++) {
    scl = this->scalar(i);
    sprintf(buf, "%*d :: %*.2f :: %*.2f", 3, i+1, spn, (scl*attack), spn, (scl*defense));
    log->named_log(__FILENAME__, buf);
  }
}

/*!
 * @todo    Helper Function: Base Scalar Value 
*/
double BalanceController::get_base() { return base; }

/*!
 * @todo    Helper Function: Game Difficulty 
*/
Hardness BalanceController::get_difficulty() { return this->DIF; }

/*!
 * @todo    Converts the difficulty to a string 
*/
std::string BalanceController::get_difficulty_str() {
  switch(this->get_difficulty()) {
    case Vasy:    return "Vasy";
    case Easy:    return "Easy";
    case Norm:    return "Norm";
    case Hard:    return "Hard";
    case Vard:    return "Vard";
    default:    return "Invalid";
  }
}

/*!
 * @brief   Helper Hook used in CLI Help System
*/
void BalanceController::_help() { 
  std::string helpline = "\nBalanceController Helpline!"
    "\n\nThis is a singleton object (https://www.geeksforgeeks.org/implementation-of-singleton-class-in-cpp/)"
    "\n\n\tThe BalanceController is meant to be the module that rules them all. By forcing an interjection algorithm"
    "\nI am introducing a slow down in calls but adding an immense amount of control over equivelancy test. Pretty"
    "\nproud of this over-engineered piece of code, because the customization should allow for rapid changes for live"
    "\ntweaking, consistant changes across base values, and if all goes right will allow easy integration for a learning"
    "\nmodel to automate performance tweaking."
    "\n"
    "\nListed below is the scaling model:"
    "\n";
  this->log->named_log(__FILENAME__, helpline);
  this->display_state();
}

/*!
 * @todo    Default Deconstructor
*/
BalanceController::~BalanceController() { }
