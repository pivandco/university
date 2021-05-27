#include "commands.hpp"

#include <fstream>
#include <iostream>

using std::cin, std::cout, std::endl;
using std::ifstream, std::ofstream;
using std::string;
using std::optional, std::make_optional;
using std::out_of_range;

/* #region Forward declarations */
static string ask_filename();
static bool check_file_saved(optional<ClassJournalFile> &);
/* #endregion */

const string FILE_NOT_OPEN = "Файл не открыт.\n";

#define RETURN_IF_JOURNAL_NOT_OPEN() \
    if (!app.journal_file.has_value()) { \
        cout << FILE_NOT_OPEN; \
        return; \
    }

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

                ClassJournalFile file(filename);
                if (file.exists_on_disk()) {
                    // TODO: ДАНЕТ?
                }
                cout << "Название журнала >> ";
                getline(cin, file.get_journal_and_mark_changed().name);

                app.journal_file = file;
            }
        }
    },
    {
        "fileinfo", {
            "Выводит информацию о файле текущего открытого журнала.",
            [] (AppState &app) {
                RETURN_IF_JOURNAL_NOT_OPEN()
                cout << "Имя файла:\t\t" << app.journal_file->name << endl
                     << "Несохр. изменения:\t" << (app.journal_file->has_unsaved_changes() ? "Да" : "Нет") << endl;
            }
        }
    },
    {
        "save", {
            "Сохраняет журнал в файл.",
            [] (AppState &app) {
                RETURN_IF_JOURNAL_NOT_OPEN()
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
    {
        "load", {
            "Загружает журнал из файла.",
            [] (AppState &app) {
                if (!check_file_saved(app.journal_file)) {
                    return;
                }
                while (true) {
                    string filename = ask_filename();
                    if (filename.empty()) {
                        return;
                    }
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
        "journal print", {
            "Печатает название журнала, названия и даты занятий.",
            [] (AppState &app) {
                RETURN_IF_JOURNAL_NOT_OPEN()
                cout << app.journal_file->get_journal().to_string();
            }
        }
    },
    {
        "lesson print", {
            "Печатает название, тему занятия, а также оценки, выставленные на нем.",
            [] (AppState &app) {
                RETURN_IF_JOURNAL_NOT_OPEN()
                while (true) {
                    cout << "Номер занятия >> ";
                    int lesson_id;
                    cin >> lesson_id;
                    try {
                        cout << app.journal_file->get_journal().lessons.at(lesson_id - 1).to_string_with_marks() << endl;
                        break;
                    } catch(out_of_range) {
                        cout << "Неверный номер занятия: " << lesson_id << endl;
                    }
                }
            }
        }
    },
    {
        "lesson add", {
            "Добваляет занятие.",
            [] (AppState &app) {
                RETURN_IF_JOURNAL_NOT_OPEN()

                Lesson lesson;

                // аааааАААААААААА
                // ПРИШЛО ВРЕМЯ РЕФАААААКТОРИИИИИИТЬ
                // КОД САМ СЕБЯ НЕ ОТРЕФАКТОРИТ
                // ОТРЕФАКТОРЬ ЕГО ЕЩЕ РАЗ
                // https://www.youtube.com/watch?v=AtaeWm8Am6Y
                cout << "Название занятия >> ";
                getline(cin, lesson.topic);
                while (true) {
                    cout << "Дата занятия в формате дд.мм.гггг >>";
                    string date_str;
                    getline(cin, date_str);
                    try {
                        lesson.date = Date::from_string(date_str);
                        break;
                    } catch (BadDateException) {
                        cout << "Неверная дата: " << date_str << endl;
                    }
                }
                app.journal_file->get_journal_and_mark_changed().lessons.push_back(lesson);
            }
        }
    }
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
