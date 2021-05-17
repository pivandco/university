#include <iostream>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    srand(time(NULL));

    const int nMax = 100, mMax = 150, baseIndex = -21;
    int n, m, k = 0;

    do {
        cout << "Введите кол-во чисел в 1 массиве (до " << nMax << "): ";
        cin >> n;
    } while (n < 1 || n > nMax);
    do {
        cout << "Введите кол-во чисел во 2 массиве (до " << mMax << "): ";
        cin >> m;
    } while (m < 1 || m > mMax);

    double* arr1 = new double[n] - baseIndex;
    double* arr2 = new double[m] - baseIndex;
    double* finalArr = NULL;

    /*double* arr1 = (double*)calloc(n, sizeof(double)) - baseIndex;
    double* arr2 = (double*)calloc(m, sizeof(double)) - baseIndex;
    double* finalArr = NULL;*/


    cout << "Значения первого массива: ";
    for (int i = 0; i < n; ++i) {
        arr1[baseIndex + i] = rand() % 100;
        
        cout << "[" << baseIndex + i << "] " << arr1[baseIndex + i] << " ";

        if ((baseIndex + i) % 2 == 0) {
            finalArr = (double*)realloc(finalArr, ++k * sizeof(double));
            finalArr[--k] = arr1[i+baseIndex];
            ++k;
        }
    }
    delete[](arr1 + baseIndex);
    //free(arr1 + baseIndex);
    cout << endl;

    cout << "Значения второго массива: ";
    for (int i = 0; i < m; ++i) {
        
        arr2[baseIndex + i] = rand() % 100;
        cout << "[" << baseIndex + i << "] " << arr2[baseIndex + i] << " ";

        if ((baseIndex + i) % 2 != 0) {
            finalArr = (double*)realloc(finalArr, ++k * sizeof(double));
            finalArr[--k] = arr2[baseIndex + i];
            ++k;
        }
    }
    cout << endl;
    delete[](arr2 + baseIndex);
    //free(arr2 + baseIndex);

    cout << "Значения третьего массива: ";
    for (int i = 0; i < k; ++i) {
        cout << finalArr[i] << " ";
    }

    delete[] finalArr;
    //free(finalArr);
 
    return 0;
}