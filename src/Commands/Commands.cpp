#include "Commands.hpp"

void printCommands() {
    std::cout << "Commands:" << std::endl;
    std::cout << "\tadd  =  Add a class or assignment." << std::endl;
    std::cout << "\tremove  =  Remove a class or assignment." << std::endl;
    std::cout << "\tshow  =  Display class or assignment." << std::endl;
    std::cout << "\tversion  =  Display current app version." << std::endl;
    std::cout << "\thelp   =  Display commands and options." << std::endl << std::endl;
}


void printCommandOptions() {
    std::cout << "Options:" << std::endl;
    std::cout << "   add" << std::endl;
    std::cout << "\tNONE  =  No options. Will prompt user input." << std::endl;
    std::cout << "\t-c <class name>  =  Specifies addition of a new class and its name." << std::endl;
    std::cout << "\t-c <class name> -a <assignment name>  =  Specifies addition of an assignment, the class it is in, and its name." << std::endl;
    std::cout << "   remove" << std::endl;
    std::cout << "\tNONE  =  No options. Will prompt user input." << std::endl;
    std::cout << "\t-c <class name>  =  Specifies remove of a class and its name." << std::endl;
    std::cout << "\t-c <class name> -a <assignment name>  =  Specifies removal of an assignment, the class it is in, and its name." << std::endl;
    std::cout << "   show" << std::endl;
    std::cout << "\tNONE  =  No options. Displays all classes and their assignments." << std::endl;
    std::cout << "\t-c <class name>  =  Displays all assignments for the specified class." << std::endl;
    std::cout << "   version" << std::endl;
    std::cout << "\tNONE  =  No options. Displays the current app version." << std::endl;
    std::cout << "   help" << std::endl;
    std::cout << "\tNONE  =  No options. Displays the apps commands and options formatting." << std::endl;
}


void printUsage() {
    std::cout << "Usage" << std::endl << std::endl;
    std::cout << "\thomework <command> [options]" << std::endl << std::endl;
}


void printGeneralUsage() {
    printUsage();
    printCommands();
}
