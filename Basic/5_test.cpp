#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

const double ONE_MINUTE_DEG = 360.0 / 60;
const double ONE_HOUR_DEG = 360.0 / 12;
// Доп. смещение часовой стрелки от минут внутри часа
const double HOUR_1_MINUTE_OFFSET_DEG = ONE_HOUR_DEG / 60;

double calc_angle(int hours, int minutes) {
    double minute_angle = ONE_MINUTE_DEG * minutes;
    double hour_angle = ONE_HOUR_DEG * (hours % 12) + HOUR_1_MINUTE_OFFSET_DEG * minutes;

    double result = std::abs(minute_angle - hour_angle);
    if (result >= 180)
        result = 360 - result;
    return result;
}

void test();

int main() {
    int hour = 14, minute = 30;

    double angle = calc_angle(hour, minute);

    test();

    return 0;
}

/// Проверка решения по тестам в условии ///

struct TestData {
    int hour, minute;
    double correct_angle;
};
const TestData TEST_DATA[] = {
    {2, 43, 176.5},
    {11, 40, 110},
    {14, 30, 105},
    {0, 0, 0},
    {12, 0, 0},
    {23, 28, 176},

    {10, 2, 71},
    {19, 3, 166.5},
    {16, 40, 100},
    {12, 18, 99},
    {5, 47, 108.5},
    {18, 42, 51},
    {15, 29, 69.5},

    {16, 44, 122},
    {21, 10, 145.0},
    {15, 48, 174},
    {22, 59, 24.5},
    {11, 34, 143},
    {6, 52, 106.0},
    {13, 30, 135},

    {-1, -1, -1}  // Маркер - конец массива
};

void test() {
    TestData td;
    for (int i = 0;; i++) {
        td = TEST_DATA[i];
        if (td.hour == -1)
            break;

        std::cout << td.hour << ":" << td.minute << " == " << td.correct_angle << "\t[";
        double result = calc_angle(td.hour, td.minute);
        if (result == td.correct_angle) {
            std::cout << "ok]";
        } else {
            std::cout << "ERR (" << result << " != " << td.correct_angle << ")]";
        }
        std::cout << std::endl;
    }
}
