#include "xutilz.h"

std::string Utilz::FileName(const char* file) {
	/* Returns a string containing the
	 * name of the given file 
	 */
	std::string fileName = file;
	size_t pos = fileName.find(".");
	return fileName.substr(0, pos);
}

std::string Utilz::FileName(int length, const char* file) {
	std::string output = Utilz::FileName(file);
	return Utilz::HeadString(length, output);
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

std::string Utilz::HeadString(int length, std::string input) {
	std::string output = input;
	output.resize(length);
	return output;
}
std::string Utilz::TailString(int length, std::string input) {
	std::string output;
	size_t l = input.size() - length;
	for (size_t i = l; i < input.size(); i++) { output += input[i]; }
	return output;
}

void Utilz::Strip(std::string& input) {
	std::string::iterator pos = std::remove(input.begin(), input.end(), ' ');
	input.erase(pos, input.end());
}