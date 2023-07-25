/* Like in life, so to in games do we need balance */
#include "xbalance.h"

BalanceController::BalanceController(Hardness difficulty) : DIF(difficulty)  {
	switch(DIF) {
		case Vesy: { base = LEVELS[1]; break; }
		case Easy: { base = LEVELS[2]; break; }
		case Norm: { base = LEVELS[3]; break; }
		case Hard: { base = LEVELS[4]; break; } 
		case Vard: { base = LEVELS[5]; break; } 
		default  : { base = LEVELS[0]; break; }
	}
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

BalanceController::~BalanceController() {}

void print_help() {
	printf("Usage: ./run.exe <int|difficulty>\n");
	printf("  difficulty: Range 1-3 [Easy-Hard]\n");
}

int main(int argc, char const *argv[]) {
	if (argc < 2) {
		print_help();
		return -1;
	}

	Hardness diff = Norm;
	int lvl = atoi(argv[1]);
	if (lvl == 1) { diff = Vesy; }
	if (lvl == 2) { diff = Easy; }
	if (lvl == 3) { diff = Norm; }
	if (lvl == 4) { diff = Hard; }
	if (lvl == 5) { diff = Vard; }
	BalanceController bc(diff);

	bc.display_state();

	return 0;
}
