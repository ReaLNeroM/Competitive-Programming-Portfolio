#include <iostream>

typedef long long ll;

int main() {
	ll candidates, cities;
	std::cin >> candidates >> cities;

	ll votes[candidates];
	for(ll i = 0; i < candidates; i++){
		votes[i] = 0;
	}

	ll maxcities = 0, maxcitiespos = 0;

	for(ll i = 0; i < cities; i++){
		ll maxvotes = 0, maxpos = 0;
		for(ll j = 0, inp; j < candidates; j++){
			std::cin >> inp;
			if(inp > maxvotes){
				maxvotes = inp;
				maxpos = j;
			}
		}

		votes[maxpos]++;

		if(votes[maxpos] > maxcities or (votes[maxpos] == maxcities and maxpos < maxcitiespos)){
			maxcities = votes[maxpos];
			maxcitiespos = maxpos + 1;
		}
	}

	std::cout << maxcitiespos;
	return 0;
}
