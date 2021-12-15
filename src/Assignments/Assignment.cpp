#include "Assignment.hpp"

// Assignment Constructor
Assignment::Assignment () {
    return;
}

Assignment::Assignment(std::string name, int category, tm dueDate) {
    this->name = name;
    this->category = category;
    this->dueDate = dueDate;
}

// Assignment Destructor
Assignment::~Assignment() {
    return;
}

void Assignment::setName(std::string assignmentName) {
    this->name = assignmentName;
    return;
}

std::string Assignment::getName() {
    return this->name;
}

void Assignment::setType(int category) {
    this->category = category;
    return;
}

int Assignment::getType() {
    return this->category;
}

void Assignment::setDueDate(int month, int day, int year) {
    return;
}

void Assignment::setPriority(int assignmentPriority) {
    this->priority = assignmentPriority;
    return;
}