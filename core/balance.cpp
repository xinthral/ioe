/*! 
 * @class   BalanceController balance.h balance.cpp
 * @brief   BalanceController handles balancing engine mechanics
 *          in a consistant, scalable and easily changeable way.
 * @details Like in life, so to in games do we need balance
 *          In order to maintain consistency in a game, you 
 *          need a universal scale in which you operate from. 
 *          This module creates a mathematical scalar curve 
 *          that all statistics can be derived from. 
 * @note  \f$y = δ\f$^[\f$x/(π^π)\f$]
 * @note  \f$δ :=\f$ Constant based on game difficulty
 * @note  \f$x :=\f$ Character's Current Level
 * @note  \f$π :=\f$ Pi....mmmm Pi
 * @note  \f$y :=\f$ The scalar value
*/
#include "balance.h"

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
  log->named_log(__FILE__, "BalanceContoller Loaded!");

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
 * @brief   Singleton Constructor 
*/
BalanceController *BalanceController::GetInstance() {
    //! Acquire Instance Mutex
    std::lock_guard<std::mutex> lock(_mutex);
    //! If singleton already exists, return instance
    if (_singleton == NULL) { _singleton = new BalanceController(); }
    return _singleton;
}

/*!
 * @brief  Scales The Universe
 * @details  Scalar Function to keep the entire universe 
 *      in balance.
 * @note  y = δ^(χ/[π^π])
 * @return   Scaled value based on level
*/
double BalanceController::scalar(int level) {
  double x = level * 1.0;
  return pow(base, (x / pow(M_PI, M_PI)));
}

/*!
 * @brief   Log Game State
 * @details Display the current state of the base game attributes
*/
void BalanceController::display_state() {
  double scl = 0.0;
  int spn = this->span;
  int attack = this->atk;
  int defense = this->def;
  
  sprintf(buf, "%*s :: %*s :: %*s", 4, "Lvl", spn, "Attack", spn, "Defense");
  log->named_log(__FILE__, buf);
  for (int i = 0; i < MAXLVL; i++) {
    scl = this->scalar(i);
    sprintf(buf, "%*d :: %*.4f :: %*.4f", 4, i, spn, (scl*attack), spn, (scl*defense));
    log->named_log(__FILE__, buf);
  }
}

/*!
 * @brief  Helper Function: Base Scalar Value 
 * @return   Returns Base Scalar Value
*/
double BalanceController::get_base() { return base; }

/*!
 * @brief   Helper Function: Game Difficulty 
 * @return   Returns difficulty level
*/
Hardness BalanceController::get_difficulty() { return this->DIF; }

/*!
 * @brief  Converts the difficulty to a string 
 * @return  Difficulty as a string 
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
void BalanceController::_help() { }

/*!
 * @brief   Default Deconstructor
*/
BalanceController::~BalanceController() { }
