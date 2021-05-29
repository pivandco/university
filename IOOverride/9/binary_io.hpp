#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>

template<typename T> void bin_read(std::istream &in, T &obj) {
    in.read(reinterpret_cast<char *>(&obj), sizeof(obj));
}

template<typename T> void bin_write(std::ostream &out, const T &obj) {
    out.write(reinterpret_cast<const char *>(&obj), sizeof(obj));
}

template<> inline void bin_read(std::istream &in, std::string &str) {
    size_t len;
    bin_read(in, len);
    str.resize(len);
    in.read(str.data(), len);
}

template<> inline void bin_write(std::ostream &out, const std::string &str) {
    size_t size = str.size();
    bin_write(out, size);
    out.write(str.c_str(), size);
}

template<typename T>
void bin_read_vector(std::istream &in, std::vector<T> &vec, void (*read_callback)(std::istream &, T &)) {
    size_t size;
    bin_read(in, size);
    vec.resize(size);
    for (size_t i = 0; i < size; i++) {
        read_callback(in, vec[i]);
    }
}

template<typename T>
void bin_write_vector(std::ostream &out, const std::vector<T> &vec, void (*write_callback)(std::ostream &, const T &)) {
    bin_write(out, vec.size());
    for (auto &item : vec) {
        write_callback(out, item);
    }
}

template<typename K, typename V>
void bin_read_map(std::istream &in, std::map<K, V> &map, void (*read_callback)(std::istream &, K &, V &)) {
    size_t size;
    bin_read(in, size);
    for (size_t i = 0; i < size; i++) {
        K key;
        V value;
        read_callback(in, key, value);
        map[key] = value;
    }
}

template<typename K, typename V>
void bin_write_map(std::ostream &out, const std::map<K, V> &map, void (*write_callback)(std::ostream &, const K &, const V &)) {
    bin_write(out, map.size());
    for (auto &[first, second] : map) {
        write_callback(out, first, second);
    }
}
