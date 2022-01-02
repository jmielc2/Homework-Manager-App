#include "Add.hpp"

bool add::addClass(const gen::flagNames &options, std::map<std::string, gen::classData> &myClasses) {
    std::cout << "Class " << options.className << " will be created. Do you want to proceed? (Yes/No): ";
    if (gen::confirm()) {
        myClasses.emplace(options.className, gen::classData());
        myClasses.at(options.className).className = options.className;
        gen::getProffessorName(myClasses.at(options.className).professor);
        std::cout << "Class " << options.className << " has been created." << std::endl << std::endl;
        return true;
    }
    return false;
}

bool add::addAssignment(const gen::flagNames &options, std::map<std::string, gen::classData> &myClasses) {
    for (auto &a : myClasses.at(options.className).assignments) {
        if (options.assignment == a.getName()) {
            std::cout << "Assignment " << options.assignment << " for " << options.className << " already exists." << std::endl << std::endl;
            return false;
        }
    }
    int type;
    gen::getAssignmentType(type);
    std::cout << "Assignment " << options.assignment << " for " << options.className << " will be added. Do you want to proceed? (Yes/No): ";
    if (gen::confirm()) {
        myClasses.at(options.className).assignments.push_back(amnt::Assignment(options.assignment, type));
        std::cout << "Assignment " << options.assignment << " for " << options.className << " has been added." << std::endl << std::endl;
        return true;
    }
    return false;
}

void add::runAdd(gen::flagNames &options, std::map<std::string, gen::classData> &myClasses) {
    if (options.className == "") {
        gen::getClassName(options.className);
    }

    if (!myClasses.count(options.className)) {
        std::cout << "Class " << options.className << " was not found." << std::endl;
        addClass(options, myClasses);
        return;
    }

    if (options.assignment == "") {
        gen::getAssignmentName(options.assignment);
    }
    addAssignment(options, myClasses);
}