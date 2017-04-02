#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod = 1e9 + 1;
ll fact[64];
ll on[64];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;

	for(int i = 1; i < 64; i++){
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
	}

	ll res = 0;

	for(ll i = 1, bit = 1; (bit + 1) <= n; i++, bit *= 2){
		
	}

	res += ((n + 1) % mod) * ((n + 1) % mod);
	for(int i = 0; i < 64; i++){
		res -= ((on[i] % mod) * (fact[i] % mod)) % mod;
		res %= mod;
	}

	cout << res << endl;
}