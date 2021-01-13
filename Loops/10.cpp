// 10

#include <iostream>
#include <ctime>

using namespace std;

const int ARRAY_SIZE = 10000;

int main() {
	setlocale(LC_ALL, "Russian");

	int nums[ARRAY_SIZE];

	int n_nums;
	do {
		cout << "Количество чисел (1 - " << ARRAY_SIZE << "): ";
		cin >> n_nums;
	} while (n_nums > ARRAY_SIZE || n_nums < 1);

	srand(time(0));
	for (int i = 0; i < n_nums; i++) {
		nums[i] = rand() % 10;
		cout << nums[i] << " ";
	}

	int product = nums[n_nums - 1];
	int i = n_nums - 1;

	if (nums[i] != 0)
	for (i = n_nums - 2; i >= 0 && nums[i] != 0; i--) {
		product *= nums[i];
	}

	cout << endl << "Произведение: " << product << endl;

	system("pause");
	return 0;
}