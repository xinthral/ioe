#include "engine.h"

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
	ConfigManager* cnf = ConfigManager::GetInstance();
	BalanceController* bal = BalanceController::GetInstance();
	Logger* log = Logger::GetInstance();
	StageManager* mgr = StageManager::GetInstance("Jugo");

	// cnf->reload_state();
	// bal->display_state();
	// log->formed_log("Hello, World!");
	std::vector<Toon*> team;
	Toon* t;
	Toon* v;
	Player p(1, 1, 1);

	for (int i = 0; i < 10; i++) {
		t = new Toon(i);
		team.push_back(t);
	}
	
	char temp[10];
	Combat* cc;
	while (team.size() > 1) {
		t = team[team.size() - 1];
		team.pop_back();
		v = team[team.size() - 1];
		team.pop_back();
		cc = new Combat(*t, *v);
		// team.push_back(cc);
	}

	cc = new Combat(p, *t);
	
    return 0;
}
