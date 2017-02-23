//============================================================================
// Name        : Kalendar.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int mesec, godina;
	cin>>mesec>>godina;
	if(mesec == 4 or mesec == 6 or mesec == 9 or mesec == 11){
		cout<<30;
	} else if(mesec == 2){
		if(godina % 400 == 0 or (godina % 4 == 0 and godina % 100 != 0)){
			cout<<29;
		} else{
			cout<<28;
		}
	} else{
		cout<<31;
	}
	return 0;
}
