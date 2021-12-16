#include "Commands.hpp"

std::set<Class> setup() {
    std::cout << std::fixed << std::setprecision(2);
    fs::path dataFolderPath("./data");
    fs::path dataFilePath("./data/class-data.json");
    
    if (!fs::exists(dataFolderPath)) {
        fs::create_directory(dataFolderPath);
    }
    if (!fs::exists(dataFilePath)) {
        std::ofstream dataFile("./data/class-data.json");
        dataFile.close();
    }
    return {};
}


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


bool getFlags(int argc, char **argv, flagNames &options) {
    int i = 2;
    while (i < argc) {
        if (std::string(argv[i]) == "-c") {
            i++;
            while (i < argc && argv[i][0] != '-') {
                options.className += std::string(argv[i]) + " ";
                i++;
            }
            options.className = options.className.substr(0, options.className.size() - 1);
        } else if (std::string(argv[i]) == "-a") {
            i++;
            while (i < argc && argv[i][0] != '-') {
                options.assignment += std::string(argv[i]) + " ";
                i++;
            }
            options.assignment = options.assignment.substr(0, options.assignment.size() - 1);
        } else {
            i++;
        }
    }
    std::cout << "Class Name: '" << options.className << "'" << std::endl;
    std::cout << "Assignment: '" << options.assignment << "'" << std::endl;
    return true;
}


bool parseCommand(int argc, char **argv, flagNames &options) {
    std::string cmd(argv[1]);
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
        std::cout << "homework " << VERSION_P1 << "." << VERSION_P2 << std::endl;
        return false;
    } else if (cmd == "help") {
        printGeneralUsage();
        printCommandOptions();
        return false;
    }
    printGeneralUsage();
    return false;
}