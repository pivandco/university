#include "CommandRegistry.hpp"

#include <fstream>
#include <iostream>

using std::map;
using std::string;

CommandRegistry instance;

CommandRegistry &get_command_registry() {
    return instance;
}

void CommandRegistry::add_command_set(CommandSet &set) {
    _commands.merge(set);
}

const Command &CommandRegistry::find_command(const string &name) const {
    return _commands.at(name);
}

CommandSet &CommandRegistry::commands() {
    return _commands;
}
