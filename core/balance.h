#ifndef BALANCE_H
#define BALANCE_H
#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <stdio.h>
#include "config.h"
#include "logger.h"

enum Hardness { Vasy, Easy, Norm, Hard, Vard };

const double LEVELS[] = {1, 3, 5, 8, 13, 21};

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
class BalanceController {
protected:
  /*!
   * @brief   Protected Constructor 
  */
  BalanceController();

private:
  static BalanceController* _singleton; //!< Singleton Instance
  static std::mutex _mutex;             //!< Lock Mutex 
  Hardness       DIF;                   //!< Difficulty Level 
  char           buf[128];              //!< Buffer Value for Logger outputs
  ConfigManager* cnf;                   //!< ConfigManager Instantiation
  Logger*        log;                   //!< Logging Handler Instantiation
  int MAXLVL     = 80;                  //!< Maximum Level Attainable
  double base    = 5.0;                 //!< Base Variant for difficulty scaling
  int span       = 8;                   //!< Display Width
  int atk        = 24;                  //!< Default Attack Value
  int def        = 32;                  //!< Default Defense Value
  int hlt        = 100;                 //!< Default Health Value

public:
  //! Singletons should not be cloneable
  BalanceController(BalanceController&) = delete;         

  //! Singletons should not be assignable
  void operator = (const BalanceController&) = delete;    

  /*!
   * @brief   Singleton Constructor 
  */
  static BalanceController *GetInstance();

  /*!
   * @brief   Scales The Universe
   * @details Scalar Function to keep the entire universe 
   *          in balance.
   * @return  Scaled value based on level
  */
  double scalar(int);

  /*!
   * @brief   Log Game State
   * @details Display the current state of the base game attributes
  */
  void display_state();

  /*!
   * @brief   Helper Function: Base Scalar Value 
   * @return  Returns Base Scalar Value
  */
  double get_base();

  /*!
   * @brief   Helper Function: Game Difficulty 
   * @return  Returns difficulty level
  */
  Hardness get_difficulty();

  /*!
   * @brief   Converts the difficulty to a string 
   * @return  Difficulty as a string 
  */
  std::string get_difficulty_str();

  /*!
   * @brief   Helper Hook used in CLI Help System
  */
  void _help();

  /*!
   * @brief   Default Deconstructor
  */
  ~BalanceController();
};

#endif // BALANCE_H //
