// 10.23

#include <iostream>
#include <cstring>
#include "utils.h"

#define LINE_LENGTH 80 + 1
#define DELIMITERS ",. "

char **get_words(const char *str, int &n_words) {
    // Т. к. strtok портит принимаемую строку, используем копию
    char *str_copy = (char*)calloc(LINE_LENGTH, sizeof(char));
    strcpy(str_copy, str);

    // Копируем первое слово
    char **words_array = (char**)calloc(1, sizeof(char*));
    words_array[0] = (char*)calloc(LINE_LENGTH, sizeof(char));
    strtok(str_copy, DELIMITERS);
    strcpy(words_array[0], str_copy);
    n_words = 1;

    // Копируем следующие
    for (; str_copy = strtok(nullptr, DELIMITERS); n_words++) {
        words_array = (char**)realloc(words_array, sizeof(char *) * (n_words + 1));
        words_array[n_words] = (char*)calloc(LINE_LENGTH, sizeof(char));
        strcpy(words_array[n_words], str_copy);
    }

    return words_array;
}

char *encode(char *word) {
    
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n = input("Количество строк", 2, 10);
    std::cin.ignore(INT32_MAX, '\n');

    char **strings = (char**)calloc(n, sizeof(char*));
    for (int i = 0; i < n; i++) {
        strings[i] = (char*)calloc(LINE_LENGTH, sizeof(char));
        std::cout << "> ";
        std::cin.getline(strings[i], LINE_LENGTH);

        int n_words;
        char **words = get_words(strings[i], n_words);
    }

    system("pause");
    return 0;
}