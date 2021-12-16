#ifndef CORE_HPP
#define CORE_HPP

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
#include "nlohmann/json.hpp"

// using namespace std;
namespace fs = std::filesystem;

enum COMMANDS {ADD, REMOVE, SHOW, VERSION, HELP, NONE};

struct flagNames {
    int cmdType;
    std::string className;
    std::string assignment;
};

#include "Assignments/Assignment.hpp"
#include "Classes/Class.hpp"

#endif