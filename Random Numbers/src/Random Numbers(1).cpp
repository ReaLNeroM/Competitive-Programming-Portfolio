#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	int lines, perline, small, big;
	std::cout << "How many? ";
	std::cin >> lines;
	std::cout << "How many per line? ";
	std::cin >> perline;
	std::cout << "Define the interval: ";
	std::cin >> small >> big;

	std::srand(std::time(NULL));

	for(int i = 0; i < lines; i++){
		for(int j = 0; j < perline; j++){
			std::cout << rand() % (big + 1 - small) + small << " ";
		}

		std::cout << std::endl;
	}
	return 0;
}
