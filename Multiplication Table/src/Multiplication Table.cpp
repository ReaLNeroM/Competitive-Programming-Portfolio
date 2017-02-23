#include <iostream>

typedef long long ll;

int main() {
	ll size, number;
	std::cin >> size >> number;

	ll res = 0;
	for(ll i = 1; i <= size; i++){
		if(number % i == 0 and number <= i * size){
			res++;
		}
	}

	std::cout << res;
	return 0;
}
