// 10_test

#include <cstdlib>
#include <functional>
#include <string>

#define TESTED_FUNC solution
#define TESTED_FUNC_RTYPE string
#include "test.h"

const int MAX_ARRAY_SIZE = 100;

using namespace std;

int cmp(const void *a, const void *b) {
	double da = *(double *)a, db = *(double *)b;
	if (da < db) return 1;
	if (da > db) return -1;
	return 0;
}

string solution(double x, double *array, int array_size) {
	string out = "";

	qsort(array, array_size, sizeof(double), cmp);

	for (int i = 0; i < array_size; i++) {
		if (array[i] < 0 && array[i] > x)
			out += to_string(array[i]) + " ";
	}

	return out;
}

int main() {
	double _1[] = { 10.0, -0.3, 20, -0.1, -0.2 };
	TEST("-0.100000 -0.200000 -0.300000 ", -0.4, _1, 5);
	TEST("-0.100000 -0.200000 ", -0.3, _1, 5);

	system("pause");
}