#include <iostream>
#include <algorithm>

typedef long long ll;

int main() {
	ll people;
	std::cin >> people;

	ll wait[people];
	for(ll i = 0; i < people; i++){
		std::cin >> wait[i];
	}

	std::sort(wait, wait + people);

	ll waittime = 0;
	ll customers = 0;
	for(int i = 0; i < people; i++){
		if(waittime <= wait[i]){
			waittime += wait[i];
			customers++;
		}
	}

	std::cout << customers;
	return 0;

}
