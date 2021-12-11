#ifndef CLASS_HPP
#define CLASS_HPP

#include "../core.hpp"

class Class {
private:
public:
    Class();
    ~Class();
    bool operator== (Class &rhs);
    bool operator!= (Class &rhs);
};

#endif