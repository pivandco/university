// 9.1 : 23

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>
#include "utils.h"

#define CPP_DYNAMIC
#define BASE_INDEX 100

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
	int now = 1613370784;
	// int now = time(0);
	cout << "Seed: " << now << endl;
	srand(now);

	cout << "Числа: ";
	for (int i = 0; i < n_nums; i++) {
		numbers[i + BASE_INDEX] = rand_range(-5, 5);
		cout << numbers[i + BASE_INDEX] << " ";
	}
	cout << endl;

	int streak = 0, max_streak = 0, max_streak_last_i;

	for (int i = 0; i < n_nums - 1; i++) {
		int this_num = numbers[i + BASE_INDEX], next_num = numbers[i + BASE_INDEX + 1];
		if (this_num == 0)
			continue;

		if (next_num != 0)
			streak++;

		if (this_num > 0 == next_num > 0 || next_num == 0) {	
			if (streak > max_streak) {
				max_streak = streak;
				streak = 0;
				max_streak_last_i = i + BASE_INDEX;
			}
		}
	}

	cout << "Длина макс. послед.: ";
	cout << max_streak << endl;

	if (max_streak == 1)
		cout << max_streak_last_i - BASE_INDEX << "-й элемент:" << endl;
	else
		cout << "С " << max_streak_last_i - max_streak - BASE_INDEX + 1 
		     << "-й по " << max_streak_last_i - BASE_INDEX << "-й элемент:" << endl;

	for (int i = max_streak_last_i - max_streak; i < max_streak_last_i; i++)
		cout << numbers[i] << " ";
	cout << endl << endl;

#ifdef CPP_DYNAMIC
    delete[] (numbers + BASE_INDEX);
#else
    free(numbers + BASE_INDEX);
#endif

	system("pause");
	return 0;
}