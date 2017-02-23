//============================================================================
// Name        : Fudbal.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int tima;
	cin >> tima;
	int win, draw, loss, maxnum = 0;
	for (int i = 0; i < tima; i++) {
		cin >> win >> draw >> loss;
		if (3 * win + draw > maxnum) {
			maxnum = 3 * win + draw;
		}
	}

	cout << maxnum;
	return 0;
}
