#include <iostream>

typedef long long ll;

ll done[100000][2];

int main() {
	std::ios_base::sync_with_stdio(false);

	ll towers;
	std::cin >> towers;
	ll height[towers], distance[towers];
	for(ll i = 0; i < towers; i++){
		std::cin >> height[i];
		distance[i] = towers;
	}

	distance[0] = (height[0] > 0);
	distance[towers - 1] = (height[towers - 1] > 0);
	for(ll i = 1; i < towers - 1; i++){
		distance[i] = std::min(height[i], distance[i - 1] + 1);
	}

	ll curr = distance[towers - 1];
	ll max = curr;
	for(ll j = towers - 2; j > 0; j--){
		curr = std::min(distance[j], curr + 1);
		max = std::max(max, curr);
	}

	std::cout << max;
	return 0;
}
