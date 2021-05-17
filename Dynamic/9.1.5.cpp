#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "");
	srand(time(NULL));

	const int baseIndex = -21;
	int n, k = 0;

	do
	{
		cout << "Введите кол-во элементов: ";
		cin >> n;
	} while (n < 1);

	double* arr1 = new double[n] - baseIndex;
	//double* arr1 = (double*)calloc(n, sizeof(double)) - baseIndex;

	double* finalArr = NULL;

	cout << fixed << setprecision(2);

	for (int i = 0; i < n; i++)
	{
		arr1[i + baseIndex] = (double)rand() / RAND_MAX * 8 - 4;
		cout << setw(6) << arr1[i + baseIndex];

		if (abs(arr1[i + baseIndex])>2) {
			finalArr = (double*)realloc(finalArr, (k + 1)* sizeof(double));
			finalArr[k] = arr1[i+baseIndex];
			k++;
		}
	}

	delete[](arr1 + baseIndex);
	//free (arr1+baseIndex);

	for (int i = 0; i < k; i++)
	{
		for (int j = i+1; j < k; j++)
		{
			if (finalArr[i] < finalArr[j])
			{
				double tmp = finalArr[i];
				finalArr[i] = finalArr[j];
				finalArr[j] = tmp;
			}
			
		}
	}
	cout << endl << "Результат: " << endl;

	for (int i = 0; i < k; i++)
	{
		cout << setw(6) << finalArr[i];
	}
	cout << endl;

	free(finalArr);

	system("pause");
	return 0;
}

