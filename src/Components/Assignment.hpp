#ifndef ASSIGNMENT_HPP
#define ASSIGNMENT_HPP 1

#include <string>
#include "../include/json.hpp"

using json = nlohmann::json;

namespace amnt {
    enum type {HOMEWORK, ESSAY, EXAM, PROJECT, OTHER};

    class Assignment {
    private:
        std::string assignmentName;
        int type;
    public:
        Assignment();
        Assignment(std::string name);
        Assignment(std::string name, int assignmentType);
        ~Assignment();

        // Accessors & Modifiers
        void setName(std::string name);
        std::string getName() const;

        void setType(int assignmentType);
        int getType() const;
    };

    extern void to_json(json &j, const amnt::Assignment &a);
    extern void from_json(const json &j, amnt::Assignment &a);
};

#endif