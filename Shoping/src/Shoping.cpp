//============================================================================
// Name        : Shoping.cpp
// Author      : 
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int prod;
	double popust;
	cin>>prod>>popust;
	popust = (100 - popust) / 100;
	double cena[prod];

	for(int i = 0; i < prod; i++){
		cin>>cena[i];
	}
	sort(cena, cena + prod);
	reverse(cena, cena + prod);
	double result = 0;
	int i = 0;
	for(; i < prod / 3; i++){
		result += cena[i] * popust;
	}
	for(; i < prod; i++){
		result += cena[i];
	}
	cout.precision(2);
	cout<<fixed<<result;
	return 0;
}
