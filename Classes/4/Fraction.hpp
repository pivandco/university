#pragma once

#include <iostream>
#include <string>

template<typename T>
static T gcd(T a, T b) {
    while (a && b) {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}

class ZeroDivisionException : std::domain_error {
public:
    ZeroDivisionException(const char *msg) : std::domain_error(msg) {}
};

template<typename T>
class Fraction {
public:
    Fraction(T numerator, T denominator) : _numerator(numerator), _denominator(denominator) {
        if (!_denominator)
            throw ZeroDivisionException("denominator is 0");
    }

    T numerator() const { return _numerator; }
    T denominator() const { return _denominator; };

    void reduce() {
        T d = gcd(_numerator, _denominator);
        _numerator /= d;
        _denominator /= d;
        if (_denominator < 0) {
            _denominator *= -1;
            _numerator *= -1;
        }
    }

    std::string to_string() const {
        std::stringstream ss;
        ss << _numerator;
        if (_numerator)
            ss << '/' << _denominator;
        return ss.str();
    }

private:
    T _numerator, _denominator;
};

template<typename T>
Fraction<T> operator+(const Fraction<T> &a, const Fraction<T> &b) {
    Fraction<T> result(
        a.numerator() * b.denominator() + b.numerator() * a.denominator(),
        a.denominator() * b.denominator()
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
    Fraction<T> result(a.numerator() * b.numerator(), a.denominator() * b.denominator());
    result.reduce();
    return result;
}

template<typename T>
Fraction<T> operator/(const Fraction<T> &a, const Fraction<T> &b) {
    return a * Fraction<T>(b.denominator(), b.numerator());
}

template <typename T>
std::ostream &operator<<(std::ostream s, const Fraction<T> &frac) {
    return s << frac.to_string();
}
