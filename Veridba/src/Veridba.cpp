//============================================================================
// Name        : Veridba.cpp
// Author      : Vladimir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

std::vector<long long> pomal, pogolem;

int main() {
	long long a, b, clenovi;
	std::cin >> a >> b >> clenovi;


	long long calc = std::floor(std::sqrt(clenovi));
	for(long long i = 1; i <= calc; i++){
		if(clenovi % i == 0){
			pomal.push_back(i);
			pogolem.push_back(clenovi / i);
		}
	}

	if(a > b){
		std::swap(a, b);
	}

	long long res = 3;
	for(long long i = 0; i < pomal.size(); i++){
		if(pomal[i] == a and pogolem[i] == b){
			res = 0;
			break;
		} else if((pomal[i] == a and pogolem[i] <= b) or (pogolem[i] == b and pomal[i] <= a) or (pogolem[i] == a and pomal[i] <= b) or (pomal[i] == b and pogolem[i] <= a)){
			res = std::min((long long) 1, res);
		} else if(pomal[i] < a and pogolem[i] < b){
			res = std::min((long long) 2, res);
		}
	}

	if(res == 3){
		res = -1;
	}

	std::cout << res;
	return 0;
}
