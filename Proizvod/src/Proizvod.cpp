//============================================================================
// Name        : Proizvod.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>

int main() {
	float fa, fb;
	std::cin>>fa>>fb;
	long long a = std::floor(fa * 100 + 0.5), b = std::floor(fb * 100 + 0.5);

	long long lcm = b;
	while(lcm % a != 0){
		lcm += b;
	}


	std::cout<<"KUPI "<<lcm / a<<" DOBIJ "<<lcm / b - lcm / a<<" GRATIS";
	return 0;
}
