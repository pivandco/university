#pragma once

#include <string>
#include <map>

#include "AppState.hpp"
#include "Command.hpp"

using CommandSet = std::map<std::string, Command>;

class CommandRegistry {
public:
    void add_command_set(CommandSet &);
    const Command &find_command(const std::string &) const;
    CommandSet &commands();

private:
    CommandSet _commands;
};

CommandRegistry &get_command_registry();
