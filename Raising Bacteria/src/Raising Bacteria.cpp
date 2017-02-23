#include <iostream>

typedef long long ll;

int main() {
	ll n;
	std::cin >> n;

	ll res = 0;
	for(ll i = 1; i <= n; i *= 2){
		if(i & n){
			res++;
		}
	}

	std::cout << res;
	return 0;
}
