#pragma once

#include <iostream>

template<typename T>
struct DynArray {
    size_t size = 0;
    T *array = nullptr;

    ~DynArray() {
        free(array);
    }

    void resize(size_t new_size) {
        size = new_size;
        array = (T *)realloc(array, new_size * sizeof(T));
    }

    void append(T obj) {
        resize(size + 1);
        array[size - 1] = obj;
    }

    T &operator[](size_t index) {
        return array[index];
    }
};

template<typename T>
std::ostream &operator<<(std::ostream &out, const DynArray<T> &arr) {
    out.write(reinterpret_cast<const char *>(&arr.size), sizeof(arr.size));
    return out.write(reinterpret_cast<const char *>(&arr.array), sizeof(arr.array));
}

template<typename T>
std::istream &operator>>(std::istream &in, DynArray<T> &arr) {
    in.read(reinterpret_cast<char *>(&arr.size), sizeof(arr.size));
    return in.read(reinterpret_cast<char *>(&arr.array), sizeof(arr.array));
}
