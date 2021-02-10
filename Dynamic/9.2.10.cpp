// 9.2 : 10

#include <iostream>
#include <iomanip>
#include <ctime>
#include "utils.h"

#define MIN_NUM 1
#define MAX_NUM 25
#define BASE_INDEX 1

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int n = input("Количество строк (N)", 1), m = input("Количество столбцов (M)", 1);
	
	int **table = (int **)calloc(n, sizeof(int *)) - BASE_INDEX;
	for (int i = BASE_INDEX; i < BASE_INDEX + n; i++) {
		table[i] = (int *)calloc(m, sizeof(int)) - BASE_INDEX;
	}

	// int **table = new int*[n] - BASE_INDEX;
	// for (int i = BASE_INDEX; i < BASE_INDEX + n; i++) {
	// 	table[i] = new int[m] - BASE_INDEX;
	// }
	
	// Заполнение
	cout << endl;
	srand(time(0));
	for (int i = BASE_INDEX; i < BASE_INDEX + n; i++) {
		for (int j = BASE_INDEX; j < BASE_INDEX + m; j++) {
			table[i][j] = rand_range(MIN_NUM, MAX_NUM);
			cout << setw(4) << table[i][j];
		}
		cout << endl;
	}
	cout << endl << endl;

	int max_sum, max_sum_row;
	for (int i = BASE_INDEX; i < BASE_INDEX + n; i++) {
		int row_sum = 0;
		for (int j = BASE_INDEX; j < BASE_INDEX + m; j++)
			row_sum += table[i][j];

		cout << "Сумма строки №" << i - BASE_INDEX + 1 << ": " << row_sum << endl;

		if (row_sum > max_sum || i == BASE_INDEX) {
			max_sum = row_sum;
			max_sum_row = i;
		}
	}

	cout << endl << "Строка №" << max_sum_row - BASE_INDEX + 1 
		 << " имеет наибольшую сумму (" << max_sum << ")" << endl << endl;

	for (int i = BASE_INDEX; i < BASE_INDEX + n; i++) {
		free(table[i] + BASE_INDEX);
	}
	free(table + BASE_INDEX);
	
	// for (int i = BASE_INDEX; i < BASE_INDEX + n; i++) {
	// 	delete[] (table[i] + BASE_INDEX);
	// }
	// delete[] (table + BASE_INDEX);

	system("pause");
	return 0;
}