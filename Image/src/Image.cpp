#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll combinations(ll n, ll k){
	if(k < n - k){
		k = n - k;
	}

	ll res = 1;

	for(ll i = k + 1; i <= n; i++){
		res *= i;
	}
	for(ll i = 1; i <= n - k; i++){
		res /= i;
	}

	return res;
}

ll n, m, k, f;
ll ways1 = 0;
ll ways0 = 0;

const ll mod = 1e9 + 7;
const ll maxn = 1e8 + 10;
ll dp[maxn];

struct matrix {
	ll v[101][101];
	matrix(){
		for(ll i = 0; i <= 100; i++){
			for(ll j = 0; j <= 100; j++){
				v[i][j] = 0;
			}
		}
	}
	void operator=(const matrix &x){
		for(ll i = 0; i <= 100; i++){
			for(ll j = 0; j <= 100; j++){
				v[i][j] = x.v[i][j];
			}
		}
	}
};

matrix operator*(const matrix &x, const matrix &y){
	matrix value;
	for(ll i = 0; i <= 100; i++){
		for(ll j = 0; j <= 100; j++){
			for(ll k = 0; k <= 100; k++){
				value.v[i][j] += x.v[i][k] * y.v[k][j];
				value.v[i][j] %= mod;
			}
		}
	}
	return value;
}

matrix eend, mult;
matrix my;

ll calc(){
	for(ll i = 0; i < k; i++){
		if(i == 0){
			mult.v[0][i] = ways1;
		} else {
			mult.v[0][i] = mult.v[0][i - 1] * ways0;
			mult.v[0][i] %= mod;
		}
	}
	for(ll i = 1; i < k; i++){
		mult.v[i][i - 1] = 1;
	}
	eend.v[0][0] = 1;
	for(ll i = 1; i <= n; i *= 2){
		if(i & n){
			eend = mult * eend;
		}

		mult = mult * mult;
	}

	ll res = 0;
	ll multiplier = 1;
	for(ll i = 0; i < k; i++){
		res += eend.v[i][0] * multiplier;
		res %= mod;
		multiplier *= ways0;
		multiplier %= mod;
	}
	return res;
}

ll brute(){
	dp[0] = 1;
	for(ll i = 1; i <= n + 1; i++){
		ll multiplier = ways1;
		if(i == n + 1){
			multiplier = 1;
		}
		dp[i] = 0;
		for(ll j = i - 1; j >= 0 and i - j <= k; j--){
			dp[i] += (multiplier * dp[j]) % mod;
			multiplier = (multiplier * ways0) % mod;
		}
	}

	return dp[n + 1];
}

int main(){
	cin >> m >> n >> k >> f;

	for(ll i = 0; i < f; i++){
		ways0 += combinations(m, i);
	}
	for(ll i = f; i <= m; i++){
		ways1 += combinations(m, i);
	}

	if(k <= 100){
		cout << calc() << endl;
	} else {
		cout << brute() << endl;
	}
}
