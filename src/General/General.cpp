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
    while (stripString(className) == "") {
        std::cout << std::endl << "Invalid name, please enter an identifiable name: ";
        std::getline(std::cin, className);
    }
    className = stripString(className);
    std::cout << std::endl;
}

void gen::getAssignmentName(std::string &assignmentName) {
    std::cout << "Please enter the name of the assignment: ";
    std::getline(std::cin, assignmentName);
    while (stripString(assignmentName) == "") {
        std::cout << std::endl << "Invalid name, please enter an identifiable name: ";
        std::getline(std::cin, assignmentName);
    }
    assignmentName = stripString(assignmentName);
    std::cout << std::endl;
}

void gen::getProffessorName(std::string &professor) {
    std::cout << "Please enter the name of the teacher: ";
    std::getline(std::cin, professor);
    while (stripString(professor) == "") {
        std::cout << std::endl << "Invalid name, please enter an identifiable name: ";
        std::getline(std::cin, professor);
    }
    professor = stripString(professor);
    std::cout << std::endl;
}

bool gen::confirm() {
    std::string ans;
    std::getline(std::cin, ans);
    std::cout << std::endl;
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
        std::getline(std::cin, ans);
        std::cout << std::endl;
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
            break;
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

std::string gen::stripString(std::string phrase) {
    int i = 0, j = 0, k = 0;
    while (i < phrase.size()) {
        if (!std::isspace(phrase.at(i))) {
            break;
        }
        i++;
    }
    if (i == phrase.size()) {
        return "";
    }
    j = k = i;

    while (k < phrase.size()) {
        while (k < phrase.size() && !std::isspace(phrase.at(k))) {
            k++;
        }
        j = k;
        while (k < phrase.size() && std::isspace(phrase.at(k))) {
            k++;
        }
    }

    return phrase.substr(i, j - i);
}


bool gen::searchClasses(const std::map<std::string, gen::classData> &myClasses, const std::string key, std::string &className) {
    if (myClasses.count(key)) {
        className = key;
        return true;
    }
    bool found = false;
    for (const auto &a : myClasses) {
        if (a.first.find(key) != std::string::npos) {
            if (!found) {
                found = true;
                className = a.first;
            } else {
                className = "";
                return false;
            }
        }
    }
    return true;
}


bool gen::searchAssignments(const std::vector<amnt::Assignment> &assignments, const std::string key, std::string &assignmentName) {
    assignmentName = key;
    return true;
}
