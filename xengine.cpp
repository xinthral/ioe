#include "xengine.h"

// Extern Variable Declaration
std::string _CNF_ = "docs/engine.ini";

void print_helper() {
	printf("Requires Hardness Level [1-5].\n");
	exit(-1);
}

int main(int argc, char const *argv[]) {
	if (argc < 2) { print_helper(); }
	ConfigManager* cm = ConfigManager::GetInstance();
	BalanceController* bc = BalanceController::GetInstance(atoi(argv[1]));
	StageManager* sm = StageManager::GetInstance("Jugo");

	// bc->display_state();
	// cm->display_state();
    return 0;
}
