//============================================================================
// Name        : Moneti.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	cin>>a>>b>>c>>d;
	if(a + b + c + d == 0 or a + b + c + d == 20){
		cout<<0;
	} else if(a + b + c + d == 5 or a + b + c + d == 15){
		cout<<1;
	} else{
		cout<<2;
	}
	return 0;
}
