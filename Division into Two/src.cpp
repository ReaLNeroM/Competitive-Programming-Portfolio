#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
const ll mod = 1e9 + 7;
ll n, a, b;
ll factorial[maxn];
ll pow2[maxn];
ll val[maxn];

ll inverse(ll x){
	ll m = mod - 2;

	ll res = 1;
	while(m){
		if(m % 2){
			res *= x;
			res %= mod;
		}

		x *= x;
		x %= mod;

		m /= 2;
	}

	return res;
}

int binomialCoefficient(int x, int y){
	return factorial[x] * inverse(factorial[x]) % mod * inverse(factorial[x - y]) % mod;
}

int countLessThan(int x){
	ll res = 0;

	for(int i = 0; i < n; i++){
		auto ite = std::lower_bound(val, val + n, val[i] + x);
		if(ite == &val[i]){
			continue;
		}

		int positions = (ite - &val[i]) - 1;
		res += pow2[positions];
		res %= mod;
	}

	return res;
}

int countLessThan(int x, int y){
	if(val[0] + x > val[n - 1]){
		return countLessThan(y);
	} else if(val[0] + y > val[n - 1]){
		return countLessThan(x);
	}

	ll res = 0;

	for(int i = 0; i < n - 1; i++){
		if(val[i] - val[0] < x){
			auto ite = std::upper_bound(val, val + n, val[n - 1] - y);

			int index = ite - &val[0];

			if(index < i){
				res += pow2[i - index];
			} else if(index == i or index - 1 == i){
				res += 1;
			}
		}
	}

	return res;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> a >> b;

	factorial[0] = 1;
	pow2[0] = 1;
	for(ll i = 1; i < maxn; i++){
		factorial[i] = (ll) factorial[i - 1] * i % mod;
		pow2[i] = pow2[i - 1] * 2 % mod;
	}

	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
	}

	ll res = pow2[n];

	res -= countLessThan(a);
	res %= mod;
	res -= countLessThan(b);
	res %= mod;
	res += countLessThan(a, b);
	res %= mod;
	res += countLessThan(b, a);
	res %= mod;

	std::cout << res << '\n';
}
