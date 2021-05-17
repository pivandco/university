#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

bool check(int m, int* arr) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        if (arr[i] < arr[i + 1]) 
            sum += 1;
    }
    if (sum == m - 1)
        return true;
    return false;
}

int main() {
    setlocale(LC_ALL, "");
    srand(time(NULL));
    int baseIndex = 21, n, m;
    bool k = false;

    do {
        cout << "Введите кол-во фирм: ";
        cin >> n;
    } while (n <= 0);

    do {
        cout << "Введите кол-во месяцев: ";
        cin >> m;
    } while (m <= 1);

    /* int **arr = (int **) calloc(n, sizeof(int *)) - baseIndex;
     for (int i = 0; i < n; ++i) 
         arr[i + baseIndex] = (int *) calloc(m, sizeof(int)) - baseIndex;
    */

    int** arr = new int* [n] - baseIndex;
    for (int i = 0; i < n; ++i) 
        arr[i + baseIndex] = new int[m] - baseIndex;

    for (int i = 0; i < n; i++) {
        cout << setw(4) << i + 1 << "-фирма ";
        for (int j = 0; j < m; j++) {
            arr[i + baseIndex][j + baseIndex] = 1 + rand() % 100;
            cout << setw(4) << arr[i + baseIndex][j + baseIndex];
        }
       cout << endl;
    }

    cout << "Курс акций всё время повышался в:" << endl;

    for (int i = 0; i < n; i++)
        if (check(m, arr[i + baseIndex] + baseIndex))
        {
            cout << i + 1 << "-фирме" << endl;
            k = true;
        }
    if (!k)
        cout << "Ни в одной фирме";

    /*for (int i = 0; i < n; i++)
        free(arr[i + baseIndex] + baseIndex);
    free(arr + baseIndex);*/

    for (int i = 0; i < n; i++)
        delete[](arr[i+baseIndex] + baseIndex);
    delete[](arr + baseIndex);

    return 0;
}