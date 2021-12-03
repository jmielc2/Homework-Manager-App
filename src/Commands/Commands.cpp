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


pair<string, vector<string>> parseCommand(int argc, char ** argv) {
    string cmd(argv[1]);
    if (cmd == "add") {
        cout << "RUN ADD" << endl;
    } else if (cmd == "remove") {
        cout << "RUN REMOVE" << endl;
    } else if (cmd == "show") {
        cout << "RUN SHOW" << endl;
    } else if (cmd == "version") {
        cout << "homework " << VERSION_1 << "." << VERSION_2 << endl;
    } else if (cmd == "help") {
        printGeneralUsage();
        printCommandOptions();
    } else {
        printGeneralUsage();
    }
    return {};
}