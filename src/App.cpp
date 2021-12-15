#include "core.hpp"
#include "App.hpp"

void runApp (const flagNames options, std::set<Class> &myClasses)  {
    switch (options.cmdType) {
        case(COMMANDS::ADD):
            std::cout << "Running Add..." << std::endl;
            break;
        case(COMMANDS::REMOVE):
            std::cout << "Running Remove..." << std::endl;
            break;
        case(COMMANDS::SHOW):
            std::cout << "Running Show..." << std::endl;
            break;
    }
};