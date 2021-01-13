// 23_test

#include <cstdlib>
#include <iostream>
#include <cmath>

#define TESTED_FUNC solution
#define TESTED_FUNC_RTYPE int
#include "test.h"

using namespace std;

const int MAX_ARRAY_SIZE = 1000;

int solution(int *numbers, int n_nums) {
	int max_streak = 0, streak = 1;
	bool last_positive = numbers[0] > 0;

	for (int i = 1; i < n_nums; i++, streak++) {
		bool this_positive = numbers[i] > 0;

		if (this_positive == last_positive || numbers[i] == 0) {
			if (max_streak < streak)
				max_streak = streak;
			streak = 0;
		}

		last_positive = this_positive;
	}
	if (max_streak < streak)
		max_streak = streak;

	return max_streak;
}

int main() {
	int _1[] = { 1, -1, 1 };
	TEST(3, _1, 3);

	int _2[] = { 1, 1, 1 };
	TEST(1, _2, 3);

	int _3[] = { 0, 0, 0 };
	TEST(1, _3, 3);

	int _4[] = { 1, 0, -1 };
	TEST(1, _4, 3);

	int _5[] = { 1, 1, -2 };
	TEST(2, _5, 3);

	int _6[] = { 1, -1 };
	TEST(2, _6, 2);

	int _7[] = { 1 };
	TEST(1, _7, 1);

	int _8[] = { 1, 1, 0, -1, 1, -1 };
	TEST(3, _8, 6);

	std::system("pause");
}