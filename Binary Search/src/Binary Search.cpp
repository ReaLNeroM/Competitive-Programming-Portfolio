#include <iostream>
#include <vector>

typedef long long ll;

ll find(std::vector<ll> array, ll target) {
	ll low = 0, high = array.size() - 1;
	while(low <= high){
		ll mid = (low + high) / 2;

		if(array[mid] == target)
			return mid;

		if(array[mid] < target){
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	return -1;
}

int main() {
	ll n, goal;
	std::cin >> n >> goal;

	std::vector<ll> array;
	array.resize(n);
	for(ll i = 0; i < n; i++){
		std::cin >> array[i];
	}

	std::cout << find(array, goal);
	return 0;
}
