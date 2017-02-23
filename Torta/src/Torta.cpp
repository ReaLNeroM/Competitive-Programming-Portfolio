//============================================================================
// Name        : Torta.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int eggpotr, vrsti, cenap = 10000, cenak = 10000, inp, ink;

	cin >> eggpotr >> vrsti;

	for (int i = 0; i < vrsti; i++) {
		cin >> ink >> inp;
		if (cenap > inp)
			cenap = inp;
		if (cenak > ink)
			cenak = ink;
	}

	int vred = 0;

	if (cenak < cenap * 6) {
		vred += eggpotr / 6 * cenak;
		if (eggpotr % 6 * cenap > cenak) {
			vred += cenak;
		} else {
			vred += eggpotr % 6 * cenap;
		}
	} else {
		vred += eggpotr * cenap;
	}

	cout << vred;
	return 0;
}
