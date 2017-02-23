//============================================================================
// Name        : Broj.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

int log(int contains){
	int result = 0;
	while(contains >= 10){
		contains /= 10;
		result++;
	}

	return (result + 1);
}

int main() {
	int contains = 0, a = 0, b = 0, result = 0;
	std::cin >> a >> b >> contains;
	int base = log(contains);
	do {
		int cop = a, copcont = contains, ite = 0;
		while (cop >= 1) {
			if (cop % 10 != copcont % 10) {
				ite = 0;
				copcont = contains;
			}
			if (cop % 10 == copcont % 10) {
				ite++;
				if (ite == base) {
					result++;
					break;
				}
				copcont /= 10;
			}
			cop /= 10;
		}

		a++;
	} while (a <= b);

	std::cout << result;
	return 0;
}
