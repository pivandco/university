// 7

#include <iostream>
#include <cmath>

int main() {
	int n;
	std::cout << "N: ";
	std::cin >> n;

	int min_absexpr = n, max_addendum = sqrt(n), min_q = 0, min_p = 0;

	for (int p = 1; p <= max_addendum; p++) {
		for (int q = p; q <= max_addendum; q++) {
			int absexpr = abs(n - pow(p, 2) - pow(q, 2));
			if (absexpr <= min_absexpr) {
				min_absexpr = absexpr;
				min_p = p;
				min_q = q;
			}
		}
	}

	std::cout
		<< "P: " << min_p << std::endl
		<< "Q: " << min_q << std::endl;

	system("pause");

	return 0;
}
