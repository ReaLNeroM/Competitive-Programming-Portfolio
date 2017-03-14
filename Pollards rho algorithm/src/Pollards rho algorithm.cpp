#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll gcd(ll a, ll b){
	while(b != 0){
		ll temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

ll f(ll x, ll mod){
	ll res = 1;
	for(ll y = 1, x_mod = x; y <= x; y *= 2, x_mod = (x_mod * 2) % mod){
		if(y & x){
			res += x_mod;
			res %= mod;
		}
	}

	return res;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;

	ll x = 2, y = 2, d = 1;
	for(ll cycle_size = 2; d == 1; cycle_size *= 2){
		for(ll i = 0; i < cycle_size and d <= 1; i++){
			y = f(y, n);
			d = gcd(abs(x - y), n);
		}

		x = f(x, n);
	}

	cout << d;
}

