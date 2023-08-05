#include "player.h"

/**
 * Default Constructor
*/
Player::Player(int level, int power, int block) :
    level(level), power(power), block(block) {
    sprintf(buf, "Level %d Player initiated.", level);
    log = Logger::GetInstance();
    log->named_log(__FILE__, buf);
}

/**
 * Helper Hook used in CLI Help System
*/
void Player::_help() {}

/**
 * Default Deconstructor
*/
Player::~Player() {}