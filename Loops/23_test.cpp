// 23_test

#include <iostream>

#define TESTED_FUNC solution
#define TESTED_FUNC_RTYPE int
#include "test.h"

using namespace std;

const unsigned long MAX_K = 1000000000;

int solution(unsigned long k) {
	unsigned int sum = 0;
	while (k > 0) {
		int n = k % 10;
		if (n % 2 == 0)
			sum += n;
		k /= 10;
	}

	return sum;
}

int main() {
	TEST(2, 123);
	TEST(12, 478);
	TEST(0, 777);
	TEST(0, 0);
	TEST(2, 2);

	system("pause");
}