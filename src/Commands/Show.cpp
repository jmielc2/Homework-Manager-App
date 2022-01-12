#include "Show.hpp"

std::string idAssignmentType(int type) {
    switch (type) {
        case (amnt::HOMEWORK):
            return "Homework";
        case (amnt::ESSAY):
            return "Essay(s)";
        case (amnt::EXAM):
            return "Exam(s)";
        case (amnt::PROJECT):
            return "Project(s)";
        case (amnt::OTHER):
            return "Other Assignment(s)";
        default:
            return "NA";
    }
}

void printClassInfo (const gen::classData &data) {
    std::cout << data.className << ":" << std::endl;
    std::cout << std::setw(13) << "Professor: " << data.professor << std::endl;
    if (!data.assignments.size()) {
        std::cout << std::setw(4) << "" << "No assignments!" << std::endl << std::endl;
        return;
    }
    std::vector<std::vector<std::string>> sortedAssignments(amnt::NUM_ASSIGNMENT_TYPES);
    for (auto &a : data.assignments) {
        sortedAssignments.at(a.getType() - 1).push_back(a.getName());
    }
    for (int j = 0; j < amnt::NUM_ASSIGNMENT_TYPES; j++) {
        if (!sortedAssignments.at(j).size()) {
            continue;
        }
        std::cout << std::setw(2) << "" << idAssignmentType(j + 1) << std::endl;
        for (int i = 0; i < sortedAssignments.at(j).size(); i++) {
            std::cout << std::setw(4) << "" << i + 1 << ". " << sortedAssignments.at(j).at(i) << std::endl;
        }
    }
    std::cout << std::endl;
}

void show::runShow(const gen::flagNames &options, const std::map<std::string, gen::classData> &myClasses) {
    std::string className;
    if (options.className == "") {
        for (auto it = myClasses.begin(); it != myClasses.end(); it++) {
            printClassInfo(it->second);
        }
    } else if (gen::searchClasses(myClasses, options.className, className)) {
        printClassInfo(myClasses.at(className));
    } else {
        std::cout << "Class " << options.className << " was not found." << std::endl << std::endl;
    }
}