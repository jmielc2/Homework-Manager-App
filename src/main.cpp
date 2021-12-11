#include "core.hpp"
#include "Commands/Commands.hpp"
#include "App.hpp"

int main (int argc, char **argv) {
    setup();
    if (argc == 1) {
        printGeneralUsage();
        return 0;
    }
    
    flagNames options;
    if (parseCommand(argc, argv, options)) {
        runApp(options);
    }
    
    return 0;
}
