#pragma once

#include <string>

#include "Command.hpp"
#include "CommandRegistry.hpp"

class CLI {
public:
    CLI();
    const Command get_command();

private:
    CommandRegistry &cmdreg = get_command_registry();
};
