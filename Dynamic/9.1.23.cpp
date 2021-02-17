// 9.1 : 23

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>
#include "utils.h"

#define CPP_DYNAMIC
#define BASE_INDEX 10

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int n_nums = input("Количество чисел", 1);

#ifdef CPP_DYNAMIC
    int *numbers = new int[n_nums] - BASE_INDEX;
#else
    int *numbers = (int *)calloc(n_nums, sizeof(int)) - BASE_INDEX;
#endif

	// int now = 1608705259;
	// int now = 1613370784;
	int now = time(0);
	// cout << now << endl;
	srand(now);

	cout << "Числа: ";
	for (int i = 0; i < n_nums; i++) {
		numbers[i + BASE_INDEX] = rand_range(-5, 5);
		cout << numbers[i + BASE_INDEX] << " ";
	}
	cout << endl;

	int max_streak = 0, max_streak_last_i = n_nums, streak = 1;

	bool last_positive = numbers[BASE_INDEX] > 0,
	     last_negative = numbers[BASE_INDEX] < 0;

	for (int i = 1; i < n_nums; i++, streak++) {
		bool this_positive = numbers[i + BASE_INDEX] > 0,
		     this_negative = numbers[i + BASE_INDEX] < 0;

		if (this_positive == last_positive || this_negative == last_negative) {
			if (max_streak < streak) {
				// Записываем рекорд
				max_streak = streak;
				// Запоминаем, где эта последовательность
				max_streak_last_i = i;
			}
			streak = 0;  // Сброс последовательности
		}

		last_positive = this_positive;
		last_negative = this_negative;
	}
	if (max_streak < streak) {
		max_streak = streak;
		max_streak_last_i = n_nums + BASE_INDEX;
	}

	cout << "Длина макс. послед.: "
	     << max_streak << endl;

	if (max_streak == 1)
		cout << max_streak_last_i - BASE_INDEX << "-й элемент:" << endl;
	else
		cout << "С " << max_streak_last_i - max_streak + 1 
		     << "-й по " << max_streak_last_i << "-й элемент:" << endl;

	for (int i = max_streak_last_i - max_streak; i < max_streak_last_i; i++)
		cout << numbers[i + BASE_INDEX] << " ";
	cout << endl << endl;

#ifdef CPP_DYNAMIC
    delete[] (numbers + BASE_INDEX);
#else
    free(numbers + BASE_INDEX);
#endif

	system("pause");
	return 0;
}