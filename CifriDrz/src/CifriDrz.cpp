//============================================================================
// Name        : CifriDrz.cpp
// Author      : Vladimir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

std::string biggest = "0";

void remove(std::string broj, int cifri, int pos = 0) {
	if (cifri == 0) {
		biggest = std::max(broj, biggest);
		return;
	}

	std::string send = broj;
	for (int i = pos; i <= broj.length() - cifri; i++) {
		send.erase(send.begin() + i);
		remove(send, cifri - 1, i);
	//	std::cout << send << " " << cifri << " " << i << std::endl;
		send.insert(send.begin() + i, broj[i]);
	}

}

int main() {
	std::string broj;
	int cifri;

	std::cin >> broj >> cifri;

	remove(broj, cifri);

	std::cout << biggest;
	return 0;
}
