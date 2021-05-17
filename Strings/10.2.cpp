#include <iostream>
#include <iostream>
#include <string.h>
using namespace std;

const int line_length = 80;

char* first_word(char* sentence) {
	char* token = nullptr;
	return strtok_s(sentence, " ,", &token);
}

bool is_duplicate(char** arr, char* word, int length) {
	for (int i = 0; i < length; i++)
		if (!strcmp(arr[i], word))
			return true;
	return false;
}

void get_sentences(char* text, char**& words, int& word_count) {
	char* sentence = strtok(text, "!?.");
	char* word = nullptr;
	do
	{
		word = first_word(sentence);
		if (!is_duplicate(words, word, word_count))
		{
			words = (char**)realloc(words, ++word_count * sizeof(char*));
			words[word_count - 1] = word;
		}
	} while (sentence = strtok(nullptr, "!?."));

}

int cmp(const void* p1, const void* p2) {
	int diff = 0;
	char* s1 = *(char**)p1;
	char* s2 = *(char**)p2;
	for (int i = 0; !diff && s1[i] && s2[i]; i++)
		diff = tolower(s2[i]) - tolower(s1[i]);
	return diff;
}

int main()
{
	setlocale(LC_ALL, "");
	int n;
	do {
		cout << "Input the number of lines: ";
		cin >> n;
	} while (n < 2 || n > 10);
	cin.ignore(INT_MAX, '\n');


	char* text = (char*)calloc(line_length * n + 1, sizeof(char));
	for (int i = 0; i < n; i++) {
		char* new_line = (char*)calloc(line_length + 1, sizeof(char*));
		cin.getline(new_line, line_length);
		strcat(text, " ");
		strcat(text, new_line);
	}
	cout << endl;

	char** words = nullptr;
	int word_count = 0;
	get_sentences(text, words, word_count);

	qsort(words, word_count, sizeof(char*), cmp);

	for (int i = 0; i < word_count; i++)
		cout << words[i] << endl;

	free(text);
	free(words);

	system("pause");

	return 0;
}
