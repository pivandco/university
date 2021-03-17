// 10.7

#include <windows.h>
#include <iostream>
#include <string.h>
#include <strings.h>
#include "utils.h"

#define LINE_LENGTH 80
#define DELIMITERS ",. \n"

bool word_matches(const char *word) {
    const char *VOWELS = "ауоыиэяюёе";

    int word_length = strlen(word),
        vowels = 0;
    for (int i = 0; i < word_length; i++) {
        if (strchr(VOWELS, tolower(word[i])))
            vowels++;
    }
    
    return word_length - vowels > vowels;
}

bool is_word_in_array(char **arr, int len, char *word) {
    for (int i = 0; i < len; i++)
        if (!strcasecmp(arr[i], word))
            return true;
    return false;
}

int word_sorter(const void *a, const void *b) {
    int diff = 0;
    char *word_a = *((char**)a),
         *word_b = *((char**)b);

    for (int i = 0; !diff && word_a[i] && word_b[i]; i++)
        diff = tolower(word_a[i]) - tolower(word_b[i]);

    return diff;
}

void get_words(char *text, char **& matching_words, int &matching_words_count) {
    char *word = strtok(text, DELIMITERS);
    matching_words = nullptr;
    matching_words_count = 0;

    do {
        if (word_matches(word) && !is_word_in_array(matching_words, matching_words_count, word)) {
            matching_words = (char**)realloc(matching_words, ++matching_words_count * sizeof(char*));
            matching_words[matching_words_count - 1] = word;
        }
    } while(word = strtok(nullptr, DELIMITERS));
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n = input("Количество строк", 2, 10);
    std::cin.ignore(INT32_MAX, '\n');

    char *text = (char*)calloc(LINE_LENGTH * n + 1, sizeof(char));
    for (int i = 0; i < n; i++) {
        std::cout << "> ";
        char new_line[LINE_LENGTH + 1];
        std::cin.getline(new_line, LINE_LENGTH);
        strcat(text, "\n");
        strcat(text, new_line);
    }

    char **matching_words = nullptr;
    int matching_words_count = 0;
    get_words(text, matching_words, matching_words_count);
   
    if (!matching_words_count)
        std::cout << "Нет подходящих слов" << std::endl;
    else {
        qsort(matching_words, matching_words_count, sizeof(char*), word_sorter);

        std::cout << std::endl;
        for (int i = 0; i < matching_words_count; i++)
            std::cout << matching_words[i] << ' ';
        std::cout << std::endl;
    }

    free(matching_words);
    free(text);

    system("pause");
    return 0;
}