#include "General.hpp"

void gen::to_json(json &j, const gen::classData &d) {
    j["class name"] = d.className;
    j["professor"] = d.professor;
    j["assignments"] = json::array();
    for (auto &assignment : d.assignments) {
        j["assignments"].push_back(assignment);
    }
}

void gen::from_json(const json &j, gen::classData &d) {
    j.at("class name").get_to(d.className);
    j.at("professor").get_to(d.professor);
    for (auto &assignment : j.at("assignments")) {
        d.assignments.push_back(assignment);
    }
}

void gen::getClassName(std::string &className) {
    std::cout << "Please enter the name of the class: ";
    std::getline(std::cin, className);
}

void gen::getAssignmentName(std::string &assignmentName) {
    std::cout << "Please enter the name of the assignment: ";
    std::getline(std::cin, assignmentName);
}

void gen::getProffessorName(std::string &proffessor) {
    std::cout << "Please enter the name of the teacher: ";
    std::getline(std::cin, proffessor);
}

bool gen::confirm() {
    std::string ans;
    std::getline(std::cin, ans);
    if (ans.find("Yes") != std::string::npos || ans.find("yes") != std::string::npos
    || ans == "Y" || ans.find("y") != std::string::npos) {
        return true;    
    }
    return false;
}

void gen::getAssignmentType(int &type) {
    std::string ans;
    std::cout << "Assinment Type Options:" << std::endl;
    std::cout << std::setw(4) << " " << "(1) Homework" << std::endl;
    std::cout << std::setw(4) << " " << "(2) Essay" << std::endl;
    std::cout << std::setw(4) << " " << "(3) Exam" << std::endl;
    std::cout << std::setw(4) << " " << "(4) Project" << std::endl;
    std::cout << std::setw(4) << " " << "(5) Other" << std::endl;

    while (true) {
        std::cout << "Enter one of the options above: ";
        std::cin >> ans;
        if (ans.find("Homework") != std::string::npos || ans.find("homework") != std::string::npos
        || ans.find("1") != std::string::npos) {
            type = amnt::HOMEWORK;
            break;
        } else if (ans.find("Essay") != std::string::npos || ans.find("essay") != std::string::npos
        || ans.find("2") != std::string::npos) {
            type = amnt::ESSAY;
            break;
        } else if (ans.find("Exam") != std::string::npos || ans.find("exam") != std::string::npos
        || ans.find("3") != std::string::npos) {
            type = amnt::EXAM;
        } else if (ans.find("Project") != std::string::npos || ans.find("project") != std::string::npos
        || ans.find("4") != std::string::npos) {
            type = amnt::PROJECT;
            break;
        } else if (ans.find("Other") != std::string::npos || ans.find("other") != std::string::npos
        || ans.find("5") != std::string::npos) {
            type = amnt::OTHER;
            break;
        } else {
            std::cout << "Your option did not match." << std::endl << std::endl;
        }
    }
}