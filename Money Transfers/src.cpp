#include <bits/stdc++.h>

typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);

	ll n;
	std::cin >> n;

	std::map<ll, ll> m;

	ll prefix_sum = 0;

	ll biggest_value = 0;
	for(ll i = 0; i < n; i++){
		ll balance;
		std::cin >> balance;
		prefix_sum += balance;

		m[prefix_sum]++;
		biggest_value = std::max(biggest_value, m[prefix_sum]);
	}

	std::cout << n - biggest_value << '\n';
}