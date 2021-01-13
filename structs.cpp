#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>
#include "input.h"

#define MAX_STUDENT_NAME_LENGTH 20
#define MAX_GRADES 100
#define MAX_STUDENTS 100
#define MAX_SUBJECTS 5
#define MAX_SUBJECT_NAME_LENGTH 20
#define DATE_COLUMN_WIDTH 20

using namespace std;

char subject_names[MAX_SUBJECTS][MAX_SUBJECT_NAME_LENGTH];
int n_students, n_subjects;

struct {
    char first_name[MAX_STUDENT_NAME_LENGTH], last_name[MAX_STUDENT_NAME_LENGTH];
    struct { 
        int day, month, year;

        void print() {
            char date_str[DATE_COLUMN_WIDTH];
            sprintf(date_str, "%02d.%02d.%d   ", day, month, year);
            cout << date_str;
        }

    } birth_date;
    int grades[MAX_GRADES];
} students[MAX_STUDENTS];

void subject_input() {
    n_subjects = input("Количество предметов", 3, MAX_SUBJECTS);

    for (int i = 0; i < n_subjects; i++) {
        cout << "Название предмета " << i + 1 << " (макс. " <<  MAX_SUBJECT_NAME_LENGTH << " симв.): ";
        cin >> subject_names[i];
    }
}

void student_input() {
    n_students = input("Количество студентов", 1, MAX_STUDENTS);

    for (int i = 0; i < n_students; i++) {
        cout << endl << "Ввод информации о студенте " << i + 1 << endl;

        cout << "Фамилия: ";
        cin >> students[i].last_name;

        cout << "Имя: ";
        cin >> students[i].first_name;

        do {
            cout << "Дата рождения (дд мм гггг): ";
            cin >> students[i].birth_date.day
                >> students[i].birth_date.month
                >> students[i].birth_date.year;
        } while(students[i].birth_date.day < 1 || students[i].birth_date.day > 31 || 
                students[i].birth_date.month < 1 || students[i].birth_date.month > 12 || 
                students[i].birth_date.year < 1900);

        for (int j = 0; j < n_subjects; j++) {
            char prompt[20 + MAX_SUBJECT_NAME_LENGTH];
            sprintf(prompt, "Оценка по предмету %s", subject_names[j]);
            students[i].grades[j] = input(prompt, 2, 5);
        }
    }
}

void print_grades_col_header() {
    cout << "Баллы (";

    for (int i = 0; i < n_subjects; i++) {
        cout << subject_names[i];
        if (i != n_subjects - 1) {
            cout << ", ";
        }
    }
    cout << ")";
}

void student_output() {
    cout << endl
         << setw(MAX_STUDENT_NAME_LENGTH) << "Фамилия"
         << setw(MAX_STUDENT_NAME_LENGTH) << "Имя"
         << setw(DATE_COLUMN_WIDTH)       << "Дата рождения   ";
    print_grades_col_header();
    cout << endl;

    for (int i = 0; i < n_students; i++) {
        cout << setw(MAX_STUDENT_NAME_LENGTH) << students[i].last_name
             << setw(MAX_STUDENT_NAME_LENGTH) << students[i].first_name
             << setw(20);
        students[i].birth_date.print();

        for (int j = 0; j < n_subjects; j++) {
            cout << students[i].grades[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Решение 10 задачи
void solve_10() {
    cout << "Не получили ни одной оценки \"Удовлетворительно\":" << endl << endl;

    bool have_matching = false;

    for (int i = 0; i < n_students; i++) {
        bool no_3s = true;
        for (int j = 0; j < n_subjects; j++) {
            if (students[i].grades[j] == 3) {
                no_3s = false;
                break;
            }
        }
        if (no_3s) {
            if (!have_matching) {
                cout << setw(MAX_STUDENT_NAME_LENGTH) << "Фамилия"
                     << setw(DATE_COLUMN_WIDTH) << "Дата рождения"
                     << endl;
                have_matching = true;
            }

            cout << setw(MAX_STUDENT_NAME_LENGTH) << students[i].last_name
                 << setw(DATE_COLUMN_WIDTH);
            students[i].birth_date.print();
            cout << endl;
        }
    }
    if (!have_matching)
            cout << "Никто" << endl;
    cout << endl;
}

// Решение 23 задачи
void solve_23() {
    bool have_matching = false;

    char matching[] = "BDE";
    cout << "Фамилии на ";
    for (int i = 0; i < strlen(matching); i++) {
        cout << "\"" << matching[i] << "\" ";
    }
    cout << ":" << endl << endl;

    for (int i = 0; i < n_students; i++) {
        bool matches = false;
        char first = toupper(students[i].last_name[0]);
        for (int j = 0; j < strlen(matching); j++) {
            if (first == matching[j]) {
                matches = true;
                break;
            }
        }
        if (matches) {
            if (!have_matching) {
                cout << setw(MAX_STUDENT_NAME_LENGTH) << "Фамилия" << ' ';
                print_grades_col_header();
                cout << endl;

                have_matching = true;
            }

            cout << setw(MAX_STUDENT_NAME_LENGTH) << students[i].last_name << " ";
            for (int j = 0; j < n_subjects; j++)
                cout << students[i].grades[j] << " ";
            cout << endl;
        }
    }
    if (!have_matching)
        cout << "Никто" << endl;

    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    subject_input();
    student_input();
    student_output();

    solve_10();
    solve_23();

    system("pause");
    return 0;
}