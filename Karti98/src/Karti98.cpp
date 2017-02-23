#include <iostream>

int main() {
	int nums;
	std::cin >> nums;

	int sum = 0, max = 0;
	for(int i = 0, inp; i < nums; i++){
		std::cin >> inp;

		sum += inp;
		max = std::max(max, inp);
	}

	std::cout << sum - max;
	return 0;
}
