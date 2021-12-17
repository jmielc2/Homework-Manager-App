#include "App.hpp"
#include "Commands/Commands.hpp"

std::set<Class> createClasses(const fs::path &dataFilePath) {
    json classData;

    std::ifstream inFile(dataFilePath);
    inFile >> classData;
    inFile.close();
    std::cout << classData << std::endl;

    std::cout << classData["CS 211"]["assignments"] << std::endl;
    std::cout << classData["CS 251"]["assignments"] << std::endl;

    return {};
}

std::set<Class> setupApp() {
    std::cout << std::fixed << std::setprecision(2);
    fs::path dataFolderPath("./data");
    fs::path dataFilePath("./data/class-data.json");
    
    if (!fs::exists(dataFolderPath)) {
        fs::create_directory(dataFolderPath);
    }
    if (!fs::exists(dataFilePath)) {
        std::ofstream dataFile(dataFilePath);
        dataFile.close();
    }
    return createClasses(dataFilePath);
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