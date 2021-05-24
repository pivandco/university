#pragma once

#include <iostream>
#include <string>
#include <map>

template<typename T> void bin_read(std::istream &in, T &obj) {
    in.read(reinterpret_cast<char *>(&obj), sizeof(obj));
}

template<typename T> void bin_write(std::ostream &out, const T &obj) {
    out.write(reinterpret_cast<const char *>(&obj), sizeof(obj));
}

template<> inline void bin_read(std::istream &in, std::string &str) {
    size_t str_size;
    bin_read(in, str_size);
    str.resize(str_size);
    in.read(str.data(), str_size);
}

template<> inline void bin_write(std::ostream &out, const std::string &str) {
    bin_write(out, str.size());
    bin_write(out, str.c_str());
}

template<typename T>
void bin_read(std::istream &in, std::vector<T> &vec) {
    size_t size;
    bin_read(in, size);
    vec.resize(size);
    for (size_t i = 0; i < size; i++) {
        bin_read(in, vec[i]);
    }
}

template<typename T>
void bin_write(std::ostream &out, const std::vector<T> &vec) {
    bin_write(out, vec.size());
    for (auto &item : vec) {
        bin_write(out, item);
    }
}

template<typename K, typename V>
void bin_read(std::istream &in, std::map<K, V> &map) {
    size_t size;
    bin_read(in, size);
    for (size_t i = 0; i < size; i++) {
        K key;
        V value;
        bin_read(in, key);
        bin_read(in, value);
        map[key] = value;
    }
}

template<typename K, typename V>
void bin_write(std::ostream &out, std::map<K, V> &map) {
    bin_write(out, map.size());
    for (auto &pair : map) {
        bin_write(out, pair->first);
        bin_write(out, pair->second);
    }
}
