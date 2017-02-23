//============================================================================
// Name        : Slide.cpp
// Author      : Vladimir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

int num[i][j];

int main() {
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			std::cin >> num[i][j];

			if(num[i][j] == -1){
				empty = i * 4 + j;
			} else{
				num[i][j]--;
			}
		}
	}

	return 0;
}
