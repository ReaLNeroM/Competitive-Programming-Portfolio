#include <iostream>

typedef long long ll;

int main() {
	int cost, balance, wish;
	std::cin >> cost >> balance >> wish;

	int bananas = 0, nextcost = cost;
	while(bananas < wish){
		balance -= nextcost;
		nextcost += cost;
		bananas++;
	}

	if(balance >= 0){
		std::cout << 0;
	} else {
		std::cout << -balance;
	}
	return 0;
}
