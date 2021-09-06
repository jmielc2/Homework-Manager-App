#ifndef ASSIGNMENT_HPP
#define ASSIGNMENT_HPP

#include "../core.hpp"
enum {TEST, QUIZ, ESSAY, DISSCUSSION_POST, HOMEWORK, READING, LECTURE_VIDEO};

class Assignment {
private:
    struct Date {
        int month, day, year;
    };

    wstring name;
    int type;
    int priority;
    Date dueDate;
public:
    Assignment();
    ~Assignment();

    // Accessors & Modifiers
    void setName(wstring assignmentName);
    wstring getName();

    void setType(int assignmentType);
    int getType();

    void setDueDate(int month, int day, int year);
    Date getDueDate();

    void setPriority(int assignmentPriority);
    int getPriority();
};

#endif