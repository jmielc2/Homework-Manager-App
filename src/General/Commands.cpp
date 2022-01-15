#include "Commands.hpp"

void cmd::printCommands() {
    std::cout << "Commands:" << std::endl;
    std::cout << "\tadd" << std::setw(7) << " " << "Add a class or assignment." << std::endl;
    std::cout << "\tremove" << std::setw(4) << " " << "Remove a class or assignment." << std::endl;
    std::cout << "\tshow" << std::setw(6) << " " << "Display class or assignment." << std::endl;
    std::cout << "\tedit" << std::setw(6) << " " << "Edits a specified class or assignment." << std::endl;
    std::cout << "\tversion" << std::setw(3) << " " << "Display current app version." << std::endl;
    std::cout << "\thelp" << std::setw(6) << " " << "Display commands and options." << std::endl << std::endl;
}


void cmd::printCommandOptions() {
    std::cout << "Command Options:" << std::endl;
    printAddOptions();
    printRemoveOptions();
    printShowOptions();
    printEditOptions();
    printVersionOptions();
    printHelpOptions();
    std::cout << std::endl;
}


void cmd::printUsage() {
    std::cout << "Usage:" << std::endl << std::endl;
    std::cout << "\thomework <command> [options]" << std::endl << std::endl;
}


void cmd::printGeneralUsage() {
    cmd::printUsage();
    cmd::printCommands();
}


void cmd::printAddOptions() {
    std::cout << "   add" << std::endl;
    std::cout << "\tNONE" << std::setw(36) << "   " << "No options. Will prompt user input." << std::endl;
    std::cout << "\t-c <class name>" << std::setw(25) << "   " << "Specifies addition of a new class and its name." << std::endl;
    std::cout << "\t-c <class name> -a <assignment name>" << std::setw(4) << "   " << "Specifies addition of an assignment, the class it is in, and its name." << std::endl;
}


void cmd::printRemoveOptions() {
    std::cout << "   remove" << std::endl;
    std::cout << "\tNONE" << std::setw(36) << "   " << "No options. Will prompt user input." << std::endl;
    std::cout << "\t-c <class name>" << std::setw(25) << "   " << "Specifies remove of a class and its name." << std::endl;
    std::cout << "\t-c <class name> -a <assignment name>" << std::setw(4) << "   " << "Specifies removal of an assignment, the class it is in, and its name." << std::endl;
}


void cmd::printShowOptions() {
    std::cout << "   show" << std::endl;
    std::cout << "\tNONE" << std::setw(36) << "   " << "No options. Displays all classes and their assignments." << std::endl;
    std::cout << "\t-c <class name>" << std::setw(25) << "   " << "Displays all assignments for the specified class." << std::endl;
}


void cmd::printVersionOptions() {
    std::cout << "   version" << std::endl;
    std::cout << "\tNONE" << std::setw(36) << "   " << "No options. Displays the current app version." << std::endl;
}


void cmd::printHelpOptions() {
    std::cout << "   help" << std::endl;
    std::cout << "\tNONE" << std::setw(36) << "   " << "No options. Displays the apps commands and options formatting." << std::endl << std::endl;
}

void cmd::printEditOptions() {
    std::cout << "   edit" << std::endl;
    std::cout << "\tNONE" << std::setw(36) << "" << "No options. Will prompt user input." << std::endl;
    std::cout << "\t-c <class name>" << std::setw(25) << "" << "Triggers the editing protocol for the specified class information." << std::endl;
    std::cout << "\t-c <class name> -a <assignment name>" << std::setw(4) << "" << "Triggers the editing protocol for the specified assignment for the given class." << std::endl;
}
