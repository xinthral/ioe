#include "utilz.h"

/**
 * Strips away the file extension 
 * @param :<chr*|__FILE__> - the file extension
 * @return :<str|filename>
*/
std::string Utilz::FileName(const char* file) {
	std::string fileName = file;
	size_t pos = fileName.find(".");
	return fileName.substr(0, pos);
}

/**
 * Truncating method to strip away file extension 
 * @param :<int|length> - Size of return string
 * @param :<chr*|__FILE__> - the file extension
 * @return :<str|filename>
*/
std::string Utilz::FileName(int length, const char* file) {
	std::string output = Utilz::FileName(file);
	return Utilz::HeadString(length, output);
}

/**
 * Formatted Timestamp for uniformity
 * @return :<str|timestamp>
*/
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

/**
 * Truncates a string from the beginning of a string
 * @param :<int|length> - Size of return string
 * @param :<str|message> - String to be truncated
 * @return :<str|trunc>
*/
std::string Utilz::HeadString(int length, std::string input) {
	std::string output = input;
	output.resize(length);
	return output;
}

/**
 * Truncates a string from the ending of a string
 * @param :<int|length> - Size of return string
 * @param :<str|message> - String to be truncated
 * @return :<str|trunc>
*/
std::string Utilz::TailString(int length, std::string input) {
	std::string output;
	size_t l = input.size() - length;
	for (size_t i = l; i < input.size(); i++) { output += input[i]; }
	return output;
}

/**
 * Removes whitespace from string
 * @param :<str|message> - String to be crunched
*/
void Utilz::Strip(std::string& input) {
	std::string::iterator pos = std::remove(input.begin(), input.end(), ' ');
	input.erase(pos, input.end());
}