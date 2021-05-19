#pragma once

#include <string>

#include "AppState.hpp"

class CLI {
public:
    void command_loop();

private:
    AppState state;
};
