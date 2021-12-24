#include "Show.hpp"

void printClassInfo (const gen::classData &data) {
    std::cout << data.className << ":" << std::endl;
    std::cout << std::setw(13) << "Professor: " << data.professor << std::endl;
    std::cout << std::setw(16) << "Assignment(s):" << std::endl;
    int i = 0;
    for (i; i < int(data.assignments.size()) - 1; i++) {
        std::cout << std::setw(5) << "(" << i + 1 << ") " << data.assignments.at(i).getName() << std::endl;
    }
    if (data.assignments.size() >= 1) {
        std::cout << std::setw(5) << "(" << i + 1 <<") " << data.assignments.at(i).getName() << std::endl;
    } else {
        std::cout << std::setw(4) << "" << "No assignments!" << std::endl;
    }
    std::cout << std::endl;
}

void show::runShow(const gen::flagNames &options, const std::map<std::string, gen::classData> &myClasses) {
    if (options.className == "") {
        for (auto it = myClasses.begin(); it != myClasses.end(); it++) {
            printClassInfo(it->second);
        }
    } else if (myClasses.count(options.className)) {
        printClassInfo(myClasses.at(options.className));
    } else {
        std::cout << "Class '" << options.className << "' was not found." << std::endl << std::endl;
    }
}