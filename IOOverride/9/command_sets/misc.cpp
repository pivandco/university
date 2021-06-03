#include "misc.hpp"

#include "_util.hpp"

using std::cout, std::endl;

CommandSet command_sets::MISC = {
    {
        "help", {
            "Выводит список доступных команд и их описание.",
            [] (AppState &app) {
                for (auto &[cmd_name, cmd] : get_command_registry().commands()) {
                    cout << cmd_name << " - " << cmd.help << endl;
                }
            }
        }
    },
    {
        "exit", {
            "Выход из программы.",
            [] (AppState &app) {
                if (!check_file_saved(app.journal_file)) {
                    return;
                }
                exit(0);
            }
        }
    },
    {
        "exit!", {
            "Принудительный выход из программы.",
            [] (AppState &app) {
                exit(0);
            }
        }
    },
};
