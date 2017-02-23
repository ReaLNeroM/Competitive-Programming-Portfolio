#include <iostream>

typedef long long ll;

int main() {
	int size;
	std::cin >> size;

	int left = -1, right = -1, top = -1, bottom = -1;

	char mat[size][size];

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			std::cin >> mat[i][j];

			if(mat[i][j] == '1' and left == -1){
				left = j;
			} else if(mat[i][j] == '0' and left != -1 and top == -1){
				right = j - 1;
				top = i;
			} else if(mat[i][j] == '0' and left <= j and right >= j and top != -1){
				bottom = i - 1;
			}
		}
	}

	bool danger = true;
	for(int i = 0; i < top; i++){
		for(int j = 0; j < size; j++){
			if(mat[i][j] == '1'){
				danger = false;
			}
		}
	}

	for(int i = top; i <= bottom; i++){
		for(int j = 0; j < left; j++){
			if(mat[i][j] == '1'){
				danger = false;
			}
		}
		for(int j = left; j <= right; j++){
			if(mat[i][j] == '0'){
				danger = false;
			}
		}
		for(int j = right + 1; j < size; j++){
			if(mat[i][j] == '1'){
				danger = false;
			}
		}
	}

	for(int i = bottom + 1; i < size; i++){
		for(int j = 0; j < size; j++){
			if(mat[i][j] == '1'){
				danger = false;
			}
		}
	}

	if(danger){
		std::cout << "DANGER";
	} else {
		std::cout << "NO";
	}
	return 0;
}
