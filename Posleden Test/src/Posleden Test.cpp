//============================================================================
// Name        : Posleden.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int ocenka, test;
	cin>>ocenka;
	ocenka = 200 + 50 * ocenka;
	for(int i = 0; i < 4; i++){
		cin>>test;
		ocenka -= test;
	}

	if(ocenka > 100){
		cout<<"GRESHKA";
	} else{
		if(ocenka < 0){
			ocenka = 0;
		}
		cout<<ocenka;
	}
	return 0;
}
