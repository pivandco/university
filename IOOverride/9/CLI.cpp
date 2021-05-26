#include "CLI.hpp"

#include <iostream>

#include "commands.hpp"

using std::cin, std::cout;
using std::endl;
using std::out_of_range;
using std::string;

static string ask_command_string();

const Command NULL_COMMAND = { "", [] (AppState &) {} };

const Command CLI::get_command() {
    while (true) {
        string cmd_str = ask_command_string();
        if (cmd_str.empty()) {
            return NULL_COMMAND;
        }
        try {
            return COMMANDS.at(cmd_str);
        } catch (out_of_range) {
            cout << "Неизвестная команда: " << cmd_str << endl;
        }
    }
}

static string ask_command_string() {
    cout << "> ";
    string command;
    getline(cin, command);
    if (cin.eof()) {
        exit(0);
    }
    return command;
}
