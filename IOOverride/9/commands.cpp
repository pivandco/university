#include "commands.hpp"

#include <fstream>
#include <iostream>

using std::cin, std::cout, std::endl;
using std::ifstream, std::ofstream;
using std::string;
using std::optional, std::make_optional;

/* #region Forward declarations */
static string ask_filename();
static bool check_file_saved(optional<ClassJournalFile> &);
/* #endregion */

const string FILE_NOT_OPEN = "Файл не открыт.\n";

const std::map<string, Command> COMMANDS = {
    {
        "help", {
            "Выводит список доступных команд и их описание.",
            [] (AppState &app) {
                for (auto &[cmd_name, cmd] : COMMANDS) {
                    cout << cmd_name << " - " << cmd.help << endl;
                }
            }
        }
    },
    {
        "new", {
            "Создает новый журнал.",
            [] (AppState &app) {
                string filename = ask_filename();
                if (filename.empty()) {
                    return;
                }
                app.journal_file.emplace(filename);
            }
        }
    },
    {
        "fileinfo", {
            "Выводит информацию о файле текущего открытого журнала.",
            [] (AppState &app) {
                if (!app.journal_file.has_value()) {
                    cout << FILE_NOT_OPEN;
                    return;
                }
                cout << "Имя файла:\t\t" << app.journal_file->name << endl
                     << "Несохр. изменения:\t" << (app.journal_file->has_unsaved_changes() ? "Да" : "Нет") << endl;
            }
        }
    },
    {
        "save", {
            "Сохраняет журнал в файл.",
            [] (AppState &app) {
                if (!app.journal_file.has_value()) {
                    cout << FILE_NOT_OPEN;
                    return;
                }
                app.journal_file->save();
            }
        }
    },
    {
        "close", {
            "Закрывает журнал.",
            [] (AppState &app) {
                if (!check_file_saved(app.journal_file)) {
                    return;
                }
                app.journal_file.reset();
            }
        }
    },
    {
        "close!", {
            "Принудительно закрывает журнал без сохранения.",
            [] (AppState &app) {
                app.journal_file.reset();
            }
        }
    },
    {
        "load", {
            "Загружает журнал из файла.",
            [] (AppState &app) {
                if (!check_file_saved(app.journal_file)) {
                    return;
                }
                string filename = ask_filename();
                if (filename.empty()) {
                    return;
                }
                ClassJournalFile file(filename);
                if (!file.exists_on_disk()) {
                    cout << "Файла не существует.";
                    return;
                }
                *app.journal_file = file;
            }
        }
    },
};

static string ask_filename() {
    cout << "Введите название файла или нажмите Enter для отмены\n>> ";
    string filename;
    getline(cin, filename);
    return filename;
}

static bool check_file_saved(optional<ClassJournalFile> &file) {
    if (!file.has_value()) {
        return true;
    }
    if (file->has_unsaved_changes()) {
        cout << "Есть несохраненные изменения.\nИспользуйте \"save\" для сохранения, или \"close!\" для принудительного закрытия.\n";
        return false;
    }
    return true;
}
