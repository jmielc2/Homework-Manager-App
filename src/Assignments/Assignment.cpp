#include "Assignment.hpp"

// Assignment Constructor
Assignment::Assignment () {
    return;
}

// Assignment Destructor
Assignment::~Assignment() {
    return;
}

void Assignment::setName(wstring assignmentName) {
    this->name = assignmentName;
    return;
}

wstring Assignment::getName() {
    return this->name;
}

void Assignment::setType(int assignmentType) {
    this->type = assignmentType;
    return;
}

int Assignment::getType() {
    return this->type;
}

void Assignment::setDueDate(int month, int day, int year) {
    this->dueDate.month = month;
    this->dueDate.day = day;
    this->dueDate.year = year;
}

Assignment::Date Assignment::getDueDate() {
    return this->dueDate;
}

void Assignment::setPriority(int assignmentPriority) {
    this->priority = assignmentPriority;
    return;
}