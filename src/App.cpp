#include "App.hpp"

std::map<std::string, gen::classData> fetchClassData(const fs::path &dataFilePath) {
    json data;
    std::ifstream inFile(dataFilePath);
    inFile >> data;
    inFile.close();
    std::map<std::string, gen::classData> myClasses;
    for (auto a : data.at("data")) {
        myClasses.emplace(a["class name"], a.get<gen::classData>());
    }
    return myClasses;
}

void saveClassData(std::map<std::string, gen::classData> &myClasses, const fs::path &dataFilePath) {
    json data;
    for (auto it = myClasses.begin(); it != myClasses.end(); it++) {
        data["data"].push_back(it->second);
    }
    std::ofstream outFile(dataFilePath);
    outFile << std::setw(4) << data << std::endl;
    outFile.close();
}

std::map<std::string, gen::classData> setupApp() {
    std::cout << std::fixed << std::setprecision(2);
    if (!fs::exists(gen::dataFolderPath)) {
        fs::create_directory(gen::dataFolderPath);
    }
    if (!fs::exists(gen::dataFilePath)) {
        std::ofstream dataFile(gen::dataFilePath);
        dataFile.close();
    }
    return fetchClassData(gen::dataFilePath);
}

bool getFlags(int argc, char **argv, gen::flagNames &options) {
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

bool parseCommand(int argc, char **argv, gen::flagNames &options) {
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

void runApp (const gen::flagNames options, std::map<std::string, gen::classData> &myClasses)  {
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
    saveClassData(myClasses, gen::testFilePath);
};