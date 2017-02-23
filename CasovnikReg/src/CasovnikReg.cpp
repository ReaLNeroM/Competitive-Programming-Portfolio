//============================================================================
// Name        : CasovnikReg.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int hr, min, hr1, min1;
	cin>>hr>>min>>hr1>>min1;

	if (hr * 60 + min > hr1 * 60 + min1)
		hr1 += 24;

	hr1 = hr1 * 60 + min1 - (hr * 60 + min);

	if(hr1 / 60 < 10)
		cout<<"0";
	cout<<hr1/60<<":";

	if(hr1 % 60 < 10)
		cout<<"0";
	cout<<hr1%60;

	return 0;
}
