#include <iostream>
#include <cmath>
typedef long long ll;

int main() {
	int n;
	std::cin >> n;

	long long res = 20 * std::pow(3, ((n - 1) * 3));
	long long ways = 1;
	for (int i = 0; i < n; i++) {
		std::cout << ways * 20 * std::pow(3, ((n - i - 1) * 3)) << std::endl;
		ways += 7;
	}
	return 0;
}
