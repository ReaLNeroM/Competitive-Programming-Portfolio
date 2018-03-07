#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 50005 + 1e2;
ll t[2][maxn];
ll v[2][maxn];

ll inf = 2000000000;
ll l_inf = -inf;

int main(){
	std::ios::sync_with_stdio(false);

	ll n, l, k;
	std::cin >> n >> l >> k;

	for(ll i = 0; i < 2; i++){
		for(ll j = 0; j < n; j++){
			std::cin >> t[i][j] >> v[i][j];
		}
	}

	ll l = 1, r = 2e9;
}