#include "Add.hpp"

void add::addClass(const gen::flagNames &options, std::map<std::string, gen::classData> &myClasses) {
    myClasses.emplace(options.className, gen::classData());
    myClasses.at(options.className).className = options.className;
    gen::getProffessorName(myClasses.at(options.className).professor);
    std::cout << "The class '" << options.className << "' has been created." << std::endl << std::endl;
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
            if (gen::confirmClassName(options.className)) {
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
        std::cout << "An assignment by the name of '" << options.assignment << "' already exists for '" << options.className <<"'." << std::endl << std::endl;
    } else {
        std::cout << "Adding '" << options.assignment << "' to '" << options.className << "'." << std::endl;
        addAssignment(options, myClasses);
        std::cout << "Assignment added." << std::endl << std::endl;
    }
}