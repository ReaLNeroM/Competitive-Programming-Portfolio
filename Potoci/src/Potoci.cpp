//============================================================================
// Name        : Potoci.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int incrzbir(int fpo) {
	int zbir = 0;
	while (fpo >= 1) {
		zbir += fpo % 10;
		fpo /= 10;
	}

	return zbir;
}

int main() {
	int potok;
	cin >> potok;
	int potok1 = 1, potok3 = 3, potok9 = 9, zbir;

	do {
		zbir = incrzbir(potok);
		while (potok1 < potok) {
			potok1 += incrzbir(potok1);
		}
		while (potok3 < potok) {
			potok3 += incrzbir(potok3);
		}
		while (potok9 < potok) {
			potok9 += incrzbir(potok9);
		}
		if (potok == potok1) {
			cout << 1 << " " << potok;
			break;
		}
		if (potok == potok3) {
			cout << 3 << " " << potok;
			break;
		} else if (potok == potok9) {
			cout << 9 << " " << potok;
			break;
		}
		potok += zbir;
	} while (true);

	return 0;
}
