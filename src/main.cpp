#include "App.hpp"

int main (int argc, char **argv) {
    std::map<std::string, gen::classData> myClasses = setupApp();
    if (argc == 1) {
        cmd::printGeneralUsage();
        return 0;
    }
    
    gen::flagNames options;
    if (parseCommand(argc, argv, options)) {
        runApp(options, myClasses);
    }
    std::cout << std::endl;
    
    return 0;
}
