#include "Commands.hpp"

void setup() {
    cout << fixed << setprecision(2);
}


void printCommands() {
    cout << "Commands:" << endl;
    cout << "\tadd  =  Add a class or assignment." << endl;
    cout << "\tremove  =  Remove a class or assignment." << endl;
    cout << "\tshow  =  Display class or assignment." << endl;
    cout << "\tversion  =  Display current app version." << endl;
    cout << "\thelp   =  Display commands and options." << endl << endl;
}


void printCommandOptions() {
    cout << "Options:" << endl;
    cout << "  - add" << endl;
    cout << "\tNONE  =  No options. Will prompt user input." << endl;
    cout << "\tclass <class name>  =  Specifies addition of a new class and its name." << endl;
    cout << "\tassignment <class name> | <assignment name>  =  Specifies addition of an assignment, the class it is in, and its name." << endl;
    cout << "  - remove" << endl;
    cout << "\tNONE  =  No options. Will prompt user input." << endl;
    cout << "\tclass <class name>  =  Specifies remove of a class and its name." << endl;
    cout << "\tassignment <class name> | <assignment name>  =  Specifies removal of an assignment, the class it is in, and its name." << endl;
    cout << "  - show" << endl;
    cout << "\tNONE  =  No options. Displays all classes and their assignments." << endl;
    cout << "\tall  =  Displays all classes and their assignments." << endl;
    cout << "\t<class name>  =  Displays all assignments for the specified class." << endl;
    cout << "  - version" << endl;
    cout << "\tNONE  =  No options. Displays the current app version." << endl;
    cout << "  - help" << endl;
    cout << "\tNONE  =  No options. Displays the apps commands and options formatting." << endl;
}


void printUsage() {
    cout << "Usage" << endl << endl;
    cout << "\thomework <command> [options]" << endl << endl;
}


void printGeneralUsage() {
    printUsage();
    printCommands();
}


vector<string> stripOptions(int argc, char **argv, int cmdType) {
    if (argc == 2) {
        return {};
    }
    vector<string> options;


    return options;
}


pair<int, vector<string>> parseCommand(int argc, char **argv) {
    string cmd(argv[1]);
    int cmdType;
    if (cmd == "add") {
        cmdType = COMMANDS::ADD;
        cout << "RUN ADD" << endl;
    } else if (cmd == "remove") {
        cmdType = COMMANDS::REMOVE;
        cout << "RUN REMOVE" << endl;
    } else if (cmd == "show") {
        cmdType = COMMANDS::SHOW;
        cout << "RUN SHOW" << endl;
    } else if (cmd == "version") {
        cmdType = COMMANDS::VERSION;
        cout << "homework " << VERSION_1 << "." << VERSION_2 << endl;
    } else if (cmd == "help") {
        cmdType = COMMANDS::HELP;
        printGeneralUsage();
        printCommandOptions();
    } else {
        cmdType = COMMANDS::NONE;
        printGeneralUsage();
    }
    return pair<int, vector<string>> (cmdType, {});
}