#include "../core.hpp"

#ifndef COMMANDS_HPP
#define COMMANDS_HPP

enum COMMANDS {ADD, REMOVE, SHOW, VERSION, HELP, NONE};

/*
setup():
*/
extern void setup();

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
extern pair<int, vector<string>> parseCommand(int argc, char **argv);

#endif