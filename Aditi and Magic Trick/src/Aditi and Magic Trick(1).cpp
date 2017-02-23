#include <iostream>

typedef long long ll;

int main() {
	ll cases;
	std::cin >> cases;

	ll res[cases];

	for(ll i = 0; i < cases; i++){
		ll given;
		std::cin >> given;

		res[i] = 0;
		while(given > 1){
			given >>= 1;
			res[i]++;
		}
		res[i]++; // given is 1, 1 should be counted too
	}

	for(ll i = 0; i < cases; i++){
		std::cout << res[i] << std::endl;
	}
	return 0;
}
