//============================================================================
// Name        : Zadaci.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

int main() {
	int clen, zadaci;
	std::cin >> clen >> zadaci;

	int denovi = 0;
	while (zadaci > 0) {
		int maxpossible = 0;/*
		for (int i = clen - (clen % 5); i >= 0; i -= 5) {
			maxpossible = std::max(maxpossible, (i / 5) * 9 + ((clen - i) / 3) * 5);
		}*/
		maxpossible = std::max((clen / 3) * 5, (clen / 5) * 9);

		zadaci -= maxpossible;
		denovi++;
	}

	std::cout << denovi;
	return 0;
}
