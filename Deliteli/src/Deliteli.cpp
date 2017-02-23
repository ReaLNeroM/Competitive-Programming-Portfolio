//============================================================================
// Name        : Deliteli.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct del {
	int broj = 1;
	int deliteli = 0;
} maks[2];

int main() {
	int op1, op2;
	cin >> op1 >> op2;

	for (int i = op1; i	 <= op2; i++) {
		maks[1].broj = i;
		maks[1].deliteli = 0;
		for (int j = 1; j <= i / 2; j++) {
			if (i % j == 0) {
				maks[1].deliteli++;
			}
		}
		if (maks[1].deliteli > maks[0].deliteli) {
			maks[0].deliteli = maks[1].deliteli;
			maks[0].broj = maks[1].broj;
		}
	}

	cout << maks[0].broj << " " << maks[0].deliteli + 1;
	return 0;
}
