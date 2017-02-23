//============================================================================
// Name        : DDV.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	string pr, petposto;
	double cena;
	int namal;
	bool finished = false;
	cin >> pr >> cena >> namal;

	for (int i = 0; i < namal; i++) {
		cin >> petposto;
		if (petposto == pr) {
			finished = true;
		}
	}
	if(!finished){
		cena += cena * 0.18;
	} else{
		cena += cena * 0.05;
	}

	cout.precision(5);
	cout<<fixed<<cena;
	return 0;
}
