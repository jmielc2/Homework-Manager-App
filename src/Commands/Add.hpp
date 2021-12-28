#ifndef ADD_HPP
#define ADD_HPP 1

#include "../core.hpp"

namespace add {
    extern void addClass(const gen::flagNames &options, std::map<std::string, gen::classData> &myClasses);

    extern void addAssignment(const gen::flagNames &options, std::map<std::string, gen::classData> &myClasses);

    extern void runAdd(gen::flagNames &options, std::map<std::string, gen::classData> &myClasses);
};

#endif