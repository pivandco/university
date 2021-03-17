#pragma once

#include <iostream>

template<typename T>
T input(const char *prompt, T min, bool exclusive = false) {
    int in;
    do {
        std::cout << prompt << " (�� " << min << "): ";
        std::cin >> in;
    } while (in < min);
    return in;
}

template<typename T>
T input(const char *prompt, T min, T max, bool exclusive = false) {
    int in;
    do {
        std::cout << prompt << " (" << min << " - " << max << "): ";
        std::cin >> in;
    } while (in > max || in < min);
    return in;
}

// ���������� ��������� ����� � �������� ��������� (������������).
// �����
template<typename T>
T rand_range(T from, T to) {
    return rand() % (to - from + 1) + from;
}

double rand_range(double from, double to) {
    return ((double)rand() / RAND_MAX) * (to - from) + from;
}
