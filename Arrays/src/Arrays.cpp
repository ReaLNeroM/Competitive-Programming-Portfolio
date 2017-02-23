#include <iostream>
#include <algorithm>

typedef long long ll;

int main() {
	ll asize, bsize;
	std::cin >> asize >> bsize;

	ll apick, bpick;
	std::cin >> apick >> bpick;

	ll a[asize], b[bsize];
	for(ll i = 0; i < asize; i++){
		std::cin >> a[i];
	}
	for(ll i = 0; i < bsize; i++){
		std::cin >> b[i];
	}

	if(a[apick - 1] < b[bsize - bpick]){
		std::cout << "YES";
	} else {
		std::cout << "NO";
	}
	return 0;
}
