//============================================================================
// Name        : IzboriDrzaven.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

struct kand{
	int prv, vtor;
};

int main() {
	int kandidati, vtorkr;
	vector<kand> k;
	kand inp;
	cin>>kandidati>>vtorkr;

	for(int i = 0; i < kandidati; i++){
		cin>>inp.prv>>inp.vtor;
		k.push_back(inp);
	}

	int leadingnum, follower;

	for(int i = 0; i < kandidati - vtorkr; i++){
		leadingnum = 100000;
		for(int j = 0; j < k.size(); j++){
			if(leadingnum > k[j].prv){
				leadingnum = k[j].prv;
				follower = j;
			}
		}
		k[follower].prv = 100000;
		k[follower].vtor = 0;
	}
	leadingnum = 0;
	for(int i = 0; i < k.size(); i++){
		if(k[i].vtor > leadingnum){
			follower = i;
			leadingnum = k[i].vtor;
		}
	}

	cout<<follower + 1;
	return 0;
}
