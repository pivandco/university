# Palindromes: 
# Do geese see God. Was it a car,
# or a cat I saw. Palindromes are often found.
# Do geese see God. Pack.

#include "stdafx.h"
#include <iostream>
#include <string.h>
using namespace std;

const int line_length = 80;


bool is_palindrome(char* sentence) {
	int length = strlen(sentence), k = 0;
	char* tmp = (char*)calloc(length + 1, sizeof(char));

	for (int i = 0; i < length; i++)
		if (isalpha(sentence[i])) { tmp[k] = sentence[i]; k++; }
	length = strlen(tmp);

	for (int i = 0; i < length; i++)
		if (tolower(tmp[i]) != tolower(tmp[length - i - 1])) { 
			free(tmp); 
			return false; 
		}
	free(tmp);

	return true;
}

bool is_duplicate(char** arr, char* sentence, int length) {
	for (int i = 0; i < length; i++)
		if (!strcmp(arr[i], sentence))
			return true;
	return false;
}

void get_sentences(char* text, char**& sentences, int& sentence_count) {
	char* sentence = strtok(text, "!?.");
	do
	{
		if (is_palindrome(sentence) && !is_duplicate(sentences, sentence, sentence_count))
		{
			sentences = (char**)realloc(sentences, ++sentence_count * sizeof(char*));
			sentences[sentence_count - 1] = sentence;
		}
	} while (sentence = strtok(nullptr, "!?."));

}

int cmp(const void * p1, const void * p2) {
	char * s1 = *(char**)p1;
	char * s2 = *(char**)p2;
	if (strlen(s1) > strlen(s2)) return  1;
	if (strlen(s2) < strlen(s2)) return -1;
	return 0;
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
		char new_line[line_length + 1];
		cin.getline(new_line, line_length);
		strcat(text, "\n");
		strcat(text, new_line);
	}
	cout << endl;

	char** sentences = nullptr;
	int sentence_count = 0;
	get_sentences(text, sentences, sentence_count);

	if (sentence_count) cout << "Palindromes: ";
	else cout << "Palindromes not found" << endl;

	qsort(sentences, sentence_count, sizeof(char*), cmp);

	for (int i = 0; i < sentence_count; i++)
		cout << sentences[i] << endl;

	free(text);

	system("pause");

	return 0;
}