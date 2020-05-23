#include "Files.h"

std::string readFileContextsToString(std::string path) {
	std::ifstream f(path);
	std::string contents;
	if (f) {
		std::ostringstream ss;
		ss << f.rdbuf();
		contents = ss.str();
	}
	return contents;
}