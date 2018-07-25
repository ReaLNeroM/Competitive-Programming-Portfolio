#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 20;
ll power[maxn];
std::map<ll, ll> ma, mb;
const ll mod = 1e15 + 37;
ll res = 0LL;

int main(){
	ll n;
	std::cin >> n;

	power[0] = 1;
	for(ll i = 1; i <= n; i++){
		power[i] = power[i - 1] * 31LL;
		power[i] %= mod;
	}

	std::string s;
	std::cin >> s;

	for(ll i = 0; i < (1 << n); i++){
		ll ahash = 0;
		ll apow = 0;
		ll bpow = n - 1;
		for(ll j = 0, bit = 1; j < n; j++, bit *= 2){
			if(i & bit){
				ahash += (s[j] - 'a' + 1) * power[apow];
				apow++;
				ahash %= mod;
			} else {
				ahash -= (s[j] - 'a' + 1) * power[bpow];
				bpow--;
				ahash = ((ahash % mod) + mod) % mod;
			}
		}

		ma[ahash]++;
	}

	for(ll i = 0; i < (1 << n); i++){
		ll ahash = 0;
		ll apow = n - 1;
		ll bpow = 0;
		for(ll j = 2 * n - 1, bit = 1; j >= n; j--, bit *= 2){
			if(i & bit){
				ahash += (s[j] - 'a' + 1) * power[apow];
				apow--;
				ahash %= mod;
			} else {
				ahash -= (s[j] - 'a' + 1) * power[bpow];
				bpow++;
				ahash = ((ahash % mod) + mod) % mod;
			}
		}

		res += ma[mod - ahash];
	}

	std::cout << res << '\n';
}
