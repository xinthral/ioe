#include "xengine.h"

// Extern Variable Declaration
std::string _CNF_ = "docs/engine.ini";

int main(int argc, char const *argv[]) {
	ConfigManager* cm = ConfigManager::GetInstance();
	BalanceController* bc = BalanceController::GetInstance(atoi(argv[1]));
	StageManager* sm = StageManager::GetInstance("Jugo");

	// bc->display_state();
	printf("Hello, my name is %s.\n", sm->get_name().c_str());
    return 0;
}
