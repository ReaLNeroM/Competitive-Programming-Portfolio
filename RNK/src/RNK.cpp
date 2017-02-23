//============================================================================
// Name        : RNK.cpp
// Author      : Vladimir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

int comb[][4] = { {0, 0, 1, 0},
				  {0, 0, 1, 1},
				  {1, 1, 0, 0},
				  {0, 1, 0, 0} };
int n;
int chain[200];
int res[200][200];

int formulate(int start, int end){
	if(end - start <= 1){
		return 0;
	}
	if(res[start][end] == -1){
		res[start][end] = 0;

		if(comb[chain[start]][chain[end]]){
			res[start][end] = 1 + formulate(start + 1, end - 1);
		}

		for(int i = start + 1; i < end; i++){
			res[start][end] = std::max(res[start][end], std::max(formulate(start, i - 1) + formulate(i, end), formulate(start, i) + formulate(i + 1, end)));
		}
	}

	return res[start][end];
}
int main() {
	std::cin >> n;

	for(int i = 0; i < n; i++){
		char c;
		std::cin >> c;
		chain[i] = (c =='G') + 2 * (c =='U') + 3 * (c =='C');
		for(int j = 0; j < n; j++){
			res[i][j] = -1;
		}
	}

	std::cout << formulate(0, n - 1);
	return 0;
}
