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
		ll start1 = 0, start2 = 1, temp = 1;
		while(temp <= given){
			res[i]++;
			start1 = start2;
			start2 = temp;
			temp = start1 + start2;
		}

	}

	for(ll i = 0; i < cases; i++){
		std::cout << res[i] << std::endl;
	}
	return 0;
}
