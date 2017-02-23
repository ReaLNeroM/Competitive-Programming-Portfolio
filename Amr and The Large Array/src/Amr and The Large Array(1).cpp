#include <iostream>
#include <map>

typedef long long ll;

int main() {

	std::map<ll, ll> occurred;

	ll size;
	std::cin >> size;

	ll array[size];

	ll biggest = 0;
	for(ll i = 0; i < size; i++){
		std::cin >> array[i];
		occurred[array[i]]++;

		if(occurred[array[i]] > occurred[biggest]){
			biggest = array[i];
		}
	}

	for(ll i = 0; i < size; i++){
		if(array[i] == biggest){
			std::cout << i + 1;
			break;
		}
	}

	for(ll i = size - 1; i >= 0; i--){
		if(array[i] == biggest){
			std::cout << " " << i + 1;
			break;
		}
	}
	return 0;
}
