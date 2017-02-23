//============================================================================
// Name        : Stepeni.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int br;
	cin >> br;
	for (int trans = 0; trans != 2; trans++, br++) {
		if ((br * br - br + 2) / 2 == br) {
			cout << 1 << " ";
		} else {
			cout << 0 << " ";
		}
	}
	return 0;
}
