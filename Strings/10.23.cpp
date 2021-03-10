// 10.23

#include <windows.h>
#include <iostream>
#include <cstring>
#include "utils.h"

#define LINE_LENGTH 80
#define DELIMITERS ",. "

void process_word(char *word, size_t word_length, bool encode) {
    for (size_t i = 0; i < word_length; i++) {
        size_t shift = word_length % (i + 1) + 1;
        bool upper;
        upper = isupper(word[i]);
        word[i] = word[i] + shift * (encode ? 1 : -1);

        if (encode) {
            if (upper && word[i] > 'Я' || !upper && word[i] > 'я')
                word[i] -= 'Я' - 'А' + 1;
        } else {
            if (!upper && word[i] < 'А' || upper && word[i] < 'а')
                word[i] += 'Я' - 'А' + 1;
        }
    }
}

void process_line(char *line, bool encode = true) {
    if (!strlen(line)) return;

    char *line_copy = (char *)calloc(LINE_LENGTH, sizeof(char));
    strcpy(line_copy, line);

    char *word = strtok(line_copy, DELIMITERS);

    do {
        size_t word_length = strlen(word);
        process_word(word, word_length, encode);
        memcpy(line + (size_t)(word - line_copy), word, word_length);
    } while (word = strtok(nullptr, DELIMITERS));

    free(line_copy);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n = input("Количество строк", 2, 10);
    std::cin.ignore(INT32_MAX, '\n');

    char **lines = (char**)calloc(n, sizeof(char*));
    for (int i = 0; i < n; i++) {
        lines[i] = (char*)calloc(LINE_LENGTH + 1, sizeof(char));
        std::cout << "> ";
        std::cin.getline(lines[i], LINE_LENGTH);
    }

    std::cout << std::endl;

    for (int i = 0; i < n; i++) {
        process_line(lines[i]);
        std::cout << lines[i] << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < n; i++) {
        process_line(lines[i], false);
        std::cout << lines[i] << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < n; i++) {
        free(lines[i]);
    }
    free(lines);

    system("pause");
    return 0;
}