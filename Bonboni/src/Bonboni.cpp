/*
//============================================================================
// Name        : Bonboni.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

std::vector<long> nino;
std::vector<long> tino;

int main() {
	long n;
	std::cin >> n;

	long curr = 1, cn = n;
	while (n != 0) {
		if (n % 3 == 1) {
			tino.push_back(curr);
			n--;
		} else if (n % 3 == 2) {
			nino.push_back(curr);
			n++;
		}

		if (n % 3 == 0) {
			n /= 3;
		}
		curr *= 3;
	}

	bool outted = false;
	for (long i = 0; i < nino.size(); i++) {
		std::cout << nino[i] << " ";
		if (nino[i] > cn) {
			std::cout << cn << " ";
			outted++;
		}
	}
	if(!outted){
		std::cout << cn;
	}
	std::cout << std::endl;
	for (long i = 0; i < tino.size(); i++) {
		std::cout << tino[i] << " ";
	}
	return 0;
}
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main(){
	int n;
	std::cin >> n;

	int p = 1;
	while(n > p){
		p *= 3;
	}

	std::vector<int> a, b;
	while(p >= 1){
		if(p <= n){
			b.push_back(p);
		} else {

		}
		p /= 3;
	}

	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	for(int i = 0; i < a.size(); i++){
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	for(int i = 0; i < b.size(); i++){
		std::cout << b[i] << " ";
	}
}
