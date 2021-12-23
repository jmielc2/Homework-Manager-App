#include "Assignment.hpp"

// Assignment Constructors
amnt::Assignment::Assignment () {
    this->type = 0;
    return;
}

amnt::Assignment::Assignment(std::string name) {
    this->type = 0;
    this->assignmentName = name;
}

amnt::Assignment::Assignment(std::string name, int assignmentType) {
    this->type = assignmentType;
    this->assignmentName = name;
}

// Assignment Destructor
amnt::Assignment::~Assignment() {
    return;
}

void amnt::Assignment::setName(std::string name) {
    this->assignmentName = name;
    return;
}

std::string amnt::Assignment::getName() const {
    return this->assignmentName;
}

void amnt::Assignment::setType(int assignmentType) {
    this->type = assignmentType;
}

int amnt::Assignment::getType() const {
    return this->type;
}

void amnt::to_json(json &j, const amnt::Assignment &a) {
    j["name"] = a.getName();
    j["type"] = a.getType();
}

void amnt::from_json(const json &j, amnt::Assignment &a) {
    a.setName(j.at("name"));
    a.setType(j.at("type"));
}

