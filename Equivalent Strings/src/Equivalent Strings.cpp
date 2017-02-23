#include <iostream>

int main() {
	int s[6];

	for(int i = 0; i < 6; i++){
		std::cin >> s[i];
	}

	int b = 0, remove = 0;
	for(int i = 0; i < s[1] + 2 * s[0]; i++){
		b += 2 * i + 1;
	}

	for(int i = 0; i < s[0]; i++){
		remove += 2 * i + 1;
	}

	std::cout << b - 3 * remove;
	return 0;
}
