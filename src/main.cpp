#include "App.hpp"

int main (int argc, char **argv) {
    std::map<std::string, gen::classData> myClasses = setupApp();
    if (argc == 1) {
        printGeneralUsage();
        return 0;
    }
    
    gen::flagNames options;
    if (parseCommand(argc, argv, options)) {
        runApp(options, myClasses);
    }
    
    return 0;
}
