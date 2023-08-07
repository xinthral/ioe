#include "player.h"

/*!
 * @brief   Default Constructor
 * @details If no values are provided, then default
 *          values are initialized as (1, 1, 1).
*/
Player::Player() : Player(1, 1, 1) {}

/*!
 * @overload
 * @brief   Constructor Initializor
 * @param[in] level - Level of the Player
 * @param[in] power - Cummulative Power of Player
 * @param[in] block - Defense of the Player
*/
Player::Player(int level, int power, int block) :
    level(level), power(power), block(block) {
    sprintf(buf, "Level %d Player initiated.", level);
    log = Logger::GetInstance();
    log->named_log(__FILE__, buf);
}

/*!
 * @brief   Helper Hook used in CLI Help System
*/
void Player::_help() {}

/*!
 * @brief   Default Deconstructor
*/
Player::~Player() {}