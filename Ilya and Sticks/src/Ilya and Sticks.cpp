#include <iostream>
#include <algorithm>

typedef long long ll;

int main() {
	ll sticks;
	std::cin >> sticks;

	ll length[sticks];
	for(ll i = 0; i < sticks; i++){
		std::cin >> length[i];
	}

	std::sort(length, length + sticks);

	ll i;
	for(i = sticks - 1; i > 0; i--){
		if(length[i] - length[i - 1] <= 1){
			break;
		}
	}
	i--;

	ll j;
	for(j = i - 2; j >= 0; j--){
		if(length[j + 1] - length[j] <= 1){
			break;
		}
	}

	if(j >= 0){
		std::cout << length[i + 1] * length[j + 1];
	} else {
		std::cout << 0;
	}
	return 0;
}
