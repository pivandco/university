// 10

#include <iostream>
#include <cmath>

int main() {
	setlocale(LC_ALL, "Russian");

	unsigned int n;
	std::cout << "Количество точек: ";
	std::cin >> n;

	double radius;
	std::cout << "Радиус: ";
	std::cin >> radius;

	unsigned int inside_both = 0, outside_both = 0;

	for (int i = 0; i < n; i++) {
		std::cout << "Координаты " << i + 1 << " точки: ";
		double x, y;
		std::cin >> x >> y;

		// Формула окружности
		bool in_circle = pow(x, 2) + pow(y, 2) <= pow(radius, 2);
		// Длина полустороны влож. квадрата
		double a = radius * sqrt(2) / 2;
		bool in_square = abs(x) <= a && abs(y) <= a;

		if (in_square)
			inside_both++;
		else if (!in_circle)
			outside_both++;
	}

	std::cout
		<< "Внутри обоих:\t" << inside_both << std::endl
		<< "Вне:\t" << outside_both << std::endl;

	system("pause");

	return 0;
}
