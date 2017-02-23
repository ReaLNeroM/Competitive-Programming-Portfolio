//============================================================================
// Name        : Nova.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int kab[5], prof, res = 0;
	for (int i = 0; i < 5; i++) {
		cin >> kab[i];
	}
	cin >> prof;
	for (int i = 0; i < prof - 1; i++) {
		res += kab[i];
	}
	if (res == 0) {
		cout << 100;
	} else if (res <= 5) {
		cout << 80;
	} else if (res <= 20) {
		cout << 60;
	} else {
		cout << 50;
	}
	return 0;
}
