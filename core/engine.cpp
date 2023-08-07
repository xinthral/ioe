/*! 
 * @mainpage 	Engine Main Index
 * @brief		Engine go vroom.
*/
#include "engine.h"

//! Extern Variable Declaration
std::string _CNF_ = "docs/engine.ini";

/*!
 * @brief	Helper Function to display help
*/
void print_helper() {
	//! Load Logger Object
	Logger* log = Logger::GetInstance();

	//! Get File Name
	std::string fileName = Utilz::FileName(__FILE__);

	//! Display Help 
	char buf[32];
	sprintf(buf, "Usage: ./%s <bool|debug>:\n", fileName.c_str()); 
	log->raw_log(buf);
	log->raw_log("\tParam: <bool|debug> - Debugging Flag\n");
	exit(-1);
}

/*!
 * @brief	Module Entry Point
*/
int main(int argc, char const *argv[]) {
	if (argc < 2) { print_helper(); }

	//! Establish Controlers
	ConfigManager* 		cnf = ConfigManager::GetInstance();
	BalanceController* 	bal = BalanceController::GetInstance();
	Logger* 			log = Logger::GetInstance();
	StageManager* 		mgr = StageManager::GetInstance("Jugo");

	//! Declare Variables
	std::vector<Toon*> team;
	Toon* t;
	Toon* v;
	Player* p;
	Combat* cc;

	//! FIXME Implement Interactive Shell
	/* ********************************** */

	std::string names[5] = {"Kevin", "Connie", "Shawna", "Trever", "Jesse"};
	std::string name;

	for (int i = 0; i < 10; i++) {
		name = names[i%5];
		t = new Toon(i, name);
		team.push_back(t);
	}
	
	char temp[10];
	p = new Player(1, 1, 1);
	while (team.size() > 1) {
		t = team[team.size() - 1];
		team.pop_back();
		v = team[team.size() - 1];
		team.pop_back();
		cc = new Combat(*t, *v);
		cc->begin_combat();
	}

	cc = new Combat(*p, *t);
	cc->begin_combat();
	
    return 0;
}
