#include <gtest/gtest.h>

#include <stdexcept>

#include "Fraction.hpp"

template <typename T>
void EXPECT_FRAC_EQ(Fraction<T> &frac, T num, T denom) {
    EXPECT_EQ(frac.numerator(), num);
    EXPECT_EQ(frac.denominator(), denom);
}

TEST(Fraction, reduce) {
    Fraction<int> f1(-10, -10);
    f1.reduce();
    EXPECT_FRAC_EQ(f1, 1, 1);

    Fraction<int> f2(10, -5);
    f2.reduce();
    EXPECT_FRAC_EQ(f2, -2, 1);
}

TEST(Fraction, reduce_already_reduced) {
    Fraction<int> f1(5, 4);
    f1.reduce();
    EXPECT_FRAC_EQ(f1, 5, 4);
}

TEST(Fraction, zero_denominator) {
    EXPECT_THROW(Fraction<int> f(1, 0), ZeroDivisionException);
}

TEST(Fraction, add) {
    auto f = Fraction<int>(2, 3) + Fraction<int>(2, 6);
    EXPECT_FRAC_EQ(f, 1, 1);
}

TEST(Fraction, subtract) {
    auto f = Fraction<int>(3, 3) - Fraction<int>(1, 5);
    EXPECT_FRAC_EQ(f, 4, 5);
}

TEST(Fraction, multiply) {
    auto f = Fraction<int>(1, 10) * Fraction<int>(10, 1);
    EXPECT_FRAC_EQ(f, 1, 1);
}

TEST(Fraction, divide) {
    auto f = Fraction<int>(1, 10) / Fraction<int>(10, 1);
    EXPECT_FRAC_EQ(f, 1, 100);
}

TEST(Fraction, to_string) {
    Fraction<int> f(-1, 3);
    EXPECT_EQ(f.to_string(), "-1/3");
}

TEST(Fraction, to_string_zero) {
    Fraction<int> f(-0, 3);
    EXPECT_EQ(f.to_string(), "0");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
