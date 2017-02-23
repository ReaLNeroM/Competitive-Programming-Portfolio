#include <iostream>
#include <utility>
#include <cmath>

typedef long long ll;

int main() {
	ll cases;
	std::cin >> cases;

	ll res[cases];
	for(ll test = 0; test < cases; test++){
		ll size;
		std::cin >> size;

		std::pair<ll, ll> pos[size * size];

		for(ll i = 0; i < size; i++){
			for(ll j = 0, inp; j < size; j++){
				std::cin >> inp;

				pos[inp - 1].first = i, pos[inp - 1].second = j;
			}
		}

		res[test] = 0;
		for(ll i = 1; i < size * size; i++){
			res[test] += std::abs(pos[i].first - pos[i - 1].first) + std::abs(pos[i].second - pos[i - 1].second);
		}
	}

	for(ll test = 0; test < cases; test++){
		std::cout << res[test] << std::endl;
	}
	return 0;
}
