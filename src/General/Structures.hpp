#ifndef STRUCT_HPP
#define STRUCT_HPP 1

#include "../core.hpp"

namespace gen {
    struct flagNames {
        int cmdType;
        std::string className;
        std::string assignment;
    };

    struct classData {
        std::string className;
        std::vector<amnt::Assignment> assignments;
        std::string professor;
        double grade;
    };

    extern void to_json(json &j, const classData &d);

    extern void from_json(const json &j, classData &d);
};

#endif