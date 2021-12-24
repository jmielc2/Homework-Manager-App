#include "Structures.hpp"

void gen::to_json(json &j, const gen::classData &d) {
    j["class name"] = d.className;
    j["professor"] = d.professor;
    for (auto &assignment : d.assignments) {
        j["assignments"].push_back(assignment);
    }
}

void gen::from_json(const json &j, gen::classData &d) {
    j.at("class name").get_to(d.className);
    j.at("professor").get_to(d.professor);
    for (auto &assignment : j.at("assignments")) {
        d.assignments.push_back(assignment);
    }
}