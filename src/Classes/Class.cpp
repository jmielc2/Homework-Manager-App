#include "Class.hpp"

// Class Constructors
Class::Class() {
    return;
}

Class::Class(std::string name) {
    this->className = name;
}

// Class Destructor
Class::~Class() {
    return;
}

// Setters & Modifiers
void Class::setName(std::string name) {
    this->className = name;
}

void Class::addAssignment(std::string name) {
    this->assignments.push_back(Assignment(name));
}

void Class::removeAssignment(std::string name) {
    for (auto it = this->assignments.begin(); it != this->assignments.end(); it++) {
        if (it->getName() == name) {
            this->assignments.erase(it);
            break;
        }
    }
}

// Getters
std::string Class::getName() const {
    return this->className;
}

std::vector<Assignment> Class::getAssignments() const {
    return this->assignments;
}

// JSON Converters
void Class::to_json(json &j, const Class &c) {
    j["name"] = "CS 211";
    j["assignments"] = {"Homework 1", "Test 6", "Project 4", "Essay 5"};
}

void Class::from_json(const json &j, Class &c) {
    return;
}

// Operators
bool Class::operator== (Class &rhs) {
    return this->className == rhs.className;
}

bool Class::operator!= (Class &rhs) {
    return !(this->operator==(rhs));
}