// 7 test

#define TESTED_FUNC find
#define TESTED_FUNC_RTYPE std::string
#include "test.h"

#include <climits>
#include <cmath>
#include <string>

std::string find(int n) {
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

	return std::to_string(min_p) + " " + std::to_string(min_q);
}

int main() {
	TEST("1 1", 2);
	TEST("3 4", 25);
	TEST("30 41", 2581);
	TEST("2 2", 9);
	TEST("60 80", 9999);
	TEST("534 777", 888888);
	TEST("600 800", 1000000);
	system("pause");
}
