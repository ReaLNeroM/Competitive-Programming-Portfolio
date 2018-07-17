#include <bits/stdc++.h>

typedef long long ll;

const ll maxbit = 55;
const ll mod = 1234567;
const ll start = 51;

ll n, k;
ll binomial[maxbit][maxbit];
ll left[maxbit];

ll res = 0;

int main(){
	std::ios::sync_with_stdio(false);

	#ifndef local
		// freopen("hn.in", "r", stdin);
		// freopen("hn.out", "w", stdout);
	#endif

	std::cin >> n >> k;

	for(ll i = 0; i < maxbit; i++){
		for(ll j = 0; j <= i; j++){
			if(i == 0 or j == 0 or j == i){
				binomial[i][j] = 1;
			} else {
				binomial[i][j] = binomial[i - 1][j] + binomial[i - 1][j - 1];
				binomial[i][j] %= mod;
			}
		}
	}

	left[start + 1] = k;

	for(ll i = start, bit = (1LL << (start)); i >= 0; i--, bit /= 2){
		if(n & bit){
			left[i] = left[i + 1] - 1;
		} else {
			left[i] = left[i + 1];
		}
	}

	for(ll i = 1, bit = 1; bit <= n; i++, bit *= 2){
		ll value = ((bit & n) != 0);
		for(ll j = start, bit2 = (1LL << (start - 1)); j > i; j--, bit2 /= 2){
			if((n & bit2) and left[j] > 0){
				res += bit % mod * binomial[j - 2][left[j] - 1] % mod;
				res %= mod;
			}
		}

		if(value){
			for(ll j = i - 1, bit2 = bit / 2; j > 0; j--, bit2 /= 2){
				if((n & bit2) and left[j] + 1 > 0){
					res += bit % mod * binomial[j - 1][left[j - 1] + 1] % mod;
					res %= mod;
				}
			}
		}
	}

	std::cout << res << '\n';
}
