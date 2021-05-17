#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int baseIndex = 21, n, m;

	do
	{
		cout << "Введите кол-во лыжников: ";
		cin >> n;
	} while (n < 0);

	do
	{
		cout << "Введите ко-во стартов: ";
		cin >> m;
	} while (m < 0);



	int** arr = (int**)calloc(n, sizeof(int*)) - baseIndex;
	for (int i = 0; i < n; i++)
	{
		arr[i + baseIndex] = (int*)calloc(m, sizeof(int)) - baseIndex;
	}

	/*int **arr = new int* [n] - baseIndex;
	for (int i = 0; i < n; i++)
	{
		arr[i + baseIndex] = new int[m] - baseIndex;
	}*/

	for (int i = 0; i < n; i++)
	{
		cout << setw(3) << i + 1 << " |";
		for (int j = 0; j < m; j++)
		{
			arr[i + baseIndex][j + baseIndex] = 1 + rand() % 2;
			cout << setw(4) << arr[i + baseIndex][j + baseIndex];
		}
		cout << endl;
	}

	cout << endl;
	int min_sum = INT32_MAX, num = 0;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < m; j++)
		{
			
			sum += arr[i + baseIndex][j + baseIndex];
		}

		cout << "Сумма " << i + 1 << " лыжника: " << sum << endl;

		if (sum < min_sum)
		{
			min_sum = sum;
			num = i;
		}
		else if (sum == min_sum && arr[i + baseIndex][m-1 + baseIndex] < arr[num + baseIndex][m-1 + baseIndex])
		{
			min_sum = sum;
			num = i;
		}
	}

	cout << endl << "Победил " << num + 1 << " лыжник со счётом " << min_sum;


	/*for (int i = 0; i < n; i++)
	{
		delete[] (arr[i + baseIndex] + baseIndex);
	}
	delete[](arr + baseIndex);*/

	for (int i = 0; i < n; i++)
	{
		free(arr[i + baseIndex] + baseIndex);
	}
	free(arr + baseIndex);

	return 0;
}
