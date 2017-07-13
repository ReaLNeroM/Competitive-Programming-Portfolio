#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
ll person[maxn];
ll key[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll n, k, p;
	std::cin >> n >> k >> p;

	for(ll i = 0; i < n; i++){
		std::cin >> person[i];
	}
	std::sort(person, person + n);

	for(ll i = 0; i < k; i++){
		std::cin >> key[i];
	}
	std::sort(key, key + k);

	ll sum = 1e18;
	for(ll i = 0; i + n <= k; i++){
		ll curr = 0;
		for(ll j = 0; j < n; j++){
			curr = std::max(curr, std::abs(key[i + j] - person[j]) + std::abs(key[i + j] - p));
		}

		sum = std::min(sum, curr);
	}

	std::cout << sum << std::endl;
}