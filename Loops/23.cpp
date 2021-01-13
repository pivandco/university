// 23

#include <iostream>

using namespace std;

const unsigned long MAX_K = 1000000000;

int main() {
	setlocale(LC_ALL, "Russian");

	unsigned long  long k;
	do {
		cout << "K (1 - 1 000 000 000): ";
		cin >> k;
	} while (k < 1 || k > MAX_K);

	unsigned int sum = 0;
	while (k > 0) {
		int n = k % 10;
		if (n % 2 == 0)
			sum += n;
		k /= 10;
	}

	cout << sum << endl;

	system("pause");
	return 0;
}