#include "Fraction.hpp"

#include <stdexcept>
#include <sstream>

static int gcd(int a, int b) {
    while (a && b) {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}

static int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

Fraction::Fraction(int numerator, int denominator) : _numerator(numerator), _denominator(denominator) {}

void Fraction::reduce() {
    if (!_denominator)
        throw std::domain_error("division by zero");
    int d = gcd(_numerator, _denominator);
    _numerator /= d;
    _denominator /= d;
}

Fraction Fraction::flipped() const {
    return Fraction(_denominator, _numerator);
}

Fraction Fraction::operator-() const {
    return Fraction(-_numerator, _denominator);
}

std::string Fraction::to_string() const {
    std::stringstream ss;
    ss << _numerator;
    if (_numerator)
        ss << '/' << _denominator;
    return ss.str();
}

Fraction operator+(const Fraction &a, const Fraction &b) {
    int denominator_lcm = lcm(a.denominator(), b.denominator()),
        a_mult = denominator_lcm / a.denominator(),
        b_mult = denominator_lcm / b.denominator();
    Fraction result(a.numerator() * a_mult + b.numerator() * b_mult, denominator_lcm);
    result.reduce();
    return result;
}

Fraction operator-(const Fraction &a, const Fraction &b) {
    return a + -b;
}

Fraction operator*(const Fraction &a, const Fraction &b) {
    Fraction result(a.numerator() * b.numerator(), a.denominator() * b.denominator());
    result.reduce();
    return result;
}

Fraction operator/(const Fraction &a, const Fraction &b) {
    return a * b.flipped();
}

std::ostream &operator<<(std::ostream s, const Fraction &frac) {
    return s << frac.to_string();
}
