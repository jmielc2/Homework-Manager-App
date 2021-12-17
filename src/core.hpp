#ifndef CORE_HPP
#define CORE_HPP 1

#define VERSION_P1 1.00
#define VERSION_P2 0

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <filesystem>
#include <iomanip>
#include <string>
#include <set>
#include <map>
#include <vector>
#include "include/json.hpp"

namespace fs = std::filesystem;
using json = nlohmann::json;

enum COMMANDS {ADD, REMOVE, SHOW, VERSION, HELP, NONE};

struct flagNames {
    int cmdType;
    std::string className;
    std::string assignment;
};

#include "Assignments/Assignment.hpp"
#include "Classes/Class.hpp"

#endif