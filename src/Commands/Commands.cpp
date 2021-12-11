#include "Commands.hpp"

set<Class> setup() {
    cout << fixed << setprecision(2);
    return {};
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
    cout << "   add" << endl;
    cout << "\tNONE  =  No options. Will prompt user input." << endl;
    cout << "\t-c <class name>  =  Specifies addition of a new class and its name." << endl;
    cout << "\t-c <class name> -a <assignment name>  =  Specifies addition of an assignment, the class it is in, and its name." << endl;
    cout << "   remove" << endl;
    cout << "\tNONE  =  No options. Will prompt user input." << endl;
    cout << "\t-c <class name>  =  Specifies remove of a class and its name." << endl;
    cout << "\t-c <class name> -a <assignment name>  =  Specifies removal of an assignment, the class it is in, and its name." << endl;
    cout << "   show" << endl;
    cout << "\tNONE  =  No options. Displays all classes and their assignments." << endl;
    cout << "\t-c <class name>  =  Displays all assignments for the specified class." << endl;
    cout << "   version" << endl;
    cout << "\tNONE  =  No options. Displays the current app version." << endl;
    cout << "   help" << endl;
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


bool getFlags(int argc, char **argv, flagNames &options) {
    int i = 2;
    while (i < argc) {
        if (string(argv[i]) == "-c") {
            i++;
            while (i < argc && argv[i][0] != '-') {
                options.className += string(argv[i]) + " ";
                i++;
            }
            options.className = options.className.substr(0, options.className.size() - 1);
        } else if (string(argv[i]) == "-a") {
            i++;
            while (i < argc && argv[i][0] != '-') {
                options.assignment += string(argv[i]) + " ";
                i++;
            }
            options.assignment = options.assignment.substr(0, options.assignment.size() - 1);
        } else {
            i++;
        }
    }
    cout << "Class Name: '" << options.className << "'" << endl;
    cout << "Assignment: '" << options.assignment << "'" << endl;
}


bool parseCommand(int argc, char **argv, flagNames &options) {
    string cmd(argv[1]);
    options.className = options.assignment = "";
    if (cmd == "add") {
        options.cmdType = COMMANDS::ADD;
        getFlags(argc, argv, options);
        return true;
    } else if (cmd == "remove") {
        options.cmdType = COMMANDS::REMOVE;
        getFlags(argc, argv, options);
        return true;
    } else if (cmd == "show") {
        options.cmdType = COMMANDS::SHOW;
        getFlags(argc, argv, options);
        return true;
    } else if (cmd == "version") {
        cout << "homework " << VERSION_P1 << "." << VERSION_P2 << endl;
        return false;
    } else if (cmd == "help") {
        printGeneralUsage();
        printCommandOptions();
        return false;
    }
    printGeneralUsage();
    return false;
}