#include "xutilz.h"

std::string Utilz::FileName(const char* file) {
	std::string fileName = file;
	size_t pos = fileName.find(".");
	return fileName.substr(0, pos);
}

