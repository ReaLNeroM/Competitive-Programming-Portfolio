#include <iostream>

int main() {
	int d1, d2, d3;
	std::cin >> d1 >> d2 >> d3;

	std::cout << std::min(std::min(d1 + d1 + d2 + d2, d1 + d2 + d3), std::min(d1 + d1 + d3 + d3, d2 + d2 + d3 + d3));
}
