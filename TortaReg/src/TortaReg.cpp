//============================================================================
// Name        : TortaReg.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <sstream>

int main() {
	long long index, ripanje = 0, currnum = 0;
	std::cin >> index;

	while (index - ripanje > 0) {
		index -= ripanje;
		currnum++;
		ripanje += std::log10(currnum) + 1;
	}

	std::ostringstream os;
	for(int i = 1; i <= currnum; i++){
		os << i;
	}

	std::string str = os.str();
	std::cout << str[index - 1];
	return 0;
}
