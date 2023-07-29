#include "xengine.h"

// Extern Variable Declaration
std::string _CNF_ = "docs/engine.ini";

void print_helper() {
	// Get File Name
	std::string fileName = Utilz::FileName(__FILE__);

	// Display Help Data
	printf("Usage:\n");
	printf("  ./%s <bool|debug>:\n", fileName.c_str()); 
	printf("  Param:\n");
	printf("    <bool|debug> - Debugging Flag:\n");
	exit(-1);
}

int main(int argc, char const *argv[]) {
	if (argc < 2) { print_helper(); }

	/* Establish Controlers */
	ConfigManager* cm = ConfigManager::GetInstance();
	BalanceController* bc = BalanceController::GetInstance();
	StageManager* sm = StageManager::GetInstance("Jugo");

    return 0;
}
