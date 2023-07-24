/* Like in life, so to in games do we need balance */
#include "xbalance.h"

BalanceController::BalanceController() {}

double BalanceController::scalar(double base, int level) {
	/* Scalar Function 
	 * y = C^(x/(pi^pi))
	 */
	double x = level * 1.0;
	return pow(base, (x / pow(M_PI, M_PI)));
}

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

	BalanceController bc;
	Hardness diff = Norm;
	int lvl = atoi(argv[1]);
	if (lvl == 1) { diff = Easy; }
	if (lvl == 2) { diff = Norm; }
	if (lvl == 3) { diff = Hard; }
	double base = 0.0;

	switch(diff) {
		case Easy: { base = levels[1]; break; }
		case Norm: { base = levels[2]; break; }
		case Hard: { base = levels[3]; break; } 
		default  : { base = levels[0]; break; }
	}

	int ATK = 25;
	int DEF = 30;
	int SPN = 8;

	printf(" %*s :: %*s :: %*s \n", 4, "Lvl", SPN, "Attack", SPN, "Defense");
	for(int x = 20; x < 40; x++) {
		double scalar = bc.scalar(base, x);
		printf(" %*d :: %0.5f :: %0.5f\n", 4, x, scalar*ATK, scalar*DEF);
	}

	return 0;
}
