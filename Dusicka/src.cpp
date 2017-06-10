#include <bits/stdc++.h>

typedef long long ll;

const ll maxbit = 25;
const ll maxn = 1e5 + 100;
ll pow2[maxbit];
ll pref[maxbit][maxn];
ll app[maxbit];

ll dfs(ll curr_bit, ll left, ll made){
	if(curr_bit == -1){
		return left * made * made;
	} else if(left == 0){
		return 0;
	}

	ll res = 0;
	if(left > app[curr_bit]){
		res += dfs(curr_bit - 1, left - app[curr_bit], made                );
		res += dfs(curr_bit - 1, app[curr_bit]       , made + pow2[curr_bit]);
		app[curr_bit] = 0;
	} else if(left < app[curr_bit]){
		res += dfs(curr_bit - 1, left                , made + pow2[curr_bit]);
		app[curr_bit] -= left;
	} else {
		res += dfs(curr_bit - 1, left                , made + pow2[curr_bit]);
		app[curr_bit] = 0;
	}

	return res;
}

int main(){
	std::ios::sync_with_stdio(false);

	ll n, q;
	std::cin >> n >> q;

	for(ll i = 0; i < maxbit; i++){
		pow2[i] = (1 << i);
	}

	for(ll i = 1; i <= n; i++){
		ll val;
		std::cin >> val;

		for(ll j = 0; j < maxbit; j++){
			pref[j][i] = pref[j][i - 1];
			if(val & (1 << j)){
				pref[j][i] += 1;
			}
		}
	}

	for(ll i = 0; i < q; i++){
		ll l, r;
		l = 1, r = n;
		std::cin >> l >> r;

		for(ll j = 0; j < 20; j++){
			app[j] = pref[j][r] - pref[j][l - 1];
		}

		std::cout << dfs(maxbit - 1, r - l + 1, 0) << '\n';
	}
}