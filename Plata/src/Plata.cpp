//============================================================================
// Name        : Plata.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int pr, vt, tr;
	cin>>pr>>vt>>tr;

	if(vt - pr == tr - vt){
		cout<<tr + (tr - vt);
	} else{
		cout<<tr * (tr / vt);
	}
	return 0;
}
