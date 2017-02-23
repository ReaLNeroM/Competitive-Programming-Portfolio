//============================================================================
// Name        : Ekspanzija.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cctype>
using namespace std;

int main() {
	string kompr;
	cin>>kompr;
	int times = 0;
	for(int i = 0; i < kompr.length(); i++){
		if(isdigit(kompr[i])){
			times = kompr[i] - 48;
		} else{
			if(times == 0)
				times++;
			for(int j = 0; j < times; j++){
				cout<<kompr[i];
			}
			times = 1;
		}
	}
	return 0;
}
