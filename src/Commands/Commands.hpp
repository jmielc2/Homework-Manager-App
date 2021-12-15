#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "../core.hpp"

/*
setup():
*/
extern std::set<Class> setup();

/*
printCommands():
*/
extern void printCommands();

/*
printCommandOptions():
*/
extern void printCommandOptions();

/*
printUsage():
*/
extern void printUsage();

/*
printGeneralUsage():
*/
extern void printGeneralUsage();

/*
parseCommand():
*/
extern bool parseCommand(int argc, char **argv, flagNames &options);

#endif