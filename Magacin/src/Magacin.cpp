//============================================================================
// Name        : Magacin.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct restrikcija {
	int vrz;
	int pod;
};

bool rcomp(restrikcija x, restrikcija y){
	return (x.vrz < y.vrz);
}

int main() {
	int kutii;
	cin >> kutii;

	int k[kutii];
	for (int i = 0; i < kutii; i++) {
		cin >> k[i];
	}

	int restrikt;
	cin >> restrikt;
	restrikcija r[restrikt];

	for (int i = 0; i < restrikt; i++) {
		cin >> r[i].vrz >> r[i].pod;
		r[i].vrz--, r[i].pod--;
	}
	std::sort(r, r + restrikt, rcomp);

	vector<int> best, curr;
	int bestres = 1000000, curres;

	for(int i = 0; i < kutii; i++){
		curr.push_back(i);
	}

	do {
		curres = 0;
		for(int i = 0; i < kutii; i++){
			curres += i * k[curr[i]];
		}

		for(int i = 0; i < restrikt; i++){
			bool ok = false;

			for(int j = 0; curr[j] != r[i].vrz; j++){
				if(curr[j] == r[i].pod){
					ok = true;
					break;
				}
			}

			if(!ok){
				curres = 1000000;
			}
		}

		if(curres < bestres){
			bestres = curres;
			best = curr;
		}

	} while(next_permutation(curr.begin(), curr.end()));

	for(int i = 0; i < kutii; i++){
		std::cout << best[i] + 1 << " ";
	}

	return 0;
}
