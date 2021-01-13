// 10_test

#include <iostream>
#include <ctime>

#define TESTED_FUNC solution
#define TESTED_FUNC_RTYPE int
#include "test.h"

using namespace std;

int solution(int n_nums, int *nums) {
	int product = nums[n_nums - 1];
	int i = n_nums - 1;

	if (nums[i] != 0)
		for (i = n_nums - 2; i >= 0 && nums[i] != 0; i--) {
			product *= nums[i];
		}

	return product;
}

int main() {
	int _123[] = { 1, 2, 3 };
	TEST(6, 3, _123);

	int _120[] = { 1, 2, 0 };
	TEST(0, 3, _120);

	int _000[] = { 0, 0, 0 };
	TEST(0, 3, _000);

	int _105[] = { 1, 0, 5 };
	TEST(5, 3, _105);

	int _042[] = { 0, 4, 2 };
	TEST(8, 3, _042);

	int _0[] = { 0 };
	TEST(0, 1, _0);

	system("pause");
}