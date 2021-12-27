#ifndef CORE_HPP
#define CORE_HPP 1

#define VERSION_P1 1.00
#define VERSION_P2 0

// Standard Libraries
#include <iostream>
#include <fstream>
#include <filesystem>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

// Github Libraries
#include "Include/json.hpp"

namespace fs = std::filesystem;
using json = nlohmann::json;

// Self-made Classes & Namespaces
#include "Components/Assignment.hpp"
#include "General/General.hpp"
#include "General/Commands.hpp"

namespace gen {
    const fs::path dataFolderPath("./data");
    const fs::path dataFilePath("./data/class-data.json");
    const fs::path testFilePath("./data/test.json");
    enum {ADD, REMOVE, SHOW, VERSION, HELP, NONE};
};

#endif