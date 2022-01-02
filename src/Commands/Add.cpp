#include "Add.hpp"

void add::addClass(const gen::flagNames &options, std::map<std::string, gen::classData> &myClasses) {
    myClasses.emplace(options.className, gen::classData());
    myClasses.at(options.className).className = options.className;
    gen::getProffessorName(myClasses.at(options.className).professor);
    std::cout << "Class " << options.className << " has been created." << std::endl << std::endl;
}

void add::addAssignment(const gen::flagNames &options, std::map<std::string, gen::classData> &myClasses) {
    int type;
    gen::getAssignmentType(type);
    myClasses.at(options.className).assignments.push_back(amnt::Assignment(options.assignment, type));
    return;
}

void add::runAdd(gen::flagNames &options, std::map<std::string, gen::classData> &myClasses) {
    bool addedClass = false;
    while (true) {
        if (options.className == "") {
            gen::getClassName(options.className);
        }
        if (!myClasses.count(options.className)) {
            std::cout << "Class " << options.className << " was not found." << std::endl;
            std::cout << "Class " << options.className << " will be created. Do you want to proceed? (Yes/No): ";
            if (gen::confirm()) {
                addClass(options, myClasses);
                addedClass = true;
                break;
            } else {
                options.className = "";
            }
        } else {
            break;
        }
    }

    if (options.assignment == "") {
        if (addedClass) {
            return;
        }
        gen::getAssignmentName(options.assignment);
    }
    bool found = false;
    for (auto &a : myClasses.at(options.className).assignments) {
        if (options.assignment == a.getName()) {
            found = !found;
            break;
        }
    }
    if (found) {
        std::cout << "Assignment " << options.assignment << " for " << options.className << " already exists." << std::endl << std::endl;
    } else {
        addAssignment(options, myClasses);
        std::cout << "Assignment " << options.assignment << " has been added." << std::endl << std::endl;
    }
}