//============================================================================
// Name        : Ocenuvanje.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <deque>
#include <algorithm>

using ll = long long;

int main() {
	ll natprev, prover;
	std::cin >> natprev >> prover;
	std::deque<ll> resenija(natprev);
	for (ll i = 0; i < natprev; i++) {
		std::cin >> resenija[i];
	}

	while(prover > 0 and !resenija.empty()){
		if(resenija.front() * resenija.size() <= prover){
			int front = resenija.front();
			prover -= front * resenija.size();

			for(int i = resenija.size(); i > 0 and !resenija.empty(); i--){
				if(resenija.front() - front > 0){
					resenija.push_back(resenija.front() - front);
				}

				resenija.pop_front();
			}
		} else{
			if(resenija.front() != 1){
				resenija.push_back(resenija.front() - 1);
			}
			resenija.pop_front();
			prover--;
		}
	}

	std::cout << resenija.size();
	return 0;
}
