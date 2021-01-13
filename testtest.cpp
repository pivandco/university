#define TESTED_FUNC_RTYPE nums
#define TESTED_FUNC add
#include "test.h"

struct nums {
    int x, y;
}

nums add(nums x, nums y) {
    return nums { n1.x + n2.x, n1.y + n2.y };
}

int main() {
    nums n1 = { 1, 2 }, n2 = { 3, 4 };
    nums result = add(n1, n2);
    nums correct = { 4, 6 };
    TEST(correct, result);
}
