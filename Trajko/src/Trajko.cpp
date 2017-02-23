//============================================================================
// Name        : Trajko.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	string com;
	cin>>com;
	long long i = 0, pari = 1;
	while(i < com.length()){
		if(com[i] == 't' || com[i] == 'T'){
			pari *= 3;
			i += 8;
		} else if(com[i] == 'd' || com[i] == 'D'){
			pari *= 2;
			i += 5;
		} else if(com[i] == 'm' || com[i] == 'M'){
			pari--;
			i += 5;
		} else{
			i++;
		}
	}

	cout<<abs(pari);
	return 0;
}
