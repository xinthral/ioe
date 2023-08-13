/*! 
 * @mainpage 	Engine Main Index
 * @brief		Engine go vroom.
*/
#include "engine.h"

//! Extern Variable Declaration
std::string _CNF_ = "docs/engine.ini";

/*!
 * @brief	Helper Function to parse input
*/
bool parse_input(std::string criteria, std::string input) {
	//! Establish Variables 
	size_t found = input.find(criteria);
	if (found != std::string::npos) { return true; }
	return false;
}

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
	//! Conditional Check
	if (argc < 2) { print_helper(); }

	//! Establish Controllers
	ConfigManager* 		cnf = ConfigManager::GetInstance();
	BalanceController* 	bal = BalanceController::GetInstance();
	Logger* 			log = Logger::GetInstance();
	StageManager* 		mgr = StageManager::GetInstance("Jugo");

	//! Declare Variables
	Battle*		bat; 
	Combat* 	cc;
	Player* 	p;
	Toon* 		t;
	Toon* 		v;
	std::vector<Toon*> team;
	std::string prompt = "> ";
	std::string rawInput;
	size_t		found;
	bool		vshContinue = true;

	//! Interactive Shell
	/* ********************************** */
	do {
		printf("%s", prompt.c_str());		//! Display Message Prompt
		std::cin >> rawInput;				//! Get User Input
		//! Conditional to end Shell
		vshContinue = parse_input(rawInput, "exit");
	} while (vshContinue == true);
	/* ********************************** */

	std::string names[5] = {
		"Kevin", 
		"Connie", 
		"Shawna", 
		"Trever", 
		"Jesse"
	};
	std::string name;

	p = new Player("Jesse", 1, 1, 1);
	mgr->casting_call(10, team);
	bat = new Battle(10, p, team);

    return 0;
}
