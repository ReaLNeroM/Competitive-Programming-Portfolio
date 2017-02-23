//============================================================================
// Name        : Coins.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

// problemo e test case-o kaj so 3kata ja nema a posle ja ima

struct moneta {
	bool could = true;
	char znak = '0';
} m[12];

int main() {
	bool contradictory = false;
	for (int i = 0; i < 3; i++) {
		int b[8];
		char znak;
		for (int j = 0; j < 8; j++) {
			cin >> b[j];
			b[j]--;
			if (j == 3) {
				cin >> znak;
			}
		}

		if (znak == '=') {
			for (int j = 0; j < 8; j++) {
				if(m[b[j]].znak == '<' or m[b[j]].znak == '>'){
					contradictory = true;
				}
				m[b[j]].znak = '=';
				m[b[j]].could = false;
			}
		} else {
			for (int i = 0; i < 12; i++){
				int j;
				for(j = 0; j < 8; j++){
					if(i == b[j]){
						break;
					}
				}
				if(j == 8){
					m[i].could = false;
				}
			}
			for (int j = 0; j < 8; j++) {
				if (j == 4 and znak == '>') {
					znak = '<';
				} else if (j == 4 and znak == '<') {
					znak = '>';
				}

				if (m[b[j]].znak == '0') {
					m[b[j]].znak = znak;
				} else if (znak != m[b[j]].znak) {
					contradictory = true;
					m[b[j]].could = false;
				}
			}
		}
	}

	int possible = 0;
	for(int i = 0; i < 12; i++){
		possible += m[i].could;
	}

	if(possible == 0){
		std::cout << "impossible";
	} else if(possible > 1){
		std::cout << "indefinite";
	} else {
		for(int i = 0; i < 12; i++){
			if(m[i].could){
				std::cout << i + 1;
				if(m[i].znak == '<'){
					std::cout << '-';
				} else {
					std::cout << '+';
				}
			}
		}
	}
	return 0;
}
