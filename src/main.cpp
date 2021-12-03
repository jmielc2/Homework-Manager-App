#include "core.hpp"
#include "Commands/Commands.hpp"
#include "App.hpp"

int main (int argc, char **argv) {
    setup();
    if (argc == 1) {
        printGeneralUsage();
        return 0;
    }
    pair<string, vector<string>> command = parseCommand(argc, argv);
    App app;
    app.run();
    
    return 0;
}
