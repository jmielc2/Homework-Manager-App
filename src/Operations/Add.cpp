#include "Add.hpp"

void getClassName(std::string &className) {
    std::cout << "Please enter the name of the class: ";
    std::getline(std::cin, className);
}

void getProffessorName(std::string &proffessor) {
    std::cout << "Please enter the name of the teacher: ";
    std::getline(std::cin, proffessor);
}

bool confirmClassName(std::string &className) {
    std::cout << "Class '" << className << "' was NOT found. Would you like to add it? (Yes/No): ";
    std::string ans;
    std::cin >> ans;
    if (ans.find("Yes") != std::string::npos || ans.find("yes") != std::string::npos
    || ans.find("Y") != std::string::npos || ans.find("y") != std::string::npos) {
        return true;    
    }
    return false;
}

void add::runAdd(gen::flagNames &options, std::map<std::string, gen::classData> &myClasses) {
    while (true) {
        if (options.className == "") {
            getClassName(options.className);
        }
        if (myClasses.count(options.className) == 0) {
            if (confirmClassName(options.className)) {
                myClasses.emplace(options.className, gen::classData());
                getProffessorName(myClasses.at(options.className).professor);
                std::cout << "Added a new class '" << options.className << "'!" << std::endl << std::endl;
                break;
            } else {
                options.className = "";
            }
        } else {
            std::cout << "Found '" << options.className << "'!" << std::endl << std::endl;
            break;
        }
    }
    if (options.assignment == "") {
        return;
    }

}