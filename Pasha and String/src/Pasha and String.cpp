//============================================================================
// Name        : Pasha.cpp
// Author      : Vladimir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>

int main() {
	std::string str;
	std::cin >> str;
	int turns;
	std::cin >> turns;
	int changed[str.length()];
	for(int i = 0; i < str.length(); i++){
		changed[i] = 0;
	}

	for(int i = turns; i > 0; i--){
		std::cin >> turns;

		changed[turns - 1]++;

		if(changed[turns - 1] == 2){
			changed[turns - 1] = 0;
		}
	}

	int leftover = 0;
	for(int i = 0; i * 2 < str.length(); i++){
		if(leftover == 1 and changed[i] == 1){
			leftover = 0;
		} else if(leftover == 1){
			std::swap(str[i], str[str.length() - i - 1]);
		} else if(changed[i] == 1){
			leftover = 1;
			std::swap(str[i], str[str.length() - i - 1]);
		}
	}

	std::cout << str;
	return 0;
}
