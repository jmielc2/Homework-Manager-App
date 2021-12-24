#include "Commands.hpp"

void cmd::printCommands() {
    std::cout << "Commands:" << std::endl;
    std::cout << "\tadd" << std::setw(7) << " " << "Add a class or assignment." << std::endl;
    std::cout << "\tremove" << std::setw(4) << " " << "Remove a class or assignment." << std::endl;
    std::cout << "\tshow" << std::setw(6) << " " << "Display class or assignment." << std::endl;
    std::cout << "\tversion" << std::setw(3) << " " << "Display current app version." << std::endl;
    std::cout << "\thelp" << std::setw(6) << " " << "Display commands and options." << std::endl << std::endl;
}


void cmd::printCommandOptions() {
    std::cout << "Command Options:" << std::endl;
    std::cout << "   ADD:" << std::endl;
    std::cout << "\tNONE" << std::setw(36) << "   " << "No options. Will prompt user input." << std::endl;
    std::cout << "\t-c <class name>" << std::setw(25) << "   " << "Specifies addition of a new class and its name." << std::endl;
    std::cout << "\t-c <class name> -a <assignment name>" << std::setw(4) << "   " << "Specifies addition of an assignment, the class it is in, and its name." << std::endl;
    std::cout << "   REMOVE:" << std::endl;
    std::cout << "\tNONE" << std::setw(36) << "   " << "No options. Will prompt user input." << std::endl;
    std::cout << "\t-c <class name>" << std::setw(25) << "   " << "Specifies remove of a class and its name." << std::endl;
    std::cout << "\t-c <class name> -a <assignment name>" << std::setw(4) << "   " << "Specifies removal of an assignment, the class it is in, and its name." << std::endl;
    std::cout << "   SHOW:" << std::endl;
    std::cout << "\tNONE" << std::setw(36) << "   " << "No options. Displays all classes and their assignments." << std::endl;
    std::cout << "\t-c <class name>" << std::setw(25) << "   " << "Displays all assignments for the specified class." << std::endl;
    std::cout << "   VERSION:" << std::endl;
    std::cout << "\tNONE" << std::setw(36) << "   " << "No options. Displays the current app version." << std::endl;
    std::cout << "   HELP:" << std::endl;
    std::cout << "\tNONE" << std::setw(36) << "   " << "No options. Displays the apps commands and options formatting." << std::endl << std::endl;
}


void cmd::printUsage() {
    std::cout << "Usage" << std::endl << std::endl;
    std::cout << "\thomework <command> [options]" << std::endl << std::endl;
}


void cmd::printGeneralUsage() {
    cmd::printUsage();
    cmd::printCommands();
}
