#ifndef ASSIGNMENT_HPP
#define ASSIGNMENT_HPP 1

#include <string>

class Assignment {
private:
    std::string assignmentName;
public:
    Assignment();
    Assignment(std::string name);
    ~Assignment();

    // Accessors & Modifiers
    void setName(std::string name);
    std::string getName();
};

#endif