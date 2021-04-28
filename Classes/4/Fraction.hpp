#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <limits>

#include "SafeArithmetics.hpp"

template<typename T>
static T gcd(T a, T b) {
    a = SafeArithmetics<T>::abs(a);
    b = SafeArithmetics<T>::abs(b);
    while (a && b) {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}

template<typename T>
class Fraction {
public:
    Fraction() = default;

    Fraction(T numerator, T denominator) : _numerator(numerator), _denominator(denominator) {
        if (!_denominator)
            throw std::domain_error("denominator is 0");
    }

    T numerator() const { return _numerator; }
    T denominator() const { return _denominator; };

    void reduce() {
        T d = gcd(_numerator, _denominator);
        _numerator /= d;
        _denominator /= d;
    }

    std::string to_string() const {
        std::stringstream ss;

        if (_denominator < 0) {
            ss << -_numerator << '/' << -_denominator;
        } else {
            ss << _numerator << '/' << _denominator;
        }

        return ss.str();
    }

private:
    T _numerator = 0, _denominator = 1;
};

template<typename T>
Fraction<T> operator+(const Fraction<T> &a, const Fraction<T> &b) {
    using SA = SafeArithmetics<T>;
    Fraction<T> result(
        SA::add(SA::multiply(a.numerator(), b.denominator()), SA::multiply(b.numerator(), a.denominator())),
        SA::multiply(a.denominator(), b.denominator())
    );
    result.reduce();
    return result;
}

template<typename T>
Fraction<T> operator-(const Fraction<T> &a, const Fraction<T> &b) {
    return a + Fraction<T>(-b.numerator(), b.denominator());
}

template<typename T>
Fraction<T> operator*(const Fraction<T> &a, const Fraction<T> &b) {
    using SA = SafeArithmetics<T>;
    Fraction<T> result(
        SA::multiply(a.numerator(), b.numerator()),
        SA::multiply(a.denominator(), b.denominator())
    );
    result.reduce();
    return result;
}

template<typename T>
Fraction<T> operator/(const Fraction<T> &a, const Fraction<T> &b) {
    using SA = SafeArithmetics<T>;
    Fraction<T> result(
        SA::multiply(a.numerator(), b.denominator()),
        SA::multiply(a.denominator(), b.numerator())
    );
    result.reduce();
    return result;
}

template <typename T>
std::ostream &operator<<(std::ostream &s, const Fraction<T> &frac) {
    return s << frac.to_string();
}

template <typename T>
std::istream &operator>>(std::istream &s, Fraction<T> &frac) {
    T num = 0, denom = 0;
    std::cout << "Числитель: ";
    s >> num;
    while (denom == 0) {
        std::cout << "Знаменатель: ";
        s >> denom;
    }

    frac = Fraction<T>(num, denom);
    return s;
}
