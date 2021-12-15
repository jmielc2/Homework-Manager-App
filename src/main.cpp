#include "core.hpp"
#include "Commands/Commands.hpp"
#include "App.hpp"

int main (int argc, char **argv) {
    std::set<Class> myClasses = setup();
    if (argc == 1) {
        printGeneralUsage();
        return 0;
    }
    
    flagNames options;
    if (parseCommand(argc, argv, options)) {
        runApp(options, myClasses);
    }
    
    return 0;
}
