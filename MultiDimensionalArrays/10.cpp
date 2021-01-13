// 10

#include <iostream>
#include <ctime>
#include "input.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	const int MAX_N = 100, MAX_M = 100, MIN_NUM = 0, MAX_NUM = 10;

	int table[MAX_N][MAX_M], n = input("Количество строк (N)", 1, MAX_N), m = input("Количество столбцов (M)", 1, MAX_M);

	// Заполнение
	printf("\n");
	srand(time(0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			table[i][j] = rand() % (MAX_NUM + 1 - MIN_NUM) + MIN_NUM;
			printf("%4d", table[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");

	int max_sum, max_sum_row;
	for (int i = 0; i < n; i++) {
		int row_sum = 0;
		for (int j = 0; j < m; j++)
			row_sum += table[i][j];

		printf("Сумма строки №%d: %d\n", i + 1, row_sum);

		if (row_sum > max_sum || i == 0) {
			max_sum = row_sum;
			max_sum_row = i;
		}
	}

	printf("\nСтрока №%d имеет наибольшую сумму (%d)\n\n", max_sum_row + 1, max_sum);

	system("pause");
	return 0;
}