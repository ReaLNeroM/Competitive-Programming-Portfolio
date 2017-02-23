#include <iostream>

typedef long long ll;

int main() {
	ll max;
	std::cin >> max;

	ll res = 0;
	for(ll i = 2; i <= max; i++){
		bool prime = true;

		if((i % 2 == 0 or i % 3 == 0) and i >= 4){
			prime = false;
		}
		for(ll j = 6; j * 2 <= i + 3; j += 6){
			if((i % (j - 1) == 0) or (i % (j + 1) == 0)){
				prime = false;
				break;
			}
		}
		if(prime){
			for(ll power = i; power <= max; power *= i){
				res++;
			}n
		}
	}

	std::cout << res << std::endl;

	for(ll i = 2; i <= max; i++){
		bool prime = true;

		if((i % 2 == 0 or i % 3 == 0) and i >= 4){
			prime = false;
		}
		for(ll j = 6; j * 2 <= i + 3; j += 6){
			if((i % (j - 1) == 0) or (i % (j + 1) == 0)){
				prime = false;
				break;
			}
		}

		if(prime){
			for(ll power = i; power <= max; power *= i){
				std::cout << power << " ";
			}
		}
	}

	return 0;
}
