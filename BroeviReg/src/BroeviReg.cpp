//============================================================================
// Name        : BroeviReg.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

int main() {
	int a, b;
	std::cin>>a>>b;
	int zbir = 0;
	for(int copy = a, digit[4]; a <= b; a++, copy = a){
		for(int a = 0; copy >= 1; a++, copy /= 10){
			digit[a] = copy % 10;
		}

		if(digit[0] > digit[1] and digit[1] > digit[2] and digit[2] > digit[3]){
			zbir++;
		}
	}

	std::cout<<zbir;
	return 0;
}
