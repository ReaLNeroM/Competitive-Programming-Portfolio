#include <iostream>
#include <cmath>

int main() {
	long long a, b;
	long long min, max;
	std::cin >> a >> b;

	max = std::min((double) 10 / 9 * a, (double) b);
	min = ((double) 20 / 19 * a) + 1;

	if (min + (5 - min % 5) % 5 <= max) {
		min += (5 - min % 5) % 5;
	}
	if (max - (max % 5) >= min) {
		max -= max % 5;
	}

	if (max % 5 == 0 and min % 5 == 0) {
		std::cout << (max - min) / 5 + 1;
	} else {
		std::cout << 0;
	}
	return 0;
}
