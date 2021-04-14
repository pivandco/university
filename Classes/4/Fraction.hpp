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

Fraction operator+(const Fraction &a, const Fraction &b) {
    Fraction result(
        a.nominator() * b.denominator() + b.nominator() * a.denominator(),
        a.denominator() * b.denominator()
    );
    result.reduce();
    return result;
}

Fraction operator-(const Fraction &a, const Fraction &b) {
    return operator+(-b);
}

Fraction operator*(const Fraction &a, const Fraction &b) {
    Fraction result(a.numerator() * b.numerator(), a.denominator() * b.denominator());
    result.reduce();
    return result;
}

Fraction operator/(const Fraction &a, const Fraction &b) {
    return operator*(Fraction(_denominator, _numerator));
}

template <typename T>
std::ostream &operator<<(std::ostream s, const Fraction<T> &frac) {
    return s << frac.to_string();
}
