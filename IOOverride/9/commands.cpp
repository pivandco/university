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

const string FILE_NOT_OPEN = "���� �� ������.\n";

const std::map<string, Command> COMMANDS = {
    {
        "help", {
            "������� ������ ��������� ������ � �� ��������.",
            [] (AppState &app) {
                for (auto &[cmd_name, cmd] : COMMANDS) {
                    cout << cmd_name << " - " << cmd.help << endl;
                }
            }
        }
    },
    {
        "new", {
            "������� ����� ������.",
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
            "������� ���������� � ����� �������� ��������� �������.",
            [] (AppState &app) {
                if (!app.journal_file.has_value()) {
                    cout << FILE_NOT_OPEN;
                    return;
                }
                cout << "��� �����:\t\t" << app.journal_file->name << endl
                     << "������. ���������:\t" << (app.journal_file->has_unsaved_changes() ? "��" : "���") << endl;
            }
        }
    },
    {
        "save", {
            "��������� ������ � ����.",
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
            "��������� ������.",
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
            "������������� ��������� ������ ��� ����������.",
            [] (AppState &app) {
                app.journal_file.reset();
            }
        }
    },
    {
        "load", {
            "��������� ������ �� �����.",
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
                    cout << "����� �� ����������.";
                    return;
                }
                *app.journal_file = file;
            }
        }
    },
};

static string ask_filename() {
    cout << "������� �������� ����� ��� ������� Enter ��� ������\n>> ";
    string filename;
    cin >> filename;
    return filename;
}

static bool check_file_saved(optional<ClassJournalFile> &file) {
    if (!file.has_value()) {
        return true;
    }
    if (file->has_unsaved_changes()) {
        cout << "���� ������������� ���������.\n����������� \"save\" ��� ����������, ��� \"close!\" ��� ��������������� ��������.\n";
        return false;
    }
    return true;
}
