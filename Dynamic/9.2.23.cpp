// 9.2 : 23

#include <iostream>
#include <iomanip>
#include "utils.h"

#define MAX_SUBJECT_NAME_LENGTH 20
#define MIN_GRADE 2
#define MAX_GRADE 5

// #define CPP_DYNAMIC
#define BASE_INDEX 666

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

    int n_students = input("Количество студентов", 1),
		n_subjects = input("Количество предметов", 1);

#ifdef CPP_DYNAMIC
	int **grades = new int*[n_students] - BASE_INDEX;
	for (int i = 0; i < n_students; i++) {
		grades[i + BASE_INDEX] = new int[n_subjects] - BASE_INDEX;
	}

	char **subject_names = new char*[n_subjects] - BASE_INDEX;
	for (int i = 0; i < n_subjects; i++) {
		subject_names[i + BASE_INDEX] = new char[MAX_SUBJECT_NAME_LENGTH + 1] - BASE_INDEX; // +1 для \0
	}
#else
	int **grades = (int **)calloc(n_students, sizeof(int *)) - BASE_INDEX;
	for (int i = 0; i < n_students; i++) {
		grades[i + BASE_INDEX] = (int *)calloc(n_subjects, sizeof(int)) - BASE_INDEX;
	}

	char **subject_names = (char **)calloc(n_subjects, sizeof(char *)) - BASE_INDEX;
	for (int i = 0; i < n_subjects; i++) {
		subject_names[i + BASE_INDEX] = (char *)calloc(MAX_SUBJECT_NAME_LENGTH + 1, sizeof(char)) - BASE_INDEX; // +1 для \0
	}	
#endif
	for (int i = 0; i < n_subjects; i++) {
		cout << "Введите название " << i + 1 << " предмета (макс. " << MAX_SUBJECT_NAME_LENGTH << " символов): ";
		cin >> subject_names[i + BASE_INDEX] + BASE_INDEX;
	}

	// Вывод названий предметов
    cout << setw(10) << "";  // Отступ
	for (int i = 0; i < n_subjects; i++) {
		cout << left << setw(MAX_SUBJECT_NAME_LENGTH) << subject_names[i + BASE_INDEX] + BASE_INDEX;
	}
	cout << endl;

    // Генерация оценок
    srand(time(0));
    for (int i = 0; i < n_students; i++) {
		cout << left << setw(10) << string("Ст. ") + to_string(i + 1) + " |";
        for (int j = 0; j < n_subjects; j++) {
            grades[i + BASE_INDEX][j + BASE_INDEX] = rand() % (MAX_GRADE - MIN_GRADE + 1) + MIN_GRADE;
            cout << setw(MAX_SUBJECT_NAME_LENGTH) << grades[i + BASE_INDEX][j + BASE_INDEX];
        }
        cout << endl;
    }
    // Счет средних
#ifdef CPP_DYNAMIC
    double *averages = new double[n_subjects]{0} - BASE_INDEX;
#else
    double *averages = (double *)calloc(n_subjects, sizeof(double)) - BASE_INDEX;
#endif
    for (int i = 0; i < n_subjects; i++) {
        for (int j = 0; j < n_students; j++) {
            averages[i + BASE_INDEX] += grades[j + BASE_INDEX][i + BASE_INDEX];
        }
        averages[i + BASE_INDEX] /= (double)n_students;
    }
    // Делим на кол-во студентов для получения среднего
    cout << "Средние оценки по предметам:" << endl << setw(10) << "";
    for (int i = 0; i < n_subjects; i++) {
        cout << setw(MAX_SUBJECT_NAME_LENGTH) << setprecision(2) << averages[i + BASE_INDEX] << " ";
    }
    cout << endl << endl;

	// Узнаем максимальный
    double max_avg = averages[BASE_INDEX];
    for (int i = 1; i < n_subjects; i++) {
        if (max_avg < averages[i + BASE_INDEX])
            max_avg = averages[i + BASE_INDEX];
    }
	cout << "Максимальный средний балл: " << max_avg << endl << "Предметы с макс. сред. баллом: ";

	// Выводим предметы с максимальными
	for (int i = 0; i < n_subjects; i++) {
		if (averages[i + BASE_INDEX] == max_avg)
			cout << subject_names[i + BASE_INDEX] + BASE_INDEX << " ";
	}
	cout << endl << endl;

#ifdef CPP_DYNAMIC
	delete[] (averages + BASE_INDEX);

	for (int i = 0; i < n_students; i++) {
		delete[] (grades[i + BASE_INDEX] + BASE_INDEX);
	}
	delete[] (grades + BASE_INDEX);

	for (int i = 0; i < n_subjects; i++) {
		delete[] (subject_names[i + BASE_INDEX] + BASE_INDEX);
	}
	delete[] (subject_names + BASE_INDEX);
#else
	free(averages + BASE_INDEX);

	for (int i = 0; i < n_students; i++) {
		free(grades[i + BASE_INDEX] + BASE_INDEX);
	}
	free(grades + BASE_INDEX);

	for (int i = 0; i < n_subjects; i++) {
		free(subject_names[i + BASE_INDEX] + BASE_INDEX);
	}
	free(subject_names + BASE_INDEX);
#endif

    system("pause");
    return 0;
}