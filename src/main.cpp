#include "App.hpp"

int main (int argc, char **argv) {
    std::map<std::string, gen::classData> myClasses = app::setupApp();
    if (argc == 1) {
        cmd::printGeneralUsage();
        return 0;
    }
    
    gen::flagNames options;
    if (app::parseCommand(argc, argv, options)) {
        app::runApp(options, myClasses);
    }
    
    return 0;
}
