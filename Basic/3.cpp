#include <cmath>

int main() {
	float REQUIRED_BEANS = pow(2, 64) - 1;
	unsigned long long AVERAGE_COLLECTION_BEANS = 7E7 /* тонны */ * 1000 /* кг */ * 1000 /* г */ * 10 /* зерен в г */;

	int years = ceil(REQUIRED_BEANS / AVERAGE_COLLECTION_BEANS);

	return 0;
}
