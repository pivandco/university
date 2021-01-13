// 23

#include <iostream>
#include <iomanip>
#include "input.h"

#define MAX_SUBJECTS 100
#define MAX_SUBJECT_NAME_LENGTH 20
#define MAX_STUDENTS 1000
#define MIN_GRADE 2
#define MAX_GRADE 5

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

    int grades[MAX_STUDENTS][MAX_SUBJECTS], 
		n_students = input("Количество студентов", 1, MAX_STUDENTS),
		n_subjects = input("Количество предметов", 1, MAX_SUBJECTS);
	char subject_names[MAX_SUBJECTS][MAX_SUBJECT_NAME_LENGTH + 1];  // +1 для \0

	for (int i = 0; i < n_subjects; i++) {
		cout << "Введите название " << i + 1 << " предмета (макс. " << MAX_SUBJECT_NAME_LENGTH << " символов): ";
		cin >> subject_names[i];
	}

	// Вывод названий предметов
    cout << setw(10) << "";  // Отступ
	for (int i = 0; i < n_subjects; i++) {
		cout << left << setw(MAX_SUBJECT_NAME_LENGTH) << subject_names[i];
	}
	cout << endl;

    // Генерация оценок
    srand(time(0));
    for (int i = 0; i < n_students; i++) {
		cout << left << setw(10) << string("Ст. ") + to_string(i + 1) + " |";
        for (int j = 0; j < n_subjects; j++) {
            grades[i][j] = rand() % (MAX_GRADE - MIN_GRADE + 1) + MIN_GRADE;
            cout << setw(MAX_SUBJECT_NAME_LENGTH) << grades[i][j];
        }
        cout << endl;
    }

    // Счет средних
    double averages[MAX_SUBJECTS] = {0};
    for (int i = 0; i < n_students; i++) {
        for (int j = 0; j < n_subjects; j++) {
            averages[j] += grades[i][j];
        }
        averages[i] /= n_students;
    }
    // Делим на кол-во студентов для получения среднего
    cout << "Средние оценки по предметам:" << endl << setw(10) << "";
    for (int i = 0; i < n_subjects; i++) {
        cout << setw(MAX_SUBJECT_NAME_LENGTH) << setprecision(2) << averages[i] << " ";
    }
    cout << endl << endl;

	// Узнаем максимальный
    double max_avg = averages[0];
    for (int i = 1; i < n_subjects; i++) {
        if (max_avg < averages[i])
            max_avg = averages[i];
    }
	cout << "Максимальный средний балл: " << max_avg << endl << "Предметы с макс. сред. баллом: ";

	// Выводим предметы с максимальными
	for (int i = 0; i < n_subjects; i++) {
		if (averages[i] == max_avg)
			cout << subject_names[i] << " ";
	}
	cout << endl << endl;

    system("pause");
    return 0;
}