// 10.7

#include <windows.h>
#include <iostream>
#include <cstring>
#include "utils.h"

#define LINE_LENGTH 80
#define DELIMITERS ",. "

const char *VOWELS = "ауоыиэяюёеАУОЫИЭЯЮЁЕ";

int count_vowels(const char *word) {
    int word_length = strlen(word),
        vowels = 0;
    for (int i = 0; i < word_length; i++) {
        if (strchr(VOWELS, word[i]))
            vowels++;
    }
    return vowels;
}

void process_text(const char *text, char *words) {
    char *text_copy = (char*)calloc(strlen(text), sizeof(char));
    char *word = strtok(text_copy, DELIMITERS);

    do {
        int vowels = count_vowels(word),
            consonants = strlen(word) - vowels;

        if (consonants > vowels) {
            strcat(words, word);
        }
    } while(word = strtok(nullptr, DELIMITERS));

    free(text_copy);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n = input("Количество строк", 2, 10);
    std::cin.ignore(INT32_MAX, '\n');

    char *text = (char*)calloc(LINE_LENGTH * n + 1, sizeof(char));
    for (int i = 0; i < n; i++) {
        std::cout << "> ";
        char new_line[LINE_LENGTH + 1];
        std::cin.getline(new_line, LINE_LENGTH);
        strcat(text, " ");
        strcat(text, new_line);
    }

    char *words = (char*)calloc(LINE_LENGTH * n + 1, sizeof(char));
    process_text(text, words);
    std::cout << std::endl << words << std::endl;

    free(words);
    free(text);

    system("pause");
    return 0;
}