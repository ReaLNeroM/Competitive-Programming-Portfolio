//============================================================================
// Name        : FaktorielDnev.cpp
// Author      : Vladimir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	int cifri;
	std::cin >> cifri;

	int atcurr = 0;
	double log = 0;

	std::vector<int> possibles;
	do {
		atcurr++;
		log += std::log10(atcurr);
		if ((int) log + 1 == cifri) {
			possibles.push_back(atcurr);
		}
	} while (log <= cifri);

	if (possibles.empty()) {
		std::cout << "NO";
	} else {
		std::cout << possibles.size() << std::endl;
		for (int i = 0; i < possibles.size(); i++) {
			std::cout << possibles[i] << std::endl;
		}
	}
	return 0;
}
