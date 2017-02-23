#include <iostream>

int main() {
	long long base, goal;
	std::cin >> base >> goal;

	long long logged = 0;

	while (goal >= 1 and logged <= 100) {
		long long remainder = goal % base;
		if (remainder == base - 1) {
			goal += 1;
		} else if(remainder != 0 and remainder != 1){
			std::cout << "NO";
			return 0;
		}

		goal /= base;
		logged++;
	}

	std::cout << "YES";
	return 0;
}
