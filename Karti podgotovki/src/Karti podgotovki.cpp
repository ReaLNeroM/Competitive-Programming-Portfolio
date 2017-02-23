#include <iostream>

int main() {
	int cards, turn;
	std::cin >> cards >> turn;

	bool cardpos[2][cards];
	for (int i = 0; i < cards; i++) {
		std::cin >> cardpos[0][i];
		cardpos[1][i] = cardpos[0][i];
	}

	long long result[] = { 0, 0 };
	for (int i = 0; i < cards; i++) {
		for (int c = 0; c < 2; c++) {
			if (cardpos[c][i] != c) {
				for (int j = std::min(cards - turn, i); j < std::min(cards, i + turn); j++) {
					cardpos[c][j] = !cardpos[c][j];
				}
				result[c]++;
			}

		}
	}
	for (int i = 0; i < cards; i++) {
		for(int c = 0; c < 2; c++){
			if(cardpos[c][i] != c){
				result[c] = -1;
			}
		}
	}
	if(result[0] == -1 and result[1] == -1){
		std::cout << result[0];
	} else if(result[0] == -1){
		std::cout << result[1];
	} else if(result[1] == -1){
		std::cout << result[0];
	} else {
		std::cout << std::min(result[0], result[1]);
	}
	return 0;
}
