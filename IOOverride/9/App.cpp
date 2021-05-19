#include "App.hpp"

#include <iostream>

#include "commands.hpp"

using std::cin, std::cout;
using std::endl;
using std::out_of_range;
using std::string;

void App::command_loop() {
    while (true) {
        CommandCallback callback = ask_command();
        callback(state);
    }
}

static CommandCallback ask_command() {
    string cmd_str = ask_command_string();
    CommandCallback callback = nullptr;
    while (!callback) {
        try {
            callback = COMMANDS.at(cmd_str.c_str());
        } catch (out_of_range) {
            cout << "Неизвестная команда: " << cmd_str << endl;
        }
    }
    return callback;
}

static string ask_command_string() {
    cout << "> ";
    string command;
    cin >> command;
    return command;
}