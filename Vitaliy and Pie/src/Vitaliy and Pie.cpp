//============================================================================
// Name        : Vitaliy.cpp
// Author      : Vladimir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

int main() {
	int keysfor[26];
	for(int i = 0; i < 26; i++){
		keysfor[i] = 0;
	}
	std::string layout;
	std::cin >> layout >> layout;

	int needed = 0;
	for(int i = 0; i < layout.length(); i++){
		if(i % 2){
			if(keysfor[layout[i] - 65] > 0){
				keysfor[layout[i] - 65]--;
			} else{
				needed++;
			}
		} else{
			keysfor[layout[i] - 97]++;
		}
	}

	std::cout << needed;
	return 0;
}
