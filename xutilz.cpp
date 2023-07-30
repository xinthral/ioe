#include "xutilz.h"

std::string Utilz::FileName(const char* file) {
	/* Returns a string containing the
	 * name of the given file 
	 */
	std::string fileName = file;
	size_t pos = fileName.find(".");
	return fileName.substr(0, pos);
}

std::string Utilz::TimeStamp() {
	std::time_t time = std::time({});
	char output[std::size("ddd mmm dd hh:mm:ss")];
	std::string fmtString = "%a %b %d %T";
	std::strftime(
		std::data(output), 
		std::size(output), 
		fmtString.c_str(), 
		std::localtime(&time)
	);
	return output;
}

void Utilz::Strip(std::string& input) {
	std::string::iterator pos = std::remove(input.begin(), input.end(), ' ');
	input.erase(pos, input.end());
}