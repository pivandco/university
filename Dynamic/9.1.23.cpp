// 9.1 : 23

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>
#include "utils.h"

#define BASE_INDEX 1

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int n_nums = input("Количество чисел", 1);

    int *numbers = (int *)calloc(n_nums, sizeof(int)) - BASE_INDEX;
    // int *numbers = new int[n_nums] - BASE_INDEX;

	int now = 1608705259;
	// int now = time(0);
	cout << now << endl;
	srand(now);

	cout << "Числа: ";
	for (int i = BASE_INDEX; i < BASE_INDEX + n_nums; i++) {
		numbers[i] = rand_range(-5, 5);
		cout << numbers[i] << " ";
	}
	cout << endl;

	int max_streak = 0, max_streak_last_i = n_nums, streak = 1;

	cout << "Длина макс. послед.: ";

	bool last_positive = numbers[BASE_INDEX] > 0;

	for (int i = BASE_INDEX + 1; i < BASE_INDEX + n_nums; i++, streak++) {
		bool this_positive = numbers[i] > 0;

		if (this_positive == last_positive || numbers[i] == 0) {
			if (max_streak < streak) {
				// Записываем рекорд
				max_streak = streak;
				// Запоминаем, где эта последовательность
				max_streak_last_i = i;
			}
			streak = 0;  // Сброс последовательности
			if (numbers[i] == 0) {
				max_streak_last_i--;
				max_streak--;
			}
		}

		last_positive = this_positive;
	}
	if (max_streak < streak) {
		max_streak = streak;
		max_streak_last_i = n_nums + BASE_INDEX;
	}

	cout << max_streak << endl;

	if (max_streak == 1)
		cout << max_streak_last_i - BASE_INDEX << "-й элемент:" << endl;
	else
		cout << "С " << max_streak_last_i - max_streak - BASE_INDEX + 1 
		     << "-й по " << max_streak_last_i - BASE_INDEX << "-й элемент:" << endl;

	for (int i = max_streak_last_i - max_streak; i < max_streak_last_i; i++)
		cout << numbers[i] << " ";
	cout << endl << endl;

    free(numbers + BASE_INDEX);
    // delete[] (numbers + BASE_INDEX);

	system("pause");
	return 0;
}