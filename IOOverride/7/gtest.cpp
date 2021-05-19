#include "DynArray.hpp"

#include <fstream>

#include <gtest/gtest.h>

TEST(DynArray, empty) {
    DynArray<int> empty;

    EXPECT_EQ(empty.size, 0);
    EXPECT_EQ(empty.array, nullptr);
}

TEST(DynArray, resize_and_set) {
    DynArray<int> arr;

    arr.resize(2);
    arr[0] = 10;
    arr[1] = 20;

    ASSERT_EQ(arr.size, 2);
    ASSERT_NE(arr.array, nullptr);
    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
}

TEST(DynArray, append) {
    DynArray<int> arr;

    arr.append(5);

    ASSERT_EQ(arr.size, 1);
    EXPECT_EQ(arr[0], 5);
}

TEST(DynArray, IO) {
    DynArray<int> arr_out, arr_in;
    arr_out.append(1);
    arr_out.append(2);
    arr_out.append(3);

    std::ofstream out;
    const char *FILENAME = "out.tmp";
    out.open(FILENAME, std::ios::out);
    out << arr_out;
    out.close();

    std::ifstream in;
    in.open(FILENAME, std::ios::in);
    in >> arr_in;
    in.close();

    ASSERT_EQ(arr_in.size, 3);
    EXPECT_EQ(arr_in[0], 1);
    EXPECT_EQ(arr_in[1], 2);
    EXPECT_EQ(arr_in[2], 3);

    remove(FILENAME);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
