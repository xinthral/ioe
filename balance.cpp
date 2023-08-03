/* Like in life, so to in games do we need balance
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
	log->named_log(__FILE__, ("BalanceContoller Loaded!"));

	// Load Configurations
	cm = ConfigManager::GetInstance();
	log = Logger::GetInstance();
	int difficulty = cm->get_difficulty();

	if (difficulty < 0 || difficulty > 5) {
		printf("level %d. Please Enter a value between 0 and 5\n", difficulty);
		printf("Error: Instatiating Balance Controller with invalid difficulty\n");
		exit(-1);
	}

	switch(difficulty) {
		case 1: { DIF = Vesy; BAS = LEVELS[1]; break; }
		case 2: { DIF = Easy; BAS = LEVELS[2]; break; }
		case 3: { DIF = Norm; BAS = LEVELS[3]; break; }
		case 4: { DIF = Hard; BAS = LEVELS[4]; break; } 
		case 5: { DIF = Vard; BAS = LEVELS[5]; break; } 
		default  : { BAS = LEVELS[0]; break; }
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
 * y = δ(χ/[π^π])
 * @return :<double|scalar> - Scaled value based on level
*/
double BalanceController::scalar(int level) {
	double x = level * 1.0;
	return pow(BAS, (x / pow(M_PI, M_PI)));
}

/**
 * Display the current state of the base game attributes
*/
void BalanceController::display_state() {
	double scl = 0.0;
	char tmsg[2048];
	sprintf(tmsg, "%*s :: %*s :: %*s", 4, "Lvl", SPN, "Attack", SPN, "Defense");
	log->formed_log(tmsg);
	for (int i = 0; i < MAXLVL; i++) {
		scl = this->scalar(i);
		sprintf(tmsg, "%*d :: %*.4f :: %*.4f", 4, i, SPN, (scl*ATK), SPN, (scl*DEF));
		log->formed_log(tmsg);
	}
}

double BalanceController::get_base() { return BAS; }

Hardness BalanceController::get_difficulty() { return this->DIF; }

BalanceController::~BalanceController() {}