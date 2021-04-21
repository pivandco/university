#include "SafeArithmetics.hpp"

#include <gtest/gtest.h>

#define SA SafeArithmetics<char>

TEST(SafeArithmetics, add) {
    EXPECT_EQ(SA::add(1, 1), 2);
}

TEST(SafeArithmetics, add_overflow) {
    EXPECT_THROW(SA::add(127, 1), std::overflow_error);
    EXPECT_THROW(SA::add(-128, -1), std::overflow_error);
}

TEST(SafeArithmetics, subtract) {
    EXPECT_EQ(SA::subtract(2, 1), 1);
}

TEST(SafeArithmetics, subtract_overflow) {
    EXPECT_THROW(SA::subtract(127, -1), std::overflow_error);
    EXPECT_THROW(SA::subtract(-128, 1), std::overflow_error);
}

TEST(SafeArithmetics, multiply) {
    EXPECT_EQ(SA::multiply(2, 2), 4);
    EXPECT_EQ(SA::multiply(-1, 3), -3);
    EXPECT_EQ(SA::multiply(1, 0), 0);
    EXPECT_EQ(SA::multiply(0, 1), 0);
    EXPECT_EQ(SA::multiply(0, 0), 0);
}

TEST(SafeArithmetics, multiply_overflow) {
    EXPECT_THROW(SA::multiply(127, 127), std::overflow_error);
    EXPECT_THROW(SA::multiply(-128, -1), std::overflow_error);
    EXPECT_THROW(SA::multiply(-128, 3), std::overflow_error);
}

TEST(SafeArithmetics, divide) {
    EXPECT_EQ(SA::divide(4, 2), 2);
    EXPECT_EQ(SA::divide(0, 2), 0);
}

TEST(SafeArithmetics, divide_zero) {
    EXPECT_THROW(SA::divide(1, 0), std::domain_error);
}

TEST(SafeArithmetics, divide_overflow) {
    EXPECT_THROW(SA::divide(-128, -1), std::overflow_error);
}

TEST(SafeArithmetics, abs) {
    EXPECT_EQ(SA::abs(-10), 10);
    EXPECT_EQ(SA::abs(10), 10);
}

TEST(SafeArithmetics, abs_overflow) {
    EXPECT_THROW(SA::abs(-128), std::overflow_error);
}

#undef SA
