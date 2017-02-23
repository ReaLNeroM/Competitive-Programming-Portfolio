#include <iostream>

typedef long long ll;

int main() {
	int days;
	std::cin >> days;

	int res = 0, mincost = 100;
	for(int i = 0, need, cost; i < days; i++){
		std::cin >> need >> cost;

		mincost = std::min(mincost, cost);

		res += mincost * need;
	}

	std::cout << res;
	return 0;

}
