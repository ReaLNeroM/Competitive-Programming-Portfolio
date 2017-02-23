//============================================================================
// Name        : Izbori.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int kand;
	cin>>kand;
	kand--;
	int trpe, repr[kand];
	cin>>trpe;
	int origtrpe = trpe;
	for(int i = 0; i < kand; i++){
		cin>>repr[i];
	}
	sort(repr, repr + kand);
	for(int i = 0; i < kand; i++){
		while(repr[i] >= trpe){
			trpe++;
			*(max_element(repr, repr + kand)) -= 1;
		}
	}

	cout<<trpe - origtrpe;
	return 0;
}
