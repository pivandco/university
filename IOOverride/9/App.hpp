#pragma once

#include <string>

#include "AppState.hpp"

class App {
public:
    void command_loop();

private:
    AppState state;
};