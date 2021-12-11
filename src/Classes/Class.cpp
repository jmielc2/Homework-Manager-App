#include "Class.hpp"

// Class Constructor
Class::Class() {
    return;
}

// Class Destructor
Class::~Class() {
    return;
}

bool Class::operator== (Class &rhs) {
    return true;
}

bool Class::operator!= (Class &rhs) {
    return !(this->operator==(rhs));
}