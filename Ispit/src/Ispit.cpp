#include <iostream>

int main() {
	int x, y;
	std::cin >> x >> y;

	std::cout << (x >= y) ? 2 * (y - 1) : 2 * x - 1;

	return 0;
}
