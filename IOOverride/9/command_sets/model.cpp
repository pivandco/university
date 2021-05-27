#include "model.hpp"

#include "_util.hpp"

using std::cin, std::cout, std::endl;
using std::out_of_range;
using std::string;

CommandSet command_sets::MODEL = {
    {
        "journal print", {
            "Печатает название журнала, названия и даты занятий.",
            [] (AppState &app) {
                require_journal_to_be_open(app.journal_file);
                cout << app.journal_file->get_journal().to_string();
            }
        }
    },
    {
        "lesson print", {
            "Печатает название, тему занятия, а также оценки, выставленные на нем.",
            [] (AppState &app) {
                require_journal_to_be_open(app.journal_file);
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
                require_journal_to_be_open(app.journal_file);

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
