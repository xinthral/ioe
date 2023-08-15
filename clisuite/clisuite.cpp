/*! 
 * @class 	CLISuite clisuite.cpp clisuite.h
 * @brief	Command Line Interface for Engine.
*/
#include "clisuite.h"

//! Extern Variable Declaration
std::string _CNF_ = "docs/engine.ini";

/*!
 * @brief	Helper Function to parse input
*/
bool parse_input(std::string input, std::string criteria) {
	//! Establish Variables 
	size_t found = input.find(criteria);
	if (found != std::string::npos) { return false; }
	return true;
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
	char buf[64];
	sprintf(buf, "\nUsage: ./%s <bool|debug>", fileName.c_str()); 
	log->raw_log(buf);
	log->raw_log("Param:\n\t<bool|debug> - Debugging Flag\n");
	exit(-1);
}

// /*!
//  * @brief	Module Entry Point
// */
int main(int argc, char const *argv[]) {
	//! Conditional Check
	if (argc < 2) { print_helper(); }

	std::string input(argv[1]);
	char _input = input[0];
	switch (_input) {
		case '0': return 0;
		case '1':
		default: 
			break;
	}

	//! Declare Variables
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

    return 0;
}
