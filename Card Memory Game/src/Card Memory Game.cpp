#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	int cardx = 5, cardy = 4;

	if(( cardx * cardy) % 2 != 0){
		std::cout << "Neparno" << std::endl;
		return 0;
	}

	int used[cardx * cardy / 2];
	for(int i = 0; i < cardx * cardy / 2; i++){
		used[i] = 2;
	}

	std::srand(std::time(NULL));

	int num[cardy][cardx];
	for(int i = 0; i < cardy; i++){
		for(int j = 0; j < cardx; j++){
			int check;

			do {
				check = std::rand() % (cardx * cardy / 2);
			} while(used[check] <= 0);

			used[check]--;
			num[i][j] = check + 1;
		}
	}

	std::string str;
	int left = cardx * cardy / 2;
	while(true){
		for(int i = 0; i < cardy; i++){
			for(int j = 0; j < cardx; j++){
				std::cout << "| ";

				if(used[num[i][j] - 1] > 0){
					std::cout << '?';
				} else {
					std::cout << num[i][j];
				}

				std::cout << " |";
			}
			std::cout << std::endl;
		}

		int x, y, x2, y2;
		std::cin >> x >> y;
		std::cout << num[x - 1][y - 1] << std::endl;
		std::cin >> x2 >> y2;
		std::cout << num[x2 - 1][y2 - 1] << std::endl;
		if((x != x2 or y != y2) and num[x - 1][y - 1] == num[x2 - 1][y2 - 1]){
			std::cout << "Tocno!" << std::endl;
			left--;
		}
	}
	return 0;
}
