//============================================================================
// Name        : Lisja.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int den, lisja, biggest = 0, follower;

	for(int i = 1; i <= 30; i++){
		cin>>den>>lisja;
		if(biggest < lisja){
			follower = den;
			biggest = lisja;
		}
	}

	cout<<follower<<" noemvri";
	return 0;
}
