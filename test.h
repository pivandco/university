/*
 * ������������ ����� ��� ������������ ����� �� ����������������. (���� ����� assert?)
 *
 * ��� ������������:
 *
 * 1. ��������� �������� ������� � ��������� �������, ����������� ������� ������ �����������
 *    � ������������ �������� ������ (���� �������� ���������, ����� �������� ��� � std::tuple)
 * 2. � ������ ����� � �������� �������� ���:
 *
 *        #define TESTED_FUNC solution
 *        #define TESTED_FUNC_RTYPE int
 *        #include "test.h"
 *
 * 3. �������� "solution" �� �������� ������� � ��������, "int" - �� ��� ������������� ��������.
 * 4. ������� ������� main � ����� ���������:
 *
 *        int main() {
 *            TEST(4, 2, 2);
 *            TEST(2, 1, 1);
 *        }
 *
 *    ������ �������� � TEST - ���������� ��������, ��������� - ������� ������.
 *
 * 5. ���������. ��������� ���� �������� ���:
 *
 *        2, 2  [ok]
 *
 *    �����������:
 *
 *        ������� ������    ���������� �����
 *        vvvv              v
 *        3, 3  [ERR (10 != 6)]
 *                     ^
 *                     ��, ��� ����� ��� ��������
 *
 * ��� ����� #include "test.h" ����� ��������� #define TEST_STOP_ON_ERR , ����� ����� ������������ ����� ������ ������.
 */

#include <iostream>
#include <cstdarg>

#ifndef TESTED_FUNC_RTYPE
#error test.h: ��� #define TESTED_FUNC_RTYPE.
#include <__stop_compilation__>
#endif

#ifndef TESTED_FUNC
#error test.h: ��� #define TESTED_FUNC.
#include <__stop_compilation__>
#endif

#ifdef TEST_STOP_ON_ERR
#undef TEST_STOP_ON_ERR
#define TEST_STOP_ON_ERR true
#else
#define TEST_STOP_ON_ERR false
#endif

#define TEST(correct_result, ...) \
    { \
        TESTED_FUNC_RTYPE result = TESTED_FUNC(__VA_ARGS__); \
        std::cout << #__VA_ARGS__ << "\t["; \
        if (result == correct_result) \
            std::cout << "ok]" << std::endl; \
        else { \
            std::cout << "KALITAEV BABAH (" \
                << result << " != " << correct_result \
                << ")]" << std::endl; \
            if (TEST_STOP_ON_ERR) \
                exit(1); \
        } \
    }
