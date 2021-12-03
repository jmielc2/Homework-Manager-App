#include "../core.hpp"

#ifndef COMMANDS_HPP
#define COMMANDS_HPP

enum COMMANDS {ADD, REMOVE, SHOW, VERSION, HELP, NONE};

extern void setup();

extern void printCommands();

extern void printCommandOptions();

extern void printGeneralUsage();

extern pair<string, vector<string>> parseCommand(int argc, char **argv);

#endif