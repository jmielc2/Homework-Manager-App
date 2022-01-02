#include "Remove.hpp"

void rm::runRemove(gen::flagNames &options, std::map<std::string, gen::classData> &myClasses) {
    if (myClasses.size() == 0) {
        std::cout << "No classes currently saved." << std::endl << std::endl;
        return;
    }
    if (options.className == "") {
        gen::getClassName(options.className);
    }
    if (!myClasses.count(options.className)) {
        std::cout << "Class " << options.className << " was not found." << std::endl << std::endl;
        return;
    }
    if (options.assignment == "") {
        removeClass(options, myClasses);
    } else {
        removeAssignment(options, myClasses);
    }
}

void rm::removeClass(const gen::flagNames &options, std::map<std::string, gen::classData> &myClasses) {
    std::cout << "Class " << options.className << " and all its data will be deleted. Do you want to proceed? (Yes/No): ";
    if (gen::confirm()) {
        myClasses.erase(options.className);
        std::cout << "Class " << options.className << " has been deleted." << std::endl;
    }
    std::cout << std::endl;
}

void rm::removeAssignment(const gen::flagNames &options, std::map<std::string, gen::classData> &myClasses) {
    int i = 0;
    for (auto &a : myClasses.at(options.className).assignments) {
        if (a.getName() == options.assignment) {
            std::cout << "Assignment " << options.assignment << " for " << options.className << " will be removed. Do you want to proceed? (Yes/No): ";
            if (gen::confirm()) {
                myClasses.at(options.className).assignments.erase(myClasses.at(options.className).assignments.begin() + i);
            }
            std::cout << "Assignment " <<  options.assignment << " for " << options.className << " has been removed." << std::endl << std::endl;
            return;
        }
        i++;
    }
    std::cout << "Assignment " << options.assignment << " was not found for " << options.className << "." << std::endl << std::endl;
}