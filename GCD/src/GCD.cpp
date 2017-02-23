#include <iostream>

typedef long long ll;

ll gcd(ll a, ll b){
	if(a % b == 0){
		return b;
	}

	return gcd(b, a % b);
}
int main() {
	ll a, b;
	std::cin >> a >> b;


	if(a < b){
		std::swap(a, b);
	}
	if(a == 0 or b == 0 or a * b < 0){
		std::cout << "Error";
	} else {
		std::cout << gcd(a, b);
	}
	return 0;
}
