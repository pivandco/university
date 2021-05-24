#pragma once

#include "AppState.hpp"
#include "CLI.hpp"

class App {
public:
    void loop();

private:
    AppState state;
    CLI cli;
};
