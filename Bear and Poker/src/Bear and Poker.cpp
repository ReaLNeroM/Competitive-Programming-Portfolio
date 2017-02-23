#include <iostream>
#include <algorithm>

typedef long long ll;

int main() {
	std::ios_base::sync_with_stdio(false);

	ll bears;
	std::cin >> bears;

	ll bid[bears];
	for(ll i = 0; i < bears; i++){
		std::cin >> bid[i];
		while(bid[i] % 2 == 0){
			bid[i] /= 2;
		}
		while(bid[i] % 3 == 0){
			bid[i] /= 3;
		}
		if(i > 0 and bid[i] != bid[i - 1]){
			std::cout << "No";
			return 0;
		}
	}

	std::cout << "Yes";
	return 0;
}
