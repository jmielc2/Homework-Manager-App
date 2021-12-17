#include "Assignment.hpp"

// Assignment Constructors
Assignment::Assignment () {
    return;
}

Assignment::Assignment(std::string name) {
    this->assignmentName = name;
}

// Assignment Destructor
Assignment::~Assignment() {
    return;
}

void Assignment::setName(std::string name) {
    this->assignmentName = name;
    return;
}

std::string Assignment::getName() {
    return this->assignmentName;
}