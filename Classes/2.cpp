#include <iostream>
#include <cstring>
#include <exception>

class String;
std::ostream &operator<<(std::ostream &, String &);

class String {
    friend std::ostream &operator<<(std::ostream &, String &);

public:
    String(size_t size) {
        str = (char *)calloc(size + 1, sizeof(char));
    }

    String(const char *source) : String(strlen(source)) {
        strcpy(str, source);
    }

    String(String const & other) : String(other.str) {}

    ~String() {
        free(str);
    }

    size_t size() {
        return strlen(str);
    }

    char *find(const char *to_find) {
        return strstr(str, to_find);
    }

    bool replace_once(const char *from, const char *to) {
        char *from_ptr = find(from);
        if (!from_ptr)
            return false;

        size_t from_size = strlen(from), to_size = strlen(to);
        size_t new_size = size() - from_size + to_size;
        size_t untouched_before_size = from_ptr - str;
        char *new_str = (char *)calloc(new_size + 1, sizeof(char));
        memcpy(new_str, str, untouched_before_size);
        strcpy(new_str + untouched_before_size, to);
        strcat(new_str + untouched_before_size + to_size, from_ptr + from_size);

        free(str);
        str = new_str;

        return true;
    }

    void replace_all(const char *from, const char *to) {
        while (replace_once(from, to));
    }

    void remove(const char *target) {
        replace_all(target, "");
    }

    String operator+(String &other) {
        size_t this_size = size(), other_size = other.size();
        String new_string(size() + other.size());
        memcpy(new_string.str, str, this_size);
        strcpy(new_string.str + this_size, other.str);

        return new_string;
    }

    char &operator[](size_t index) {
        if (index >= size())
            throw std::out_of_range("out of range");
        return str[index];
    }

private:
    char *str;
};

std::ostream &operator<<(std::ostream &os, String & str) {
    return os << str.str;
}

using namespace std;

int main() {
    String test("aaabbbcccbbbeeebbbggg");

    cout << "String:\t" << test << endl;
    cout << "Size:\t" << test.size() << endl;
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
