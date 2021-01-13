// 9

#include <iostream>
#include <iomanip>
#include "utils.h"

#define MAX_NUMS 1000
#define RANGE_START 5
#define RANGE_END 25
#define RANGE_SIZE (RANGE_END - RANGE_START + 1)

using namespace std;

int count_repeats(int[], int, int);

int main() {
    setlocale(LC_ALL, "Russian");
    
    int nums[MAX_NUMS];
    int n_nums = input("Количество чисел", 1, MAX_NUMS);

    srand(time(0));
    for (int i = 0; i < n_nums; i++) {
        nums[i] = rand_range(RANGE_START, RANGE_END);
    }

    cout << "Массив:" << endl;
    for (int i = 0; i < n_nums; i++) {
        cout << nums[i] << " ";
    }
    cout << endl << endl;

    int repeats[RANGE_SIZE] = {0};

    // Подсчет повторений
    for (int i = 0; i < RANGE_SIZE; i++) {
        int num = i + RANGE_START;
        repeats[i] = count_repeats(nums, n_nums, num);
        cout << num << ": " << repeats[i] << " повторов" << endl;
    }
    cout << endl;

    // Поиск масимального количества повторов
    int max_repeats = 0;
    for (int i = 0; i < RANGE_SIZE; i++) {
        if (repeats[i] > max_repeats) {
            max_repeats = repeats[i];
        }
    }

    // Вывод
    cout << "Самые частые числа (" << max_repeats << " повторов): ";
    for (int i = 0; i < RANGE_SIZE; i++) {
        if (repeats[i] == max_repeats) {
            cout << i + RANGE_START << " ";
        }
    }
    cout << endl << endl;
    
    system("pause");
    return 0;
}

int count_repeats(int nums[], int n_nums, int num) {
    int repeats = 0;
    for (int i = 0; i < n_nums; i++) {
        if (nums[i] == num)
            repeats++;
    }
    return repeats;
}