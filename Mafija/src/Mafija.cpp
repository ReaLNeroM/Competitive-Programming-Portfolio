//============================================================================
// Name        : Mafija.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int komsii;
	cin>>komsii;

	int loc[komsii];
	float aritsredina = 0;
	for(int i = 0;i < komsii; i++){
		cin>>loc[i];
		aritsredina += loc[i];
	}

	aritsredina /= komsii;
	float closestnum = 1001;
	int follower;
	for(int i = 0; i < komsii; i++){
		if(abs(loc[i] - aritsredina) < closestnum){
			closestnum = abs(loc[i] - aritsredina);
			follower = i;
		}
	}
	cout<<loc[follower];

	return 0;
}
