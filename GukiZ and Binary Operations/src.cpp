#include <bits/stdc++.h>

typedef long long ll;

ll mod;

ll exp(ll a, ll b){
	ll res = 1;

	ll a_generated = a;
	for(ll i = 1; i <= b; i *= 2){
		if(i & b){
			res *= a_generated;
			res %= mod;
		}

		a_generated *= a_generated;
		a_generated %= mod;
	}

	return res;
}

ll fib(ll n){
	std::vector<std::vector<ll>> res = {{1, 1}, {1, 0}};

	std::vector<std::vector<ll>> temp = {{1, 1}, {1, 0}};
	for(ll i = 1; i <= n; i *= 2){
		if(i & n){
			auto new_v = res;

			for(int j = 0; j < 2; j++){
				for(int k = 0; k < 2; k++){
					new_v[j][k] = 0;
					for(int l = 0; l < 2; l++){
						new_v[j][k] += res[j][l] * temp[l][k];
						new_v[j][k] %= mod;
					}
				}
			}

			res = new_v;
		}

		auto new_v = res;

		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				new_v[j][k] = 0;
				for(int l = 0; l < 2; l++){
					new_v[j][k] += temp[j][l] * temp[l][k];
					new_v[j][k] %= mod;
				}
			}
		}

		temp = new_v;
	}

	return res[1][1];
}

int main(){
	ll n, k, l;
	std::cin >> n >> k >> l >> mod;

	ll max = 1;
	ll ones = 0;
	ll zeroes = 0;
	for(int i = 0; i < l; i++){
		if(max & k){
			ones++;
		} else {
			zeroes++;
		}

		if(max > k){
			zeroes += l - i - 1;
			break;
		}

		max *= 2;
	}

	if(max <= k or mod == 1){
		std::cout << 0 << std::endl;
		return 0;
	}

	ll res = 1;

	ll zero_fib = fib(n + 2);
	for(int i = 0; i < zeroes; i++){
		res *= zero_fib;
		res %= mod;
	}

	ll one_fib = exp(2, n) - zero_fib;

	if(one_fib < 0){
		one_fib += mod;
	}

	for(int i = 0; i < ones; i++){
		res *= one_fib;
		res %= mod;
	}

	std::cout << res << std::endl;
}