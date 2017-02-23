#include <iostream>

typedef long long ll;

int main() {
	char mat[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			std::cin >> mat[i][j];
		}
	}

	int blackdist = 8, whitedist = 8;
	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < whitedist; i++) {
			if (mat[i][j] == 'B') {
				break;
			} else if (mat[i][j] == 'W') {
				whitedist = i;
			}
		}
		for (int i = 7; i >= 8 - blackdist; i--) {
			if (mat[i][j] == 'W') {
				break;
			} else if (mat[i][j] == 'B') {
				blackdist = 7 - i;
			}
		}
	}

	if (whitedist <= blackdist) {
		std::cout << 'A';
	} else {
		std::cout << 'B';
	}
	return 0;
}
