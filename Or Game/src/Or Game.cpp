#include <iostream>

typedef long long ll;

int main() {
	ll numbers, bonuses, multiplier;
	std::cin >> numbers >> bonuses >> multiplier;

	ll val[numbers], max = 0;
	for(ll i = 0; i < numbers; i++){
		std::cin >> val[i];
		if(val[i] > val[max]){
			max = i;
		}
	}

	for(int i = 0; i < bonuses; i++){
		val[max] *= multiplier;
	}

	ll oroper = 0;
	for(ll i = 0; i < numbers; i++){
		oroper |= val[i];
	}

	std::cout << oroper << std::endl;
	return 0;
}
