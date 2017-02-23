#include <iostream>

int main() {
	int rectangles;
	std::cin >> rectangles;

	int sum = 0;
	for(int i = 0, x1, y1, x2, y2; i < rectangles; i++){
		std::cin >> x1 >> y1 >> x2 >> y2;

		sum += (x2 - x1 + 1) * (y2 - y1 + 1);
	}

	std::cout << sum;
	return 0;
}
