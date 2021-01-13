// 6_test

#include <string>

#define TESTED_FUNC count
#define TESTED_FUNC_RTYPE std::string
#include "test.h"

std::string count(unsigned short money) {
	const int MONEY_TO_DROP = 29;
	unsigned short max_sum = money, starting_money = money, walks = 0, best_walks = 0;

	if (money >= MONEY_TO_DROP) {
		do {
			if (money > max_sum)  {
				max_sum = money;
				best_walks = walks;
			}

			money -= MONEY_TO_DROP;
			money = money % 100 * 100 + money / 100;
			walks++;
		} while (money >= MONEY_TO_DROP && money != starting_money);
	}

	return std::to_string(max_sum) + '-' + std::to_string(best_walks);
}

int main() {
	TEST("9904-81", 7699);
	TEST("9998-196", 7069);
	TEST("9902-63", 1136);
	TEST("9964-197", 3599);
	TEST("8916-10", 3563);
	TEST("9967-196", 7038);
	TEST("6287-0", 6287);
	TEST("10-0", 0);
	TEST("0-0", 0);
	system("pause");
}
