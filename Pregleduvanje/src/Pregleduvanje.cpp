//============================================================================
// Name        : Pregleduvanje.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <limits.h>

int main() {
	int zad, dog;
	std::cin>>zad>>dog;

	int min = INT_MAX, ite = 1, result = 0, follower = 1;

	do{
		result = dog * ((ite * (ite - 1)) / 2);

		result += std::ceil(float(zad) / ite);

		if(result < min){
			follower = ite;
			min = result;
			ite++;
		} else{
			break;
		}
	} while(true);

	std::cout<<follower;
	return 0;
}
