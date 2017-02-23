#include <iostream>
#include <algorithm>
#include <utility>

typedef long long ll;

bool secondcompare(std::pair<ll, ll> a, std::pair<ll, ll> b){
	if(a.second < b.second){
		return true;
	}

	return false;
}
int main() {
	ll n;
	std::cin >> n;

	std::pair<ll, ll> val[n];
	for(ll i = 0; i < n; i++){
		std::cin >> val[i].first;
		val[i].second = i;
	}

	std::sort(val, val + n);

	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j < n; j++){
			if(	)
		}
	}

	return 0;
}
