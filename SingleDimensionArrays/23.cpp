// 23

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main() {
	const int MAX_ARRAY_SIZE = 1000;

	setlocale(LC_ALL, "Russian");

	int numbers[MAX_ARRAY_SIZE];

	int n_nums;
	do {
		cout << "Количество чисел: ";
		cin >> n_nums;
	} while (n_nums > MAX_ARRAY_SIZE || n_nums < 1);

	srand(time(0));
	cout << "Числа: ";
	for (int i = 0; i < n_nums; i++) {
		numbers[i] = rand() % 11 - 5;
		cout << numbers[i] << " ";
	}
	cout << endl;

	int max_streak = 0, max_streak_last_i = n_nums, streak = 1;

	cout << "Длина макс. послед.: ";

	bool last_positive = numbers[0] > 0;

	for (int i = 1; i < n_nums; i++, streak++) {
		bool this_positive = numbers[i] > 0;

		if (this_positive == last_positive || numbers[i] == 0) {
			if (max_streak < streak) {
				// Записываем рекорд
				max_streak = streak;
				// Запоминаем, где эта последовательность
				max_streak_last_i = i;
			}
			streak = 0;  // Сброс последовательности
		}

		last_positive = this_positive;
	}
	if (max_streak < streak)
		max_streak = streak;

	cout << max_streak << endl;

	if (max_streak == 1)
		cout << max_streak_last_i << "-й элемент:" << endl;
	else
		cout << "С " << max_streak_last_i - max_streak + 1 << "-й по " << max_streak_last_i << "-й элемент:" << endl;

	for (int i = max_streak_last_i - max_streak; i < max_streak_last_i; i++)
		cout << numbers[i] << " ";
	cout << endl << endl;

	system("pause");
	return 0;
}