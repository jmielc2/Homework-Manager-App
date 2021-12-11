#include "core.hpp"
#include "App.hpp"

void runApp (const flagNames options, set<Class> &myClasses)  {
    switch (options.cmdType) {
        case(COMMANDS::ADD):
            cout << "Running Add..." << endl;
            break;
        case(COMMANDS::REMOVE):
            cout << "Running Remove..." << endl;
            break;
        case(COMMANDS::SHOW):
            cout << "Running Show..." << endl;
            break;
    }
};