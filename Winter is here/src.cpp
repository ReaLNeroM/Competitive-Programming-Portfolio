#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
const ll mod = 1e9 + 7;

ll v[maxn];
ll previous[maxn];
ll pow2[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	pow2[0] = 1;
	for(ll i = 1; i < maxn; i++){
		pow2[i] = pow2[i - 1] * 2;	
		pow2[i] %= mod;
	}

	ll n;
	std::cin >> n;

	for(ll i = 0; i < n; i++){
		ll val;
		std::cin >> val;
		v[val]++;
	}

	ll res = 0;

	for(ll i = maxn - 1; i >= 2; i--){
		ll found = 0;
		ll sec = 0;
		for(ll j = i; j < maxn; j += i){
			found += v[j];
			sec += previous[j];
		}

		if(found){
			res += (pow2[found - 1] * found - sec) % mod * i % mod;
			previous[i] = (pow2[found - 1] * found - sec) % mod;
			res %= mod;
		}
	}

	std::cout << res << std::endl;
}	