#ifndef APP_HPP
#define APP_HPP 1

#include "core.hpp"
#include "Commands/Show.hpp"
#include "Commands/Add.hpp"
#include "Commands/Remove.hpp"

namespace app {
    extern std::map<std::string, gen::classData> setupApp();

    extern bool parseCommand(int argc, char** argv, gen::flagNames &options);

    extern void saveClassData(std::map<std::string, gen::classData> &myClasses, const fs::path &dataFilePath);

    extern void runApp (gen::flagNames &options, std::map<std::string, gen::classData> &myClasses);
};

#endif