#include <gtest/gtest.h>

#include <stdexcept>

#include "Fraction.hpp"

void EXPECT_FRAC_EQ(Fraction &frac, int num, int denom) {
    EXPECT_EQ(frac.numerator(), num);
    EXPECT_EQ(frac.denominator(), denom);
}

TEST(Fraction, reduce) {
    Fraction f1(10, 10);
    f1.reduce();
    EXPECT_FRAC_EQ(f1, 1, 1);

    Fraction f2(10, 5);
    f2.reduce();
    EXPECT_FRAC_EQ(f2, 2, 1);
}

TEST(Fraction, reduce_already_reduced) {
    Fraction f1(5, 4);
    f1.reduce();
    EXPECT_FRAC_EQ(f1, 5, 4);
}

TEST(Fraction, reduce_zero_denominator) {
    Fraction f(1, 0);
    EXPECT_THROW(f.reduce(), std::domain_error);
}

TEST(Fraction, flipped) {
    auto f = Fraction(1, 3).flipped();
    EXPECT_FRAC_EQ(f, 3, 1);
}

TEST(Fraction, negate) {
    auto f = -Fraction(1, 1);
    EXPECT_FRAC_EQ(f, -1, 1);
}

TEST(Fraction, add) {
    auto f = Fraction(2, 3) + Fraction(2, 6);
    EXPECT_FRAC_EQ(f, 1, 1);
}

TEST(Fraction, subtract) {
    auto f = Fraction(3, 3) - Fraction(1, 5);
    EXPECT_FRAC_EQ(f, 4, 5);
}

TEST(Fraction, multiply) {
    auto f = Fraction(1, 10) * Fraction(10, 1);
    EXPECT_FRAC_EQ(f, 1, 1);
}

TEST(Fraction, divide) {
    auto f = Fraction(1, 10) / Fraction(10, 1);
    EXPECT_FRAC_EQ(f, 1, 100);
}

TEST(Fraction, to_string) {
    Fraction f(-1, 3);
    EXPECT_EQ(f.to_string(), "-1/3");
}

TEST(Fraction, to_string_zero) {
    Fraction f(-0, 3);
    EXPECT_EQ(f.to_string(), "0");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
