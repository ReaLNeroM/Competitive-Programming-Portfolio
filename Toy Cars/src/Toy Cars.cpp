#include <iostream>
#include <vector>

typedef long long ll;

int main() {
	ll size;
	std::cin >> size;

	std::vector<ll> good;
	for(ll i = 0; i < size; i++){
		bool flag = false;
		for(ll j = 0, inp; j < size; j++){
			std::cin >> inp;
			if(inp % 2 == 1){
				flag = true;
			}
		}
		if(!flag){
			good.push_back(i + 1);
		}
	}

	std::cout << good.size() << std::endl;

	for(ll i = 0; i < good.size(); i++){
		std::cout << good[i] << ' ';
	}
	return 0;
}
