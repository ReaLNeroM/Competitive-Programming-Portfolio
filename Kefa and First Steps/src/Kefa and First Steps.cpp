#include <iostream>
#include <cmath>

int main() {
	int n;
	std::cin >> n;

	int last = 0, steps = 0, max = 0;
	for (int i = 0, inp; i < n; i++) {
		std::cin >> inp;
		if (inp >= last) {
			last = inp;
			steps++;
		} else {
			max = std::max(max, steps);
			last = 0;
			steps = 1;
		}
	}
	max = std::max(max, steps);

	std::cout << max;
}
