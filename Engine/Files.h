#pragma once

#include <fstream>
#include <sstream>
#include <string>

#define RESOURCE(path) "res/" path

std::string readFileContextsToString(std::string path); 