// 10

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <clocale>

using namespace std;

const int MAX_ARRAY_SIZE = 100;
const char const * NUM_FORMAT = "%8.2f";

int main() {
	setlocale(LC_ALL, "Russian");

	double src_array[MAX_ARRAY_SIZE], dest_array[MAX_ARRAY_SIZE];

	int n_nums;
	do {
		cout << "Количество чисел: ";
		cin >> n_nums;
	} while (n_nums > MAX_ARRAY_SIZE || n_nums < 1);

	// Заполнение случ. числами
	srand(time(0));
	for (int i = 0; i < n_nums; i++)
		src_array[i] = ((double)rand() / RAND_MAX) * (45 + 25) - 45;

	cout << "Исходный массив:" << endl;
	for (int i = 0; i < n_nums; i++)
		printf(NUM_FORMAT, src_array[i]);
	cout << endl;

	double x;
	do {
		cout << "X: ";
		cin >> x;
	} while (x >= 0 || x <= -45);

	// Выбор чисел, соотв. условию
	int dest_len = 0;
	for (int i = 0; i < n_nums; i++)
	if (src_array[i] < 0 && src_array[i] > x)
		dest_array[dest_len++] = src_array[i];

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
				if (dest_array[j] < dest_array[j + 1])
				{
					double temp = dest_array[j];
					dest_array[j] = dest_array[j + 1];
					dest_array[j + 1] = temp;
					swapped = true;
				}
			}

			if (!swapped)
				break;
		}

		for (int i = 0; i < dest_len; i++)
			printf(NUM_FORMAT, dest_array[i]);
		cout << endl;
	}

	system("pause");
	return 0;
}