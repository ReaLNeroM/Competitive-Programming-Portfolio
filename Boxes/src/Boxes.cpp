#include <iostream>

typedef long long ll;

int main() {
	int boxes;
	std::cin >> boxes;

	static int ways[7][7][7][7][7][7][100];
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			for (int k = 0; k < 7; k++) {
				for (int l = 0; l < 7; l++) {
					for (int m = 0; m < 7; m++) {
						for (int n = 0; n < 7; n++) {
							for (int o = 0; o < 100; o++) {
								ways[i][j][k][l][m][n][o] = 6;
							}
						}
					}
				}
			}
		}
	}

	int b[boxes][6];

	for (int i = 0; i < boxes; i++) {
		for (int j = 0; j < 6; j++) {
			std::cin >> b[i][j];
		}

		for()

		for(int j = 0; j < 6; j++){
			if()
		}
	}

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			for (int k = 0; k < 7; k++) {
				for (int l = 0; l < 7; l++) {
					for (int m = 0; m < 7; m++) {
						for (int n = 0; n < 7; n++) {
							int curr = 0;
							for (int o = 0; o < 100; o++) {
								curr += ways[i][j][k][l][m][n][o];
							}

							min = std::min(min, curr);
						}
					}
				}
			}
		}
	}
	std::cout << min;
	return 0;
}
