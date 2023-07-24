/*

*/
#include "xbalance.h"

void print_help() {
	printf("Usage: ./run.exe <int|difficulty>\n");
	printf("  difficulty: Range 1-3 [Easy-Hard]\n");
}

double balance_value(double base, int level) {
	// y = C^(x/(pi^pi))
	double x = level * 1.0;
	return pow(base, (x / pow(M_PI, M_PI)));
}

int main(int argc, char const *argv[]) {
	if (argc < 2) {
		print_help();
		return -1;
	}

	enum Hardness { Easy, Norm, Hard };
	const double levels[] = {1.3, 1.6, 1.9, 2.2};
	int lvl = atoi(argv[1]);
	Hardness diff;
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
		double scalar = balance_value(base, x);
		printf(" %*d :: %0.5f :: %0.5f\n", 4, x, scalar*ATK, scalar*DEF);
	}

	return 0;
}
