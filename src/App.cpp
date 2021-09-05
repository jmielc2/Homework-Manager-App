#include "App.hpp"

// App Constructor
App::App() : variable(1) {
    return;
}

// App Destructor
App::~App() {
    return;
}

// App Executor
void App::run()  {
    MainMenu mainMenu;
    cout << "The variable has the value of: " << this->variable << endl;
    return;
};