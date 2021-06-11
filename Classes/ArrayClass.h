//
// Created by 1 on 04.06.2021.
//

#ifndef CLASSARRAY_ARRAYCLASS_H
#define CLASSARRAY_ARRAYCLASS_H

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;


template<typename T>
class Array {
    int a_length;
    int a_index;
    T *array;

public:
    Array(int length = 0, int index = 0) {
        if (length >= 0) {
            a_length = length;
            a_index = index;
            array = (T *) calloc(a_length, sizeof(T)) - a_index;
        } else throw exception("Length cannot be negative");
    }

    Array(T a[], int length) {
        if (length >= 0) {
            a_index = 0;
            a_length = length;
            array = (T *) calloc(a_length, sizeof(T));
            for (int i = 0; i < a_length; i++)
                array[i] = a[i];
        } else throw exception("Length cannot be negative");
    }

    Array(const Array &a) {
        a_length = a.a_length;
        a_index = a.a_index;
        array = (T *) calloc(a_length, sizeof(T)) - a_index;
        for (int i = 0; i < a_length; i++)
            array[i + a_index] = a.array[i + a_index];
    }

    int get_index() {
        return a_index;
    };

    int get_length() {
        return a_length;
    };

    void set_base_index(int index) {
        array += a_index - index;
        a_index = index;
    };

    void set_length(int length) {
        array = (T *) realloc(array + a_index, length * sizeof(T)) - a_index;
        if (length > a_length)
            for (int i = a_length; i < length; i++)
                array[i + a_index] = 0;
        a_length = length;
    };



    void a_rand(T begin, T end) {
        for (int i = 0; i < a_length; i++) {
            array[i + a_index] = rand() % (end - begin + 1) + begin;
        }
    };

    void ascending_sort() {
        T tmp;
        for (int i = 0; i < a_length - 1; i++)
            for (int j = i + 1; j < a_length; j++)
                if (array[i + a_index] > array[j + a_index]) {
                    tmp = array[i + a_index];
                    array[i + a_index] = array[j + a_index];
                    array[j + a_index] = tmp;
                }
    };

    void descending_sort() {
        T tmp;
        for (int i = 0; i < a_length - 1; i++)
            for (int j = i + 1; j < a_length; j++)
                if (array[i + a_index] < array[j + a_index]) {
                    tmp = array[i + a_index];
                    array[i + a_index] = array[j + a_index];
                    array[j + a_index] = tmp;
                }
    };

    T *find(T key) {
        for (int i = 0; i < a_length; i++) {
            if (array[i + a_index] == key)
                return &array[i];
        }
        return 0;
    }

    T &operator[](int i) const {
        if (i >= a_index && i < a_length + a_index)
            return array[i];
        else throw exception("Out of range exception");
    }

    friend Array<T> operator+(Array<T> &a, Array<T> &b) {
        if (a.a_length == b.a_length) {
            Array<T> c(a.a_length, 0);
            for (int i = 0; i < a.a_length; i++) {
                c[i + c.a_index] = a[i + a.a_index] + b[i + b.a_index];
            }
            return c;
        } else throw exception("Different array lengths");
    }

    friend Array<T> operator-(const Array<T> &a, const Array<T> &b) {
        if (a.a_length == b.a_length) {
            Array<T> c(a.a_length, 0);
            for (int i = 0; i < a.a_length; i++) {
                c[i + c.a_index] = a[i + a.a_index] - b[i + b.a_index];
            }
            return c;
        } else throw exception("Different array lengths");
    }

    friend ostream &operator<<(ostream &out, const Array &a) {
        for (int i = 0; i < a.a_length; i++)
            out << setw(5) << a[i + a.a_index];
        out << endl;
        return out;
    };

    friend istream &operator>>(istream &in, Array<T> &a) {
        int length, index;
        cout << "Input length: ";
        in >> length;
        while (length < 1)
            cout << "Wrong length" << endl;
        a.set_length(length);
        cout << endl << "Input base index: ";
        in >> index;
        a.set_base_index(index);
        cout << endl << "Input elements: ";
        for (int i = 0; i < length; i++)
            in >> a[i + index];
        return in;
    }

};


#endif //CLASSARRAY_ARRAYCLASS_H
