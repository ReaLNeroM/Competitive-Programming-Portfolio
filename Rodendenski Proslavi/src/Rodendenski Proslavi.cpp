#include <iostream>
#include <vector>

std::vector<int> max;
std::vector<int> follower;

int main() {
	bool ro[12][31];

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 31; j++) {
			ro[i][j] = false;
		}
	}

	int br;
	std::cin >> br;

	for (int i = 0; i < br; i++) {
		int date, month;
		std::cin >> date >> month;
		ro[month - 1][date - 1] = true;
	}

	max.push_back(0);
	follower.push_back(1);
	int atcurr = 0;

	for (int i = 0; i < 12; i++) {
		int births = 0;
		for (int j = 0; j < 31; j++) {
			if (ro[i][j]) {
				births++;
			}
		}

		if (births > max[atcurr]) {
			max[atcurr] = births;
			follower[atcurr] = i + 1;
			for (int i = 0; i < max.size(); i++) {
				if (births > max[i]) {
					max.erase(max.begin() + i);
					follower.erase(follower.begin() + i);
					i--;
				}
			}
			atcurr = max.size() - 1;
		} else if (births == max[atcurr] and births != 0) {
			atcurr++;
			max.push_back(births);
			follower.push_back(i + 1);
		}
	}

	for (int i = 0; i < follower.size(); i++) {
		std::cout << follower[i] << std::endl;
	}

	return 0;
}
