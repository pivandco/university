#pragma once

#include <iostream>
#include <string>

class Fraction {
public:
    Fraction(int, int);

    int numerator() const { return _numerator; }
    int denominator() const { return _denominator; };
    void reduce();
    Fraction flipped() const;
    Fraction operator-() const;
    std::string to_string() const;

private:
    int _numerator = 0, _denominator = 1;
};

Fraction operator+(const Fraction &, const Fraction &);
Fraction operator-(const Fraction &, const Fraction &);
Fraction operator*(const Fraction &, const Fraction &);
Fraction operator/(const Fraction &, const Fraction &);
std::ostream &operator<<(std::ostream, const Fraction &);
