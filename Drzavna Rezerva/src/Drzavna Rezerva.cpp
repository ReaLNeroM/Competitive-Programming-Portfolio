//============================================================================
// Name        : Drzavna.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int potr, proiz, cen, k;
	cin >> potr >> proiz;
	vector<int> kg;
	vector<int> cena;

	for (int i = 0; i < proiz; i++) {
		cin >>cen>>k;
		cena.push_back(cen);
		kg.push_back(k);
	}

	int min, follower, denari = 0;

	while(true){
		min = 100000;
		for (int j = 0; j < cena.size(); j++) {
			if (min > cena[j]) {
				min = cena[j];
				follower = j;
			}
		}
		if (potr <= kg[follower]) {
			denari += potr * cena[follower];
			break;
		} else {
			denari += kg[follower] * cena[follower];
			potr -= kg[follower];
		}
		cena.erase(cena.begin() + follower);
		kg.erase(kg.begin() + follower);
	}

	cout << denari;
	return 0;
}
