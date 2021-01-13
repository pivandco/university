// 23

#include <iostream>

int main() {
	setlocale(LC_ALL, "Russian");

	unsigned int n;
	std::cout << "Введите количество углов: ";
	std::cin >> n;

	double x_prev, y_prev;
	std::cout << "Введите координаты 1 вершины: ";
	std::cin >> x_prev >> y_prev;
	double x_first = x_prev, y_first = y_prev;
	unsigned int intersecting_edges = 0;

	double x, y;
	for (int i = 2; i <= n; i++) {
		std::cout << "Введите координаты " << i << " вершины: ";
		std::cin >> x >> y;
		if (y_prev * y <= 0)
			intersecting_edges++;
		x_prev = x;
		y_prev = y;
	}
	if (y * y_first <= 0)
		intersecting_edges++;

	std::cout << intersecting_edges << " ребер" << std::endl;

	system("pause");

	return 0;
}
