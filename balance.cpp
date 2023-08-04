/**
 * Like in life, so to in games do we need balance
 * In order to maintain consistency in a game, you need a universal scale
 * in which you operate from. This module creates a mathematical scalar
 * curve that all statistics can be derived from. y = c^[x/(π^π)]
 */
#include "balance.h"

// Singleton Instance
BalanceController* BalanceController::_singleton = NULL;
std::mutex BalanceController::_mutex;

/**
 *  Protected Constructor 
*/
BalanceController::BalanceController() {
	// Load Logger
	log = Logger::GetInstance();
	log->named_log(__FILE__, "BalanceContoller Loaded!");

	// Load Configurations
	cnf = ConfigManager::GetInstance();
	log = Logger::GetInstance();
	base = cnf->get_base();
	int difficulty = cnf->get_difficulty();

	if (difficulty < 0 || difficulty > 5) {
		sprintf(buf, "level %d. Please Enter a value between 0 and 5\n", difficulty);
		log->formed_log(buf);
		log->raw_log(": Instatiating Balance Controller with invalid difficulty\n");
		exit(-1);
	}

	switch(difficulty) {
		case 1: { DIF = Vesy; base = LEVELS[1]; break; }
		case 2: { DIF = Easy; base = LEVELS[2]; break; }
		case 3: { DIF = Norm; base = LEVELS[3]; break; }
		case 4: { DIF = Hard; base = LEVELS[4]; break; } 
		case 5: { DIF = Vard; base = LEVELS[5]; break; } 
		default  : { base = LEVELS[0]; break; }
	}
}

/**
 *  Singleton Constructor 
*/
BalanceController *BalanceController::GetInstance() {
    // Acquire Instance Mutex
    std::lock_guard<std::mutex> lock(_mutex);
    // If singleton already exists, return instance
    if (_singleton == NULL) { _singleton = new BalanceController(); }
    return _singleton;
}

/**
 * Scalar Function to keep the entire universe in balance
 * y = δ^(χ/[π^π])
 * @return Scaled value based on level
*/
double BalanceController::scalar(int level) {
	double x = level * 1.0;
	return pow(base, (x / pow(M_PI, M_PI)));
}

/**
 * Display the current state of the base game attributes
*/
void BalanceController::display_state() {
	double scl = 0.0;
	char tmsg[2048];
	int spn = this->span;
	int attack = this->atk;
	int defense = this->def;
	
	sprintf(tmsg, "%*s :: %*s :: %*s", 4, "Lvl", spn, "Attack", spn, "Defense");
	log->named_log(__FILE__, tmsg);
	for (int i = 0; i < MAXLVL; i++) {
		scl = this->scalar(i);
		sprintf(tmsg, "%*d :: %*.4f :: %*.4f", 4, i, spn, (scl*attack), spn, (scl*defense));
		log->named_log(__FILE__, tmsg);
	}
}

/**
 * Helper Function: Base Scalar Value 
 * @return Returns Base Scalar Value
*/
double BalanceController::get_base() { return base; }

/**
 * Helper Function: Game Difficulty 
 * @return Returns difficulty level
*/
Hardness BalanceController::get_difficulty() { return this->DIF; }

/**
 * Helper Hook used in CLI Help System
*/
void BalanceController::_help() { }

/**
 * Default Deconstructor
*/
BalanceController::~BalanceController() {}