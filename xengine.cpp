#include "xengine.h"

int main(int argc, char const *argv[]) {
	BalanceController* bc = BalanceController::GetInstance(atoi(argv[1]));
	StageManager* sm = StageManager::GetInstance("Jugo");
	ConfigManager* cm = ConfigManager::GetInstance();

	bc->display_state();
	printf("Hello, my name is %s.\n", sm->get_name().c_str());
    return 0;
}
