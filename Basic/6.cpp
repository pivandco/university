// 6

#include <iostream>

int main() {
	const int MONEY_TO_DROP = 29;

	unsigned short money;
	std::cout << "Money: ";
	std::cin >> money;

	unsigned short max_sum = money, starting_money = money, walks = 0, best_walks = 0;

	if (money >= MONEY_TO_DROP) {
		do {
			money -= MONEY_TO_DROP;
			money = money % 100 * 100 + money / 100;
			walks++;

			if (money > max_sum)  {
				max_sum = money;
				best_walks = walks;
			}
		} while (money >= MONEY_TO_DROP && money != starting_money);
	}

	std::cout << "Max money:\t" << max_sum << std::endl
		<< "Best walks:\t" << best_walks << std::endl;

	system("pause");

	return 0;
}
