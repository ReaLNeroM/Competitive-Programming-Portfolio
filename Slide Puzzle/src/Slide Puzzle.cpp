//============================================================================
// Name        : Slide.cpp
// Author      : Vladimir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

int iddfs(int empty, int depth, int num[4][4]) {
	bool good = true;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i * 4 + j != empty and num[i][j] != i * 4 + j) {
				good = false;
				break;
			}
		}
	}
	if (good) {
		return depth;
	}

	if (depth == 0) {
		return -1;
	}

	int send = 100000, copy;

	for(int k = 0; k <= 1; k++){
		for(int i = -1; i <= 1; i += 2){
			if(empty / 4 + k * i < 0 or empty / 4 + k * i >= 4 or empty % 4 + (1 - k) * i < 0 or empty % 4 + (1 - k) * i >= 4){
				continue;
			}
			std::swap(num[empty / 4][empty % 4], num[empty / 4 + k * i][empty % 4 + (1 - k) * i]);
			copy = iddfs(empty + (3 * k + 1) * i, depth - 1, num);
			std::swap(num[empty / 4][empty % 4], num[empty / 4 + k * i][empty % 4 + (1 - k) * i]);
			if (copy != -1) {
				send = std::min(send, copy);
			}
		}
	}
	return (send == 100000) ? -1 : send;
}

int main() {
	int num[4][4];
	int empty = -1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cin >> num[i][j];
			if (num[i][j] == -1) {
				empty = i * 4 + j;
			} else{
				num[i][j]--;
			}
		}
	}

	for (int i = 0; i <= 15; i++) {
		int res = iddfs(empty, i, num);
		if (res != -1) {
			std::cout << i - res << std::endl;
			break;
		} else if(i == 15){
			std::cout << res << std::endl;
		}
	}
	return 0;
}
