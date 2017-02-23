#include <iostream>

const int size = 8;
bool board[size][size];

// forgot the knight movement, instead of searching for adjacent search +2 -1
bool iddfs(int depth, int last = 0){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if(!board[i][j]){
						break;
			}
			if(i == size - 1 and j == size - 1){
				return true;
			}
		}
	}

	if(depth == 0){
		return false;
	}

	for(int i = last; i < size * size; i++){
		if(!board[i / 8][i % 8]){
			board[i / 8][i % 8] = true;
			if(i / 8 <0)
			if(iddfs(depth - 1, i + 1)){
				return true;
			}
			board[i / 8][i % 8] = false;
		}
	}

	return false;
}
int main() {
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			board[i][j] = false;
		}
	}
	for(int i = 0; i <= size * size; i++){
		if(iddfs(i)){
			std::cout << i << std::endl;
			break;
		}
	}

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
	return 0;
}
