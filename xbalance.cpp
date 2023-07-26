/* Like in life, so to in games do we need balance */
#include "xbalance.h"

// Singleton Instance
BalanceController* BalanceController::_singleton = NULL;
std::mutex BalanceController::_mutex;

BalanceController::BalanceController(int difficulty) {
	if (difficulty < 0 || difficulty > 5) {
		printf("level %d. Please Enter a value between 0 and 5\n", difficulty);
		printf("Error: Instatiating Balance Controller with invalid difficulty\n");
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

BalanceController *BalanceController::GetInstance(int difficulty) {
    // Acquire Instance Mutex
    std::lock_guard<std::mutex> lock(_mutex);
    // If singleton already exists, return instance
    if (_singleton == NULL) { _singleton = new BalanceController(difficulty); }
    return _singleton;
}

double BalanceController::scalar(int level) {
	/* Scalar Function 
	 * The crux of the games balance scaling
	 * y = C^(x/(pi^pi))
	 */
	double x = level * 1.0;
	return pow(base, (x / pow(M_PI, M_PI)));
}

void BalanceController::display_state() {
	double scl = 0.0;
	printf("%*s :: %*s :: %*s \n", 4, "Lvl", SPN, "Attack", SPN, "Defense");
	for (int i = 0; i < MAXLVL; i++) {
		scl = this->scalar(i);
		printf("%*d :: %*.4f :: %*.4f\n", 4, i, SPN, scl*ATK, SPN, scl*DEF);
	}
}

double BalanceController::get_base() { return this->base; }

Hardness BalanceController::get_difficulty() { return this->DIF; }

void BalanceController::_help() {
	// Establish a helper function
}

BalanceController::~BalanceController() {}