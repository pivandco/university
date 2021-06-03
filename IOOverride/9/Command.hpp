#pragma once

struct AppState;
#include "AppState.hpp"

// using CommandCallback = void (*)(AppState &);

struct Command {
    const char *help;
    void (*callback)(AppState &);
};

class CommandAborted : public std::exception {
public:
    CommandAborted() {
    }
};
