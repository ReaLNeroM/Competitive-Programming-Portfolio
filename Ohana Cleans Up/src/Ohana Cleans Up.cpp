#include <iostream>

int main() {
	int size;
	std::cin >> size;

	char mat[size][size];
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			std::cin >> mat[i][j];
		}
	}
	bool same[size][size];

	for(int i = 0; i < size; i++){
		for(int j = i + 1; j < size; j++){
			bool identical = true;

			for(int k = 0; k < size; k++){
				if(mat[i][k] != mat[j][k]){
					identical = false;
				}
			}

			same[i][j] = same[j][i] = identical;
		}

		same[i][i] = true;
	}

	int max = 0;
	for(int i = 0; i < size; i++){
		int curr = 0;

		for(int j = 0; j < size; j++){
			if(same[i][j]){
				curr++;
			}
		}

		max = std::max(max, curr);
	}

	std::cout << max;
	return 0;
}
