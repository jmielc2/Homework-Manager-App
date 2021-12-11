#ifndef CORE_HPP
#define CORE_HPP

#define VERSION_P1 1.00
#define VERSION_P2 0

#include <iostream>
#include <iomanip>
#include <string>
#include <typeinfo>  // DELETE

#include <set>
#include <map>
#include <vector>

using namespace std;

enum COMMANDS {ADD, REMOVE, SHOW, VERSION, HELP, NONE};

struct flagNames {
    int cmdType;
    string className;
    string assignment;
};

#include "Assignments/Assignment.hpp"
#include "Classes/Class.hpp"

#endif