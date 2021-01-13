/*
 * Велосипедный хедер для тестирования задач по программированию. (Кому нужны assert?)
 *
 * Как использовать:
 *
 * 1. Перенести алгоритм решения в отдельную функцию, принимающую входные данные параметрами
 *    и возвращающую выходные данные (если значений несколько, можно засунуть все в std::tuple)
 * 2. В начале файла с решением вставить код:
 *
 *        #define TESTED_FUNC solution
 *        #define TESTED_FUNC_RTYPE int
 *        #include "test.h"
 *
 * 3. Заменить "solution" на название функции с решением, "int" - на тип возвращаемого значения.
 * 4. Создать функцию main с кодом наподобие:
 *
 *        int main() {
 *            TEST(4, 2, 2);
 *            TEST(2, 1, 1);
 *        }
 *
 *    Первый аргумент у TEST - правильное значение, остальные - входные данные.
 *
 * 5. Запустить. Прошедший тест выглядит так:
 *
 *        2, 2  [ok]
 *
 *    Проваленный:
 *
 *        Входные данные    Правильный ответ
 *        vvvv              v
 *        3, 3  [ERR (10 != 6)]
 *                     ^
 *                     То, что выдал ваш алгоритм
 *
 * Еще перед #include "test.h" можно поместить #define TEST_STOP_ON_ERR , чтобы тесты прекращались после первой ошибки.
 */

#include <iostream>
#include <cstdarg>

#ifndef TESTED_FUNC_RTYPE
#error test.h: нет #define TESTED_FUNC_RTYPE.
#include <__stop_compilation__>
#endif

#ifndef TESTED_FUNC
#error test.h: нет #define TESTED_FUNC.
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
