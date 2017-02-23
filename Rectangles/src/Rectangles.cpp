//============================================================================
// Name        : Rectangles.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>

int main() {
	int rect;
	std::cin>>rect;
	int d[rect][2];
	int res[rect][2];

	for(int i = 0; i < rect; i++){
		std::cin >> d[i][0] >> d[i][1];
	}

	for(int i = rect - 1; i >= 0; i--){
		for(int j = 0; j < 2; j++){
			res[i][j] = 0;
			if(i != rect - 1){
				for(int k = 0; k < 2; k++){
					res[i][j] = std::max(res[i][j], res[i + 1][k] + (int) std::abs(d[i][(j + 1) % 2] - d[i + 1][(k + 1) % 2]));
				}
			}
			res[i][j] += d[i][j];
		}
	}
	std::cout << std::max(res[0][0], res[0][1]);
	return 0;
}
