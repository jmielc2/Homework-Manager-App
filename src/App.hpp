#ifndef APP_HPP
#define APP_HPP 1

#include "core.hpp"

extern std::set<Class> setupApp();

extern bool parseCommand(int argc, char** argv, flagNames &options);

extern void runApp (const flagNames options, std::set<Class> &myClasses);

#endif