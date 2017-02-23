//============================================================================
// Name        : KnigiJBOI.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

int size;
std::vector<std::vector<int> > mat;

bool checker(int pa, int pb){
	for(int i = 0; i < pa; i++){
		if(mat[pa][pb] <= mat[i][pb]){
			break;
		}
		if(i == pa - 1){
			return false;
		}
	}
	for(int i = size - 1; i > pa; i--){
		if(mat[pa][pb] <= mat[i][pb]){
			break;
		}
		if(i == pa + 1){
			return false;
		}
	}
	for(int i = 0; i < pb; i++){
		if(mat[pa][pb] <= mat[pa][i]){
			break;
		}
		if(i == pb - 1){
			return false;
		}
	}
	for(int i = size - 1; i > pb; i--){
		if(mat[pa][pb] <= mat[pa][i]){
			break;
		}
		if(i == pb + 1){
			return false;
		}
	}

	return true;
}

int main() {
	std::cin >> size;

	int visible = size * size;

	for (int i = 0; i < size; i++) {
		std::vector<int> copy;
		for (int j = 0; j < size; j++) {
			int c;
			std::cin >> c;
			if (c == 0) {
				visible--;
			}
			copy.push_back(c);
		}
		mat.push_back(copy);
	}

	for (int i = 1; i < size - 1; i++) {
		for (int j = 1; j < size - 1; j++) {
			if(mat[i][j] != 0 and checker(i, j)){
				visible--;
			}
		}
	}

	std::cout << visible;
	return 0;
}
