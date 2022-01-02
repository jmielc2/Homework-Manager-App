#ifndef REMOVE_HPP
#define REMOVE_HPP 1

#include "../core.hpp"

namespace rm {
    extern void runRemove(gen::flagNames &options, std::map<std::string, gen::classData> &myClasses);

    extern bool removeClass(const gen::flagNames &options, std::map<std::string, gen::classData> &myClasses);
    
    extern bool removeAssignment(const gen::flagNames &options, std::map<std::string, gen::classData> &myClasses);
}

#endif