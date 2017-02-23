//============================================================================
// Name        : Ostatok.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	bool mod[42] = {0};
	unsigned int num, raz = 0;

	for(int i = 0; i < 10; i++){
		cin>>num;
		if(!mod[num % 42]){
			raz++;
			mod[num % 42] = true;
		}
	}

	cout<<raz;
	return 0;
}
