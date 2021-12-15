#ifndef ASSIGNMENT_HPP
#define ASSIGNMENT_HPP

#include "../core.hpp"

enum {TEST, QUIZ, ESSAY, DISSCUSSION_POST, HOMEWORK, READING};

class Assignment {
private:
    std::string name;
    int category;
    int priority;
    tm dueDate;
public:
    Assignment();
    Assignment(std::string name, int category, tm dueDate);
    ~Assignment();

    // Accessors & Modifiers
    void setName(std::string assignmentName);
    std::string getName();

    void setType(int assignmentType);
    int getType();

    void setDueDate(int month, int day, int year);
    tm* getDueDate();

    void setPriority(int assignmentPriority);
    int getPriority();
};

#endif