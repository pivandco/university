#include "file.hpp"

#include "_util.hpp"

using std::string;
using std::cin, std::cout, std::endl;
using std::optional;

/* #region Forward declarations */
static void require_journal_to_be_open(AppState &);
static string ask_and_abort_if_empty(const string &);
static void confirm_overwrite();
static bool yes_no(const string &);
static bool char_is_y(char);
static bool char_is_n(char);
/* #endregion */

CommandSet command_sets::FILE = {
    {
        "fileinfo", {
            "Выводит информацию о файле текущего открытого журнала.",
            [] (AppState &app) {
                require_journal_to_be_open(app);
                cout << "Имя файла:\t\t" << app.journal_file->name << endl
                     << "Несохр. изменения:\t" << (app.journal_file->has_unsaved_changes() ? "Да" : "Нет") << endl;
            }
        }
    },
    {
        "new", {
            "Создает новый журнал.",
            [] (AppState &app) {
                string filename = ask_and_abort_if_empty("Название файла");

                ClassJournalFile file(filename);
                if (file.exists_on_disk()) {
                    confirm_overwrite();
                }
                string journal_name = ask_and_abort_if_empty("Название журнала");
                file.get_journal_and_mark_changed().name = journal_name;

                app.journal_file = file;
            }
        }
    },
    {
        "save", {
            "Сохраняет журнал в файл.",
            [] (AppState &app) {
                require_journal_to_be_open(app);
                app.journal_file->save();
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
                while (true) {
                    string filename = ask_and_abort_if_empty("Название файла");
                    ClassJournalFile file(filename);
                    if (!file.exists_on_disk()) {
                        cout << "Файла не существует.\n";
                        continue;
                    }
                    app.journal_file = file;
                    break;
                }
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
};

static void require_journal_to_be_open(AppState &app) {
    if (!app.journal_file.has_value()) {
        cout << "Файл не открыт.\n";
        throw CommandAborted();
    }
}

static string ask_and_abort_if_empty(const string &prompt) {
    cout << prompt << " (нажмите Enter для отмены)\n>> ";
    string input;
    getline(cin, input);
    if (input.empty()) {
        throw CommandAborted();
    }
    return input;
}

static void confirm_overwrite() {
    auto overwrite = yes_no("Файл уже есть на диске. Перезаписать?");
    if (!overwrite) {
        throw CommandAborted();
    }
}

static bool yes_no(const string &prompt) {
    cout << prompt << " [y/n] ";
    char input;
    do {
        cin >> input;
        cout << endl;
    } while (!char_is_y(input) && !char_is_n);
    return char_is_y(input);
}

static bool char_is_y(char c) {
    return c == 'y' || c == 'Y';
}

static bool char_is_n(char c) {
    return c == 'n' || c == 'N';
}
