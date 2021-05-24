#pragma once

#include <string>
#include <map>

#include "AppState.hpp"

using CommandCallback = void (*)(AppState &);
struct Command {
    const char *help;
    CommandCallback callback;
};

extern const std::map<std::string, Command> COMMANDS;
