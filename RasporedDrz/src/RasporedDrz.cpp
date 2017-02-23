#include <iostream>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;

	int know[n], min = 1000000, max = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> know[i];
		min = std::min(min, know[i]);
		max = std::max(max, know[i]);
	}

	std::cout << max - min;
	return 0;
}
