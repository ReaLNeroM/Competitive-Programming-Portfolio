//============================================================================
// Name        : Igra.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int turns, a, l = 0, l1 = 0;
	cin >> turns;
	for (int i = 0; i < turns; i++) {
		cin >> a;
		if (a == 1) {
			l1++;
		} else {
			l1 = 0;
		}
		if (l1 > l) {
			l = l1;
		}
	}

	cout << l;
	return 0;
}
