/*
#include <iostream>
#include <vector>

int main() {
	int cows;
	std::cin >> cows;
	std::vector<int> speed(cows);

	for (int i = 0, copy; i < cows; i++) {
		std::cin >> copy >> speed[i];
	}

	for (int i = speed.size() - 1; i > 0; i--) {
		for (int j = i - 1; j >= 0; j--, i--) {
			if (speed[i] < speed[j]) {
				speed.erase(speed.begin() + j);
			} else {
				break;
			}
		}
	}

	std::cout << speed.size();
	return 0;
}
*/
#include <fstream>
#include <vector>

int main() {
	std::ifstream myf;
	std::ofstream mof;
	myf.open("cowjog.in");
	mof.open("cowjog.out");
	int cows;
	myf >> cows;
	std::vector<int> speed(cows);

	for (int i = 0, copy; i < cows; i++) {
		myf >> copy >> speed[i];
	}

	for (int i = speed.size() - 1; i > 0; i--) {
		for (int j = i - 1; j >= 0; j--, i--) {
			if (speed[i] < speed[j]) {
				speed.erase(speed.begin() + j);
			} else {
				break;
			}
		}
	}

	mof << speed.size();
	return 0;
}
