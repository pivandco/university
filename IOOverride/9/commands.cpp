#include "commands.hpp"

const std::map<const char *, Command> COMMANDS = {
    {
        "new", {
            "Создает новый журнал.",
            [] (AppState &app) {
                // TODO
            }
        }
    },
    {
        "load", {
            "Загружает журнал из файла.",
            [] (AppState &app) {
                // TODO
            }
        }
    },
};
