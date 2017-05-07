#include <bits/stdc++.h>

typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);

	ll t;
	std::cin >> t;

	for(ll cc = 0; cc < t; cc++){
		ll a, b, p, q;
		std::cin >> a >> b >> p >> q;

		if(p == 0){
			if(a == 0){
				std::cout << 0 << '\n';
			} else {
				std::cout << "-1\n";
			}
		} else if(p == q){
			if(a == b){
				std::cout << 0 << '\n';
			} else {
				std::cout << "-1\n";
			}
		} else {
			ll k = 1;
			k = std::max(k, a / p + (a % p != 0));
			k = std::max(k, b / q + (b % q != 0));
			k = std::max(k, (b - a) / (q - p) + ((b - a) % (q - p) != 0));

			std::cout << k * q - b << std::endl;
		}
	}
}