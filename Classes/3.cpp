// 12.3

#include <iostream>
#include <cstring>
#include <exception>

class String {
    friend std::ostream &operator<<(std::ostream &, const String &);
    friend String operator+(const String &, const String &);

public:
    String() = delete;

    String(size_t size) {
        str = (char *)calloc(size + 1, sizeof(char));
    }

    String(const char *source) : String(strlen(source)) {
        strcpy(str, source);
    }

    String(const String & other) : String(other.str) {}

    ~String() {
        free(str);
    }

    size_t size() const {
        return strlen(str);
    }

    char *find(const char *to_find) {
        return strstr(str, to_find);
    }

    bool replace_once(const char *from, const char *to) {
        char *from_ptr = find(from);
        if (!from_ptr)
            return false;

        // Размер заменяемой строки
        size_t from_size = strlen(from);
        // Размер строки на замену
        size_t to_size = strlen(to);
        // Новый размер строки после замены
        size_t new_size = size() - from_size + to_size;

        char *new_str = (char *)calloc(new_size + 1, sizeof(char));

        // Размер фрагмента строки от ее начала до индекса заменяемого участка
        size_t untouched_before_size = from_ptr - str;
        // Копируем нетронутый участок перед заменяемым
        memcpy(new_str, str, untouched_before_size);
        // Копируем новый фрагмент
        strcpy(new_str + untouched_before_size, to);
        // Копируем нетронутый участок после заменяемого
        strcat(new_str + untouched_before_size + to_size, from_ptr + from_size);

        free(str);
        str = new_str;

        return true;
    }

    void replace_all(const char *from, const char *to) {
        while (replace_once(from, to));
    }

    String slice(size_t from, size_t count) {
        if (from >= size() || from + count > size())
            throw std::out_of_range("out of range");

        String new_str(count + 1);
        memcpy(new_str.str, str + from, count);
        return new_str;
    }

    void remove(const char *target) {
        replace_all(target, "");
    }

    char &operator[](size_t index) {
        if (index >= size())
            throw std::out_of_range("out of range");
        return str[index];
    }

private:
    char *str;
};

std::ostream &operator<<(std::ostream &os, const String & str) {
    return os << str.str;
}

String operator+(const String &a, const String &b) {
    size_t this_size = a.size(), other_size = b.size();
    String new_string(a.size() + b.size());
    strcpy(new_string.str, a.str);
    strcat(new_string.str, b.str);

    return new_string;
}

using namespace std;

int main() {
    String test("aaabbbcccbbbeeebbbggg");

    cout << "Size of \"abc\":\t" << String("abc").size() << endl << endl;

    String test2("abcdef");
    cout << "slice(3, 3) of \"abcdef\":\t" << test2.slice(3, 3) << endl;
    try {
        cout << "slice(3, 4) of \"abcdef\":\t" << test2.slice(3, 4) << endl;
    } catch(std::out_of_range e) {
        cout << e.what() << endl;
    }

    cout << "String:\t" << test << endl;
    cout << "find(\"bbb\"):\t" << test.find("bbb") << endl;

    test.replace_once("bbb", "fff");
    cout << "replace_once(\"bbb\", \"fff\"):\t" << test << endl;

    test.replace_all("b", "s");
    cout << "replace_all(\"bbb\", \"sss\"):\t" << test << endl;

    test.remove("a");
    cout << "remove(\"a\"):\t" << test << endl;
    test.remove("s");
    cout << "remove(\"s\"):\t" << test << endl;

    cout << "test[5]:\t" << test[5] << endl;

    cout << "test[666]:\t";
    try {
        test[666];
    } catch(std::out_of_range e) {
        cout << e.what() << endl;
    }

    test[0] = 'z';
    cout << "test[0] = 'z':\t" << test << endl;

    String a("abc"), b("def");
    String c = a + b;
    cout << "\"abc\" + \"def\":\t" << c << endl;

    system("pause");

    return 0;
}
