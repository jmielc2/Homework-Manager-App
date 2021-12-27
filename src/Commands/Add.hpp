#include "../core.hpp"

namespace add {
    extern void addClass(const gen::flagNames &options, std::map<std::string, gen::classData> &myClasses);

    extern void addAssignment(const gen::flagNames &options, std::map<std::string, gen::classData> &myClasses);

    extern void runAdd(gen::flagNames &options, std::map<std::string, gen::classData> &myClasses);
};