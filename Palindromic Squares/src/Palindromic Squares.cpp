//============================================================================
// Name        : Palindromic.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>

bool checker(std::string copy) {
	for (int i = 0; i < (int) copy.length(); i++) {
		if (copy[i] != copy[copy.length() - 1 - i]) {
			return false;
		}
	}
	return true;
}

std::string bconvert(int copy, int base) {
	std::string convert;
	while (copy != 0) {
		if (copy % base < 10) {
			convert.insert(convert.begin(), 48 + copy % base);
		} else {
			convert.insert(convert.begin(), 55 + copy % base);
		}
		copy /= base;
	}
	return convert;
}

int main() {
	/*std::ifstream in;
	std::ofstream out;
	in.open("palsquare.in");
	out.open("palsquare.out");*/
	int base;
	std::cin >> base;

	for (int i = 1, root, square; i <= 300; i++) {
		std::string bnum, bsquare;
		root = i;
		square = i * i;

		bnum = bconvert(root, base);
		bsquare = bconvert(square, base);

		if (checker(bsquare)) {
			std::cout << bnum << " " << bsquare << std::endl;o
		}
	}
}
