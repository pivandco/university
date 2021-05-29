#include "model.hpp"

#include "_util.hpp"

using std::cin, std::cout, std::endl;
using std::out_of_range, std::logic_error, std::invalid_argument;
using std::string;
using std::vector;

static const Lesson &select_lesson(const vector<Lesson> &lessons);
static Lesson &select_lesson(vector<Lesson> &lessons);
static int read_mark();
static Date read_date();

CommandSet command_sets::MODEL = {
    {
        "journal print", {
            "Печатает название журнала, названия и даты занятий.",
            [] (AppState &app) {
                require_journal_to_be_open(app.journal_file);
                cout << app.journal_file->get_journal().to_string() << endl;
            }
        }
    },
    {
        "lesson print", {
            "Печатает название, тему занятия, а также оценки, выставленные на нем.",
            [] (AppState &app) {
                require_journal_to_be_open(app.journal_file);
                cout << select_lesson(app.journal_file->get_journal().lessons).to_string_with_marks() << endl;
            }
        }
    },
    {
        "lesson add", {
            "Добваляет занятие.",
            [] (AppState &app) {
                require_journal_to_be_open(app.journal_file);

                Lesson lesson;

                cout << "Название занятия >> ";
                getline(cin, lesson.topic);
                lesson.date = read_date();
                app.journal_file->get_journal_and_mark_changed().lessons.push_back(lesson);
            }
        }
    },
    {
        "mark add", {
            "Добавляет оценки к занятию.", [] (AppState &app) {
                require_journal_to_be_open(app.journal_file);

                auto &marks = select_lesson(app.journal_file->get_journal_and_mark_changed().lessons).marks;

                while (true) {
                    string student;
                    cout << "Ученик (Enter - конец добавления) >> ";
                    getline(cin, student);
                    if (student.empty()) {
                        break;
                    }
                    int mark = read_mark();
                    marks[student] = mark;
                }
            }
        }
    }
};

static const Lesson &select_lesson(const vector<Lesson> &lessons) {
    while (true) {
        cout << "Номер занятия >> ";
        string lesson_id_str;
        getline(cin, lesson_id_str);
        try {
            int lesson_id = stoi(lesson_id_str);
            return lessons.at(lesson_id - 1);
        } catch(logic_error) {
            cout << "Неверный номер занятия: " << lesson_id_str << endl;
        }
    }
}

static Lesson &select_lesson(vector<Lesson> &lessons) {
    return const_cast<Lesson &>(select_lesson(const_cast<const vector<Lesson> &>(lessons)));
}

static Date read_date() {
    while (true) {
        cout << "Дата занятия в формате дд.мм.гггг >> ";
        string date_str;
        getline(cin, date_str);
        try {
            return Date::from_string(date_str);
            break;
        } catch (invalid_argument) {
            cout << "Неверная дата: " << date_str << endl;
        }
    }
}

static int read_mark() {
    while (true) {
        cout << "Оценка >> ";
        string mark_str;
        getline(cin, mark_str);
        int mark;
        try {
            mark = stoi(mark_str);
        } catch (invalid_argument) {
            cout << "Оценка должна быть числом\n";
            continue;
        }
        if (mark >= 2 && mark <= 5) {
            return mark;
        }
        cout << "Оценка может быть в интервале от 2 до 5\n";
    }
}
