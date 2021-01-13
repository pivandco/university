// 9.2 : 23 - сдать

#include <iostream>
#include <iomanip>
#include "utils.h"

#define MAX_SUBJECT_NAME_LENGTH 20
#define MIN_GRADE 2
#define MAX_GRADE 5

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

    int n_students = input("Количество студентов", 1),
		n_subjects = input("Количество предметов", 1);

	int **grades = new int*[n_students];
	for (int i = 0; i < n_students; i++) {
		grades[i] = new int[n_subjects];
	}

	char **subject_names = new char*[n_subjects];
	for (int i = 0; i < n_subjects; i++) {
		subject_names[i] = new char[MAX_SUBJECT_NAME_LENGTH + 1]; // +1 для \0
	}

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
    double *averages = new double[n_subjects]{0};
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

	delete[] averages;

	for (int i = 0; i < n_students; i++) {
		delete[] grades[i];
	}
	delete[] grades;

	for (int i = 0; i < n_subjects; i++) {
		delete[] subject_names[i];
	}
	delete[] subject_names;

    system("pause");
    return 0;
}