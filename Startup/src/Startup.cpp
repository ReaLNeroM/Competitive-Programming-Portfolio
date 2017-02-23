#include <iostream>
#include <set>

typedef long long ll;

int main() {
	std::ios::sync_with_stdio(false);
	ll n;
	std::cin >> n;

	ll val[n], lastsum = 0;
	std::multiset<ll> occur;
	for(ll i = 0; i < n; i++){
		std::cin >> val[i];

		lastsum += val[i];
		occur.insert(lastsum);
	}

	ll res = 0, change = 0;
	for(ll i = 0; i < n; i++){
		if(*occur.begin() >= change){
			res++;
		}

		change += val[i];
		occur.erase(occur.find(change));
		occur.insert(lastsum + change);

	}

	std::cout << res;
	return 0;
}
