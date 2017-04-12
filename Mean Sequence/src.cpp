#include <iostream>

typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);
	
	ll n;
	std::cin >> n;

	ll smallest = -1000000000;
	ll largest = 1000000000;

	for(ll i = 0; i < n; i++){
		ll val;
		std::cin >> val;

		largest = std::min(largest, val);

		ll next_smallest = 2 * val - largest;
		ll next_largest = 2 * val - smallest;

		next_smallest = std::max(next_smallest, largest);

		if(next_smallest > next_largest){
			std::cout << 0 << std::endl;
			return 0;
		}

		smallest = next_smallest;
		largest = next_largest;
	}

	std::cout << std::max(0LL, largest - smallest + 1LL);
}