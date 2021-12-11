#include "core.hpp"
#include "Commands/Commands.hpp"
#include "App.hpp"

int main (int argc, char **argv) {
    setup();
    if (argc == 1) {
        printGeneralUsage();
        return 0;
    }
    pair<int, vector<string>> commandInfo = parseCommand(argc, argv);
    if (commandInfo.first <= 2) {
        App app;
        app.run(commandInfo.first, commandInfo.second);
    }
    
    return 0;
}
