// 9.1 : 10

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <clocale>
#include "utils.h"

#define BASE_INDEX -3

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int n_nums = input("Количество чисел", 1, 50000);
    double *src_array = new double[n_nums] - BASE_INDEX, *dest_array = nullptr;
    // double *src_array = (double *)calloc(n_nums, sizeof(double)) - BASE_INDEX, *dest_array = nullptr;

	// Заполнение случ. числами
	srand(time(0));
	for (int i = 0; i < n_nums; i++)
		src_array[BASE_INDEX + i] = rand_range(-45, 25);

	cout << "Исходный массив:" << endl;
	for (int i = 0; i < n_nums; i++)
        cout << setw(8) << setprecision(2) << src_array[BASE_INDEX + i];
	cout << endl;

	double x = input("X", -45, 0);

	// Выбор чисел, соотв. условию
	int dest_len = 0;
	for (int i = 0; i < n_nums; i++) {
        if (src_array[BASE_INDEX + i] < 0 && src_array[BASE_INDEX + i] > x) {
            dest_array = (double *)realloc(dest_array, (dest_len + 1) * sizeof(double));
            dest_array[dest_len++] = src_array[i];
        }
    }

    dest_array -= BASE_INDEX;

	if (dest_len == 0) {
		cout << "Нет соответствующих чисел" << endl;
	}
	else {
		// Сортировка
		bool swapped;
		for (int i = 0; i < dest_len - 1; i++)
		{
			swapped = false;
			for (int j = 0; j < dest_len - i - 1; j++)
			{
				if (dest_array[BASE_INDEX + j] < dest_array[BASE_INDEX + j + 1])
				{
					double temp = dest_array[BASE_INDEX + j];
					dest_array[BASE_INDEX + j] = dest_array[BASE_INDEX + j + 1];
					dest_array[BASE_INDEX + j + 1] = temp;
					swapped = true;
				}
			}

			if (!swapped)
				break;
		}

		for (int i = 0; i < dest_len; i++)
			cout << setw(8) << setprecision(2) << dest_array[BASE_INDEX + i];
		cout << endl;
	}

    delete[] (src_array + BASE_INDEX), (dest_array + BASE_INDEX);
    // free(src_array + BASE_INDEX);
    // free(dest_array + BASE_INDEX);

	system("pause");
	return 0;
}