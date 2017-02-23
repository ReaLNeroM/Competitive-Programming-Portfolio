//============================================================================
// Name        : Brojot.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
using namespace std;

int main() {
	string broj, cifra;
	cin>>broj;
	int zbir = 0, num;
	for(int i = 0; i < broj.length();i++){
		cifra = broj[i];
		istringstream in(cifra);
		in>>num;
		zbir += num;
	}
	int cekori = 0, origzbir = zbir;
	while (zbir % 9 != 0){
		zbir += origzbir;
		cekori++;
	}

	cout<<cekori;
	return 0;
}
