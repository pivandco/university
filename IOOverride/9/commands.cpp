#include "commands.hpp"

const std::map<const char *, Command> COMMANDS = {
    {
        "new", {
            "������� ����� ������.",
            [] (AppState &app) {
                // TODO
            }
        }
    },
    {
        "load", {
            "��������� ������ �� �����.",
            [] (AppState &app) {
                // TODO
            }
        }
    },
};
