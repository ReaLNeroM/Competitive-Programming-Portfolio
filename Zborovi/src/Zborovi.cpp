//============================================================================
// Name        : Zborovi.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int lista[26], zborovi, leadingnum = 0;
	char ch;
	string follower;
	for(int i = 0; i < 26; i++){
		cin>>ch;
		cin>>lista[ch - 97];
	}
	cin>>zborovi;

	for(int i = 0; i < zborovi; i++){
		string zbor;
		int vrednost = 0;
		cin>>zbor;
		for(int j = 0; j < (int) zbor.length(); j++){
			if(zbor[i] < 97){
				vrednost += 20;
				vrednost += lista[zbor[j] - 65];
			} else {
				vrednost += lista[zbor[j] - 97];
			}
		}
		if(vrednost > leadingnum){
			leadingnum = vrednost;
			follower = zbor;
		}
	}

	cout<<follower;
	return 0;
}
