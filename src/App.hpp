#ifndef APP_HPP
#define APP_HPP

#include "core.hpp"
#include "States/MainMenu.hpp"

class App {
private:
    int variable;
public:
    App ();
    ~App();
    void run ();
};

#endif