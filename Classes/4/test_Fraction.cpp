#include "Fraction.hpp"

#include <gtest/gtest.h>

#define EXPECT_FRAC_EQ(frac, num, denom) { \
    EXPECT_EQ((frac).numerator(), (num));      \
    EXPECT_EQ((frac).denominator(), (denom));  \
}

TEST(Fraction, reduce_both_negative) {
    Fraction<int> f(-10, -10);
    f.reduce();
    EXPECT_FRAC_EQ(f, -1, -1);
}

TEST(Fraction, reduce_denominator_negative) {
    Fraction<int> f(10, -5);
    f.reduce();
    EXPECT_FRAC_EQ(f, 2, -1);
}

TEST(Fraction, reduce_numerator_negative) {
    Fraction<int> f(-10, 5);
    f.reduce();
    EXPECT_FRAC_EQ(f, -2, 1);
}

TEST(Fraction, reduce_already_reduced) {
    Fraction<int> f(5, 4);
    f.reduce();
    EXPECT_FRAC_EQ(f, 5, 4);
}

TEST(Fraction, zero_denominator) {
    EXPECT_THROW(Fraction<int>(1, 0), std::domain_error);
}

TEST(Fraction, add) {
    EXPECT_FRAC_EQ(Fraction<int>(2, 3) + Fraction<int>(2, 6), 1, 1);
    EXPECT_FRAC_EQ(Fraction<int>(1, 2) + Fraction<int>(0, 3), 1, 2);
}

TEST(Fraction, add_overflow) {
    EXPECT_THROW(Fraction<char>(127, 1) + Fraction<char>(1, 1), std::overflow_error);
    EXPECT_THROW(Fraction<char>(127, 127) + Fraction<char>(127, 127), std::overflow_error);
}

TEST(Fraction, subtract) {
    EXPECT_FRAC_EQ(Fraction<int>(3, 3) - Fraction<int>(1, 5), 4, 5);
}

TEST(Fraction, subtract_overflow) {
    EXPECT_THROW(Fraction<char>(-127, 1) - Fraction<char>(1, 1), std::overflow_error);
    EXPECT_THROW(Fraction<char>(-127, 127) - Fraction<char>(-127, 127), std::overflow_error);
    EXPECT_THROW(Fraction<char>(1, 1) - Fraction<char>(128, 128), std::overflow_error);
}

TEST(Fraction, multiply) {
    EXPECT_FRAC_EQ(Fraction<int>(1, 10) * Fraction<int>(10, 1), 1, 1);
}

TEST(Fraction, multiply_overflow) {
    EXPECT_THROW(Fraction<char>(127, 1) * Fraction<char>(2, 1), std::overflow_error);
    EXPECT_THROW(Fraction<char>(1, 127) * Fraction<char>(1, 2), std::overflow_error);
    EXPECT_THROW(Fraction<char>(-128, 1) * Fraction<char>(-1, 1), std::overflow_error);
}

TEST(Fraction, divide) {
    EXPECT_FRAC_EQ(Fraction<int>(1, 10) / Fraction<int>(10, 1), 1, 100);
}

TEST(Fraction, divide_overflow) {
    EXPECT_THROW(Fraction<int>(-128, 1) / Fraction<int>(-1, 1), std::overflow_error);
}

TEST(Fraction, divide_zero) {
    EXPECT_THROW(Fraction<int>(1, 10) / Fraction<int>(0, 1), std::domain_error);
}

TEST(Fraction, to_string) {
    EXPECT_EQ(Fraction<int>(1, 3).to_string(), "1/3");
    EXPECT_EQ(Fraction<int>(-1, 3).to_string(), "-1/3");
    EXPECT_EQ(Fraction<int>(-1, -3).to_string(), "1/3");
}

// ÿ”≈ œœÿ I/O ¬ ﬁÕ»“ “≈—“¿’ –Œ‘À¿Õ ≈¡¿ÀŒ
TEST(Fraction, input) {
    setlocale(LC_ALL, "Russian");
    Fraction<int> f;
    std::cin >> f;

    std::cout << "¬˚ ‚‚ÂÎË " << f << std::endl;
}

#undef EXPECT_FRAC_EQ
