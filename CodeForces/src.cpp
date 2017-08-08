#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
ll val[maxn];
std::set<ll> s;
ll n, k;
ll comp[maxn];

bool good(ll num, ll threshold){
	ll sum = 0;
	for(ll i = 0; i < n; i++){
		ll x = val[i] / num + (val[i] % num != 0);
		sum += x * num;
	}

	return sum <= threshold;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> k;

	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
		k += val[i];
	}

	ll best = 1;
	for(ll i = 1; i <= 1e6 + 1e2; i++){
		if(good(i, k)){
			best = i;
		}
	}

	for(ll i = 1; i * i <= 1e10; i++){
		for(ll j = 0; j < n; j++){
			if(val[j] / i > 1e6 + 1e2 and good(val[j] / i, k)){
				best = std::max(best, val[j] / i);
			}
		}
	}

	std::cout << best << std::endl;
}