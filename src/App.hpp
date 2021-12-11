#ifndef APP_HPP
#define APP_HPP

#include "core.hpp"

class App {
private:
public:
    App ();
    ~App();
    void run (int cmdType, vector<string> &contents);
};

#endif