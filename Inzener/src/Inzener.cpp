//============================================================================
// Name        : Inzener.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

int main() {
	int brza, brzb, locb;
	std::cin >> brza >> brzb >> locb;

	int vrel=(((brzb*3)/4)-brza);
	if(vrel < 0){
		std::cout << "DA";
	} else{
		std::cout << "NE";
	}
	/*if (4 * brza > 3 * brzb) {
		std::cout << "DA";
	} else {
		std::cout << "NE";
	}*/
	return 0;
}
