#include <iostream>

int main() {
	long long x;
	std::cin >> x;

	long long res = 1;

	for (int i = 1; i < x; i++) {
		if (i + i - 1 >= x) {
			res += 1;
		}
	}

	if (x % 2 == 0) {
		res += x / 2;
	}

	std::cout << res;
}
