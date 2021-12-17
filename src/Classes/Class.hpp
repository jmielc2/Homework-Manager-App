#ifndef CLASS_HPP
#define CLASS_HPP 1

#include <string>
#include <vector>
#include "../Assignments/Assignment.hpp"
#include "../include/json.hpp"

using json = nlohmann::json;

class Class {
private:
    std::string className;
    std::vector<Assignment> assignments;
public:
    Class();
    Class(std::string name);
    ~Class();

    // Setters & Modifiers
    void setName(std::string name);
    void addAssignment(std::string name);
    void removeAssignment(std::string name);

    // Accessors
    std::string getName() const;
    std::vector<Assignment> getAssignments() const;

    // JSON Converters
    void to_json(json &j, const Class& c);
    void from_json(const json &j, Class& c);

    // Operators
    bool operator== (Class &rhs);
    bool operator!= (Class &rhs);
};

#endif