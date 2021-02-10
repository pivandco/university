// 9.2 : 23 - �����

#include <iostream>
#include <iomanip>
#include "utils.h"

#define MAX_SUBJECT_NAME_LENGTH 20
#define MIN_GRADE 2
#define MAX_GRADE 5

// #define CPP_DYNAMIC
#define BASE_INDEX 1

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

    int n_students = input("���������� ���������", 1),
		n_subjects = input("���������� ���������", 1);

#ifdef CPP_DYNAMIC
	int **grades = new int*[n_students] - BASE_INDEX;
	for (int i = BASE_INDEX; i < BASE_INDEX + n_students; i++) {
		grades[i] = new int[n_subjects] - BASE_INDEX;
	}

	char **subject_names = new char*[n_subjects] - BASE_INDEX;
	for (int i = BASE_INDEX; i < BASE_INDEX + n_subjects; i++) {
		subject_names[i] = new char[MAX_SUBJECT_NAME_LENGTH + 1] - BASE_INDEX; // +1 ��� \0
	}
#else
	int **grades = (int **)calloc(n_students, sizeof(int *)) - BASE_INDEX;
	for (int i = BASE_INDEX; i < BASE_INDEX + n_students; i++) {
		grades[i] = (int *)calloc(n_subjects, sizeof(int)) - BASE_INDEX;
	}

	char **subject_names = (char **)calloc(n_subjects, sizeof(char *)) - BASE_INDEX;
	for (int i = BASE_INDEX; i < BASE_INDEX + n_subjects; i++) {
		subject_names[i] = (char *)calloc(MAX_SUBJECT_NAME_LENGTH + 1, sizeof(char)) - BASE_INDEX; // +1 ��� \0
	}	
#endif

	for (int i = BASE_INDEX; i < BASE_INDEX + n_subjects; i++) {
		cout << "������� �������� " << i + 1 << " �������� (����. " << MAX_SUBJECT_NAME_LENGTH << " ��������): ";
		cin >> subject_names[i];
	}

	// ����� �������� ���������
    cout << setw(10) << "";  // ������
	for (int i = BASE_INDEX; i < BASE_INDEX + n_subjects; i++) {
		cout << left << setw(MAX_SUBJECT_NAME_LENGTH) << subject_names[i];
	}
	cout << endl;

    // ��������� ������
    srand(time(0));
    for (int i = BASE_INDEX; i < BASE_INDEX + n_students; i++) {
		cout << left << setw(10) << string("��. ") + to_string(i + 1) + " |";
        for (int j = BASE_INDEX; j < BASE_INDEX + n_subjects; j++) {
            grades[i][j] = rand() % (MAX_GRADE - MIN_GRADE + 1) + MIN_GRADE;
            cout << setw(MAX_SUBJECT_NAME_LENGTH) << grades[i][j];
        }
        cout << endl;
    }

    // ���� �������
#ifdef CPP_DYNAMIC
    double *averages = new double[n_subjects]{0} - BASE_INDEX;
#else
    double *averages = (double *)calloc(n_subjects, sizeof(double)) - BASE_INDEX;
#endif
    for (int i = BASE_INDEX; i < BASE_INDEX + n_students; i++) {
        for (int j = BASE_INDEX; j < BASE_INDEX + n_subjects; j++) {
            averages[j] += grades[i][j];
        }
        averages[i] /= n_students;
    }
    // ����� �� ���-�� ��������� ��� ��������� ��������
    cout << "������� ������ �� ���������:" << endl << setw(10) << "";
    for (int i = BASE_INDEX; i < BASE_INDEX + n_subjects; i++) {
        cout << setw(MAX_SUBJECT_NAME_LENGTH) << setprecision(2) << averages[i] << " ";
    }
    cout << endl << endl;

	// ������ ������������
    double max_avg = averages[BASE_INDEX];
    for (int i = BASE_INDEX + 1; i < BASE_INDEX + n_subjects; i++) {
        if (max_avg < averages[i])
            max_avg = averages[i];
    }
	cout << "������������ ������� ����: " << max_avg << endl << "�������� � ����. ����. ������: ";

	// ������� �������� � �������������
	for (int i = BASE_INDEX; i < BASE_INDEX + n_subjects; i++) {
		if (averages[i] == max_avg)
			cout << subject_names[i] << " ";
	}
	cout << endl << endl;

#ifdef CPP_DYNAMIC
	delete[] averages + BASE_INDEX;

	for (int i = BASE_INDEX; i < BASE_INDEX + n_students; i++) {
		delete[] grades[i] + BASE_INDEX;
	}
	delete[] grades + BASE_INDEX;

	for (int i = BASE_INDEX; i < BASE_INDEX + n_subjects; i++) {
		delete[] subject_names[i] + BASE_INDEX;
	}
	delete[] subject_names + BASE_INDEX;
#else
	free(averages + BASE_INDEX);

	for (int i = BASE_INDEX; i < BASE_INDEX + n_students; i++) {
		free(grades[i] + BASE_INDEX);
	}
	free(grades + BASE_INDEX);

	for (int i = BASE_INDEX; i < BASE_INDEX + n_subjects; i++) {
		free(subject_names[i] + BASE_INDEX);
	}
	free(subject_names + BASE_INDEX);
#endif

    system("pause");
    return 0;
}