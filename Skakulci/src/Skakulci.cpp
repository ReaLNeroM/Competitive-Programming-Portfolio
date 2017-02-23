//============================================================================
// Name        : Skakulci.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int in1, in2, in3;
	cin>>in1>>in2>>in3;
	if(in2 - in1 > in3 - in2){
		cout<<in2-in1-1;
	} else{
		cout<<in3-in2-1;
	}
	return 0;
}
